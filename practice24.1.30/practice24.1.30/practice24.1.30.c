#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	double a;
	scanf("%lf", &a);
	printf("%.2lf\n", (a < 0) ? -a : a);
	return 0;
}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	if (n > 0) 
//	{
//		printf("positive");
//	}
//	else if (n == 0)
//	{
//		printf("zero");
//	}
//	else
//	{
//		printf("nagetive");
//	}
//	return 0;
//}
//int main()
//{
//	int i, n,c=1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		c*= 2;
//	}
//	printf("%d", c);
//	return 0;
//}
//int main()
//{
//	unsigned int a, b;
//	scanf("%d%d", &a, &b);
//	printf("%d", a * b);
//	return 0;
//}
//int main()
//{
//	int a, b,n;
//	scanf("%d%d%d", &a, &b,&n);
//	int c = b - a;
//	printf("%d", a+c*(n-1));
//	return 0;
//}
//double zhixian(double x1, double y1, double x2, double y2) 
//{
//	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
//}
//int main()
//{
//	double x1, y1, x2, y2, x3, y3;
//	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
//	double a = zhixian(x1, y1, x2, y2);
//	double b = zhixian(x1, y1, x3, y3);
//	double c = zhixian(x2, y2, x3, y3);
//	double p = (a + b + c) / 2;
//	double s = sqrt(p * (p - a) * (p - b) * (p - c));
//	printf("%.2lf", s);
//	return 0;
//}
//int main()
//{
//	int a, b, x, y;
//	scanf("%d%d\n%d%d", &a, &b, &x, &y);
//	float l = sqrt((a - x) * (a - x) + (b - y) * (b - y));
//	printf("%.3f", l);
//	return 0;
//}
//int main()
//{
//	int h, r;
//	scanf("%d %d", &h, &r);
//	float v = 3.14 * r * r * h;
//	int t = 20000 / v + 1;
//	printf("%d", t);
//	return 0;
//}
//int main()
//{
//	int i,a,b,c;
//	scanf("%d", &i);
//	a = i / 100;
//	b = i / 10 % 10;
//	c = i % 10;
//	printf("%d%d%d", c, b, a);
//	return 0;
//}
//int  main()
//{
//	double r;
//	scanf("%lf", &r);
//	double v = 4.0 / 3  * 3.14*r*r*r;
//	printf("%.5lf", v);
//	return 0;
//}
//int main()
//{
//	double a, b,r;
//	int k;
//	scanf("%lf%lf", &a, &b);
//	k = a / b;
//	r = a - (k * b);
//	printf("%lf", r);
//	return 0;
//}

//int main()
//{
//    printf(
//        "  *\n"
//        " ***\n"
//        "*****\n"
//        " ***\n"
//        "  *\n");
//	return 0;
//}
//int main()
//{
//	char a;
//	int i;
//	float f;
//	double d;
//	scanf("%c\n%d\n%f\n%lf", &a, &i, &f, &d);
//	printf("%c %d %.6f %.6lf", a, i, f, d);
//	return 0;
//}
//int main()
//{
//	double d;
//	scanf("%lf", &d);
//	printf("%.12lf", d);
//	return 0;
//}
//int main()
//{
//	float f;
//	scanf("%f", &f);
//	printf("%.3f", f);
//	return 0;
//}
//int main()
//{
//	int a, b, c, d, e;
//	int sum=0;
//	scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
//	sum += (a % 3);
//	a /= 3,b += a,e += a;
//	sum += b % 3;
//	b /= 3,c += b,a += b;
//	sum += c % 3;
//	c /= 3,d += c,b += c;
//	sum += d % 3;
//	d /= 3,e += d,c += d;
//	sum += e % 3;
//	e /= 3,d += e,a += e;
//	printf("%d %d %d %d %d \n%d", a, b, c, d, e, sum);
//	return 0;
//}
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	if (x)
//	{
//		printf("1");
//	}
//	else
//		printf("0");
//	return 0;
//}
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	printf("%c", x);
//	return 0;
//}
//int main()
//{
//	char x;
//	scanf("%c", &x);
//	printf("%d", x);
//	return 0;
//}
//int main()
//{
//	long long i;
//	scanf("%lld", &i);
//	printf("%lld", i);
//	return 0;
//}