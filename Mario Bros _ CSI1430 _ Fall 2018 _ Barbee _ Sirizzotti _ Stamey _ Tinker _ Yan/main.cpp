#include <fstream>
#include <iostream>
#include "line.h"
#include "SDL_Plotter.h"
#include "rectangle.h"
#include "circle.h"
#include "snowman.h"
#include "enemies.h"
#include "background.h"

using namespace std;

void draw(char [], SDL_Plotter&, point);

// -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer

int main(int argc, char** argv)
{
    SDL_Plotter g(750, 750);
    snowman sman; // snow man is called sman
    sman.setSpeed(10);
    
    background b;
    b.drawBackground(g);

//    rectangle r1, r2(point(25, 25), point(300, 150), RED);
//    int delay = 100;
//
//    line lineOne(point(100, 25), point(101, 300)), lineTwo(point(0, 0), point(499, 499));
//    int count = 0;
//
//    lineOne.setColor(RED);

    while(!g.getQuit())
    {
        if (g.kbhit())
        {
            switch(g.getKey())
            {
                case RIGHT_ARROW: sman.move(RIGHT);
                          break;
                case LEFT_ARROW: sman.move(LEFT);
                          break;
                case UP_ARROW: sman.move(UP);
                        for(int i = 15; i > 0; i--){
                            point newCenter;
                            newCenter.x = sman.getCenter().x;
                            newCenter.y = sman.getCenter().y - i;
                            sman.setCenter(newCenter);

                            //sman.setChangeY(changeY - i);
                            sman.draw(g);
                            g.update();
                        }
                        g.Sleep(100);
                        for(int i = 0; i <= 15; i++){
                            point newCenter;
                            newCenter.x = sman.getCenter().x;
                            newCenter.y = sman.getCenter().y + i;
                            sman.setCenter(newCenter);

                            //sman.setChangeY(changeY + i);
                            sman.draw(g);
                            g.update();
                        }
                          break;
                case DOWN_ARROW: sman.move(DOWN);
                          break;
                case 'A'       : draw("A.txt", g, point(200,200));
            }
//            if(center.y - radius < 0) center.y = radius;
//            if(center.x - radius < 0) center.x = radius;
        }
            sman.draw(g);
            g.update();
        }


//        newColor.R = rand()%255;
//        newColor.G = rand()%255;
//        newColor.B = rand()%255;
//        r1.setColor(newColor);
//        r1.setP1(point(rand()%200, rand()%200));
//        r1.setP2(point(r1.getP1().x + rand()%300, r1.getP1().y + rand()%300));
//
//        r1.draw(g);
//        g.update();
//        g.Sleep(delay);
//        g.clear();
//        if (delay > 0)
//        {
//            delay--;
//        }
//    }

    return 0;
}

void draw(char fileName[], SDL_Plotter& g, point p){
    ifstream file(fileName);
    char value;
    if(!file){
        cout <<"Error File Not Open" << endl;
    }
    int row, col;

    file >> row >> col;

    for (int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            file >> value;
            if (value == '1'){
                g.plotPixel(p.x+c,p.y+r,0,0,0); // default black
            }
        }
    }

    file.close();
}
