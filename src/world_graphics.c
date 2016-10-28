#include <stdio.h>
#include <SDL2/SDL.h>
#include </home/matej/Desktop/PS/git.tmp/heads/world.h>
#include </home/matej/Desktop/PS/git.tmp/heads/world_test.h>
#include </home/matej/Desktop/PS/git.tmp/heads/world_graphics.h>

SDL_Window *main_window = NULL;
SDL_Renderer *main_renderer = NULL;
SDL_Surface *loading_surface = NULL;
SDL_Texture *background_texture = NULL;
SDL_Texture *cellular_cell = NULL;
SDL_Rect src_rect;
SDL_Rect dest_rect;

/*
    Sprosti in zapri vse strukture za grafiko:
*/
void destroySDL() {
    SDL_DestroyTexture(cellular_cell);
    SDL_DestroyTexture(background_texture);
    SDL_DestroyRenderer(main_renderer);
    SDL_DestroyWindow(main_window);
    SDL_Quit();
}
/*
    Inicializacija grafike:
*/
int initSDL(world *w) {
    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = WINDOW_WIDTH/w->width;
    src_rect.h = WINDOW_HEIGHT/w->height;
    printf("window --> WIDHT: %4d HEIGHT:%4d\n", WINDOW_WIDTH, WINDOW_HEIGHT);
    printf("world --> WIDHT: %4d HEIGHT: %4d\n", w->width, w->height);
    printf("src_rect: w=%d h=%d\n", src_rect.w, src_rect.h);
    
    dest_rect.x = 0;
    dest_rect.y = 0;
    dest_rect.w = src_rect.w;
    dest_rect.h = src_rect.h;

    SDL_PollEvent(NULL);
    main_window = SDL_CreateWindow("SDL window!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    main_renderer = SDL_CreateRenderer(main_window, -1, 0);

    loading_surface = SDL_LoadBMP("textures/background.bmp");
    background_texture = SDL_CreateTextureFromSurface(main_renderer, loading_surface);
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
    SDL_PumpEvents();
    int i,j;
    for(i = 0; i < w->height; i++) {
        for(j = 0; j < w->width; j++) {
            if(w->area[i][j] > 0) {
                dest_rect.x = src_rect.w*j;
                dest_rect.y = src_rect.h*i;
                SDL_RenderCopy(main_renderer, cellular_cell, &src_rect, &dest_rect);
            }
        }
    }
    SDL_RenderPresent(main_renderer);
}

/*
    Simulacija ki izvede iterations generacij + vizualizacija
*/
void demo(int iterations) {
    world *w = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    initInfWorld(w);
    initSDL(w);
    int i;
	for(i = 0; i < iterations; i++) {
        render(w);
        SDL_Delay(50);
		simulateOneCicle(w);
	}
    destroySDL();
}

void demo2(int iterations) {
    world *w = createWorld(WORLD_SIZE_HEIGHT, WORLD_SIZE_WIDTH);
    initInf2World(w);
    initSDL(w);
    int i;
	for(i = 0; i < iterations; i++) {
        render(w);
        SDL_Delay(40);
		simulateOneCicle(w);
	}
    destroySDL();
}