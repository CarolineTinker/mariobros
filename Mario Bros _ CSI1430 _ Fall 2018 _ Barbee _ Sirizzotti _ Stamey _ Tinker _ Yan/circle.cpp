#include "circle.h"

circle::circle()
{
    center.x = XSTART;
    center.y = YSTART;
    radius = BODY;
    clr = SNOWMAN;
    speed = 1;

    prev_center = center;
}

circle::circle(point p, int r, color c)
{
    center = p;
    radius = r;
    clr = c;
    speed = 1;

    prev_center = center;
}

point circle::getCenter()
{
    return center;
}

int circle::getRadius()
{
    return radius;
}

color circle::getColor()
{
    return clr;
}

void circle::setCenter(point p)
{
    center = p;
}

void circle::setRadius(int r)
{
    radius = r;
}

void circle::setColor(color c)
{
    clr = c;
}

void circle::draw(SDL_Plotter& g)
{
    if (prev_center.x != center.x || prev_center.y != center.y)
     {
         erase(g);
         prev_center = center;
         for (int x = -radius; x <= radius; x++)
        {
            for (int y = -radius; y <= radius; y++)
            {
                if (point(0, 0).distance(point(x, y)) <= radius)
                {
                    g.plotPixel(center.x + x, center.y + y,
                                 clr.R, clr.G, clr.B);
                }
            }
        }
     }
}

void circle::erase(SDL_Plotter& g)
{
    for (int x = -radius; x <= radius; x++)
        {
            for (int y = -radius; y <= radius; y++)
            {
                if (point(0, 0).distance(point(x, y)) <= radius)
                {
                    if (center.x - radius < 0) center.x = radius;
                    {
                        g.plotPixel(prev_center.x + x, prev_center.y + y,
                                255, 255, 255);
                    }
                }
            }
        }
}

void circle::move(DIRECTION d)
{
    prev_center = center;
    switch (d)
    {
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
