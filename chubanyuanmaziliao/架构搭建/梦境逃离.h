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
	char name[30];//�¼����֣��������10��������
	char info[600];//�¼�����������300�������
	char choose_one[200];//ѡ��һ��100���������
	char choose_two[200];//ѡ�����100���������
	char choose_three[200];//ѡ������100���������
	char after_info_one[400];//ѡ��һ�������飬����200���������
	char after_info_two[400];//ѡ����������飬����200���������
	char after_info_three[400];//ѡ�����������飬����200���������
	int life[3];
	int shield[3];
	int power[3];
	int smart[3];
	int speed[3];//�¼�����ά���Եĸı䣬���ı�д0��
};
struct Good_tool
{
	int life;
	int shield;
	int power;
	int smart;
	int speed;//���߶���ά����+����+����ֵ�ĸı䣬����Ϊ0������Ҫд
	int sp;//�ɾ���أ��޳ɾ���ض���Ϊ-1
	char name[20];//���ֿ�����10����
	char info[100];//��Ʒ��Ϣ������50������

};
struct Bad_tool
{
	int life;
	int shield;
	int power;
	int smart;
	int speed;//���߶���ά����+�����ĸı䣬����Ϊ0������Ҫд
	int sp;//�ɾ���أ��޳ɾ���ض���Ϊ-1
	char name[20];//���ֿ�����10����
	char info[100];//��Ʒ��Ϣ������50������

};
struct Bag
{
	
	int Gt[36];//�¼���úõ����±��Ӧ����
	int Bt[36];//�¼���û������±��Ӧ����
	int GT[36];//�õ���ѡ���±��Ӧ����
	int BT[36];//������ѡ���±��Ӧ����
};
struct Achievement
{
	int sp;//��������ɾ�ϵͳ�ҹ�
	char name[20];//�ɾ�����10������
	char text[100];//�ɾ���Ϣ50������
	int flag;//0����δ��ɣ�1���������
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

void controller();//����������

//----------------------�����溯��----------------------
void gamemenu();
void button(int x, int y,  const char* ming, const char* text);
void button_nomsg(int x, int y, const char* text);
void startgame();
void relevant_set();
void achieve();
void gamehelp();
bool inArea(int mx, int my, int x, int y, int w, int h);
void kaifastaff();
//----------------------�����溯��----------------------
//---------�ɾ�ϵͳ����---------
void achieve_get();
void store_achieve();
void get_achievement(int a);
void file_achieve_get();
void int_to_string(int number, char* str);
void print_achievement();
//--------�ɾ�ϵͳ����-----------
//---------��������---------
void Gear_set();
//---------��������---------
//--------------------------��Ϸ���溯��------------------------
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
//--------------------------��Ϸ���溯��------------------------

//-------------------------������Ա����Ϸ��������------------------------------
bool inArea_xiaer(int mx, int my, int x, int y, int w, int h);
bool button_xiaer(int x, int y, int w, int h);

//-------------------------������Ա����Ϸ��������------------------------------
//---------------------------�¼�������ߺ���---------------------------
void init_good_tool();
void init_bad_tool();
void load_event();
//---------------------------�¼�������ߺ���---------------------------