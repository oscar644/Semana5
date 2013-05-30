/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Timer.h"
#include "Particle.h"
#include "Dot.h"
#include <string>
#include <cstdlib>
#include "block.h"
#define PI 3.14159265
#include <list>
#include "Player.h"

//The surfaces

const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 60;

//The surfaces
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Semana 5", NULL );

    //Seed random
    srand( SDL_GetTicks() );

    //If everything initialized fine
    return true;
}

void clean_up()
{
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //The frame rate regulator
    Timer fps;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //The dot that will be used
    Dot myDot(screen);
    SDL_Surface *block_image = load_image("block.png");
    SDL_Surface *play_image = load_image("cubo.png");
    Block *block = new Block(100,100,100,25,block_image,screen,&myDot);
    Block *block2 = new Block(210,100,100,25,block_image,screen,&myDot);
    Block *block3 = new Block(320,100,100,25,block_image,screen,&myDot);
    block->life =3;
    block3->life=5;
    std::list<Block*>block_list;
    block_list.push_back(block);
    block_list.push_back(block2);
    block_list.push_back(block3);
    Player *play= new Player(210,400,100,25,play_image,screen,&myDot);
    //While the user hasn't quit
    while( quit == false )
    {

        //Start the frame timer
        fps.start();

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the dot
            myDot.handle_input();
if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {

                   case SDLK_LEFT:
                    //play->ismove();
                    play->x-=50;
                    break;
                   case SDLK_RIGHT:
                    play->x+=50;

                }
            }
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }


        //Move the dot

        myDot.move();
 play->logic();

        std::list<Block*>::iterator inte=block_list.begin();
        while(inte!=block_list.end()){
            Block* block_temp=*inte;
            block_temp->logic();
            if(block_temp->life<=0){
                block_list.erase(inte);
                inte--;

            }
            inte++;
        }


        /*if (block != 0){
        block->logic();
        if (block->life <= 0){
            delete block;
            block = 0;
        }
        }
        if (block2 != 0){
        block2->logic();
        if (block2->life <= 0){
            delete block2;
            block2 = 0;
        }
        }*/


        //Fill the screen white
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

        //Show the dot on the screen

        myDot.show();

        inte=block_list.begin();
        while(inte!=block_list.end()){
            Block* block_temp=*inte;
            if(block_temp!=0)
            block_temp->show();
            inte++;
        }
        play->show();

        /*if (block != 0){
        block->show();
        }
        if (block2 != 0){
        block2->show();
        }*/
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    //Clean up
    clean_up();

    return 0;
}
