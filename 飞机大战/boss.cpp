#include"boss.h"
#include"play_game.h"
#include<thread>

using namespace std;
extern  plane player;
extern	LinkList L;
extern  int em_id;
extern LinkList_b BE;
IMAGE elite_monster_photo[5][2];  //ͼƬ
elite_monster em[5];
extern LinkList_em EM;
boss1 b1;
void boss_init()
{
	b1.life = 5000;
	b1.angle = 0;
	b1.speed = 1;
	b1.width = b1.height = 200;
	b1.x = getwidth() / 2;
	b1.y = -b1.height/2;

}

int detect_condition(int num)
{

	if (num >= 166)
		return 1;
	return 0;
}



void attack_b1()
{
	static clock_t start_1 = clock();
	clock_t end = clock();
	if (end - start_1 < 1000)
		return;
	int num = 0;
	double angle,t;
	//判断子弹发射数目
	if(b1.life<=2500){
		num = 8;
		t = 360.0 / (num + 1);
		angle = 180;
		for (int i = 0; i < num; i++)
		{
			angle -= t;
			create_bullet(0, angle, b1.x + b1.width / 2, b1.y + b1.height + 10);
		}
	}
	else if (b1.life <= 5000)
	{
		num = 3;
		t = 180.0 / (num + 1);
		angle = 90 ;
		for (int i = 0; i < num; i++)
		{
			angle += t;
			create_bullet(0, angle, b1.x + b1.width / 2, b1.y + b1.height + 10);
		}
	}  
	
	

	start_1 = clock();
}


void boss_fly() {
	static int t1=1 ,t2=1;
	//if (b1.x < 0 || b1.x >= (getwidth() - b1.width)) t1 *= -1;   //判断到边界改变t的值
	//if (b1.y < 0 || b1.y >= (getheight()/2 - b1.width)) t2 *= -1;
	if (b1.x >= (getwidth() - b1.width))
		t1 = -1;
	else if (b1.x <= 0)
		t1 = 1;
	if (b1.y >= (getheight() / 2 - b1.width))
		t2 *= -1;
	else if (b1.y <= 0)
		t2 = 1;
	b1.x += b1.speed * t1;
	b1.y += b1.speed * t2;
}

//-------------------------------------------
void victory_interface() {//胜利界面
		while (1) {
			settextstyle(80, 0, _T("宋体"));
			int textWidth = textwidth(_T("G a m e   w i n"));
			int textHeight = textheight(_T("G a m e   w i n"));
			int textX = (1080 - textWidth) / 2;
			int textY = (840 - textHeight) / 2;
			outtextxy(textX, textY, _T("G a m e   w i n"));
			Sleep(2500);//延迟2.5秒
			develop_staff();//展示开发人员界面
			controller();
		}
}

void crush_boss()
{
	// 判断Boss是否碰到玩家
	clock_t end_1 = clock();
	static clock_t start_1 = clock();

	if ((end_1 - start_1) >= (500 * CLOCKS_PER_SEC) / 1000)
	{
		if (abs((player.x + player.width / 2) - (b1.x + b1.width / 2)) < (player.width + b1.width) / 2
			&& abs((player.y + player.height / 2) - (b1.y + b1.height / 2)) < (player.height + b1.height) / 2)
		{
			// 检测到碰撞
			b1.life -= 200; // Boss的生命值减少200
			player.life -= player.max_life / 10; // 玩家的生命值减少最大生命值的1/10
		}
		start_1 = clock(); // 更新开始时间为当前时间
	}
}
//-------------------------------------------

//---------------------------------------//


void init_elite_monster()
{
	em[0] = { 2000,4,100,100,3,2,0 };
	em[1] = {5000,1,100,100,1,0,1};
	em[2] = {1000,3,100,100,5,3,2};
	em[3] = {2500,3,100,100,3,2,3};
	em[4] = {1000,5,100,100,3,5,4};
}



void create_em()
{
	LinkList_em t = (LinkList_em)malloc(sizeof(em_Node));
	if (t == NULL)
		return;
	srand((unsigned int)time(NULL));
	t->ID = rand() % 5;  //随机精英怪种类
	//初始化
	t->x = rand() % (1080 - em[t->ID].width);
	t->y = -100;
	t->life = em[t->ID].life;
	t->flag = em[t->ID].flag;
	LinkList_em tem = EM;
	if (tem->next != NULL)
		tem->next->pre = t;
	t->next = tem->next;
	t->pre = tem;
	tem->next = t;

}

void elite_monster_fly()
{
	LinkList_em p = EM->next, q;
	while (p != NULL)
	{
		p->y += em[p->ID].speed;

		if (p->y > getheight())
		{
			q = p->pre;
			delete_em(p);  //删除节点后p指向地址被释放，让p指向其先前前一个结点  
			p = q;
		}
		p = p->next;
	}

}

void crush_em() 
{
	LinkList_em E = EM->next;

	LinkList_em e;
	// 遍历敌机链表
	while (E != NULL)
	{
		e = E;


		// 检测飞机是否碰撞
		if (abs(((player.x * 2 + 50) / 2) - ((e->x * 2 + 100) / 2)) < ((50 + 100) / 2)
			&& abs(((player.y * 2 + 50) / 2) - ((e->y * 2 + 100) / 2)) < ((50 + 100) / 2)

			)

		{
			// 检测到碰撞
			damage(e, e->life); // 敌机被摧毁
			damage(&player, 100);    // 假设玩家有100hp，则玩家失去40hp

		}

		// 移动到下一个敌机节点
		E = E->next;
	}
}

void dodge_1(em_Node* p)
{
	LinkList_b q = BE->next;
	while (q != NULL)
	{
	
		if (abs(((q->bthis->x * 2 + 30) / 2) - ((p->x * 2 + 100) / 2)) < ((30 + 100) / 2)
			&& abs(((q->bthis->y*2+40)/2)-((p->y*2+100)/2)<(40+150)/2)
			)
		{
			srand((unsigned int)time(NULL));
			int t = rand() % 2;
			if (!t)t = -1;
			if (p->flag)
			{
				p->x = p->x + em[p->ID].width * t;
				if (p->x > 1080)p->x = 980;
				if (p->x < 0)p->x = 0;
				p->flag--;
				printf("闪避");
			}
		}
		q = q->next;
	}

}

int isDie(em_Node* p)
{
	if (p->life <= 0)
		return 1;
	else
		return 0;
}

void delete_em(em_Node* p)
{
	em_Node* q = EM->next;
	while(q != NULL && q != p) //遍历链表查询
	q = q->next;
	if (q)
	{

		//删除节点
		q->pre->next = q->next;
		if (q->next)
			q->next->pre = q->pre;
		free(q);
	}
}

void death(em_Node* p)
{
	int flag = 0;
	srand((unsigned int)time(NULL));
	while (flag != 2)
	{
		int R1, R2;
		//根据随机数在不同位置生成敌人
		R1 = R2 = rand() % 2 ? -1 : 1;
		//创建节点
		enemy* t = (enemy*)malloc(sizeof(enemy));
		if (t == NULL)
			return;
		t->pthis = (plane*)malloc(sizeof(plane));
		if (t->pthis == NULL)
			return;
		//初始化敌机
		enemy_init(t->pthis);      //初始化
		//调整生成位置为精英怪周围
		t->pthis->x = p->x + 40 * R1;  //数值可改为图片大小
		t->pthis->y = p->y + 40 * R2;
		if (t->pthis->x < 1080 - 50 && t->pthis->x > 0 && t->pthis->y < 800 - 50)
		{
			//将创建的节点连接到链表
			if (L->next != NULL)
				L->next->pre = t;
			t->next = L->next;
			t->pre = L;
			L->next = t;
			flag++;
		}
	}
}

