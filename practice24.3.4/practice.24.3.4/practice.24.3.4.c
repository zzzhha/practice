#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>

int detect(int a)
{
	int i = 2;
	for (; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	int count = 1;
	scanf("%d", &n);//第n个素数
	while (n != 0)
	{
		count++;
		if (detect(count) == 1)
		{
			n--;
		}
	}
	printf("%d", count);
	return 0;
}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 2;
//	for (; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			printf("%d", n / i);
//		}
//	}
//	return 0;
//}
//int main()//实心矩阵和空心矩阵
//{
//	int a,b,f;
//	char c;
//	int i = 1;
//	scanf("%d %d %c %d", &a, &b,&c,&f);
//	if (f == 0)
//	{
//		for (; i <= a; i++)
//		{
//			
//			int j = 1;
//			for (; j <= b; j++)
//			{
//				if ((i == 1 || i == a) || (j == 1 || j == b))
//				{
//					printf("%c", c);
//				}
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	else
//	{
//		for (; i <= a; i++)
//		{
//			int j = 1;
//			for (; j <= b; j++)
//			{
//				printf("%c", c);
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
// 
//int detect2(int x,int y)//检测多少个2（递归）
//{
//	if (x % 10 == 2)
//	{
//		y++;	
//	}
//	if(x>=10)
//	{
//		return detect2(x / 10,y);
//	}
//	return y;
//}
//int main()
//{
//	int a, s, i = 0;
//	int sum = 0;
//	scanf("%d %d", &a, &s);
//	for (; a <= s; a++)
//	{
//		sum+=detect2(a,i);
//	}
//	printf("%d", sum);
//	return 0;
//}