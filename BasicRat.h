#ifndef BASICRAT_H_INCLUDED
#define BASICRAT_H_INCLUDED

#include "Rat.h"

class BasicRat : public Rat
{
public:
    BasicRat(int x) : Rat(x)
    {

        HealthPoint = 100;
        speed = 2;
        worth = 5;
        score = 50;

        strncpy(class_name, "Rat", 20);

        Load_Move();
    }

};


#endif // CLAW_H_INCLUDED
