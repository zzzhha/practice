#define  _CRT_SECURE_NO_WARNINGS 1
#include"�ξ�����.h"
ExMessage msg;
int flag = MY_MENU;
//-----------------------�������-----------------------
//-----------------------service------------------------------------
int main()
{
	initgraph(1080, 960);//����һ��ͼ��
	mciSendString("open music\\����.mp3 ", NULL, 0, NULL);
	mciSendString("play music\\����.mp3 repeat", NULL, 0, NULL);
	peekmessage(&msg, EX_MOUSE);
	controller();//����������
	return 0;
}
void controller()
{
	while (1)
	{
		switch (flag)
		{
		case MY_MENU:
			gamemenu();
			break;
		case MY_GAME:
			startgame();
			break;
		case MY_SETTING:
			relevant_set();
			break;
		case MY_ACHIEVE:
			achieve();
			break;
		case MY_HELP:
			gamehelp();
			break;
		case MY_SATFF:
			kaifastaff();
			break;
		case Win_VIEW:
			Win_View();
			break;
		case DEFEAT_VIEW:
			Defeat_View();
			break;
		case MY_OVER:
			exit(0);
		}
	}
	
}
