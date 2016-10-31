#include <SDL2/SDL.h>
#include "heads/world.h"
#include "heads/world_graphics.h"
#include "heads/world_test.h"

/*
    gcc main.c -o main -pthread -lSDL2
*/

int main(int argc, char **argv) {

    SDL_Simulate_Game_of_Life();
    //printf("enaka: %d\n", test1());
    //countTime();

    return 0;
}