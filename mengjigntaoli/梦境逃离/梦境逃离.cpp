#define  _CRT_SECURE_NO_WARNINGS 1
#include"√Œæ≥Ã”¿Î.h"
ExMessage msg;
int flag = MY_MENU;//∆Ï÷ƒ
//--------------------service------------------------------
int main()
{
	mciSendString("open music\\≥±√˘.mp3 ", NULL, 0, NULL);
	mciSendString("play music\\≥±√˘.mp3 repeat", NULL, 0, NULL);
	initgraph(1080, 960);
	controller();//øÿ÷∆Ã®
	return 0;
}

//--------------------service------------------------------
void controller()
{
	cleardevice();
	flag = MY_MENU;
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
		case MY_OVER:
			exit(0);
			break;
		}
	}
}



