#include <SDL2/SDL.h>
#include "../heads/world.h"
#include "../heads/world_graphics.h"
#include "../heads/world_test.h"

int test1() {
    world *w1, *w2;
    w1 = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    w2 = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    initInfWorld(w1);
    initInfWorld(w2);
    
    int i;
    for(i = 0; i < 500; i++) {
        simulateOneCicle(w1);
        simulateMultyOneCicle(w2, THREADS_COUNT);
        if(compareWorldAreas(w1, w2) != 1) {
            return 0;
        }
    }

    destroyWorld(w1);
    destroyWorld(w2);
    return 1;
}

/*
    Stopa cas na eni niti in na THREADS_COUNT nitih
*/
void countTime() {
// simuliraj 2 svetova: nakoncu ju primerjaj ce sta koncni stanji svetov enaki
    world *w1, *w2;
    w1 = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    w2 = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    printf("%4d nit: %10.2f milisekund\n", 1, simulateMax(w1, MAX_ITERATION));
    printf("%4d nit: %10.2f milisekund\n", THREADS_COUNT, simulateMaxMulty(w2, THREADS_COUNT, MAX_ITERATION));
    printf("enako(1=true, 0=false): %d\n", compareWorldAreas(w1, w2));
    destroyWorld(w1);
    destroyWorld(w2);
}

void initWorld(world *w) {
    w->area[15][2] = 1;
    w->area[15][1] = 1;
    w->area[16][2] = 1;
    w->area[16][1] = 1;

    w->area[15][11] = 1;
    w->area[16][11] = 1;
    w->area[17][11] = 1;
    w->area[14][12] = 1;
    w->area[13][13] = 1;
    w->area[13][14] = 1;
    w->area[18][12] = 1;
    w->area[19][13] = 1;
    w->area[19][14] = 1;

    w->area[18][16] = 1;
    w->area[17][17] = 1;
    w->area[16][17] = 1;
    w->area[16][15] = 1;
    w->area[15][17] = 1;
    w->area[14][16] = 1;
    w->area[16][18] = 1;

    w->area[14][21] = 1;
    w->area[15][21] = 1;
    w->area[16][21] = 1;
    w->area[14][22] = 1;
    w->area[15][22] = 1;
    w->area[16][22] = 1;
    w->area[17][23] = 1;
    w->area[17][25] = 1;
    w->area[18][25] = 1;
    w->area[13][23] = 1;
    w->area[13][25] = 1;
    w->area[12][25] = 1;

    w->area[13][35] = 1;
    w->area[13][36] = 1;
    w->area[14][35] = 1;
    w->area[14][36] = 1;

}

/*
    Inicializa zacetni svet: kvadrati v vogalih
*/
void initInf2World(world *w) {

    w->area[0][0] = 1;
    w->area[0][1] = 1;
    w->area[1][0] = 1;
    w->area[1][1] = 1;

    w->area[0][w->width-1] = 1;
    w->area[0][w->width-2] = 1;
    w->area[1][w->width-1] = 1;
    w->area[1][w->width-2] = 1;

    w->area[w->height-1][0] = 1;
    w->area[w->height-1][1] = 1;
    w->area[w->height-2][0] = 1;
    w->area[w->height-2][1] = 1;

    w->area[w->height-1][w->width-1] = 1;
    w->area[w->height-1][w->width-2] = 1;
    w->area[w->height-2][w->width-1] = 1;
    w->area[w->height-2][w->width-2] = 1;

}

/*
    Inicializa zacetni svet za demo, svet mora biti vecji ali enak 94x94 celic
*/
void initInfWorld(world *w) {

    w->area[0][0] = 1;
    w->area[0][1] = 1;
    w->area[1][0] = 1;
    w->area[1][1] = 1;

    w->area[0][w->width-1] = 1;
    w->area[0][w->width-2] = 1;
    w->area[1][w->width-1] = 1;
    w->area[1][w->width-2] = 1;

    w->area[w->height-1][0] = 1;
    w->area[w->height-1][1] = 1;
    w->area[w->height-2][0] = 1;
    w->area[w->height-2][1] = 1;

    w->area[w->height-1][w->width-1] = 1;
    w->area[w->height-1][w->width-2] = 1;
    w->area[w->height-2][w->width-1] = 1;
    w->area[w->height-2][w->width-2] = 1;

    w->area[4][4] = 1;
    w->area[4][5] = 1;
    w->area[5][4] = 1;
    w->area[5][5] = 1;

    w->area[3][80] = 1;
    w->area[3][81] = 1;
    w->area[4][80] = 1;
    w->area[4][81] = 1;

    w->area[10][10] = 1;
    w->area[10][11] = 1;
    w->area[10][12] = 1;
    w->area[9][12] = 1;
    w->area[8][11] = 1;

    w->area[20][80] = 1;
    w->area[20][81] = 1;
    w->area[20][82] = 1;
    w->area[19][80] = 1;
    w->area[18][81] = 1;

    w->area[50][50] = 1;
    w->area[50][51] = 1;
    w->area[50][52] = 1;

    w->area[60][60] = 1;
    w->area[60][61] = 1;
    w->area[60][62] = 1;
    w->area[61][63] = 1;
    w->area[61][61] = 1;
    w->area[61][62] = 1;

    w->area[90][90] = 1;
    w->area[91][90] = 1;
    w->area[90][91] = 1;
    w->area[91][91] = 1;
    w->area[92][92] = 1;
    w->area[92][93] = 1;
    w->area[93][92] = 1;
    w->area[93][93] = 1;
}
