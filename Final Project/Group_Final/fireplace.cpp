#include "fireplace.h"

fireplace::fireplace(){
    r1 = rectangle(point(0,0),   point(10,10), color(255,255,255));
    r2 = rectangle(point(11,11), point(20,20), color(255,255,255));
    r3 = rectangle(point(21,21), point(30,30), color(255,255,255));
    r4 = rectangle(point(21,21), point(30,30), color(255,255,255));
}
fireplace::fireplace(rectangle a, rectangle b, rectangle c, rectangle d){
    r1 = a;
    r2 = b;
    r3 = c;
    r4 = d;
}

void fireplace::drawFireplace(SDL_Plotter& g){
    for (int x = r1.getP1().x; x <= r1.getP2().x; x++){
        for (int y = r1.getP1().y; y <= r1.getP2().y; y++){
            g.plotPixel(x, y, r1.getColor().R, r1.getColor().G, r1.getColor().B);
        }
    }
    for (int x = r2.getP1().x; x <= r2.getP2().x; x++){
        for (int y = r2.getP1().y; y <= r2.getP2().y; y++){
            g.plotPixel(x, y, r2.getColor().R, r2.getColor().G, r2.getColor().B);
        }
    }
    for (int x = r3.getP1().x; x <= r3.getP2().x; x++){
        for (int y = r3.getP1().y; y <= r3.getP2().y; y++){
            g.plotPixel(x, y, r3.getColor().R, r3.getColor().G, r3.getColor().B);
        }
    }
    for (int x = r4.getP1().x; x <= r4.getP2().x; x++){
        for (int y = r4.getP1().y; y <= r4.getP2().y; y++){
            g.plotPixel(x, y, r4.getColor().R, r4.getColor().G, r4.getColor().B);
        }
    }
}
void fireplace::snowmanEnter(snowman& s, SDL_Plotter& g){
    bool enter = false;
    if (s.getCenter().x > r2.getP1().x &&
        s.getCenter().x < r2.getP2().x){
            enter = true;
            //s.erase();
        }
}

