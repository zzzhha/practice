#include"Aircraft battle.h"

extern ExMessage msg;
extern int flag;
#include"Aircraft battle.h"

IMAGE player_photo[2];
IMAGE game_photo;
IMAGE gun[2];
extern ExMessage msg;
struct character {
	int life;//生命值
	int power;//攻击力
	int x, y;//初始坐标轴
	character(int life, int power, int x, int y) :life(life), power(power), x(x), y(y) {}
};

class player :public character {
public:
	int vx, vy;
	int speed = 3;
	player(int life, int power, int x, int y, int vx, int vy) :character(life, power, x, y), vx(vx), vy(vy) {}
	inline void play_move() {
		peekmessage(&msg, EX_KEY | EX_MOUSE);
		if (msg.message == WM_KEYDOWN) {
			switch (msg.vkcode) {
			case VK_UP:
			case 'W':
				vy = -1;
				break;
			case 'A':
			case VK_LEFT:
				vx = -1;
				break;
			case VK_DOWN:
			case 'S':
				vy = 1;
				break;
			case VK_RIGHT:
			case 'D':
				vx = 1;
				break;
			}
		}
		else if (msg.message == WM_KEYUP) {
			switch (msg.vkcode) {
			case VK_UP:
			case 'W':
				vy = 0;
				break;
			case 'A':
			case VK_LEFT:
				vx = 0;
				break;
			case VK_DOWN:
			case 'S':
				vy = 0;
				break;
			case VK_RIGHT:
			case 'D':
				vx = 0;
				break;
			}
		}
	}
	void player_speed() {
		x += speed * vx;
		y += speed * vy;
	}
	bool is_life() {
		if (life == 0)
			return true;
		return false;
	}

};

class nor_monster :public character {
	nor_monster(int life, int power, int x, int y) :character(life, power, x, y) {}
};


class b_boss_monster :public character {
	b_boss_monster(int life, int power, int x, int y) :character(life, power, x, y) {}
};


player p1 = { 100,100,1080 / 2 - 50,860,0,0 };


void in_graph(character& a) {
	if (a.x < 0)
		a.x = 0;
	if (a.x + 100 > 1080)
		a.x = 980;
	if (a.y < 0)
		a.y = 0;
	if (a.y + 100 > 960)
		a.y = 860;
}

void start_game() {
	loadimage(player_photo, "photo/player_photo1.jpg", 100, 100);
	loadimage(player_photo + 1, "photo/player_photo2.jpg", 100, 100);
	loadimage(gun, "photo/子弹.jpg", 20, 30);
	loadimage(gun + 1, "photo/子弹1.jpg", 20, 30);
	loadimage(&game_photo, "photo/game_photo.jpg", 1080, 960);

	while (1) {
		if (p1.is_life())
			break;
		p1.play_move();
		p1.player_speed();
		in_graph(p1);
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, &game_photo);
		putimage(p1.x, p1.y, player_photo + 1, NOTSRCERASE);
		putimage(p1.x, p1.y, player_photo, SRCINVERT);
		int tempx = p1.x, tempy = p1.y;
		putimage(tempx + 40, tempy - 20, gun + 1, NOTSRCERASE);
		putimage(tempx + 40, tempy - 20, gun, SRCINVERT);


		EndBatchDraw();
		msg.message = 0;
		Sleep(10);
	}
}