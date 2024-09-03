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
* 负责人：
* 功能：根据用户的选择(用flag来表示用户选择)进入不同界面（开始/结束游戏、主菜单、开发人员、帮助）
* 参数：int
* 返回值：void
*/
void controller();

