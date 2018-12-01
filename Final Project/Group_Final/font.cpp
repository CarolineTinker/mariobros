#include "font.h"


font::font(int a, color b){
    size = a;
    c = b;

}

font::font(color b){
    c = b;
    size =1;
}

font::font(){
    size = 1;
    c = BLACK;
}


void font::setColor(color b){
    c = b;
}

void font::setSize(int a){
    size = a;
}


color font::getColor(){
    return c;
}

int font::getSize(){
    return size;
}


void font::draw(string filename, SDL_Plotter& g, point p){
    ifstream file;
    file.open(filename.c_str());
    char value;
    int row, col;

    if(!file){
        cout << "file not open";
    }

    file >> row >>col;

    for( int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            file >> value;
            if(value == '1'){
                g.plotPixel(p.x+c, p.y+r, c.r, c.g, c.b);
            }
        }
    }


    file.close();
