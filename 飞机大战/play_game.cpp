#include"play_game.h"
#include<thread>
using namespace std;
#define M_PI 3.14159265358979323846
//����M_PI���Ȳ�������ʱ�����ƫ��
extern int flag;
extern ExMessage msg;
extern struct bullet weapon[15];
extern struct tool_plane tool[25];
extern IMAGE elite_monster_photo[5][2];
extern struct elite_monster em[5];
extern boss1 b1;
IMAGE skin_plane[9][2];//��ŷɻ�Ƥ��
IMAGE skin_bullet[10][2];    //����ӵ�Ƥ��
IMAGE tool_photo[20];	//��ŵ���ͼƬ����load������һ������

IMAGE play_bk;//��ű���
int djcount = 0;//�¼ӱ��������ڼ�¼С��������
int kill;
int bullet_ind = 0;
int bullet_temp;
plane player;   //�ȶ������
LinkList L;     //����ŵл�����
LinkList_b BP;//��������ӵ�
LinkList_b BE; //��������ӵ�
LinkList_w BW;//������������
LinkList_w BT;//�����������
LinkList_em EM;//���徫Ӣ������

IMAGE boss_photo[2];//boss
IMAGE boss_bullet_photo[2];//boss�ӵ�
IMAGE monster_photo[2];//С��
IMAGE monster_bullet_photo[2];//��Ӣ���ӵ�
int bk_y = 0;//����ͼƬy��


void player_init()
{
	player.bullet_num = 1;
	player.height = player.width = 100;
	player.ID_skin = 0;
	player.life = 100;
	player.max_life = 100;
	player.speed = 4;
	player.power = 10;
	player.x = (getwidth() - skin_plane[0][0].getwidth()) / 2;
	player.y = getheight() - 50;
}

void enemy_init(plane* p)
{
	p->bullet_num = 1;
	p->height = p->width = 50;
	p->ID_skin = 0;
	p->life = 150;
	p->speed = 3;
	p->x = rand() % (1086- monster_photo[0].getwidth());
	p->y = - monster_photo[0].getheight();
}

void linklist_init()
{
	L = (enemy*)malloc(sizeof(enemy));
	if (L == NULL)
		return;
	L->next =L->pre= NULL;
	BP = (bullet_Node*)malloc(sizeof(bullet_Node));
	if (BP == NULL)
		return;
	BP->next = BP->pre = NULL;
	BE = (bullet_Node*)malloc(sizeof(bullet_Node));
	if (BE == NULL)
		return;
	BE->next = BE->pre = NULL;
	BW = (weapon_Node*)malloc(sizeof(weapon_Node));
	if (BW == NULL)
		return;
	BW->next = BW->pre = NULL;
	BT = (weapon_Node*)malloc(sizeof(weapon_Node));
	if (BT == NULL)
		return;
	BT->next = BT->pre = NULL;
	EM = (em_Node*)malloc(sizeof(em_Node));
	if (EM == NULL)
		return;
	EM->next = EM->pre = NULL;
}

void creat_enemy()
{
	//ͨ����������Ʒɻ�����
	int t;
	srand((unsigned int)time(NULL));
	t = rand() % 100;
	t > 60 ? t = 2 : t = 0;
	t = 1;
	for (int i = 0; i <1; i++)
	{
		if (!Timer(1000))
			continue;
		//�����ڵ�
		
		enemy* t = (enemy*)malloc(sizeof(enemy));
		if (t == NULL)
			return;
		t->pthis = (plane*)malloc(sizeof(plane));
		if (t->pthis == NULL)
			return;
		//��ʼ���л�
		enemy_init(t->pthis);
		//�������Ľڵ����ӵ�����
		if (L->next != NULL)
			L->next->pre = t;
		t->next = L->next;
		t->pre = L;
		L->next = t;
	}
	if (djcount % 15 == 0&& djcount!=0)
	{
		create_em();
		djcount++;
	}
	
	
}

void create_weapon(int x,int y,int width,int height,int temp) {
	weapon_Node* p = (weapon_Node*)malloc(sizeof(weapon_Node));
	if (p == NULL)
		return;
	p->x = x, p->y = y;
	p->width=width, p->height = height;
	p->tool_temp = temp;
	p->next = p->pre = NULL;
	LinkList_w tem=BW;
	if (tem->next != NULL)
	{
		tem->next->pre = p;
	}
	p->next = tem->next;
	p->pre = tem;
	tem->next = p;
}

void create_tool(int x, int y, int width, int height,int temp) {
	weapon_Node* p = (weapon_Node*)malloc(sizeof(weapon_Node));
	if (p == NULL)
		return;
	p->x = x, p->y = y;
	p->tool_temp = temp;
	p->width = width, p->height = height;
	p->next = p->pre = NULL;
	LinkList_w tem = BT;
	if (tem->next != NULL)
	{
		tem->next->pre = p;
	}
	p->next = tem->next;
	p->pre = tem;
	tem->next = p;
}


void create_bullet(int flag, double angle,int x,int y)
{
	bullet_Node* p = (bullet_Node*)malloc(sizeof(bullet_Node));
	if (p == NULL)
		return;
	p->bthis = (bullet*)malloc(sizeof(bullet));
	if (p->bthis == NULL)
		return;
	
	LinkList_b tem;
	if (flag==1)
	{
		p->bthis->angle = angle;
		p->bthis->harm = weapon[bullet_ind].harm;
		p->bthis->ID_bullet = weapon[bullet_ind].ID_bullet;
		p->bthis->speed = weapon[bullet_ind].speed+3;
		p->bthis->x = x;
		p->bthis->y = y;
		p->next = p->pre = NULL;
		tem = BP;
	}
	else
	{
		
		p->bthis->angle = angle;
		p->bthis->harm = 50;
		p->bthis->speed = 3;
		p->bthis->x = x;
		p->bthis->y = y;
		p->next = p->pre = NULL;
		tem = BE;
	}
	if (tem->next != NULL)
	{
		tem->next->pre = p;	
	}
	p->next = tem->next;
	p->pre = tem;
	tem->next = p;  
}

void fire(int flag)
{
	static clock_t start = clock();
	clock_t end = clock();

	double angle, t;
	if (end - start < 250)
		return;
	if (player.bullet_num < 5)
	{
		t = 180.0 / (player.bullet_num + 1);
		for (angle = 90 - t; angle > -90; angle -= t)
		{
			create_bullet(flag, angle, player.x + player.width / 2 - 25, player.y);
		}
	}
	else
	{
		t = 360.0 / (player.bullet_num + 1);
		for (angle = 180 - t; angle > -180; angle -= t)
		{
			create_bullet(flag, angle, player.x + player.width / 2 - 25, player.y);
		}
	}
	
	start = clock(); 
}


void fire_em(int flag)
{
	static clock_t start_em = clock();
	clock_t end_em = clock();		
	double angle, t;
		if (end_em - start_em < 2000)
			return;
		LinkList_em p = EM->next;
		while (p != NULL) {
			if (em[p->ID].bullet_num < 5)
			{
				t = 180.0 / (em[p->ID].bullet_num + 1);
				for (angle = 90 + t; angle < 270; angle += t)
				{
					/*printf("����");*/
					create_bullet(flag, angle, p->x + 50, p->y + 100);

				}
			}
			else
			{
				t = 360.0 / (em[p->ID].bullet_num + 1);
				for (angle = 180; angle > -180; angle -= t)
				{
					create_bullet(flag, angle, p->x + 50, p->y + 100);
				}
			}
			p = p->next;
		}
	start_em = clock();
}

void delet_enemy(plane* pthis)
{
	enemy* p = L->next;
	while (p != NULL && p->pthis != pthis) //���������ѯ
		p = p->next;
	if (p)//���ҵ�
	{
		
		//ɾ���ڵ�
		p->pre->next = p->next;
		if(p->next)
		p->next->pre = p->pre;
		free(p);
		djcount++;
	}
}

void delete_weapon(weapon_Node *pthis)
{
	weapon_Node* p = BW->next;
	while (p != NULL&& p!=pthis) 
	{
		p = p->next;
	}
	if (p)
	{
		p->pre->next = p->next;
		if (p->next)
			p->next->pre = p->pre;
		free(p);
	}
}

void delete_tool(weapon_Node* pthis)
{
	weapon_Node* p = BT->next;
	while (p != NULL && p!=pthis)
	{
		p = p->next;
	}
	if (p)
	{
		p->pre->next = p->next;
		if (p->next)
			p->next->pre = p->pre;
		free(p);
	}
}

int drop_weapon_or_tool() {
	
	return rand() % 3;
}

int isDie(plane* pthis)
{
	if (pthis->life <= 0)
		return 1;
	else
		return 0;
}

bool Timer(int ms) {
	static int start;
	int end = clock();
	if (end - start >= ms) {
		start = end;
		return true;
	}
	return false;
}

void detect_action()
{
	if (GetAsyncKeyState('W') && player.y > player.speed)
		player.y -= player.speed;
	if (GetAsyncKeyState('S') && player.y+player.height < getheight())
		player.y += player.speed;
	if (GetAsyncKeyState('A') && player.x > player.speed)
		player.x -= player.speed;
	if (GetAsyncKeyState('D') && player.x+player.width < getwidth())
		player.x += player.speed;

	if (GetAsyncKeyState(VK_SPACE))
	{
		fire(1);
	}
	if (_kbhit()) {
		char ch = _getch(); // ��ȡ����
		if (ch == 84 || ch == 116) { // 'T' �� 't'
			show_pause();
		}
	}
}


void bullet_fly() 
{
	//�л��ӵ�����
	bullet_Node* p = BE->next;//ָ����Ԫ�ڵ�
	double a;
	while (p != NULL)
	{
		a = p->bthis->angle * M_PI / 180.0;
		/*p->bthis->y += p->bthis->speed;*/
		p->bthis->y -= (p->bthis->speed + 3) * cos(a);
		p->bthis->x-= (p->bthis->speed + 3) * sin(a);
		p = p->next;
	}
	
	//����ӵ�����
	p = BP->next;
	while (p != NULL)
	{
		/*p->bthis->y -= p->bthis->speed*/
		a = p->bthis->angle * M_PI / 180.0;
		p->bthis->y -= p->bthis->speed * cos(a);
		p->bthis->x -= p->bthis->speed * sin(a);
		p = p->next;
	}
	
}

void enemy_fly()
{
	enemy* p = L->next,*q;
	while (p != NULL)
	{
		p->pthis->y += p->pthis->speed;
		
		if (p->pthis->y > getheight())
		{
			q = p->pre;
			delet_enemy(p->pthis);  //ɾ���ڵ��pָ���ַ���ͷţ���pָ������ǰǰһ�����  
			p = q;
		}
		p = p->next;
	}

}


void tool_fly()
{
	weapon_Node* p=BT->next,*q;
	while (p != NULL )
	{
		p->y += tool[p->tool_temp].self_speed;
		//ɾ����Ӧ�ڵ�
		if (p->y > getheight())
		{
			q = p->pre;
			delete_tool(p);
			p = q;
		}	
		p = p->next;
	}
	
}

void weapon_fly(){
	weapon_Node* p = BW->next,*q;
	while (p != NULL)
	{
		p->y += weapon[p->tool_temp].speed;
		if (p->y  > getheight())
		{
			q = p->pre;
			delete_weapon(p);
			p = q;
		}
			
		p = p->next;
	}
}

void crush_plane(){
	enemy* E = L->next;

	plane* e;
	// �����л�����
	while (E != NULL)
	{
		e = E->pthis;


		// ���ɻ��Ƿ���ײ
		if (e->x<player.x+player.width&&e->x+e->width>player.x&&
			e->y<player.y+player.height&&e->y+e->height>player.y

			)

		{
			// ��⵽��ײ
			damage(e, e->life); // �л����ݻ�
			damage(&player,40);    // ���������100hp�������ʧȥ40hp

		}

		// �ƶ�����һ���л��ڵ�
		E = E->next;
	}

	

}


void crush_bullet()
{
	//��������û�������л��ӵ�

	bullet_Node* p = BE->next,*q;  //����ָ�룬ָ��л��ӵ�������Ԫ���
	while (p != NULL)
	{
		//�ж������Ƿ��غ�

		if (abs(((p->bthis->x * 2 + 30) / 2) - ((player.x * 2 + player.width) / 2)) < ((30 + player.width) / 2)
			&& abs(((p->bthis->y * 2 + 40) / 2) - ((player.y * 2 + player.height) / 2)) < ((40 + player.height) / 2
			))
		{
			q = p->pre;
			damage(&player,p->bthis->harm);  //��ҿ�Ѫ
			//ɾ���ӵ����
			p->pre->next = p->next;
			if (p->next != NULL)
				p->next->pre = p->pre;
			free(p);
			p = q;
		}
		p = p->next;
	}

	enemy* e = L->next;  //����ָ��л�������Ԫ�ڵ�ָ��
	while (e != NULL)
	{
		p = BP->next;   //ˢ��pָ�룬ʹ��ָ������ӵ�������Ԫ�ڵ�
		//����ÿһ�ܵл�����Ƿ��������ӵ�
		while (p != NULL)
		{

			if(abs(((p->bthis->x*2+30)/2)-((e->pthis->x*2+e->pthis->width)/2))<((30+e->pthis->width)/2)
				&&abs(((p->bthis->y*2+40)/2)-((e->pthis->y*2+e->pthis->height)/2))<(( 40+ e->pthis->height)/2)
				)
			{
				q = p->pre;
				damage(e->pthis,p->bthis->harm+player.power); //�л���Ѫ
				//ɾ���ӵ����
				p->pre->next = p->next;
				if (p->next != NULL)
					p->next->pre = p->pre;
				free(p);
				p = q;
			}
			p = p->next;
		}
		e = e->next;
	}
	em_Node* em = EM->next;  //����ָ��л�������Ԫ�ڵ�ָ��
	while (em != NULL)
	{
		p = BP->next;   //ˢ��pָ�룬ʹ��ָ������ӵ�������Ԫ�ڵ�
		//����ÿһ�ܵл�����Ƿ��������ӵ�
		while (p != NULL)
		{

			if (abs(((p->bthis->x * 2 + 30) / 2) - ((em->x * 2 + 100) / 2)) < ((30 + 100) / 2)
				&& abs(((p->bthis->y * 2 + 40) / 2) - ((em->y * 2 + 100) / 2)) < ((40 + 100) / 2)
				)
			{
				q = p->pre;
				damage(em, p->bthis->harm + player.power); //�л���Ѫ
				//ɾ���ӵ����
				p->pre->next = p->next;
				if (p->next != NULL)
					p->next->pre = p->pre;
				free(p);
				p = q;
			}
			p = p->next;
		}
		em = em->next;
	}

	if(detect_condition(kill))
	{
		p = BP->next;   //ˢ��pָ�룬ʹ��ָ������ӵ�������Ԫ�ڵ�
		//���boss�Ƿ��������ӵ�
		while (p != NULL)
		{

			if (p->bthis->x<b1.x+b1.width&&p->bthis->x+30>b1.x&&
				p->bthis->y<b1.y+b1.height&&p->bthis->y+40>b1.y
				)
			{
				q = p->pre;
				b1.life -= p->bthis->harm;
				//ɾ���ӵ����
				p->pre->next = p->next;
				if (p->next != NULL)
					p->next->pre = p->pre;
				free(p);
				p = q;
			}
			p = p->next;
		}
	}
}

void crush_weapon() {
	weapon_Node* E = BW->next;

	// ������������
	while (E != NULL)
	{
		// ���ɻ��Ƿ���ײ
		if (E->x<player.x + player.width && E->x + E->width>player.x &&
			E->y<player.y + player.height && E->y + E->width>player.y)//��⵽��ײ
		{
			bullet_ind = bullet_temp;

			delete_weapon(E);
			return;
		}
		// �ƶ�����һ���л��ڵ�
		E = E->next;
	}
}

void crush_tool() {
	weapon_Node* E = BT->next;
	

	// ������������
	while (E != NULL)
	{
		// ���ɻ��Ƿ���ײ
		if (E->x<player.x + player.width && E->x + E->width>player.x &&
			E->y<player.y + player.height && E->y + E->width>player.y)//��⵽��ײ
		{
			//��Ч
			life_change(tool[E->tool_temp].life, tool[E->tool_temp].max_life, tool[E->tool_temp].percent_life);
			power_change(tool[E->tool_temp].power,tool[E->tool_temp].precent_power);
			speed_change(tool[E->tool_temp].buff_speed);
			x_y_change(tool[E->tool_temp].x, tool[E->tool_temp].y);
			w_h_change(tool[E->tool_temp].width, tool[E->tool_temp].height);
			bullet_num_change(tool[E->tool_temp].bullet_num);
			//ɾ��
			delete_tool(E);
			return;
		}
		// �ƶ�����һ���л��ڵ�
		E = E->next;
	}
}

void detect_overstep()
{
	bullet_Node* t,*p;//����������ɾ���ӵ�
	//��������ӵ�
	t = BP->next;   //ָ��tָ����Ľڵ�
	while (t != NULL)
	{
		//����Ƿ�Խ��
		if (t->bthis->y<0 || t->bthis->y>getheight() || t->bthis->x<0 || t->bthis->x>getwidth())
		{
			//ɾ��t�ڵ��ӵ�
			p = t->pre;       //���Ҫɾ���ڵ��ǰ�ýڵ�
			t->pre->next = t->next;
			if (t->next != NULL)
				t->next->pre = t->pre;
			free(t);
			t = p;           //����ִ����ɾ��������t�ڵ���ʧ��t��ʱָ������ɽڵ㣬������ָ��ǰ�ýڵ�
		}
		t = t->next;   //t�ڵ�����ɣ�ǰ��
	}
}


void load() {
	//����ͼƬ����
	loadimage(&play_bk, "photo/play_bk.jpg", 1080, 800);
	//bossͼƬ����
	loadimage(boss_photo, "photo/boss_1_0.jpg", b1.width, b1.height);
	loadimage(boss_photo + 1, "photo/boss_1_1.jpg", b1.width, b1.height);
	//boss�ӵ�����

	loadimage(boss_bullet_photo, "photo/ά����_0.jpg", 30, 40);
	loadimage(boss_bullet_photo + 1, "photo/ά����_1.jpg", 30, 40);
	//С��ͼƬ����
	loadimage(monster_photo,  "photo/monster_1_0.jpg", 50,50);
	loadimage(monster_photo + 1,"photo/monster_1_1.jpg" , 50,50);
	//��Ӣ���ӵ�����
	loadimage(monster_bullet_photo,"photo/��ͳ��_0.jpg", 30, 40);
	loadimage(monster_bullet_photo + 1,"photo/��ͳ��_1.jpg" , 30, 40);
	//���ͼƬ����
	loadimage(&skin_plane[0][0], "photo/player_1_0.jpg", player.height, player.width);
	loadimage(&skin_plane[0][1], "photo/player_1_1.jpg", player.height, player.width);
	//����ӵ�����
	loadimage(&skin_bullet[0][0], "photo/player_bullet_1_0.jpg", 30, 40);
	loadimage(&skin_bullet[0][1], "photo/player_bullet_1_1.jpg", 30, 40);
	loadimage(&skin_bullet[1][0], "photo/player_bullet_2_0.jpg", 30, 40);
	loadimage(&skin_bullet[1][1], "photo/player_bullet_2_1.jpg", 30, 40);
	loadimage(&skin_bullet[2][0], "photo/player_bullet_3_0.jpg", 30, 40);
	loadimage(&skin_bullet[2][1], "photo/player_bullet_3_1.jpg", 30, 40);
	loadimage(&skin_bullet[3][0], "photo/player_bullet_4_0.jpg", 30, 40);
	loadimage(&skin_bullet[3][1], "photo/player_bullet_4_1.jpg", 30, 40);
	loadimage(&skin_bullet[4][0], "photo/player_bullet_5_0.jpg", 30, 40);
	loadimage(&skin_bullet[4][1], "photo/player_bullet_5_1.jpg", 30, 40);
	loadimage(&skin_bullet[5][0], "photo/player_bullet_6_0.jpg", 30, 40);
	loadimage(&skin_bullet[5][1], "photo/player_bullet_6_1.jpg", 30, 40);
	loadimage(&skin_bullet[6][0], "photo/player_bullet_7_0.jpg", 30, 40);
	loadimage(&skin_bullet[6][1], "photo/player_bullet_7_1.jpg", 30, 40);
	loadimage(&skin_bullet[7][0], "photo/player_bullet_8_0.jpg", 30, 40);
	loadimage(&skin_bullet[7][1], "photo/player_bullet_8_1.jpg", 30, 40);
	//����ͼƬ����
	loadimage(&tool_photo[0], "photo/tool_1.jpg", 50, 50);
	loadimage(&tool_photo[1], "photo/tool_2.jpg", 50, 50);
	loadimage(&tool_photo[2], "photo/tool_3.jpg", 50, 50);
	loadimage(&tool_photo[3], "photo/tool_4.jpg", 50, 50);
	loadimage(&tool_photo[4], "photo/tool_5.jpg", 50, 50);
	loadimage(&tool_photo[5], "photo/tool_6.jpg", 50, 50);
	loadimage(&tool_photo[6], "photo/tool_7.jpg", 50, 50);
	loadimage(&tool_photo[7], "photo/tool_8.jpg", 50, 50);
	loadimage(&tool_photo[8], "photo/tool_9.jpg", 50, 50);
	loadimage(&tool_photo[9], "photo/tool_10.jpg", 50, 50);
	loadimage(&tool_photo[10], "photo/tool_11.jpg", 50, 50);
	loadimage(&tool_photo[11], "photo/tool_12.jpg", 50, 50);
	loadimage(&tool_photo[12], "photo/tool_13.jpg", 50, 50);
	loadimage(&tool_photo[13], "photo/tool_14.jpg", 50, 50);
	loadimage(&tool_photo[14], "photo/tool_15.jpg", 50, 50);
	loadimage(&tool_photo[15], "photo/tool_16.jpg", 50, 50);
	loadimage(&tool_photo[16], "photo/tool_17.jpg", 50, 50);
	loadimage(&tool_photo[17], "photo/tool_18.jpg", 50, 50);
	loadimage(&tool_photo[18], "photo/tool_19.jpg", 50, 50);
	//��Ӣ��ͼƬ����
	loadimage(&elite_monster_photo[0][0], "photo/elite_monster_1_0.jpg", 100, 100);
	loadimage(&elite_monster_photo[0][1], "photo/elite_monster_1_1.jpg", 100, 100);
	loadimage(&elite_monster_photo[1][0], "photo/elite_monster_2_0.jpg", 100, 100);
	loadimage(&elite_monster_photo[1][1], "photo/elite_monster_2_1.jpg", 100, 100);
	loadimage(&elite_monster_photo[2][0], "photo/elite_monster_3_0.jpg", 100, 100);
	loadimage(&elite_monster_photo[2][1], "photo/elite_monster_3_1.jpg", 100, 100);
	loadimage(&elite_monster_photo[3][0], "photo/elite_monster_4_0.jpg", 100, 100);
	loadimage(&elite_monster_photo[3][1], "photo/elite_monster_4_1.jpg", 100, 100);
	loadimage(&elite_monster_photo[4][0], "photo/elite_monster_5_0.jpg", 100, 100);
	loadimage(&elite_monster_photo[4][1], "photo/elite_monster_5_1.jpg", 100, 100);
}

void load_music() {
	mciSendString("open music\\����������Ч.mp3", 0, 0, 0);
	mciSendString("open music\\��Ц��������Ч.mp3", 0, 0, 0);
	mciSendString("open music\\����ʤ����Ч.mp3", 0, 0, 0);
	mciSendString("open music\\����������Ч.mp3", 0, 0, 0);	mciSendString("open music\\��Ӣ��������Ч.mp3", 0, 0, 0);
}

void play_kunkun() 
{
	// ����Ƶ�ļ�  
	mciSendString("open music\\����������Ч.mp3", 0, 0, 0);
	// ������Ƶ  
	mciSendString(TEXT("play music\\����������Ч.mp3"), NULL, 0, NULL);

}

void play_fail()
{
	// ����Ƶ�ļ�  
	mciSendString("open music\\����ʧ����Ч.mp3", 0, 0, 0);
	// ������Ƶ  
	mciSendString(TEXT("play music\\����ʧ����Ч.mp3"), NULL, 0, NULL);
}
void play_win()
{
	// ����Ƶ�ļ�  
	mciSendString("open music\\����ʤ����Ч.mp3", 0, 0, 0);
	// ������Ƶ  
	mciSendString(TEXT("play music\\����ʤ����Ч.mp3"), NULL, 0, NULL);
}
void play_boss_die()
{
	// ����Ƶ�ļ�  
	mciSendString("open music\\��Ц��������Ч.mp3", 0, 0, 0);
	// ������Ƶ  
	mciSendString(TEXT("play music\\��Ц��������Ч.mp3"), NULL, 0, NULL);
}

int isDie(boss1* p) {
	if(p->life<0)
	{
		
		return 1;
	}
	return 0;
}

void play_otto()
{
	// ����Ƶ�ļ�  
	mciSendString("open music\\��Ӣ��������Ч.mp3", 0, 0, 0);
	// ������Ƶ  
	mciSendString("play music\\��Ӣ��������Ч.mp3", 0, 0, 0);
}



void show_bk() {
	
	putimage(0, bk_y, &play_bk);
	putimage(0, bk_y - 800, &play_bk);
	bk_y += player.speed + 3;//y���ƶ��ٶ�,��������ٶȽ��и���
	if (bk_y > 800) {
		bk_y -= 800;
	}
}

void show_player() {
	

	putimage(player.x, player.y, &skin_plane[player.ID_skin][1], NOTSRCERASE);
	putimage(player.x, player.y,  &skin_plane[player.ID_skin][0], SRCINVERT);


	settextcolor(RED);
	settextstyle(40, 0, "������κ");
	char arr[20];
	itoa(player.life, arr, 10);
	outtextxy(50, getheight() - 160, arr);
	setfillcolor(WHITE);
	double m = player.max_life * 1.0 / 100 * (200 - 50);
	fillrectangle(50, getheight() - 100, m+50, getheight() - 70);
	itoa(player.max_life, arr, 10);
	outtextxy(120, getheight() - 160, "/");
	outtextxy(140, getheight() - 160, arr);
	double w = player.life*1.0 / 100 * (200 - 50);
	setfillcolor(RED);
	fillrectangle(50, getheight() - 100, w+50, getheight() - 70);
	settextcolor(BLACK);
	outtextxy(800, getheight() - 150, "������");
	itoa(player.power, arr, 10);
	outtextxy(950, getheight() - 150, arr);
	outtextxy(800, getheight() - 100, "�ٶ�ֵ");
	itoa(player.speed, arr, 10);
	outtextxy(950, getheight() - 100, arr);
	outtextxy(800, getheight() - 50, "�ӵ���");
	itoa(player.bullet_num, arr, 10);
	outtextxy(950, getheight() - 50, arr);

	//������
	if(kill<166)
	{
		setfillcolor(WHITE);
		fillrectangle(50, 50, 200, 70);
		setfillcolor(GREEN);
		fillrectangle(50, 50, 50 + kill / 166.0 * 150, 70);
	}
}

void show_enemy() 
{
	
	enemy* i = L->next,*j;
	while (i != NULL) {
		if (isDie(i->pthis))
		{
			kill++;
			//�����������ߵ���
			int a = drop_weapon_or_tool();
			srand(time(0));
			if (a == 1)//��������
			{
				create_weapon(i->pthis->x, i->pthis->y,i->pthis->width,i->pthis->height, rand_weapon());
				
			}
			else//�������
			{
				create_tool(i->pthis->x, i->pthis->y, i->pthis->width, i->pthis->height,rand_tool());
				
			}
			j = i->pre;//ɾ���л�
			delet_enemy(i->pthis);
			thread t1(play_kunkun);
			i = j;
			t1.join();
		}
		else{
			putimage(i->pthis->x, i->pthis->y, &monster_photo[1], NOTSRCERASE);
			putimage(i->pthis->x, i->pthis->y, &monster_photo[0], SRCINVERT);
		}
		i = i->next;
	}

}

void show_em()
{
	printf("��Ӣ�ֳ��֣�");
	em_Node* i = EM->next, * j;
	while (i != NULL) {

		dodge_1(i);
		fire_em(0);
		if (isDie(i)) {
			kill+=5;
			thread t2(play_otto);
			//�����������ߵ���
			int a = drop_weapon_or_tool();
			if (a == 1)//��������
			{
				create_weapon(i->x, i->y, em[i->ID].width, em[i->ID].height, rand_weapon());
			}
			else//�������
			{
				create_tool(i->x, i->y, em[i->ID].width, em[i->ID].height, rand_tool());
			}
			j = i->pre;//ɾ���л�
			death(i);
			delete_em(i);

			i = j;
			t2.join();

		}
		else {
			putimage(i->x, i->y, elite_monster_photo[i->ID] + 1, NOTSRCERASE);
			putimage(i->x, i->y, elite_monster_photo[i->ID] + 0, SRCINVERT);
		}
		i = i->next;
	}
}

void show_boss()
{
	putimage(b1.x, b1.y, &boss_photo[1], NOTSRCERASE);
	putimage(b1.x, b1.y, &boss_photo[0], SRCINVERT);

	setfillcolor(WHITE);
	double m = 1000 * 1.0 / 100 * (200 - 50);
	fillrectangle(100,  100, getwidth()-100, 150);

	double w =b1.life * 1.0 / 100 * (200 - 50);
	setfillcolor(RED);
	fillrectangle(100,  100, 100+ b1.life/5000.0*(getwidth()-200), 150);
}

void show_bullet()
{
	LinkList_b i = BP->next;
	while (i != NULL) {
		putimage(i->bthis->x, i->bthis->y, &skin_bullet[bullet_ind][1], NOTSRCERASE);
		putimage(i->bthis->x, i->bthis->y, &skin_bullet[bullet_ind][0], SRCINVERT);
		i = i->next;
	}
	i = BE->next;
	while (i != NULL) {
		putimage(i->bthis->x, i->bthis->y, &monster_bullet_photo[1], NOTSRCERASE);
		putimage(i->bthis->x, i->bthis->y,&monster_bullet_photo[0], SRCINVERT);
		i = i->next;
	}
}

void show_weapon() {
	LinkList_w p = BW->next;
	while (p != NULL) {
		putimage(p->x, p->y, &skin_bullet[p->tool_temp][1], NOTSRCERASE);
		putimage(p->x, p->y, &skin_bullet[p->tool_temp][0], SRCINVERT);
		p = p->next;
	}
}

void show_tool() {
	LinkList_w p = BT->next;
	while (p != NULL) {
		putimage(p->x, p->y, &tool_photo[p->tool_temp]);
		putimage(p->x, p->y, &tool_photo[p->tool_temp]);
		p = p->next;
	}
}

void show_pause() {
	while (1) {
		int x1 = 340, y1 = 300, x2 = 740, y2 = 540;
		setlinecolor(DARKGRAY);
		setfillcolor(LIGHTBLUE);
		setlinestyle(PS_SOLID, 1);
		rectangle(x1, y1, x2, y2);
		floodfill(x1 + 1, y1 + 1, DARKGRAY);
		settextstyle(40, 0, _T("����"));
		int textWidth1 = textwidth(_T("��T���ص���Ϸ"));
		int textHeight1 = textheight(_T("��T���ص���Ϸ"));
		int textWidth2 = textwidth(_T("��ESC���������˵�"));
		int textHeight2 = textheight(_T("��ESC���������˵�"));
		int textX1 = x1 + (x2 - x1 - textWidth1) / 2;
		int textY1 = y1 + (y2 - y1 - textHeight1) / 2 - 40;
		int textX2 = x1 + (x2 - x1 - textWidth2) / 2;
		int textY2 = y1 + (y2 - y1 - textHeight2) / 2 + 40;
		outtextxy(textX1, textY1, _T("��T���ص���Ϸ"));
		outtextxy(textX2, textY2, _T("��ESC���������˵�"));
		if (_kbhit()) {
			char ch = _getch(); // ��ȡ����
			if (ch == 84 || ch == 116) { // 'T' �� 't'
				break;
			}
			if (ch == 27) { // ESC
				controller();
			}
		}
		FlushBatchDraw();
	}
}

void fail_interface(){
	while (1) {
		settextstyle(80, 0, _T("����"));
		int textWidth = textwidth(_T("G a m e   o v e r"));
		int textHeight = textheight(_T("G a m e   o v e r"));
		int textX = (1080 - textWidth) / 2;
		int textY = (840 - textHeight) / 2;
		outtextxy(textX, textY, _T("G a m e   o v e r"));
		if (_kbhit()) {
				controller();
		}
	}

}

void start_game()
{
	int bf=0;
	kill = 0;
	srand(time(NULL));
	int starttime, frametime;
	player_init(); 

	boss_init(); //��ʼ��boss
	linklist_init(); //��ʼ������
	weapon_init();
	tool_init();
	init_elite_monster();
	load();   //����ͼƬ
	load_music();
	
	while (true)
	{
		starttime = clock();
		if (!bf&&detect_condition(kill))
		{
			bf = 1;
		}
		detect_action(); //����������

		
		if(bf)
		{
			attack_b1(); 
			boss_fly();
			//---------------------
			/*if (Timer(1000))*/
			crush_boss();
			//---------------------
		}

		bullet_fly();//�ӵ�����
		detect_overstep();  //���Խ���ӵ����;
		creat_enemy();  //�����л�

		enemy_fly();
		elite_monster_fly();
		weapon_fly();
		tool_fly();
		if (isDie(&player))
		{
			thread t3(play_fail);
			t3.join();
			fail_interface();  //ʧ�ܽ���
		}
		//-----------------------------------------------------
		if (isDie(&b1))
		{
			/*thread t3(play_win);
			t3.join();*/
			thread t4(play_win);
			t4.join();
			thread t5(play_boss_die);
			t5.join();
			victory_interface();//ʤ������
		}
		//-----------------------------------------------------
		crush_plane();//�л���ײ
		crush_bullet();//�ӵ���ײ
		crush_weapon();//��ײ������
		crush_tool();//��ײ������
		crush_em();//������Ӣ��

		BeginBatchDraw();

		cleardevice();
		
		draw();  //����չʾ
		
		EndBatchDraw();

		frametime = clock() - starttime;
		if (1000 / 60 - frametime > 0)
			Sleep(1000 / 60 - frametime);
		
	}
	
}

void draw()
{
	setbkmode(TRANSPARENT);

	//չʾ����
	show_bk();

	//չʾ���
	show_player();

	//չʾ�л������ж��Ƿ����������������ű�ը������
	show_enemy();
	show_em();
	if(detect_condition(kill))
	show_boss();
	//չʾ�ӵ� 
	show_bullet();
	//
	show_weapon();
	//
	show_tool();

	
}


int rand_tool()
{
	srand(time(0));

	return rand() %19;
}

int rand_weapon()
{
	srand(time(0));
	bullet_temp = rand() % 8;
	return bullet_temp;
}

void damage(plane* p, int harm)
{
	p->life -= harm;
}
void damage(em_Node* p, int harm)
{
	p->life -= harm;
}

void w_h_change(int tool_width, int tool_height) {
	player.width += tool_width;
	player.height += tool_height;
}
void x_y_change(int tool_x, int tool_y) {
	player.x += tool_x;
	if (player.x + player.width > 1080)
		player.x = 1080 - player.width;
	if (player.x + player.width < 0)
		player.x =0;
	player.y += tool_y;
	if (player.y + player.height > 800)
		player.y = 800 - player.height;
	if (player.y + player.height < 0)
		player.y = 0;
}

void power_change(int tool_power,int tool_percent_power) {
	player.power += tool_power;
	player.power += player.power * tool_percent_power / 100.0;
	if (player.power < 5)
		player.power = 5;
	if(player.power > 1000)
		player.power = 1000;
}
void life_change(int tool_life,int tool_max_life,int tool_percent_life) {
	player.life += tool_life;
	if(tool_max_life>0)
	{
		player.life += tool_max_life;
	}
	player.max_life += tool_max_life;
	player.life += player.max_life * tool_percent_life / 100.0;
	if (player.life > player.max_life)
		player.life = player.max_life;
}
void speed_change(int tool_speed) {
	player.speed += tool_speed;
	if (player.speed <1)
		player.speed = 1;
}
void bullet_num_change(int tool_bullet_num) {
	player.bullet_num += tool_bullet_num;
	if (player.bullet_num > 6)
		player.bullet_num = 6;
}