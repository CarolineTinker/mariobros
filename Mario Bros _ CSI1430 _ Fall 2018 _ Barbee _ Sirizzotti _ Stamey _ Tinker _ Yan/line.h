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
 Date Last Modified: 11/17/18
 */

#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "headers.h"

class line{
    private:
        point p1, p2;
        color c;
        bool slope(double&);
        double y_inter();

    public:
        //constructors
        line();
        line(point, point);
    
        //functions
    
        /*
         description: gets point P1
         return: point
         precondition: line and point P1 exists
         postcondition: values of line unchanged
        */
        point getP1();
    
        /*
         description: gets point P2
         return: point
         precondition: line and point P2 exists
         postcondition: values of line unchanged
        */
        point getP2();
    
        /*
         description: gets color of line
         return: color
         precondition: line exists
         postcondition: values of line unchanged
        */
        color getColor();

        /*
         description: sets value of point P1
         return: void
         precondition: line exists
         postcondition: values of P1 changed
        */
        void setP1(point);
    
        /*
         description: sets value of point P2
         return: void
         precondition: line exists
         postcondition: values of P2 changed
        */
        void setP2(point);
    
        /*
         description: sets value of color
         return: void
         precondition: line exists
         postcondition: values of color changed
        */
        void setColor(color);
    
        /*
         description: prints line to output stream
         return: void
         precondition: line exists
         postcondition: values of line unchanged
        */
        void draw(ostream&);
    
        /*
         description: prints line to SDL_Plotter
         return: void
         precondition: line exists
         postcondition: values of line unchanged
        */
        void draw(SDL_Plotter&);
};

#endif // LINE_H_INCLUDED
