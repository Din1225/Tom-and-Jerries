#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <allegro5/allegro_video.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <string>
#include <array>
#include <sstream>
#include <list>
#include <time.h>
#include "Menu.h"
#include "Level.h"
#include "WolfKnight.h"
#include "CaveMan.h"
#include "Wolf.h"
#include "DemonNijia.h"
#include "Arcane.h"
#include "Archer.h"
#include "Canon.h"
#include "Poison.h"
#include "Storm.h"
#include "Attack.h"
#include "Slider.h"
#include "Cat.h"
#include "BasicCat.h"
#include "MoneyCat.h"
#include "AttackCat.h"
#include "SpeedCat.h"
#include "Rat.h"
#include "BasicRat.h"
#include "Rectangle.h"
#include "algif5/src/algif.h"
#include <allegro5/allegro_color.h>


#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7

// clock rate
const float FPS = 60;

// total number of level
const int LevelNum = 4;

// 1 coin every 2 seconds
const int CoinSpeed = FPS * 2;
const int Coin_Time_Gain = 1;

class GameWindow
{
public:
    // constructor
    GameWindow();
    // each process of scene
    void game_init();
    void game_reset();
    void game_play();
    void game_begin();

    int game_run();
    int game_update();

    void show_err_msg(int msg);
    void game_destroy();


    void main_menu_init();
    int main_menu_update();
    void main_menu_draw();
    void main_menu_destroy();

    void about_scene_init();
    int about_scene_update();
    void about_scene_draw();
    void about_scene_destroy();

    void game_scene_init();
    int game_scene_update();
    void game_scene_draw();
    void game_scene_destroy();

    void store_scene_init();
    int store_scene_update();
    void store_scene_draw();
    void store_scene_destroy();

    void end_scene_init();
    int end_scene_update();
    void end_scene_draw();
    void end_scene_destroy();

    void end_video_init();
    int end_video_update();
    void end_video_draw();
    //void video_display(ALLEGRO_VIDEO *);
    void end_video_destroy();


    // each drawing scene function
    void draw_running_map();

    // process of updated event
    int process_event();
    // detect if mouse hovers over a rectangle
    bool mouse_hover(int, int, int, int);
    // detect if a tower will be constructed on road
    bool isOnRoad();

    Cat* create_cat(int);
    Tower* create_tower(int);
    Monster* create_monster();
    Rat* create_rat();

public:
    bool initial = true;

private:
    bool judge_next_window = false;
    int window = 0;
    int on_button_flag = 0;      //判斷主選單的滑鼠有沒有移到按鈕上(特效)
    bool about_flag = false;    //判斷是不是進about
    bool level_up_check_flag = false;   //判斷是不是正在按強化按鈕(特效)
    bool store_flag = false;    //判斷此時有沒有打開商店
    bool store_press_flag = false;//判斷是不是正在按商店按鈕 (特效)
    bool store_exit_press_flag = false; //判斷是不是正在按離開商店的按鈕 (特效)

    bool auto_machine_flag = false; //判斷貓咪買了嗎 買了的話重新打開商店 下面那排會變成賣自動補鼠機
    bool restart_store_flag = false;//判斷重新打開商店了嗎

    bool no_money_flag = false;     //判斷有沒有money買商品
    bool furniture1_flag = false;   //判斷有沒有被購買  也是判斷畫什麼的依據
    bool furniture2_flag = false;
    bool furniture3_flag = false;
    bool furniture4_flag = false;
    bool furniture5_flag = false;
    bool AttackCat_flag = false;
    bool SpeedCat_flag = false;
    bool MoneyCat_flag = false;

    int rat_born_percent = 100; //老鼠生成頻率
    int furniture_count = 0;//家具個數

    bool auto_machine_buy_flag = false; //判斷買自動補鼠機了沒有 (重要!!)
    int installing_time = 0;   //判斷安裝動畫播了多久
    bool install_flag = false; //判斷播完安裝動畫了嗎

    bool end_flag = false; //判斷遊戲結束(Money到99999999)了嗎


    int defend_draw_time = 0;   //畫defend的時間

    int end_video_time = 0;  //紀錄end_video播了多久
    bool end_video_flag = false; //判斷播完安裝動畫了嗎

    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *tower[Num_TowerType];
    ALLEGRO_BITMAP *background = NULL;      //主選單
    ALLEGRO_BITMAP *rat_image = NULL;
    ALLEGRO_BITMAP *jail = NULL;

    ALLEGRO_BITMAP *about_scene = NULL;

    ALLEGRO_BITMAP *game_scene = NULL;
    ALLEGRO_BITMAP *attribute_window = NULL;
    ALLEGRO_BITMAP *store_button_block = NULL;
    ALLEGRO_BITMAP *store_button_block_effect = NULL;
    ALLEGRO_BITMAP *store_button = NULL;
    ALLEGRO_BITMAP *game_counter = NULL;
    ALLEGRO_BITMAP *total_money_icon = NULL;
    ALLEGRO_BITMAP *level_up_button = NULL;
    ALLEGRO_BITMAP *level_up_button_effect = NULL;

    ALLEGRO_BITMAP *store_scene = NULL;
    ALLEGRO_BITMAP *store_exit_button_block = NULL;
    ALLEGRO_BITMAP *store_exit_button_block_effect = NULL;
    ALLEGRO_BITMAP *store_exit_button = NULL;
    ALLEGRO_BITMAP *item_block = NULL;
    ALLEGRO_BITMAP *item_block_selected = NULL;
    ALLEGRO_BITMAP *item_block_cant_buy = NULL;
    ALLEGRO_BITMAP *furniture_icon = NULL;
    ALLEGRO_BITMAP *furniture1 = NULL;
    ALLEGRO_BITMAP *furniture2 = NULL;
    ALLEGRO_BITMAP *furniture3 = NULL;
    ALLEGRO_BITMAP *furniture4 = NULL;
    ALLEGRO_BITMAP *furniture5 = NULL;

    ALLEGRO_BITMAP *BasicCat_profile = NULL;    //基本貓
    ALLEGRO_BITMAP *AttackCat_profile = NULL;   //橘色貓
    ALLEGRO_BITMAP *SpeedCat_profile = NULL;    //creme色貓
    ALLEGRO_BITMAP *MoneyCat_profile = NULL;    //白色貓
    ALLEGRO_BITMAP *attack_icon = NULL;
    ALLEGRO_BITMAP *speed_icon = NULL;
    ALLEGRO_BITMAP *money_icon = NULL;
    ALLEGRO_BITMAP *buff_icon = NULL;
    ALLEGRO_BITMAP *price_icon = NULL;

    ALLEGRO_BITMAP *rat_icon = NULL;

    ALLEGRO_BITMAP *cheese = NULL;
    ALLEGRO_BITMAP *auto_machine = NULL;
    //ALLEGRO_BITMAP *installing_bar = NULL;
    struct gif{
        double start_time = 0;
        ALGIF_ANIMATION *gif = NULL;
        double get_time(double time){
            if(start_time==0) start_time = time;
            return time - start_time;
        }
    }installing_bar;


    ALLEGRO_BITMAP *end_scene = NULL;




    ALLEGRO_BITMAP *cat[Num_CatType];

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *rpg_font = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;

    char time_item[10]={'0','0',':','0','0',':','0','0'};

    int keep_time = 0;  //draw no money的持續時間
    int record_time = 0;
    ALLEGRO_TIMER *timer = NULL;        //大部分遊戲的timer(draw是靠這個...)
    ALLEGRO_TIMER *record_timer = NULL; //破遊戲的時間
    ALLEGRO_TIMER *monster_pro = NULL;  //之後會是老鼠隨機生成的timer

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *failSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *backgroundSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *typingSound = NULL;
    //ALLEGRO_SAMPLE_INSTANCE *attack_fail_Sound = NULL;

    LEVEL *level = NULL;
    Menu *menu = NULL;

    std::vector<Rat*> ratSet;
    std::vector<Monster*> monsterSet;
    std::list<Tower*> towerSet;
    std::list<Cat*> catSet;
    std::vector<Rectangle*> furnitureSet;

    int Monster_Pro_Count = 0;
    int Coin_Inc_Count = 0;
    int mouse_x, mouse_y;
    int selectedTower = -1, lastClicked = -1;
    int selectedCat = 0;
    int Money = 0;

    bool redraw = false;
    bool mute = false;
    int ending_start = 0;
};


#endif // MAINWINDOW_H_INCLUDED
