#include"controller.h"

int flag;
void controller()
{
	initgraph(1080, 800);
	cleardevice();
	flag = MY_MENU;
	while (1) {
		switch (flag) {
		case MY_MENU:
			game_menu();
			break;
		case END_GAME:
			exit(0);
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

