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

    //casovna_analiza_1_nit       (10, 100, 100, 2000, 1);
    //casovna_analiza_1_nit       (10, 100, 100, 3000, 1);
    //casovna_analiza_1_nit       (10, 100, 100, 4000, 1);
    //casovna_analiza_1_nit       (10, 100, 100, 5000, 1);

    //casovna_analiza_vec_niti    (20, 100, 100, 2000, 2, 1);
    //casovna_analiza_vec_niti    (10, 100, 100, 3000, 2, 1);
    //casovna_analiza_vec_niti    (10, 100, 100, 4000, 2, 1);
    //casovna_analiza_vec_niti    (10, 100, 100, 5000, 2, 1);

    //casovna_analiza_vec_niti2   (10, 100, 100, 2000, 2, 1);
    //casovna_analiza_vec_niti2   (10, 100, 100, 3000, 2, 1);
    casovna_analiza_vec_niti2   (10, 100, 100, 4000, 2, 1);
    casovna_analiza_vec_niti2   (10, 100, 100, 5000, 2, 1);
    
    

    return 0;
}
