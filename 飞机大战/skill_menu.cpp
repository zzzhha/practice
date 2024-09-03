#include"skill_menu.h"

extern ExMessage msg;
extern int flag;
const char* weapon_name[8] = { "高燃爆弹","阿姆斯特朗回旋喷气式阿姆斯特朗炮","流汗黄豆","天火圣裁", "w","q","e","r"};
const char* player_skill_name[8] = { "子弹升级","畅通无阻","血手","小小的也很可爱",};
const char* boss_skill_name[8] = { "合金装甲","巨型飞机","妈妈生的","安如磐石",};
const char* tool_name[8] = { "金坷垃","高级发动装置","急救包","流汗黄豆" ,};
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
		settextstyle(60, 0, "华文新魏");
		outtextxy(400, 50, "技能 武器 道具");
		outtextxy(950, 10, "退出");
		settextstyle(30, 0, "华文新魏");
		peekmessage(&msg, EX_MOUSE);
		button(100, 550, "玩家技能", "玩家技能");
		rectangle(100, 550, 300, 630);
		outtextxy(120, 570, "玩家技能");

		rectangle(400, 550, 550, 630);
		outtextxy(420, 570, "武器");

		rectangle(100, 700, 300, 770);
		outtextxy(120, 720, "boss技能");

		rectangle(400, 700, 550, 770);
		outtextxy(420, 720, "道具");

		outtextxy(120, 470, "上一页");
		outtextxy(420, 470, "下一页");
		if (inArea(msg.x, msg.y, 120, 570, 120 + textwidth("玩家技能"), 570 + textheight("玩家技能")))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 120, 570, 120 + textwidth("玩家技能"), 570 + textheight("玩家技能")))
			{
				printf("111");
				library_cur = 1;
				i = j = 0;
			}
		}
		else if (inArea(msg.x, msg.y, 420, 570, 420 + textwidth("武器"), 570 + textheight("武器")))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 420, 570, 420+ textwidth("武器"), 570 + textheight("武器")))
			{
				printf("222");
				library_cur = 0;
				i = j = 0;
			}

		}
		else if (inArea(msg.x, msg.y, 120, 700, 100 + textwidth("boss技能"), 720 + textheight("boss技能")))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 120, 700, 100 + textwidth("boss技能"), 720 + textheight("boss技能")))
			{
				printf("333");
				library_cur = 2;
				i = j = 0;
			}
		}
		else if (inArea(msg.x, msg.y, 420, 720, 420 + textwidth("道具"), 720 + textheight("道具")))
		{
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 420, 720, 420 + textwidth("道具"), 720 + textheight("道具")))
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
			
			if (inArea(msg.x, msg.y, 120, 470, 120+textwidth("上一页"), 470+textheight("上一页")) && i >=1)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 120, 470, 120 + textwidth("上一页"), 470 + textheight("上一页")))
				{
					i--;
					Sleep(250);
				}
			}
			if (inArea(msg.x, msg.y, 420, 470, 420 + textwidth("下一页"), 470 + textheight("下一页")) && i <= 0)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 420, 470, 420 + textwidth("下一页"), 470 + textheight("下一页")))
				{
					i++;
					Sleep(250);
				}
			}
			msg.message = 0;
		}
	}
}