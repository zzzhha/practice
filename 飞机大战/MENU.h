#pragma once
#include"controller.h"


/*
* �����ˣ�
* ���ܣ��˵���������
* ������void
* ����ֵ��void
*/
void game_menu();

/*
* �����ˣ�
* ���ܣ��ж�����Ƿ��ڰ�����
* �������������mx��my;����������������x,y,dx,dy
* ����ֵ��bool
*/
bool inArea(int mx, int my, int x, int y, int dx, int dy);

/*
* �����ˣ�
* ���ܣ����ư�ť,����ƶ���ָ��λ�õ�ʱ��ᷢ����ɫ�ı�
* ��������ť���꣬��ɫ
* ����ֵ��void
*/
void button(int x, int y, const char* white, const char* dark);

/*
* �����ˣ�
* ���ܣ�д���⣬ͬ�ϣ����ǲ��ᷢ����ɫ�仯
* ����������x��y������
* ����ֵ��void
*/
void button_nomsg(int x, int y, const char* text);
