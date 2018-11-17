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

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "headers.h"

struct point
{
    //variables
    int x, y;

    //constructors
    point(){
        x = 0;
        y = 0;
    }
    
    point (int a){
        x = a;
        y = 0;
    }

    point(int a, int b){
        x = a;
        y = b;
    }
    
    //functions
    
    /*
     description: calculates distance between 2 points
     return: double
     precondition: 2 points exist
     postcondition: values of points unchanged
     */
    double distance (point p){
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
    
    /*
     description: calculates midpoint between 2 points
     return: point
     precondition: 2 points exist
     postcondition: values of points unchanged
     */
    point midPoint (point p){
        double midX, midY;
        point mid;
        
        midX = (x + p.x)/2.0;
        midY = (y + p.y)/2.0;
        
        mid.x = midX;
        mid.y = midY;
        
        return mid;
    }
};

#endif // POINT_H_INCLUDED
