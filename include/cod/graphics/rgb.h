#ifndef RGB_H
#define RGB_H

struct RGB 
{
public:
    RGB() : red(0), green(0), blue(0) {}
    RGB(float red, float green, float blue) : red(red), green(green), blue(blue) {}
    
    float red;
    float green;
    float blue;
};

#endif