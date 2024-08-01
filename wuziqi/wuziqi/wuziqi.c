#define  _CRT_SECURE_NO_WARNINGS 1
#include"wuziqi.h"

int flag ;//显示当前回合数
void winView()
{
	if (flag % 2)
	{
		printf("恭喜！黑子玩家胜利！\n");
	}
	else
	{
		printf("恭喜！白子玩家胜利！\n");
	}
}
int isWin(int x, int y)//判断白子或者黑子是否胜利或者是平局
{
	int i, j;
	int count = 1;//记录当前落子与旁边的字相接的有多少个
	int gg=0 ;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 19; j++)
		{
			if (map[i][j] == 0)
				continue;
			if (j < 19 - 4)//横着是否胜利
			{
				if (map[i][j] == map[i][j + 1] &&
					map[i][j] == map[i][j + 2] &&
					map[i][j] == map[i][j + 3] &&
					map[i][j] == map[i][j + 4] && 
					map[i][j]!=0)
				{
					gg = 1;
				}
			}
			if(i< 19 -4)//竖着是否胜利
			{
				if (map[i][j] == map[i + 1][j] &&
					map[i][j] == map[i + 2][j] && 
					map[i][j] == map[i + 3][j] && 
					map[i][j] == map[i + 4][j] && 
					map[i][j] != 0)
				{
					gg = 1;
				}
			}
			if (i < 19 - 4 && j < 19 - 4)//左上至右下是否胜利
			{
				if (map[i][j] == map[i + 1][j+1] &&
					map[i][j] == map[i + 2][j+2] && 
					map[i][j] == map[i + 3][j+3] && 
					map[i][j] == map[i + 4][j+4] && 
					map[i][j] !=0 )
				{
					gg = 1;
				}
			}
			if ((i < 19 - 4) && (j >= 4))//右上至左下是否胜利
				if (map[i][j] == map[i + 1][j - 1] &&
					map[i][j] == map[i + 2][j - 2] &&
					map[i][j] == map[i + 3][j - 3] && 
					map[i][j] == map[i + 4][j - 4] && 
					map[i][j] != 0)
				{
					gg = 1;
				}

		}
	}
	if (gg)//判断赢没赢
	{
		if (flag % 2 == 1)
		{
			return 1;//黑子赢了
		}
		else
		{
			return 2;//白子赢了
		}
	}
	else
	{
		return 0;//没有获胜
	}
}
int playerMove(int x, int y)//玩家移动
{
	if (x > 19 || y > 19)
	{
		printf("落子错误请再来一次(行要小于等于%d,列要小于等于%d)\n", 19, 19);
		return 0;
	}
	else if (map[x - 1][y - 1] != 0)
	{
		printf("落子错误,请重试");
		return 0;
	}
	else
	{
		if (flag % 2)//黑子移动
		{

			map[x - 1][y - 1] = 1;
			return 1;
		}
		else//白子移动
		{
			map[x - 1][y - 1] = 2;
			return 1;
		}
	}
}
	
void gameView_ShowMap()//展示棋盘
{
	int i = 0;
	for (i = 0; i < 19; i++)
	{
		int j = 0;
		for (j = 0; j < 19; j++)
		{
			printf(" %d ", map[i][j]);//打印当前数组内容
			if (j != 19 -1)
			{
				printf("|");//打印棋盘中的竖杠，每两个数字中间一个竖杠，最外层两边没有
			}
		}
		printf("\n");//换行打印一行横杠
		for (j = 0; j < 19; j++)
		{
			if (i != 19 -1)//打印棋盘中的横杠，每两个数字中间一个横杠，最上和最下边没有
			{
				printf("___ ");
			}
		}
		printf("\n");//换行继续打印数组内容和竖杠
	}
}
void init()
{
	flag = 1;
	int i;//控制map行
	for (i = 0; i < 19; i++)
	{
		int j;//控制列
		for (j = 0; j < 19; j++)
		{
			map[i][j] = 0;//使map数组全为0
		}
	}
}
void gameView()
{
	init();//初始化数组
	gameView_ShowMap();
	while(1)
	{
		int x, y;
		printf("第%d回合\n", flag);
		if (flag % 2)
		{
			printf("请黑子落棋:>");
		}
		else
		{
			printf("请白子落棋:>");
		}
		scanf("%d%d", &x, &y);
			if(playerMove(x, y))
			{
				gameView_ShowMap();
				if (isWin(x, y))
				{
					winView();
					break;
				}
				if (flag == 19 * 19)
				{
					printf("平局！\n");
					break;
				}
				flag++;
			}
	}
}
void menuView()
{
	int i;
	int ch;
	do
	{
		printf("***********************************************\n");
		printf("*************** 五    子    棋 ****************\n");
		printf("***********************************************\n");
		printf("*************** 1.开 始 游 戏  ****************\n");
		printf("***********************************************\n");
		printf("*************** 2.进 入 设 置（敬请期待）******\n");
		printf("***********************************************\n");
		printf("*************** 0.退 出 游 戏  ****************\n");
		printf("***********************************************\n");

		printf("\n");
		printf("请选择(1/0):>");
		scanf("%d", &i);
		switch (i)
		{
		case  1:
			printf("game start!\n");
			gameView();
			break;
		case 2:
			break;
		case  0:
			printf("欢迎下次游玩本游戏:)\n");
			exit(0);
		default:
			printf("你输入的格式不正确，请重新输入\n");
			while ((ch = getchar()) != '\n' && ch != EOF);
		}
	} while (i);
}