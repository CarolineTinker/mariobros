#ifndef FIREPLACE_H_INCLUDED
#define FIREPLACE_H_INCLUDED

#include "rectangle.h"
#include "color.h"
#include "SDL_Plotter.h"
#include "snowman.h"
#include "point.h"

class fireplace{
    public:
        rectangle r1, r2, r3, r4;
    public:
        fireplace();
        fireplace(rectangle a, rectangle b, rectangle c, rectangle d);

        void drawFireplace(SDL_Plotter& g);
        void snowmanEnter(snowman& s, SDL_Plotter& g);



};

#endif // FIREPLACE_H_INCLUDED
