#define  _CRT_SECURE_NO_WARNINGS 1
#include"�ξ�����.h"
extern ExMessage msg;
extern int flag;
IMAGE win_photo;
IMAGE defeat_photo;
int level = 0;//��Ϸʤ����������
int level_arr[36] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};//������Ĺؿ�
int life = 100;//��һ�������ֵ
int shield = 0;//��һ�������ֵ
int power = 100;//��һ�������
int smart = 100;//��һ�������
int speed = 100;//��һ�������

IMAGE guochang_photo;
extern struct EVENT Event[36];//��30���¼�
extern class IMAGE Event_photo[36];//30���¼���Ӧ��ͼƬ

extern Good_tool all_good_tool[36][3];//�����ܹ���36���¼�ÿ���¼����3���ӳ��͵���
extern Bad_tool all_bad_tool[36][3];//�����ܹ���36���¼�ÿ���¼����3���ͷ��͵���
extern IMAGE good_tool[36][3];//������ĺõ�����أ����Ҫ�ӵ�����һһ��Ӧ
extern IMAGE bad_tool[36][3];//������Ļ�������أ����Ҫ�ӵ�����һһ��Ӧ

Bag bag;//����һ�����������Է���16���ӳ��͵��ߣ���16���ͷ��Ե���
int bag_gt;//�����õ��߼���
int bag_bt;//���������߼���
//-----------------------�������-----------------------
//------------------------service--------------------
/*
 �����ˣ�4c
 ���ܣ�
   �ж���Ϸ�Ƿ����
   �Ƿ�ͨ��or�Ƿ���������ͨ��ʱ����ֵС��0��ʧ�ܣ�
 ������void
 ����ֵ��0����û������Ϸ��1����ʤ����2����ʧ��

*/
int If_End_Game()
{
	if (level == 7)
	{
		if (life > 1e-6)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		if (life <= 0)
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
}
/*
   �����ˣ���з
 ���ܣ�
   �ж������ȡ���¼��Ƿ��ѷ���
 �������¼����event
 ����ֵ��bool���൱��int������ture 1����false 0��
*/
bool judge_event(int event)
{
	for (int i = 0; i < level; i++)
	{
		if (level_arr[i] == event)
			return false;
	}
	return true;
}
/*
 �����ˣ�С��
 ���ܣ�
   ���������ȡ�¼���Ŀǰ�趨36�����飩
	��ȡ���ж��Ƿ��Ѿ���ȡ���������ȡ�����ٴγ�ȡ
	���û��ȡ�����¼�����������¼����
 ������void
 ����ֵ���¼����
*/
int choose_event()//ѡ���¼�
{
	srand((unsigned)time(NULL));
	int event = rand() % 30;//%�������Ըı䣬���������ж��ٸ�����͸ı�ɶ���
	return event;
}
/*
 �����ˣ�������
 ���ܣ�
   ��ʼ������������ֵ����ά���ԣ���������Ĺؿ����������
 ������void
 ����ֵ��void
*/
void Init_attribute()
{
	life = 100;//��һ�������ֵ
	shield = 0;//��һ�������ֵ
	power = 100;//��һ�������
	smart = 100;//��һ�������
	speed = 100;//��һ�������
	level = 0;
	for (int i = 0; i <36; i++)
	{
		level_arr[i] = -1;
	}
	bag_gt = 0;
	bag_bt = 0;
	for (int i = 0; i < 36; i++)
	{
		bag.GT[i] = 0;
		bag.BT[i] = 0;
		bag.Gt[i] = 0;
		bag.Bt[i] = 0;
	}
}
/*
  �����ˣ�С��
  ���ܣ�
	�����ڸ��¼�����ҵ�����ֵ�ͻ���ֵ���¼���ʹ������Ըı䣩
	ע�����Ϊ����Ч��������ֵ��Ϊ��ҵֵ������˺�
	����ֵ���ܹ�0��ʧ��
  ��������������ֵ�ӳ�/���� tool_life���¼�����ֵevent_life�����߻���ֵtool_shield���¼�����ֵevent_shield
  ����ֵ��void
*/
void life_and_shield_change(int tool_life, int event_life, int tool_shield, int event_shield)
{
	int ret = tool_shield + event_shield;//�¼��͵��߼���һ��Ļ���ֵ
	int sum = tool_life + event_life;//�¼��͵��߼���һ�������ֵ
	shield += ret;
	if (sum < 0)
	{
		if (shield >= abs(sum))
		{
			shield += sum;
		}
		else
		{
			if (abs(sum) >= life + shield)
			{
				shield = 0;
				life = 0;
				If_End_Game();
			}
			else
			{
				sum += shield;
				shield = 0;
				life += sum;
			}
		}
	}
	else
	{
		life += sum;
	}
}

/*
  �����ˣ��˷���
  ���ܣ�
	�����ڸ��¼�����ҵ�����ֵ���¼���ʹ������Ըı䣩
	������ֵС��0��0��
  ��������������ֵ�ӳ�/���� tool_power���¼�����ֵevent_power
  ����ֵ��void
*/
void power_change(int tool_power, int event_power)
{
	int sum = tool_power + event_power;//�¼��͵��߼���һ�������ֵ
	if (sum < 0)
	{
		if (power < abs(sum))
		{
			power = 0;
		}
		else
		{
			power += sum;
		}
	}
	else
		power += sum;
}

/*
  �����ˣ�
  ���ܣ�
	�����ڸ��¼�����ҵ��������¼���ʹ������Ըı䣩
	������С��0��0��
  ��������������ֵ�ӳ�/���� tool_smart���¼�����ֵevent_smart
  ����ֵ��void
*/
void smart_change(int tool_smart, int event_smart)
{
	int sum = tool_smart + event_smart;//�¼��͵��߼���һ�������ֵ
	if (sum < 0)
	{
		if (smart < abs(sum))
		{
			smart = 0;
		}
		else
		{
			smart += sum;
		}
	}
	else
		smart += sum;
}

/*
  �����ˣ�
  ���ܣ�
	�����ڸ��¼�����ҵ����ݣ��¼���ʹ������Ըı䣩
	������С��0��0��
  ���������߶����ݼӳ�/���� tool_speed���¼�����ֵevent_speed
*/
void speed_change(int tool_speed, int event_speed)
{
	int sum = tool_speed + event_speed;//�¼��͵��߼���һ�������ֵ
	if (sum < 0)
	{
		if (speed < abs(sum))
		{
			speed = 0;
		}
		else
		{
			speed += sum;
		}
	}
	else
		speed += sum;
}

//------------------------service--------------------
//----------------------------view--------------------------
/*
  �����ˣ��հ�
  ���ܣ�
	���������һ��
  ������void
  ����ֵ��void
*/
//void interlude_photo()
//{
//	while (1)
//	{
//		if (msg.message == WM_LBUTTONDOWN && (!inArea(msg.x, msg.y, 1000, 0, 80, 100)))
//		{
//			flag = MY_GAME;
//			break;
//		}
//		msg.message = 0;
//	}
//}
/*
  �����ˣ�����
  ���ܣ�
	
		1.չʾ�������棨����/��Բ���Σ����Ը����ֽ���һ��������һ�����Σ�Ȼ����������ʾ�����Ϣ
		//Ҳ���԰�������һ�������Ľ��棬�ڽ�����չʾ�����Ϣ
		2.�·����и��ӷ��ñ�������ӵ�еĵ���
		3.������߻����Ϸ�չʾ���ߵ���ϸ���Ժ͵��ߵ���Ϣ
		4.�˳����˻���Ϸ���棻
  ������void
  ����ֵ��void
*/
void Bag_view()
{
	while (1)
	{
		int gg = 0;
		BeginBatchDraw();
		setlinecolor(BLACK);		
		settextstyle(40, 0, "΢���ź�");
		peekmessage(&msg, EX_MOUSE);
		for (int i = 0; i < 30;)
		{
			clearrectangle(150, 150, 850, 850);
			setfillcolor(RGB(211, 211, 211));
			fillrectangle(150, 150, 850, 850);
			settextstyle(50, 0, "��������");
			outtextxy(750, 150, "�˳�");
			outtextxy(300, 700, "��һҳ");
			outtextxy(700, 700, "��һҳ");
			char str[10];
			sprintf(str, "��%dҳ", i);
			outtextxy(500, 700, str);
			peekmessage(&msg, EX_MOUSE);
			if (inArea(msg.x, msg.y, 300, 700, textwidth("��һҳ"), textheight("��һҳ")) && i >= 1)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 300, 700, textwidth("��һҳ"), textheight("��һҳ")))
				{
					i--;
					Sleep(250);
				}
			}
			if (inArea(msg.x, msg.y, 700, 700, textwidth("��һҳ"), textheight("��һҳ")) && i <= 21)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 700, 700, textwidth("��һҳ"), textheight("��һҳ")))
				{
					i++;
					Sleep(250);
				}
			}
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 750, 150, textwidth("�ر�"), textwidth("�ر�")))
			{
				//gg = 1;
				settextcolor(RGB(157, 0, 176));
				clearrectangle(200, 200, 800, 800);
				//flag = MY_GAME;
				return;
			}
			settextcolor(BLACK);
			settextstyle(35, 0, "΢���ź�");
			putimage(180, 180, &good_tool[bag.Gt[i]][bag.GT[i]]);//�õ��ߵ�ͼƬչʾ
			outtextxy(310,180 , all_good_tool[bag.Gt[i]][bag.GT[i]].name);//�õ��ߵ�����չʾ
			RECT text1{ 310,220,425,425 };
			settextstyle(25, 0, "΢���ź�");
			drawtext(all_good_tool[bag.Gt[i]][bag.GT[i]].info, &text1, DT_WORDBREAK);//�õ��ߵ���Ϣչʾ
			char arr[10];
			itoa(all_good_tool[bag.Gt[i]][bag.GT[i]].life, arr, 10);
			settextstyle(35, 0, "΢���ź�");
			outtextxy(150, 425, "����ֵ��");//�õ��ߵ�����ֵչʾ
			outtextxy(150 + textwidth("����ֵ��"), 425, arr);
			itoa(all_good_tool[bag.Gt[i]][bag.GT[i]].shield, arr, 10);
			outtextxy(150, 470, "����ֵ��");//�õ��ߵĻ���ֵչʾ
			outtextxy(150 + textwidth("����ֵ��"), 470, arr);
			itoa(all_good_tool[bag.Gt[i]][bag.GT[i]].power, arr, 10);
			outtextxy(150, 515, "����ֵ��");//�õ��ߵ�����ֵչʾ
			outtextxy(150 + textwidth("����ֵ��"), 515, arr);
			itoa(all_good_tool[bag.Gt[i]][bag.GT[i]].smart, arr, 10);
			outtextxy(150, 560, "����ֵ��");//�õ��ߵ�����ֵչʾ
			outtextxy(150 + textwidth("����ֵ��"), 560, arr);
			itoa(all_good_tool[bag.Gt[i]][bag.GT[i]].speed, arr, 10);
			outtextxy(150, 605, "����ֵ��");//�õ��ߵ�����ֵչʾ
			outtextxy(150 + textwidth("����ֵ��"), 605, arr);


			putimage(450, 180, &bad_tool[bag.Bt[i]][bag.BT[i]]);//�����ߵ�ͼƬչʾ
			outtextxy(580, 180, all_bad_tool[bag.Bt[i]][bag.BT[i]].name);//�����ߵ�����չʾ
			RECT text2{ 580,220,700,425 };
			settextstyle(25, 0, "΢���ź�");
			drawtext(all_bad_tool[bag.Bt[i]][bag.BT[i]].info, &text2, DT_WORDBREAK);//�����ߵ���Ϣչʾ
			itoa(all_bad_tool[bag.Bt[i]][bag.BT[i]].life, arr, 10);
			settextstyle(35, 0, "΢���ź�");
			outtextxy(450, 425, "����ֵ��");//�����ߵ�����ֵչʾ
			outtextxy(450 + textwidth("����ֵ��"), 425, arr);
			itoa(all_bad_tool[bag.Bt[i]][bag.BT[i]].shield, arr, 10);
			outtextxy(450, 470, "����ֵ��");//�����ߵĻ���ֵչʾ
			outtextxy(450 + textwidth("����ֵ��"), 470, arr);
			itoa(all_bad_tool[bag.Bt[i]][bag.BT[i]].power, arr, 10);
			outtextxy(450, 515, "����ֵ��");//�����ߵ�����ֵչʾ
			outtextxy(450 + textwidth("����ֵ��"), 515, arr);
			itoa(all_bad_tool[bag.Bt[i]][bag.BT[i]].smart, arr, 10);
			outtextxy(450, 560, "����ֵ��");//�����ߵ�����ֵչʾ
			outtextxy(450 + textwidth("����ֵ��"), 560, arr);
			itoa(all_bad_tool[bag.Bt[i]][bag.BT[i]].speed, arr, 10);
			outtextxy(450, 605, "����ֵ��");//�����ߵ�����ֵչʾ
			outtextxy(450 + textwidth("����ֵ��"), 605, arr);
			FlushBatchDraw();
			setlinestyle(PS_SOLID, 1);
			setlinecolor(RGB(255, 255, 255));
			msg.message = 0;
		}
		/*if (gg)
		{
			break;
		}*/
		EndBatchDraw();
		msg.message = 0;

	}
}



/*
  �����ˣ���κ
  ���ܣ�
	չʾ��Ϸʤ������
	������⴦�������˵�
  ������void
  ����ֵ��void
*/
void Win_View()
{
	loadimage(&win_photo, "photos/ʤ������.jpg",1080,960);//ʤ��ͼƬ��û�ң������滻��
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &win_photo);
		settextstyle(40, 0, "����");
		outtextxy(460, 680, "���������ص���ҳ��");
		
		EndBatchDraw();
		
		if (msg.message == WM_LBUTTONDOWN)
		{
			flag = MY_MENU;
			Sleep(100);
			break;
		}
		msg.message = 0;

	}
}
/*
  �����ˣ���κ
  ���ܣ�
	�����Ϸʧ�ܽ���
	������⴦�������˵�
  ������void
  ����ֵ��void
*/
void Defeat_View()
{
	loadimage(&defeat_photo, "photos\\ʧ��ͼƬ.jpg",1080,960);
	while (1)
	{
		BeginBatchDraw();
		peekmessage(&msg, EX_MOUSE);
		cleardevice();
		putimage(0, 0, &defeat_photo);
		settextstyle(40, 0, "����");
		outtextxy(460, 680, "���������ص���ҳ��");
		EndBatchDraw();
		
		if (msg.message == WM_LBUTTONDOWN)
		{
			flag = MY_MENU;
			Sleep(100);
			break;
		}
		msg.message = 0;
	}
}
void show_change(int event, int i)
{
	char arr[10];
	//�¼��仯ֵ,��ѡ�������չʾ
	itoa(Event[event].life[i], arr, 10);
	outtextxy(360, 760, Event[event].name);
	outtextxy(360, 800, "����ֵ��");
	outtextxy(360 + textwidth("����ֵ��"), 800, arr);
	itoa(Event[event].shield[i], arr, 10);
	outtextxy(360, 830, "����ֵ��");
	outtextxy(360 + textwidth("����ֵ��"), 830, arr);
	itoa(Event[event].power[i], arr, 10);
	outtextxy(360, 860, "����ֵ��");
	outtextxy(360 + textwidth("����ֵ��"), 860, arr);
	itoa(Event[event].smart[i], arr, 10);
	outtextxy(360, 890, "����ֵ��");
	outtextxy(360 + textwidth("����ֵ��"), 890, arr);
	itoa(Event[event].speed[i], arr, 10);
	outtextxy(360, 920, "�ٶ�ֵ��");
	outtextxy(360 + textwidth("�ٶ�ֵ��"), 920, arr);
	//������߱仯ֵ����ѡ������һչʾ
	putimage(0, 800, &(good_tool[event][i]));
	outtextxy(0, 760, all_good_tool[event][i].name);
	itoa(all_good_tool[event][i].life, arr, 10);
	outtextxy(100, 800, "����ֵ��");
	outtextxy(100 + textwidth("����ֵ��"), 800, arr);
	itoa(all_good_tool[event][i].shield, arr, 10);
	outtextxy(100, 830, "����ֵ��");
	outtextxy(100 + textwidth("����ֵ��"), 830, arr);
	itoa(all_good_tool[event][i].power, arr, 10);
	outtextxy(100, 860, "����ֵ��");
	outtextxy(100 + textwidth("����ֵ��"), 860, arr);
	itoa(all_good_tool[event][i].smart, arr, 10);
	outtextxy(100, 890, "����ֵ��");
	outtextxy(100 + textwidth("����ֵ��"), 890, arr);
	itoa(all_good_tool[event][i].speed, arr, 10);
	outtextxy(100, 920, "�ٶ�ֵ��");
	outtextxy(100 + textwidth("�ٶ�ֵ��"), 920, arr);
	//������߱仯ֵ����ѡ��������չʾ
	putimage(620, 700, &(bad_tool[event][i]));
	outtextxy(720, 760, all_bad_tool[event][i].name);
	itoa(all_bad_tool[event][i].life, arr, 10);
	outtextxy(720, 800, "����ֵ��");
	outtextxy(720 + textwidth("����ֵ��"), 800, arr);
	itoa(all_bad_tool[event][i].shield, arr, 10);
	outtextxy(720, 830, "����ֵ��");
	outtextxy(720 + textwidth("����ֵ��"), 830, arr);
	itoa(all_bad_tool[event][i].power, arr, 10);
	outtextxy(720, 860, "����ֵ��");
	outtextxy(720 + textwidth("����ֵ��"), 860, arr);
	itoa(all_bad_tool[event][i].smart, arr, 10);
	outtextxy(720, 890, "����ֵ��");
	outtextxy(720 + textwidth("����ֵ��"), 890, arr);
	itoa(all_bad_tool[event][i].speed, arr, 10);
	outtextxy(720, 920, "�ٶ�ֵ��");
	outtextxy(720 + textwidth("�ٶ�ֵ��"), 920, arr);

}
void show_player()
{
	char player_attribute[10];
	int_to_string(life, player_attribute);
	settextstyle(30, 0, "��������");
	outtextxy(850, 150, "����ֵ��");
	outtextxy(850 + textwidth("����ֵ��"), 150, player_attribute);
	itoa(shield, player_attribute, 10);
	outtextxy(850, 250, "����ֵ��");
	outtextxy(850 + textwidth("����ֵ��"), 250, player_attribute);
	itoa(power, player_attribute, 10);
	outtextxy(850, 350, "����ֵ��");
	outtextxy(850 + textwidth("����ֵ��"), 350, player_attribute);
	itoa(smart, player_attribute, 10);
	outtextxy(850, 450, "����ֵ��");
	outtextxy(850 + textwidth("����ֵ��"), 450, player_attribute);
	itoa(speed, player_attribute, 10);
	outtextxy(850, 550, "����ֵ��");
	outtextxy(850 + textwidth("����ֵ��"), 550, player_attribute);
}
/*
  �����ˣ�
  ���ܣ�
	    1.�ж�level�Ƿ�Ϊ0�������Գ�ʼ����ͼƬ�ļ���
	    2.�ж�If_End_Game�ж��Ƿ������Ϸ
			3����level����choose_event
				3.1��level=0���򲻽��н���choose_event��ֱ�ӽ��е���������ѡ�����
				3.2��level������0�������choose_event�����������ȡһ�������������عؿ�
			4.��ʾ��ǰ�ĵڼ���(��levelȥ��ʾ������)(�ʼ��Ҳ���ǵ�0�أ���ѡ���������߽����ξ������Ե�0��Ҫд�� Ш�� ���� ��ʼ )
			5.�ڹ̶�����ȥ��ʾ�������ı���ʱ��ѡ�����������ԣ��������ã���������
			6.���������ѡ�����ʾѡ��ĺ�������
			7.����������ʾ��Ϻ�չʾ�¼������Եĸı�͵��ߵ�����
			8.������ŵ���
			9.�������Ե����ӻ��߿۳�
			10.����level�ı�
			11.����interlude_photo()����ͼƬ���νӹؿ���
  ������void
  ����ֵ��void
*/
void startgame()//
{
	int control = 0;
	if (level == 0)
	{
		load_photo();
		init_good_tool();
		init_bad_tool();
		load_event();
		//1.�ж�level�Ƿ�Ϊ7
		//��Ϊ7���жϵ�ǰ����ֵ�Ƿ�Ϊ0����Ϊ�������ʧ�ܽ��棬������0�����ʤ������
			//2.��level��Ϊ7�����жϵ�ǰ�����Ƿ�Ϊ0����Ϊ�������ʧ�ܽ��棬����Ϊ���������Ϸ
		Init_attribute();
		achieve_get();
		file_achieve_get();
		store_achieve();
	}
	
	setbkcolor(WHITE);
	cleardevice();
	int event = 0;
	while (!judge_event(event = choose_event()))
	{
		;
	}
	level_arr[level] = event;
	while (1)
	{
		BeginBatchDraw();
		settextstyle(50, 0, "��������");
		settextcolor(RGB(157, 0, 176));

		peekmessage(&msg, EX_MOUSE);
		/*
			2.�ж�If_End_Game�ж��Ƿ������Ϸ
			3����level����choose_event
				3.1��level=0���򲻽��н���choose_event��ֱ�ӽ��е���������ѡ�����
				3.2��level������0�������choose_event�����������ȡһ�������������عؿ�
			4.��ʾ��ǰ�ĵڼ���(��levelȥ��ʾ������)(�ʼ��Ҳ���ǵ�0�أ���ѡ���������߽����ξ������Ե�0��Ҫд�� Ш�� ���� ��ʼ )
			5.�ڹ̶�����ȥ��ʾ�������ı���ʱ��ѡ�����������ԣ��������ã���������
			6.���������ѡ�����ʾѡ��ĺ�������
			7.����������ʾ��Ϻ�չʾ�¼������Եĸı�͵��ߵ�����
			8.������ŵ���
			9.�н����Ե����ӻ��߿۳�
			10.����level�ı�
			11.����interlude_photo()����ͼƬ���νӹؿ���
		*/
		if (If_End_Game() == 1)
		{
			flag = Win_VIEW;
			break;
		}
		else if (If_End_Game() == 2)
		{
			flag = DEFEAT_VIEW;
			break;
		}
		putimage(0, 0, &Event_photo[event]);//����Ӧ������ͼƬ
		/*
			ʵ�������������򣬱���ͼƬ���������õķ��á�
		*/
		outtextxy(950, 10, "����");//�������õķ���
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 1000, 0, 80, 100))
		{
			Gear_set();
			/*control = 1;
			flag = GEAR;*/
			//break;
		}
		outtextxy(0, 300, "����");//��������ķ���
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 50, 300, 50, 50))
		{
			Bag_view();
			/*control = 1;
			flag = BAG;*/
			//break;
		}
		//��Ϸ������ά���Ե�չʾ
		show_player();
		/*
			1.����ѡ�� 2.ÿ��ѡ��ĺ������� 3.�������Եĸı� 4.������ŵ���
		*/
		settextstyle(30, 0, "΢���ź�");
		settextcolor(WHITE);
		RECT r = { 150, 150, 760, 850 };//�����������¼�������Ϣ
		RECT one{ 0,800,360,960 };//չʾѡ��һ
		RECT two{ 360,800,720,960 };//չʾѡ���
		RECT three{ 720,800,1080,960 };//չʾѡ����
		RECT next{ 850,600,1030,800 };
		rectangle(0, 800, 360, 960);//չʾѡ��һ
		rectangle(360, 800, 720, 960);//չʾѡ���
		rectangle(720, 800, 1080, 960);//չʾѡ����
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 750, 360, 210))//���ѡ��һ
		{
			get_achievement(all_good_tool[event][0].sp);
			get_achievement(all_bad_tool[event][0].sp);
			level++;
			if (all_good_tool[event][0].life != 0 || all_good_tool[event][0].shield != 0 || all_good_tool[event][0].power != 0 || all_good_tool[event][0].smart != 0 || all_good_tool[event][0].speed)
			{
				life_and_shield_change(all_good_tool[event][0].life, Event[event].life[0], all_good_tool[event][0].shield, Event[event].shield[0]);
				power_change(all_good_tool[event][0].power, Event[event].power[0]);
				smart_change(all_good_tool[event][0].smart, Event[event].smart[0]);
				speed_change(all_good_tool[event][0].speed, Event[event].speed[0]);//�ı���ά����ֵ
			}
			else
			{
				life_and_shield_change(all_bad_tool[event][0].life, Event[event].life[0], all_bad_tool[event][0].shield, Event[event].shield[0]);
				power_change(all_bad_tool[event][0].power, Event[event].power[0]);
				smart_change(all_bad_tool[event][0].smart, Event[event].smart[0]);
				speed_change(all_bad_tool[event][0].speed, Event[event].speed[0]);//�ı���ά����ֵ
			}
			if (strlen(all_good_tool[event][0].name)!=0)//����кõ���
			{
				bag.Gt[bag_gt] = event;//�ڱ�����洢
				bag.GT[bag_gt] = 0;
				bag_gt++;
				
				msg.message = 0;
			}
			
			else if (strlen(all_bad_tool[event][0].name)!=0)//����л�����
			{
				bag.Bt[bag_bt] = event;//�ڱ�����洢
				bag.BT[bag_bt] = 0;
				bag_bt++;
				msg.message = 0;
			}
			Sleep(300);
			while (1)
			{
				peekmessage(&msg, EX_MOUSE);
				settextcolor(WHITE);
				drawtext(Event[event].after_info_one, &r, DT_WORDBREAK);
				show_change(event, 0);
				drawtext("���������һ��", &next, DT_WORDBREAK);
				FlushBatchDraw();
				peekmessage(&msg, EX_MOUSE);
				if (msg.message == WM_LBUTTONDOWN && (!inArea(msg.x, msg.y, 0, 750, 1080, 210)))
				{
					control = 1;
					break;
				}
				msg.message = 0;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 360, 750, 360, 210))//���ѡ���
		{
			get_achievement(all_good_tool[event][1].sp);
			get_achievement(all_bad_tool[event][1].sp);
			level++;
			if (all_good_tool[event][1].life != 0 || all_good_tool[event][1].shield != 0 || all_good_tool[event][1].power != 0 || all_good_tool[event][1].smart != 0 || all_good_tool[event][1].speed)
			{
				life_and_shield_change(all_good_tool[event][1].life, Event[event].life[1], all_good_tool[event][1].shield, Event[event].shield[1]);
				power_change(all_good_tool[event][1].power, Event[event].power[1]);
				smart_change(all_good_tool[event][1].smart, Event[event].smart[1]);
				speed_change(all_good_tool[event][1].speed, Event[event].speed[1]);
			}
			else
			{
				life_and_shield_change(all_bad_tool[event][1].life, Event[event].life[1], all_bad_tool[event][1].shield, Event[event].shield[1]);
				power_change(all_bad_tool[event][1].power, Event[event].power[1]);
				smart_change(all_bad_tool[event][1].smart, Event[event].smart[1]);
				speed_change(all_bad_tool[event][1].speed, Event[event].speed[1]);
			}
			if (strlen(all_good_tool[event][1].name )!=0)//���Ϸ�һ��
			{
				bag.Gt[bag_gt] = event;//�ڱ�����洢
				bag.GT[bag_gt] = 1;
				bag_gt++;//�洢������Ϣ�±�		
				msg.message = 0;
			}
			else if (strlen(all_bad_tool[event][1].name )!=0)
			{
				bag.Bt[bag_bt] = event;//�ڱ�����洢
				bag.BT[bag_bt] = 1;
				bag_bt++;
				msg.message = 0;
			}
			Sleep(300);
			settextcolor(WHITE);
			while (1)
			{
				peekmessage(&msg, EX_MOUSE);
				drawtext(Event[event].after_info_two, &r, DT_WORDBREAK);
				show_change(event, 1);
				drawtext("���������һ��", &next, DT_WORDBREAK);
				FlushBatchDraw();
				peekmessage(&msg, EX_MOUSE);
				if (msg.message == WM_LBUTTONDOWN && (!inArea(msg.x, msg.y, 0, 750, 1080, 210)))
				{
					control = 1;
					break;
				}
				msg.message = 0;
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 720, 750, 360, 210))//���ѡ����
		{
			get_achievement(all_good_tool[event][2].sp);
			get_achievement(all_bad_tool[event][2].sp);
			level++;
			if (all_good_tool[event][2].life != 0 || all_good_tool[event][2].shield != 0 || all_good_tool[event][2].power != 0 || all_good_tool[event][2].smart != 0 || all_good_tool[event][2].speed)
			{
				life_and_shield_change(all_good_tool[event][2].life, Event[event].life[2], all_good_tool[event][2].shield, Event[event].shield[2]);
				power_change(all_good_tool[event][2].power, Event[event].power[2]);
				smart_change(all_good_tool[event][2].smart, Event[event].smart[2]);
				speed_change(all_good_tool[event][2].speed, Event[event].speed[2]);
			}
			else
			{
				life_and_shield_change(all_bad_tool[event][2].life, Event[event].life[2], all_bad_tool[event][2].shield, Event[event].shield[2]);
				power_change(all_bad_tool[event][2].power, Event[event].power[2]);
				smart_change(all_bad_tool[event][2].smart, Event[event].smart[2]);
				speed_change(all_bad_tool[event][2].speed, Event[event].speed[2]);
			}
			if (strlen(all_good_tool[event][2].name )!=0)//���Ϸ�һ��
			{
				bag.Gt[bag_gt] = event;//�ڱ�����洢
				bag.GT[bag_gt] = 2;
				bag_gt++;//�洢������Ϣ�±�
				msg.message = 0;
			}
			else if (strlen(all_bad_tool[event][2].name )!=0)
			{
				bag.Gt[bag_bt] = event;//�ڱ�����洢
				bag.GT[bag_bt] = 2;
				bag_bt++;//�洢������Ϣ�±�	
			
				msg.message = 0;
			}
			Sleep(300);
			while (1)
			{
				peekmessage(&msg, EX_MOUSE);
				settextcolor(WHITE);
				drawtext(Event[event].after_info_three, &r, DT_WORDBREAK);
				show_change(event, 2);
				drawtext("���������һ��", &next, DT_WORDBREAK);
				FlushBatchDraw();
				peekmessage(&msg, EX_MOUSE);
				if (msg.message == WM_LBUTTONDOWN && (!inArea(msg.x,msg.y,0, 750, 1080, 210)))
				{
					control = 1;
					break;
				}
				msg.message = 0;
			}
		}
		else
		{
			
			drawtext(Event[event].info, &r, DT_WORDBREAK);//�������RECT�ľ�������д�¼����Զ�����
			drawtext(Event[event].choose_one, &one, DT_WORDBREAK);
			drawtext(Event[event].choose_two, &two, DT_WORDBREAK);
			drawtext(Event[event].choose_three, &three, DT_WORDBREAK);
		}
		if (control)
		{
			break;
		}
		EndBatchDraw();

		msg.message = 0;
	}
	
}
//----------------------------view--------------------------
/*
  �����ˣ�
  ���ܣ�
	���������¼��͵���ͼƬ
  ������void
  ����ֵ��void
*/
void load_photo()
{
	loadimage(&guochang_photo, "photos/��������.jpg");
	int i = 0;

	//�¼�ͼƬ���¼���Ӧ����ͼƬ
	loadimage(&good_tool[i][1], "TOOL_PHOTO/�¼�0ѡ�������.jpg",100,100);	//0
	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�0ѡ��������.jpg",100,100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�0����.jpg",1080,960);

	loadimage(&good_tool[i][1], "TOOL_PHOTO/�¼�1ѡ�������.jpg", 100, 100);//1
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�1����.jpg", 1080, 960);

	loadimage(&good_tool[i][0], "TOOL_PHOTO/�¼�2ѡ��һ����.jpg",100,100);//2
	loadimage(&bad_tool[i][1], "TOOL_PHOTO/�¼�2ѡ�������.jpg",100,100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�2����.jpg", 1080, 960);


	loadimage(&good_tool[i][1], "TOOL_PHOTO/�¼�3ѡ�������.jpg",100, 100);//3
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�3����.jpg", 1080, 960);


	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�4ѡ��������.jpg", 100, 100);//4
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�4����.jpg", 1080, 960);

	loadimage(&good_tool[i][0], "TOOL_PHOTO/�¼�5ѡ��һ����.jpg", 100, 100);//5
	loadimage(&good_tool[i][1], "TOOL_PHOTO/�¼�5ѡ�������.jpg", 100, 100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�5����.jpg", 1080, 960);

	loadimage(&bad_tool[i][0], "TOOL_PHOTO/�¼�6ѡ��һ����.jpg", 100, 100);//6
	loadimage(&bad_tool[i][1], "TOOL_PHOTO/�¼�6ѡ�������.jpg",100,100);
	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�6ѡ��������.jpg", 100, 100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�6����.jpg", 1080, 960);

	loadimage(&bad_tool[i][0], "TOOL_PHOTO/�¼�7ѡ��һ����.jpg", 100, 100);//7
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�7����.jpg", 1080, 960);

	loadimage(&good_tool[i][0], """TOOL_PHOTO/�¼�8ѡ��һ����.jpg", 100, 100);//8
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�8����.jpg", 1080, 960);

	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�9ѡ��������.jpg", 100, 100);//9
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�9����.jpg", 1080, 960);

	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�10ѡ��������.jpg", 100, 100);//10
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�10����.jpg", 1080, 960);

	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�11����.jpg", 1080, 960);//11

	loadimage(&good_tool[i][1], "TOOL_PHOTO/�¼�12ѡ�������.jpg", 100, 100);//12
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�12����.jpg", 1080, 960);

	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�13ѡ��������.jpg", 100, 100);//13
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�13����.jpg", 1080, 960);


	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�14ѡ��������.jpg", 100, 100);//14
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�14����.jpg", 1080, 960);

	loadimage(&good_tool[i][0], "TOOL_PHOTO/�¼�15ѡ��һ����.jpg", 100, 100);//15
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�15����.jpg", 1080, 960);

	loadimage(&good_tool[i][1], "TOOL_PHOTO/�¼�16ѡ�������.jpg", 100, 100);//16
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�16����.jpg", 1080, 960);

	loadimage(&good_tool[i][0], "TOOL_PHOTO/�¼�17ѡ��һ����.jpg", 100, 100);//17
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�17����.jpg", 1080, 960);

	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�18ѡ��������.jpg", 100, 100);//18
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�18����.jpg", 1080, 960);


	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�19ѡ��������.jpg", 100, 100);//19
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�19����.jpg", 1080, 960);

	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�20����.jpg", 1080, 960);//20

	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�21����.jpg", 1080, 960);//21

	loadimage(&bad_tool[i][2], "TOOL_PHOTO/�¼�22ѡ��������.jpg", 100, 100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�22����.jpg", 1080, 960);//22


	loadimage(&bad_tool[i][1], "TOOL_PHOTO/�¼�23ѡ�������.jpg", 100, 100);//23
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�23����.jpg", 1080, 960);

	loadimage(&bad_tool[i][0], "TOOL_PHOTO/�¼�24ѡ��һ����.jpg", 100, 100);//24
	loadimage(&bad_tool[i][1], "TOOL_PHOTO/�¼�24ѡ�������.jpg", 100, 100);
	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�24ѡ��������.jpg", 100, 100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�24����.jpg", 1080, 960);

	loadimage(&good_tool[i][0], "TOOL_PHOTO/�¼�25ѡ��һ����.jpg", 100, 100);//25
	loadimage(&good_tool[i][1], "TOOL_PHOTO/�¼�25ѡ�������.jpg", 100, 100);
	loadimage(&good_tool[i][2], "TOOL_PHOTO/�¼�25ѡ��������.jpg", 100, 100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�25����.jpg", 1080, 960);


	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�26����.jpg", 1080, 960);//26

	loadimage(&good_tool[i][0], "TOOL_PHOTO/�¼�27ѡ��һ����.jpg", 100, 100);//27
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�27����.jpg", 1080, 960);

	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�28����.jpg", 1080, 960);//28

	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼�29����.jpg", 1080, 960);//29



}