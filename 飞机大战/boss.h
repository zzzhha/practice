#pragma once

struct boss1
{
	int life;
	int speed;
	int x, y;
	int width, height;
	double angle;  //ת���Ƕ�
	int attack_flag_1; //����״̬��ʶ
	int cd;
};

/*
* �����ˣ�
* ���ܣ���ʼ��boss
* ������void
* ����ֵ��void
*/
void boss_init();

/*
* �����ˣ�
* ���ܣ����ݻ�ɱ��/�÷��ж��Ƿ�����boss
* ������int
* ����ֵ��int
*/
int detect_condition(int num);

/*
* �����ˣ�
* ���ܣ����boss��ǰ��״̬���ж�ʹ�����ֹ�����ʽ
* ������
* ����ֵ��void
*/
int isAttack();

/*
* �����ˣ�
* ���ܣ�boss����
* ������void
* ����ֵ��void
*/
void attack_b1();

/*
* �����ˣ�
* ���ܣ�boss�ƶ�
* ������void
* ����ֵ��void
*/
void boss_fly();


/*
* �����ˣ�
* ���ܣ�չʾboss
* ������void
* ����ֵ��void
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
	int flag; //��ʶ����״̬
	int id;
};

typedef struct em_Node {
	int x, y;
	int ID;  //�����±�
	int life;
	int flag;
	struct em_Node* pre, *next;
} *LinkList_em;

/*
* �����ˣ�4C
* ���ܣ����ɾ�Ӣ��
* ������
* ����ֵ��void
*/
void create_em();

/*
* �����ˣ�
* ���ܣ���Ӣ�ַ���
* ������
* ����ֵ��void
*/
void elite_monster_fly();
/*
* �����ˣ�
* ���ܣ���ײ��Ӣ��
* ������
* ����ֵ��void
*/
void crush_em();
/*
* �����ˣ�4C
* ���ܣ�ʹ��Ӧ�л���������
* �������л��ڵ�ָ��
* ����ֵ��void
*/
void dodge_1(em_Node* p);

/*
* �����ˣ��˷���
* ���ܣ��ж϶�Ӧ�ɻ��Ƿ�����
* ����������ڵ�ָ��
* ����ֵ��void
*/
int isDie(em_Node* p);

/*
* �����ˣ��˷���
* ���ܣ�
* ������
* ����ֵ��void
*/
void delete_em(em_Node* p);

/*
* �����ˣ�����
* ���ܣ�������������ͨ�л�/����
* �������л��ڵ�ָ��
* ����ֵ��void
*/
void death(em_Node* p);

/*
* �����ˣ�������
* ���ܣ���ӡ�л�
* ����������ͷָ��
* ����ֵ��void
*/
void show_em();

/*
* �����ˣ�
* ���ܣ���ʼ����Ӣ��
* ������
* ����ֵ��void
*/

void init_elite_monster();
