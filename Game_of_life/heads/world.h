#ifndef _WORLD_H_
#define _WORLD_H_

#define WORLD_SIZE_HEIGHT 115
#define WORLD_SIZE_WIDTH 115

#define MAX_ITERATION 500

typedef struct {
    int width, height, **area;
} world;

typedef struct {
	int min, max, **area, num_iter;
	world *w;
	pthread_barrier_t *barrier;
} param;

world* 	createWorld(int, int);
void 	destroyWorld(world*);
void 	printWorld(world*);
void 	addNewArea(world*, int**);
int** 	createNewArea(int , int);
int 	compareWorldAreas(world*, world*);

void 	cell_destiny_3x3(int, int, world*, int*);
void 	cell_destiny_5x5(int, int, world*, int*);

int 	numOfNeighbors_Moore_3x3(int, int, world*);
int 	numOfNeighbors_Moore_5x5(int, int, world*);

void 	simulate(world*);
void 	simulateOneCicle(world*);
double  simulateMax(world*, int);

void*   doSomething(void*);
void 	simulateMulty(world*, int);
void 	simulateMultyOneCicle(world*, int);
double 	simulateMaxMulty(world*, int, int);

void*	doSomething2(void *arg);
double	simulateMaxMulty2(world*, int , int);

#endif
