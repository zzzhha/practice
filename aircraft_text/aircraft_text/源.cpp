#include<stdio.h>
#include<easyx.h>


struct character {
	int life;//ÉúÃüÖµ
	int power;//¹¥»÷Á¦
	character(int life, int power) :life(life), power(power) {}
};

class player :public character {
public:
	int x, y;
	int vx, vy;
	int r;
	int speed = 3;
	player(int life, int power, int x, int y,int r, int vx, int vy) :character(life, power), x(x),
		y(y), vx(vx), vy(vy),r(r) {}
	void player_speed() {
		x += speed * vx;
		y += speed * vy;
	}

};

class nor_monster :public character {
	nor_monster(int life, int power) :character(life, power) {}
};


class b_boss_monster :public character {
	b_boss_monster(int life, int power) :character(life, power) {}
};

player p1 = { 100,100,1080 / 2 - 50,860,20,0,0 };


int main() {
	initgraph(1080, 960);
	ExMessage msg;
	
	while (1) {
		peekmessage(&msg, EX_KEY | EX_MOUSE);
		setbkcolor(WHITE);
		if (msg.message == WM_KEYDOWN) {
			switch (msg.vkcode) {
			case VK_UP:
			case 'W':
				p1.vy = -1;
				break;
			case 'A':
			case VK_LEFT:
				p1.vx = -1;
				break;
			case VK_DOWN:
			case 'S':
				p1.vy = 1;
				break;
			case VK_RIGHT:
			case 'D':
				p1.vx = 1;
				break;
			}
		}
		else if (msg.message == WM_KEYUP) {
			switch (msg.vkcode) {
			case VK_UP:
			case 'W':
				p1.vy = 0;
				break;
			case 'A':
			case VK_LEFT:
				p1.vx = 0;
				break;
			case VK_DOWN:
			case 'S':
				p1.vy = 0;
				break;
			case VK_RIGHT:
			case 'D':
				p1.vx =0;
				break;
			}
		}
		p1.player_speed();

		BeginBatchDraw();
		cleardevice();
		
		setfillcolor(RGB(187, 59, 196));
		solidcircle(p1.x, p1.y, p1.r);
		//if (msg.message == WM_KEYDOWN) {
		//	/*if (msg.vkcode == VK_LEFT)
		//		printf("w");*/
		//	p1.x++;
		//	printf("keydown\n");
		//	
		//}
		//else if (msg.message == WM_KEYUP) {
		//	p1.y++;
		//	printf("keyup\n");
		//}
		EndBatchDraw();
		msg.message = 0;
		Sleep(10);
	}
	return 0;
}

