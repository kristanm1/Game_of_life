#include <SDL2/SDL.h>
#include </home/matej/Desktop/PS/git.tmp/heads/world.h>
#include </home/matej/Desktop/PS/git.tmp/heads/world_graphics.h>
#include </home/matej/Desktop/PS/git.tmp/heads/world_test.h>

/*
    nekaj narobe?? pri 625/626 generaciji
*/
int test1() {
    world *w1, *w2;
    w1 = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    w2 = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    initInfWorld(w1);
    initInfWorld(w2);
    simulateMax(w1, 624);
    simulateMaxMulty(w2, THREADS_COUNT, 625);

    initSDL(w1);
    render(w1);
    SDL_Delay(4000);
    destroySDL();

    initSDL(w2);
    render(w2);
    SDL_Delay(4000);
    destroySDL();

    return compareWorldAreas(w1, w2);
}

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

    w->area[20][80] = 1;
    w->area[20][81] = 1;
    w->area[20][82] = 1;
    w->area[19][80] = 1;
    w->area[18][81] = 1;

}

/*
    Inicializa zacetni svet za demo, svet mora biti vecji ali enak 94x94 celic
*/
void initInfWorld(world *w) {
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
