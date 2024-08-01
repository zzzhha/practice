#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>


int main()
{
	int n;
	scanf("%d", &n);
	int i = 1;
	int sum = 0;
	for (; i <= n; i++)
	{
		if(i%7==0|| i % 10 == 7 || i / 10 % 10 == 7)
		{ }
		else
		{
			sum += i * i;
		}
	}
	printf("%d", sum);
	return 0;
//}
//int main()
//{
//	int n;
//	float x;
//	scanf("%f%d", &x, &n);
//	int i = 0;
//	double sum = 0;
//	for (; i <= n; i++)
//	{
//		sum += pow(x, i);
//	}
//	printf("%.2lf", sum);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 1;
//	double e = 1.0;
//	double sum = 1.0;
//	for (; i <= n; i++)
//	{
//		e *= i;
//		sum += 1.0 / e;
//	}
//	printf("%.10lf", sum);
//	return 0;
//}
//int main()
//{
//	int count = 0;
//	int k;
//	long long m;
//	scanf("%lld%d", &m, &k);
//	while (m > 10)
//	{
//		int a = m % 10;
//		if (a == 3)
//		{
//			count++;
//		}
//		m /= 10;
//	}
//	if (m == 3)
//	{
//		count++;
//	}
//		if (count == k)
//	{
//		printf("YES");
//	}
//	else
//		printf("NO");
//	return 0;
//}
//int jug(long long m, int k)
//{
//	int a = m % 7;
//	int count = 0;
//	if (a == k)
//	{
//		count++;
//	}
//	jug(m / 10,k);
//	return count;
//}
//int main()
//{
//	long long m;
//	int k;
//	scanf("%lld%d", &m, &k);
//	int ret = jug(m, k);
//	if (ret == 3)
//	{
//		printf("YES");
//	}
//	else
//		printf("NO");
//	return 0;
//}
//int main()
//{
//	long long sum;
//	scanf("%lld", &sum);
//	
//	while (sum != 1)
//	{
//		long long tmp = sum;
//		if (sum % 2 == 1)
//		{
//			sum = tmp * 3 + 1;
//			printf("%lld*3+1=%lld\n", tmp, sum);
//		}
//		else
//		{
//			sum /= 2;
//			printf("%lld/2=%lld\n", tmp, sum);
//		}
//	}
//	printf("End");
//	return 0;
//}
//int main()
//{
//	int h;
//	scanf("%d", &h);
//	double sum = h;
//	int n = 2;
//	double m = h;
//	for(;n<=10;n++)
//	{
//		m /= 2.0;
//		sum += 2*m;
//	}
//	printf("%.4lf\n", sum);
//	printf("%lf", m/2);
//	return  0;
//}
//main()
//{
//    double b;
//    long a = 65535;
//    int c, d;
//    char f, g;
//
//    b = (1234.0 - 1) / 10;
//    scanf("%d %d %c\n", &c, &d, &f);
//    scanf(" %c", &g);
//    printf("%d,%d,%c,", c, d, f);
//    printf("%c,%lf,%ld", g, b, a);
//}
//int main()
//{
//    int h, r, n;
//    double a = 0;
//    printf("please input the height and the radius:\n");
//    scanf("%d,%d", &h, &r);
//    a = 3.14159 * r * r * h / 1000.0;
//    n = ceil(20 / a);
//    printf("%d", n);
//        return 0;
//}
//int main()
//{
//    int x;
//    int a, b, c, d, n, m, y, sum;
//    printf("input x:\n");
//    scanf("%d", &x);
//    x = fabs(x);
//    n = x / 1000;
//    m = x / 100 % 10;
//    d = x / 10 % 10;
//    c = x % 10;
//        a = c * 10 + d;
//    b = (m * 10 + n);
//    y = (c * 1000 + d * 100 + m * 10 + n);
//    printf("y=%d\n", y);
//    printf("a=%d,b=%d\n", a, b);
//    sum = a * a + b * b;
//    printf("result=%d\n", sum);
//    return 0;
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d",&a,&b);
//	int i = 1;
//	int n = 1;
//	for (; i <= b; i++)
//	{	
//		n *= a % 1000;
//		n %= 1000;
//	}
//	if (n < 10)
//		printf("00%d", n);
//	else if (n > 100)
//		printf("%d", n);
//	else
//		printf("0%d", n);
//	return 0;
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int i = 1;
//	int n = 1;
//	for (; i <=b ; i++)
//	{
//		n *= a % 7;
//		n = n % 7;
//	}
//	switch (n)
//	{
//	case 0:
//		printf("Sunday");
//		break;
//	case 1:
//		printf("Monday");
//		break;
//	case 2:
//		printf("Tuesday");
//		break;
//	case 3:
//		printf("Wednesday");
//		break;
//	case 4:
//		printf("Thursday");
//		break;
//	case 5:
//		printf("Friday");
//		break;
//	case 6:
//		printf("Saturday");
//		break;
//	}
//	return 0;
//}