#ifndef _WORLD_H_
#define _WORLD_H_

#define WORLD_SIZE_HEIGHT 120
#define WORLD_SIZE_WIDTH 120

#define MAX_ITERATION 500
#define THREADS_COUNT 6

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
int 	numOfNeighbors(int, int, world*);
void 	simulateOneCicle(world*);
void 	simulateMultyOneCicle(world*, int);
void 	simulate(world*);
void 	simulateMulty(world*, int);
double  simulateMax(world*, int);
double 	simulateMaxMulty(world*, int, int);

void*   doSomething(void*);

#endif
