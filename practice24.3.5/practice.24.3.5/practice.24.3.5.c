#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<malloc.h>

//int main()
//{
//	int people;
//	scanf("%d", &people);
//	int i = 0;
//	int x = 0;
//	int y = 0;
//	int z = 0;
//	int c = 0;
//	int arr[100] = { 0 };
//	for (; i < people; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i=0; i < people; i++)
//	{
//		if (arr[i] < 19)
//		{
//			x++;
//		}
//		if (arr[i] > 18&&arr[i]<36)
//		{
//			y++;
//		}
//		if (arr[i] > 35 && arr[i] < 61)
//		{
//			z++;
//		}
//		if (arr[i] > 60 )
//		{
//			c++;
//		}
//	}
//	printf("%.2f%%\n", 1.0 * x / people * 100);
//	printf("%.2f%%\n", 1.0 * y / people * 100);
//	printf("%.2f%%\n", 1.0 * z / people * 100);
//	printf("%.2f%%\n", 1.0 * c / people * 100);
//	return 0;
//}
//int main()
//{
//	int arr[100] = { 0 };
//	int n;
//	scanf("%d", &n);
//	int i = 1;
//	for (; i <= n; i++) 
//	{
//		scanf("%d", &arr[i]);
//	} 
//	for ( i = n; i >= 1; i--)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	double arr[10] = { 28.9,32.7,45.6,78.0,35.0,86.2,27.8,43.0,56.0,65.0 };
//	int i = 0;
//	double sum = 0;
//	for (; i < 10; i++)
//	{
//		int a;
//		scanf("%d", &a);
//		sum += a * arr[i];
//	}
//	printf("%.1lf", sum);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int* p = (int*)calloc(n, 4);
//	if (p != NULL)
//	{
//		int i = 0;
//		int a;
//		int count = 0;
//		for (; i < n; i++)
//		{
//			scanf("%d", &a);
//			*(p + i) = a;
//		}
//		int b;
//		scanf("%d", &b);
//		for (i=0; i < n; i++)
//		{
//			if (*(p + i) == b)
//			{
//				count++;
//			}
//		}
//		printf("%d", count);
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	int x = 0;
//	int count = 0;
//	for (; x <= c; x++)
//	{
//		int y = 0;
//		for (; y <= c; y++)
//		{
//			if (a * x + b * y == c)
//			{
//				count++;
//			}
//		}
//	}
//	printf("%d", count);
//	return 0;
//}