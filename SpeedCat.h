#ifndef SPEEDCAT_H_INCLUDED
#define SPEEDCAT_H_INCLUDED

#include "Cat.h"

class SpeedCat : public Cat
{
public:
    SpeedCat(int mouse_x = 0, int mouse_y = 0) : Cat(mouse_x, mouse_y)
    {
        printf("SPEED\n");
        type = SPEEDCAT;

        move_x_direction = 0;
        move_y_direction = 0;
        circle->r = 110;
        attack_frequency = 50;
        attack_velocity = 10;
        img = al_load_bitmap("./image/Cat/SpeedCat.png");
        img_move1 = al_load_bitmap("./image/Cat/SpeedCat_walk1.png");
        img_move2 = al_load_bitmap("./image/Cat/SpeedCat_walk2.png");
        img_move3 = al_load_bitmap("./image/Cat/SpeedCat_walk3.png");
        img_move4 = al_load_bitmap("./image/Cat/SpeedCat_walk4.png");
        attack_img = algif_load_animation("./image/Cat/attack_animation5.gif");

        double attack2[6]={0,40,50,60,70,80};
        double speed2[6]={0,4,5,6,7,10};
        double coin_product2[6]={0,5,6,7,8,9};
        double upgrade_money2[6]={0,300,600,1000,2000,4000};
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
