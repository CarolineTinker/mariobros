/*
* Author: First_Name Last_Name
* Assignment Title: LetterDisplay
* Assignment Description: will display the given letter
* Due Date:
* Date Created: 11/7/2018
* Date Last Modified: 11/7/2018
 */

#ifndef LETTERSDISPLAY_H_INCLUDED
#define LETTERSDISPLAY_H_INCLUDED

#include "point.h"
#include "SDL_Plotter.h"
#include "ostream"
#include "color.h"


class letterdisplay{
private:
    color c;
    SDL_Plotter g;


public:
    leterdisplay(color, SDL_Plotter& );
    leterdisplay(SDL_Plotter&);

    //change default color
    void setColor(color);

    //when called, will draw the given char with the top left corner at the point
    void draw(char, point);
    void draw(char, point, color);

    //will erase any chars at the given point
    void erase(point);
};

#endif // LETTERSDISPLAY_H_INCLUDED
