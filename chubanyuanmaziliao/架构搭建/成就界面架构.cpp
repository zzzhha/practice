#define  _CRT_SECURE_NO_WARNINGS 1
#include"梦境逃离.h"
Achievement achievement[36];
extern ExMessage msg;
IMAGE achieve_photo;
extern int flag;
int symbol = 0;
FILE* fp;
//-----------------------数据设计-----------------------
//-----------------------service-----------------------
/*
	负责人: 空白
    功能: 
        列出游戏中的所有成就信息
    参数: void
    返回值: void
*/
void achieve_get()//成就获取
{
	int i = 0;
	achievement[i++] = { 0,"蒙多！","蒙多！想去哪就去哪",0 };
	achievement[i++] = { 1,"给爷爬！","网络上的经典用词，但你竟然会用在自己身上？不得不说，躲陷阱给爷爬还是很聪慧的！",0 };
	achievement[i++] = { 2,"D32钢战士","这个物品怎么与说话的那个人如此相似，她们究竟是什么关系。",0 };
	achievement[i++] = { 3,"亲情告诫","来自已故亲人的告诫，是恶作剧，还是真的？",0 };
	achievement[i++] = { 4,"早晚，我会","迟早有一天，我会...",0 };
	achievement[i++] = { 5,"破坏与创造","破坏，是为了更伟大的创造",0 };
	achievement[i++] = { 6,"复活！","复活吧！我的爱人！（笑）",0 };
	achievement[i++] = { 7,"败者食尘","killer Queen！输的吃土！",0 };
	achievement[i++] = { 8,"入梦","是梦？还是······",0 };
	achievement[i++] = { 9,"无尽等待","失去了机会的你还在等待什么？你不知道，然而你更怕前面的悬崖让你万劫不复！",0 };
	achievement[i++] = { 10,"体育生","幸好我是体育生，进过沉淀后就恢复了",0 };
	achievement[i++] = { 11,"未知前路","你将去哪？将面对何事？将做什么？",0 };
	achievement[i++] = { 12,"道德赞许","你的道德值得人仰敬",0 };
	achievement[i++] = { 13,"小猫老弟","喜欢吗？老弟",0 };
	achievement[i++] = { 14,"黑熊的晚餐","在一头饥饿的黑熊面前，你竟然选择装死？你这不是给别人当快递员送餐去了吗？",0 };
	achievement[i++] = { 15,"黑熊玩弄者","你不仅嚣张的挑衅了它，还将它戏弄了一番，它一定会记住你的！",0 };
	achievement[i++] = { 16,"深海探险家","没有人能比我更懂深海探险！",0 };
	achievement[i++] = { 17,"云中解谜者","浮起来的是云，还是这片水晶呢？",0 };
	achievement[i++] = { 18,"记忆的永恒","时钟在滴滴答答响着，可流过的时间却在你的记忆永恒",0 };
	achievement[i++] = { 19,"前进4！","自然选择，前进四！",0 };
	achievement[i++] = { 20,"战地风云","小子，欢迎来到快乐洞！",0 };
	achievement[i++] = { 21,"进攻D点","进攻A点，不！进攻B点，不！进攻C点，不！进攻D点，好！",0 };
	achievement[i++] = { 22,"别无选择","你还幻想上了，还真让你选起来了？",0 };
	achievement[i++] = { 23,"大爱仙尊","大爱仙尊",0 };
	achievement[i++] = { 24,"飞毛腿","很快的跑嗷",0 };
	achievement[i++] = { 25,"军方还是暴徒","末世中，所谓军方和暴徒的区别就是有无纪律而已",0 };
	achievement[i++] = { 26,"笑口常开","无欲无求，笑口常开",0 };
	achievement[i++] = { 27,"守法公民","你对有人即将实施犯罪憎恶不已，即使是在梦境中你也是个遵纪守法的好公民！",0 };
	achievement[i++] = { 28,"暂未有成就","这是为什么呢？肯定是游戏开发者偷懒了！",1 };
	achievement[i++] = { 29,"别看了","真的没有成就了，别看了",1 };
}
/*
    负责人:空白
    功能:
       将成就更新到txt文件中
    参数: void
    返回值: void
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
    负责人:空白
    功能:
       //从txt文件中读取更新成就是否完成
    参数: void
    返回值: void
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
    负责人:空白
    功能:
       将字符串里的数字字符转换成int类型数字
      参数: int:需要改变的数字，char*存储数字字符的字符串
    返回值: void
*/
void int_to_string(int number, char* str)
{
	int index = 0;
	// 逆序构建字符串（从最低位开始）  
	do {
		str[index++] = '0' + (number % 10);
		number /= 10;
	} while (number > 0);
	// 添加字符串结束符  
	str[index] = '\0';
	// 反转字符串以得到正确的顺序  
	for (int i = 0; i < index / 2; i++) {
		char temp = str[i];
		str[i] = str[index - i - 1];
		str[index - i - 1] = temp;
	}
}
//---------------------------service--------------------------
//--------------------------view--------------------------------------
/*
    负责人:空白
    功能:
       若完成有一个新的成就，则弹窗提示，
       改变成就为已完成
    参数: int:道具的sp值，IMAGE:成就的图像
    返回值: void
*/
void get_achievement(int sp)//若完成有一个新的成就，则弹窗提示，然后改变成就为已完成
//第一个参数是道具的sp值
{
	for (int i = 0; i < 30; i++)
	{
		if (sp == achievement[i].sp)
		{
			if (achievement[i].flag == 0)
			{
				achievement[i].flag = 1;
				store_achieve();
				settextstyle(40, 0, "微软雅黑");
				setlinestyle(PS_SOLID, 5);
				setlinecolor(RGB(138, 27, 255));
				fillrectangle(500, 50, 800, 100);
				setfillcolor(WHITE);
				button_nomsg(500, 50, "获得成就！");
				button_nomsg(500 + textwidth("获得成就!"), 50, achievement[i].name);
				FlushBatchDraw();
			}
		}
	}
}
/*
    负责人:空白
    功能:
      打印成就系统的界面
    参数:void
    返回值: void
*/
void print_achievement()
{
	while (1)
	{
		putimage(0, 0, &achieve_photo);
		setbkmode(TRANSPARENT);
		for (int i = 0; i < 5;)
		{
			settextstyle(60, 0, "华文琥珀");
			outtextxy(500, 50, "成就");
			outtextxy(950, 10, "退出");
			for (int j = 0; j < 6; j++)
			{
				setfillcolor(RGB(186, 127, 245));
				settextcolor(WHITE);
				setlinestyle(PS_SOLID, 3);
				setlinecolor(RGB(138, 27, 255));
				fillrectangle(100, (j + 1) * 120, 950, ((j + 1) * 120) + 90);//x轴长850，y轴长90，图片假定70*70
				settextstyle(40, 0, "华文琥珀");
				char arr[12] = { 0 };
				int_to_string(achievement[(i * 6) + j].sp, arr);
				outtextxy(100 + 100, (j + 1) * 120, arr);
				outtextxy(100 + 145, (j + 1) * 120, achievement[(i * 6) + j].name);
				settextstyle(25, 0, "微软雅黑");
				RECT text1 = { 100 + 350, (j + 1) * 120 ,950, ((j + 1) * 120) + 90 };
				drawtext(achievement[(i * 6) + j].text, &text1, DT_WORDBREAK);
				outtextxy(100 + 120, (j + 1) * 120 + 50, achievement[(i * 6) + j].flag ? "已完成" : "未完成");
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
			outtextxy(300, 870, "上一页");
			outtextxy(700, 870, "下一页");
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
    负责人:空白
    功能:
      1、统合上述功能
      2、读取用户操作，返回菜单
     参数:void
    返回值: void
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
