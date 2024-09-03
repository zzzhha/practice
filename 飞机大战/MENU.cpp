#include<cstdio>
#include<easyx.h>
#include"MENU.h"


extern int flag;
using namespace std;
ExMessage msg;

bool inArea(int mx, int my, int x, int y, int dx, int dy) {
	if (mx > x && mx<dx && my>y && my < dy) {
		return true;
	}
	return false;
}

void button(int x, int y, const char* white, const char* dark){
	if (inArea(msg.x, msg.y, x, y, x + textwidth(white), y + textheight(white)))
	{
		settextcolor(RGB(0, 108, 190));
		outtextxy(x, y, dark);
	}
	else
	{
		settextcolor(WHITE);
		outtextxy(x, y, white);
	}
}

void button_nomsg(int x, int y, const char* text){
	settextcolor(WHITE);
	outtextxy(x, y, text);
}

void game_menu(){
	IMAGE main_photo;
	loadimage(&main_photo, "photo/menu_photo.jpg", 1080,800);

	while (1) {
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &main_photo);
		peekmessage(&msg, EX_MOUSE | EX_KEY);
		settextstyle(60, 0, "华文新魏");
		setbkmode(TRANSPARENT);
		button_nomsg(400, 100, "丁真大作战");
		settextstyle(40, 0, "华文新魏");
		button(900, 300, "开始游戏", "开始游戏");
		button(900, 400, "相关设置", "相关设置");
		button(900, 500, "游戏帮助", "游戏帮助");
		button(900, 600, "开发人员", "开发人员");
		button(900, 700, "退出游戏", "退出游戏");
		if (inArea(msg.x, msg.y, 900, 300, 1050, 370))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 300, 900 + textwidth("开始游戏"), 300 + textheight("开始游戏")))
			{
				flag = GAME_PLAY;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 400, 1050, 470))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 400, 900 + textwidth("相关设置"), 400 + textheight("相关设置")))
			{
				flag = SETTING;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 500, 1050, 570))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 500, 900 + textwidth("游戏帮助"), 500 + textheight("游戏帮助")))
			{
				flag = GAME_HELP;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 600, 1050, 670))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 600, 900 + textwidth("开发人员"), 600 + textheight("开发人员")))
			{
				flag = STAFF;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 700, 1050, 770))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 700, 900 + textwidth("退出游戏"), 700 + textheight("退出游戏")))
			{
				flag = END_GAME;
				break;
			}
		}
		EndBatchDraw();
		msg.message = { 0 };
	}
}