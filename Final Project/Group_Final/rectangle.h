#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"

class rectangle
{
    private:
        point p1, p2;
        color c;

    public:
        rectangle();
        rectangle(point a, point b, color = BLACK);

        point getP1();
        point getP2();
        color getColor();

        void setP1(point p);
        void setP2(point p);
        void setColor(color a);

        void draw(SDL_Plotter& g);
};

#endif // RECTANGLE_H_INCLUDED
