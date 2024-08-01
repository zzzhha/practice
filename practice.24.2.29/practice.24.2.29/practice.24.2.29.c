#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

//int main()//	求小数的某一位
//{
//	int a, b, n;
//	scanf("%d %d %d", &a, &b, &n);
//	//double c = 1.0 * a / b;
//	//c -= (int)c;
//	int i = 1;
//	for (; i < n; i++)
//	{
//		a %= b;
//		a *= 10;
//	}
//	a /= b;
//	printf("%d", a);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 1;
//	int sum = 0;
//	for (; i <= n; i++)
//	{
//		sum += i;
//	}
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	int x = 2;
//	for (; x <= a && x <= b && x <= c; x++)
//	{
//		if (a % x == b % x && b % x == c % x)
//		{
//			printf("%d", x);
//			break;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	double s = 0,y=0;
//	int n;
//	scanf("%d", &n);
//	int i = 1,x=0;
//	for (; i <= n; i++)
//	{
//		x = pow((-1), (i-1));
//		y = x * 1.0 / i;
//		s += y;
//	}
//	printf("%.4lf", s);
//	return 0;
//}
//int main()
//{
//	int p[30] = { 0 };
//	int q[30] = { 0 };
//	p[0] = 1;
//	q[0] = 2;
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	double x = 0;
//	for (; i < n; i++)
//	{
//		x += 1.0*q[i] / p[i];
//		p[i + 1] = q[i];
//		q[i + 1] = q[i] + p[i];
//	}
//	printf("%.4lf", x);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 1;
//	int a;
//	int count = 0;
//	
//	for (; i <= n; i++)
//	{
//		scanf("%d", &a);
//		int j = 1;
//		int ret = 0;
//		int b = a / 10;
//		int sum = a % 10;
//		for (; j <= 4; j++)
//		{
//			ret += b % 10;
//			b /= 10;
//			
//		}
//		if (sum > ret)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int people;
//	scanf("%d", &people);
//	int i = 0;
//	int x, y = n, count = 0;
//	for (; i < people; i++)
//	{
//		scanf("%d", &x);
//		if (y >= x)
//		{
//			y -= x;
//		}
//		else
//		{
//			count++;
//		}	
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{	
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	double tmp = 0;
//	for (; i < n; i++)
//	{
//		int c;
//		double a, b;
//		scanf("%lf %lf %d", &a, &b, &c);
//		double x = a*a+b*b;
//		double y = sqrt(x);
//		double z = y / 25;
//		while (c--)
//		{
//			z++;
//			z += 0.5;
//		}
//		tmp += z;
//	}
//	int sum = (int)tmp;
//	if (sum < tmp)
//	{
//		sum += 1;
//	}
//	printf("%d",sum);
//	return 0;
//}