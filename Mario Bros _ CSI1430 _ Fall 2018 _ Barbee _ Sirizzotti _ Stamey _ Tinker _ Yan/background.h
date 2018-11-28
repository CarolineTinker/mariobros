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
 Date Last Modified: 11/17/18
 */

#ifndef background_h
#define background_h

#include "headers.h"
#include "blocks.h"
#include "fireplace.h"
#include "chimney.h"
#include "point.h"
#include "rectangle.h"



class background{
    private:
        //int blockCount;
        //int chimneyCount;
        block blocks[100];
        rectangle base;
        fireplace f1, f2;
        chimney ch1, ch2;

    public:
        background();
        //background(block b[], int sb, fireplace fp1, fireplace fp2);
        void drawBackground(SDL_Plotter& g);


};

#endif /* background_h */
