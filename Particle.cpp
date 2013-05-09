#include "Particle.h"

Particle::Particle( int X, int Y ,SDL_Surface *screen, SDL_Surface *type)
{
    this->screen = screen;

    //Set offsets
    x = X - 5 + ( rand() % 25 );
    y = Y - 5 + ( rand() % 25 );

    //Initialize animation
    frame = rand() % 5;

    this->type=type;
}

void Particle::show()
{
    //Show image
    apply_surface( x, y, type, screen );

    //Show shimmer
    if( frame % 2 == 0 )
    {
        apply_surface( x, y, shimmer, screen );
    }

    //Animate
    frame++;
}

bool Particle::is_dead()
{
    if( frame > 10 )
    {
        return true;
    }

    SDL_FreeSurface( shimmer );

    return false;
}
