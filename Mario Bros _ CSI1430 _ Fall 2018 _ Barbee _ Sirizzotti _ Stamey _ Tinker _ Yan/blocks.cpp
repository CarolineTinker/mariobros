/*
 Author:
 Elisabeth Barbee
 Ben Sirizzotti
 Landon Stamey
 Caroline Tinker
 Zhenbo Yan
 Assignment Title: Group Project
 Assignment Description: Mario Bros
 Due Date: 12/3/18
 Date Created: 10/?/18
 Date Last Modified: 11/18/18
 */

#include "headers.h"
#include "blocks.h"

block::block(){
    point p, np;
    p.x = 0;
    p.y = 0;
    np.x = 10;
    np.y = 10;
    b.setP1(p);
    b.setP2(np);
}
block::block(point p1, point p2, color clr){
    b.setP1(p1);
    b.setP2(p2);
    b.setColor(clr);
}

void block::drawBlock(SDL_Plotter& g){

    for (int x = b.getP1().x; x <= b.getP2().x; x++)
    {
        for (int y = b.getP1().y; y <= b.getP2().y; y++)
        {
            g.plotPixel(x, y, b.getColor().R, b.getColor().G,
                        b.getColor().B);
        }
    }

}
