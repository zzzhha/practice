#pragma once
#include"controller.h"


/*
* 负责人：
* 功能：菜单界面运行
* 参数：void
* 返回值：void
*/
void game_menu();

/*
* 负责人：
* 功能：判断鼠标是否在按键上
* 参数：鼠标坐标mx，my;按键左上右下坐标x,y,dx,dy
* 返回值：bool
*/
bool inArea(int mx, int my, int x, int y, int dx, int dy);

/*
* 负责人：
* 功能：绘制按钮,鼠标移动到指定位置的时候会发生颜色改变
* 参数：按钮坐标，颜色
* 返回值：void
*/
void button(int x, int y, const char* white, const char* dark);

/*
* 负责人：
* 功能：写标题，同上，但是不会发生颜色变化
* 参数：坐标x，y。标题
* 返回值：void
*/
void button_nomsg(int x, int y, const char* text);
