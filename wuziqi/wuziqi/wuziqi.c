#define  _CRT_SECURE_NO_WARNINGS 1
#include"wuziqi.h"

int flag ;//��ʾ��ǰ�غ���
void winView()
{
	if (flag % 2)
	{
		printf("��ϲ���������ʤ����\n");
	}
	else
	{
		printf("��ϲ���������ʤ����\n");
	}
}
int isWin(int x, int y)//�жϰ��ӻ��ߺ����Ƿ�ʤ��������ƽ��
{
	int i, j;
	int count = 1;//��¼��ǰ�������Աߵ�����ӵ��ж��ٸ�
	int gg=0 ;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 19; j++)
		{
			if (map[i][j] == 0)
				continue;
			if (j < 19 - 4)//�����Ƿ�ʤ��
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
			if(i< 19 -4)//�����Ƿ�ʤ��
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
			if (i < 19 - 4 && j < 19 - 4)//�����������Ƿ�ʤ��
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
			if ((i < 19 - 4) && (j >= 4))//�����������Ƿ�ʤ��
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
	if (gg)//�ж�ӮûӮ
	{
		if (flag % 2 == 1)
		{
			return 1;//����Ӯ��
		}
		else
		{
			return 2;//����Ӯ��
		}
	}
	else
	{
		return 0;//û�л�ʤ
	}
}
int playerMove(int x, int y)//����ƶ�
{
	if (x > 19 || y > 19)
	{
		printf("���Ӵ���������һ��(��ҪС�ڵ���%d,��ҪС�ڵ���%d)\n", 19, 19);
		return 0;
	}
	else if (map[x - 1][y - 1] != 0)
	{
		printf("���Ӵ���,������");
		return 0;
	}
	else
	{
		if (flag % 2)//�����ƶ�
		{

			map[x - 1][y - 1] = 1;
			return 1;
		}
		else//�����ƶ�
		{
			map[x - 1][y - 1] = 2;
			return 1;
		}
	}
}
	
void gameView_ShowMap()//չʾ����
{
	int i = 0;
	for (i = 0; i < 19; i++)
	{
		int j = 0;
		for (j = 0; j < 19; j++)
		{
			printf(" %d ", map[i][j]);//��ӡ��ǰ��������
			if (j != 19 -1)
			{
				printf("|");//��ӡ�����е����ܣ�ÿ���������м�һ�����ܣ����������û��
			}
		}
		printf("\n");//���д�ӡһ�к��
		for (j = 0; j < 19; j++)
		{
			if (i != 19 -1)//��ӡ�����еĺ�ܣ�ÿ���������м�һ����ܣ����Ϻ����±�û��
			{
				printf("___ ");
			}
		}
		printf("\n");//���м�����ӡ�������ݺ�����
	}
}
void init()
{
	flag = 1;
	int i;//����map��
	for (i = 0; i < 19; i++)
	{
		int j;//������
		for (j = 0; j < 19; j++)
		{
			map[i][j] = 0;//ʹmap����ȫΪ0
		}
	}
}
void gameView()
{
	init();//��ʼ������
	gameView_ShowMap();
	while(1)
	{
		int x, y;
		printf("��%d�غ�\n", flag);
		if (flag % 2)
		{
			printf("���������:>");
		}
		else
		{
			printf("���������:>");
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
					printf("ƽ�֣�\n");
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
		printf("*************** ��    ��    �� ****************\n");
		printf("***********************************************\n");
		printf("*************** 1.�� ʼ �� Ϸ  ****************\n");
		printf("***********************************************\n");
		printf("*************** 2.�� �� �� �ã������ڴ���******\n");
		printf("***********************************************\n");
		printf("*************** 0.�� �� �� Ϸ  ****************\n");
		printf("***********************************************\n");

		printf("\n");
		printf("��ѡ��(1/0):>");
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
			printf("��ӭ�´����汾��Ϸ:)\n");
			exit(0);
		default:
			printf("������ĸ�ʽ����ȷ������������\n");
			while ((ch = getchar()) != '\n' && ch != EOF);
		}
	} while (i);
}