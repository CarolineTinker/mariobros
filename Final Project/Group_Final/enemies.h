#ifndef ENEMIES_H_INCLUDED
#define ENEMIES_H_INCLUDED

#include "headers.h"

class enemies
{
    private:
        color clr;
        point center, prev_center;
        int radius;
        int speed;
    public:
        enemies();
        enemies(point, int, color = RED);

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

#endif // ENEMIES_H_INCLUDED
