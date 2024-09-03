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


//--------------------数据设计---------------------//

struct bullet {//子弹
	int x, y;
	double angle;  //与y轴负半轴，上方，夹角
	int harm;
	int speed;
	int ID_bullet;
};


struct plane {
	int x, y;//飞机坐标
	int width, height;//飞机长宽
	int life;//飞机生命值
	int max_life;//血量上限  -》加血 -》加百分比血 -》加血量上限
	int power;//攻击力 
	int speed;//飞机速度
	int bullet_num; //子弹数量（一次发射多少个子弹）
	int ID_skin = 0;

	//int exp;
};


typedef struct enemy {
	plane* pthis;
	struct enemy* next, * pre;  //方便删除
}*LinkList;    //用链表放敌机信息

typedef struct bullet_Node {
	struct bullet* bthis;
	struct bullet_Node* next, * pre;
}*LinkList_b;




//--------------------数据设计---------------------//

//----------------------service------------------------//


/*
* 负责人：
* 功能：初始化玩家的数据（像修改皮肤可引入其他文件中定义变量来标识图片指针初始化），buttle_num先初始化为1
* 参数：空
* 返回值：空
*/
void player_init();


/*
* 负责人：
* 功能：初始化敌机、子弹链表
* 参数：void
* 返回值：void
*/
void linklist_init();

/*
* 负责人：老魏
* 功能：初始化敌机
* 参数：void
* 返回值：void
*/
void enemy_init(plane *p);

/*
* 负责人：
* 功能：创建敌机
* 参数：void（可考虑改成int来表示创建的飞机数）
* 返回值：void
*/
void creat_enemy();

/*
* 负责人：
* 功能：保存武器图片
* 参数：int x,y
* 返回值：void
*/
void create_weapon(int x,int y,int width,int height,int temp);

/*
* 负责人：
* 功能：保存道具图片
* 参数：int x,y
* 返回值：void
*/
void create_tool(int x, int y,int width,int height,int temp);

/*
* 负责人：老魏
* 功能：创建子弹
* 参数：子弹坐标x,y,敌机/玩家子弹标记flag,flag为1表示是玩家发射子弹，为0表示是敌机发射子弹
* 返回值：void
*/
void create_bullet(int flag, double angle, int x, int y);

/*
* 负责人：
* 功能：删除死亡敌机
* 参数：指向死亡飞机地址
* 返回值：void
*/
void delet_enemy(plane* pthis);

/*
* 负责人：
* 功能：根据传入指针，判断玩家/敌机是否死亡，死亡返回1，否则返回0
* 参数：plane*
* 返回值：int
*/
int isDie(plane* pthis);
int isDie(boss1* b);


/*
* 负责人：
* 功能：控制发射子弹速度
* 参数：int ms，表示要停顿时间
* 返回值：bool
*/


bool Timer(int ms);

/*
* 负责人：
* 功能：检测玩家按键操作，并进行数据处理（按暂停时调用暂停界面函数）
       （处理坐标时考虑飞机在镜头内，发射子弹速度）
* 参数：void
* 返回值：void
*/
void detect_action();

/*

* 负责人：夏尔
* 功能：更新子弹坐标
* 参数：void
* 返回值：void
*/
void bullet_fly();

/*
* 负责人：
* 功能：更新坐标敌机
* 参数：void
* 返回值：void
*/
void enemy_fly();

/*
* 负责人：
* 功能：更新武器坐标
* 参数：void
* 返回值：void
*/
void weapon_fly();

/*
* 负责人：
* 功能：更新道具坐标
* 参数：void
* 返回值：void
*/
void tool_fly();

/*
* 负责人：小七
* 功能：检测敌机与玩家飞机是否会发生碰撞，若发生碰撞，敌机直接死亡（生命值归零），玩家扣除生命值
* 参数：void
* 返回值：void
*/
void crush_plane();



/*
* 负责人：
* 功能：判断子弹是否碰到飞机，碰到清除对应子弹，飞机扣血
* 参数：void
* 返回值：void
*/
void crush_bullet();

/*
* 负责人：夏尔
* 功能：检测是否存在越界（飞出镜头）子弹
*      有则删除
* 参数：void
* 返回值：void
*/
void detect_overstep();

/*
* 负责人：
* 功能：掉落道具或者武器，道具返回0 武器返回1
* 参数：void
* 返回值：int
*/
int drop_weapon_or_tool();

/*
* 负责人：
* 功能：敌人/玩家开火
* 参数：int
* 返回值：void
*/
void fire(int flag);
void fire_em(int flag);
/*
* 负责人：
* 功能：减少敌机/玩家生命值
* 参数：plane 代表受伤飞机，int 代表伤害值
* 返回值：void
*/
void damage(plane* p, int harm);
void damage(em_Node* p, int harm);
/*
* 负责人：
* 功能：改变飞机生命值,根据道具的属性，改变飞机life、max_life值，percent_life值以百分比来改变飞机的life值
* 参数：void
* 返回值：void
*/
void life_change(int tool_life, int tool_max_life, int tool_percent_life);
/*
* 负责人：
* 功能：改变飞机power值,根据道具的属性，改变飞机power、percent_power值以百分比来改变飞机的power值
* 参数：void
* 返回值：void
*/
void power_change(int tool_power,int tool_percent);
/*
* 负责人：
* 功能：改变飞机speed值,根据道具的属性，改变飞机的speed值
* 参数：void
* 返回值：void
*/
void speed_change(int tool_speed);
/*
* 负责人：
* 功能：改变飞机的xy坐标值
* 参数：void
* 返回值：void
*/
void x_y_change(int tool_x, int tool_y);

/*
* 负责人：
* 功能：改变飞机的大小
* 参数：void
* 返回值：void
*/
void w_h_change(int tool_width, int tool_height);

/*
* 负责人：
* 功能：改变飞机的大小
* 参数：void
* 返回值：void
*/
void bullet_num_change(int tool_bullet_num);

/*
* 负责人：空白
* 功能：加载会使用到的图片
* 参数：void
* 返回值：void
*/
void load();
/*
* 负责人：空白
* 功能：加载会使用到的音乐
* 参数：void
* 返回值：void
*/
void load_music();
void MonsterDied(const char* musicFilePath);

//----------------------service------------------------//
// 
//----------------------view------------------------//

/*：
* 负责人：阿星
* 功能：展示失败界面
* 参数：void
* 返回值：void
*/
void fail_interface(); //失败界面
/*：
* 负责人：空白
* 功能：展示武器
* 参数：void
* 返回值：void
*/
void show_weapon();
/*：
* 负责人：空白
* 功能：展示道具
* 参数：void
* 返回值：void
*/
void show_tool();

/*：
* 负责人：空白、看见了
* 功能：绘制背景、飞机、子弹等……
* 参数：void
* 返回值：void
*/
void draw();
//展示背景
void show_bk();
//展示玩家
void show_player();
//展示敌机（先判断是否死亡，若死亡，放爆炸动画）
void show_enemy();
//展示子弹 
void show_bullet();


/*
* 负责人：
* 功能：展示暂停界面，直到用户按下对应按键退出回到游戏界面
* 参数：void
* 返回值：void
*/
void show_pause();

/*
* 负责人：
* 功能：游戏界面运行逻辑
* 参数：void
* 返回值：void
*/
void start_game();
/*
* 负责人：
* 功能：随机掉落道具
* 参数：int x,y 坐标值
* 返回值：void
*/
int rand_tool();
/*
* 负责人：
* 功能：随机掉落装备
* 参数：
* 返回值：void
*/
int rand_weapon();

//----------------------view------------------------//
/*整合前提
	1，把bullet_fly和detect_overstep合到一起，只留下一个bullet_fly
	2，修改一下子弹的结构体
*/


//子弹发射参考代码
	 //定时器

	////绘制子弹
	//for (int i = 0; i < BULLET_NUMBER; i++) {
	//	if (!bullet[i].isDie)
	//		img_bullet.Draw(bullet[i].x, bullet[i].y);//在（x,y)加载子弹图片
	//}
	////发射子弹
	//if (GetAsyncKeyState(VK_SPACE) && Timer(300,0)){//timer（ms,0）ms越大子弹发得越慢,太小的话会黏在一起
	//	for (int i = 0; i < BULLET_NUMBER; i++) {//创建子弹
	//		if (bullet[i].isDie) {
	//			bullet[i].x = //飞机x位置加上飞机宽度的一半再减去子弹宽度的一半；
	//			bullet[i].y = //飞机的y坐标减去子弹的y长度；
	//			bullet[i].isDie = false;
	//			break;
	//		}
	//	}
	//}


/*
需要在初始化中加入一些代码
for(int i = 0; i < BULLET_NUMBER; i++){
	bullet[i].isDie = true;//ture时图片不会加载，false时子弹加载
}
*/