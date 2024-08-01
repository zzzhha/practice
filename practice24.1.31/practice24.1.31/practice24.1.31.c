#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
		printf("1");
	else
		printf("0");
	return 0;
}
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	
//	if (a < b)	
//		a = b;
//	if (a < c)
//		a = c;
//	printf("%d", a);
//	return 0;
//}
//int main()
//{
//	int i, x;
//	char a;
//	scanf("%d %c", &i,&a);
//	if (i <= 1000 && a == 'y')
//		printf("13");
//	else if (i <= 1000 && a == 'n')
//		printf("8");
//	if(i>1000)
//	{
//		i = i - 1000;
//		x = i / 500;
//		if (i % 500 != 0)
//		{
//			x += 1;
//		}
//		if (a == 'y')
//			printf("%d", 8 + 4 * x + 5);
//		else if (a == 'n')
//			printf("%d", 8 + 4 * x );
//	}
//	return 0;
//}
//int main()
//{
//	double i, y;
//	scanf("%lf", &i);
//	if (i >= 0 && i < 5.0)
//		printf("%.3lf", -i + 2.5);
//	if (i >= 5 && i < 10)
//		printf("%.3lf", 2 - 1.5 * (i - 3) * (i - 3));
//	if (i >= 10 && i < 20)
//		printf("%.3lf", i / 2.0 - 1.5);
//	return 0;
//}
//int main()
//{
//	int s;
//	double t2,t3;
//	scanf("%d", &s);
//	t2 = s / 1.2;
//	t3 = s / 3.0 + 27.0 + 23.0;
//	if (t3 > t2)
//		printf("Walk");
//	else if (t3 < t2)
//		printf("Bike");
//	else
//		printf("All");
//	return 0;
//}
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	if (i != 1 && i != 3 && i != 5)
//		printf("YES");
//	else
//		printf("NO");
//	return 0;
//}
//int bujige(int x)
//{
//	if (x < 60)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int a, b, c,count=0,i;
//	scanf("%d %d %d", &a, &b, &c);
//	count += bujige(a);
//	count += bujige(b);
//	count += bujige(c);
//	if (count == 1)
//		printf("1");
//	else
//		printf("0");
//	return 0;
//}
//int main()
//{
//	int i,n;
//	scanf("%d", &n);
//	for(i=3;i<=7;i+=2)
//	{
//		if (n % i == 0)
//			printf("%d ", i);
//	}
//	if (n % 3 != 0 && n % 5 != 0 && n % 7 != 0)
//		printf("n");
//	return 0;
//}
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	if (i % 3 == 0 && i % 5 == 0)
//		printf("YES");
//	else
//		printf("NO");
//	return 0;
//}
//int main()
//{
//	int x, y;
//	scanf("%d %d", &x, &y);
//	if (x >= 10 || y >= 20)
//		printf("1");
//	else
//		printf("0");
//	return 0;
//}
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	if (i >= 10 && i <= 99)
//		printf("1");
//	else
//		printf("0");
//	return 0;
//}
//int main()
//{
//	int x, y;
//	scanf("%d%d", &x, &y);
//	if (x > y)
//		printf(">");
//	else if (x < y)
//		printf("<");
//	else
//		printf("=");
//	return 0;
//}
//int main()
//{
//	char i;
//	scanf("%c", &i);
//	if (i % 2 == 0)
//				printf("NO");
//			else
//				printf("YES");
//	return 0;
//}
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	if (i % 2 == 0)
//		printf("even");
//	else
//		printf("odd");
//	return 0;
//}