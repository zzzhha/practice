#define  _CRT_SECURE_NO_WARNINGS 1
#include"梦境逃离.h"
extern ExMessage msg;
IMAGE main_photo;
extern int flag;
//-----------------------数据设计-----------------------
//------------------------view---------------------
/*
    负责人:
    功能:
     1. 打印主界面
     2.根据接受鼠标左键信息跳转至相应的界面
     参数:void
    返回值: void
*/
void gamemenu()
{
	loadimage(&main_photo, "photos/hui.jpg", 1080, 960);
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &main_photo);
		peekmessage(&msg, EX_MOUSE);
		settextstyle(60, 0, "微软雅黑");
		setbkmode(TRANSPARENT);
		button_nomsg(450, 100, "恍如梦境");
		settextstyle(40, 0, "微软雅黑");
		button(50, 300, "若梦浮生", "开始游戏");
		button(50, 500, "黄粱一梦", "相关设置");
		button(50, 700, "恍如梦寐", "成就系统");
		button(900, 300, "江淹梦笔", "游戏帮助");
		button(900, 500, "开发人员", "开发人员");
		button(900, 700, "梦幻泡影", "退出游戏");//以上是主界面展示

		if (inArea(msg.x, msg.y, 50, 300, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 50, 300, textwidth("若梦浮生"), textheight("若梦浮生")))
			{
				//mciSendString("close music\\潮鸣.mp3",NULL,0,NULL);
				flag = MY_GAME;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 50, 500, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 50, 500, textwidth("黄粱一梦"), textheight("黄粱一梦")))
			{
				//mciSendString("close music\\潮鸣.mp3", NULL, 0, NULL);
				flag = MY_SETTING;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 50, 700, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 50, 700, textwidth("恍如梦寐"), textheight("恍如梦寐")))
			{
				//mciSendString("close music\\潮鸣.mp3", NULL, 0, NULL);
				flag = MY_ACHIEVE;
				return;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 300, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 300, textwidth("江淹梦笔"), textheight("江淹梦笔")))
			{
				//mciSendString("close music\\潮鸣.mp3", NULL, 0, NULL);
				flag = MY_HELP;
				return;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 500, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 500, textwidth("开发人员"), textheight("开发人员")))
			{
				//mciSendString("close music\\潮鸣.mp3", NULL, 0, NULL);
				flag = MY_SATFF;
				return;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 700, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 700, textwidth("梦幻泡影"), textheight("梦幻泡影")))
			{
				printf("111");
				exit(0);
			}
		}
		EndBatchDraw();
		msg.message ;
	}
}

//------------------------view---------------------
//-------------------------service----------------------

/*
    负责人:
    功能:
        1.展示文字
        2.当鼠标移到文字处时显示高光
         参数:int mx, int my, int x, int y, int w, int h
         mx,my是鼠标位置，x,y区域是左上角，w为宽度，h为高度
    返回值: bool
*/
bool inArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx<x + w && my>y && my < y + h)
		return true;
	else
		return false;
    return 0;
}

/*
    负责人:
    功能:
        1.展示文字
        2.当鼠标移到文字处时显示高光
         参数:int x， int y, const char* ming, const char* an
         x,y是文字起始点位置,ming是鼠标未指到x,y时展示的文字，an是鼠标指到x,y时展示的文字
    返回值: void
*/
void button(int x, int y, const char* ming, const char* an)
{
	if (inArea(msg.x, msg.y, x, y, textwidth(an), textheight(an)))
	{
		settextcolor(RGB(229, 171, 166));
		outtextxy(x, y, an);
	}
	else
	{
		settextcolor(RGB(157, 0, 176));
		outtextxy(x, y, ming);
	}
}

/*
    负责人:
    功能:
        展示文字
     参数:int x， int y, const char* text, 
     x,y是文字起始点位置,text是所需打印的文字，
    返回值: void
*/
void button_nomsg(int x, int y, const char* text)
{
	settextcolor(RGB(157, 0, 176));
	outtextxy(x, y, text);
}