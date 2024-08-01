#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int n, m;
	int sum = 0;
	scanf("%d %d", &n, &m);
	for (; n <= m; n++)
	{
		if (n % 17 == 0)
			sum += n;
	}
	printf("%d",sum);
	return 0;
}
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int sum = 0;
//	for (; n <= m; n++)
//	{
//		if (n % 2 != 0)
//			sum += n;
//	}
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	int n,i;
//	scanf("%d", &n);
//	int gold, sliver, cu;
//	int x=0, y=0, z=0,m;
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d %d %d", &gold, &sliver, &cu);
//		x += gold;
//		y += sliver;
//		z += cu;
//	}
//	m = x + y + z;
//	printf("%d %d %d %d",  x, y, z,m);
//	return 0;
//}
//int main()
//{
//	int n,i;
//	scanf("%d", &n);
//	int arr[100] = {0};
//	for (i = 0; i < n; i++)
//	{
//		int a;
//		scanf("%d", &a);
//		arr[i] = a;
//	}
//	for (i = 0; i < n-1; i++)
//	{
//		if (arr[i] > arr[i + 1])
//		{
//			int tmp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = tmp;
//		}
//	}
//	printf("%d", arr[n - 1]);
//	return 0;
//}
//int main()
//{
//	unsigned int n,i;
//	int sum=0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int a;
//		scanf("%d", &a);
//		sum += a;
//	}
//	double x = sum;
//	printf("%d ", sum);
//	printf("%.5lf", x / n);
//	return 0;
//}
//int main()
//{
//	int n,i;
//	scanf("%d", &n);
//	double sum=0;
//	for (i = 1; i <= n; i++)
//	{
//		double a;
//		scanf("%lf", &a);
//		sum += a;
//	}
//	printf("%lf", sum / n);
//	return 0;
//}
//int main()
//{
//	int n,i;
//	double sum = 0;
//	double x;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int a=0;
//		scanf("%d", &a);
//		sum += a;
//	}
//	x = sum / n;
//	printf("%.2lf", x);
//	return 0;
//}
//int main()
//{
//	double a, b, c,t;
//	scanf("%lf %lf %lf", &a, &b, &c);
//	t = b * b - 4 * a * c;
//	double x1, x2;
//	if (t < 0)
//		printf("No answer!");
//	else if (t == 0)
//	{
//		x1 = ((-b) - sqrt(t)) / (2.0 * a);
//		printf("x1=x2=%.5lf", x1);
//	}	
//	else if(t>0)
//	{
//		x1 = ((-b) - sqrt(t)) / (2.0*a);
//		x2 = ((-b) + sqrt(t)) / (2.0*a);
//		if (x1 > x2)
//		{
//			double tmp = x1;
//			x1 = x2;
//			x2 = tmp;
//		}
//		printf("x1=%.5lf;x2=%.5lf", x1, x2);
//	}
//	return 0;
//}
//int main()
//{
//	int a, b;
//	char c;
//	scanf("%d %d %c", &a, &b,&c);
//	if (c == '+')
//		printf("%d", a + b);
//	else if (c == '-')
//		printf("%d", a - b);
//	else if (c == '*')
//		printf("%d", a * b);
//	else if (c == '/')
//	{
//		if (b == 0)
//			printf("Divided by zero!");
//		else
//			printf("%d", a / b);
//	}
//	else
//		printf("Invalid operator!");
//	return 0;
//}
//int main()
//{
//	int x, y;
//	scanf("%d %d", &x, &y);
//	if ((x <= 1 && x >= -1) && (y <= 1 && y >= -1))
//		printf("yes");
//	else
//		printf("no");
//	return 0;
//}