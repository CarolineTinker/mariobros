#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct color
{
    int R, G, B;

    color() //all color is black by default
    {
        R = G = B = 0;
    }

    color(int r, int g, int b)  //custom color
    {
        R = r;
        G = g;
        B = b;
    }

    void setColor(color c)
    {
        R = c.R;
        G = c.G;
        B = c.B;
    }
};

const color BLACK(0, 0, 0);
const color RED(255, 0, 0);
const color GREEN(0, 255, 0);
const color BLUE(0, 0, 255);
const color SNOWMAN(135, 204, 251);
const color DEEP_ORANGE(255, 91, 26);
const color ORANGE(221, 116, 19);

#endif // COLOR_H_INCLUDED
