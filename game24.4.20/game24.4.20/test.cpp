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
		cout << "���Ӯ" << endl;
	}
	else if (ret == '#')
	{
		cout << "����Ӯ" << endl;
	}
	else
	{
		cout << "ƽ��" << endl;
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
		cout << "��ѡ��:>";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "������" << endl;
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