#pragma once
#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<Windows.h>
#include<stack>
#include <conio.h>
#include"controller.h"
#include"weapon&tool.h"
#include"boss.h"
using namespace std;


//--------------------�������---------------------//

struct bullet {//�ӵ�
	int x, y;
	double angle;  //��y�Ḻ���ᣬ�Ϸ����н�
	int harm;
	int speed;
	int ID_bullet;
};


struct plane {
	int x, y;//�ɻ�����
	int width, height;//�ɻ�����
	int life;//�ɻ�����ֵ
	int max_life;//Ѫ������  -����Ѫ -���Ӱٷֱ�Ѫ -����Ѫ������
	int power;//������ 
	int speed;//�ɻ��ٶ�
	int bullet_num; //�ӵ�������һ�η�����ٸ��ӵ���
	int ID_skin = 0;

	//int exp;
};


typedef struct enemy {
	plane* pthis;
	struct enemy* next, * pre;  //����ɾ��
}*LinkList;    //������ŵл���Ϣ

typedef struct bullet_Node {
	struct bullet* bthis;
	struct bullet_Node* next, * pre;
}*LinkList_b;




//--------------------�������---------------------//

//----------------------service------------------------//


/*
* �����ˣ�
* ���ܣ���ʼ����ҵ����ݣ����޸�Ƥ�������������ļ��ж����������ʶͼƬָ���ʼ������buttle_num�ȳ�ʼ��Ϊ1
* ��������
* ����ֵ����
*/
void player_init();


/*
* �����ˣ�
* ���ܣ���ʼ���л����ӵ�����
* ������void
* ����ֵ��void
*/
void linklist_init();

/*
* �����ˣ���κ
* ���ܣ���ʼ���л�
* ������void
* ����ֵ��void
*/
void enemy_init(plane *p);

/*
* �����ˣ�
* ���ܣ������л�
* ������void���ɿ��Ǹĳ�int����ʾ�����ķɻ�����
* ����ֵ��void
*/
void creat_enemy();

/*
* �����ˣ�
* ���ܣ���������ͼƬ
* ������int x,y
* ����ֵ��void
*/
void create_weapon(int x,int y,int width,int height,int temp);

/*
* �����ˣ�
* ���ܣ��������ͼƬ
* ������int x,y
* ����ֵ��void
*/
void create_tool(int x, int y,int width,int height,int temp);

/*
* �����ˣ���κ
* ���ܣ������ӵ�
* �������ӵ�����x,y,�л�/����ӵ����flag,flagΪ1��ʾ����ҷ����ӵ���Ϊ0��ʾ�ǵл������ӵ�
* ����ֵ��void
*/
void create_bullet(int flag, double angle, int x, int y);

/*
* �����ˣ�
* ���ܣ�ɾ�������л�
* ������ָ�������ɻ���ַ
* ����ֵ��void
*/
void delet_enemy(plane* pthis);

/*
* �����ˣ�
* ���ܣ����ݴ���ָ�룬�ж����/�л��Ƿ���������������1�����򷵻�0
* ������plane*
* ����ֵ��int
*/
int isDie(plane* pthis);
int isDie(boss1* b);


/*
* �����ˣ�
* ���ܣ����Ʒ����ӵ��ٶ�
* ������int ms����ʾҪͣ��ʱ��
* ����ֵ��bool
*/


bool Timer(int ms);

/*
* �����ˣ�
* ���ܣ������Ұ������������������ݴ�������ͣʱ������ͣ���溯����
       ����������ʱ���Ƿɻ��ھ�ͷ�ڣ������ӵ��ٶȣ�
* ������void
* ����ֵ��void
*/
void detect_action();

/*

* �����ˣ��Ķ�
* ���ܣ������ӵ�����
* ������void
* ����ֵ��void
*/
void bullet_fly();

/*
* �����ˣ�
* ���ܣ���������л�
* ������void
* ����ֵ��void
*/
void enemy_fly();

/*
* �����ˣ�
* ���ܣ�������������
* ������void
* ����ֵ��void
*/
void weapon_fly();

/*
* �����ˣ�
* ���ܣ����µ�������
* ������void
* ����ֵ��void
*/
void tool_fly();

/*
* �����ˣ�С��
* ���ܣ����л�����ҷɻ��Ƿ�ᷢ����ײ����������ײ���л�ֱ������������ֵ���㣩����ҿ۳�����ֵ
* ������void
* ����ֵ��void
*/
void crush_plane();



/*
* �����ˣ�
* ���ܣ��ж��ӵ��Ƿ������ɻ������������Ӧ�ӵ����ɻ���Ѫ
* ������void
* ����ֵ��void
*/
void crush_bullet();

/*
* �����ˣ��Ķ�
* ���ܣ�����Ƿ����Խ�磨�ɳ���ͷ���ӵ�
*      ����ɾ��
* ������void
* ����ֵ��void
*/
void detect_overstep();

/*
* �����ˣ�
* ���ܣ�������߻������������߷���0 ��������1
* ������void
* ����ֵ��int
*/
int drop_weapon_or_tool();

/*
* �����ˣ�
* ���ܣ�����/��ҿ���
* ������int
* ����ֵ��void
*/
void fire(int flag);
void fire_em(int flag);
/*
* �����ˣ�
* ���ܣ����ٵл�/�������ֵ
* ������plane �������˷ɻ���int �����˺�ֵ
* ����ֵ��void
*/
void damage(plane* p, int harm);
void damage(em_Node* p, int harm);
/*
* �����ˣ�
* ���ܣ��ı�ɻ�����ֵ,���ݵ��ߵ����ԣ��ı�ɻ�life��max_lifeֵ��percent_lifeֵ�԰ٷֱ����ı�ɻ���lifeֵ
* ������void
* ����ֵ��void
*/
void life_change(int tool_life, int tool_max_life, int tool_percent_life);
/*
* �����ˣ�
* ���ܣ��ı�ɻ�powerֵ,���ݵ��ߵ����ԣ��ı�ɻ�power��percent_powerֵ�԰ٷֱ����ı�ɻ���powerֵ
* ������void
* ����ֵ��void
*/
void power_change(int tool_power,int tool_percent);
/*
* �����ˣ�
* ���ܣ��ı�ɻ�speedֵ,���ݵ��ߵ����ԣ��ı�ɻ���speedֵ
* ������void
* ����ֵ��void
*/
void speed_change(int tool_speed);
/*
* �����ˣ�
* ���ܣ��ı�ɻ���xy����ֵ
* ������void
* ����ֵ��void
*/
void x_y_change(int tool_x, int tool_y);

/*
* �����ˣ�
* ���ܣ��ı�ɻ��Ĵ�С
* ������void
* ����ֵ��void
*/
void w_h_change(int tool_width, int tool_height);

/*
* �����ˣ�
* ���ܣ��ı�ɻ��Ĵ�С
* ������void
* ����ֵ��void
*/
void bullet_num_change(int tool_bullet_num);

/*
* �����ˣ��հ�
* ���ܣ����ػ�ʹ�õ���ͼƬ
* ������void
* ����ֵ��void
*/
void load();
/*
* �����ˣ��հ�
* ���ܣ����ػ�ʹ�õ�������
* ������void
* ����ֵ��void
*/
void load_music();
void MonsterDied(const char* musicFilePath);

//----------------------service------------------------//
// 
//----------------------view------------------------//

/*��
* �����ˣ�����
* ���ܣ�չʾʧ�ܽ���
* ������void
* ����ֵ��void
*/
void fail_interface(); //ʧ�ܽ���
/*��
* �����ˣ��հ�
* ���ܣ�չʾ����
* ������void
* ����ֵ��void
*/
void show_weapon();
/*��
* �����ˣ��հ�
* ���ܣ�չʾ����
* ������void
* ����ֵ��void
*/
void show_tool();

/*��
* �����ˣ��հס�������
* ���ܣ����Ʊ������ɻ����ӵ��ȡ���
* ������void
* ����ֵ��void
*/
void draw();
//չʾ����
void show_bk();
//չʾ���
void show_player();
//չʾ�л������ж��Ƿ����������������ű�ը������
void show_enemy();
//չʾ�ӵ� 
void show_bullet();


/*
* �����ˣ�
* ���ܣ�չʾ��ͣ���棬ֱ���û����¶�Ӧ�����˳��ص���Ϸ����
* ������void
* ����ֵ��void
*/
void show_pause();

/*
* �����ˣ�
* ���ܣ���Ϸ���������߼�
* ������void
* ����ֵ��void
*/
void start_game();
/*
* �����ˣ�
* ���ܣ�����������
* ������int x,y ����ֵ
* ����ֵ��void
*/
int rand_tool();
/*
* �����ˣ�
* ���ܣ��������װ��
* ������
* ����ֵ��void
*/
int rand_weapon();

//----------------------view------------------------//
/*����ǰ��
	1����bullet_fly��detect_overstep�ϵ�һ��ֻ����һ��bullet_fly
	2���޸�һ���ӵ��Ľṹ��
*/


//�ӵ�����ο�����
	 //��ʱ��

	////�����ӵ�
	//for (int i = 0; i < BULLET_NUMBER; i++) {
	//	if (!bullet[i].isDie)
	//		img_bullet.Draw(bullet[i].x, bullet[i].y);//�ڣ�x,y)�����ӵ�ͼƬ
	//}
	////�����ӵ�
	//if (GetAsyncKeyState(VK_SPACE) && Timer(300,0)){//timer��ms,0��msԽ���ӵ�����Խ��,̫С�Ļ������һ��
	//	for (int i = 0; i < BULLET_NUMBER; i++) {//�����ӵ�
	//		if (bullet[i].isDie) {
	//			bullet[i].x = //�ɻ�xλ�ü��Ϸɻ���ȵ�һ���ټ�ȥ�ӵ���ȵ�һ�룻
	//			bullet[i].y = //�ɻ���y�����ȥ�ӵ���y���ȣ�
	//			bullet[i].isDie = false;
	//			break;
	//		}
	//	}
	//}


/*
��Ҫ�ڳ�ʼ���м���һЩ����
for(int i = 0; i < BULLET_NUMBER; i++){
	bullet[i].isDie = true;//tureʱͼƬ������أ�falseʱ�ӵ�����
}
*/