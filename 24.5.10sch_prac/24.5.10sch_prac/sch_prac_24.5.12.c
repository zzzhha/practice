#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

#include <stdio.h>
#define N 40
int ReadScore(int income[], long num[]);
int LinSearch(long num[], long x, int n);
int main()
{
	int income[N], n, pos;
	long num[N], x;
	n = ReadScore(income, num);
	printf("Total number is %d\n", n);
	printf("Input the searching ID:");
	scanf("%d", &x);
	pos = LinSearch(num, x, n);
	if (pos != -1)
	{
		printf("income = %d", income[pos-1]);
	}
	else
	{
		printf("Not found!\n");
	}
	return 0;
}

int ReadScore(int income[], long num[])
{
	int i=0;
	do
	{
			printf("Input person's ID and income:");
			scanf("%d%ld", &num[i], &income[i]);
			i++;
	} while (num[i-1] >= 0 &&income[i-1] >= 0);
		return i-1;
}

int LinSearch(long num[], long x, int n)
{
	int  i;
	for (i = 0; i < n; i++)
	{
		if (num[i] == x)  return (i);
	}
	return (-1);
}
//struct node
//{
//    int nextp;
//    int no_out;
//} 	   link[31];
//main()
//{
//    int i, j, k;
//    printf("The original circle is (+:papandom,  @:christian);\n");
//    for (i = 1; i <= 30; i++)
//    {
//        link[i].nextp = i + 1;//指向数组的下一个元素（类似与链表）
//        link[i].no_out = 1;//代表人，1没淘汰0淘汰了
//    }
//    link[30].nextp = 1;//使末尾的结构体指向开头，形成一个圈
//    j = 30;//指向最后一个人
//    for (i = 0; i < 15; i++)
//    {
//        for (k = 0;;)
//            if (k < 9)
//            {
//                j = link[j].nextp;//第一次使他指向第一位人，后续就指向后面的人
//                k += link[j].no_out;//数数，当数到9的时候退出去
//            }
//            else break;
//        link[j].no_out = 0;//k=9的时候，相对应的人死亡
//    }
//    for (i = 1; i <= 30; i++)
//        printf("%c ", link[i].no_out ? '@' : '+');//打印
//    printf("\n");
//
//}
//int main()
//{
//	int arr[10];
//	int i = 0;
//	printf("Input 10 numbers:");
//	int max;
//	int min;
//	for (; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	max = arr[0];
//	min = arr[0];
//	int max_x = 0;
//	int min_x = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//			max_x = i;
//		}
//		if (min > arr[i])
//		{
//			min = arr[i];
//			min_x = i;
//		}
//	}
//	printf("Max element position:%d,Max element:%d\n", max_x,max);
//	printf("Min element position:%d,Min element:%d\n", min_x,min);
//	printf("Exchange results:");
//	arr[max_x] = min;
//	arr[min_x] = max;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%4d", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int arr[10];
//	int n = 10;
//	
//	printf("Please input %d numbers:\n",n);
//	for (int i = 0; i < 10; i++)
//	{
//		int sum = 0;
//		scanf("%d", &arr[i]);
//		for (int j = 0; j <= i; j++)
//		{
//			sum += arr[j];
//		}
//		printf("%5d", sum);
//	}
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int j = 0;
//
//	for (int i = 100; i < 1000; i++)
//	{
//		int a = i % 10;//个位
//		int b = i / 10 % 10;//十位
//		int c = i / 100;
//		if ((pow(a,3)+pow(b,3)+pow(c,3) == i))
//		{
//			arr[j++] = i;
//		}
//	}
//	printf("There are following Armstrong number smaller than 1000:\n");
//	for (int i = 0; i < j; i++)
//	{
//		printf(" %d ", arr[i]);
//	}
//	return 0;
//}