#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include "color.h"
#include "point.h"
#include "SDL_Plotter.h"
#include <fstream>

using namespace std;

class font{
private:

    color c;
    int size;

public:

    font();
    font(int, color);
    font(color);

    void setColor(color);
    void setSize(int);

    color getColor();
    int getSize();

    void draw(string filename, SDL_Plotter& g, point p);



};

const char A('a.txt');

#endif // FONT_H_INCLUDED
