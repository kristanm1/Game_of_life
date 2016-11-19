#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <omp.h>
#include "../heads/world.h"

/*
	Kreiraj nov svet(visina, sirina):
		-svet je na zacetku polje mrtvih celic
*/
world* createWorld(int size_x, int size_y) {
    world *w = (world*) malloc(sizeof(world));
    w->area = (int**) malloc(sizeof(int*) * size_x);
    w->height = size_x;
    w->width = size_y;
    int i;
    for(i = 0; i < size_x; i++) {
        w->area[i] = (int*) calloc(sizeof(int), size_y);
    }
    return w;
}

/*
	Metoda presteje zive sosede celice(i, j) v svetu w po Moorovem pravilu 3x3
*/
int numOfNeighbors_Moore_3x3(int i, int j, world *w) {
    int n, m, num_of_neighbors = 0;
    for(n = -1; n < 2; n++) {
        for(m = -1; m < 2; m++) {
            if(n == 0 && m == 0) continue;
            if((i + n) >= 0 && (i + n) < w->height && (j + m) >= 0 && (j + m) < w->width) {
                if(w->area[i+n][j+m] > 0) {
                    num_of_neighbors++;
                }
            }
        }
    }
    return num_of_neighbors;
}

void cell_destiny_3x3(int i, int j, world *w, int *area) {
    int non = numOfNeighbors_Moore_3x3(i, j, w);
    if(w->area[i][j] > 0) {
        if(non == 2 || non == 3) {
            area[j] = 1;
        }
        else {
            area[j] = 0;
        }
    }
    else {
        if(non == 3) {
            area[j] = 1;
        }
    }
}

/*
	Metoda presteje zive sosede celice(i, j) v svetu w po Moorovem pravilu 5x5
*/
int numOfNeighbors_Moore_5x5(int i, int j, world *w) {
    int n, m, num_of_neighbors = 0;
    for(n = -2; n < 3; n++) {
        for(m = -2; m < 3; m++) {
            if(n == 0 && m == 0) continue;
            if((i + n) >= 0 && (i + n) < w->height && (j + m) >= 0 && (j + m) < w->width) {
                if(w->area[i+n][j+m] > 0) {
                    num_of_neighbors++;
                }
            }
        }
    }
    return num_of_neighbors;
}

void cell_destiny_5x5(int i, int j, world *w, int *area) {
    int non = numOfNeighbors_Moore_5x5(i, j, w); 
    if(w->area[i][j] > 0) {
        if(non == 3) {
            area[j] = 1;
        }
        else {
            area[j] = 0;
        }
    }
    else {
        if(non == 4) {
            area[j] = 1;
        }
    }
}

/*
	Dodaj novo polje v svet in sprosti resurse starega polja
*/
void addNewArea(world *w, int **area) {
    int i;
    for(i = 0; i < w->height; i++) {
        free(w->area[i]);
    }
    free(w->area);
    w->area = area;
}

/*
	Vrne novo polje velikosti height x width
*/
int** createNewArea(int height, int width) {
	int **area = (int**) malloc(sizeof(int*) * height), i;
	for(i = 0; i < height; i++) {
		area[i] = (int*) calloc(sizeof(int), width);
	}
	return area;
}

/*
	Simulira eno generacijo sveta na eni niti
*/
void simulateOneCicle(world *w) {
    int i, j, **area = (int**) malloc(sizeof(int*) * w->height);
    for(i = 0; i < w->height; i++) {
        area[i] = (int*) calloc(sizeof(int), w->width);
        for(j = 0; j < w->width; j++) {
            cell_destiny_3x3(i, j, w, area[i]);
        }
    }
    addNewArea(w, area);
}

/*
	Funkcija primerja svetova in vrne 1 ce sta enaka in 0 ce sta razlicna
*/
int compareWorldAreas(world *w1, world *w2) {
	if(w1->width == w2->width && w1->height == w2->height) {
		int i, j;
		for(i = 0; i < w1->height; i++) {
			for(j = 0; j < w1->width; j++) {
				if(w1->area[i][j] != w2->area[i][j]) {
					return 0;
				}
			}
		}
		return 1;
	}
	return 0;
}

/*
	Sprosti resurse za svet
*/
void destroyWorld(world *w) {
    int i;
    for(i = 0; i < w->height; i++) {
        free(w->area[i]);
    }
    free(w->area);
    free(w);
}

void printWorld(world *w) {
    int i, j;
    for(i = 0; i < w->height; i++) {
        for(j = 0; j < w->width; j++) {
            printf("%u ", w->area[i][j]);
        }
        printf("\n");
    }
    printf("World size[height:%d, width:%d]\n", w->height, w->width);
}

/*
	Simulira v neskoncno z izpisom v konzolo na eni niti
*/
void simulate(world *w) {
    while(1) {
        simulateOneCicle(w);
        printWorld(w);
    }
}

/*
	Simulira max generacij na eni niti in vrne double v milisekundah porabljenega casa
*/
double simulateMax(world *w, int max) {
	struct timeval t1, t2;
	int i;
	gettimeofday(&t1, NULL);
	for(i = 0; i < max; i++) {
		simulateOneCicle(w);
	}
	gettimeofday(&t2, NULL);
	double time_elapsed = (t2.tv_sec - t1.tv_sec) * 1000;
	time_elapsed += (double)(t2.tv_usec - t1.tv_usec) / 1000;
	return time_elapsed;
}

/*
	Funkcija ki jo izvaja nit
*/
void* doSomething(void *arg) {
	param *p = (param*) arg;
	int i, j, non;
    for(i = p->min; i < p->max; i++) {
        for(j = 0; j < p->w->width; j++) {
            cell_destiny_3x3(i, j, p->w, p->area[i]);          
        }
    }
	return NULL;	
}

/*
	Simulira eno generacijo sveta na threadCount nitih in za vsako
    generacijo naredi niti in nakoncu jih 'pobije'
*/
void simulateMultyOneCicle(world *w, int threadCount) {
	pthread_t t[threadCount];
	param p[threadCount];
	int **newArea = createNewArea(w->height, w->width), i, min = 0, max, delta = w->height/threadCount + 1;
	for(i = 0; i < threadCount; i++) {
		max = min + delta;
		if(min >= w->height) {
			min = w->height;
			max = w->height;
		}
		else if(max > w->height) {
			max = w->height;
		}
		p[i].min = min;
		p[i].max = max;
		p[i].area = newArea;
		p[i].w = w;
		pthread_create(&t[i], NULL, doSomething, (void*) &p[i]);
		min += delta;
	}
	for(i = 0; i < threadCount; i++) {
		pthread_join(t[i], NULL);
	}
	addNewArea(w, newArea);
}

/*
	Simulira max generacij na threadCount nitih in vrne long long v milisekundah porabljenega casa
*/
double simulateMaxMulty(world *w, int threadCount, int max) {
	struct timeval t1, t2;
	int i;
	gettimeofday(&t1, NULL);
	for(i = 0; i < max; i++) {
		simulateMultyOneCicle(w, threadCount);
	}
	gettimeofday(&t2, NULL);
	double time_elapsed = (t2.tv_sec - t1.tv_sec) * 1000;
	time_elapsed += (double)(t2.tv_usec - t1.tv_usec) / 1000;
	return time_elapsed;
}

/*
	Simulira v neskoncno z izpisom v konzolo na threadCount nitih
		-exit = ctrl + c
*/
void simulateMulty(world *w, int threadCount) {
	while(1) {
		simulateMultyOneCicle(w, threadCount);
		sleep(2.0);
		printWorld(w);
	}
}

/*
	Funkcija ki jo izvaja nit
*/
//polje v katerega pisejo vse niti, vsaka v svoje obmocje: [min, max]
static int **tmpArea;

void* doSomething2(void *arg) {
	param *p = (param*) arg;
	int i, j, k, non;
    for(k = 0; k < p->num_iter; k++) {
        for(i = p->min; i < p->max; i++) {
            for(j = 0; j < p->w->width; j++) {
                cell_destiny_3x3(i, j, p->w, tmpArea[i]);          
            }
        }
        pthread_barrier_wait(p->barrier);
        if(p->min == 0) {
            int m;
            for(m = 0; m < p->w->height; m++) {
                free(p->w->area[m]);
                p->w->area[m] = tmpArea[m];
                tmpArea[m] = calloc(sizeof(int), p->w->width);
            }
        }   
        pthread_barrier_wait(p->barrier);
    }
	return NULL;
}

/*
	Simulira max generacij na threadCount nitih in vrne double v milisekundah porabljenega casa
*/
double simulateMaxMulty2(world *w, int threadCount, int max) {

    struct timeval t1, t2;

    pthread_t t[threadCount];
    param p[threadCount];

    pthread_barrier_t barrier;
    pthread_barrier_init(&barrier, NULL, threadCount);

    tmpArea = createNewArea(w->height, w->width);
    int i, min_t = 0, max_t, delta = w->height/threadCount + 1;

    gettimeofday(&t1, NULL);
    //printf("st.niti:%d, visina sveta:%d\n", threadCount, w->height);
	for(i = 0; i < threadCount; i++) {
		max_t = min_t + delta;
		if(min_t >= w->height) {
			min_t = w->height;
			max_t = w->height;
		}
		else if(max_t > w->height) {
			max_t = w->height;
		}
		p[i].min = min_t;
		p[i].max = max_t;
		p[i].area = tmpArea;
		p[i].w = w;
        p[i].barrier = &barrier;
        p[i].num_iter = max;
        //printf("%d, %d\n", min_t, max_t);
		pthread_create(&t[i], NULL, doSomething2, (void*) &p[i]);
		min_t += delta;
	}
    //printf("-----------------------\n");
	for(i = 0; i < threadCount; i++) {
		pthread_join(t[i], NULL);
	}

    pthread_barrier_destroy(&barrier);

    gettimeofday(&t2, NULL);
	double time_elapsed = (t2.tv_sec - t1.tv_sec) * 1000;
	time_elapsed += (double)(t2.tv_usec - t1.tv_usec) / 1000;

    return time_elapsed;
}