#include"game_help.h"


extern int flag;
extern ExMessage msg;
void game_help()
{
	// �����Ļ
	cleardevice();

	//���Ʊ���
	IMAGE img_bk;
	loadimage(&img_bk, "photo/game_help.jpg",1080,800);


	//���ñ���ģʽ
	setbkmode(TRANSPARENT);


	while (true) {
		putimage(0, 0, &img_bk);
		//��ȡ�����Ϣ
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		// ���������¼�
		settextstyle(60, 0, "������κ");
		outtextxy(950, 10, "�˳�");
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