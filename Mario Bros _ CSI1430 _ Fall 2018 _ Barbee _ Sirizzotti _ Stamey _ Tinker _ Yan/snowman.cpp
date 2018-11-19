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
// rectangles
snowman::snowman(point a, point b, color clr)
{
    p1 = a;
    p2 = b;
    c = clr;

}
point snowman::getP1()
{
    return p1;
}

point snowman::getP2()
{
    return p2;
}
void snowman::setP1(point p)
{
    p1 = p;
}

void snowman::setP2(point p)
{
    p2 = p;
}
// drawing

// rectangles
int snowman::getChangeY(){
    return changeY;
}
void snowman::setChangeY(int a){
    changeY = a;
}
void snowman::draw(SDL_Plotter& g)
{
    background.R = 255;
    background.G = 255;
    background.B = 255;
//    cigarette.R =
//    cigarette.G =
//    cigarette.B =
    if(prev_center.x != center.x  || prev_center.y != center .y){
        erase(g);
        prev_center = center;
        //eye 1
        p1.x = XSTART - 10;
        p1.y = YSTART - 39;
        p2.x = XSTART - 5;
        p2.y = YSTART - 33;

        //eye 2
        p3.x = XSTART + 5;
        p3.y = YSTART - 39;
        p4.x = XSTART + 10;
        p4.y = YSTART - 33;

        //frame
        p5.x = XSTART - 10;
        p5.y = YSTART - 37;
        p6.x = XSTART + 10;
        p6.y = YSTART - 36.5;

        //Cigarettes
        pc1.x = XSTART ;
        pc1.y = YSTART ;
        pc2.x = XSTART + 10;
        pc2.y = YSTART - 36.5;
    // circles
//        for (int x = -HAT; x <= HAT; x ++){
//            for (int y = -HAT; y <= HAT; y+=2){
//                if(point(0,0).distance(point(x,y)) <= HAT){
//                    // put a guard here
//                    g.plotPixel(center.x + x , center.y + y - BODY - HEAD - 2*HEAD_AND_BODY_OVERLAP , 0, 0, 0); //light blue color
//                }
//            }
//        }


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


//        for (int x = -EYE; x <= EYE; x ++){
//            for (int y = -EYE; y <= EYE; y++){
//                if(point(0,0).distance(point(x,y)) <= EYE){
//                    // put a guard here
//                    g.plotPixel(center.x + x - 4*EYE, center.y + y - HEAD - HEAD - HEAD_AND_BODY_OVERLAP , 0, 0, 0); // left black eyes
//                }
//            }
//        }
//
//        for (int x = -EYE; x <= EYE; x ++){
//            for (int y = -EYE; y <= EYE; y++){
//                if(point(0,0).distance(point(x,y)) <= EYE){
//                    // put a guard here
//                    g.plotPixel(center.x + x + 4*EYE, center.y + y - HEAD - HEAD - HEAD_AND_BODY_OVERLAP , 0, 0, 0); // right black eyes
//                }
//            }
//        }

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


//        for (int x = -NOSE; x <= NOSE; x ++){
//            for (int y = -NOSE; y <= NOSE; y++){
//                if(point(0,0).distance(point(x,y)) <= NOSE){
//                    // put a guard here
//                    g.plotPixel(center.x + x , center.y + y - BODY - HEAD + 1.7* static_cast<double>(HEAD_AND_BODY_OVERLAP) , 255, 153, 0); // nose color
//                }
//            }
//        }
    }



        for (int x = p1.x; x <= p2.x; x++){
            for (int y = p1.y; y <= p2.y; y++){
                g.plotPixel(x + changeX, y + changeY, c.R, c.G, c.B); // sunglasses black
        }
    }

        for (int x = p3.x; x <= p4.x; x++){
            for (int y = p3.y; y <= p4.y; y++){
                g.plotPixel(x + changeX, y + changeY, c.R, c.G, c.B); // sunglasses black
        }
    }

        for (int x = p5.x; x <= p6.x; x++){
            for (int y = p5.y; y <= p6.y; y++){
                g.plotPixel(x + changeX, y + changeY, c.R, c.G, c.B); // sunglasses black
        }
    }

        for (int x = pc1.x; x <= pc2.x; x++){
            for (int y = pc1.y; y <= pc2.y; y++){
                g.plotPixel(x + changeX, y + changeY, c.R, c.G, c.B); // sunglasses black
        }
    }

    // cigarettes

    // when moving to the right
    if(moveRight){
            for (double y = YSTART - BODY - 3; y < YSTART -BODY - 3 + 7; y+=0.5)
            {
                lineX = -slope * y + YSTART - XSTART - 21;
                g.plotPixel(lineX+changeX, y + changeY,  128,64, 0); //cigarette butt
                g.plotPixel(lineX+changeX + 0.5, y+0.5 + changeY,  128,64, 0);
                g.plotPixel(lineX+changeX + 1, y+1 + changeY, 128,64, 0);
            }

            for (double y = YSTART - BODY - 7; y < YSTART -BODY - 3; y+=0.5)
            {
                lineX = -slope * y + YSTART - XSTART - 21;

                g.plotPixel(lineX+changeX + 0.5, y+0.5 + changeY, 255, 0, 0); // red
                g.plotPixel(lineX+changeX + 1, y+1 + changeY,  255, 0, 0);
                g.plotPixel(lineX+changeX + 1.5, y+1.5 + changeY,  255, 0, 0);
                g.plotPixel(lineX+changeX + 2, y+2 + changeY,  255, 0, 0);
            }
            // smoke
            if(!moveUp){
                for (double y = YSTART - BODY - 14; y <  YSTART -BODY - 10; y+=0.5)
                {
                    lineX = -y/3  - YSTART + XSTART - 15;
                    g.plotPixel(lineX+changeX-1, y + changeY,  128,64, 0); //smoke
                    g.plotPixel(lineX+changeX+2, y + changeY,  128,64, 0); //smoke
                        if (center.x > 400){
                    g.plotPixel(lineX+changeX-1, y + changeY-4,  128,64, 0); //smoke
                    g.plotPixel(lineX+changeX+2, y + changeY-4,  128,64, 0); //smoke
                        }
                        if (center.x > 490){
                    g.plotPixel(lineX+changeX-1, y + changeY-8,  128,64, 0); //smoke
    //                g.plotPixel(lineX+changeX, y + changeY-8,  128,64, 0); //smoke
                        }
                }
            }
    }

        // when moving to the left
        if(moveLeft){
            for (double y = YSTART - BODY - 4; y < YSTART -BODY - 4 + 6; y+=0.5)
            {
                lineX = slope * y - YSTART + XSTART + 22;
                g.plotPixel(lineX+changeX, y + changeY,  128,64, 0); //cigarette butt
                g.plotPixel(lineX+changeX - 0.5, y+0.5 + changeY,  128,64, 0);
                g.plotPixel(lineX+changeX - 1, y+1 + changeY, 128,64, 0);
            }

            for (double y = YSTART - BODY - 8; y < YSTART -BODY - 4; y+=0.5)
            {
                lineX = slope * y - YSTART + XSTART + 22;

                g.plotPixel(lineX+changeX - 0.5, y+0.5 + changeY, 255, 0, 0); // red
                g.plotPixel(lineX+changeX - 1, y+1 + changeY,  255, 0, 0);
                g.plotPixel(lineX+changeX - 1.5, y+1.5 + changeY,  255, 0, 0);
                g.plotPixel(lineX+changeX - 2, y+2 + changeY,  255, 0, 0);
            }
            // smoke
            if (!moveUp){
                for (double y = YSTART - BODY - 15; y <  YSTART -BODY - 11; y+=0.5)
                {
                    lineX = y/3  + YSTART - XSTART + 13;
                    g.plotPixel(lineX+changeX-1, y + changeY,  128,64, 0); //smoke
                    g.plotPixel(lineX+changeX+2, y + changeY,  128,64, 0); //smoke
                        if(center.x < 290){
                            g.plotPixel(lineX+changeX-1, y + changeY-4,  128,64, 0); //smoke
                            g.plotPixel(lineX+changeX+2, y + changeY-4,  128,64, 0); //smoke
                        }
                        if(center.x < 200){
    //                        g.plotPixel(lineX+changeX-1, y + changeY-8,  128,64, 0); //smoke
                            g.plotPixel(lineX+changeX+3, y + changeY-7,  128,64, 0); //smoke
                        }
                }
            }
    }

}

void snowman::erase(SDL_Plotter &g){
        if(moveLeft){
            for (double y = YSTART - BODY - 15; y <  YSTART -BODY - 11; y+=0.5)
            {
                lineX = y/3  + YSTART - XSTART + 13;
                g.plotPixel(lineX+changeX-1, y + changeY+10,   background.R, background.G, background.B); //smoke
                g.plotPixel(lineX+changeX+2, y + changeY+10,   background.R, background.G, background.B); //smoke
                    if(center.x < 290){
                        g.plotPixel(lineX+changeX-1, y + changeY+6, background.R, background.G, background.B); //smoke
                        g.plotPixel(lineX+changeX+2, y + changeY+6,   background.R, background.G, background.B); //smoke
                    }
                    if(center.x < 200){
//                        g.plotPixel(lineX+changeX-1, y + changeY-8,  128,64, 0); //smoke
                        g.plotPixel(lineX+changeX+3, y + changeY+3,   background.R, background.G, background.B); //smoke
                    }
            }
    }
    // smoke eraser
    if(eraseLeft and eraseLeft2){
        eraser1.x =XSTART-34;
        eraser1.y =YSTART-45;
        eraser2.x =XSTART-29;
        eraser2.y =YSTART-35;
        for (int x = eraser1.x; x <= eraser2.x; x++){
                for (int y = eraser1.y; y <= eraser2.y; y++){
                    g.plotPixel(x + changeX, y + changeY,  background.R, background.G, background.B); // erase to background color
            }
        }
        eraseLeft2 = false;
    }

        if(moveRight){
                for (double y = YSTART - BODY - 14; y <  YSTART -BODY - 10; y+=0.5)
                {
                    lineX = -y/3  - YSTART + XSTART - 15;
                    g.plotPixel(lineX+changeX-1, y + changeY+10,   background.R, background.G, background.B); //smoke
                    g.plotPixel(lineX+changeX+2, y + changeY+10,   background.R, background.G, background.B); //smoke
                        if (center.x > 400){
                    g.plotPixel(lineX+changeX-1, y + changeY+6,   background.R, background.G, background.B); //smoke
                    g.plotPixel(lineX+changeX+2, y + changeY+6,   background.R, background.G, background.B); //smoke
                        }
                        if (center.x > 490){
                    g.plotPixel(lineX+changeX-1, y + changeY+2,   background.R, background.G, background.B); //smoke
    //                g.plotPixel(lineX+changeX, y + changeY-8,  128,64, 0); //smoke
                        }
                }
    }
    if(eraseRight and eraseRight2){
        eraser3.x =XSTART+25;
        eraser3.y =YSTART-46;
        eraser4.x =XSTART+33;
        eraser4.y =YSTART-35;
        for (int x = eraser3.x; x <= eraser4.x; x++){
                for (int y = eraser3.y; y <= eraser4.y; y++){
                    g.plotPixel(x + changeX, y + changeY,  background.R, background.G, background.B); // erase to background color
            }
        }
        eraseRight2 = false;
    }

    for (int x = -BODY; x <= BODY; x ++){
        for (int y = -BODY; y <= BODY; y++){
            if(point(0,0).distance(point(x,y)) <= BODY){
                g.plotPixel(prev_center.x + x , prev_center.y + y , background.R, background.G, background.B); // erase to background color
            }
        }
    }


    for (int x = -HEAD; x <= HEAD; x ++){
        for (int y = -HEAD; y <= HEAD; y++){
            if(point(0,0).distance(point(x,y)) <= HEAD){
                g.plotPixel(prev_center.x + x , prev_center.y + y - BODY - HEAD + HEAD_AND_BODY_OVERLAP, background.R, background.G, background.B); // erase head
            }
        }
    }

//    for (int x = -HAT; x <= HAT; x ++){
//        for (int y = -HAT; y <= HAT; y+=2){
//            if(point(0,0).distance(point(x,y)) <= HAT){
//                // put a guard here
//                g.plotPixel(prev_center.x + x , prev_center.y + y - BODY - HEAD - 2*HEAD_AND_BODY_OVERLAP , background.R, background.G, background.B); //light blue color
//            }
//        }
//    }
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
                    changeX += speed;
                    moveRight = true;
                    moveLeft =false;
//                    moveDown = false;
                    moveUp = false;
                    eraseLeft = true;
                    eraseRight = false;
                    eraseRight2 = true;
                    break;

        case LEFT: center.x -= speed;
                    changeX -= speed;
                    moveLeft = true;
                    moveRight = false;
//                    moveDown = false;
                    moveUp = false;
                    eraseRight = true;
                    eraseLeft = false;
                    eraseLeft2 = true;
                    break;

        case UP:

//                    center.y -= speed;
//                    changeY -= speed;
                    moveUp = true;
//                    moveDown = false;
                    break;

        case DOWN: center.y += speed;
                    changeY += speed;
//                    moveDown =true;
                    moveUp = false;
                    break;

        }
}
