#include "headers.h"

enemies::enemies()
{
    center.x = EXSTART;
    center.y = EYSTART;
    radius = ENEMY_BODY;
    clr = DEEP_ORANGE;
    speed = 1;

    prev_center = center;
}

enemies::enemies(point p, int r, color c)
{
    center = p;
    radius = r;
    clr = c;
    speed = 1;

    prev_center = center;
}

point enemies::getCenter()
{
    return center;
}

int enemies::getRadius()
{
    return radius;
}

color enemies::getColor()
{
    return clr;
}

void enemies::setCenter(point p)
{
    center = p;
}

void enemies::setRadius(int r)
{
    radius = r;
}

void enemies::setColor(color c)
{
    clr = c;
}

void enemies::draw(SDL_Plotter& g)
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

            for (int x = -ORANGE_STRIPE; x <= ORANGE_STRIPE; x++)
            {
                for (int y = -ORANGE_STRIPE; y <= ORANGE_STRIPE; y++)
                {
                    if (point(0, 0).distance(point(x, y)) <= ORANGE_STRIPE)
                    {
                        g.plotPixel(center.x + x, center.y + y,
                                     255, 156, 26);
                    }
                }
            }

            for (int x = -WHITE_CENTER; x <= WHITE_CENTER; x++)
            {
                for (int y = -WHITE_CENTER; y <= WHITE_CENTER; y++)
                {
                    if (point(0, 0).distance(point(x, y)) <= WHITE_CENTER)
                    {
                        g.plotPixel(center.x + x, center.y + y,
                                     255, 255, 255);
                    }
                }
            }
         }

}

void enemies::erase(SDL_Plotter& g)
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

void enemies::move(DIRECTION d)
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

