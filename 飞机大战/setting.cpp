#include"setting.h"
extern int flag;
extern ExMessage msg;
int c;//���Ƹ����л�
IMAGE set_photo;
const char* musci[] =
{
	"��ɱ�ҵ���","�����ս��","igotsmoke"
};

const char* musciplay[3]
{
	"play music\\��ɱ�ҵ���.mp3 repeat",
	"play music\\�����ս��.mp3 repeat",
	"play music\\igotsmoke.mp3 repeat"
};
const char* musciclose[3]
{
	"close music\\��ɱ�ҵ���.mp3",
	"close music\\�����ս��.mp3",
	"close music\\igotsmoke.mp3 "
};
const char* muscistatu[3]
{
	"status music\\��ɱ�ҵ���.mp3 volume",
	"status music\\�����ս��.mp3 volume",
	"status music\\igotsmoke.mp3 volume"
};
const char* musciset[3]
{
	"setaudio music\\��ɱ�ҵ���.mp3 volume to %d",
	"setaudio music\\�����ս��.mp3 volume to %d",
	"setaudio music\\igotsmoke.mp3 volume to %d"
};
void relevant_set(){
	mciSendString("open music\\��ɱ�ҵ���.mp3", 0, 0, 0);
	mciSendString("open music\\�����ս��.mp3", 0, 0, 0);
	mciSendString("open music\\igotsmoke.mp3 ", 0, 0, 0);
	char a[100];
	mciSendString(muscistatu[c], a, 100, 0);//��ȡ��ʱ���������ݷ��ص�a�������100�Ǳ�ʾa�ĳ��ȣ�sizeof��a��
	//����a���ַ�����������aת��Ϊ���֣����Ե���atoi����
	int b = atoi(a);//ͨ��atoi���������ַ����ִ�ת����int����
	char s[100];
	sprintf(s, musciset[c], b % 1000 + 200);//���ｨ��ȥȡģ����ʱ��õ���������200���ٳ���1000���ϴ�ʱý���������ǽ�Ҫ���ų���������
	mciSendString(s, 0, 0, 0);
	loadimage(&set_photo, "photo/setting_photo.jpg", 1080, 800);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &set_photo);
		peekmessage(&msg, EX_MOUSE);
		button_nomsg(410, 300, "��������");
		button(700 - 60, 300, "��", "��");
		button(725 + textwidth(musci[c]), 300, "��", "��");
		button_nomsg(700, 300, musci[c]);
		button_nomsg(410, 430, "���ִ�С����");
		if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 700 - 60, 300, 740, 340)))
		{
			if (c >= 1)
			{
				mciSendString(musciclose[c], 0, 0, 0);
				c -= 1;
			}
			mciSendString(musciplay[c], 0, 0, 0);
		}
		else if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 725 + textwidth(musci[c]), 300, 725 + textwidth(musci[c])+40, 340)))
		{
			if (c <= 1)
			{
				mciSendString(musciclose[c], 0, 0, 0);
				c += 1;
			}

			mciSendString(musciplay[c], 0, 0, 0);
		};
		button(670, 380, "��", "��");
		button(670, 490, "��", "��");
		if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 670, 380, 710, 420)))
		{
			if (b <= 999)
				b += 100;
		}
		else if ((msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 670, 490, 710, 530)))
		{
			if (b >= 99)
				b -= 100;
		};
		sprintf(a, musciset[c], b);
		mciSendString(a, NULL, 0, NULL);
		char arr[10];
		sprintf(arr, "%d", b / 10);
		button_nomsg(660, 430, arr);
		button(410, 565, "�ر�", "�ر�");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 410, 565, 480, 605))
		{
			flag = MY_MENU;
			break;
		}
		msg.message = 0;
		EndBatchDraw();
	}
}