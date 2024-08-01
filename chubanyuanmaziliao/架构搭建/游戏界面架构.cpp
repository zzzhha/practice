#define  _CRT_SECURE_NO_WARNINGS 1
#include"梦境逃离.h"
extern ExMessage msg;
extern int flag;
IMAGE win_photo;
IMAGE defeat_photo;
int level = 0;//游戏胜利基础条件
int level_arr[36] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};//游玩过的关卡
int life = 100;//玩家基础生命值
int shield = 0;//玩家基础护盾值
int power = 100;//玩家基础力量
int smart = 100;//玩家基础智力
int speed = 100;//玩家基础敏捷

IMAGE guochang_photo;
extern struct EVENT Event[36];//第30个事件
extern class IMAGE Event_photo[36];//30个事件对应的图片

extern Good_tool all_good_tool[36][3];//定义总共有36个事件每个事件最多3个加成型道具
extern Bad_tool all_bad_tool[36][3];//定义总共有36个事件每个事件最多3个惩罚型道具
extern IMAGE good_tool[36][3];//与上面的好道具相关，如果要加道具请一一对应
extern IMAGE bad_tool[36][3];//与上面的坏道具相关，如果要加道具请一一对应

Bag bag;//定义一个背包，可以放置16个加成型道具，和16个惩罚性道具
int bag_gt;//背包好道具计数
int bag_bt;//背包坏道具计数
//-----------------------数据设计-----------------------
//------------------------service--------------------
/*
 负责人：4c
 功能：
   判断游戏是否结束
   是否通关or是否死亡（若通关时生命值小于0算失败）
 参数：void
 返回值：0代表没结束游戏，1代表胜利，2代表失败

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
   负责人：河蟹
 功能：
   判断随机抽取的事件是否已发生
 参数：事件编号event
 返回值：bool（相当于int，返回ture 1，或false 0）
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
 负责人：小七
 功能：
   用随机数抽取事件（目前设定36个剧情）
	抽取后判断是否已经抽取过，如果抽取过则再次抽取
	如果没抽取过则记录下来，返回事件编号
 参数：void
 返回值：事件编号
*/
int choose_event()//选择事件
{
	srand((unsigned)time(NULL));
	int event = rand() % 30;//%的数可以改变，根据我们有多少个剧情就改变成多少
	return event;
}
/*
 负责人：看见了
 功能：
   初始化生命，护盾值，三维属性，和游玩过的关卡，背包清空
 参数：void
 返回值：void
*/
void Init_attribute()
{
	life = 100;//玩家基础生命值
	shield = 0;//玩家基础护盾值
	power = 100;//玩家基础力量
	smart = 100;//玩家基础智力
	speed = 100;//玩家基础敏捷
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
  负责人：小七
  功能：
	计算在该事件中玩家的生命值和护盾值（事件会使玩家属性改变）
	注意可能为负面效果，护盾值会为玩家抵挡部分伤害
	生命值可能归0，失败
  参数：道具生命值加成/减益 tool_life，事件生命值event_life，道具护盾值tool_shield，事件护盾值event_shield
  返回值：void
*/
void life_and_shield_change(int tool_life, int event_life, int tool_shield, int event_shield)
{
	int ret = tool_shield + event_shield;//事件和道具加在一起的护盾值
	int sum = tool_life + event_life;//事件和道具加在一起的生命值
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
  负责人：核废料
  功能：
	计算在该事件中玩家的力量值（事件会使玩家属性改变）
	若力量值小于0按0计
  参数：道具力量值加成/减益 tool_power，事件生命值event_power
  返回值：void
*/
void power_change(int tool_power, int event_power)
{
	int sum = tool_power + event_power;//事件和道具加在一起的力量值
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
  负责人：
  功能：
	计算在该事件中玩家的智力（事件会使玩家属性改变）
	若智力小于0按0计
  参数：道具力量值加成/减益 tool_smart，事件生命值event_smart
  返回值：void
*/
void smart_change(int tool_smart, int event_smart)
{
	int sum = tool_smart + event_smart;//事件和道具加在一起的智力值
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
  负责人：
  功能：
	计算在该事件中玩家的敏捷（事件会使玩家属性改变）
	若智力小于0按0计
  参数：道具对敏捷加成/减益 tool_speed，事件生命值event_speed
*/
void speed_change(int tool_speed, int event_speed)
{
	int sum = tool_speed + event_speed;//事件和道具加在一起的力量值
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
  负责人：空白
  功能：
	点击进行下一关
  参数：void
  返回值：void
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
  负责人：阿星
  功能：
	
		1.展示背包界面（矩形/椭圆矩形）可以跟齿轮界面一样，插入一个矩形，然后在里面显示相关信息
		//也可以把他当做一个完整的界面，在界面里展示相关信息
		2.下方会有格子放置本局中已拥有的道具
		3.点击道具会在上方展示道具的详细属性和道具的信息
		4.退出可退回游戏界面；
  参数：void
  返回值：void
*/
void Bag_view()
{
	while (1)
	{
		int gg = 0;
		BeginBatchDraw();
		setlinecolor(BLACK);		
		settextstyle(40, 0, "微软雅黑");
		peekmessage(&msg, EX_MOUSE);
		for (int i = 0; i < 30;)
		{
			clearrectangle(150, 150, 850, 850);
			setfillcolor(RGB(211, 211, 211));
			fillrectangle(150, 150, 850, 850);
			settextstyle(50, 0, "华文琥珀");
			outtextxy(750, 150, "退出");
			outtextxy(300, 700, "上一页");
			outtextxy(700, 700, "下一页");
			char str[10];
			sprintf(str, "第%d页", i);
			outtextxy(500, 700, str);
			peekmessage(&msg, EX_MOUSE);
			if (inArea(msg.x, msg.y, 300, 700, textwidth("上一页"), textheight("上一页")) && i >= 1)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 300, 700, textwidth("上一页"), textheight("上一页")))
				{
					i--;
					Sleep(250);
				}
			}
			if (inArea(msg.x, msg.y, 700, 700, textwidth("上一页"), textheight("上一页")) && i <= 21)
			{
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 700, 700, textwidth("上一页"), textheight("上一页")))
				{
					i++;
					Sleep(250);
				}
			}
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 750, 150, textwidth("关闭"), textwidth("关闭")))
			{
				//gg = 1;
				settextcolor(RGB(157, 0, 176));
				clearrectangle(200, 200, 800, 800);
				//flag = MY_GAME;
				return;
			}
			settextcolor(BLACK);
			settextstyle(35, 0, "微软雅黑");
			putimage(180, 180, &good_tool[bag.Gt[i]][bag.GT[i]]);//好道具的图片展示
			outtextxy(310,180 , all_good_tool[bag.Gt[i]][bag.GT[i]].name);//好道具的名字展示
			RECT text1{ 310,220,425,425 };
			settextstyle(25, 0, "微软雅黑");
			drawtext(all_good_tool[bag.Gt[i]][bag.GT[i]].info, &text1, DT_WORDBREAK);//好道具的信息展示
			char arr[10];
			itoa(all_good_tool[bag.Gt[i]][bag.GT[i]].life, arr, 10);
			settextstyle(35, 0, "微软雅黑");
			outtextxy(150, 425, "生命值：");//好道具的生命值展示
			outtextxy(150 + textwidth("生命值："), 425, arr);
			itoa(all_good_tool[bag.Gt[i]][bag.GT[i]].shield, arr, 10);
			outtextxy(150, 470, "护盾值：");//好道具的护盾值展示
			outtextxy(150 + textwidth("护盾值："), 470, arr);
			itoa(all_good_tool[bag.Gt[i]][bag.GT[i]].power, arr, 10);
			outtextxy(150, 515, "力量值：");//好道具的力量值展示
			outtextxy(150 + textwidth("力量值："), 515, arr);
			itoa(all_good_tool[bag.Gt[i]][bag.GT[i]].smart, arr, 10);
			outtextxy(150, 560, "智力值：");//好道具的智力值展示
			outtextxy(150 + textwidth("智力值："), 560, arr);
			itoa(all_good_tool[bag.Gt[i]][bag.GT[i]].speed, arr, 10);
			outtextxy(150, 605, "敏捷值：");//好道具的敏捷值展示
			outtextxy(150 + textwidth("敏捷值："), 605, arr);


			putimage(450, 180, &bad_tool[bag.Bt[i]][bag.BT[i]]);//坏道具的图片展示
			outtextxy(580, 180, all_bad_tool[bag.Bt[i]][bag.BT[i]].name);//坏道具的名字展示
			RECT text2{ 580,220,700,425 };
			settextstyle(25, 0, "微软雅黑");
			drawtext(all_bad_tool[bag.Bt[i]][bag.BT[i]].info, &text2, DT_WORDBREAK);//坏道具的信息展示
			itoa(all_bad_tool[bag.Bt[i]][bag.BT[i]].life, arr, 10);
			settextstyle(35, 0, "微软雅黑");
			outtextxy(450, 425, "生命值：");//坏道具的生命值展示
			outtextxy(450 + textwidth("生命值："), 425, arr);
			itoa(all_bad_tool[bag.Bt[i]][bag.BT[i]].shield, arr, 10);
			outtextxy(450, 470, "护盾值：");//坏道具的护盾值展示
			outtextxy(450 + textwidth("护盾值："), 470, arr);
			itoa(all_bad_tool[bag.Bt[i]][bag.BT[i]].power, arr, 10);
			outtextxy(450, 515, "力量值：");//坏道具的力量值展示
			outtextxy(450 + textwidth("力量值："), 515, arr);
			itoa(all_bad_tool[bag.Bt[i]][bag.BT[i]].smart, arr, 10);
			outtextxy(450, 560, "智力值：");//坏道具的智力值展示
			outtextxy(450 + textwidth("智力值："), 560, arr);
			itoa(all_bad_tool[bag.Bt[i]][bag.BT[i]].speed, arr, 10);
			outtextxy(450, 605, "敏捷值：");//坏道具的敏捷值展示
			outtextxy(450 + textwidth("敏捷值："), 605, arr);
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
  负责人：老魏
  功能：
	展示游戏胜利界面
	点击任意处返回主菜单
  参数：void
  返回值：void
*/
void Win_View()
{
	loadimage(&win_photo, "photos/胜利界面.jpg",1080,960);//胜利图片我没找，后期替换了
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &win_photo);
		settextstyle(40, 0, "楷体");
		outtextxy(460, 680, "随意点击返回到主页面");
		
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
  负责人：老魏
  功能：
	输出游戏失败界面
	点击任意处返回主菜单
  参数：void
  返回值：void
*/
void Defeat_View()
{
	loadimage(&defeat_photo, "photos\\失败图片.jpg",1080,960);
	while (1)
	{
		BeginBatchDraw();
		peekmessage(&msg, EX_MOUSE);
		cleardevice();
		putimage(0, 0, &defeat_photo);
		settextstyle(40, 0, "楷体");
		outtextxy(460, 680, "随意点击返回到主页面");
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
	//事件变化值,在选项区域二展示
	itoa(Event[event].life[i], arr, 10);
	outtextxy(360, 760, Event[event].name);
	outtextxy(360, 800, "生命值：");
	outtextxy(360 + textwidth("生命值："), 800, arr);
	itoa(Event[event].shield[i], arr, 10);
	outtextxy(360, 830, "护盾值：");
	outtextxy(360 + textwidth("护盾值："), 830, arr);
	itoa(Event[event].power[i], arr, 10);
	outtextxy(360, 860, "力量值：");
	outtextxy(360 + textwidth("力量值："), 860, arr);
	itoa(Event[event].smart[i], arr, 10);
	outtextxy(360, 890, "智力值：");
	outtextxy(360 + textwidth("智力值："), 890, arr);
	itoa(Event[event].speed[i], arr, 10);
	outtextxy(360, 920, "速度值：");
	outtextxy(360 + textwidth("速度值："), 920, arr);
	//正面道具变化值，在选项区域一展示
	putimage(0, 800, &(good_tool[event][i]));
	outtextxy(0, 760, all_good_tool[event][i].name);
	itoa(all_good_tool[event][i].life, arr, 10);
	outtextxy(100, 800, "生命值：");
	outtextxy(100 + textwidth("生命值："), 800, arr);
	itoa(all_good_tool[event][i].shield, arr, 10);
	outtextxy(100, 830, "护盾值：");
	outtextxy(100 + textwidth("护盾值："), 830, arr);
	itoa(all_good_tool[event][i].power, arr, 10);
	outtextxy(100, 860, "力量值：");
	outtextxy(100 + textwidth("力量值："), 860, arr);
	itoa(all_good_tool[event][i].smart, arr, 10);
	outtextxy(100, 890, "智力值：");
	outtextxy(100 + textwidth("智力值："), 890, arr);
	itoa(all_good_tool[event][i].speed, arr, 10);
	outtextxy(100, 920, "速度值：");
	outtextxy(100 + textwidth("速度值："), 920, arr);
	//负面道具变化值，在选项区域三展示
	putimage(620, 700, &(bad_tool[event][i]));
	outtextxy(720, 760, all_bad_tool[event][i].name);
	itoa(all_bad_tool[event][i].life, arr, 10);
	outtextxy(720, 800, "生命值：");
	outtextxy(720 + textwidth("生命值："), 800, arr);
	itoa(all_bad_tool[event][i].shield, arr, 10);
	outtextxy(720, 830, "护盾值：");
	outtextxy(720 + textwidth("护盾值："), 830, arr);
	itoa(all_bad_tool[event][i].power, arr, 10);
	outtextxy(720, 860, "力量值：");
	outtextxy(720 + textwidth("力量值："), 860, arr);
	itoa(all_bad_tool[event][i].smart, arr, 10);
	outtextxy(720, 890, "智力值：");
	outtextxy(720 + textwidth("智力值："), 890, arr);
	itoa(all_bad_tool[event][i].speed, arr, 10);
	outtextxy(720, 920, "速度值：");
	outtextxy(720 + textwidth("速度值："), 920, arr);

}
void show_player()
{
	char player_attribute[10];
	int_to_string(life, player_attribute);
	settextstyle(30, 0, "华文琥珀");
	outtextxy(850, 150, "生命值：");
	outtextxy(850 + textwidth("生命值："), 150, player_attribute);
	itoa(shield, player_attribute, 10);
	outtextxy(850, 250, "护盾值：");
	outtextxy(850 + textwidth("护盾值："), 250, player_attribute);
	itoa(power, player_attribute, 10);
	outtextxy(850, 350, "力量值：");
	outtextxy(850 + textwidth("力量值："), 350, player_attribute);
	itoa(smart, player_attribute, 10);
	outtextxy(850, 450, "智力值：");
	outtextxy(850 + textwidth("智力值："), 450, player_attribute);
	itoa(speed, player_attribute, 10);
	outtextxy(850, 550, "敏捷值：");
	outtextxy(850 + textwidth("敏捷值："), 550, player_attribute);
}
/*
  负责人：
  功能：
	    1.判断level是否为0进行属性初始化和图片的加载
	    2.判断If_End_Game判断是否结束游戏
			3根据level进行choose_event
				3.1若level=0，则不进行进行choose_event，直接进行第零关让玩家选择道具
				3.2若level不等于0，则进行choose_event，用随机数抽取一个数，当做本关关卡
			4.显示当前的第几关(用level去显示就行了)(最开始（也就是第0关）是选择三个道具进入梦境，所以第0关要写成 楔子 或者 起始 )
			5.在固定区域去显示：剧情文本，时间选项，玩家五项属性，齿轮设置，背包界面
			6.当玩家做出选择后，显示选项的后续剧情
			7.后续剧情显示完毕后，展示事件对属性的改变和道具的属性
			8.背包存放道具
			9.进行属性的增加或者扣除
			10.进行level改变
			11.进行interlude_photo()过场图片，衔接关卡。
  参数：void
  返回值：void
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
		//1.判断level是否为7
		//若为7则判断当前生命值是否为0；若为零则进入失败界面，若大于0则进入胜利界面
			//2.若level不为7，则判断当前生命是否为0，若为零则进入失败界面，若不为零则继续游戏
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
		settextstyle(50, 0, "华文琥珀");
		settextcolor(RGB(157, 0, 176));

		peekmessage(&msg, EX_MOUSE);
		/*
			2.判断If_End_Game判断是否结束游戏
			3根据level进行choose_event
				3.1若level=0，则不进行进行choose_event，直接进行第零关让玩家选择道具
				3.2若level不等于0，则进行choose_event，用随机数抽取一个数，当做本关关卡
			4.显示当前的第几关(用level去显示就行了)(最开始（也就是第0关）是选择三个道具进入梦境，所以第0关要写成 楔子 或者 起始 )
			5.在固定区域去显示：剧情文本，时间选项，玩家五项属性，齿轮设置，背包界面
			6.当玩家做出选择后，显示选项的后续剧情
			7.后续剧情显示完毕后，展示事件对属性的改变和道具的属性
			8.背包存放道具
			9.行进属性的增加或者扣除
			10.进行level改变
			11.进行interlude_photo()过场图片，衔接关卡。
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
		putimage(0, 0, &Event_photo[event]);//放相应背景的图片
		/*
			实现人物属性区域，背包图片，齿轮设置的放置。
		*/
		outtextxy(950, 10, "设置");//齿轮设置的放置
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 1000, 0, 80, 100))
		{
			Gear_set();
			/*control = 1;
			flag = GEAR;*/
			//break;
		}
		outtextxy(0, 300, "背包");//背包界面的放置
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 50, 300, 50, 50))
		{
			Bag_view();
			/*control = 1;
			flag = BAG;*/
			//break;
		}
		//游戏界面五维属性的展示
		show_player();
		/*
			1.三个选项 2.每个选项的后续剧情 3.人物属性的改变 4.背包存放道具
		*/
		settextstyle(30, 0, "微软雅黑");
		settextcolor(WHITE);
		RECT r = { 150, 150, 760, 850 };//矩形区域存放事件背景信息
		RECT one{ 0,800,360,960 };//展示选项一
		RECT two{ 360,800,720,960 };//展示选项二
		RECT three{ 720,800,1080,960 };//展示选项三
		RECT next{ 850,600,1030,800 };
		rectangle(0, 800, 360, 960);//展示选项一
		rectangle(360, 800, 720, 960);//展示选项二
		rectangle(720, 800, 1080, 960);//展示选项三
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 750, 360, 210))//点击选项一
		{
			get_achievement(all_good_tool[event][0].sp);
			get_achievement(all_bad_tool[event][0].sp);
			level++;
			if (all_good_tool[event][0].life != 0 || all_good_tool[event][0].shield != 0 || all_good_tool[event][0].power != 0 || all_good_tool[event][0].smart != 0 || all_good_tool[event][0].speed)
			{
				life_and_shield_change(all_good_tool[event][0].life, Event[event].life[0], all_good_tool[event][0].shield, Event[event].shield[0]);
				power_change(all_good_tool[event][0].power, Event[event].power[0]);
				smart_change(all_good_tool[event][0].smart, Event[event].smart[0]);
				speed_change(all_good_tool[event][0].speed, Event[event].speed[0]);//改变五维属性值
			}
			else
			{
				life_and_shield_change(all_bad_tool[event][0].life, Event[event].life[0], all_bad_tool[event][0].shield, Event[event].shield[0]);
				power_change(all_bad_tool[event][0].power, Event[event].power[0]);
				smart_change(all_bad_tool[event][0].smart, Event[event].smart[0]);
				speed_change(all_bad_tool[event][0].speed, Event[event].speed[0]);//改变五维属性值
			}
			if (strlen(all_good_tool[event][0].name)!=0)//如果有好道具
			{
				bag.Gt[bag_gt] = event;//在背包里存储
				bag.GT[bag_gt] = 0;
				bag_gt++;
				
				msg.message = 0;
			}
			
			else if (strlen(all_bad_tool[event][0].name)!=0)//如果有坏道具
			{
				bag.Bt[bag_bt] = event;//在背包里存储
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
				drawtext("点击进入下一关", &next, DT_WORDBREAK);
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
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 360, 750, 360, 210))//点击选项二
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
			if (strlen(all_good_tool[event][1].name )!=0)//与上方一致
			{
				bag.Gt[bag_gt] = event;//在背包里存储
				bag.GT[bag_gt] = 1;
				bag_gt++;//存储道具信息下标		
				msg.message = 0;
			}
			else if (strlen(all_bad_tool[event][1].name )!=0)
			{
				bag.Bt[bag_bt] = event;//在背包里存储
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
				drawtext("点击进入下一关", &next, DT_WORDBREAK);
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
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 720, 750, 360, 210))//点击选项三
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
			if (strlen(all_good_tool[event][2].name )!=0)//与上方一致
			{
				bag.Gt[bag_gt] = event;//在背包里存储
				bag.GT[bag_gt] = 2;
				bag_gt++;//存储道具信息下标
				msg.message = 0;
			}
			else if (strlen(all_bad_tool[event][2].name )!=0)
			{
				bag.Gt[bag_bt] = event;//在背包里存储
				bag.GT[bag_bt] = 2;
				bag_bt++;//存储道具信息下标	
			
				msg.message = 0;
			}
			Sleep(300);
			while (1)
			{
				peekmessage(&msg, EX_MOUSE);
				settextcolor(WHITE);
				drawtext(Event[event].after_info_three, &r, DT_WORDBREAK);
				show_change(event, 2);
				drawtext("点击进入下一关", &next, DT_WORDBREAK);
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
			
			drawtext(Event[event].info, &r, DT_WORDBREAK);//在上面的RECT的矩形区域写事件，自动换行
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
  负责人：
  功能：
	加载所有事件和道具图片
  参数：void
  返回值：void
*/
void load_photo()
{
	loadimage(&guochang_photo, "photos/过场动画.jpg");
	int i = 0;

	//事件图片和事件对应道具图片
	loadimage(&good_tool[i][1], "TOOL_PHOTO/事件0选项二道具.jpg",100,100);	//0
	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件0选项三道具.jpg",100,100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件0背景.jpg",1080,960);

	loadimage(&good_tool[i][1], "TOOL_PHOTO/事件1选项二道具.jpg", 100, 100);//1
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件1背景.jpg", 1080, 960);

	loadimage(&good_tool[i][0], "TOOL_PHOTO/事件2选项一道具.jpg",100,100);//2
	loadimage(&bad_tool[i][1], "TOOL_PHOTO/事件2选项二道具.jpg",100,100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件2背景.jpg", 1080, 960);


	loadimage(&good_tool[i][1], "TOOL_PHOTO/事件3选项二道具.jpg",100, 100);//3
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件3背景.jpg", 1080, 960);


	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件4选项三道具.jpg", 100, 100);//4
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件4背景.jpg", 1080, 960);

	loadimage(&good_tool[i][0], "TOOL_PHOTO/事件5选项一道具.jpg", 100, 100);//5
	loadimage(&good_tool[i][1], "TOOL_PHOTO/事件5选项二道具.jpg", 100, 100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件5背景.jpg", 1080, 960);

	loadimage(&bad_tool[i][0], "TOOL_PHOTO/事件6选项一道具.jpg", 100, 100);//6
	loadimage(&bad_tool[i][1], "TOOL_PHOTO/事件6选项二道具.jpg",100,100);
	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件6选项三道具.jpg", 100, 100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件6背景.jpg", 1080, 960);

	loadimage(&bad_tool[i][0], "TOOL_PHOTO/事件7选项一道具.jpg", 100, 100);//7
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件7背景.jpg", 1080, 960);

	loadimage(&good_tool[i][0], """TOOL_PHOTO/事件8选项一道具.jpg", 100, 100);//8
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件8背景.jpg", 1080, 960);

	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件9选项三道具.jpg", 100, 100);//9
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件9背景.jpg", 1080, 960);

	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件10选项三道具.jpg", 100, 100);//10
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件10背景.jpg", 1080, 960);

	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件11背景.jpg", 1080, 960);//11

	loadimage(&good_tool[i][1], "TOOL_PHOTO/事件12选项二道具.jpg", 100, 100);//12
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件12背景.jpg", 1080, 960);

	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件13选项三道具.jpg", 100, 100);//13
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件13背景.jpg", 1080, 960);


	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件14选项三道具.jpg", 100, 100);//14
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件14背景.jpg", 1080, 960);

	loadimage(&good_tool[i][0], "TOOL_PHOTO/事件15选项一道具.jpg", 100, 100);//15
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件15背景.jpg", 1080, 960);

	loadimage(&good_tool[i][1], "TOOL_PHOTO/事件16选项二道具.jpg", 100, 100);//16
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件16背景.jpg", 1080, 960);

	loadimage(&good_tool[i][0], "TOOL_PHOTO/事件17选项一道具.jpg", 100, 100);//17
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件17背景.jpg", 1080, 960);

	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件18选项三道具.jpg", 100, 100);//18
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件18背景.jpg", 1080, 960);


	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件19选项三道具.jpg", 100, 100);//19
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件19背景.jpg", 1080, 960);

	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件20背景.jpg", 1080, 960);//20

	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件21背景.jpg", 1080, 960);//21

	loadimage(&bad_tool[i][2], "TOOL_PHOTO/事件22选项三道具.jpg", 100, 100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件22背景.jpg", 1080, 960);//22


	loadimage(&bad_tool[i][1], "TOOL_PHOTO/事件23选项二道具.jpg", 100, 100);//23
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件23背景.jpg", 1080, 960);

	loadimage(&bad_tool[i][0], "TOOL_PHOTO/事件24选项一道具.jpg", 100, 100);//24
	loadimage(&bad_tool[i][1], "TOOL_PHOTO/事件24选项二道具.jpg", 100, 100);
	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件24选项三道具.jpg", 100, 100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件24背景.jpg", 1080, 960);

	loadimage(&good_tool[i][0], "TOOL_PHOTO/事件25选项一道具.jpg", 100, 100);//25
	loadimage(&good_tool[i][1], "TOOL_PHOTO/事件25选项二道具.jpg", 100, 100);
	loadimage(&good_tool[i][2], "TOOL_PHOTO/事件25选项三道具.jpg", 100, 100);
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件25背景.jpg", 1080, 960);


	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件26背景.jpg", 1080, 960);//26

	loadimage(&good_tool[i][0], "TOOL_PHOTO/事件27选项一道具.jpg", 100, 100);//27
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件27背景.jpg", 1080, 960);

	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件28背景.jpg", 1080, 960);//28

	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件29背景.jpg", 1080, 960);//29



}