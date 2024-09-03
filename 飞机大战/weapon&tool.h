#pragma once
#include"play_game.h"

struct tool_plane {
	int life;//直接恢复等量的血
	int max_life;//增加最大生命值并且增加等量血量值
	int percent_life;//根据数值恢复最大生命值的百分比血量
	int power;//直接增加等量的攻击力
	int precent_power;//依据飞机现有攻击力根据数值增加百分比攻击
	int x;
	int y;//改变x，y轴坐标
	int width;
	int height;//改变飞机大小
	int buff_speed;//提供给飞机的速度大小
	int self_speed;//自身道具掉落速度
	int bullet_num;  //增加子弹数量
	int ID_tool;//每个道具的特有的特殊值，用来区分道具，从零开始，每多一个加1
};


typedef struct weapon_Node {
	int x, y;
	int width, height;
	int tool_temp;
	struct weapon_Node* next, * pre;
}*LinkList_w;



void weapon_init();

void tool_init();