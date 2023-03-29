#ifndef RAT_H_INCLUDED
#define RAT_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include "Object.h"
#include "Circle.h"
#include "global.h"

class Rat: public Object {
public:
    Rat(int);
    virtual ~Rat();

    // Draw image per frame
    // override virtual function "Object::Draw"
    void Draw();
    // Load bitmaps of animation image into container "moveImg"
    void Load_Move();

    // Update monster position per frame
    // And detect if it reaches end point but not destroyed
    bool Move(double,double,int);

    // functions that return informations of monster
    int getWorth() { return worth; }


    bool Subtract_HP(int);
    double speed = 1;

protected:
    int HealthPoint = 20;
    int worth = 10;
    int score = 100;
    char class_name[20];
    int width,height;
private:
    // direction and index for "path"
    double move_x_direction;
    double move_y_direction;
    // animation counter
    int counter;
    // animation image of current direction
    int sprite_pos;

    // set of animation images
    std::vector<ALLEGRO_BITMAP*> moveImg;
    // path on map

    int ending_x = 410;
    int ending_y = 410;
};


#endif // MONSTER_H_INCLUDED
