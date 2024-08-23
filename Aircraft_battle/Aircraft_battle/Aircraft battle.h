#pragma once
#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<Windows.h>
#include<mmsystem.h>
#include<conio.h> 
#include<stdlib.h>
#include<climits>
#pragma comment(lib,"winmm.lib")
#define MY_MENU 0
#define END_GAME 1
#define GAME_PLAY 2
#define GAME_HELP 3
#define STAFF 4
#define SETTING 5

void game_menu();
void relevant_set();
void start_game();
void game_help();
void develop_staff();



