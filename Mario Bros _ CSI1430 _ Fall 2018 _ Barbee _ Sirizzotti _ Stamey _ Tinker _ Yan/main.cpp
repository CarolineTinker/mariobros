#include <iostream>
#include <cmath>
#include "point.h"
#include "line.h"
#include "SDL_Plotter.h"
#include "rectangle.h"
#include "circle.h"
#include "headers.h"

class point_t
{
private:
    int x, y;

public:
    point_t();  // no information
    point_t(int);   // one int
    point_t(int, int);  // two ints

    int getX();
    int getY();
    void setX(int);
    void setY(int);

    double distance(point_t);
    point_t midPoint(point_t); // returns a point

};

using namespace std;

int main(int argc, char** argv)
{
/*    color newColor;
    int count = 0;
    rectangle r1, r2(point(25, 25), point(300, 150), RED);
    int delay = 100;

    SDL_Plotter g(500, 500);

    line lineOne(point(100, 25), point(101, 300)), lineTwo(point(0, 0),
            point(499, 499));
    lineOne.setColor(RED);
*/

    SDL_Plotter g(550, 690);
    enemies eman;
    eman.setSpeed(5);

    while (!g.getQuit())
    {
        if(g.kbhit())
        {
            switch (g.getKey())
            {
                case RIGHT_ARROW: eman.move(RIGHT);
                                    break;
                case LEFT_ARROW: eman.move(LEFT);
                                    break;
                case UP_ARROW: eman.move(UP);
                                    break;
                case DOWN_ARROW: eman.move(DOWN);
                                    break;
            }
        }
/*        newColor.R = rand()%255;
        newColor.G = rand()%255;
        newColor.B = rand()%255;

        r1.setColor(newColor);      //change color of rectangle

        r1.setP1(point(rand()%200, rand()%200));    //change location
        r1.setP2(point(r1.getP1().x + rand()%300, r1.getP1().y + rand()%300));
            //ensures p1 remains at the top left

        r1.draw(g);     //draw rectangle
*/
        eman.draw(g);
        g.update();
/*        g.Sleep(delay); //slows down the speed of the plotter
        g.clear();  //erase entire screen
        if (delay > 0)
        {
            delay--;
        }
*/    }
    return 0;
}

point_t::point_t()
{
    x = y = 0;
}

point_t::point_t(int a)
{
    x = a;
    y = 0;
}

point_t::point_t(int a, int b)
{
    x = a;
    y = b;
}

double point_t::distance(point_t other)
{
//    return sqrt(pow(getX() - other.getX, 2) + pow(getY() - other.getY, 2));   //in the
        //same class so they can "see" each other's private data
}

point_t point_t::midPoint(point_t otherPoint)
{
    point_t mp;
    mp.setX((getX() + otherPoint.getX()) / 2.0 + 0.5);  // causes it to round
    mp.setY((getY() + otherPoint.getY()) / 2.0 + 0.5);
    return mp;
    //this one easier to read

    //return point_t(((getX() + otherPoint.getX()) / 2.0 + 0.5),
    //               ((getY() + otherPoint.getY()) / 2.0 + 0.5));
}

int point_t::getX()
{
    return x;
}

int point_t::getY()
{
    return y;
}

void point_t::setX(int xValue)
{
    x = xValue;
}

void point_t::setY(int yValue)
{
    y = yValue;
}
