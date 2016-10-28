#include <SDL2/SDL.h>
#include "heads/world.h"
#include "heads/world_graphics.h"
#include "heads/world_test.h"

/*
    gcc main.c -o main -pthread -lSDL2
*/

int main(int argc, char **argv) {

    world *w1 = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    initInfWorld(w1);
    world *w2 = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    initInfWorld(w2);

    demo(700);
    //demo2(400);

    //simulateMax(w1, 5);

// simuliraj 2 svetova: nakoncu ju primerjaj ce sta koncni stanji stevov isti
//    printf("%4d nit: %10.2f milisekund\n", 1, simulateMax(w1, MAX_ITERATION));
//    printf("%4d nit: %10.2f milisekund\n", THREADS_COUNT, simulateMaxMulty(w2, THREADS_COUNT, MAX_ITERATION));
//    printf("enako: %d\n", compareWorldAreas(w1, w2));

    //printf("test1: '%d'\n", test1());

    //destroyWorld(w1);
    return 0;
}
