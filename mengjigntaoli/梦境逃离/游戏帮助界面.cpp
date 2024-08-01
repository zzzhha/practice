#define  _CRT_SECURE_NO_WARNINGS 1
#include"梦境逃离.h"
extern ExMessage msg;
IMAGE help_photo;
extern int flag;
//--------------------------------view-----------------------------
/*
	负责人:夏尔
	功能:
	  1.展示游戏帮助
	  2.返回主页面
	参数:void
	返回值: void
*/

//使用前先进行预设菜单栏->项目->属性->高级->字符集->把UNICODE改为多字节字符集


// 判断mx, my是否在指定的矩形区域内
bool inArea_xiaer(int mx, int my, int x, int y, int w, int h) {
	return mx > x && mx < x + w && my > y && my < y + h;
}

// 绘制并检测按钮点击
bool button_xiaer(int x, int y, int w, int h) {
	if (inArea(msg.x, msg.y, x, y, w, h))
		settextcolor(RGB(43, 39, 85));
	else
		settextcolor(WHITE);

	// 绘制返回按钮
	settextstyle(60, 0, "华文琥珀");
	outtextxy(x, y, "退出");

	// 判断按钮是否被点击
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h))
		return true;
	else
		return false;
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


	while (true) {
		putimage(0, 0, &img_bk);
		//获取鼠标消息
		peekmessage(&msg, EX_MOUSE);

		// 检测鼠标点击事件
		settextstyle(60, 0, "华文琥珀");
		outtextxy(950, 10, "退出");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 1000, 0, 80, 100))
		{
			flag = MY_MENU;
			break;
		}
		FlushBatchDraw();

		Sleep(120);
	}

	
}
//-------------------------------view----------------------------------