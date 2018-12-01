#include "chimney.h"

chimney::chimney(){

}

chimney::chimney(rectangle a, rectangle b, rectangle c){
    r1 = a;
    r2 = b;
    r3 = c;
}

void chimney::drawChimney(SDL_Plotter& g){
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
}

/*
void chimney::snowmanEnter(snowman& s){

}
*/
