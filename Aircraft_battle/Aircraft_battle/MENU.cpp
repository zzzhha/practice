#include"Aircraft battle.h"

extern ExMessage msg;
IMAGE main_photo;
extern int flag ;


//-------------------------serive-----------------------------------



bool inArea(int mx, int my, int x, int y, int dx, int dy) {
	if (mx > x && mx<dx && my>y && my < dy) {
		return true;
	}
	return false;
}

void button(int x, int y,const char *white ,const char *dark) {
	peekmessage(&msg, EX_MOUSE);
	if(inArea(msg.x,msg.y,x,y,x+textwidth(white),y+textheight(white)))
	{
		settextcolor(RGB(0, 108, 190));
		outtextxy(x, y, dark);
	}
	else
	{
		settextcolor(BLACK);
		outtextxy(x, y, white);
	}
}

void button_nomsg(int x, int y, const char* text)
{
	settextcolor(BLACK);
	outtextxy(x, y, text);
}
//-------------------------serive-----------------------------------
// 
// 
//-------------------------view----------------------------------

void game_menu() {
	loadimage(&main_photo, "photo/main_photo.jpg", 1080, 960);
	while (1) {
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &main_photo);
		peekmessage(&msg, EX_MOUSE| EX_KEY);
		settextstyle(60, 0, "������κ");
		setbkmode(TRANSPARENT);
		button_nomsg(450, 100, "�ɻ���ս");
		settextstyle(40, 0, "������κ");
		button(900, 300, "��ʼ��Ϸ", "��ʼ��Ϸ");
		button(900, 400, "�������", "�������");
		button(900, 500, "��Ϸ����", "��Ϸ����");
		button(900, 600, "������Ա", "������Ա");
		button(900, 700, "�˳���Ϸ", "�˳���Ϸ");
		if (inArea(msg.x, msg.y, 900, 300, 1050, 370))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 300, 900+textwidth("��ʼ��Ϸ"), 300+textheight("��ʼ��Ϸ")))
			{
				flag = GAME_PLAY;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 400, 1050, 470))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 400, 900+textwidth("�������"), 400+textheight("�������")))
			{
				flag = SETTING;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 500, 1050, 570))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 500, 900+textwidth("��Ϸ����"), 500+textheight("��Ϸ����")))
			{
				flag = GAME_HELP;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 600, 1050, 670))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 600, 900+textwidth("������Ա"), 600+textheight("������Ա")))
			{
				flag = STAFF;
				break;
			}
		}
		else if (inArea(msg.x, msg.y, 900, 700, 1050, 770))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 900, 700, 900+textwidth("������Ա"), 700+textheight("������Ա")))
			{
				flag = END_GAME;
				break;
			}
		}
		msg.message = 0;
		EndBatchDraw();
	}
}
//----------------------------view--------------------------------

