#pragma once
#include<stdio.h>
#include<easyx.h>
#include"play_game.h"
#include"MENU.h"
#include"setting.h"
#include"game_help.h"
#include"staff.h"
#include"skill_menu.h"


#define MY_MENU 0
#define END_GAME 1
#define GAME_PLAY 2
#define GAME_HELP 3
#define STAFF 4
#define SETTING 5


/*
* �����ˣ�
* ���ܣ������û���ѡ��(��flag����ʾ�û�ѡ��)���벻ͬ���棨��ʼ/������Ϸ�����˵���������Ա��������
* ������int
* ����ֵ��void
*/
void controller();

