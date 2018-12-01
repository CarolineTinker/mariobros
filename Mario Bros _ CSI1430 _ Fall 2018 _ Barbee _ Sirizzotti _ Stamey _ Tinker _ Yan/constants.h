#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

enum DIRECTION {UP, DOWN, LEFT, RIGHT};
// for snowman constant
const int BODY = 23;
const int HEAD = 17;
const int XSTART = 345;
const int YSTART = 200;
const int XHEADSTART = XSTART;
const int YHEADSTART = YHEADSTART - BODY - HEAD;
const int HEAD_AND_BODY_OVERLAP = 7;
const double EYE = 1.5;
const double NOSE = 1.7;
const double BUTTON = 2.5;
const int HAT = 5;

// color
//const color BLACK(0, 0, 0);
//const color RED(255, 0, 0);
//const color GREEN(0, 255, 0);
//const color BLUE(0,0,255);
//const color LIGHTBLUE(135, 204, 251);

// enemies constant
const int EXSTART = 480;
const int EYSTART = 100;
const int ORANGE_STRIPE = 10;
const int WHITE_CENTER = 5;
const int ENEMY_BODY = 15;

//const int DEEP_ORANGE = ();

#endif // CONSTANTS_H_INCLUDED
