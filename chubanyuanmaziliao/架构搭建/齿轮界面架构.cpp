#define  _CRT_SECURE_NO_WARNINGS 1
#include"梦境逃离.h"
extern ExMessage msg;
extern int flag;
extern int c;
//-----------------------数据设计-----------------------
//---------------------view--------------------
/*
	负责人:空白
	功能:
	  1.返回主界面
	  2.调整音量
	  3.关闭此界面
	参数:void
	返回值: void
*/
void Gear_set()
{
	const char* musci[3] =
	{
		"潮鸣","時編み","アルカテイル"
	};
	mciSendString("open music\\潮鸣.mp3", 0, 0, 0);
	mciSendString("open music\\時編み.mp3", 0, 0, 0);
	mciSendString("open music\\アルカテイル.mp3 ", 0, 0, 0);
	const char* musciplay[3]
	{
		"play music\\潮鸣.mp3",
		"play music\\時編み.mp3",
		"play music\\アルカテイル.mp3 "
	};
	const char* musciclose[3]
	{
		"close music\\潮鸣.mp3",
		"close music\\時編み.mp3",
		"close music\\アルカテイル.mp3 "
	};
	const char* muscistatu[3]
	{
		"status music\\潮鸣.mp3 volume",
		"status music\\時編み.mp3 volume",
		"status music\\アルカテイル.mp3 volume"
	};
	const char* musciset[3]
	{
		"setaudio music\\潮鸣.mp3 volume to %d",
		"setaudio music\\時編み.mp3 volume to %d",
		"setaudio music\\アルカテイル.mp3 volume to %d"
	};
	char a[100];
	mciSendString(muscistatu[c], a, 100, 0);//获取此时的音量数据返回到a，这里的100是表示a的长度，sizeof（a）
	//其中a是字符串，如果想把a转换为数字，可以调用atoi函数
	int b = atoi(a);//通过atoi函数进行字符数字串转换到int类型
	char s[100];
	sprintf(s, musciset[c], b % 1000 + 200);//这里建议去取模，此时获得的音量加上200，再除以1000乘上此时媒体音量就是将要播放出来的音量
	mciSendString(s, 0, 0, 0);
	while (1)
	{
		BeginBatchDraw();
		setlinecolor(BLACK);
		setfillcolor(RGB(211, 211, 211));
		fillrectangle(350, 200, 750, 780);
		settextstyle(40, 0, "微软雅黑");
		button(430, 330, "返回主界面", "返回主界面");
		peekmessage(&msg, EX_MOUSE);
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 430, 330, 150, 60))
		{	
			flag = MY_MENU;
			controller();
			break;
		}
		button_nomsg(410, 530, "音乐大小调节");
		outtextxy(660, 480, "↑");
		outtextxy(660, 590, "↓");
		if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 660, 480, 40, 40)))
		{
			if (b <= 999)
				b += 100;
		}
		else if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 660, 590, 40, 40)))
		{
			if (b >= 99)
				b -= 100;
		};
		sprintf(a, musciset[c], b);
		mciSendString(a, NULL, 0, NULL);
		char arr[10];
		sprintf(arr, "%d", b / 10);
		button_nomsg(660, 530, arr);
		button(500, 730, "关闭", "关闭");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 500, 730, 70, 40))
		{
			settextcolor(RGB(157, 0, 176));
			clearrectangle(350, 200, 750, 780);
			//flag = MY_GAME;
			break;
		}

		msg.message = 0;
		EndBatchDraw();

	}
}

//--------------------------view------------------------