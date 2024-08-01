#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<Windows.h>
#include<mmsystem.h>
#include<conio.h> 
#include<stdlib.h>
#include<climits>
#pragma comment(lib,"winmm.lib")
#define MY_MENU 0
#define MY_SETTING 1
#define MY_GAME 2
#define MY_STAFF 3
#define MY_ACHIEVE 4
#define MY_HELP 5
#define MY_OVER -1


ExMessage main_msg;
IMAGE main_photo;
int flag = MY_MENU;
//void volume()
//{
//	int i = 0;
//	char a[100];
//	while (true)
//	{
//		char s = getch();
//		system("cls");
//		if (s == 'w')
//		{
//			i += 10;
//		}
//		else if (s == 's')
//		{
//			i -= 10;
//		}
//		printf("%d", i);
//		sprintf(a, "setaudio music volume to %d", i);
//		mciSendString(a, NULL, 0, NULL);
//	}
//}
bool inArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx<x + w && my>y && my < y + h)
		return true;
	else
		return false;
}
void button(int x, int y, int w, int h, const char* ming, const char* an)
{
	peekmessage(&main_msg, EX_MOUSE);
	if (inArea(main_msg.x, main_msg.y, x, y, textwidth(an), textheight(an)))
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
void button_nomsg(int x, int y, int w, int h, const char* text)
{
	settextcolor(RGB(157, 0, 176));
	outtextxy(x, y, text);
}

void int_to_string(int number, char* str)//将字符串里的数字字符转换成int类型数字
{
	int index = 0;
	// 逆序构建字符串（从最低位开始）  
	do {
		str[index++] = '0' + (number % 10);
		number /= 10;
	} while (number > 0);
	// 添加字符串结束符  
	str[index] = '\0';
	// 反转字符串以得到正确的顺序  
	for (int i = 0; i < index / 2; i++) {
		char temp = str[i];
		str[i] = str[index - i - 1];
		str[index - i - 1] = temp;
	}
}
void Gear_set()
{
	char a[100];
	//mciSendString("status music volume", a, 100, 0);//获取此时的音量数据返回到a，这里的100是表示a的长度，sizeof（a）
	//其中a是字符串，如果想把a转换为数字，可以调用atoi函数
	int b = atoi(a);//通过atoi函数进行字符数字串转换到int类型
	char s[100];
	sprintf(s, "setaudio music volume to %d", b % 1000 + 200);//这里建议去取模，此时获得的音量加上200，再除以1000乘上此时媒体音量就是将要播放出来的音量
	mciSendString(s, 0, 0, 0);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		fillrectangle(350, 200, 750, 780);
		button(430, 330, 500, 400, "返回主界面", "返回主界面");
		if(main_msg.message == WM_LBUTTONDOWN && inArea(main_msg.x, main_msg.y, 430, 330, 70, 70))
		{
			break;
		}
		button_nomsg(410, 530, 600, 600, "音乐大小调节");
		outtextxy(660, 480, "↑");
		outtextxy(660, 590, "↓");
		if ((main_msg.message == WM_LBUTTONDOWN && inArea(main_msg.x, main_msg.y, 660, 480,40, 40)))
		{
			if(b<=900)
			b += 100;
		}
		else if ((main_msg.message == WM_LBUTTONDOWN && inArea(main_msg.x, main_msg.y, 660, 590, 40, 40)))
		{
			if(b>=100)
			b -= 100;
		};
		sprintf(a, "setaudio music volume to %d", b);
		//mciSendString(a, NULL, 0, NULL);
		char arr[10];
		sprintf(arr, "%d", b/10);
		button_nomsg(660, 530, 680, 600, arr);
		button(500, 730, 570, 770, "关闭", "关闭");
		if (main_msg.message == WM_LBUTTONDOWN && inArea(main_msg.x, main_msg.y, 500, 730, 70, 40))
		{
			exit(0);
		}
		main_msg.message = 0;
		EndBatchDraw();
	}
}
int main()
{
	initgraph(1080, 960);
	mciSendString("open music\\M500002Zzstc2j8y6Q.mp3 alias music", NULL, 0, NULL);
//	mciSendString("play music", NULL, 0, NULL);
	while (1)
	{
		
		BeginBatchDraw();
		cleardevice();
		setbkcolor(BLUE);
		
		settextstyle(40, 0, "楷体");
		peekmessage(&main_msg);
		outtextxy(460, 680, "随意点击返回到主页面");
		if (main_msg.message == WM_LBUTTONDOWN)
		{
			Gear_set();
		}
		main_msg.message = 0;
		EndBatchDraw();
	}
	Gear_set();
}


