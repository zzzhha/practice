#define  _CRT_SECURE_NO_WARNINGS 1
#include"�ξ�����.h"
extern ExMessage msg;
IMAGE main_photo;
extern int flag;
//----------------------------view--------------------------
void gamemenu()
{
	loadimage(&main_photo, "photos/hui.jpg", 1080, 960);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &main_photo);
		peekmessage(&msg, EX_MOUSE);
		settextstyle(60, 0, "΢���ź�");
		setbkmode(TRANSPARENT);
		button_nomsg(450, 100,  "�����ξ�");
		settextstyle(40, 0, "΢���ź�");
		button(50, 300,  "���θ���", "��ʼ��Ϸ");
		button(50, 500,  "����һ��", "�������");
		button(50, 700, "��������", "�ɾ�ϵͳ");
		button(900, 300,  "�����α�", "��Ϸ����");
		button(900, 500,  "������Ա", "������Ա");
		button(900, 700, "�λ���Ӱ", "�˳���Ϸ");//������������չʾ
		
		if (inArea(msg.x, msg.y, 50, 300, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 50, 300, textwidth("���θ���"), textheight("���θ���")))
			{
				//mciSendString("close music\\����.mp3",NULL,0,NULL);
				flag = MY_GAME;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 50, 500, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 50, 500, textwidth("����һ��"), textheight("����һ��")))
			{
				//mciSendString("close music\\����.mp3", NULL, 0, NULL);
				flag = MY_SETTING;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 50, 700, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 50, 700, textwidth("��������"), textheight("��������")))
			{
				//mciSendString("close music\\����.mp3", NULL, 0, NULL);
				flag = MY_ACHIEVE;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 300, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 300, textwidth("�����α�"), textheight("�����α�")))
			{
				//mciSendString("close music\\����.mp3", NULL, 0, NULL);
				flag = MY_HELP;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 500, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 500, textwidth("������Ա"), textheight("������Ա")))
			{
				//mciSendString("close music\\����.mp3", NULL, 0, NULL);
				flag = MY_SATFF;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 800, 150, 70))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 800, textwidth("�λ���Ӱ"), textheight("�λ���Ӱ")))
			{
				exit(0);
			}
		}
		msg.message = 0;
		EndBatchDraw();
	}

}
//----------------------------view--------------------------
void button(int x, int y, const char* ming, const char* an)
{
	peekmessage(&msg, EX_MOUSE);
	if (inArea(msg.x, msg.y, x, y, textwidth(an), textheight(an)))
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
void button_nomsg(int x, int y, const char* text)
{
	settextcolor(RGB(157, 0, 176));
	outtextxy(x, y, text);
}

bool inArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx<x + w && my>y && my < y + h)
		return true;
	else
		return false;
}