#ifndef _WORLD_H_
#define _WORLD_H_

#define WORLD_SIZE_HEIGHT 120
#define WORLD_SIZE_WIDTH 120

#define MAX_ITERATION 500
#define THREADS_COUNT 8

typedef struct {
    int width, height, **area;
} world;

typedef struct {
	int min, max, **area;
	world *w;
} param;

world* 	createWorld(int, int);
void 	destroyWorld(world*);
void 	printWorld(world*);
void 	addNewArea(world*, int**);
int** 	createNewArea(int , int);
int 	compareWorldAreas(world*, world*);
int 	numOfNeighbors_Moore_3x3(int, int, world*);
void 	cell_destiny_3x3(int, int, world*, int*);
int 	numOfNeighbors_Moore_5x5(int, int, world*);
void 	cell_destiny_5x5(int, int, world*, int*);
void 	simulateOneCicle(world*);
void 	simulateMultyOneCicle(world*, int);
void 	simulate(world*);
void 	simulateMulty(world*, int);
double  simulateMax(world*, int);
double 	simulateMaxMulty(world*, int, int);

void*   doSomething(void*);

#endif
