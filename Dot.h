#ifndef DOT_H
#define DOT_H

#include <cmath>
#include "Utility.h"
#include "Particle.h"

#define PI 3.14159265

const int TOTAL_PARTICLES = 20;
const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Dot
{
    private:
    //The offsets
    int x, y;

    SDL_Surface *red = NULL;
    SDL_Surface *green = NULL;
    SDL_Surface *blue = NULL;

    SDL_Surface *dot = NULL;

    float angle, velocity;

    SDL_Surface *screen;

    //The particles
    Particle *particles[ TOTAL_PARTICLES ];

    public:
    //Initializes
    Dot(SDL_Surface *screen);

    //Cleans up particles
    ~Dot();

    //Handles keypresses
    void handle_input();

    //Moves the dot
    void move();

    //Shows the particles
    void show_particles();

    //Shows the dot
    void show();
};

#endif // DOT_H
