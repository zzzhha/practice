#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>

//int main()
//{
//	int n;
//	int a = 1, b = 1, i = 1;
//	scanf("%d", &n);
//	if (n <= 2)
//	{
//		printf("1");
//	}
//	else
//	{
//		for (; i <= n-2; i++)
//		{
//			int tmp = a + b;
//			a = b;
//			b = tmp;
//		}
//	}
//	int ret = b;
//	printf("%d", ret);
//	return 0;
//}
//int Fibonacci(int n)
//{
//	if (n > 2)
//	{
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//	else
//		return 1;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret=Fibonacci(n);
//	printf("%d", ret);
//	return 0;
//}
//void to_base_n(unsigned long n, unsigned short x)
//{
//	int r;
//	r = n % x;
//	to_base_n(n / x, x);
//	printf("%d", r);
//}
//int main()
//{
//	unsigned long n;
//	unsigned short x;
//	scanf("%lu%hu", &n, &x);
//	to_base_n(n, x);
//}
//double power(double x, int y)
//{
//	if (x == 0)
//	{
//		if (y == 0)
//		{
//			printf("0的0次方未定义，返回1");
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	if (x == 1)
//	{
//		return 1;
//	}
//	if (y > 0)
//	{
//		
//		return x* power(x, y - 1);
//	}
//	else if (y == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 1 / x * power(x, y + 1);
//	}
//}
//int main()
//{
//	double x, xpow;
//	int exp;
//	while ((scanf("%lf%d", &x, &exp)) == 2)
//	{
//		xpow = power(x, exp);
//		printf("%lf", xpow);
//	}
//	return 0;
//}
//double power(double x, int y)
//{
//	double ret=1;
//	if (x == 0)
//	{
//		if (y == 0)
//		{
//			printf("0的0次方未定义，返回1");
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	if (x == 1)
//	{
//		return 1;
//	}
//	if (y > 0)
//	{
//		int i = 1;
//		for (; i <= y; i++)
//		{
//			ret *=  x;
//		}
//		return ret;
//	}
//	else if (y == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		int i;
//		for (i = y; i < 0; i++)
//		{
//			ret *= x;
//		}
//		return 1/ret;
//	}
//}
//int main()
//{
//	double x, xpow;
//	int exp;
//	while ((scanf("%lf%d", &x, &exp)) == 2)
//	{
//		xpow = power(x, exp);
//		printf("%lf", xpow);
//	}
//	return 0;
//}
//int alpha1(char ch)
//{
//	if (isupper(ch))
//	{
//		return ch - 'A' + 1;
//	}
//	else if (islower(ch))
//	{
//		return ch - 'a' + 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//int main()
//{
//	char ch,in;
//	int x;
//	while ((ch = getchar()) != EOF)
//	{
//		while (in = getchar() != '\n')
//		{
//			continue;
//		}
//		x = alpha1(ch);
//		if (x != -1)
//		{
//			printf("%d\n",x);
//		}
//	}
//	return 0;
//}
//void mysort(double* a, double* b, double* c)
//{
//	if (*a < *b)
//	{
//		double tmp = *b;
//		*a = *b;
//		*b = tmp;
//	}
//	if (*a < *c)
//	{
//		double tmp = *c;
//		*a = *c;
//		*c = tmp;
//	}
//	if (*b < *c)
//	{
//		double tmp = *c;
//		*b = *c;
//		*c = tmp;
//	}
//
//}
//int main()
//{
//	double a, b, c;
//	scnaf("%lf%lf%lf", & a, &b, &c);
//	mysort(&a, &b, &c);
//	return 0;
//}
//void larger_of(double *x, double *y)
//{
//	if (*x > *y)
//	{
//		*y = *x;
//	}
//	else
//	{
//		*x = *y;
//	}
//}
//int main()
//{
//	double x, y;
//	scanf("%lf%lf", &x, &y);
//	larger_of(&x, &y);
//	printf("%lf%lf", x, y);
//	return 0;
//}
//double tiaohe(double x, double y)
//{
//	double a = (1 / x + 1 / y)/2.0;;
//	double b = 1 / a;
//	return b;
//}
//int main()
//{
//	double x, y;
//	scanf("%lf%lf", &x, &y);
//	double ret=tiaohe(x, y);
//	printf("%lf", ret);
//	return 0;
//}
//void chline(char ch, int x, int y)
//{
//	int i = 1;
//	for (; i <= x; i++)
//	{
//		int j = 1;
//		for (; j <= y; j++)
//		{
//			printf("%c", ch);;
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	char ch;
//	int x, y;
//	scanf("%c%d%d", &ch, &x, &y);
//	chline(ch, x, y);
//	return 0;
//}
//double min(double x, double y)
//{
//	if (x < y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	double x, y;
//	scanf("%lf%lf", &x, &y);
//	printf("%lf",min(x, y));
//	return 0;
//}
//void menu()
//{
//	printf("******************************************************\n");
//	printf("******* 1) copy files******** 2) move files***********\n");
//	printf("******* 3) remove files******* 4) quit ***************\n");
//	printf("******************************************************\n");
//	printf("enter the number of your choice:>");
//}
//int midvalue(int max, int min)
//{
//	float x;
//	int y;
//	printf("plz input one int(if you input other size ,it will turn into int):>");
//	scanf("%f", &x);
//	y = (int)x;
//	if (y >= min && y <= max)
//	{
//		return y;
//	}
//	else
//	{
//		return 4;
//	}
//}
//int main()
//{
//	int n;
//	int a, b;
//	int ret;
//	
//	do
//	{
//		menu();
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			
//			printf("plz input two int,they will be max and min(the max in front of the min):>");
//			scanf("%d%d", &a, &b);
//			if (a <= b)
//			{
//				printf("error\n");
//				break;
//			}
//			ret=midvalue(a, b);
//			if (ret == 4)
//			{
//				n = 4;
//			}
//			break;
//		case 2:
//			printf("move files");
//			break;
//		case 3:
//			printf("remove files");
//			break;
//		case 4:
//			break;
//		default:
//			printf("error,plz input again\n");
//		}
//	} while (n != 4);
//	return 0;
//}