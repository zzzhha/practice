#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int prime(int n)
{
	int i = 2;
	for (; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int s;
	scanf("%d", &s);
	int i = 1;
	int max = 0;
	for (;i<=s;i++)
	{
		for (; !prime(i); i++)
		{
			;
		}
		if (prime(s - i))
		{
			if (max < i * (s - i))
			{
				max = i * (s - i);
			}
		}
	}
	printf("%d", max);
	return 0;
}
//int main()
//{
//	int i = 1;//共有多少家
//	int n;//输入的数，控制最外部的循环
//	int j = 1;
//	scanf("%d", &n);
//	for (; ; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			if (i * (i + 1) / 2 - 3 * j == n)
//			{
//				printf("%d %d\n", j, i);
//				return 0;
//			}
//		}
//	}
//}
//int main()
//{
//	int i = 1;//共有多少家
//	int n;//输入的数，控制最外部的循环
//	int y=0;//我家门牌号
//	int sum = 0;
//	int j = 1;
//	scanf("%d", &n);
//	for (; ; i++)
//	{
//		sum += i;//门牌号总和
//		for (j = 1; j <= i; j++)
//		{
//			//统计到i家一共有多少
//			if (!((sum - n) % 3) && (sum - n)>0)
//			{
//				y = (sum - n) / 3;
//				printf("%d %d\n", y, i);
//				break;
//			}
//		}
//		if (y)
//		{
//			break;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int y = 2;
//	int n;
//	int count = 0;
//	scanf("%d", &n);
//	int i = 2;
//	for (; i <= n; i++)
//	{
//		int j = 2;
//		int flag = 1;
//		for (; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (i - y == 2&&flag)
//		{
//			printf("%d %d\n", y,i);
//			count++;
//		}
//		if (flag)
//		{
//			y = i;
//		}
//	}
//	if (count == 0)
//	{
//		printf("empty");
//	}
//	return 0;
//}
//struct people
//{
//	char name[10];
//	float temper;
//	int kesou;
//};
//int main()
//{
//	int n;
//	int count = 0;
//	scanf("%d", &n);
//	struct people* p = (struct people*)malloc(sizeof(struct people) * n);
//	int i = 0;
//	for (; i < n; i++)
//	{
//		scanf("%s %f %d", p[i].name, &p[i].temper, &p[i].kesou);
//	}
//	for (i = 0; i < n; i++)
//	{
//		if (p[i].kesou&&p[i].temper>=37.5)
//		{
//			printf("%s\n", p[i].name);
//			count++;
//		}
//	}
//	free(p);
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	char ch;
//	int a, b;
//	scanf("%d%c%d", &a, &ch, &b);
//	if (ch == '+')
//	{
//		printf("%d", a + b);
//	}
//	else if (ch == '-')
//	{
//		printf("%d", a - b);
//	}
//	else if (ch == '*')
//	{
//		printf("%d", a * b);
//	}
//	else if (ch == '/')
//	{
//		printf("%d", a / b);
//	}
//	else if (ch == '%')
//	{
//		printf("%d", a % b);
//	}
//	return 0;
//}
//#define MAX(a,b,c) (((a)>(c))?((a)>(b)?(a):(b)):((c)>(b)?(c):(b)))
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	double m = MAX(a, b, c) / (1.0 * (MAX(a + b, b, c) * MAX(a, b, b + c)));
//	printf("%.3f", m);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 2;
//	int count = 0;
//	for (; i <= n; i++)
//	{
//		int flag = 1;
//		int j = 2;
//		for (; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//
//	int i = 2;
//	int n;
//	scanf("%d", &n);
//	for (; i <= n; i++)
//	{
//		int j = 1;
//		int sum = 0;
//		for (; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				sum += j;
//			}
//		}
//		if (sum == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	int count = 1;
//	scanf("%d", &n);
//	char arr[1005] = {0};
//	scanf("%s", arr);
//	char* str = arr;
//	int i = 1;
//	for(;i<strlen(arr)-1;i++)
//	{
//
//		if (*str == arr[i])
//		{
//			count++;
//		}
//		else
//		{
//			count = 1;
//		}
//		if (count == n)
//		{
//			printf("%c", * (str - 1));
//			break;
//		}	
//		str++;
//	}
//	if (count != n)
//	{
//		printf("No");
//	}
//	return 0;
//}