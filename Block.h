#ifndef BLOCK_H
#define BLOCK_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Utility.h"
#include "Dot.h"

class Block
{
    public:
        int x,y;
        int width,height;
        SDL_Surface *image;
        SDL_Surface *screen;
        Dot* dot;
        bool dotCollides();
bool pointIsInBlock(int point_x,int point_y);
        Block(int x,int y,int width,int height,SDL_Surface *image,SDL_Surface *screen,Dot* dot);
        virtual ~Block();
        void show();
        void logic();
    protected:
    private:
};

#endif // BLOCK_H
