#pragma once
#include"play_game.h"

struct tool_plane {
	int life;//ֱ�ӻָ�������Ѫ
	int max_life;//�����������ֵ�������ӵ���Ѫ��ֵ
	int percent_life;//������ֵ�ָ��������ֵ�İٷֱ�Ѫ��
	int power;//ֱ�����ӵ����Ĺ�����
	int precent_power;//���ݷɻ����й�����������ֵ���Ӱٷֱȹ���
	int x;
	int y;//�ı�x��y������
	int width;
	int height;//�ı�ɻ���С
	int buff_speed;//�ṩ���ɻ����ٶȴ�С
	int self_speed;//������ߵ����ٶ�
	int bullet_num;  //�����ӵ�����
	int ID_tool;//ÿ�����ߵ����е�����ֵ���������ֵ��ߣ����㿪ʼ��ÿ��һ����1
};


typedef struct weapon_Node {
	int x, y;
	int width, height;
	int tool_temp;
	struct weapon_Node* next, * pre;
}*LinkList_w;



void weapon_init();

void tool_init();