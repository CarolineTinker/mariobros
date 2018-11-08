#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <ostream>
#include "point.h"
#include "SDL_Plotter.h"
#include "color.h"

using namespace std;

class line
{
private:
    point p1, p2;
    color c;
    bool slope(double&);
    double y_inter();

public:
    line();
    line(point, point);
    point getP1();
    point getP2();
    color getColor();

    void setP1(point);
    void setP2(point);
    void setColor(color);

    void draw(ostream&);
    void draw(SDL_Plotter&);
};

#endif // LINE_H_INCLUDED
