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
    int on_button_flag = 0;      //�Д����x�εĻ����Л]���Ƶ����o��(��Ч)
    bool about_flag = false;    //�Д��ǲ����Mabout
    bool level_up_check_flag = false;   //�Д��ǲ������ڰ��������o(��Ч)
    bool store_flag = false;    //�Д�˕r�Л]�д��_�̵�
    bool store_press_flag = false;//�Д��ǲ������ڰ��̵갴�o (��Ч)
    bool store_exit_press_flag = false; //�Д��ǲ������ڰ��x�_�̵�İ��o (��Ч)

    bool auto_machine_flag = false; //�Д�؈���I�ˆ� �I�˵�Ԓ���´��_�̵� �������ŕ�׃���u�Ԅ��a��C
    bool restart_store_flag = false;//�Д����´��_�̵��ˆ�

    bool no_money_flag = false;     //�Д��Л]��money�I��Ʒ
    bool furniture1_flag = false;   //�Д��Л]�б�ُ�I  Ҳ���Д஋ʲ�N������
    bool furniture2_flag = false;
    bool furniture3_flag = false;
    bool furniture4_flag = false;
    bool furniture5_flag = false;
    bool AttackCat_flag = false;
    bool SpeedCat_flag = false;
    bool MoneyCat_flag = false;

    int rat_born_percent = 100; //���������l��
    int furniture_count = 0;//�Ҿ߂���

    bool auto_machine_buy_flag = false; //�Д��I�Ԅ��a��C�˛]�� (��Ҫ!!)
    int installing_time = 0;   //�Дల�b�Ӯ����˶��
    bool install_flag = false; //�Дಥ�갲�b�Ӯ��ˆ�

    bool end_flag = false; //�Д��[��Y��(Money��99999999)�ˆ�


    int defend_draw_time = 0;   //��defend�ĕr�g

    int end_video_time = 0;  //�o�end_video���˶��
    bool end_video_flag = false; //�Дಥ�갲�b�Ӯ��ˆ�

    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *tower[Num_TowerType];
    ALLEGRO_BITMAP *background = NULL;      //���x��
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

    ALLEGRO_BITMAP *BasicCat_profile = NULL;    //����؈
    ALLEGRO_BITMAP *AttackCat_profile = NULL;   //��ɫ؈
    ALLEGRO_BITMAP *SpeedCat_profile = NULL;    //cremeɫ؈
    ALLEGRO_BITMAP *MoneyCat_profile = NULL;    //��ɫ؈
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

    int keep_time = 0;  //draw no money�ĳ��m�r�g
    int record_time = 0;
    ALLEGRO_TIMER *timer = NULL;        //�󲿷��[���timer(draw�ǿ��@��...)
    ALLEGRO_TIMER *record_timer = NULL; //���[��ĕr�g
    ALLEGRO_TIMER *monster_pro = NULL;  //֮����������S�C���ɵ�timer

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
