#include"Aircraft battle.h"

ExMessage msg;
int flag = MY_MENU;//ÆìÖÄ
void controller();
int main() {
	controller();//¿ØÖÆÌ¨
	return 0;
}

void controller() {
	initgraph(1080,960);
	cleardevice();
	while (1) {
		switch (flag) {
		case MY_MENU:
			game_menu();
			break;
		case END_GAME:
			exit(0);
			break;
		case GAME_PLAY:
			start_game();
			break;
		case SETTING:
			relevant_set();
			break;
		case GAME_HELP:
			game_help();
			break;
		case STAFF:
			develop_staff();
			break;


		}
		

	}
}
