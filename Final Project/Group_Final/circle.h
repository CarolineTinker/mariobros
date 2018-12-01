#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"
#include "constants.h"

class circle
{
    private:
        color clr;
        point center, prev_center;
        int radius;
        int speed;

    public:
        circle();
        circle(point, int, color = BLACK);

        point getCenter();
        int getRadius();
        color getColor();
        int getSpeed(){return speed;};  //inlining

        void setCenter(point);
        void setRadius(int);
        void setColor(color);
        void setSpeed(int s){speed = s;};

        void draw(SDL_Plotter& g);
        void erase(SDL_Plotter& g);
        void move(DIRECTION);
};

#endif // CIRCLE_H_INCLUDED
