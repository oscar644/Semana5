#include "Block.h"

Block::Block(int x,int y,int width,int height,SDL_Surface *image,SDL_Surface *screen,Dot* dot)
{
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    this->image=image;
    this->screen=screen;
    this->dot=dot;
    //ctor
}

Block::~Block()
{
    //dtor
}
void Block::show(){
apply_surface(x,y,image,screen);
}
bool Block::dotCollides(){
if(pointIsInBlock(dot->x,dot->y))
    return true;
if(pointIsInBlock(dot->x+dot->DOT_WIDTH,dot->y))
    return true;
    if(pointIsInBlock(dot->x,dot->y+dot->DOT_HEIGHT))
    return true;
    if(pointIsInBlock(dot->x+dot->DOT_WIDTH,dot->y+dot->DOT_HEIGHT))
        return true;

    return false;
}
bool Block::pointIsInBlock(int point_x,int point_y){
if(point_x>this->x
   &&point_x<this->x+this->width
   &&point_y>this->y
   &&point_y<this->y+this->height)
   return true;

   return false;
}
void Block::logic(){
if(dotCollides())
{
    dot->angle+=60;
    this->x=1000;
}
}
