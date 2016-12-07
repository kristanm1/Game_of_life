#include <SDL2/SDL.h>
#include "heads/world.h"
#include "heads/world_graphics.h"
#include "heads/world_test.h"

/*
    ./makefile
*/

int main(int argc, char **argv) {


    //graficna simulacija cellularnega avtomata
    //SDL_Simulate_Game_of_Life();
    
    //printf("threads:%d, procs: %d\n", omp_get_thread_num(), omp_get_num_threads());

    

    //:parametri funkcije casovna_analiza_1(vec)_nit(i): #ponovitev, visina, sirina, st. iteracij, #niti, DEBUG(izpisuje vmesne rezultate = 1, ne izpisuj = 0)
/*
    casovna_analiza_1_nit       (25, 100, 100, 100, 1);
    casovna_analiza_1_nit       (25, 100, 100, 200, 1);
    casovna_analiza_1_nit       (25, 100, 100, 400, 1);
    casovna_analiza_1_nit       (25, 100, 100, 800, 1);

    casovna_analiza_vec_niti    (25, 100, 100, 100, 2, 1);
    casovna_analiza_vec_niti    (25, 100, 100, 200, 2, 1);
    casovna_analiza_vec_niti    (25, 100, 100, 400, 2, 1);
    casovna_analiza_vec_niti    (25, 100, 100, 800, 2, 1);

    casovna_analiza_vec_niti2   (25, 100, 100, 100, 2, 1);
    casovna_analiza_vec_niti2   (25, 100, 100, 200, 2, 1);
    casovna_analiza_vec_niti2   (25, 100, 100, 400, 2, 1);
    casovna_analiza_vec_niti2   (25, 100, 100, 800, 2, 1);
*/
    casovna_analiza_vec_niti_OMP(25, 100, 100, 100, 2, 1);
    casovna_analiza_vec_niti_OMP(25, 100, 100, 200, 2, 1);
    casovna_analiza_vec_niti_OMP(25, 100, 100, 400, 2, 1);
    casovna_analiza_vec_niti_OMP(25, 100, 100, 800, 2, 1);

    //------------------------------------------------------------------------------------
/*
    casovna_analiza_1_nit       (25, 100, 100, 100, 1);
    casovna_analiza_1_nit       (25, 100, 200, 100, 1);
    casovna_analiza_1_nit       (25, 100, 400, 100, 1);
    casovna_analiza_1_nit       (25, 100, 800, 100, 1);

    casovna_analiza_vec_niti    (25, 100, 100, 100, 2, 1);
    casovna_analiza_vec_niti    (25, 100, 200, 100, 2, 1);
    casovna_analiza_vec_niti    (25, 100, 400, 100, 2, 1);
    casovna_analiza_vec_niti    (25, 100, 800, 100, 2, 1);

    casovna_analiza_vec_niti2   (25, 100, 100, 100, 2, 1);
    casovna_analiza_vec_niti2   (25, 100, 200, 100, 2, 1);
    casovna_analiza_vec_niti2   (25, 100, 400, 100, 2, 1);
    casovna_analiza_vec_niti2   (25, 100, 800, 100, 2, 1);
*/
    casovna_analiza_vec_niti_OMP(25, 100, 100, 100, 2, 1);
    casovna_analiza_vec_niti_OMP(25, 100, 200, 100, 2, 1);
    casovna_analiza_vec_niti_OMP(25, 100, 400, 100, 2, 1);
    casovna_analiza_vec_niti_OMP(25, 100, 800, 100, 2, 1);

    //------------------------------------------------------------------------------------

/*
    casovna_analiza_1_nit       (25, 100, 100, 100, 1);
    casovna_analiza_1_nit       (25, 200, 100, 100, 1);
    casovna_analiza_1_nit       (25, 400, 100, 100, 1);
    casovna_analiza_1_nit       (25, 800, 100, 100, 1);

    casovna_analiza_vec_niti    (25, 100, 100, 100, 2, 1);
    casovna_analiza_vec_niti    (25, 200, 100, 100, 2, 1);
    casovna_analiza_vec_niti    (25, 400, 100, 100, 2, 1);
    casovna_analiza_vec_niti    (25, 800, 100, 100, 2, 1);

    casovna_analiza_vec_niti2   (25, 100, 100, 100, 2, 1);
    casovna_analiza_vec_niti2   (25, 200, 100, 100, 2, 1);
    casovna_analiza_vec_niti2   (25, 400, 100, 100, 2, 1);
    casovna_analiza_vec_niti2   (25, 800, 100, 100, 2, 1);
*/
    casovna_analiza_vec_niti_OMP(25, 100, 100, 100, 2, 1);
    casovna_analiza_vec_niti_OMP(25, 200, 100, 100, 2, 1);
    casovna_analiza_vec_niti_OMP(25, 400, 100, 100, 2, 1);
    casovna_analiza_vec_niti_OMP(25, 800, 100, 100, 2, 1);

    return 0;
}
