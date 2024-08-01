#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int arr[100][100];
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < n; j++)
		{
			
		}
		printf("\n");
	}
	return 0;
}
//int main()
//{
//	int arr[105];
//	int n, i;
//	int count = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < n - 1; i++)
//	{
//		int j = i;
//		int s = i + 1;
//		for (; s < n ; s++)
//		{
//			for (int b = 0; b < n; b++)
//			{
//				if (arr[i] + arr[s] == arr[b])
//				{
//					count++;
//				}
//			}
//			
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int arr[105];
//	int i = 0;
//	for (; i < 100; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (arr[i] == 0)
//		{
//			break;
//		}
//	}
//	for (i = 0; i < 100; i++)
//	{
//		if (arr[i] ==0)
//		{
//			break;
//		}
//	}
//	for (;i>0; )
//	{
//		printf("%d ", arr[--i]);
//	}
//	return 0;
//}
//int main()
//{
//	int x, n;
//	scanf("%d%d", &x, &n);
//	int* p = (int*)malloc((x + 1) * sizeof(int));
//	if (p == NULL)
//	{
//		printf("error");
//		return 0;
//	}
//	int i = 0;
//	for (i=0; i < x+1; i++)
//	{
//		p[i] = 1;
//	}
//	for (i = 1; i <= n; i++)
//	{
//		int a, b;
//		scanf("%d%d", &a, &b);
//		for (int j = a; j < b; j++)
//		{
//			p[j] = 0;
//		}
//		p[b] = 0;
//	}
//	int count = 0;
//	for (i = 0; i < x+1; i++)
//	{
//		if (p[i] == 1)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	free(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	int arr[10];
//	int i = 0;
//	for (; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int n;
//	scanf("%d", &n);
//	int count = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (n+30 >= arr[i])
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int x = fabs(n);
//	int sum = 0;
//	while (x)
//	{
//		sum = sum * 10 + x % 10;
//		x /= 10;
//	}
//	if (n < 0)
//	{
//		sum = -sum;
//	}
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	long long l = 1, r, mid, n, a;
//	scanf("%lld", &n);
//	r = n;
//	while (l < r)
//	{
//		mid = (l + r) / 2;
//		if (mid * (mid + 1) / 2 < n)
//			l = mid + 1;
//		else
//			r = mid;
//	}
//	a = n - l * (l - 1) / 2;
//	if (l % 2 == 0)
//		printf("%lld/%lld", a, l + 1 - a);
//	else
//		printf("%lld/%lld", l + 1 - a, a);
//	return 0;
//}
//int main()
//{
//	int n, x;
//	scanf("%d%d", &n, &x);
//	int i = 1;
//	int count = 0;
//	for (; i <= n; i++)
//	{
//		if (i >= 10)
//		{
//			int w = i;
//			while (w)
//			{
//				if (w % 10 == x)
//				{
//					count++;
//				}
//				w /= 10;
//			}
//		}
//		else
//		{
//			if (i == x)
//			{
//				count++;
//			}
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int k,n=1;
//	scanf("%d", &k);
//	double sum = 0;
//	for (; sum <= (double)k; n++)
//	{
//		sum += 1.0 / n;
//	}
//	printf("%d", n-1);
//	return 0;
//}
//int main()
//{
//	int n, m;
//	int y = 0;
//	int max=0,x=0;
//	int i = 1;
//	for (; i <= 7; i++)
//	{
//		scanf("%d%d", &n, &m);
//		if ((n+m+y) > 8)
//		{
//			y = (m + n+y) - 8;
//		}
//		int sum = n + m + y;
//		if (max < sum&&sum>8)
//		{
//			max = sum;
//			x = i;
//		}
//		y = 0;
//	}
//	if (x != 0)
//	{
//		printf("%d", x);
//	}
//	else
//	{
//		printf("0");
//	}
//	return 0;
//}