#ifndef UTILITY_H
#define UTILITY_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Timer.h"
#include <string>

SDL_Surface *load_image( std::string filename );

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination);



#endif // UTILITY_H
