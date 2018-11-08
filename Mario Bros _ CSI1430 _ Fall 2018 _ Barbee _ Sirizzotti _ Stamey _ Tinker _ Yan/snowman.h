#ifndef SNOWMAN_H_INCLUDED
#define SNOWMAN_H_INCLUDED

#include "color.h"
#include "point.h"
#include "SDL_Plotter.h"
#include "constants.h"
#include "rectangle.h"
class snowman
{
    private:
        color clr;
        point center;
        int radius;
        int speed;
        point prev_center;

    public:
        snowman();
        snowman(point, int, color = BLACK);

        point getCenter();
        int getRadius();
        color getColor();
        int getSpeed(){return speed;}


        void setCenter(point);
        void setRadius(int);
        void setColor(color);
        void setSpeed(int s){ speed = s;}

        void draw(SDL_Plotter& g);
        void erase(SDL_Plotter &g);
        void move(DIRECTION);
};

#endif // SNOWMAN_H_INCLUDED
