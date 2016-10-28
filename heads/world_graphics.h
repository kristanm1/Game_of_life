#ifndef _WORLD_GRAPHICS_H_
#define _WORLD_GRAPHICS_H_

#define WINDOW_WIDTH 888
#define WINDOW_HEIGHT 888

int     initSDL(world*);
void    destroySDL();
void    render(world*);
void    demo(int);
void    demo2(int);

#endif