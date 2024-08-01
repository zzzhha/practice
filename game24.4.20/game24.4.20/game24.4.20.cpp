#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			cout << " " << board[i][j] << " ";
			if (j < col - 1)
				cout << "|";
			
		}
		cout << endl;
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				cout << "---";
				if(j<col-1)
				cout << "|";
			}
			cout << endl;
		}
		
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	cout << "玩家下棋" << endl;
	int x = 0,y = 0;
	while(1)
	{
		cout << "请输入坐标:>";
		cin >> x >> y;
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				cout << "改坐标被占用" << endl;
			}
		}
		else
		{
			cout << "坐标非法，请重新输入" << endl;
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	cout << "电脑走:>" << endl;
	int x = 0, y = 0;
	x = rand() % row;
	y = rand() % col;
	while(1)
	{
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][1] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[i][0];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[0][0];
	if (board[2][0] == board[1][1] && board[0][2] == board[2][2] && board[1][1] != ' ')
		return board[0][0];
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}