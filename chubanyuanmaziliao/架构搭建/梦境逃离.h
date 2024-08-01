#pragma once
#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<Windows.h>
#include<mmsystem.h>
#include<conio.h> 
#include<stdlib.h>
#include<climits>
#pragma comment(lib,"winmm.lib")

struct EVENT
{
	char name[30];//事件名字，请控制在10个字以内
	char info[600];//事件背景，请在300以内完成
	char choose_one[200];//选项一，100字以内完成
	char choose_two[200];//选项二，100字以内完成
	char choose_three[200];//选项三，100字以内完成
	char after_info_one[400];//选项一后续剧情，请在200字以内完成
	char after_info_two[400];//选项二后续剧情，请在200字以内完成
	char after_info_three[400];//选项三后续剧情，请在200字以内完成
	int life[3];
	int shield[3];
	int power[3];
	int smart[3];
	int speed[3];//事件对五维属性的改变，不改变写0；
};
struct Good_tool
{
	int life;
	int shield;
	int power;
	int smart;
	int speed;//道具对三维属性+生命+护盾值的改变，可以为0，但是要写
	int sp;//成就相关，无成就相关定义为-1
	char name[20];//名字控制在10以内
	char info[100];//物品信息控制在50字以内

};
struct Bad_tool
{
	int life;
	int shield;
	int power;
	int smart;
	int speed;//道具对三维属性+生命的改变，可以为0，但是要写
	int sp;//成就相关，无成就相关定义为-1
	char name[20];//名字控制在10以内
	char info[100];//物品信息控制在50字以内

};
struct Bag
{
	
	int Gt[36];//事件获得好道具下标对应数组
	int Bt[36];//事件获得坏道具下标对应数组
	int GT[36];//好道具选项下标对应数组
	int BT[36];//坏道具选项下标对应数组
};
struct Achievement
{
	int sp;//正数，与成就系统挂钩
	char name[20];//成就名字10个字内
	char text[100];//成就信息50个字内
	int flag;//0代表未完成，1代表已完成
};

#define MY_MENU 0
#define MY_GAME 1
#define MY_SETTING 2
#define MY_ACHIEVE 3
#define MY_HELP 4
#define MY_SATFF 5
#define Win_VIEW 6
#define DEFEAT_VIEW 7
#define INTER_PHOTO 8
#define GEAR 9
#define BAG 10
#define MY_OVER -1

void controller();//进入主界面

//----------------------主界面函数----------------------
void gamemenu();
void button(int x, int y,  const char* ming, const char* text);
void button_nomsg(int x, int y, const char* text);
void startgame();
void relevant_set();
void achieve();
void gamehelp();
bool inArea(int mx, int my, int x, int y, int w, int h);
void kaifastaff();
//----------------------主界面函数----------------------
//---------成就系统函数---------
void achieve_get();
void store_achieve();
void get_achievement(int a);
void file_achieve_get();
void int_to_string(int number, char* str);
void print_achievement();
//--------成就系统函数-----------
//---------齿轮设置---------
void Gear_set();
//---------齿轮设置---------
//--------------------------游戏界面函数------------------------
void Bag_view();
void Win_View();
void Defeat_View();
void startgame();
int If_End_Game();
bool judge_event(int event);
int choose_event();
void Init_attribute();
void life_and_shield_change(int tool_life, int event_life, int tool_shield, int event_shield);
void power_change(int tool_power, int event_power);
void smart_change(int tool_smart, int event_smart);
void speed_change(int tool_speed, int event_speed);
void load_photo();
void interlude_photo();
void show_player();
void show_change(int event, int i);
//--------------------------游戏界面函数------------------------

//-------------------------开发人员和游戏帮助函数------------------------------
bool inArea_xiaer(int mx, int my, int x, int y, int w, int h);
bool button_xiaer(int x, int y, int w, int h);

//-------------------------开发人员和游戏帮助函数------------------------------
//---------------------------事件及其道具函数---------------------------
void init_good_tool();
void init_bad_tool();
void load_event();
//---------------------------事件及其道具函数---------------------------