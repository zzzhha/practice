#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

//int main()
//{
//	int n;
//	scanf("%d\n",&n);
//	int i = 2;
//	int a, b;
//	scanf("%d %d", &a, &b);
//	double x = 1.0 * b / a;
//	for (i=2; i <= n; i++)
//	{
//		scanf("%d %d", &a, &b);
//		double y = 1.0 * b / a;
//		if (y - x > 0.05)
//			printf("better\n");
//		else if (x - y > 0.05)
//			printf("worse\n");
//		else
//			printf("same\n");	
//	}
//	return 0;
//}
//int main()
//{
//	int a,n;
//	scanf("%d\n", &n);
//	int i = 1;
//	for (i = 1; i <= n; i++)
//	{
//		int sum = 0;
//		int x = 1;
//		int y = 1;
//		int j = 1;
//		scanf("%d\n", &a);
//		if (a <= 2)
//		{
//			printf("1\n");
//		}
//		else
//		{
//			for (j = 1; j <= a-2; j++)
//			{
//				sum = x + y;
//				x = y;
//				y = sum;
//				
//			}
//			printf("%d\n", sum);
//		}
//	}	
//	return 0;
//}
//int main()
//{
//	int x, n;
//	scanf("%d%d", &x, &n);
//	double ret = 0;
//	double a = pow((1.0 + 0.001), n);
//	ret = x * a;
//	printf("%.4lf", ret);
//	return 0;
//}
//int main()
//{
//	int a, n;
//	scanf("%d%d", &a, &n);
//	int ret = pow(a, n);
//	printf("%d", ret);
//	return 0;
//}
//int main()
//{
//	int k = 0;
//	scanf("%d\n", &k);
//	int i = 0;
//	int count1 = 0;
//	int count2 = 0;
//	int count3 = 0;
//	int a = 0;
//	for (i = 0; i < k; i++)
//	{
//		scanf("%d", &a);
//		if (a == 1 )
//		{
//			count1++;
//		}
//		if (a == 5)
//		{
//			count2++;
//		}
//		if (a == 10)
//		{
//			count3++;
//		}
//	}
//	printf("%d\n%d\n%d\n", count1, count2, count3);
//	return 0;
//}