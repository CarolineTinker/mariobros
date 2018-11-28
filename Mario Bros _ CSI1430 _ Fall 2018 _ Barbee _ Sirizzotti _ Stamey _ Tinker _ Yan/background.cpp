#include "background.h"


background::background(){
    //blocks
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
        //definition of blocks[]
        blocks[count].b.setP1(first);
        blocks[count].b.setP2(second);
        blocks[count].b.setColor(clr);
        
        count++;
    }
    
    //base
    point base1(0,690), base2(750, 750);
    //definition of base
    base = rectangle(base1, base2, WHITE1);
    
    
    //fireplace
    point f1r1p1(0, 679), f1r1p2(120, 689), f1r2p1(10, 621);
    point f1r2p2(110, 679), f1r3p1(30, 641), f1r3p2(90, 679);
    point f1r4p1(45, 591), f1r4p2(75, 621);
    point f2r1p1(620, 679), f2r1p2(740, 689), f2r2p1(630,621);
    point f2r2p2(730, 679), f2r3p1(650, 641), f2r3p2(710, 679);
    point f2r4p1(665, 591), f2r4p2(695, 621);
    
    color c1(144, 85, 70), c2(102, 62, 52);
    color c3(0, 0, 0), c4(144, 85, 70);
    
    rectangle f1r1(f1r1p1, f1r1p2, c1), f1r2(f1r2p1, f1r2p2, c2);
    rectangle f1r3(f1r3p1, f1r3p2, c3);
    rectangle f2r1(f2r1p1, f2r1p2, c1), f2r2(f2r2p1, f2r2p2, c2);
    rectangle f2r3(f2r3p1, f2r3p2, c3);
    rectangle f1r4(f1r4p1, f1r4p2, c4), f2r4(f2r4p1, f2r4p2, c4);
    
    //definition of f1, f2
    f1 = fireplace(f1r1, f1r2, f1r3, f1r4);
    f2 = fireplace(f2r1, f2r2, f2r3, f2r4);
    
    
    //chimneys
    point ch1r1p1(45, 90), ch1r1p2(75, 164);
    point ch1r2p1(30, 65), ch1r2p2(90, 89);
    point ch1r3p1(45, 60), ch1r3p2(75, 84);
    point ch2r1p1(665, 90), ch2r1p2(695, 164);
    point ch2r2p1(650, 65), ch2r2p2(710, 89);
    point ch2r3p1(665, 60), ch2r3p2(695, 84);
    
    rectangle ch1r1(ch1r1p1, ch1r1p2, c4), ch1r2(ch1r2p1, ch1r2p2, c2);
    rectangle ch1r3(ch1r3p1, ch1r3p2, c3), ch2r1(ch2r1p1, ch2r1p2, c4);
    rectangle ch2r2(ch2r2p1, ch2r2p2, c2), ch2r3(ch2r3p1, ch2r3p2, c3);
    
    //definition of ch1, ch2
    ch1 = chimney(ch1r1, ch1r2, ch1r3);
    ch2 = chimney(ch2r1, ch2r2, ch2r3);

}

/*
 background::background(block b[], int sb, fireplace fp1, fireplace fp2){
    blocks[sb] = b[sb];

}
 */


void background::drawBackground(SDL_Plotter& g){
    //empty space
    for (int y = 0; y <= 750; y++){
        for (int x = 0; x <= 750; x++){
            g.plotPixel(x, y, 0, 0, 0);
        }
    }
    
    //blocks
    for (int i = 0; i < 67; i++){
        blocks[i].drawBlock(g);
    }
    
    //base
    base.draw(g);
    
    //fireplaces
    f1.drawFireplace(g);
    f2.drawFireplace(g);
   
    
    //chimneys
    ch1.drawChimney(g);
    ch2.drawChimney(g);
    
}
