#define  _CRT_SECURE_NO_WARNINGS 1
#include"�ξ�����.h"
extern ExMessage msg;
IMAGE set_photo;
extern int flag;
int c;//���Ƹ����л�
//-----------------------�������-----------------------
//------------------------------view---------------------------
/*
	������:�հ�
	����:
	  1.��ӡ���ý���
	  2.�����û��������Ϣ�л������汳������
	  3.�����û��������Ϣ�������ִ�С�ĵ���
	  4.�û����������������󷵻���ҳ��
	����:void
	����ֵ: void
*/
void relevant_set()
{
	const char* musci[3] =
	{
		"����","�r����","���륫�ƥ���"
	};
	mciSendString("open music\\����.mp3", 0, 0, 0);
	mciSendString("open music\\�r����.mp3", 0, 0, 0);
	mciSendString("open music\\���륫�ƥ���.mp3 ", 0, 0, 0);
	const char* musciplay[3]
	{
		"play music\\����.mp3",
		"play music\\�r����.mp3",
		"play music\\���륫�ƥ���.mp3 "
	};
	const char* musciclose[3]
	{
		"close music\\����.mp3",
		"close music\\�r����.mp3",
		"close music\\���륫�ƥ���.mp3 "
	};
	const char* muscistatu[3]
	{
		"status music\\����.mp3 volume",
		"status music\\�r����.mp3 volume",
		"status music\\���륫�ƥ���.mp3 volume"
	};
	const char* musciset[3]
	{
		"setaudio music\\����.mp3 volume to %d",
		"setaudio music\\�r����.mp3 volume to %d",
		"setaudio music\\���륫�ƥ���.mp3 volume to %d"
	};
	char a[100];
	mciSendString(muscistatu[c], a, 100, 0);//��ȡ��ʱ���������ݷ��ص�a�������100�Ǳ�ʾa�ĳ��ȣ�sizeof��a��
	//����a���ַ�����������aת��Ϊ���֣����Ե���atoi����
	int b = atoi(a);//ͨ��atoi���������ַ����ִ�ת����int����
	char s[100];
	sprintf(s, musciset[c], b % 1000 + 200);//���ｨ��ȥȡģ����ʱ��õ���������200���ٳ���1000���ϴ�ʱý���������ǽ�Ҫ���ų���������
	mciSendString(s, 0, 0, 0);
	loadimage(&set_photo, "photos/���ý���.jpg", 1080, 960);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &set_photo);
		peekmessage(&msg, EX_MOUSE);
		button_nomsg(410, 400, "��������");
		button(700 - 60, 400, "��", "��");
		button(725 + textwidth(musci[c]), 400, "��", "��");
		button_nomsg(700, 400, musci[c]);
		button_nomsg(410, 530, "���ִ�С����");
		if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 700 - 60, 400, 40, 40)))
		{
			if (c >= 1)
			{
				mciSendString(musciclose[c], 0, 0, 0);
				c -= 1;
			}
			mciSendString(musciplay[c], 0, 0, 0);
		}
		else if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 725 + textwidth(musci[c]), 400, 40, 40)))
		{
			if (c <= 1)
			{
				mciSendString(musciclose[c], 0, 0, 0);
				c += 1;
			}

			mciSendString(musciplay[c], 0, 0, 0);
		};
		button(660, 480, "��", "��");
		button(660, 590, "��", "��");
		if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 660, 480, 40, 40)))
		{
			if (b <= 999)
				b += 100;
		}
		else if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 660, 590, 40, 40)))
		{
			if (b >= 99)
				b -= 100;
		};
		sprintf(a, musciset[c], b);
		mciSendString(a, NULL, 0, NULL);
		char arr[10];
		sprintf(arr, "%d", b / 10);
		button_nomsg(660, 530, arr);
		button(410, 665, "�ر�", "�ر�");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 410, 665, 70, 40))
		{
			flag = MY_MENU;
			break;
		}
		msg.message = 0;
		EndBatchDraw();
	}
}

//-------------------------view-----------------------
