#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "point.h"
#include "rectangle.h"
#include "circle.h"
#include "color.h"
#include "SDL_Plotter.h"
#include <iostream>
#include <fstream>
using namespace std;

void draw(char [],SDL_Plotter&,point);
void drawRECT(char fileName[], SDL_Plotter&);
void drawCIRC(char fileName[], SDL_Plotter&);
void drawFromFile(char fileName[], SDL_Plotter&);

#endif // USER_H_INCLUDED
