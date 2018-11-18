#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include "color.h"
#include "point.h"
#include "SDL_Plotter.h"

using namespace std;

class font{
private:

    color c;
    int size;

public:

    font(int, color);
    font(color);

    void setColor(color);
    void setSize(int);

    color getColor();
    int getSize();

    void draw(char[], SDL_Plotter&, point);



};

#endif // FONT_H_INCLUDED
