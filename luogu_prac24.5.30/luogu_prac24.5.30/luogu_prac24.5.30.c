#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	char arr[1000];
	char str[1000];
	gets(arr);
	gets(str);
	int sum = 1;
	int ret = 1;
	for (int i = 0; i < strlen(arr); i++)
	{
		sum *= arr[i] - 'A' + 1;
	}
	for (int i = 0; i < strlen(str); i++)
	{
		ret *= str[i] - 'A' + 1;
	}
	sum %= 47;
	ret %= 47;
	if (sum == ret)
	{
		printf("GO");
	}
	else
		printf("STAY");
	return 0;
}
//int main()
//{
//	int n, m;
//	int count = 0;
//	scanf("%d%d", &n, &m);
//	for (; n <= m; n++)
//	{
//		int a = n;
//		while (a)
//		{
//			if (a % 10 == 2)
//				count++;
//			a /= 10;
//		}
//	}
//	printf("%d", count);
//}
//
//int prime(int i)
//{
//	for (int j = 2; j <= sqrt(i); j++)
//	{
//		if (i % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 4; i <= n; i+=2)
//	{
//		for(int j=2;j<i;j++)
//		{
//			if (prime(j) && prime(i - j))
//			{
//				printf("%d=%d+%d\n", i, j, i - j);
//				break;
//			}
//		}
//	}
//	return 0;
//}
//int a[2000001];
//int main()
//{
//	int t;
//	int n;
//	
//	double x, y;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%lf%lf",&x,&y);
//		for (double j = 1; j <= y; ++j)
//		{
//			if (a[(int)(j * x)] == 0)
//				a[(int)(j * x)] = 1;
//			else
//				a[(int)(j * x)] = 0;
//		}
//	}
//	for (int i = 1;; i++)
//	{
//		if (a[i] == 1)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[1000];
//	int cha[1000];
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < n-1; i++)
//	{
//		 cha[i] = abs(arr[i] - arr[i + 1]);
//	}
//	for (int i = 0; i < n - 1; i++)
//	{
//		for(int j = 1; j < n;j++)
//		{
//			if (cha[i] == j)
//			{
//				count++;
//				break;
//			}
//		}
//	}
//	if (count == n-1 )
//	{
//		printf("Jolly");
//	}
//	else
//	{
//		printf("Not jolly");
//	}
//	return 0;
//}
//int main()
//{
//	int k;
//	scanf("%d", &k);
//	int flag = 0;
//	for (int i = 10000; i <= 30000; i++)
//	{
//		int a = i / 100;
//		int b = i / 10 % 1000;
//		int c = i % 1000;
//		if (a % k == 0 && b % k == 0 && c % k == 0)
//		{
//			printf("%d\n", i);
//			flag++;
//		}
//	}
//	if (!flag)
//	{
//		printf("No");
//	}
//	return 0;
//}