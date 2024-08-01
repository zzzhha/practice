#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>


//int main()
//{
//	int n = 5;
//	int i = 1;
//	for (; n <= 150; i++)
//	{
//		n -= i;
//		n *= 2;
//	}
//	printf("%d", n);
//	return 0;
//}
//int main()
//{
//	float a = 100;
//	int y = 0;
//	while (a > 0)
//	{
//		a += a * 0.08;
//		a -= 10;
//		y++;
//	}
//	printf("%d,%f", y, a);
//	return 0;
//}
//int main()
//{
//	float a, b;
//	a = b = 100;
//	int y = 0;
//	do
//	{
//		a += 100 * 0.1;
//		b +=  b* 0.05;
//		y++;
//	} while (a > b);
//	printf("%d %f %f", y,a,b);
//	return 0;
//}
//int main()
//{
//	char arr[255];
//	int i = 0;
//	gets(arr);
//	int sz = strlen(arr);
//	for (i=sz-1; i >= 0; i--)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	double arr[8];
//	double str[8];
//	int i = 0;
//	double sum = 0;
//	for (; i < 8; i++)
//	{
//		scanf("%lf", &arr[i]);
//	}
//	for (i = 0; i < 8; i++)
//	{
//		sum += arr[i];
//		str[i] = sum;
//	}
//	for (i = 0; i < 8; i++)
//	{
//		printf(" %lf", arr[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 8; i++)
//	{
//		printf(" %lf", str[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int arr[8];
//	int i = 0,j=0;
//	for (; i < 8; i++)
//	{
//		arr[i] = pow(2, i);
//	}
//	do
//	{
//		printf("%d ", arr[j]);
//	} while (++j < 8);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int  i = 1;
//	double sum=0;
//	for (; i <= n; i++)
//	{
//		if (i / 2 == 0)
//		{
//			sum -= 1.0 / i;
//		}
//		else
//		{
//			sum += 1.0 / i;
//		}
//	}
//	printf("%lf", sum);
//	return 0;
//}
//int main()
//{
//	int arr[8];
//	int i = 0;
//	for (; i < 8; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	for (i = sz-1; i >= 0; i--)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int max, min;
//	scanf("%d%d", &min, &max);
//	int i;
//	while(min!=max)
//	{
//		int sum=0;
//		for (i = min; i <= max; i++)
//		{
//			sum += i * i;
//		}
//		printf("%d %d %d\n", min*min, max*max, sum);
//		printf("next\n");
//		scanf("%d%d", &min, &max);
//	}
//	printf("done\n");
//	return 0;
//}
//int main()
//{
//	float a, b;
//	while(scanf("%f%f", &a, &b))
//	{
//		float c = a * b;
//		float d = a - b;
//		printf("%f\n", d / c);
//		printf("q to quit\n");
//	}
//	return 0;
//}