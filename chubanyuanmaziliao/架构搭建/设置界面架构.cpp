#define  _CRT_SECURE_NO_WARNINGS 1
#include"梦境逃离.h"
extern ExMessage msg;
IMAGE set_photo;
extern int flag;
int c;//控制歌曲切换
//-----------------------数据设计-----------------------
//------------------------------view---------------------------
/*
	负责人:空白
	功能:
	  1.打印设置界面
	  2.根据用户鼠标点击信息切换主界面背景音乐
	  3.根据用户鼠标点击信息进行音乐大小的调整
	  4.用户鼠标点击相关相关区域后返回主页面
	参数:void
	返回值: void
*/
void relevant_set()
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
	loadimage(&set_photo, "photos/设置界面.jpg", 1080, 960);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &set_photo);
		peekmessage(&msg, EX_MOUSE);
		button_nomsg(410, 400, "更换音乐");
		button(700 - 60, 400, "←", "←");
		button(725 + textwidth(musci[c]), 400, "→", "→");
		button_nomsg(700, 400, musci[c]);
		button_nomsg(410, 530, "音乐大小调节");
		if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 700 - 60, 400, 40, 40)))
		{
			if (c >= 1)
			{
				mciSendString(musciclose[c], 0, 0, 0);
				c -= 1;
			}
			mciSendString(musciplay[c], 0, 0, 0);
		}
		else if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 725 + textwidth(musci[c]), 400, 40, 40)))
		{
			if (c <= 1)
			{
				mciSendString(musciclose[c], 0, 0, 0);
				c += 1;
			}

			mciSendString(musciplay[c], 0, 0, 0);
		};
		button(660, 480, "↑", "↑");
		button(660, 590, "↓", "↓");
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
		button(410, 665, "关闭", "关闭");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 410, 665, 70, 40))
		{
			flag = MY_MENU;
			break;
		}
		msg.message = 0;
		EndBatchDraw();
	}
}

//-------------------------view-----------------------
