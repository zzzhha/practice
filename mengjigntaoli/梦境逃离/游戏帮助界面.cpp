#define  _CRT_SECURE_NO_WARNINGS 1
#include"�ξ�����.h"
extern ExMessage msg;
IMAGE help_photo;
extern int flag;
//--------------------------------view-----------------------------
/*
	������:�Ķ�
	����:
	  1.չʾ��Ϸ����
	  2.������ҳ��
	����:void
	����ֵ: void
*/

//ʹ��ǰ�Ƚ���Ԥ��˵���->��Ŀ->����->�߼�->�ַ���->��UNICODE��Ϊ���ֽ��ַ���


// �ж�mx, my�Ƿ���ָ���ľ���������
bool inArea_xiaer(int mx, int my, int x, int y, int w, int h) {
	return mx > x && mx < x + w && my > y && my < y + h;
}

// ���Ʋ���ⰴť���
bool button_xiaer(int x, int y, int w, int h) {
	if (inArea(msg.x, msg.y, x, y, w, h))
		settextcolor(RGB(43, 39, 85));
	else
		settextcolor(WHITE);

	// ���Ʒ��ذ�ť
	settextstyle(60, 0, "��������");
	outtextxy(x, y, "�˳�");

	// �жϰ�ť�Ƿ񱻵��
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h))
		return true;
	else
		return false;
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


	while (true) {
		putimage(0, 0, &img_bk);
		//��ȡ�����Ϣ
		peekmessage(&msg, EX_MOUSE);

		// ���������¼�
		settextstyle(60, 0, "��������");
		outtextxy(950, 10, "�˳�");
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