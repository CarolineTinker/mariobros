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
                lineX = -slope * y + YSTART - XSTART - 80;
                g.plotPixel(lineX+changeX, y + changeY,  128,64, 0); //cigarette butt
                g.plotPixel(lineX+changeX + 0.5, y+0.5 + changeY,  128,64, 0);
                g.plotPixel(lineX+changeX + 1, y+1 + changeY, 128,64, 0);
            }

            for (double y = YSTART - BODY - 7; y < YSTART -BODY - 3; y+=0.5)
            {
                lineX = -slope * y + YSTART - XSTART - 80;

                g.plotPixel(lineX+changeX + 0.5, y+0.5 + changeY, 255, 0, 0); // red
                g.plotPixel(lineX+changeX + 1, y+1 + changeY,  255, 0, 0);
                g.plotPixel(lineX+changeX + 1.5, y+1.5 + changeY,  255, 0, 0);
                g.plotPixel(lineX+changeX + 2, y+2 + changeY,  255, 0, 0);
            }


    if(moveRight and !moveLeft){
        for (double x = -eraseSmoke; x <= eraseSmoke; x ++){
            for (double y = -eraseSmoke; y <= eraseSmoke; y++){
                if(point(0,0).distance(point(x,y)) <= eraseSmoke){
                    // put a guard here
                    g.plotPixel(center.x + x + 25, center.y + y - 39 , 0, 0, 0); //light blue color
                }
            }
        }
        for (double x = -eraseSmoke; x <= eraseSmoke; x ++){
            for (double y = -eraseSmoke; y <= eraseSmoke; y++){
                if(point(0,0).distance(point(x,y)) <= eraseSmoke){
                    // put a guard here
                    g.plotPixel(center.x + x + 20, center.y + y - 39 , 0, 0, 0); //light blue color
                }
            }
        }
    }
    }
        // when moving to the left
        if(moveLeft and !moveRight){
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

            for (double x = -eraseSmoke; x <= eraseSmoke; x ++){
                for (double y = -eraseSmoke; y <= eraseSmoke; y++){
                    if(point(0,0).distance(point(x,y)) <= eraseSmoke){
                        // put a guard here
                        g.plotPixel(center.x + x - 25, center.y + y - 39 , 0, 0, 0); //light blue color
                    }
                }
            }
            for (double x = -eraseSmoke; x <= eraseSmoke; x ++){
                for (double y = -eraseSmoke; y <= eraseSmoke; y++){
                    if(point(0,0).distance(point(x,y)) <= eraseSmoke){
                        // put a guard here
                        g.plotPixel(center.x + x - 20, center.y + y - 39 , 0, 0, 0); //light blue color
                    }
                }
            }
        }

}


void snowman::erase(SDL_Plotter &g){


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

//    if(moveRight){
        for (double x = -eraseSmoke; x <= eraseSmoke; x ++){
            for (double y = -eraseSmoke; y <= eraseSmoke; y++){
                if(point(0,0).distance(point(x,y)) <= eraseSmoke){
                    // put a guard here
                    g.plotPixel(prev_center.x + x + 25, prev_center.y + y - 39 , 255, 255, 255); //light blue color
                }
            }
        }

        for (double x = -eraseSmoke; x <= eraseSmoke; x ++){
            for (double y = -eraseSmoke; y <= eraseSmoke; y++){
                if(point(0,0).distance(point(x,y)) <= eraseSmoke){
                    // put a guard here
                    g.plotPixel(prev_center.x + x + 20, prev_center.y + y - 39 , 255, 255, 255); //light blue color
                }
            }
        }


//    if(moveLeft){
        for (double x = -eraseSmoke; x <= eraseSmoke; x ++){
            for (double y = -eraseSmoke; y <= eraseSmoke; y++){
                if(point(0,0).distance(point(x,y)) <= eraseSmoke){
                    // put a guard here
                    g.plotPixel(prev_center.x + x - 25, prev_center.y + y - 39 , background.R, background.G, background.B); //light blue color
                }
            }
        }
        for (double x = -eraseSmoke; x <= eraseSmoke; x ++){
            for (double y = -eraseSmoke; y <= eraseSmoke; y++){
                if(point(0,0).distance(point(x,y)) <= eraseSmoke){
                    // put a guard here
                    g.plotPixel(prev_center.x + x - 20, prev_center.y + y - 39 , background.R, background.G, background.B); //light blue color
                }
            }
        }

}


void snowman::move(DIRECTION d){
    prev_center = center;

    switch (d){
        case UP:
//                    center.y -= speed;
//                    changeY -= speed;
                    if(moveRight){
                        rightJump = true;
                    }
                    if(moveLeft){
                        leftJump = true;
                    }
                    moveUp = true;
                    moveDown = false;
//                    moveRight = false;
//                    moveLeft = false;

                    break;
        case RIGHT: center.x += speed;
                    changeX += speed;
                    moveRight = true;
                    moveLeft =false;
//                    moveDown = false;
                    moveUp = false;
                    moveDown =false;
                    break;

        case LEFT: center.x -= speed;
                    changeX -= speed;
                    moveLeft = true;
                    moveRight = false;
//                    moveDown = false;
                    moveUp = false;
                    moveDown =false;
                    break;

//        case DOWN: center.y += speed;
//                    changeY += speed;
////                    moveDown =true;
//                    moveUp = false;
                    break;
    }
}
void snowman::jump(SDL_Plotter &g){
            moveLeft = false;
            moveRight = false;

        for(double i=15; i > 0; i-=1){
            center.y = center.y - i;
            center.x = center.x;
            changeY -= i;
            if(center.x > 749 - BODY - 3){
                center.x = 749 - BODY - 3;
                changeX = 378;
            }
            if(center.x < BODY + 3){
                center.x = BODY + 3;
                changeX = 431;
            }
            if(center.y > 700 - BODY - 10){
            center.y = 700 - BODY  ;
            changeY = 277;
            }
            draw(g);
            g.Sleep(delay*1.5);
            g.update();
            if (!g.kbhit())
            {
            switch(g.getKey())
            {
                case RIGHT_ARROW: moveRight = true;
                    center.x += speed/2;
                    changeX += speed/2;
                          break;
                case LEFT_ARROW: //move(LEFT);
                                moveLeft = true;
                    center.x -= speed/2;
                    changeX -= speed/2;
                          break;
            }
//            center.y = center.y - i;
//            center.x = center.x;
//            changeY -= i;

            }
    }


    for(double i = 0; i <= 15; i+=1){
        center.y = center.y + i;
        changeY += i;
        draw(g);
        g.Sleep(delay*1.5);
        g.update();
        if(center.x > 749 - BODY - 3){
            center.x = 749 - BODY - 3;
            changeX = 378;
        }
        if(center.x < BODY + 3){
            center.x = BODY + 3;
            changeX = 431;
        }
        if(center.y > 700 - BODY - 10){
            center.y = 700 - BODY  ;
            changeY = 277;
        }
            if (!g.kbhit())
            {
                switch(g.getKey())
                {
                    case RIGHT_ARROW: // move(RIGHT);
                        moveRight= true;
                        center.x += speed/2;
                        changeX += speed/2;
                              break;
                    case LEFT_ARROW:// move(LEFT);
                        moveLeft = true;
                        center.x -= speed/2;
                        changeX -= speed/2;
                              break;
                }
//            if(moveRight){
//                center.x +=speed;
//                changeX += speed;
//            }
//            if(moveLeft){
//                center.x -= speed;
//                changeX -= speed;
//            }
        }
    }
}

void snowman::movement(SDL_Plotter &g){

        switch(g.getKey())
        {
            case RIGHT_ARROW: move(RIGHT);
                      break;
            case LEFT_ARROW: move(LEFT);
                      break;
            case UP_ARROW: move(UP);
                        jump(g);
                    break;
        }
        if(center.x > 749 - BODY - 3){
            center.x = 749 - BODY - 3;
            changeX = 378;
        }
        if(center.x < BODY + 3){
            center.x = BODY + 3;
            changeX = 431;
        }
        if(center.y > 700 - BODY - 10){
            center.y = 700 - BODY  ;
            changeY = 277;
        }

//            if(center.y < 350 and center.x <200){
//                        for(double i = 0; i <= 350 - sman.getCenter().y; i++){
//                            sman.moveDown = true;
//                            newCenter.x = sman.getCenter().x;
//                            newCenter.y = sman.getCenter().y + i;
//                            sman.setCenter(newCenter);
//                            sman.changeY += i;
//                            sman.draw(g);
//                            g.Sleep(delay*2);
//                            g.update();
//                            }
//                        }
                 if(center.y < 700 - BODY){
                    for(double i = 0; i <= 700 - center.y - BODY; i++){
                        moveDown = true;
                        center.y += i;
                        changeY += i;
                        draw(g);
                        g.Sleep(delay*2);
                        g.update();
                        }
        }
    }

