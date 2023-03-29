#ifndef BASICCAT_H_INCLUDED
#define BASICCAT_H_INCLUDED

#include "Cat.h"

class BasicCat : public Cat
{
public:
    BasicCat(int mouse_x = 0, int mouse_y = 0) : Cat(mouse_x, mouse_y)
    {
        //printf("BASIC\n");
        type = BASICCAT;

        move_x_direction = 0;
        move_y_direction = 0;
        circle->r = 110;
        attack_frequency = 50;
        attack_velocity = 10;

        img = al_load_bitmap("./image/Cat/BasicCat.png");
        img_move1 = al_load_bitmap("./image/Cat/BasicCat_walk1.png");
        img_move2 = al_load_bitmap("./image/Cat/BasicCat_walk2.png");
        img_move3 = al_load_bitmap("./image/Cat/BasicCat_walk3.png");
        img_move4 = al_load_bitmap("./image/Cat/BasicCat_walk4.png");
        //attack_img = al_load_bitmap("./image/Cat/attack.jpg");
        attack_img = algif_load_animation("./image/Cat/attack_animation5.gif");

        double attack2[6]={0,25,30,40,45,50};
        double speed2[6]={0,3,3,3,3,3};
        double coin_product2[6]={0,3,3,4,4,5};
        double upgrade_money2[6]={0,100,200,300,400,500};
        for(int i=0 ; i<=5 ; i++){
            attack[i] = attack2[i];
            speed[i] = speed2[i];
            coin_product[i] = coin_product2[i];
            upgrade_money[i] = upgrade_money2[i];
        }
        move_x_speed = speed[1];
        move_y_speed = speed[1];
        attack_harm_point = attack[1];

    }

    int getWidth() override { return 100; }
    int getHeight() override { return 75; }
};

#endif // POISON_H_INCLUDED
