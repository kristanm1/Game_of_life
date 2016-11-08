#include <SDL2/SDL.h>
#include "heads/world.h"
#include "heads/world_graphics.h"
#include "heads/world_test.h"

/*
    gcc main.c -o main -pthread -lSDL2
*/

int main(int argc, char **argv) {

    //SDL_Simulate_Game_of_Life();
    //                     #ponovitev, visina, sirina, st. iteracij, #niti
    //casovna_analiza_vec_niti    (10, 500, 500, 50, 8, 1);

    printf("---SE: %.3f\n", SE(casovna_analiza_1_nit(5, 500, 500, 50, 1)));
    printf("---SE: %.3f\n", SE(casovna_analiza_1_nit(5, 600, 500, 50, 1)));
    printf("---SE: %.3f\n", SE(casovna_analiza_1_nit(5, 700, 500, 50, 1)));
    printf("---SE: %.3f\n", SE(casovna_analiza_1_nit(5, 800, 500, 50, 1)));
    printf("---SE: %.3f\n", SE(casovna_analiza_1_nit(5, 900, 500, 50, 1)));
    printf("---SE: %.3f\n", SE(casovna_analiza_1_nit(5, 1000, 500, 50, 1)));

    return 0;
}
