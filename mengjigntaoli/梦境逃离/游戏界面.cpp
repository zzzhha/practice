#define _CRT_SECURE_NO_WARNINGS 1
#include"�ξ�����.h"
extern ExMessage msg;
IMAGE Win_photo;
IMAGE Defeat_photo;
extern int flag;
int level = 0;//��Ϸʤ����������
int level_arr[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };//������Ĺؿ�
int life = 100;//��һ�������ֵ
int shield = 0;//��һ�������ֵ
int power = 100;//��һ�������
int smart = 100;//��һ�������
int speed = 100;//��һ�������

IMAGE guochang_photo;//���� ��
extern struct EVENT Event[36];//37���¼�,����ʮ�߸��¼���level����0�Ĺ̶��¼�
extern class IMAGE Event_photo[36];//36���¼���Ӧ��ͼƬ����37���¼�,��level����0�Ĺ̶��¼�
extern IMAGE achieve_photo[40];//�ɾ�ͼƬ

extern Good_tool all_good_tool[36][3];//�����ܹ���36���¼�ÿ���¼����3���ӳ��͵���
extern Bad_tool all_bad_tool[36][3];//�����ܹ���36���¼�ÿ���¼����3���ͷ��͵���
extern IMAGE good_tool[36][3];//������ĺõ�����أ����Ҫ�ӵ�����һһ��Ӧ
extern IMAGE bad_tool[36][3];//������Ļ�������أ����Ҫ�ӵ�����һһ��Ӧ

extern Good_tool level_zero_tool[9];//��ʼ������Ϸʱ���ߵ�ѡ��,����Ҫ����������������ѡ��
extern IMAGE level_zero_tool_photo[9];//��ʼ������Ϸʱ���ߵ�ͼƬ
Bag bag;//����һ�����������Է���16���ӳ��͵��ߣ���16���ͷ��Ե���
int bag_gt;
int bag_bt;

//----------------------------view--------------------------
/*
  �����ˣ�
  ���ܣ�
	��ӡ��������
	����ص���һ�ν���
  ������void
  ����ֵ��void
*/
void interlude_photo()
{
	loadimage(&guochang_photo, "photos/��������.jpg");
	putimage(0, 0, &guochang_photo);
	cleardevice();
	settextstyle(40, 0, "����");
	outtextxy(460, 680, "������������һ��");
	if (msg.message == WM_LBUTTONDOWN && (!inArea(msg.x, msg.y, 1000, 0, 80, 100)))
	{
		flag = MY_GAME;
		return;
	}
	msg.message = 0;
}


/*
  �����ˣ�
  ���ܣ�
	չʾ��������
	�ж��Ƿ�
  ������void
  ����ֵ��void
*/
void Bag_view()
{
	/*
		1.չʾ�������棨����/��Բ���Σ����Ը����ֽ���һ��������һ�����Σ�Ȼ����������ʾ�����Ϣ
		//Ҳ���԰�������һ�������Ľ��棬�ڽ�����չʾ�����Ϣ
		2.�·����и��ӷ��ñ�������ӵ�еĵ���
		3.������߻����Ϸ�չʾ���ߵ���ϸ���Ժ͵��ߵ���Ϣ
		4.�˳����˻���Ϸ����break��
	*/

}

/*
  �����ˣ�
  ���ܣ�
	�ж��Ƿ�����Ʒ���������������Ʒ���
  ������void
  ����ֵ��int
*/
int item_clicked()
{
	return 0;
}

void Win_View()
{
	/*
		1.��ӡʤ����Ϸ����
		2.�������ͷ��ص����˵�
	*/
	//��ͼƬ����ʤ�������һ�·���
	loadimage(&Win_photo, "photos/hui.jpg");//ʤ��ͼƬ��û�ң������滻��
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &Win_photo);
		cleardevice();
		settextstyle(40, 0, "����");
		outtextxy(460, 680, "���������ص���ҳ��");
		if (msg.message == WM_LBUTTONDOWN)
		{
			gamemenu();
		}
		msg.message = 0;
		EndBatchDraw();
	}
}

/*
  �����ˣ�
  ���ܣ�
	�����Ϸʧ�ܽ���
	������⴦�������˵�
  ������void
  ����ֵ��void
*/
void Defeat_View()
{
	/*
		1.��ӡʧ����Ϸ����
		2.�������ͷ��ص����˵�
	*/
	loadimage(&Defeat_photo, "photos/hui.jpg");//ʧ��ͼƬ��û���أ�������һ�£������滻��
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &Defeat_photo);
		cleardevice();
		settextstyle(40, 0, "����");
		outtextxy(460, 680, "���������ص���ҳ��");
		if (msg.message == WM_LBUTTONDOWN)
		{
			flag = MY_MENU;
			gamemenu();
		}
		msg.message = 0;
		EndBatchDraw();
	}
}

void startgame()//
{
	
	if (level == 0)
	{
		load_photo();
		init_good_tool();
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
	while (1)
	{
		BeginBatchDraw();
		settextstyle(50, 0, "��������");
		settextcolor(RGB(157, 0, 176));
		int event = 0;
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
			Win_View();
		}
		else if (If_End_Game() == 2)
		{
			Defeat_View();
		}
		event = 2;
		/*	if (level == 0)
			{
				event = 0;
			}
			else
			{
				event = choose_event();
			}*/
		char a[50] = "��0��";
		a[2] = level + 1 + '0';                                     //������ת��Ϊ��Ӧ�ַ�
		int x = textwidth(a) / 2;
		int y = textheight(a) / 2;
		outtextxy(getwidth() / 2 - x, 85 - y, a);
		putimage(0, 0, &Event_photo[event]);//����Ӧ������ͼƬ
		/*
			ʵ�������������򣬱���ͼƬ���������õķ��á�
		*/
		outtextxy(950, 10, "����");//�������õķ���
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 1000, 0, 80, 100))
		{
			Gear_set();
		}
		outtextxy(0, 300, "����");//��������ķ���
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 50, 300, 50, 50))
		{
			Bag_view();
		}
		//��Ϸ������ά���Ե�չʾ
		show_player();
		/*
			1.����ѡ�� 2.ÿ��ѡ��ĺ������� 3.�������Եĸı� 4.������ŵ���
		*/
		settextstyle(35, 0, "΢���ź�");
		settextcolor(BLACK);
		RECT r = { 150, 150, 760, 850 };//�����������¼�������Ϣ
		RECT one{ 0,800,360,960 };//չʾѡ��һ
		RECT two{ 360,800,720,960 };//չʾѡ���
		RECT three{ 720,800,1080,960 };//չʾѡ����
		RECT next{ 850,600,1030,800 };
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 750, 360, 960))//���ѡ��һ
		{
			get_achievement(all_good_tool[event][0].sp);
			get_achievement(all_bad_tool[event][0].sp);
			level++;
			if (all_good_tool[event][0].name != "\0")//����кõ���
			{
			//	bag.gt[bag_gt++] = all_good_tool[event][0];//�ڱ�����洢
				life_and_shield_change(all_good_tool[event][0].life, Event[event].life[0], all_good_tool[event][0].shield, Event[event].shield[0]);
				power_change(all_good_tool[event][0].power, Event[event].power[0]);
				smart_change(all_good_tool[event][0].smart, Event[event].smart[0]);
				speed_change(all_good_tool[event][0].speed, Event[event].speed[0]);//�ı���ά����ֵ
			}

			else if (all_bad_tool[event][0].name != "\0")//����л�����
			{
				//bag.bt[bag_bt++] = all_bad_tool[event][0];//�ڱ�����洢
				life_and_shield_change(all_bad_tool[event][0].life, Event[event].life[0], all_bad_tool[event][0].shield, Event[event].shield[0]);
				power_change(all_bad_tool[event][0].power, Event[event].power[0]);
				smart_change(all_bad_tool[event][0].smart, Event[event].smart[0]);
				speed_change(all_bad_tool[event][0].speed, Event[event].speed[0]);//�ı���ά����ֵ

			}
			while (1)
			{
				settextcolor(BLACK);
				drawtext(Event[event].after_info_one, &r, DT_WORDBREAK);
				show_change(event, 0);
				drawtext("���������һ��", &next, DT_WORDBREAK);
				if (msg.message == WM_LBUTTONDOWN )
				{
					interlude_photo();//���ù�������
					break;
				}
				FlushBatchDraw();
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 360, 800, 720, 960))//���ѡ���
		{
			get_achievement(all_good_tool[event][1].sp);
			get_achievement(all_bad_tool[event][1].sp);
			level++;
			if (all_good_tool[event][1].name != "\0")//���Ϸ�һ��
			{
			//	bag.gt[bag_gt++] = all_good_tool[event][1];
				life_and_shield_change(all_good_tool[event][1].life, Event[event].life[1], all_good_tool[event][1].shield, Event[event].shield[1]);
				power_change(all_good_tool[event][1].power, Event[event].power[1]);
				smart_change(all_good_tool[event][1].smart, Event[event].smart[1]);
				speed_change(all_good_tool[event][1].speed, Event[event].speed[1]);
			}
			else if (all_bad_tool[event][1].name != "\0")
			{
			//	bag.bt[bag_bt++] = all_bad_tool[event][1];

				life_and_shield_change(all_bad_tool[event][1].life, Event[event].life[1], all_bad_tool[event][1].shield, Event[event].shield[1]);
				power_change(all_bad_tool[event][1].power, Event[event].power[1]);
				smart_change(all_bad_tool[event][1].smart, Event[event].smart[1]);
				speed_change(all_bad_tool[event][1].speed, Event[event].speed[1]);
			}
			while(1)
			{
				settextcolor(BLACK);
				drawtext(Event[event].after_info_two, &r, DT_WORDBREAK);
				show_change(event, 1);
				drawtext("���������һ��", &next, DT_WORDBREAK);
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 850, 600, 1030, 800))
				{
					interlude_photo();//���ù�������
					break;
				}
				FlushBatchDraw();
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 720, 800, 1080, 960))//���ѡ����
		{
			get_achievement(all_good_tool[event][2].sp);
			get_achievement(all_bad_tool[event][2].sp);
			level++;
			if (all_good_tool[event][2].name != "\0")//���Ϸ�һ��
			{
			//	bag.gt[bag_gt++] = all_good_tool[event][2];
				life_and_shield_change(all_good_tool[event][2].life, Event[event].life[2], all_good_tool[event][2].shield, Event[event].shield[2]);
				power_change(all_good_tool[event][2].power, Event[event].power[2]);
				smart_change(all_good_tool[event][2].smart, Event[event].smart[2]);
				speed_change(all_good_tool[event][2].speed, Event[event].speed[2]);
			}
			else if (all_bad_tool[event][2].name != "\0")
			{
			//	bag.bt[bag_bt++] = all_bad_tool[event][2];
				life_and_shield_change(all_bad_tool[event][2].life, Event[event].life[2], all_bad_tool[event][2].shield, Event[event].shield[2]);
				power_change(all_bad_tool[event][2].power, Event[event].power[2]);
				smart_change(all_bad_tool[event][2].smart, Event[event].smart[2]);
				speed_change(all_bad_tool[event][2].speed, Event[event].speed[2]);
			}
			while(1)
			{
				settextcolor(BLACK);
				drawtext(Event[event].after_info_three, &r, DT_WORDBREAK);
				show_change(event, 2);
				drawtext("���������һ��", &next, DT_WORDBREAK);
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 850, 600, 1030, 800))
				{
					interlude_photo();//���ù�������
					break;
				}
				FlushBatchDraw();
			}
		}
		else
		{
			drawtext(Event[event].info, &r, DT_WORDBREAK);//�������RECT�ľ�������д�¼����Զ�����
			drawtext(Event[event].choose_one, &one, DT_WORDBREAK);
			drawtext(Event[event].choose_two, &two, DT_WORDBREAK);
			drawtext(Event[event].choose_three, &three, DT_WORDBREAK);
		}
		msg.message = 0;
		EndBatchDraw();
	}
}


/*
	�����ˣ�
	���ܣ�
		չʾ��������
	���� void
	����ֵ void
*/
void show_player()
{
	char player_attribute[10];
	int_to_string(life, player_attribute);
	settextstyle(30, 0, "��������");
	outtextxy(850, 150, "����ֵ��");
	outtextxy(850 + textwidth("����ֵ��"), 150, player_attribute);
	int_to_string(shield, player_attribute);
	outtextxy(850, 250, "����ֵ��");
	outtextxy(850 + textwidth("����ֵ��"), 250, player_attribute);
	int_to_string(power, player_attribute);
	outtextxy(850, 350, "����ֵ��");
	outtextxy(850 + textwidth("����ֵ��"), 350, player_attribute);
	int_to_string(smart, player_attribute);
	outtextxy(850, 450, "����ֵ��");
	outtextxy(850 + textwidth("����ֵ��"), 450, player_attribute);
	int_to_string(speed, player_attribute);
	outtextxy(850, 550, "����ֵ��");
	outtextxy(850 + textwidth("����ֵ��"), 550, player_attribute);
}
/*

	�����ˣ�
	���ܣ�
		չʾ�¼��͵��ߵ�����ֵ
	������int,int
	����ֵ��void
*/
void show_change(int event,int i)
{
	char arr[10];
	//�¼��仯ֵ,��ѡ�������չʾ
	int_to_string(Event[event].life[i], arr);
	outtextxy(360, 760, Event[event].name);
	outtextxy(360, 800, "����ֵ��");
	outtextxy(360 + textwidth("����ֵ��"), 800, arr);
	int_to_string(Event[event].shield[i], arr);
	outtextxy(360, 830, "����ֵ��");
	outtextxy(360 + textwidth("����ֵ��"), 830, arr);
	int_to_string(Event[event].power[i], arr);
	outtextxy(360, 860, "����ֵ��");
	outtextxy(360 + textwidth("����ֵ��"), 860, arr);
	int_to_string(Event[event].smart[i], arr);
	outtextxy(360, 890, "����ֵ��");
	outtextxy(360 + textwidth("����ֵ��"), 890, arr);
	int_to_string(Event[event].speed[i], arr);
	outtextxy(360, 920, "�ٶ�ֵ��");
	outtextxy(360 + textwidth("�ٶ�ֵ��"), 920, arr);
	//������߱仯ֵ����ѡ������һչʾ
	putimage(0, 800, &(good_tool[event][i]));
	outtextxy(0, 760,all_good_tool[event][i].name);
	int_to_string(all_good_tool[event][i].life, arr);
	outtextxy(100, 800, "����ֵ��");
	outtextxy(100 + textwidth("����ֵ��"), 800, arr);
	int_to_string(all_good_tool[event][i].shield, arr);
	outtextxy(100, 830, "����ֵ��");
	outtextxy(100 + textwidth("����ֵ��"), 830, arr);
	int_to_string(all_good_tool[event][i].power, arr);
	outtextxy(100, 860, "����ֵ��");
	outtextxy(100 + textwidth("����ֵ��"), 860, arr);
	int_to_string(all_good_tool[event][i].smart, arr);
	outtextxy(100, 890, "����ֵ��");
	outtextxy(100 + textwidth("����ֵ��"), 890, arr);
	int_to_string(all_good_tool[event][i].speed, arr);
	outtextxy(100, 920, "�ٶ�ֵ��");
	outtextxy(100 + textwidth("�ٶ�ֵ��"), 920, arr);
	//������߱仯ֵ����ѡ��������չʾ
	putimage(620, 700, &(bad_tool[event][i]));
	outtextxy(720, 760, all_bad_tool[event][i].name);
	int_to_string(all_bad_tool[event][i].life, arr);
	outtextxy(720, 800, "����ֵ��");
	outtextxy(720 + textwidth("����ֵ��"), 800, arr);
	int_to_string(all_bad_tool[event][i].shield, arr);
	outtextxy(720, 830, "����ֵ��");
	outtextxy(720 + textwidth("����ֵ��"), 830, arr);
	int_to_string(all_bad_tool[event][i].power, arr);
	outtextxy(720, 860, "����ֵ��");
	outtextxy(720 + textwidth("����ֵ��"), 860, arr);
	int_to_string(all_bad_tool[event][i].smart, arr);
	outtextxy(720, 890, "����ֵ��");
	outtextxy(720 + textwidth("����ֵ��"), 890, arr);
	int_to_string(all_bad_tool[event][i].speed, arr);
	outtextxy(720, 920, "�ٶ�ֵ��");
	outtextxy(720 + textwidth("�ٶ�ֵ��"), 920, arr);
	
}
//----------------------------view--------------------------
//----------------------------service-------------------------------------

/*
 �����ˣ�
 ���ܣ�
   �ж���Ϸ�Ƿ����
   �Ƿ�ͨ��or�Ƿ���������ͨ��ʱ����ֵС��0��ʧ�ܣ�
 ������void
 ����ֵ��0��ʾû�н�����Ϸ��1����ʤ��������ʧ��

*/
int If_End_Game()
{
	if (level == 7)
	{
		if (life > 0)
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
   �����ˣ�
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
 �����ˣ�
 ���ܣ�
   ���������ȡ�¼���Ŀǰ�趨36�����飩
 ������void
 ����ֵ���¼����
*/
int choose_event()//ѡ���¼�
{
	srand((unsigned)time(NULL));
	int event = rand() % 8;//%�������Ըı䣬���������ж��ٸ�����͸ı�ɶ���
	if (judge_event(event))
		level_arr[level] = event;
	else
	{
		choose_event();
	}
	return event;
}

/*
 �����ˣ�
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
	for (int i = 0; i < 10; i++)
	{
		level_arr[i] = -1;
	}
	bag_gt = 0;
	bag_bt = 0;
	for (int i = 0; i < 16; i++)
	{
		bag.gt[i] = { 0 };
		bag.gt[i] = { 0 };
	}
}

/*
  �����ˣ�
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
  �����ˣ�
  ���ܣ�
	�����ڸ��¼�����ҵ�����ֵ���¼���ʹ������Ըı䣩
	������ֵС��0��0��
  ��������������ֵ�ӳ�/���� tool_power���¼�����ֵevent_power
  ����ֵ��
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
  ����ֵ��
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

void load_photo()
{
	loadimage(&guochang_photo, "photos/��������.jpg");
	int i = 0;

	//�¼�ͼƬ���¼���Ӧ����ͼƬ
	loadimage(&good_tool[i][0], "");//0
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//1
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "TOOL_PHOTO/�¼���ѡ��һ����.jpg",100,100);//2
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&bad_tool[i][0], "");
	loadimage(&bad_tool[i][1], "TOOL_PHOTO/�¼���ѡ���ͼƬ.jpg",100,100);
	loadimage(&bad_tool[i][2], "");
	loadimage(&Event_photo[i++], "EVENT_PHOTO/�¼���.jpg",1080,960);

	loadimage(&good_tool[i][0], "");//3
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//4
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//5
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//6
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//7
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//8
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//9
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//10
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//11
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//12
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//13
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//14
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//15
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//16
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//17
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//18
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//19
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//20
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//21
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//22
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//23
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//24
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//25
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//26
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//27
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//28
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//29
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//30
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//31
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//32
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//33
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//34
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//35
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");
}