#define _CRT_SECURE_NO_WARNINGS 1
#include"梦境逃离.h"
extern ExMessage msg;
IMAGE Win_photo;
IMAGE Defeat_photo;
extern int flag;
int level = 0;//游戏胜利基础条件
int level_arr[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };//游玩过的关卡
int life = 100;//玩家基础生命值
int shield = 0;//玩家基础护盾值
int power = 100;//玩家基础力量
int smart = 100;//玩家基础智力
int speed = 100;//玩家基础敏捷

IMAGE guochang_photo;//柯南 门
extern struct EVENT Event[36];//37个事件,第三十七个事件是level等于0的固定事件
extern class IMAGE Event_photo[36];//36个事件对应的图片，第37个事件,是level等于0的固定事件
extern IMAGE achieve_photo[40];//成就图片

extern Good_tool all_good_tool[36][3];//定义总共有36个事件每个事件最多3个加成型道具
extern Bad_tool all_bad_tool[36][3];//定义总共有36个事件每个事件最多3个惩罚型道具
extern IMAGE good_tool[36][3];//与上面的好道具相关，如果要加道具请一一对应
extern IMAGE bad_tool[36][3];//与上面的坏道具相关，如果要加道具请一一对应

extern Good_tool level_zero_tool[9];//初始进入游戏时道具的选择,我们要随机三个，给供玩家选择，
extern IMAGE level_zero_tool_photo[9];//初始进入游戏时道具的图片
Bag bag;//定义一个背包，可以放置16个加成型道具，和16个惩罚性道具
int bag_gt;
int bag_bt;

//----------------------------view--------------------------
/*
  负责人：
  功能：
	打印过场动画
	点击回到上一次界面
  参数：void
  返回值：void
*/
void interlude_photo()
{
	loadimage(&guochang_photo, "photos/过场动画.jpg");
	putimage(0, 0, &guochang_photo);
	cleardevice();
	settextstyle(40, 0, "楷体");
	outtextxy(460, 680, "随意点击进行下一关");
	if (msg.message == WM_LBUTTONDOWN && (!inArea(msg.x, msg.y, 1000, 0, 80, 100)))
	{
		flag = MY_GAME;
		return;
	}
	msg.message = 0;
}


/*
  负责人：
  功能：
	展示背包界面
	判断是否
  参数：void
  返回值：void
*/
void Bag_view()
{
	/*
		1.展示背包界面（矩形/椭圆矩形）可以跟齿轮界面一样，插入一个矩形，然后在里面显示相关信息
		//也可以把他当做一个完整的界面，在界面里展示相关信息
		2.下方会有格子放置本局中已拥有的道具
		3.点击道具会在上方展示道具的详细属性和道具的信息
		4.退出可退回游戏界面break；
	*/

}

/*
  负责人：
  功能：
	判断是否点击物品，若点击，返回物品编号
  参数：void
  返回值：int
*/
int item_clicked()
{
	return 0;
}

void Win_View()
{
	/*
		1.打印胜利游戏界面
		2.随意点击就返回到主菜单
	*/
	//用图片代表胜利，点击一下返回
	loadimage(&Win_photo, "photos/hui.jpg");//胜利图片我没找，后期替换了
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &Win_photo);
		cleardevice();
		settextstyle(40, 0, "楷体");
		outtextxy(460, 680, "随意点击返回到主页面");
		if (msg.message == WM_LBUTTONDOWN)
		{
			gamemenu();
		}
		msg.message = 0;
		EndBatchDraw();
	}
}

/*
  负责人：
  功能：
	输出游戏失败界面
	点击任意处返回主菜单
  参数：void
  返回值：void
*/
void Defeat_View()
{
	/*
		1.打印失败游戏界面
		2.随意点击就返回到主菜单
	*/
	loadimage(&Defeat_photo, "photos/hui.jpg");//失败图片我没找呢，你们找一下，后期替换了
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &Defeat_photo);
		cleardevice();
		settextstyle(40, 0, "楷体");
		outtextxy(460, 680, "随意点击返回到主页面");
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
	while (1)
	{
		BeginBatchDraw();
		settextstyle(50, 0, "华文琥珀");
		settextcolor(RGB(157, 0, 176));
		int event = 0;
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
		char a[50] = "第0关";
		a[2] = level + 1 + '0';                                     //将数字转化为对应字符
		int x = textwidth(a) / 2;
		int y = textheight(a) / 2;
		outtextxy(getwidth() / 2 - x, 85 - y, a);
		putimage(0, 0, &Event_photo[event]);//放相应背景的图片
		/*
			实现人物属性区域，背包图片，齿轮设置的放置。
		*/
		outtextxy(950, 10, "设置");//齿轮设置的放置
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 1000, 0, 80, 100))
		{
			Gear_set();
		}
		outtextxy(0, 300, "背包");//背包界面的放置
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 50, 300, 50, 50))
		{
			Bag_view();
		}
		//游戏界面五维属性的展示
		show_player();
		/*
			1.三个选项 2.每个选项的后续剧情 3.人物属性的改变 4.背包存放道具
		*/
		settextstyle(35, 0, "微软雅黑");
		settextcolor(BLACK);
		RECT r = { 150, 150, 760, 850 };//矩形区域存放事件背景信息
		RECT one{ 0,800,360,960 };//展示选项一
		RECT two{ 360,800,720,960 };//展示选项二
		RECT three{ 720,800,1080,960 };//展示选项三
		RECT next{ 850,600,1030,800 };
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 750, 360, 960))//点击选项一
		{
			get_achievement(all_good_tool[event][0].sp);
			get_achievement(all_bad_tool[event][0].sp);
			level++;
			if (all_good_tool[event][0].name != "\0")//如果有好道具
			{
			//	bag.gt[bag_gt++] = all_good_tool[event][0];//在背包里存储
				life_and_shield_change(all_good_tool[event][0].life, Event[event].life[0], all_good_tool[event][0].shield, Event[event].shield[0]);
				power_change(all_good_tool[event][0].power, Event[event].power[0]);
				smart_change(all_good_tool[event][0].smart, Event[event].smart[0]);
				speed_change(all_good_tool[event][0].speed, Event[event].speed[0]);//改变五维属性值
			}

			else if (all_bad_tool[event][0].name != "\0")//如果有坏道具
			{
				//bag.bt[bag_bt++] = all_bad_tool[event][0];//在背包里存储
				life_and_shield_change(all_bad_tool[event][0].life, Event[event].life[0], all_bad_tool[event][0].shield, Event[event].shield[0]);
				power_change(all_bad_tool[event][0].power, Event[event].power[0]);
				smart_change(all_bad_tool[event][0].smart, Event[event].smart[0]);
				speed_change(all_bad_tool[event][0].speed, Event[event].speed[0]);//改变五维属性值

			}
			while (1)
			{
				settextcolor(BLACK);
				drawtext(Event[event].after_info_one, &r, DT_WORDBREAK);
				show_change(event, 0);
				drawtext("点击进入下一关", &next, DT_WORDBREAK);
				if (msg.message == WM_LBUTTONDOWN )
				{
					interlude_photo();//调用过场动画
					break;
				}
				FlushBatchDraw();
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 360, 800, 720, 960))//点击选项二
		{
			get_achievement(all_good_tool[event][1].sp);
			get_achievement(all_bad_tool[event][1].sp);
			level++;
			if (all_good_tool[event][1].name != "\0")//与上方一致
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
				drawtext("点击进入下一关", &next, DT_WORDBREAK);
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 850, 600, 1030, 800))
				{
					interlude_photo();//调用过场动画
					break;
				}
				FlushBatchDraw();
			}
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 720, 800, 1080, 960))//点击选项三
		{
			get_achievement(all_good_tool[event][2].sp);
			get_achievement(all_bad_tool[event][2].sp);
			level++;
			if (all_good_tool[event][2].name != "\0")//与上方一致
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
				drawtext("点击进入下一关", &next, DT_WORDBREAK);
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 850, 600, 1030, 800))
				{
					interlude_photo();//调用过场动画
					break;
				}
				FlushBatchDraw();
			}
		}
		else
		{
			drawtext(Event[event].info, &r, DT_WORDBREAK);//在上面的RECT的矩形区域写事件，自动换行
			drawtext(Event[event].choose_one, &one, DT_WORDBREAK);
			drawtext(Event[event].choose_two, &two, DT_WORDBREAK);
			drawtext(Event[event].choose_three, &three, DT_WORDBREAK);
		}
		msg.message = 0;
		EndBatchDraw();
	}
}


/*
	负责人：
	功能：
		展示人物属性
	参数 void
	返回值 void
*/
void show_player()
{
	char player_attribute[10];
	int_to_string(life, player_attribute);
	settextstyle(30, 0, "华文琥珀");
	outtextxy(850, 150, "生命值：");
	outtextxy(850 + textwidth("生命值："), 150, player_attribute);
	int_to_string(shield, player_attribute);
	outtextxy(850, 250, "护盾值：");
	outtextxy(850 + textwidth("护盾值："), 250, player_attribute);
	int_to_string(power, player_attribute);
	outtextxy(850, 350, "力量值：");
	outtextxy(850 + textwidth("力量值："), 350, player_attribute);
	int_to_string(smart, player_attribute);
	outtextxy(850, 450, "智力值：");
	outtextxy(850 + textwidth("智力值："), 450, player_attribute);
	int_to_string(speed, player_attribute);
	outtextxy(850, 550, "敏捷值：");
	outtextxy(850 + textwidth("敏捷值："), 550, player_attribute);
}
/*

	负责人：
	功能：
		展示事件和道具的属性值
	参数：int,int
	返回值：void
*/
void show_change(int event,int i)
{
	char arr[10];
	//事件变化值,在选项区域二展示
	int_to_string(Event[event].life[i], arr);
	outtextxy(360, 760, Event[event].name);
	outtextxy(360, 800, "生命值：");
	outtextxy(360 + textwidth("生命值："), 800, arr);
	int_to_string(Event[event].shield[i], arr);
	outtextxy(360, 830, "护盾值：");
	outtextxy(360 + textwidth("护盾值："), 830, arr);
	int_to_string(Event[event].power[i], arr);
	outtextxy(360, 860, "力量值：");
	outtextxy(360 + textwidth("力量值："), 860, arr);
	int_to_string(Event[event].smart[i], arr);
	outtextxy(360, 890, "智力值：");
	outtextxy(360 + textwidth("智力值："), 890, arr);
	int_to_string(Event[event].speed[i], arr);
	outtextxy(360, 920, "速度值：");
	outtextxy(360 + textwidth("速度值："), 920, arr);
	//正面道具变化值，在选项区域一展示
	putimage(0, 800, &(good_tool[event][i]));
	outtextxy(0, 760,all_good_tool[event][i].name);
	int_to_string(all_good_tool[event][i].life, arr);
	outtextxy(100, 800, "生命值：");
	outtextxy(100 + textwidth("生命值："), 800, arr);
	int_to_string(all_good_tool[event][i].shield, arr);
	outtextxy(100, 830, "护盾值：");
	outtextxy(100 + textwidth("护盾值："), 830, arr);
	int_to_string(all_good_tool[event][i].power, arr);
	outtextxy(100, 860, "力量值：");
	outtextxy(100 + textwidth("力量值："), 860, arr);
	int_to_string(all_good_tool[event][i].smart, arr);
	outtextxy(100, 890, "智力值：");
	outtextxy(100 + textwidth("智力值："), 890, arr);
	int_to_string(all_good_tool[event][i].speed, arr);
	outtextxy(100, 920, "速度值：");
	outtextxy(100 + textwidth("速度值："), 920, arr);
	//负面道具变化值，在选项区域三展示
	putimage(620, 700, &(bad_tool[event][i]));
	outtextxy(720, 760, all_bad_tool[event][i].name);
	int_to_string(all_bad_tool[event][i].life, arr);
	outtextxy(720, 800, "生命值：");
	outtextxy(720 + textwidth("生命值："), 800, arr);
	int_to_string(all_bad_tool[event][i].shield, arr);
	outtextxy(720, 830, "护盾值：");
	outtextxy(720 + textwidth("护盾值："), 830, arr);
	int_to_string(all_bad_tool[event][i].power, arr);
	outtextxy(720, 860, "力量值：");
	outtextxy(720 + textwidth("力量值："), 860, arr);
	int_to_string(all_bad_tool[event][i].smart, arr);
	outtextxy(720, 890, "智力值：");
	outtextxy(720 + textwidth("智力值："), 890, arr);
	int_to_string(all_bad_tool[event][i].speed, arr);
	outtextxy(720, 920, "速度值：");
	outtextxy(720 + textwidth("速度值："), 920, arr);
	
}
//----------------------------view--------------------------
//----------------------------service-------------------------------------

/*
 负责人：
 功能：
   判断游戏是否结束
   是否通关or是否死亡（若通关时生命值小于0算失败）
 参数：void
 返回值：0表示没有结束游戏，1代表胜利，代表失败

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
   负责人：
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
 负责人：
 功能：
   用随机数抽取事件（目前设定36个剧情）
 参数：void
 返回值：事件编号
*/
int choose_event()//选择事件
{
	srand((unsigned)time(NULL));
	int event = rand() % 8;//%的数可以改变，根据我们有多少个剧情就改变成多少
	if (judge_event(event))
		level_arr[level] = event;
	else
	{
		choose_event();
	}
	return event;
}

/*
 负责人：
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
  负责人：
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
  负责人：
  功能：
	计算在该事件中玩家的力量值（事件会使玩家属性改变）
	若力量值小于0按0计
  参数：道具力量值加成/减益 tool_power，事件生命值event_power
  返回值：
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
  返回值：
*/
void smart_change(int tool_smart, int event_smart)
{
	int sum = tool_smart + event_smart;//事件和道具加在一起的力量值
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

void load_photo()
{
	loadimage(&guochang_photo, "photos/过场动画.jpg");
	int i = 0;

	//事件图片和事件对应道具图片
	loadimage(&good_tool[i][0], "");//0
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "");//1
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&Event_photo[i++], "");

	loadimage(&good_tool[i][0], "TOOL_PHOTO/事件二选项一道具.jpg",100,100);//2
	loadimage(&good_tool[i][1], "");
	loadimage(&good_tool[i][2], "");
	loadimage(&bad_tool[i][0], "");
	loadimage(&bad_tool[i][1], "TOOL_PHOTO/事件二选项二图片.jpg",100,100);
	loadimage(&bad_tool[i][2], "");
	loadimage(&Event_photo[i++], "EVENT_PHOTO/事件二.jpg",1080,960);

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