#pragma once
#include<stdio.h>
#include<stdlib.h>
int map[19][19];//玩家下棋的地方
void menuView();//根据map数组 打印游戏棋盘
void gameView();
void init();//初始化棋盘
void gameView_ShowMap();//展示棋盘
int playerMove(int x, int y);//玩家移动
int isWin(int x, int y);
void winView();
