#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <limits.h>

int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	int i = 0;
	int j = 0;
	int arr1[100][100] = { 0 };
	int arr2[100][100] = { 0 };
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			int a = 0;
			scanf("%d", &a);
			arr1[i][j] = a;
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr1[j][i]);
		}
		printf("\n");
	}
	return 0;
}
//int main()
//{
//	int arr1[100][100] = { 0 };
//	int arr2[100][100] = { 0 };
//	int arr3[100][100] = { 0 };
//	int i = 0;
//	int j = 0;
//	int n, m;
//	int  y;
//	scanf("%d%d%d", &n,&m,&y);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			int a = 0;
//			scanf("%d", &a);
//			arr1[i][j] = a;
//		}
//	}
//	
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			int  b = 0;
//			scanf("%d", &b);
//			arr2[i][j] = b;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			int k = 0;
//			int sum = 0;
//			for (k = 0; k < m; k++)
//			{
//				sum += arr1[i][k] * arr2[k][j];
//			}
//			arr3[i][j] = sum;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr3[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	int arr1[100][100] = { 0 };
//	int arr2[100][100] = { 0 };
//	int arr3[100][100] = { 0 };
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			int a = 0;
//			scanf("%d", &a);
//			arr1[i][j] = a;
//		}
//	}
//	
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			int a = 0;
//			scanf("%d", &a);
//			arr2[i][j] = a;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			printf( "%d ",arr1[i][j] + arr2[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
	//int n, m;
	//scanf("%d%d",&n,&m);
	//int arr1[100][100] = { 0 };
	//int arr2[100][100] = { 0 };
	//int i = 0;
	//int j = 0;
	//int count = 0;
	//for (i = 0; i < n; i++)
	//{
	//	for (j = 0; j < m; j++)
	//	{
	//		int a = 0;
	//		scanf("%d", &a);
	//		arr1[i][j] = a;
	//	}
	//}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			int a = 0;
	//			scanf("%d", &a);
	//			arr2[i][j] = a;
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			if (arr1[i][j] == arr2[i][j])
	//			{
	//				count++;
	//			}
	//		}
	//	}
	//	double ret = 1.0*count / (m * n)*100;
	//	printf("%.2lf", ret);
	//	return 0;
//}
//int main()
//{//题目同下，法二：
//	int arr[5][5] = {0};
//	int arrh[5][5] = { 0 };//记录arr数组中每一行的最大值，并记录至相应位置
//	int arrl[5][5] = { 0 };//记录arr数组中每一列的最小值，并记录至相应位置
//	int i = 0;
//	int j = 0;
//	for (i=0; i < 5; i++)
//	{
//		for (j=0; j < 5; j++)
//		{
//			int a = 0;
//			scanf("%d", &a);
//			arr[i][j] = a;
//		}
//	}
//	for (i = 0; i < 5; i++)
//	{
//		int max_h = INT_MIN;
//		int y = 0;
//		for (j = 0; j < 5; j++)//遍历一行
//		{
//			if (max_h < arr[i][j])
//			{
//				max_h = arr[i][j];//更新每一行的最大值
//				y = j;//记录此行的最大值；
//			}
//		}
//		arrh[i][y] = max_h;//将这一行的最大值记录到arrh的相应位置，总共记录5次，共会产生5组数据。
//	}
//	for (i = 0; i < 5; i++)
//	{
//		int max_l = INT_MAX;
//		int x = 0;
//		for (j=0; j < 5; j++)//遍历一列
//		{
//			if (max_l > arr[j][i])
//			{
//				max_l = arr[j][i];
//				x = j;
//			}
//		}
//		arrl[x][i] = max_l;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			if (arrh[i][j] != 0 && arrl[i][j] != 0)
//			{
//				printf("%d %d %d", i+1, j+1, arrl[i][j]);
//				return 0;
//			}
//		}
//	}
//	printf("not found");
//	return 0;
//}
//int main()//给定一个 5×5
////的矩阵，每行只有一个最大值，
//// 每列只有一个最小值，寻找这个矩阵的鞍点。
//// 鞍点指的是矩阵中的一个元素，它是所在行的最大值，并且是所在列的最小值。
//// //法1
//{
//	int arr[5][5] = { 0 };
//	int i = 0,j=0,k=0;
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int x = 0;
//	int ret = 0;
//	for (i = 0; i < 5; i++)//i列
//	{
//		//这种方法有点难以理解，每次if语句需要是的它的否定，
//		// 如果进if语句说明当前arr[i][j]不符合题目要求
//		//如果一直不进if则表明当前arr[i][j]就是行最大列最小的。
//		//
//		for (j = 0; j < 5; j++)//j行
//		{
//			int flag = 1;
//			for (x = 0; x < 5; x++)
//			{
//				if (arr[x][j] < arr[i][j])//判断j列是否为最小
//				{//接上文，从否定去看，如果arrp[i][j]为最小，那么就小于所有的arr[x][j]
//				//所以如果有arr[x][j]小于arr[i][j]那么arr[i][j]就不是最小的。
//					flag = 0;//不是就跳出去
//					break;
//				}
//			}
//			for (x = 0; x < 5; x++)
//			{
//				if (arr[i][x] > arr[i][j])//判断i行是否为最大，理由同上。
//				{
//					flag = 0;
//					break;
//				}
//			}
//			if (flag)//上两次循环中只要有一次行不为最大列不为最小则不满足条件
//			{
//				ret++;
//				printf("%d %d %d", i+1, j+1, arr[i][j]);
//			}
//		}
//	}
//	if (ret == 0)//ret等于0说明上面最外面的循环，每次循环都不符合条件。
//	{
//		printf("not found");
//	}
//	return 0;
//}

//int main()
//{
//    int m, n;
//    scanf("%d%d", &m, &n);
//    int i = 1, j = 1;
//    int sum = 0;
//    for (i = 1; i <= m; i++)
//    {
//        for (j = 1; j <= n; j++)
//        {
//            int a;
//            scanf("%d ", &a);
//            if ((i == 1 || i == m) || (j == 1 || j == n))
//            {
//                sum += a;
//            }
//        }
//    }
//    printf("%d", sum);
//    return 0;
//}