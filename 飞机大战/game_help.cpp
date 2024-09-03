#include"game_help.h"


extern int flag;
extern ExMessage msg;
void game_help()
{
	// 清除屏幕
	cleardevice();

	//绘制背景
	IMAGE img_bk;
	loadimage(&img_bk, "photo/game_help.jpg",1080,800);


	//设置背景模式
	setbkmode(TRANSPARENT);


	while (true) {
		putimage(0, 0, &img_bk);
		//获取鼠标消息
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		// 检测鼠标点击事件
		settextstyle(60, 0, "华文新魏");
		outtextxy(950, 10, "退出");
		if (inArea(msg.x, msg.y, 900, 0, 1080, 200))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 0, 1080, 200))
			{
				flag = MY_MENU;
				break;
			}
		}
		EndBatchDraw();
	}


}