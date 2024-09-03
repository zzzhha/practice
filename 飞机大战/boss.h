#pragma once

struct boss1
{
	int life;
	int speed;
	int x, y;
	int width, height;
	double angle;  //转动角度
	int attack_flag_1; //攻击状态标识
	int cd;
};

/*
* 负责人：
* 功能：初始化boss
* 参数：void
* 返回值：void
*/
void boss_init();

/*
* 负责人：
* 功能：根据击杀数/得分判断是否生成boss
* 参数：int
* 返回值：int
*/
int detect_condition(int num);

/*
* 负责人：
* 功能：检测boss当前的状态，判断使用那种攻击方式
* 参数：
* 返回值：void
*/
int isAttack();

/*
* 负责人：
* 功能：boss攻击
* 参数：void
* 返回值：void
*/
void attack_b1();

/*
* 负责人：
* 功能：boss移动
* 参数：void
* 返回值：void
*/
void boss_fly();


/*
* 负责人：
* 功能：展示boss
* 参数：void
* 返回值：void
*/
void show_boss();



void victory_interface();
void crush_boss();

 //--------------------------------//
struct elite_monster {
	int life;
	int speed;
	int width, height;
	int bullet_num;
	int flag; //标识闪避状态
	int id;
};

typedef struct em_Node {
	int x, y;
	int ID;  //数组下标
	int life;
	int flag;
	struct em_Node* pre, *next;
} *LinkList_em;

/*
* 负责人：4C
* 功能：生成精英怪
* 参数：
* 返回值：void
*/
void create_em();

/*
* 负责人：
* 功能：精英怪飞行
* 参数：
* 返回值：void
*/
void elite_monster_fly();
/*
* 负责人：
* 功能：碰撞精英怪
* 参数：
* 返回值：void
*/
void crush_em();
/*
* 负责人：4C
* 功能：使对应敌机进行闪避
* 参数：敌机节点指针
* 返回值：void
*/
void dodge_1(em_Node* p);

/*
* 负责人：核废料
* 功能：判断对应飞机是否死亡
* 参数：链表节点指针
* 返回值：void
*/
int isDie(em_Node* p);

/*
* 负责人：核废料
* 功能：
* 参数：
* 返回值：void
*/
void delete_em(em_Node* p);

/*
* 负责人：阿星
* 功能：死亡后生成普通敌机/……
* 参数：敌机节点指针
* 返回值：void
*/
void death(em_Node* p);

/*
* 负责人：看见了
* 功能：打印敌机
* 参数：链表头指针
* 返回值：void
*/
void show_em();

/*
* 负责人：
* 功能：初始化精英怪
* 参数：
* 返回值：void
*/

void init_elite_monster();
