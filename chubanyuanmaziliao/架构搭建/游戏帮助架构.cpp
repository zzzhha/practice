#define  _CRT_SECURE_NO_WARNINGS 1
#include"梦境逃离.h"
extern ExMessage msg;
IMAGE help_photo;
extern int flag;
//-----------------------数据设计-----------------------
//-------------------------view-----------------------
/*
    负责人:夏尔
    功能:
      1.展示游戏帮助
      2.返回主页面
    参数:void
    返回值: void
*/
bool inArea_xiaer(int mx, int my, int x, int y, int w, int h) {
	return mx > x && mx < x + w && my > y && my < y + h;
}
bool button_xiaer(int x, int y, int w, int h) {
	if (inArea(msg.x, msg.y, x, y, w, h))
		settextcolor(RGB(43, 39, 85));
	else
		settextcolor(WHITE);

	// 绘制返回按钮
	settextstyle(60, 0, "华文琥珀");
	outtextxy(x, y, "退出");

	// 判断按钮是否被点击
	return msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h);
}

void gamehelp()
{
	// 清除屏幕
	cleardevice();

	//绘制背景
	IMAGE img_bk;
	loadimage(&img_bk, "photos/torii.png");
	//设置背景模式
	setbkmode(TRANSPARENT);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &img_bk);
		peekmessage(&msg, EX_MOUSE);
		settextstyle(60, 0, "华文琥珀");
		settextcolor(WHITE);
		outtextxy(950, 10, "退出");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 1000, 0, 80, 100))
		{
			flag = MY_MENU;
			break;
		}
		EndBatchDraw();
		msg.message = 0;
	}
}
//-------------------------view-----------------------