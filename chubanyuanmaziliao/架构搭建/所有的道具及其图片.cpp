﻿#define  _CRT_SECURE_NO_WARNINGS 1
#include"梦境逃离.h"
Good_tool all_good_tool[36][3];//定义总共有36个事件每个事件最多3个加成型道具
Bad_tool all_bad_tool[36][3];//定义总共有36个事件每个事件最多3个惩罚型道具
IMAGE good_tool[36][3];//与上面的好道具相关，如果要加道具请一一对应
IMAGE bad_tool[36][3];//与上面的坏道具相关，如果要加道具请一一对应
//道具列在下方
void init_good_tool()
{
	int i = 0;
	//事件零对应道具
	all_good_tool[0][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[0][1] = { 40,0,0,0,0,-1,"锈迹斑斑的罐头","一个普通的罐头，不知道还能不能食用" };
	all_good_tool[0][2] = { 70,0,0,0,0,0,"使用了一半的注射器","不知道能做什么用的注射器" };
	//事件一对应道具
	all_good_tool[1][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[1][1] = { 0,30,0,0,-20 ,-1,"普通的桌子","正如你所见，它和它的名字一样普通。" };
	all_good_tool[1][2] = { 0,0,0,0,0,1,"\0","\0" };
	//事件二对应道具
	all_good_tool[2][0] = { 0,50,20,0,0,2,"D32钢","一个十分坚硬的物体可以用它来做武器，也可以用来它做护盾，它为什么会出现在这里呢？" };
	all_good_tool[2][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[2][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件三对应道具
	all_good_tool[3][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[3][1] = { 40,0,0,25,0,3,"发黄的信纸","纸面泛黄，但信中急切的心情却溢于言表" };
	all_good_tool[3][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件四对应道具
	all_good_tool[4][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[4][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[4][2] = { 0,20,30,0,0,4,"驱虫剂","梦境守护者。在如梦似幻的夜晚，它驱散一切扰人梦魇的小虫，让每个梦境都清新宁静" };
	//事件五对应道具
	all_good_tool[5][0] = { 30,+20,0,-20,0,-1,"过期的...巧克力？","包装袋上的日期已经过去，但这块巧克力却仿佛获得了新生。它的味道更加浓郁，力量似乎也更胜一筹。" };
	all_good_tool[5][1] = { 0,0,0,+50,+20,5,"博学者之怒","低调而神秘，感悟梦境中的轨迹，很好奇这顶帽子的主人都是些什么人？" };
	all_good_tool[5][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件六对应道具
	all_good_tool[6][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[6][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[6][2] = { 20,10,0,0,0,-1,"厕纸","厕纸，可以用来上厕所" };
	//事件七对应道具
	all_good_tool[7][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[7][1] = { 0,0,0,0,0 ,-1,"\0","\0" };
	all_good_tool[7][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件八对应道具
	all_good_tool[8][0] = { 0,0,0,0,0,-1,"神秘的笔记","里面的字体你并不能看懂，但是你依然学到了些东西" };
	all_good_tool[8][1] = { 0,0,0,0,0 ,-1,"\0","\0" };
	all_good_tool[8][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件九对应道具
	all_good_tool[9][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[9][1] = { 0,0,0,0,0 ,-1,"\0","\0" };
	all_good_tool[9][2] = { 0, 100,0,10,0,-1,"黑衣人的玉佩","刻有精致龙纹的白玉，关键时刻能保我一命？" };
	//事件十对应道具
	all_good_tool[10][0] = { 0,0,0,0,0,10, "\0","\0" };
	all_good_tool[10][1] = { 0,0,0,0,0 ,-1,"\0","\0" };
	all_good_tool[10][2] = { 20,0,10,0,0,-1,"奇异果实","一个声音诱惑着你，让你吃下去他" };
	//事件11对应道具
	all_good_tool[11][0] = { 0,0,0,0,0,11,"\0","\0" };
	all_good_tool[11][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[11][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件12对应道具
	all_good_tool[12][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[12][1] = { 0,0,0,0,0,-1,"小鸡玩偶","鸡你太美，鸡你实在是太美" };
	all_good_tool[12][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件13对应道具
	all_good_tool[13][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[13][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[13][2] = { 0,20,10,10,0,12,"道德秤","一杆道德的秤，可以判断测验者的道德水准" };
	//事件14对应道具
	all_good_tool[14][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[14][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[14][2] = { 0,10,0,0,20,-1,"铃铛","叮铃铃，叮铃铃，铃儿响铃铛" };
	//事件15对应道具
	all_good_tool[15][0] = { 0,50,0,0,0,-1,"铁质小盾牌","一个十分坚硬的盾牌，可以护你一时平安" };
	all_good_tool[15][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[15][2] = { 0,0,0,0,0,15,"\0","\0" };
	//事件16对应道具
	all_good_tool[16][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[16][1] = { 50,0,0,0,0,16,"应急灯","航海中必须准备的灯，为照亮前路而亮" };
	all_good_tool[16][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件17对应道具
	all_good_tool[17][0] = { 20,0,0,0,0,17,"能量水晶","包含了能量的水晶，可能是这座城能浮在云上的原因吧" };
	all_good_tool[17][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[17][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件18对应道具
	all_good_tool[18][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[18][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[18][2] = { 10, 0,0,20,0,18,"软掉的时钟","奇怪的时钟，为什么是软的呢？" };
	//事件19对应道具
	all_good_tool[19][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[19][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[19][2] = { 70, 0,0,0,0,19,"蓝色空间号","自然选择，前进四！" };
	//事件20对应道具
	all_good_tool[20][0] = { 0,0,0,0,0,20,"\0","\0" };
	all_good_tool[20][1] = { 0,0,0,0,0 ,20,"\0","\0" };
	all_good_tool[20][2] = { 0,0,0,0,0,20,"\0","\0" };
	//事件21对应道具
	all_good_tool[21][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[21][1] = { 0,0,0,0,0,21,"\0","\0" };
	all_good_tool[21][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件22对应道具
	all_good_tool[22][0] = { 0,0,0,0,0,22,"\0","\0" };
	all_good_tool[22][1] = { 0,0,0,0,0,22,"\0","\0" };
	all_good_tool[22][2] = { 0,0,0,0,0,22,"\0","\0" };
	//事件23对应道具
	all_good_tool[23][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[23][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[23][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件24对应道具
	all_good_tool[24][0] = { 0,0,0,0,0,-1,"","\0" };
	all_good_tool[24][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[24][2] = { 0,0,+50,0,0,23,"血颅蛊","血祭血神，颅献颅座" };
	//事件25对应道具
	all_good_tool[25][0] = { 0,+15,0,0,-10,24,"防毒面具","军用防毒面具，给你带来妈妈般的温暖" };
	all_good_tool[25][1] = { 0,0,0,0,+20,-1,"手电筒","电池手电筒，拥有超高亮度，让前路一望无际" };
	all_good_tool[25][2] = { 0,+20,0,0,-20,-1,"防火锡纸套","可以隔绝大部分热量，但是很笨重" };
	//事件26对应道具
	all_good_tool[26][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[26][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[26][2] = { 0,0,0,0,0,25,"\0","\0" };
	//事件27对应道具
	all_good_tool[27][0] = { 0,0,0,0,0,-1,"死亡笔记","DEATH NOTE——被世人所畏惧的存在，但是在这个世界中，还会有效吗？" };
	all_good_tool[27][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[27][2] = { 0,0,0,0,0,26,"\0","\0" };
	//事件28对应道具
	all_good_tool[28][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[28][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[28][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件29对应道具
	all_good_tool[28][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_good_tool[28][1] = { 0,0,0,0,0,27,"\0","\0" };
	all_good_tool[28][2] = { 0,0,0,0,0,-1,"\0","\0" };
}
void init_bad_tool()
{
	//事件零对应道具
	all_bad_tool[0][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[0][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[0][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件一对应道具
	all_bad_tool[1][0] = { 0, 0,0,0,0,-1,"\0","\0" };
	all_bad_tool[1][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[1][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件二对应道具
	all_bad_tool[2][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[2][1] = { -42,0,0,-20,0,-1,"哭泣","究竟是何等变态才能将她惹哭呢?"};
	all_bad_tool[2][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件三对应道具q
	all_bad_tool[3][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[3][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[3][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件四对应道具
	all_bad_tool[4][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[4][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[4][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件五对应道具
	all_bad_tool[5][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[5][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[5][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件六对应道具
	all_bad_tool[6][0] = { -10,0,0,-10,0,6,"复活吧我的爱人！","复活吧！我的爱人！" };
	all_bad_tool[6][1] = { -20,0,0,-10,0,-1,"高压锅","不是，哥们？" };
	all_bad_tool[6][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件七对应道具
	all_bad_tool[7][0] = { -999,0,0,0,0,7,"败者食尘","输的吃土！" };
	all_bad_tool[7][1] = { 0,0,-10,0,0,-1,"\0","\0" };
	all_bad_tool[7][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件八对应道具
	all_bad_tool[8][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[8][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[8][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件九对应道具
	all_bad_tool[9][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[9][1] = { 0,0,0,0,0,8,"\0","\0" };
	all_bad_tool[9][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件十对应道具
	all_bad_tool[10][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[10][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[10][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件11对应道具
	all_bad_tool[11][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[11][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[11][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件12对应道具
	all_bad_tool[12][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[12][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[12][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件13对应道具
	all_bad_tool[13][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[13][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[13][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件14对应道具
	all_bad_tool[14][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[14][1] = { 0,0,0,0,0,13,"\0","\0" };
	all_bad_tool[14][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件15对应道具
	all_bad_tool[15][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[15][1] = { 0,0,0,0,0,14,"\0","\0" };
	all_bad_tool[15][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件16对应道具
	all_bad_tool[16][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[16][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[16][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件17对应道具
	all_bad_tool[17][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[17][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[17][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件18对应道具
	all_bad_tool[18][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[18][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[18][2] = { 0, 0,0,0,0,-1,"\0","\0" };
	//事件19对应道具
	all_bad_tool[19][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[19][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[19][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件20对应道具
	all_bad_tool[20][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[20][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[20][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件21对应道具
	all_bad_tool[21][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[21][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[21][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件22对应道具
	all_bad_tool[22][0] = { 0,0,0,0,0,22,"\0","\0" };
	all_bad_tool[22][1] = { 0,0,0,0,0,22,"\0","\0" };
	all_bad_tool[22][2] = { 0,0,0,0,0,22,"\0","\0" };;
	//事件23对应道具
	all_bad_tool[23][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[23][1] = {-10,0,0,-20,0,-1,"诅咒文物","······" };
	all_bad_tool[23][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件24对应道具
	all_bad_tool[24][0] = { -25,0,-20,0,0,-1,"耐摔王","从直升机下降落，被人尊称为耐摔王" };
	all_bad_tool[24][1] = { 0,0,0,-50,0,-1,"阿库娅","来自智慧女神阿库娅的祝福" };
	all_bad_tool[24][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件25对应道具
	all_bad_tool[25][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[25][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[25][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件26对应道具
	all_bad_tool[26][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[26][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[26][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件27对应道具
	all_bad_tool[27][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[27][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[27][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件28对应道具
	all_bad_tool[28][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[28][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[28][2] = { 0,0,0,0,0,-1,"\0","\0" };
	//事件29对应道具
	all_bad_tool[29][0] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[29][1] = { 0,0,0,0,0,-1,"\0","\0" };
	all_bad_tool[29][2] = { 0,0,0,0,0,-1,"\0","\0" };

}