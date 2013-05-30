#ifndef PLAYER_H
#define PLAYER_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Utility.h"
#include "Dot.h"

enum{
        NONE2,
        TOP2,
        BOT2,
        LEFT2,
        RIGHT2,
        CORNERUL2,
        CORNERUR2,
        CORNERDL2,
        CORNERDR2,
        COLLIDING2
        };

class Player
{
    public:
         bool isColliding;
        bool wasColliding;
        int mover;
        float x, y;
        int width,height;
        SDL_Surface *image;
        SDL_Surface *screen;
        Dot *dot;
        Player(float x, float y, int width, int height,
              SDL_Surface *image, SDL_Surface *screen,
              Dot *dot);
        int collisionType();
        bool isPointInside(float pointX, float pointY);
        void show();
        void ismove();
        void logic();
        Player();
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
