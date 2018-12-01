
/*
 Assignment Title: Group Project
 Assignment Description: chimney
 Due Date: 12/3/18
 Date Created: 10/?/18
 Date Last Modified: 11/28/18 -Ben
 */
 #ifndef CHIMNEY_H_INCLUDED
#define CHIMNEY_H_INCLUDED

#include "rectangle.h"
#include "point.h"
#include "SDL_Plotter.h"
#include "color.h"
#include "snowman.h"

class chimney{
    public:
        rectangle r1, r2, r3;
    public:
        chimney();
        chimney(rectangle a, rectangle b, rectangle c);

        void drawChimney(SDL_Plotter& g);
        void snowmanEnter(snowman& s);

};


#endif // CHIMNEY_H_INCLUDED
