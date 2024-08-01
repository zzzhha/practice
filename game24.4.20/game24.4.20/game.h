#pragma once
#include<iostream>
#include<time.h>
using namespace std;
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL],int,int );
void DisplayBoard(char board[ROW][COL], int, int);
void PlayerMove(char board[ROW][COL], int, int);
void ComputerMove(char board[ROW][COL], int, int);
char Iswin(char board[ROW][COL], int, int);