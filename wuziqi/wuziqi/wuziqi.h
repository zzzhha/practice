#pragma once
#include<stdio.h>
#include<stdlib.h>
int map[19][19];//�������ĵط�
void menuView();//����map���� ��ӡ��Ϸ����
void gameView();
void init();//��ʼ������
void gameView_ShowMap();//չʾ����
int playerMove(int x, int y);//����ƶ�
int isWin(int x, int y);
void winView();
