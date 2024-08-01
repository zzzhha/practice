#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<Windows.h>
#include<mmsystem.h>
#include< conio.h> 
#include<stdlib.h>
#pragma comment(lib,"winmm.lib")


ExMessage msg = { 0 };
IMAGE p;
int level;
int life=100;
int level_arr[20];
bool inArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx<x + w && my>y && my < y + h)
		return true;
	else
		return false;
}
void button_1(int x, int y, int w, int h, const char* text)
{
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	setfillcolor(RGB(255, 255, 85));
	fillroundrect(x - hSpace, y - vSpace, x - hSpace + w, y - vSpace + h, 20, 20);
	settextcolor(BROWN);
	outtextxy(x, y, text);
	//�жϰ�ť�Ƿ񱻵��

}
void tanchuchuangkou()
{
	int c = 0;
	printf("c=%d", c++);
	cleardevice();
	settextstyle(40, 0, "΢���ź�");
	setfillcolor(RGB(3, 37, 255));
	button_1(80, 100, 400, 500,"");
	outtextxy(100, 150, "�˳���Ϸ");
}
void guanbichuangkou(IMAGE img)
{
	//putimage(0, 0, &img);
}
void chengjiutanchu(IMAGE img)
{
	tanchuchuangkou();
	Sleep(300);
	guanbichuangkou(img);
}
bool button(int x, int y, int w, int h, const char* text)
{
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	if (inArea(msg.x, msg.y, x, y, w, h))
	{
		setfillcolor(RGB(204, 206, 219));
	}
	else
	{
		setfillcolor(RGB(255, 255, 85));
	}
	fillroundrect(x - hSpace, y - vSpace, x - hSpace + w, y - vSpace + h, 20, 20);
	settextcolor(BROWN);
	outtextxy(x, y, text);
	//�жϰ�ť�Ƿ񱻵��
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h))
	{
		return true;
	}
	return false;
}
void interlude_photo()
{
	/*
	1.��һ���ν������¼��Ĺ���ͼƬ�����ϵ��Ǹ��Ͳ���
	2.�������ͽ�����һ��
	*/
}
void game_event_display(struct Event* p)
{
	/*
	1.�ڹ̶���λ��չʾ�¼���������
	2.�ڹ̶���λ��չʾ�¼�ѡ��
	3.�ж����ѡ�����ͬ������ͬ���ĺ�������
	4.��ʾ��Ӧ�¼�ѡ��ĵ��������������Ժ���ʾ�¼�����ѡ��Ӽ�������
	5.����life_change��sanwei_change����������
	*/
}
void attribute_change(int tool, int event)
{
	/*
		1.1�жϵ��ߺ��¼��۳������Ƿ������Ӧ����
			1.1.1�������ڣ���ֱ�����
			1.1.2�����ڣ������Թ���
		2.�����ܺ�����ֵ�����ԣ���ֱ�Ӽ�����
	*/
}
void life_change(int tool_life,int event_life)
{
	/*
		0.����������ֵ���¼�����ֵ��ӣ��õ��ܺ�����ֵ
		1.�ж��ܺ�����ֵ�ǿ�Ѫ���Ǽ�Ѫ
			1.0����ǿ�Ѫ�ж��Ƿ��е���������˴��˺�
			1.1�жϵ��ߺ��¼��۳�Ѫ���Ƿ����Ѫ���ͻ���ֵ�ܺ�			
				1.1.1�������ڣ������ж��Ƿ��е��߿۳�����ֵ�����ȿ۳�����ֵ��������ֵΪ0ʱ���ٿ۳�����ֵ
				1.1.2�����ڣ��ж��Ƿ��е��߸�����û����������ֵΪ0������У�����������ֵΪ0��sleep 1-3�룬�ٴ�������Ч�����ָ�����ֵ���������ƶ�������ֵ
		 		1.1.3��û�е��߸����������ֵΪ0,����һ��If_End_Game();
		2.�����ܺ�����ֵ��Ѫ����ֱ�Ӽ�Ѫ
		
	*/
}
void Bag_view()
{
	/*
	
		1.չʾ�������棨��Բ���Σ�
		2.�·����и��ӷ��ñ�������ӵ�еĵ���
		3.������߻����Ϸ�չʾ���ߵ���ϸ���Ժ͵��ߵ���Ϣ
		4.�˳����˻���Ϸ����
	*/
}
void Win_View()
{
	/*
		1.��ӡʤ����Ϸ����
		2.�������ͷ��ص����˵�
	*/
	//��ͼƬ����ʤ�������һ�·���
	loadimage(&p, "assets/hui.jpg");
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &p);
		cleardevice();
		settextstyle(40, 0, "����");
		outtextxy(460, 680, "���������ص���ҳ��");
		if (msg.message == WM_LBUTTONDOWN)
		{
			gameview();
		}
		msg.message = 0;
		EndBatchDraw();
	}
}
void Defeat_View()
{
	/*
		1.��ӡʧ����Ϸ����	
		2.�������ͷ��ص����˵�
	*/
	loadimage(&p, "assets/hui.jpg");
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &p);
		cleardevice();
		settextstyle(40, 0, "����");
		outtextxy(460, 680, "���������ص���ҳ��");
		if (msg.message == WM_LBUTTONDOWN)
		{
			gameview();
		}
		msg.message = 0;
		EndBatchDraw();
	}
}
void If_End_Game()
{
	/*
		1.�ж�level�Ƿ�Ϊ7
			��Ϊ7���жϵ�ǰ����ֵ�Ƿ�Ϊ0����Ϊ�������ʧ�ܽ��棬������0�����ʤ������
		2.��level��Ϊ7�����жϵ�ǰ�����Ƿ�Ϊ0����Ϊ�������ʧ�ܽ��棬����Ϊ���������Ϸ
		*/
	if (level == 7)
	{
		if (life > 0)
		{
			Win_View();
		}
		else
		{
			Defeat_View();
		}
	}
	else
	{
		if (life <= 0)
		{
			Defeat_View();
		}
	}
}
bool judge_event(int event)//�ж��¼��Ƿ��Ѿ�ѡ�����
{
	for (int i = 0; i < level; i++)
	{
		if (level_arr[i] == event)
			return false;
	}
	return true;
}
int choose_event()//ѡ���¼�
{
	srand((unsigned)time(NULL));
	int event = rand() % 20;//%�������Ըı䣬���������ж��ٸ�����͸ı�ɶ���
	if (judge_event(event))
		choose_event();
	else
	{
		level_arr[level] = event;
	}
	return event;
}
void Init_attribute()
{
	/*
	��ʼ������������ֵ����ά����
	*/
}
void shengbianview() 
{
	/*
	1.�ж�level�Ƿ�Ϊ0
	��Ϊ0������Init_attribute()����
	2.�ж�If_End_Game
	3.����choose_event
	4.��ʾ��ǰ�ĵڼ���(��levelȥ��ʾ������)(�ʼ��Ҳ���ǵ�0�أ���ѡ���������߽����ξ������Ե�0��Ҫд�� Ш�� ���� ��ʼ )
	4.����game_event_display
	5.����life_change������attribute_change�ֱ�ı�power��smart��speed
	6.����interlude_photo()����ͼƬ���νӹؿ���
	*/
	If_End_Game();
	{		
	}
	int event=choose_event();
	//���������Ӧ���¼��ṹ�������ͼƬ���鼴�ɣ�������û����Ӧ�Ķ�����ûд
	//��һ������ȥ����ͼƬ��IMAGE��ͼƬ�ṹ������ ��һ��ͼƬ��Ӧһ��IMAGE���±���������ֱ�ӵ���
	//putimage(&img[event],0,0);
	//�¼��ĵ������¼��ṹ���Ӧ�±���ã��¼��ṹ������¼������¼����ݡ�����ѡ�ÿ��ѡ���ľ��顢�¼���õĵ���
	// Event[event];
	//���������ǵ���
	//�����뷨����drawtext��RECT����¼�������Χ����ÿ��ѡ���ѡ�Χ���ұ���ʾ������ԣ������ʾ��������if�Ƿ���ȥ�ж��Ƿ���뱳������
	//
}
void danyiqizimodeview() {}void canjuview() {}
void gameview()
{
	int b = 0;
	setbkcolor(RGB(230, 231, 232));
	loadimage(&p, "assets/QQͼƬ20240510152709.jpg",1080,960);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &p);
		peekmessage(&msg, EX_MOUSE);
		settextstyle(40, 0, "΢���ź�");
		setbkmode(TRANSPARENT);
		if (button(900, 250, 150, 70, "����ģʽ"))
		{
			printf("b=%d\n", b++);
			//chengjiutanchu(p);
			int c = 0;
			printf("c=%d", c++);
			
			settextstyle(40, 0, "΢���ź�");
			setfillcolor(RGB(3, 37, 255));
			cleardevice();
			putimage(0, 0, &p);
			button_1(500, 100, 600, 120, "");
			outtextxy(500, 100, "�˳���Ϸ");
			FlushBatchDraw();
			Sleep(1000);
			clearrectangle(400, 100, 600, 200);
			putimage(0, 0, &p);
			
		}
		else if (button(900, 450, 150, 70, "����ģʽ"))
		{
			shengbianview();
		}
		else if (button(900, 600, 250, 70, "��һ����ģʽ"))
		{
			danyiqizimodeview();
		}
		else if (button(900, 750, 150, 70, "�о�ģʽ"))
		{
			canjuview();
		}
		msg.message = 0;
		EndBatchDraw();
		
	}
}
void setview(){}
void teamview(){}
void gamehelpview(){}
void volume()
{
	int i = 0;
	char a[100];
	while (true)
	{
		char s = getch();
		system("cls");
		if (s == 'w')
		{
			i += 10;
		}
		else if (s == 's')
		{
			i -= 10;
		}
		printf("%d", i);
		sprintf(a, "setaudio music volume to %d", i);
		mciSendString(a, NULL,0, NULL);
	}
}
int main()
{
	initgraph(1080, 960, EX_SHOWCONSOLE);
	setbkcolor(RGB(230, 231, 232));
	cleardevice();
	mciSendString("open assets\\M500002Zzstc2j8y6Q.mp3 alias music", NULL, 0, NULL);
	mciSendString("play music", NULL, 0, NULL);
	volume();
	IMAGE img;
	loadimage(&img, "assets/shou.jpg");
	int a = 0;
	while(1)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &img);
		peekmessage(&msg, EX_MOUSE);
		settextstyle(40, 0, "΢���ź�");
		setbkmode(TRANSPARENT);
		
		button_1(1080 / 2, 100, 150, 70, "����");
		if (button(900, 250, 150, 70, "��ʼ��Ϸ"))
		{
			printf("a=%d\n", a++);
			gameview();
		}
		else if (button(900, 400, 150, 70, "�������"))
		{
			setview();
		}
		else if (button(900, 550, 150, 70, "�����Ŷ�"))
		{
			teamview();
		}
		else if (button(900, 700, 150, 70, "��Ϸ����"))
		{
			gamehelpview();
		}
		msg.message = 0;
		EndBatchDraw();
		
	}
	return 0;
}

//����ṹ�����
//ExMessage msg = { 0 };
//bool inArea(int mx, int my,int x, int y, int w, int h)
//{
//	if (mx > x && mx < x + w && my > y && my < y + h)
//	{
//		return true;
//	}
//	return false;
//}
//bool button(int x, int y, int w, int h,const char* text)
//{
//	if (inArea(msg.x, msg.y, x, y, w, h))
//	{
//		setfillcolor(RGB(93, 107, 157));
//	}
//	else
//		setfillcolor(RGB(230, 231, 232));
//	//���ư�ť
//	
//	fillroundrect(x, y, x + w, y + h, 5, 5);
//	//���ư�ť�ı�
//	int hSpace = (w - textwidth(text)) / 2;
//	int vSpace = (h - textheight(text)) / 2;
//	settextcolor(BROWN);
//	outtextxy(x + hSpace, y + vSpace, text);
//	//�жϰ�ť�Ƿ񱻵��
//	if (msg.message==WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h))
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	//�������� m media c control i interface
//	mciSendString("open assets\\M500002Zzstc2j8y6Q.mp3 alias music", NULL, 0, NULL);
//	mciSendString("play music", NULL, 0, NULL);
//	//���ʧ�ܷ��ط���ֵ���ɹ�����0
//	char a[100];
//	MCIERROR ret=mciSendString("status music volume", a, 100, 0);
//	int b = atoi(a);
//	char s[100];
//	sprintf(s, "setaudio music volume to %d", b % 1000 + 200);
//	MCIERROR sum=mciSendString(s, 0, 0, 0);
//	if (sum != 0)
//	{
//		//��ȡ������Ϣ
//		char err[100];
//		mciGetErrorString(sum, err, sizeof(err));
//		puts(err);
//	}
//	if (ret != 0)
//	{
//		//��ȡ������Ϣ
//		char err[100];
//		mciGetErrorString(ret, err, sizeof(err));
//		puts(err);
//	}
//	
//	getchar();
//	return 0;
//}
//int main()
//{
//	initgraph(1080, 960, EX_SHOWCONSOLE | EX_DBLCLKS);
//	setbkcolor(WHITE/*RGB(194, 195, 201)*/);
//	cleardevice();
//	//setbkmode(TRANSPARENT);
//	//����ͼƬ����
//	IMAGE img_mm;
//	//����ͼƬ
//	loadimage(&img_mm,"assets/shou.jpg",1080,960);
//	//����·��"D:\\please look svcr\\xiangmu\\c\\easyxtest\\easyxtest\\assets\\shou.jpg"
//	//���·��"assets/shou.jpg"
//	//���ͼƬ
//	putimage(0, 0, &img_mm);
//
//	//����ͼ͸����ͼ
//	IMAGE img_plane[2];
//	loadimage(img_plane, "assets/planeNormal_1.jpg");
//	loadimage(img_plane+1, "assets/planeNormal_1.jpg");
//	putimage(50, 100, img_plane + 0, NOTSRCERASE);//�Ȼ�������ͼ
//	putimage(50, 100, img_plane + 1, SRCINVERT);//�ٻ���ԭͼ
//	getchar();
//
//	return 0;
//}
//int main()
//{
//	initgraph(1080, 960, EX_SHOWCONSOLE | EX_DBLCLKS);
//	setbkcolor(RGB(194, 195, 201));
//	cleardevice();
//	setbkmode(TRANSPARENT);
//
//	//FPS 60f
//	const clock_t FPS = 1000 / 60;//1000�Ǻ��롣Ҳ����1s60֡=16.6��ÿһ֡Ӧ�û��ѵ�ʱ��
//	int starttime = 0;
//	int freamtime = 0;//��ǰ֡ʵ��ִ��ʱ��
//	int score = 0;
//	char str[50] = "";
//	while (true)
//	{
//		starttime = clock();//��¼��ʼ����ʱ��ʱ�� ����Ϊ50ms
//		BeginBatchDraw();
//		sprintf(str, "score:%d", score++);
//		settextcolor(BLACK);
//		
//		cleardevice();
//		outtextxy(20, 20, str);
//
//		EndBatchDraw();
//		
//		freamtime = clock() - starttime;//�������������е�ʱ�䣬����Ϊ6����Ϊ��ʼΪ50�����Խ�����ʱ��clock����=56
//		//56-50=6
//		if (freamtime > 0)
//		{
//			Sleep(FPS - freamtime);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	//����һ��ͼ�δ��ڣ����*�߶�
//	initgraph(1080, 960, EX_SHOWCONSOLE |EX_DBLCLKS);
//	//���ô��ڱ�����ɫ
//	setbkcolor(RGB(40, 239, 255));
//	//�����õı�����ɫ��մ���
//	cleardevice();
//	//���ñ���ģʽ
//	setbkmode(TRANSPARENT);
//	putpixel(50, 50, RED);
//	//����������ɫ
//	setlinecolor(RED);
//	//����������ʽ(���������Σ�)
//	setlinestyle(PS_SOLID,3); 
//	line(0, 0, getwidth(), getheight());
//	//����һ��������
//	rectangle(100, 100, 200, 200);//��������
//	//���������ɫ
//	setfillcolor(YELLOW);
//	fillrectangle(205, 205, 305, 305);//������
//	solidrectangle(310, 310, 415, 415);//�ޱ߿����
//	//����һ��Բ�Ǿ���
//	roundrect(420, 420, 535, 535, 20,20);
//	
//	//��ȡ��Ϣ
//	//while (true)
//	//{
//	//	if (peekmessage(&msg, EX_MOUSE))
//	//	{
//	//		switch (msg.message)
//	//		{
//	//		case WM_LBUTTONDOWN://�������
//	//			printf("������� pos(%d,%d)\n",msg.x,msg.y);
//	//			break;
//	//		case WM_RBUTTONDOWN://�Ҽ�����
//	//			printf("�Ҽ�����\n");
//	//			break;
//	//		case WM_MBUTTONDOWN://�м�����
//	//			printf("�м�����\n");
//	//			break;
//	//		case WM_MOUSEWHEEL://���ֹ���	120�ǳ�����Ļ���� -120�ǳ����Լ�����
//	//			printf("���ֹ��� dir(%d)\n",msg.wheel);
//	//			break; 
//	//		case WM_LBUTTONDBLCLK://���˫��
//	//			printf("���˫��\n");
//	//			break;
//	//		//case WM_MOUSEMOVE://����ƶ�
//	//			//printf("����ƶ�\n");
//
//	//		}
//	//	}
//	//}
//	//����С������
//	int x = 50;
//	int y = 50;
//	int r = 30;
//
//	int speed = 3;
//	int vx = 0;
//	int vy = 0;
//	int i = 0;
//	while (true)
//	{
//		if (peekmessage(&msg, EX_MOUSE|EX_KEY))
//		{
//
//		}
//		
//		//���еĻ�ͼ����������begin��end֮��
//		BeginBatchDraw();
//		cleardevice();
//		if (button(20, 20, 150, 35, "Start Game"))
//		{
//			printf("Start Game,%d\n",i++);
//		}
//		
//		//�жϰ�����Ϣ
//		if (msg.message == WM_KEYDOWN)
//		{
//			printf("keydown\n");
//			//�����ж����Ǹ�������
//			switch (msg.vkcode)
//			{
//			case VK_UP:
//				vy=-1;
//				break;
//			case VK_DOWN:
//				vy=1;
//				break;
//			case VK_LEFT:
//				vx=-1;
//				break;
//			case VK_RIGHT:
//				vx=1;
//				break;
//			case 'A'://������ĸ���������Ǵ�д��Сд��ʶ��
//				break;
//			}
//		}
//		else if (msg.message == WM_KEYUP)
//		{
//			switch (msg.vkcode)
//			{
//			case VK_UP:
//				vy = 0;
//				break;
//			case VK_DOWN:
//				vy = 0;
//				break;
//			case VK_LEFT:
//				vx = 0;
//				break;
//			case VK_RIGHT:
//				vx = 0;
//				break;
//			case 'A'://������ĸ���������Ǵ�д��Сд��ʶ��
//				break;
//			}
//			printf("keyup\n");
//		}
//		//����С��
//		setfillcolor(RGB(0, 108, 190));
//		solidcircle(x, y, r);
//		//����С��λ��
//		x += speed * vx;
//		y += speed * vy;
//		EndBatchDraw();
//		Sleep(10);
//		//����Ϣ��������Ϊ0
//		msg.message = 0;
//	}
//
//	//��ֹ�����˳�
//	getchar();
//	return 0;
//}