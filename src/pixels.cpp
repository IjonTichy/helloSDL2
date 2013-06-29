#ifndef _HELLOSDL_PIXELS__
#define _HELLOSDL_PIXELS__

#include <SDL/SDL.h>

Uint32 getpixel(SDL_Surface *surface, int x, int y);
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

#endif
