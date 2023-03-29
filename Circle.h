#ifndef RECT_H_INCLUDED
#define RECT_H_INCLUDED

class Circle{
public:
    Circle() {}

    Circle(double x, double y, double r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
    }

    static bool isOverlap(Circle*, Circle*);

    double r;
    double x, y;
};



#endif // RECT_H_INCLUDED
