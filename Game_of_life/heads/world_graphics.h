#ifndef _WORLD_GRAPHICS_H_
#define _WORLD_GRAPHICS_H_

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 900

int     initSDL(world*);
void    destroySDL();
void    render(world*);
void    SDL_Simulate_Game_of_Life();

#endif