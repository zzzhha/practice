#include"setting.h"
extern int flag;
extern ExMessage msg;
int c;//控制歌曲切换
IMAGE set_photo;
const char* musci[] =
{
	"敢杀我的马","国玉的战争","igotsmoke"
};

const char* musciplay[3]
{
	"play music\\敢杀我的马.mp3 repeat",
	"play music\\国玉的战争.mp3 repeat",
	"play music\\igotsmoke.mp3 repeat"
};
const char* musciclose[3]
{
	"close music\\敢杀我的马.mp3",
	"close music\\国玉的战争.mp3",
	"close music\\igotsmoke.mp3 "
};
const char* muscistatu[3]
{
	"status music\\敢杀我的马.mp3 volume",
	"status music\\国玉的战争.mp3 volume",
	"status music\\igotsmoke.mp3 volume"
};
const char* musciset[3]
{
	"setaudio music\\敢杀我的马.mp3 volume to %d",
	"setaudio music\\国玉的战争.mp3 volume to %d",
	"setaudio music\\igotsmoke.mp3 volume to %d"
};
void relevant_set(){
	mciSendString("open music\\敢杀我的马.mp3", 0, 0, 0);
	mciSendString("open music\\国玉的战争.mp3", 0, 0, 0);
	mciSendString("open music\\igotsmoke.mp3 ", 0, 0, 0);
	char a[100];
	mciSendString(muscistatu[c], a, 100, 0);//获取此时的音量数据返回到a，这里的100是表示a的长度，sizeof（a）
	//其中a是字符串，如果想把a转换为数字，可以调用atoi函数
	int b = atoi(a);//通过atoi函数进行字符数字串转换到int类型
	char s[100];
	sprintf(s, musciset[c], b % 1000 + 200);//这里建议去取模，此时获得的音量加上200，再除以1000乘上此时媒体音量就是将要播放出来的音量
	mciSendString(s, 0, 0, 0);
	loadimage(&set_photo, "photo/setting_photo.jpg", 1080, 800);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &set_photo);
		peekmessage(&msg, EX_MOUSE);
		button_nomsg(410, 300, "更换音乐");
		button(700 - 60, 300, "←", "←");
		button(725 + textwidth(musci[c]), 300, "→", "→");
		button_nomsg(700, 300, musci[c]);
		button_nomsg(410, 430, "音乐大小调节");
		if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 700 - 60, 300, 740, 340)))
		{
			if (c >= 1)
			{
				mciSendString(musciclose[c], 0, 0, 0);
				c -= 1;
			}
			mciSendString(musciplay[c], 0, 0, 0);
		}
		else if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 725 + textwidth(musci[c]), 300, 725 + textwidth(musci[c])+40, 340)))
		{
			if (c <= 1)
			{
				mciSendString(musciclose[c], 0, 0, 0);
				c += 1;
			}

			mciSendString(musciplay[c], 0, 0, 0);
		};
		button(670, 380, "↑", "↑");
		button(670, 490, "↓", "↓");
		if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 670, 380, 710, 420)))
		{
			if (b <= 999)
				b += 100;
		}
		else if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 670, 490, 710, 530)))
		{
			if (b >= 99)
				b -= 100;
		};
		sprintf(a, musciset[c], b);
		mciSendString(a, NULL, 0, NULL);
		char arr[10];
		sprintf(arr, "%d", b / 10);
		button_nomsg(660, 430, arr);
		button(410, 565, "关闭", "关闭");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 410, 565, 480, 605))
		{
			flag = MY_MENU;
			break;
		}
		msg.message = 0;
		EndBatchDraw();
	}
}