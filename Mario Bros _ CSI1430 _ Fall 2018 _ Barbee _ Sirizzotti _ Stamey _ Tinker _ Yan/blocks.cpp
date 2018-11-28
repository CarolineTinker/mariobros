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
    /*
    block blocks[100];
    ifstream input;
    string line;
    int count=0;
    point first, second;
    int x1, y1, x2, y2;
    int a=255, b=255, c=255;
    color clr(a, b, c);

    input.open("blocks.txt");
    getline(input, line);
    getline(input, line);

    while(input >> x1 >> y1 >> x2 >> y2){
        first.x  = x1;
        first.y  = y1;
        second.x = x2;
        second.y = y2;

        for (int clry2 = y2 - 5; clry2 <= y2; clry2++){
           //this makes the snow blocks have a lightblue
           //tint at the bottom
            clr = LIGHTBLUE;
        }

        blocks[count].b.setP1(first);
        blocks[count].b.setP2(second);
        blocks[count].b.setColor(clr);

        count++;
     }
     */
    
    for (int x = b.getP1().x; x <= b.getP2().x; x++)
    {
        for (int y = b.getP1().y; y <= b.getP2().y; y++)
        {
            g.plotPixel(x, y, b.getColor().R, b.getColor().G,
                        b.getColor().B);
        }
    }


}

