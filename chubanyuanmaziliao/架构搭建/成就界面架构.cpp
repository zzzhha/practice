#define  _CRT_SECURE_NO_WARNINGS 1
#include"�ξ�����.h"
Achievement achievement[36];
extern ExMessage msg;
IMAGE achieve_photo;
extern int flag;
int symbol = 0;
FILE* fp;
//-----------------------�������-----------------------
//-----------------------service-----------------------
/*
	������: �հ�
    ����: 
        �г���Ϸ�е����гɾ���Ϣ
    ����: void
    ����ֵ: void
*/
void achieve_get()//�ɾͻ�ȡ
{
	int i = 0;
	achievement[i++] = { 0,"�ɶ࣡","�ɶ࣡��ȥ�ľ�ȥ��",0 };
	achievement[i++] = { 1,"��ү����","�����ϵľ����ôʣ����㾹Ȼ�������Լ����ϣ����ò�˵���������ү�����Ǻܴϻ۵ģ�",0 };
	achievement[i++] = { 2,"D32��սʿ","�����Ʒ��ô��˵�����Ǹ���������ƣ����Ǿ�����ʲô��ϵ��",0 };
	achievement[i++] = { 3,"������","�����ѹ����˵ĸ�룬�Ƕ����磬������ģ�",0 };
	achievement[i++] = { 4,"�����һ�","������һ�죬�һ�...",0 };
	achievement[i++] = { 5,"�ƻ��봴��","�ƻ�����Ϊ�˸�ΰ��Ĵ���",0 };
	achievement[i++] = { 6,"���","����ɣ��ҵİ��ˣ���Ц��",0 };
	achievement[i++] = { 7,"����ʳ��","killer Queen����ĳ�����",0 };
	achievement[i++] = { 8,"����","���Σ����ǡ�����������",0 };
	achievement[i++] = { 9,"�޾��ȴ�","ʧȥ�˻�����㻹�ڵȴ�ʲô���㲻֪����Ȼ�������ǰ�������������ٲ�����",0 };
	achievement[i++] = { 10,"������","�Һ����������������������ͻָ���",0 };
	achievement[i++] = { 11,"δ֪ǰ·","�㽫ȥ�ģ�����Ժ��£�����ʲô��",0 };
	achievement[i++] = { 12,"��������","��ĵ���ֵ��������",0 };
	achievement[i++] = { 13,"Сè�ϵ�","ϲ�����ϵ�",0 };
	achievement[i++] = { 14,"���ܵ����","��һͷ�����ĺ�����ǰ���㾹Ȼѡ��װ�������ⲻ�Ǹ����˵����Ա�Ͳ�ȥ����",0 };
	achievement[i++] = { 15,"������Ū��","�㲻�����ŵ�����������������ϷŪ��һ������һ�����ס��ģ�",0 };
	achievement[i++] = { 16,"�̽�ռ�","û�����ܱ��Ҹ����̽�գ�",0 };
	achievement[i++] = { 17,"���н�����","�����������ƣ�������Ƭˮ���أ�",0 };
	achievement[i++] = { 18,"���������","ʱ���ڵεδ�����ţ���������ʱ��ȴ����ļ�������",0 };
	achievement[i++] = { 19,"ǰ��4��","��Ȼѡ��ǰ���ģ�",0 };
	achievement[i++] = { 20,"ս�ط���","С�ӣ���ӭ�������ֶ���",0 };
	achievement[i++] = { 21,"����D��","����A�㣬��������B�㣬��������C�㣬��������D�㣬�ã�",0 };
	achievement[i++] = { 22,"����ѡ��","�㻹�������ˣ���������ѡ�����ˣ�",0 };
	achievement[i++] = { 23,"������","������",0 };
	achievement[i++] = { 24,"��ë��","�ܿ�����",0 };
	achievement[i++] = { 25,"�������Ǳ�ͽ","ĩ���У���ν�����ͱ�ͽ������������޼��ɶ���",0 };
	achievement[i++] = { 26,"Ц�ڳ���","��������Ц�ڳ���",0 };
	achievement[i++] = { 27,"�ط�����","������˼���ʵʩ���������ѣ���ʹ�����ξ�����Ҳ�Ǹ�����ط��ĺù���",0 };
	achievement[i++] = { 28,"��δ�гɾ�","����Ϊʲô�أ��϶�����Ϸ������͵���ˣ�",1 };
	achievement[i++] = { 29,"����","���û�гɾ��ˣ�����",1 };
}
/*
    ������:�հ�
    ����:
       ���ɾ͸��µ�txt�ļ���
    ����: void
    ����ֵ: void
*/
void store_achieve()
{
	fp = fopen("achieve.txt", "w");
	for (int i = 0; i < 30; i++)
	{
		fprintf(fp, "SP: %d\n", achievement[i].sp);
		fprintf(fp, "Name: %s\n", achievement[i].name);
		fprintf(fp, "Text: %s\n", achievement[i].text);
		fprintf(fp, "Flag: %d\n", achievement[i].flag);
	}
}
/*
    ������:�հ�
    ����:
       //��txt�ļ��ж�ȡ���³ɾ��Ƿ����
    ����: void
    ����ֵ: void
*/
void file_achieve_get()
{
	fp = fopen("achieve.txt", "r");
	if (fp == NULL)
	{
		return;
	}
	else
	{
		for (int i = 0; i < 30; i++)
		{
			fscanf(fp, "SP: %d\n \
					Name: %s\n \
					Text: %s\n \
					Flag: %d\n",
				&achievement[i].sp, achievement[i].name, achievement[i].text, &achievement[i].flag);
		}
	}
}
/*
    ������:�հ�
    ����:
       ���ַ�����������ַ�ת����int��������
      ����: int:��Ҫ�ı�����֣�char*�洢�����ַ����ַ���
    ����ֵ: void
*/
void int_to_string(int number, char* str)
{
	int index = 0;
	// ���򹹽��ַ����������λ��ʼ��  
	do {
		str[index++] = '0' + (number % 10);
		number /= 10;
	} while (number > 0);
	// ����ַ���������  
	str[index] = '\0';
	// ��ת�ַ����Եõ���ȷ��˳��  
	for (int i = 0; i < index / 2; i++) {
		char temp = str[i];
		str[i] = str[index - i - 1];
		str[index - i - 1] = temp;
	}
}
//---------------------------service--------------------------
//--------------------------view--------------------------------------
/*
    ������:�հ�
    ����:
       �������һ���µĳɾͣ��򵯴���ʾ��
       �ı�ɾ�Ϊ�����
    ����: int:���ߵ�spֵ��IMAGE:�ɾ͵�ͼ��
    ����ֵ: void
*/
void get_achievement(int sp)//�������һ���µĳɾͣ��򵯴���ʾ��Ȼ��ı�ɾ�Ϊ�����
//��һ�������ǵ��ߵ�spֵ
{
	for (int i = 0; i < 30; i++)
	{
		if (sp == achievement[i].sp)
		{
			if (achievement[i].flag == 0)
			{
				achievement[i].flag = 1;
				store_achieve();
				settextstyle(40, 0, "΢���ź�");
				setlinestyle(PS_SOLID, 5);
				setlinecolor(RGB(138, 27, 255));
				fillrectangle(500, 50, 800, 100);
				setfillcolor(WHITE);
				button_nomsg(500, 50, "��óɾͣ�");
				button_nomsg(500 + textwidth("��óɾ�!"), 50, achievement[i].name);
				FlushBatchDraw();
			}
		}
	}
}
/*
    ������:�հ�
    ����:
      ��ӡ�ɾ�ϵͳ�Ľ���
    ����:void
    ����ֵ: void
*/
void print_achievement()
{
	while (1)
	{
		putimage(0, 0, &achieve_photo);
		setbkmode(TRANSPARENT);
		for (int i = 0; i < 5;)
		{
			settextstyle(60, 0, "��������");
			outtextxy(500, 50, "�ɾ�");
			outtextxy(950, 10, "�˳�");
			for (int j = 0; j < 6; j++)
			{
				setfillcolor(RGB(186, 127, 245));
				settextcolor(WHITE);
				setlinestyle(PS_SOLID, 3);
				setlinecolor(RGB(138, 27, 255));
				fillrectangle(100, (j + 1) * 120, 950, ((j + 1) * 120) + 90);//x�᳤850��y�᳤90��ͼƬ�ٶ�70*70
				settextstyle(40, 0, "��������");
				char arr[12] = { 0 };
				int_to_string(achievement[(i * 6) + j].sp, arr);
				outtextxy(100 + 100, (j + 1) * 120, arr);
				outtextxy(100 + 145, (j + 1) * 120, achievement[(i * 6) + j].name);
				settextstyle(25, 0, "΢���ź�");
				RECT text1 = { 100 + 350, (j + 1) * 120 ,950, ((j + 1) * 120) + 90 };
				drawtext(achievement[(i * 6) + j].text, &text1, DT_WORDBREAK);
				outtextxy(100 + 120, (j + 1) * 120 + 50, achievement[(i * 6) + j].flag ? "�����" : "δ���");
				FlushBatchDraw();
			}
			setlinestyle(PS_SOLID, 1);
			setlinecolor(RGB(255, 255, 255));
			peekmessage(&msg, EX_MOUSE);
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 950, 0, 130, 100))
			{
				flag = MY_MENU;
				symbol = 1;
				return;
			}
			fillrectangle(250, 850, 400, 910);
			fillrectangle(650, 850, 800, 910);
			outtextxy(300, 870, "��һҳ");
			outtextxy(700, 870, "��һҳ");
			if (inArea(msg.x, msg.y, 650, 850, 800, 910) && i <= 4)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 650, 850, 150, 60))
				{
					i++;
					Sleep(250);
				}
			}
			if (inArea(msg.x, msg.y, 250, 850, 400, 910) && i > 0)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 250, 850, 150, 60))
				{
					i--;
					Sleep(250);
				}
			}
			msg.message = 0;
		}
	}
}
/*
    ������:�հ�
    ����:
      1��ͳ����������
      2����ȡ�û����������ز˵�
     ����:void
    ����ֵ: void
*/
void achieve()
{
	loadimage(&achieve_photo, "photos\\purple.jpg", 1080, 960);
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		cleardevice();
		setbkmode(TRANSPARENT);
		achieve_get();
		file_achieve_get();
		store_achieve();
		print_achievement();
		if (symbol)
		{
			break;
		}
		msg.message = 0;
	}
}
//---------------------------view-----------------------------
