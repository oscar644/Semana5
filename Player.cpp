#include "Player.h"

Player::Player()
{
    //ctor
}

Player::Player(float x, float y, int width, int height,SDL_Surface *image,SDL_Surface *screen, Dot *dot){
this->x = x;
this->y = y;
this->width = width;
this->height = height;
this->screen = screen;
this->image = image;
this->dot = dot;
this->isColliding = false;
this->wasColliding = false;
}

void Player::show(){
apply_surface( x, y, image, screen);
}

void Player::logic(){

  //  int dotHeight = dot->y + dot->DOT_HEIGHT;
        int collision = collisionType();
        if(!wasColliding){
        switch(collision){
        case 0:
        break;

        case TOP2:
                dot->angle = -dot->angle;
                dot->angle += rand()%10 - 20;

            break;
        case BOT2:
            dot->angle = -dot->angle;
            dot->angle += rand()%10 - 20;

            break;

        case RIGHT2: case LEFT2:
            dot->angle = -dot->angle+180;
            dot->angle += rand()%10 - 20;
            break;
         case CORNERUL2:
             dot->velocity = abs(dot->velocity);
             dot->angle = 315;
             dot->angle += rand()%5-10;
             break;
        case CORNERUR2:
            dot->velocity = abs(dot->velocity);
             dot->angle = 225;
             dot->angle += rand()%5-10;
             break;
        case CORNERDR2:
            dot->velocity = abs(dot->velocity);
             dot->angle = 135;
             dot->angle += rand()%5-10;
             break;
        case CORNERDL2:
            dot->velocity = abs(dot->velocity);
             dot->angle = 45;
             dot->angle += rand()%5-10;
             }

        }

}

bool Player::isPointInside(float pointX, float pointY){
if(    pointX > this->x
       && pointX < this->x+this->width
       && pointY > this->y
       && pointY < this->y + this->height){
       return true;
       }
       return false;
}

int Player::collisionType(){
        // ESQUINA SUPERIOR IZQUIERDA   dot->x                  dot->y
        // ESQUINA SUPERIOR DERECHA     dot->x + DOT_WIDTH      dot->y
        // ESQUINA INFERIOR IZQUIERDA   dot->x                  dot->y + DOT_HEIGHT
        // ESQUINA INFERIOR DERECHA     dot->x + DOT_WIDTH      dot->y + DOT_HEIGHT
        float posX = dot->x;
        float posXMid = dot->x + (dot->DOT_WIDTH/2);
        float posXEnd = dot->x + dot->DOT_WIDTH;
        float posY = dot->y, posYMid = dot->y+ dot->DOT_HEIGHT/2, posYEnd = dot->y + dot->DOT_HEIGHT;

        if(this->isColliding){
            this->wasColliding = true;
        } else {
        this->wasColliding =false;
        }

        this->isColliding = false;
        if (!this->wasColliding){
        if(    isPointInside(posX,posY)
                &&
                isPointInside(posXMid,posY)
                ||
               isPointInside(posXMid,posY)
                &&
                 isPointInside(posXEnd,posY)
                ){
                    this->isColliding = true;
                    return TOP2;
        } else if (
                   isPointInside(posX,posYEnd)
                && isPointInside(posXMid,posYEnd)
                ||
                 isPointInside(posXMid,posYEnd)
                && isPointInside(posXEnd,posYEnd)

                ){
                    this->isColliding = true;
                    return BOT2;

        }else if (

                  isPointInside(posX,posY)
            &&
                isPointInside(posX,posYMid)
                ||
                 isPointInside(posX,posYMid)
               && isPointInside(posX,posYEnd)

                   ){
                        this->isColliding = true;
                        return LEFT2;
        }else if (

                  isPointInside(posXEnd,posY)
                &&
                isPointInside(posXEnd,posYMid)
                ||
                 isPointInside(posXEnd,posYMid)
                && isPointInside(posXEnd,posYEnd)

                   ){
                    this->isColliding = true;
                    return RIGHT2;
        }else if (isPointInside(posX,posY)){
        return CORNERUL2;
        }else if(isPointInside(posX,posYEnd)){
        return CORNERDL2;
        }else if(isPointInside(posXEnd,posY)){
        return CORNERUR2;
        }else if(isPointInside(posXEnd,posYEnd)){
        return CORNERDR2;
        }

        }

        return 0;
}


void Player::ismove(){
        this->x-=100;
}


Player::~Player()
{
     SDL_FreeSurface( image );
    //dtor
}
