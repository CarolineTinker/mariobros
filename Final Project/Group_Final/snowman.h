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
        // circle
        color clr;
        point center;
        int radius;
        int speed;
        point prev_center;

        // rectangles
        point p1, p2; // eye 1
        point p3, p4; // eye 2
        point p5, p6; // sunglasses frame
        point pc1,pc2;       //Cigarettes
        color c;

        //lines
        double slope = 1;
        int lineX;

        int timeSmoke = 0;
        int prev_lineX;
        int prev_y;

        // color
        color background;
//        color cigarette;

        //eraser
        point eraser1, eraser2; // erase left
        point eraser3, eraser4; // erase right

    public:
        double eraseSmoke = 1.4;
        int changeX = 0, changeY = 0;
        bool moveRight = false;
        bool moveLeft = false;
        bool moveUp = false;
        bool moveDown = false;
        bool eraseLeft = false;
        bool eraseLeft2 = false;
        bool eraseRight = false;
        bool eraseRight2 = false;
        // circle
        snowman();
        snowman(point, int, color = BLACK);

        point getCenter();
        int getRadius();
        color getColor();
        int getSpeed(){return speed;}

        int getChangeY();
        void setChangeY(int);

        void setCenter(point);
        void setRadius(int);
        void setColor(color);
        void setSpeed(int s){ speed = s;}

        void draw(SDL_Plotter& g);
        void erase(SDL_Plotter &g);
        void move(DIRECTION);

        // rectangles
        snowman(point a, point b, color = BLACK);

        point getP1();
        point getP2();

        void setP1(point p);
        void setP2(point p);
};

#endif // SNOWMAN_H_INCLUDED
