#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		cout << "玩家赢" << endl;
	}
	else if (ret == '#')
	{
		cout << "电脑赢" << endl;
	}
	else
	{
		cout << "平局" << endl;
	}
}
void menu()
{
	cout << "**********************************" << endl;
	cout << "********1.play    0.exit   *******" << endl;
	cout << "**********************************" << endl;
	cout << "**********************************" << endl;
}
void test()
{
	int n;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		cout << "请选择:>";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "三子棋" << endl;
			game();
			break;
		case 0:
			cout <<"bye";
			break;
		default:
			cout << "error please try again" << endl;
		}
	} while (n);
}
int main()
{
	test();
	return 0;
}