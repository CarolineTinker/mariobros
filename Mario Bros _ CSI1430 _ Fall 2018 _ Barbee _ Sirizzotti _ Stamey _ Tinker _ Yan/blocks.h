/*
 Author:
 Elisabeth Barbee
 Ben Sirizzotti
 Landon Stamey
 Caroline Tinker
 Zhenbo Yan
 Assignment Title: Group Project
 Assignment Description: Mario Bros
 Due Date: 12/3/18
 Date Created: 10/?/18
 Date Last Modified: 11/18/18
 */
#ifndef blocks_h
#define blocks_h

#include "rectangle.h"
#include "point.h"


class block{
    public:
        rectangle b;

    public:
        //constructors
        block();
        block(point p1, point p2, color clr);

        //functions

        /*
         description: test for snowman and block
                      collision
         return: void
         precondition: snowman and block exist
         postcondition: coin count changes from 1 to 0
        */
        //void collide(snowman s);


        /*
         description: draws the block to SDL_Plotter
         return: void
         precondition: block(s) exist
         postcondition: plotter g by reference
        */
        void drawBlock(SDL_Plotter& g);


};


#endif /* blocks_h */
