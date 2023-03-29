#ifndef RE_H_INCLUDED
#define RE_H_INCLUDED

#include "Circle.h"
class Rectangle{
public:
    Rectangle() {}

    Rectangle(double x, double y, double width , double height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    static bool isOverlap(Rectangle*, Circle*);

    double x, y;
    double width,height;
};



#endif // RECT_H_INCLUDED
