#include"skill_menu.h"

extern ExMessage msg;
extern int flag;
const char* weapon_name[8] = { "��ȼ����","��ķ˹���ʻ�������ʽ��ķ˹������","�����ƶ�","���ʥ��", "w","q","e","r"};
const char* player_skill_name[8] = { "�ӵ�����","��ͨ����","Ѫ��","СС��Ҳ�ܿɰ�",};
const char* boss_skill_name[8] = { "�Ͻ�װ��","���ͷɻ�","��������","������ʯ",};
const char* tool_name[8] = { "�����","�߼�����װ��","���Ȱ�","�����ƶ�" ,};
const char** library[8] = { weapon_name,player_skill_name, boss_skill_name,tool_name };
int library_cur = 0;
int i, j;
void show_library()
{
	peekmessage(&msg, EX_MOUSE);
	cleardevice();
	setbkcolor(BLACK);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	while (1)
	{
		cleardevice();
		settextstyle(60, 0, "������κ");
		outtextxy(400, 50, "���� ���� ����");
		outtextxy(950, 10, "�˳�");
		settextstyle(30, 0, "������κ");
		peekmessage(&msg, EX_MOUSE);
		button(100, 550, "��Ҽ���", "��Ҽ���");
		rectangle(100, 550, 300, 630);
		outtextxy(120, 570, "��Ҽ���");

		rectangle(400, 550, 550, 630);
		outtextxy(420, 570, "����");

		rectangle(100, 700, 300, 770);
		outtextxy(120, 720, "boss����");

		rectangle(400, 700, 550, 770);
		outtextxy(420, 720, "����");

		outtextxy(120, 470, "��һҳ");
		outtextxy(420, 470, "��һҳ");
		if (inArea(msg.x, msg.y, 120, 570, 120 + textwidth("��Ҽ���"), 570 + textheight("��Ҽ���")))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 120, 570, 120 + textwidth("��Ҽ���"), 570 + textheight("��Ҽ���")))
			{
				printf("111");
				library_cur = 1;
				i = j = 0;
			}
		}
		else if (inArea(msg.x, msg.y, 420, 570, 420 + textwidth("����"), 570 + textheight("����")))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 420, 570, 420+ textwidth("����"), 570 + textheight("����")))
			{
				printf("222");
				library_cur = 0;
				i = j = 0;
			}

		}
		else if (inArea(msg.x, msg.y, 120, 700, 100 + textwidth("boss����"), 720 + textheight("boss����")))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 120, 700, 100 + textwidth("boss����"), 720 + textheight("boss����")))
			{
				printf("333");
				library_cur = 2;
				i = j = 0;
			}
		}
		else if (inArea(msg.x, msg.y, 420, 720, 420 + textwidth("����"), 720 + textheight("����")))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 420, 720, 420 + textwidth("����"), 720 + textheight("����")))
			{
				printf("444");
				library_cur = 3;
				i = j = 0;
			}
		}
		for (; i < 2;)
		{
			for (; j < 4; j++)
			{
				char arr[12] = { 0 };
				itoa(i*3+j+1,arr,10);
				outtextxy(100 , 150+(j + 1) * 60, arr);
				RECT text1 = { 100 + 40 , 150 + (j + 1) * 60 ,600, 150+((j + 1) * 60) + 60 };
				drawtext(library[library_cur][i * 3 + j], &text1, DT_WORDBREAK);
				FlushBatchDraw();
			}
			peekmessage(&msg, EX_MOUSE);
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 950, 0, 1080, 100))
			{
				flag = MY_MENU;
				return;
			}
			
			if (inArea(msg.x, msg.y, 120, 470, 120+textwidth("��һҳ"), 470+textheight("��һҳ")) && i >=1)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 120, 470, 120 + textwidth("��һҳ"), 470 + textheight("��һҳ")))
				{
					i--;
					Sleep(250);
				}
			}
			if (inArea(msg.x, msg.y, 420, 470, 420 + textwidth("��һҳ"), 470 + textheight("��һҳ")) && i <= 0)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 420, 470, 420 + textwidth("��һҳ"), 470 + textheight("��һҳ")))
				{
					i++;
					Sleep(250);
				}
			}
			msg.message = 0;
		}
	}
}