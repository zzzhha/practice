#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>

IMAGE photo;//图片
FILE* fp;
ExMessage msg;
struct Achiebement
{
	int sp;//正数
	char name[10];
	char text[100];
	int flag;//0代表未完成，1代表已完成
}achievement[64];
bool inArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx<x + w && my>y && my < y + h)
		return true;
	else
		return false;
}
void button(int x, int y, int w, int h)
{
	if (msg.x > x && msg.x<x + w && msg.y>y && msg.y < y + h)
	{
		setfillcolor(RGB(229, 171, 166));
	}
	else
	{
		setfillcolor(RGB(66, 82, 146));
	}
	fillroundrect(x , y , x  + w, y  + h, 30, 30);

}
void achieve_get()
{
	int i=0;
	achievement[i++] = { 1,"入梦","一场持久未能结束的梦，为你而展开",0 };
	achievement[i++] = { 2,"金酒之杯","酒杯中的就似乎无穷无尽，根本喝不完，而你沉醉其中无法自拔，扣除血量一佰，去问啊行者常至手打",0 };
	achievement[i++] = { 3,"xxx","xxx",0 };
	achievement[i++] = { 4,"xxx","xxx",0 };
	achievement[i++] = { 5,"xxx","xxx",0 };
	achievement[i++] = { 6,"xxx","xxx",0 };
	achievement[i++] = { 7,"xxx","xxx",0 };
	achievement[i++] = { 8,"xxx","xxx",0 };
	achievement[i++] = { 9,"xxx","xxx",0 };
	achievement[i++] = { 10,"xxx","xxx",0 };
	achievement[i++] = { 11,"xxx","xxx",0 };
	achievement[i++] = { 12,"xxx","xxx",0 };
	achievement[i++] = { 13,"xxx","xxx",0 };
	achievement[i++] = { 14,"xxx","xxx",0 };
	achievement[i++] = { 15,"xxx","xxx",0 };
	achievement[i++] = { 16,"xxx","xxx",0 };
	achievement[i++] = { 17,"xxx","xxx",0 };
	achievement[i++] = { 18,"xxx","xxx",0 };
	achievement[i++] = { 19,"xxx","xxx",0 };
	achievement[i++] = { 20,"xxx","xxx",0 };
	achievement[i++] = { 21,"xxx","xxx",0 };
	achievement[i++] = { 22,"xxx","xxx",0 };
	achievement[i++] = { 23,"xxx","xxx",0 };
	achievement[i++] = { 24,"xxx","xxx",0 };
	achievement[i++] = { 25,"xxx","xxx",0 };
	achievement[i++] = { 26,"xxx","xxx",0 };
	achievement[i++] = { 27,"xxx","xxx",0 };
	achievement[i++] = { 28,"xxx","xxx",0 };
	achievement[i++] = { 29,"xxx","xxx",0 };
	achievement[i++] = { 30,"xxx","xxx",0 };
	achievement[i++] = { 31,"xxx","xxx",0 };
	achievement[i++] = { 32,"xxx","xxx",0 };
	achievement[i++] = { 33,"xxx","xxx",0 };
	achievement[i++] = { 34,"xxx","xxx",0 };
	achievement[i++] = { 35,"xxx","xxx",0 };
	achievement[i++] = { 36,"xxx","xxx",0 };
	achievement[i++] = { 37,"xxx","xxx",0 };
	achievement[i++] = { 38,"xxx","xxx",0 };
}
void store_achieve()
{
	fp = fopen("achieve.txt", "w");
	for(int i=0;i<2;i++)
	{
		fprintf(fp, "SP: %d\n", achievement[i].sp);
		fprintf(fp, "Name: %s\n", achievement[i].name);
		fprintf(fp, "Text: %s\n", achievement[i].text);
		fprintf(fp, "Flag: %d\n", achievement[i].flag);
	}
}

void get_achievement(int a)
{
	for (int i = 0; i < 2; i++)
	{
		if (a == achievement[i].sp)
		{
			if (!achievement[i].flag)
			{
				achievement[i].flag = 1;
				store_achieve();
			}
		}
	}
}
void file_achieve_get()
{
	fp = fopen("achieve.txt", "r");
	if(fp==NULL)
	{
		return;
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			fscanf(fp, "SP: %d\n \
					Name: %s\n \
					Text: %s\n \
					Flag: %d\n",
				&achievement[i].sp, achievement[i].name, achievement[i].text, &achievement[i].flag);
		}
	}
	
}
void int_to_string(int number, char* str) {
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
void print_achievement()
{
	loadimage(&photo, "assets/hui.jpg", 1080, 960);
	while (1)
	{
		cleardevice();
		putimage(0, 0, &photo);
		peekmessage(&msg, EX_MOUSE);
		settextstyle(40, 0, "微软雅黑");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(0, 0, 255));
		fillrectangle(1080 / 2 - 100, 10, 1080 / 2 + 100, 80);
		for (int i = 0; i < 6;)
		{
			BeginBatchDraw();
			peekmessage(&msg, EX_MOUSE);
			putimage(0, 0, &photo);
			fillrectangle(50, 90, 1050, 930);
			for (int j = 0; j < 6; j++)
			{
				setfillcolor(RGB(0, 108, 190));
				setlinestyle(PS_SOLID, 3);
				setlinecolor(RGB(138, 27, 255));
				fillrectangle(100, (j + 1) * 120, 950, ((j + 1) * 120) + 90);//x轴长850，y轴长90，图片假定70*70
				settextstyle(40, 0, "华文琥珀");
				char arr[12] = { 0 };
				int_to_string(achievement[(i * 6) + j].sp, arr);
				outtextxy(100 + 100, (j + 1) * 120, arr);
				outtextxy(100+145, (j + 1) * 120, achievement[(i * 6) + j].name);
				settextstyle(25, 0, "微软雅黑");
				RECT text1{ 100 + 310, (j + 1) * 120 ,950, ((j + 1) * 120) + 90 };
				drawtext(achievement[(i * 6) + j].text, &text1, DT_WORDBREAK);
				outtextxy(100+120, (j + 1) * 120+50, achievement[(i * 6) + j].flag ? "已完成" : "未完成");	
			}
			setlinestyle(PS_SOLID, 1);
			peekmessage(&msg, EX_MOUSE);
			if (i == 0)
			{
				fillrectangle(650, 850, 800, 910);
			}
			else if (i == 5)
			{
				fillrectangle(250, 850, 400, 910);
			}
			else
			{
				fillrectangle(250, 850, 400, 910);
				fillrectangle(650, 850, 800, 910);
			}
			if (inArea(msg.x, msg.y, 650, 850, 800, 910) && i < 5)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 650, 850, 800, 910))
				{
					i++;
				}
			}
			if (inArea(msg.x, msg.y, 250, 850, 400, 910) && i > 0)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 250, 850, 400, 910))
				{
					i--;
				}
			}
			msg.message = 0;
			EndBatchDraw();
		}
	}
}
int main()
{
		initgraph(1080, 960);
		
		cleardevice();
		achieve_get();
		file_achieve_get();
		store_achieve();
		get_achievement(0);//这四个函数就可以完成成就系统的读取和记录
		print_achievement();
		getchar();
	return 0;
}




//for (int i = 0; i < 6;)
		//{
//for (int j = 0; j < 6; j++)
//{
//	//putimage(0, 0, &photo);
//	setfillcolor(RGB(0, 108, 190));
//	fillrectangle(100, (j + 1) * 120, 950, ((j + 1) * 120) + 90);
//	/*printf("SP: %d\n", achievement[(i*6)+j].sp);
//	printf("Name: %s\n", achievement[(i*6)+j].name);
//	printf("Text: %s\n", achievement[(i*6)+j].text);
//	printf("Flag: %s\n", achievement[(i*6)+j].flag ? "已完成" : "未完成");*/
//
//}
//if (i == 0)
//{
//	fillrectangle(650, 850, 800, 910);
//}
//else if (i == 6)
//{
//	fillrectangle(250, 850, 400, 910);
//}
//else 
//{
//	fillrectangle(250, 850, 400, 910);
//	fillrectangle(650, 850, 800, 910);
//}
//if (inArea(msg.x, msg.y, 700, 850, 850, 910) && i != 6)
/*{
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 700, 850, 850, 910))
	{
		i++;
	}
}
if (inArea(msg.x, msg.y, 250, 850, 400, 910) && i != 0)
{
	if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 250, 850, 400, 910))
	{
		i--;
	}
}*/
//msg.message=0;
//}