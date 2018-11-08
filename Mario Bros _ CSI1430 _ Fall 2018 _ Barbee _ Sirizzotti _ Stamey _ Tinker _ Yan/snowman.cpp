#include "snowman.h"

snowman::snowman()
{
    center.x = XSTART;
    center.y = YSTART;
    radius = BODY;
    clr = LIGHTBLUE;
    speed = 1;

    prev_center = center;
}

snowman::snowman(point p, int r, color c )
{
    center = p;
    radius = r;
    clr = c;

    prev_center =  center;
}

point snowman::getCenter()
{
    return center;
}

int snowman::getRadius()
{
    return radius;
}

color snowman::getColor()
{
    return clr;
}

void snowman::setCenter(point p)
{
    center = p;
}

void snowman::setRadius(int r)
{
    radius = r;
}

void snowman::setColor(color c)
{
    clr = c;
}

void snowman::draw(SDL_Plotter& g)
{
    if(prev_center.x != center.x  || prev_center.y != center .y){
        erase(g);
        prev_center = center;

        for (int x = -HAT; x <= HAT; x ++){
            for (int y = -HAT; y <= HAT; y+=2){
                if(point(0,0).distance(point(x,y)) <= HAT){
                    // put a guard here
                    g.plotPixel(center.x + x , center.y + y - BODY - HEAD - 2*HEAD_AND_BODY_OVERLAP , 0, 0, 0); //light blue color
                }
            }
        }

        for (int x = -BODY; x <= BODY; x ++){
            for (int y = -BODY; y <= BODY; y++){
                if(point(0,0).distance(point(x,y)) <= BODY){
                    // put a guard here
                    g.plotPixel(center.x + x , center.y + y , 135, 204, 251); //light blue color
                }
            }
        }


        for (int x = -HEAD; x <= HEAD; x ++){
            for (int y = -HEAD; y <= HEAD; y++){
                if(point(0,0).distance(point(x,y)) <= HEAD){
                    // put a guard here
                    g.plotPixel(center.x + x , center.y + y - BODY - HEAD + HEAD_AND_BODY_OVERLAP , 135, 204, 251); // Draw head
                }
            }
        }


        for (int x = -EYE; x <= EYE; x ++){
            for (int y = -EYE; y <= EYE; y++){
                if(point(0,0).distance(point(x,y)) <= EYE){
                    // put a guard here
                    g.plotPixel(center.x + x - 4*EYE, center.y + y - HEAD - HEAD - HEAD_AND_BODY_OVERLAP , 0, 0, 0); // left black eyes
                }
            }
        }

        for (int x = -EYE; x <= EYE; x ++){
            for (int y = -EYE; y <= EYE; y++){
                if(point(0,0).distance(point(x,y)) <= EYE){
                    // put a guard here
                    g.plotPixel(center.x + x + 4*EYE, center.y + y - HEAD - HEAD - HEAD_AND_BODY_OVERLAP , 0, 0, 0); // right black eyes
                }
            }
        }

        for (int x = -BUTTON; x <= BUTTON; x ++){
            for (int y = -BUTTON; y <= BUTTON; y++){
                if(point(0,0).distance(point(x,y)) <= BUTTON){
                    // put a guard here
                    g.plotPixel(center.x + x, center.y + y - 1.5* static_cast<double>(HEAD_AND_BODY_OVERLAP) , 0, 167, 0); // green top button
                }
            }
        }

        for (int x = -BUTTON; x <= BUTTON; x ++){
            for (int y = -BUTTON; y <= BUTTON; y++){
                if(point(0,0).distance(point(x,y)) <= BUTTON){
                    // put a guard here
                    g.plotPixel(center.x + x, center.y + y + HEAD_AND_BODY_OVERLAP , 255, 0, 0); // red bottom button
                }
            }
        }


        for (int x = -NOSE; x <= NOSE; x ++){
            for (int y = -NOSE; y <= NOSE; y++){
                if(point(0,0).distance(point(x,y)) <= NOSE){
                    // put a guard here
                    g.plotPixel(center.x + x , center.y + y - BODY - HEAD + 1.7* static_cast<double>(HEAD_AND_BODY_OVERLAP) , 255, 153, 0); // nose color
                }
            }
        }
    }
}

void snowman::erase(SDL_Plotter &g){


        for (int x = -BODY; x <= BODY; x ++){
            for (int y = -BODY; y <= BODY; y++){
                if(point(0,0).distance(point(x,y)) <= BODY){
                    g.plotPixel(prev_center.x + x , prev_center.y + y ,255 ,255 ,255); // erase to background color
                }
            }
        }

        for (int x = -HEAD; x <= HEAD; x ++){
            for (int y = -HEAD; y <= HEAD; y++){
                if(point(0,0).distance(point(x,y)) <= HEAD){
                    g.plotPixel(prev_center.x + x , prev_center.y + y - BODY - HEAD + HEAD_AND_BODY_OVERLAP,255 ,255 ,255); // erase head
                }
            }
        }

        for (int x = -HAT; x <= HAT; x ++){
            for (int y = -HAT; y <= HAT; y+=2){
                if(point(0,0).distance(point(x,y)) <= HAT){
                    // put a guard here
                    g.plotPixel(prev_center.x + x , prev_center.y + y - BODY - HEAD - 2*HEAD_AND_BODY_OVERLAP , 255, 255, 255); //light blue color
                }
            }
        }
//         for (int x = -EYE; x <= EYE; x ++){
//            for (int y = -EYE; y <= EYE; y++){
//                if(point(0,0).distance(point(x,y)) <= EYE){
//                    // put a guard here
//                    g.plotPixel(center.x + x - 4*EYE, center.y + y - HEAD - HEAD - HEAD_AND_BODY_OVERLAP , 255, 255, 255); // left black eyes
//                }
//            }
//        }
//
//        for (int x = -EYE; x <= EYE; x ++){
//            for (int y = -EYE; y <= EYE; y++){
//                if(point(0,0).distance(point(x,y)) <= EYE){
//                    // put a guard here
//                    g.plotPixel(center.x + x + 4*EYE, center.y + y - HEAD - HEAD - HEAD_AND_BODY_OVERLAP , 255, 255, 255); // right black eyes
//                }
//            }
//        }
    }


void snowman::move(DIRECTION d){
    prev_center = center;
    switch (d){
        case RIGHT: center.x += speed;
                    break;

        case LEFT: center.x -= speed;
                    break;

        case UP: center.y -= speed;
                    break;

        case DOWN: center.y += speed;
                    break;

        }
}
