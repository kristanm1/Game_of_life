#include <stdio.h>
#include <SDL2/SDL.h>
#include "../heads/world.h"
#include "../heads/world_graphics.h"
#include "../heads/world_test.h"

SDL_Window *main_window = NULL;
SDL_Renderer *main_renderer = NULL;
SDL_Surface *loading_surface = NULL;
SDL_Texture *background_texture = NULL, *cellular_cell = NULL, *worldground_texture = NULL;
SDL_Rect *src_rect, *dest_rect;
SDL_Event *event;

void SDL_Simulate_Game_of_Life() {
    world *w = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    initInfWorld(w);
    initSDL(w);
    int run = 1;
    while(run) {
        while(!SDL_PollEvent(event)) {
            render(w);
            SDL_Delay(60);
            simulateOneCicle(w);
            //simulateMultyOneCicle(w, THREADS_COUNT);
        }
        //ce je bila tipka q pritisnjena koncaj program....
        if(event->key.keysym.sym == SDLK_q) {
            printf("Exited by keyboard input!!!\n");
            run = 0;
        }
    }
    destroySDL();
    destroyWorld(w);
}

/*
    Sprosti in zapri vse strukture za grafiko:
*/
void destroySDL() {
    SDL_DestroyTexture(cellular_cell);
    SDL_DestroyTexture(background_texture);
    SDL_DestroyRenderer(main_renderer);
    SDL_DestroyWindow(main_window);
    free(src_rect);
    free(dest_rect);
    free(event);
    SDL_Quit();
}
/*
    Inicializacija grafike:
*/
int initSDL(world *w) {
    src_rect = (SDL_Rect*) malloc(sizeof(SDL_Rect));
    dest_rect = (SDL_Rect*) malloc(sizeof(SDL_Rect));
    event = (SDL_Event*) malloc(sizeof(SDL_Event));

    SDL_PollEvent(NULL);

    main_window = SDL_CreateWindow("SDL: Game of Life! - Press key: 'q' to exit", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    main_renderer = SDL_CreateRenderer(main_window, -1, 0);

    loading_surface = SDL_LoadBMP("textures/background.bmp");
    background_texture = SDL_CreateTextureFromSurface(main_renderer, loading_surface);
    SDL_FreeSurface(loading_surface);

    loading_surface = SDL_LoadBMP("textures/worldground.bmp");
    worldground_texture = SDL_CreateTextureFromSurface(main_renderer, loading_surface);
    SDL_FreeSurface(loading_surface);

    loading_surface = SDL_LoadBMP("textures/yellow.bmp");
    cellular_cell = SDL_CreateTextureFromSurface(main_renderer, loading_surface);
    SDL_FreeSurface(loading_surface); 

    return 0;
}

/*
    Funkcija za renderiranje slik na window
*/
void render(world *w) {

    SDL_RenderCopy(main_renderer, background_texture, NULL, NULL);

    int c_x = WINDOW_HEIGHT/w->height;
    int c_y = WINDOW_WIDTH/w->width;
    int totalSizeHeight = c_x*w->height;
    int totalSizeWidth = c_y*w->width;
    int offHeight = (WINDOW_HEIGHT - totalSizeHeight) / 2;
    int offWidth = (WINDOW_WIDTH - totalSizeWidth) / 2;
    
    src_rect->x = offWidth;
    src_rect->y = offHeight;
    src_rect->w = totalSizeWidth;
    src_rect->h = totalSizeHeight;

    dest_rect->x = offWidth;
    dest_rect->y = offHeight;
    dest_rect->w = totalSizeWidth;
    dest_rect->h = totalSizeHeight;

    SDL_RenderCopy(main_renderer, worldground_texture, src_rect, dest_rect);

    src_rect->x = 2;
    src_rect->y = 2;
    src_rect->w = WINDOW_WIDTH/w->width;
    src_rect->h = WINDOW_HEIGHT/w->height;
    
    dest_rect->x = 0;
    dest_rect->y = 0;
    dest_rect->w = src_rect->w;
    dest_rect->h = src_rect->h;

    int i,j;
    for(i = 0; i < w->height; i++) {
        for(j = 0; j < w->width; j++) {
            if(w->area[i][j] > 0) {
                dest_rect->x = src_rect->w*j + offWidth;
                dest_rect->y = src_rect->h*i + offHeight;
                SDL_RenderCopy(main_renderer, cellular_cell, src_rect, dest_rect);
            }
        }
    }
    SDL_RenderPresent(main_renderer);
}