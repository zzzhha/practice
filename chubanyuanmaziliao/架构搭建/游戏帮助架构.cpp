#define  _CRT_SECURE_NO_WARNINGS 1
#include"�ξ�����.h"
extern ExMessage msg;
IMAGE help_photo;
extern int flag;
//-----------------------�������-----------------------
//-------------------------view-----------------------
/*
    ������:�Ķ�
    ����:
      1.չʾ��Ϸ����
      2.������ҳ��
    ����:void
    ����ֵ: void
*/
bool inArea_xiaer(int mx, int my, int x, int y, int w, int h) {
	return mx > x && mx < x + w && my > y && my < y + h;
}
bool button_xiaer(int x, int y, int w, int h) {
	if (inArea(msg.x, msg.y, x, y, w, h))
		settextcolor(RGB(43, 39, 85));
	else
		settextcolor(WHITE);

	// ���Ʒ��ذ�ť
	settextstyle(60, 0, "��������");
	outtextxy(x, y, "�˳�");

	// �жϰ�ť�Ƿ񱻵��
	return msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h);
}

void gamehelp()
{
	// �����Ļ
	cleardevice();

	//���Ʊ���
	IMAGE img_bk;
	loadimage(&img_bk, "photos/torii.png");
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &img_bk);
		peekmessage(&msg, EX_MOUSE);
		settextstyle(60, 0, "��������");
		settextcolor(WHITE);
		outtextxy(950, 10, "�˳�");
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