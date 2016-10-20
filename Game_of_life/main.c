#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//---------------------------konstante--------------------------------------//
#define WORLD_SIZE_X 10
#define WORLD_SIZE_Y 10

//---------------------------strukture--------------------------------------//
typedef struct {
    unsigned int x, y;
    int **area;
} world;

//---------------------------glave vseh funkcij--------------------------------------//
world* createWorld(int sizeX, int sizeY);
int numOfNeighbors(int i, int j, world *w);
void addNewArea(world *w, int **area);
void simulateOneCicle(world *w);
void destroyWorld(world *w);
void printWorld(world *w);

void destroyGraphics(void);
void createWindow(int argc, char **argv);

int main(int argc, char **argv);

//---------------------------struct in funkcije za struct--------------------------------------//

world* createWorld(int sizeX, int sizeY) {
    world *w = (world*) malloc(sizeof(world));
    w->area = (int**) malloc(sizeof(int*) * sizeX);
    w->x = sizeX;
    w->y = sizeY;
    int i;
    for(i = 0; i < sizeX; i++) {
        w->area[i] = (int*) calloc(sizeof(int), sizeY);
    }
    return w;
}

int numOfNeighbors(int i, int j, world *w) {
    int n, m, num_of_neighbors = 0;
    for(n = -1; n < 2; n++) {
        for(m = -1; m < 2; m++) {
            if(n == 0 && m == 0) continue;
            if((i + n) >= 0 && (i + n) < w->x && (j + m) >= 0 && (j + m) < w->y) {
                if(w->area[i+n][j+m] > 0) {
                    num_of_neighbors++;
                }
            }
        }
    }
    return num_of_neighbors;
}

void addNewArea(world *w, int **area) {
    int i;
    for(i = 0; i < w->x; i++) {
        free(w->area[i]);
    }
    free(w->area);
    w->area = area;
}

void simulateOneCicle(world *w) {
    int i, j, non, **area = (int**) malloc(sizeof(int*) * w->x);

    for(i = 0; i < w->x; i++) {
        area[i] = (int*) calloc(sizeof(int), w->y);
        for(j = 0; j < w->y; j++) {
            non = numOfNeighbors(i, j, w);
            if(w->area[i][j] > 0) {
                if(non == 2 || non == 3) {
                    area[i][j] = w->area[i][j] + 1;
                }
                else {
                    area[i][j] = 0;
                }
            }
            else {
                if(non == 3) {
                    area[i][j] = 1;
                }
            }
        }
    }
    addNewArea(w, area);
}

void destroyWorld(world *w) {
    int i;
    for(i = 0; i < w->x; i++) {
        free(w->area[i]);
    }
    free(w->area);
    free(w);
}

void printWorld(world *w) {
    int i, j;
    for(i = 0; i < w->x; i++) {
        for(j = 0; j < w->y; j++) {
            printf("%u ", w->area[i][j]);
        }
        printf("\n");
    }
    printf("World size: %dx%d.\n", w->x, w->y);
}

void simulate(world *w) {
    while(1) {
        simulateOneCicle(w);
        printWorld(w);
        sleep(1.5);
    }
}

//---------------------------graphics--------------------------------------//


//---------------------------main--------------------------------------//

int main(int argc, char **argv) {

    world *w = createWorld(WORLD_SIZE_X, WORLD_SIZE_Y);
    
    w->area[0][2] = 1;
    w->area[1][2] = 1;
    w->area[2][2] = 1;
    w->area[2][1] = 1;
    w->area[1][0] = 1;

    w->area[5][5] = 1;
    w->area[5][4] = 1;
    w->area[4][4] = 1;
    w->area[4][5] = 1;

    printWorld(w);

    simulate(w);
    
    destroyWorld(w);
    return 0;
}
