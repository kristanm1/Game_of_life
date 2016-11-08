#include <SDL2/SDL.h>
#include "heads/world.h"
#include "heads/world_graphics.h"
#include "heads/world_test.h"

/*
    gcc main.c -o main -pthread -lSDL2
*/

int main(int argc, char **argv) {

    //SDL_Simulate_Game_of_Life();
    //                     #ponovitev, visina, sirina, st. iteracij, #niti, DEBUG(izpisuje vmesne rezultate = 1, ne izpisuj = 0)
    //casovna_analiza_vec_niti    (10, 500, 500, 50, 8, 1);

    SE(casovna_analiza_1_nit(10, 500, 500, 50, 1), 1);
    SE(casovna_analiza_1_nit(10, 500, 500, 60, 1), 1);
    SE(casovna_analiza_1_nit(10, 500, 500, 70, 1), 1);
    SE(casovna_analiza_1_nit(10, 500, 500, 80, 1), 1);
    SE(casovna_analiza_1_nit(10, 500, 500, 90, 1), 1);
    SE(casovna_analiza_1_nit(10, 500, 500, 100, 1), 1);

    return 0;
}
