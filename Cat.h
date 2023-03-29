#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <set>
#include <vector>
#include <iostream>
#include "Object.h"
#include "Attack.h"
#include "Circle.h"
#include "Monster.h"
#include "Rat.h"
#include "global.h"
#include "Rectangle.h"
#include "algif5/src/algif.h"

class Cat : public Object
{
public:
    Cat(int, int);
    virtual ~Cat();

    // override virtual function "Object::Draw"
    void Draw();
    void resetAttackCounter() { attack_counter = 0; }
    void ToggleClicked() { isClicked = !isClicked; }

    // update whole attack set
    // if any attack goes out of the range of tower, delete it
    void UpdateAttack();
    // detect if tower needs to attack some monster
    bool DetectAttack();
    // process if some of attack in set touches monster
    bool TriggerAttack(Rat*,std::vector<Rectangle*> &);

    void change_defend_flag() {  defend_flag = false; }
    virtual bool get_defend_flag() { return defend_flag; }

    virtual int getWidth() { return 40; }
    virtual int getHeight() { return 40; }
    virtual int getattack(){return attack[lev];}
    virtual int getspeed(){return speed[lev];}
    virtual int getCoin_times() { return coin_product[lev]; }
    virtual int Upgrade_Money(){return upgrade_money[lev];}
    virtual int cat_level(){return lev;}
    // show selected tower image on cursor position
    void Movecat(int, int);
    void change_mv_direct(int , int);
    void Jump(double,double);
    void move_on_about(int, int);

    double cat_x = 0;
    double cat_y = 0;

    void Upgrade();

protected:
    // setting of attack
    int attack_frequency = 20;
    int attack_counter = 0;
    int attack_harm_point = 100;
    int attack_velocity = 10;

    double move_x_direction = 0;
    double move_y_direction = 0;
    double move_x_speed = 0;
    double move_y_speed = 0;
    int place_x = 400;
    int place_y = 400;
    int attack_cooldown = 0;
    //ALLEGRO_BITMAP *attack_img;
    ALGIF_ANIMATION* attack_img;
    std::vector<Attack*> attack_set;

    // information of tower
    int type;
    bool isClicked = false;
    ALLEGRO_BITMAP *img;

    ALLEGRO_BITMAP *img_move1;
    ALLEGRO_BITMAP *img_move2;
    ALLEGRO_BITMAP *img_move3;
    ALLEGRO_BITMAP *img_move4;
    int draw_change = 0;


    bool defend_flag = false;   //用來判斷有沒有defend到攻擊
    int lev = 1;
    double attack[6]={0,1,2,3,4,5};
    double speed[6]={0,1,2,3,4,5};
    double coin_product[6]={0,3,2,3,4,5};
    int upgrade_money[6]={0,0,0,0,0,0};

private:
    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *attack_fail_Sound = NULL;

};

#endif // TOWER_H_INCLUDED
