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
	//判断按钮是否被点击

}
void tanchuchuangkou()
{
	int c = 0;
	printf("c=%d", c++);
	cleardevice();
	settextstyle(40, 0, "微软雅黑");
	setfillcolor(RGB(3, 37, 255));
	button_1(80, 100, 400, 500,"");
	outtextxy(100, 150, "退出游戏");
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
	//判断按钮是否被点击
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h))
	{
		return true;
	}
	return false;
}
void interlude_photo()
{
	/*
	1.放一个衔接两个事件的过场图片（柯南的那个就不错）
	2.随意点击就进入下一关
	*/
}
void game_event_display(struct Event* p)
{
	/*
	1.在固定的位置展示事件背景剧情
	2.在固定的位置展示事件选项
	3.判断玩家选项触发不同（或相同）的后续剧情
	4.显示相应事件选项的道具名和它的属性和显示事件后续选项加减的属性
	5.进行life_change和sanwei_change这两个函数
	*/
}
void attribute_change(int tool, int event)
{
	/*
		1.1判断道具和事件扣除属性是否大于相应属性
			1.1.1若不大于，则直接相减
			1.1.2若大于，令属性归零
		2.若是总和生命值加属性，则直接加属性
	*/
}
void life_change(int tool_life,int event_life)
{
	/*
		0.将道具生命值和事件生命值相加，得到总和生命值
		1.判断总和生命值是扣血还是加血
			1.0如果是扣血判断是否有道具来免除此次伤害
			1.1判断道具和事件扣除血量是否大于血量和护盾值总和			
				1.1.1若不大于，则先判断是否有道具扣除护盾值，优先扣除护盾值，当护盾值为0时，再扣除生命值
				1.1.2若大于，判断是否有道具复活，如果没有则令生命值为0，如果有，则先令生命值为0，sleep 1-3秒，再触发道具效果，恢复生命值至道具所制定的生命值
		 		1.1.3若没有道具复活，则令生命值为0,插入一次If_End_Game();
		2.若是总和生命值加血，则直接加血
		
	*/
}
void Bag_view()
{
	/*
	
		1.展示背包界面（椭圆矩形）
		2.下方会有格子放置本局中已拥有的道具
		3.点击道具会在上方展示道具的详细属性和道具的信息
		4.退出可退回游戏界面
	*/
}
void Win_View()
{
	/*
		1.打印胜利游戏界面
		2.随意点击就返回到主菜单
	*/
	//用图片代表胜利，点击一下返回
	loadimage(&p, "assets/hui.jpg");
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &p);
		cleardevice();
		settextstyle(40, 0, "楷体");
		outtextxy(460, 680, "随意点击返回到主页面");
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
		1.打印失败游戏界面	
		2.随意点击就返回到主菜单
	*/
	loadimage(&p, "assets/hui.jpg");
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &p);
		cleardevice();
		settextstyle(40, 0, "楷体");
		outtextxy(460, 680, "随意点击返回到主页面");
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
		1.判断level是否为7
			若为7则判断当前生命值是否为0；若为零则进入失败界面，若大于0则进入胜利界面
		2.若level不为7，则判断当前生命是否为0，若为零则进入失败界面，若不为零则继续游戏
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
bool judge_event(int event)//判断事件是否已经选择过了
{
	for (int i = 0; i < level; i++)
	{
		if (level_arr[i] == event)
			return false;
	}
	return true;
}
int choose_event()//选择事件
{
	srand((unsigned)time(NULL));
	int event = rand() % 20;//%的数可以改变，根据我们有多少个剧情就改变成多少
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
	初始化生命，护盾值，三维属性
	*/
}
void shengbianview() 
{
	/*
	1.判断level是否为0
	若为0，进行Init_attribute()函数
	2.判断If_End_Game
	3.进行choose_event
	4.显示当前的第几关(用level去显示就行了)(最开始（也就是第0关）是选择三个道具进入梦境，所以第0关要写成 楔子 或者 起始 )
	4.进行game_event_display
	5.进行life_change和三次attribute_change分别改变power，smart，speed
	6.进行interlude_photo()过场图片，衔接关卡。
	*/
	If_End_Game();
	{		
	}
	int event=choose_event();
	//后面调用相应的事件结构体数组和图片数组即可，我这里没有相应的东西就没写
	//用一个函数去缓存图片和IMAGE的图片结构体数组 ，一张图片对应一个IMAGE的下标这里我们直接调用
	//putimage(&img[event],0,0);
	//事件的调用用事件结构体对应下标调用，事件结构体包括事件名、事件内容、三个选项、每个选项后的剧情、事件获得的道具
	// Event[event];
	//上面两行是调用
	//后续想法，空drawtext和RECT框出事件背景范围，和每个选项的选项范围，右边显示玩家属性，左边显示背包，用if是否点击去判断是否进入背包画面
	//
}
void danyiqizimodeview() {}void canjuview() {}
void gameview()
{
	int b = 0;
	setbkcolor(RGB(230, 231, 232));
	loadimage(&p, "assets/QQ图片20240510152709.jpg",1080,960);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &p);
		peekmessage(&msg, EX_MOUSE);
		settextstyle(40, 0, "微软雅黑");
		setbkmode(TRANSPARENT);
		if (button(900, 250, 150, 70, "经典模式"))
		{
			printf("b=%d\n", b++);
			//chengjiutanchu(p);
			int c = 0;
			printf("c=%d", c++);
			
			settextstyle(40, 0, "微软雅黑");
			setfillcolor(RGB(3, 37, 255));
			cleardevice();
			putimage(0, 0, &p);
			button_1(500, 100, 600, 120, "");
			outtextxy(500, 100, "退出游戏");
			FlushBatchDraw();
			Sleep(1000);
			clearrectangle(400, 100, 600, 200);
			putimage(0, 0, &p);
			
		}
		else if (button(900, 450, 150, 70, "升变模式"))
		{
			shengbianview();
		}
		else if (button(900, 600, 250, 70, "单一棋子模式"))
		{
			danyiqizimodeview();
		}
		else if (button(900, 750, 150, 70, "残局模式"))
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
		settextstyle(40, 0, "微软雅黑");
		setbkmode(TRANSPARENT);
		
		button_1(1080 / 2, 100, 150, 70, "象棋");
		if (button(900, 250, 150, 70, "开始游戏"))
		{
			printf("a=%d\n", a++);
			gameview();
		}
		else if (button(900, 400, 150, 70, "相关设置"))
		{
			setview();
		}
		else if (button(900, 550, 150, 70, "开发团队"))
		{
			teamview();
		}
		else if (button(900, 700, 150, 70, "游戏帮助"))
		{
			gamehelpview();
		}
		msg.message = 0;
		EndBatchDraw();
		
	}
	return 0;
}

//定义结构体变量
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
//	//绘制按钮
//	
//	fillroundrect(x, y, x + w, y + h, 5, 5);
//	//绘制按钮文本
//	int hSpace = (w - textwidth(text)) / 2;
//	int vSpace = (h - textheight(text)) / 2;
//	settextcolor(BROWN);
//	outtextxy(x + hSpace, y + vSpace, text);
//	//判断按钮是否被点击
//	if (msg.message==WM_LBUTTONDOWN && inArea(msg.x, msg.y, x, y, w, h))
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	//播放音乐 m media c control i interface
//	mciSendString("open assets\\M500002Zzstc2j8y6Q.mp3 alias music", NULL, 0, NULL);
//	mciSendString("play music", NULL, 0, NULL);
//	//如果失败返回非零值，成功返回0
//	char a[100];
//	MCIERROR ret=mciSendString("status music volume", a, 100, 0);
//	int b = atoi(a);
//	char s[100];
//	sprintf(s, "setaudio music volume to %d", b % 1000 + 200);
//	MCIERROR sum=mciSendString(s, 0, 0, 0);
//	if (sum != 0)
//	{
//		//获取错误信息
//		char err[100];
//		mciGetErrorString(sum, err, sizeof(err));
//		puts(err);
//	}
//	if (ret != 0)
//	{
//		//获取错误信息
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
//	//定义图片变量
//	IMAGE img_mm;
//	//加载图片
//	loadimage(&img_mm,"assets/shou.jpg",1080,960);
//	//绝对路径"D:\\please look svcr\\xiangmu\\c\\easyxtest\\easyxtest\\assets\\shou.jpg"
//	//相对路径"assets/shou.jpg"
//	//输出图片
//	putimage(0, 0, &img_mm);
//
//	//掩码图透明贴图
//	IMAGE img_plane[2];
//	loadimage(img_plane, "assets/planeNormal_1.jpg");
//	loadimage(img_plane+1, "assets/planeNormal_1.jpg");
//	putimage(50, 100, img_plane + 0, NOTSRCERASE);//先绘制掩码图
//	putimage(50, 100, img_plane + 1, SRCINVERT);//再绘制原图
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
//	const clock_t FPS = 1000 / 60;//1000是毫秒。也就是1s60帧=16.6，每一帧应该花费的时间
//	int starttime = 0;
//	int freamtime = 0;//当前帧实际执行时间
//	int score = 0;
//	char str[50] = "";
//	while (true)
//	{
//		starttime = clock();//记录开始运行时的时间 假设为50ms
//		BeginBatchDraw();
//		sprintf(str, "score:%d", score++);
//		settextcolor(BLACK);
//		
//		cleardevice();
//		outtextxy(20, 20, str);
//
//		EndBatchDraw();
//		
//		freamtime = clock() - starttime;//上述功能所运行的时间，假设为6，因为开始为50，所以结束的时候clock（）=56
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
//	//创建一个图形窗口，宽度*高度
//	initgraph(1080, 960, EX_SHOWCONSOLE |EX_DBLCLKS);
//	//设置窗口背景颜色
//	setbkcolor(RGB(40, 239, 255));
//	//用设置的背景颜色填空窗口
//	cleardevice();
//	//设置背景模式
//	setbkmode(TRANSPARENT);
//	putpixel(50, 50, RED);
//	//设置线条颜色
//	setlinecolor(RED);
//	//设置线条样式(线条，矩形，)
//	setlinestyle(PS_SOLID,3); 
//	line(0, 0, getwidth(), getheight());
//	//绘制一个正矩形
//	rectangle(100, 100, 200, 200);//无填充矩形
//	//设置填充颜色
//	setfillcolor(YELLOW);
//	fillrectangle(205, 205, 305, 305);//填充矩形
//	solidrectangle(310, 310, 415, 415);//无边框矩形
//	//绘制一个圆角矩形
//	roundrect(420, 420, 535, 535, 20,20);
//	
//	//获取消息
//	//while (true)
//	//{
//	//	if (peekmessage(&msg, EX_MOUSE))
//	//	{
//	//		switch (msg.message)
//	//		{
//	//		case WM_LBUTTONDOWN://左键按下
//	//			printf("左键按下 pos(%d,%d)\n",msg.x,msg.y);
//	//			break;
//	//		case WM_RBUTTONDOWN://右键按下
//	//			printf("右键按下\n");
//	//			break;
//	//		case WM_MBUTTONDOWN://中键按下
//	//			printf("中键按下\n");
//	//			break;
//	//		case WM_MOUSEWHEEL://滚轮滚动	120是朝向屏幕滚动 -120是朝向自己滚动
//	//			printf("滚轮滚动 dir(%d)\n",msg.wheel);
//	//			break; 
//	//		case WM_LBUTTONDBLCLK://左键双击
//	//			printf("左键双击\n");
//	//			break;
//	//		//case WM_MOUSEMOVE://鼠标移动
//	//			//printf("鼠标移动\n");
//
//	//		}
//	//	}
//	//}
//	//定义小球属性
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
//		//所有的绘图代码必须放在begin和end之间
//		BeginBatchDraw();
//		cleardevice();
//		if (button(20, 20, 150, 35, "Start Game"))
//		{
//			printf("Start Game,%d\n",i++);
//		}
//		
//		//判断按键消息
//		if (msg.message == WM_KEYDOWN)
//		{
//			printf("keydown\n");
//			//具体判断是那个键按下
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
//			case 'A'://对于字母按键必须是大写。小写不识别
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
//			case 'A'://对于字母按键必须是大写。小写不识别
//				break;
//			}
//			printf("keyup\n");
//		}
//		//绘制小球
//		setfillcolor(RGB(0, 108, 190));
//		solidcircle(x, y, r);
//		//更新小球位置
//		x += speed * vx;
//		y += speed * vy;
//		EndBatchDraw();
//		Sleep(10);
//		//把消息类型设置为0
//		msg.message = 0;
//	}
//
//	//防止程序退出
//	getchar();
//	return 0;
//}