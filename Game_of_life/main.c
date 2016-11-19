#include <SDL2/SDL.h>
#include "heads/world.h"
#include "heads/world_graphics.h"
#include "heads/world_test.h"

/*
    gcc main.c -o main -pthread -lSDL2
*/

int main(int argc, char **argv) {


    //graficna simulacija cellularnega avtomata
    //SDL_Simulate_Game_of_Life();

    //:parametri funkcije casovna_analiza_1(vec)_nit(i): #ponovitev, visina, sirina, st. iteracij, #niti, DEBUG(izpisuje vmesne rezultate = 1, ne izpisuj = 0)
    //casovna_analiza_1_nit(10, 500, 500, 50, 1);
    //casovna_analiza_1_nit(10, 500, 500, 60, 1);
    //casovna_analiza_1_nit(10, 500, 500, 70, 1);
    //casovna_analiza_1_nit(10, 500, 500, 80, 1);
    //casovna_analiza_1_nit(10, 500, 500, 90, 1);
    //casovna_analiza_1_nit(10, 500, 500, 100, 1);


    casovna_analiza_1_nit       (4, 1000, 200, 100, 1);
    casovna_analiza_vec_niti    (4, 1000, 200, 100, 8, 1);
    casovna_analiza_vec_niti2   (4, 1000, 200, 100, 8, 1);

    return 0;
}
