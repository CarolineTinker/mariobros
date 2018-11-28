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
        chimney(rectangle a, rectangle b, rectangle c);

        void drawChimney(SDL_Plotter& g);
        void snowmanEnter(snowman& s);

};


#endif // CHIMNEY_H_INCLUDED
