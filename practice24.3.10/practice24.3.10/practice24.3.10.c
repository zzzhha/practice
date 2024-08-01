#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

//int main()
//{
//	char a;
//	printf("Press a key and then press Enter:");
//	scanf("%c", &a);
//	printf("%c", a + 32);
//	return 0;
//}
//int digui(int i)
//{
//	if (i > 10)
//		return (i % 10) + digui(i / 10);
//	else
//		return i;
//}
//int main()
//{
//	int i;
//	printf("请输入一个三位整数：");
//	scanf("%d", &i);
//	int a = i/100;
//	int b = i / 10 % 10;
//	int c = i % 10;
//	int sum = digui(i);
//	printf("b2=%d, b1=%d, b0=%d, sum=%d\n", a, b, c, sum);
//	return 0;
//}
//int main()
//{
//	float a, b, c;
//	printf("Input a,b,c:");
//	scanf("%f,%f,%f", &a, &b, &c);
//	float s = (a+b+c)/2;
//	float area = sqrt(s*(s - a)*(s - b)*(s - c));
//	printf("area = %.2f\n", area);
//	return 0;
//}
//int main()
//{
//	int i;
//	printf("Please enter a positive integer: ");
//	scanf("%d", &i);
//	i=fabs(i);
//	int a, b, c;
//	a = i / 100;
//	b = i / 10 % 10;
//	c = i % 10;
//	int sum = c * 100 + b * 10 + a;
//	printf("%d-->%d\n" ,i, sum);
//	return 0;
//}
//int main()
//{
//	int a;
//	printf("Please input your age: ");
//	scanf("%d", &a);
//	printf("The heart beats in your life: %d", a * 75 * 60 * 24 * 365);
//	return 0;
//}
//int main()
//{
//	float  x;
//	float y;
//	printf("Please input x and y:\n");
//	scanf("%f,%f", &x, &y);
//	float a=pow(x, 2);
//	float b = pow(y, 2);
//	float sum = a + b;
//	printf("result=%.2f\n", sum);
//	return 0;
//}
//int main()
//{
//	int i;
//	printf("Input x:");
//	scanf("%d", &i);
//	i=fabs(i);
//	int a, b, c;
//	a = i / 100;
//	b = i / 10 % 10;
//	c = i % 10;
//	int sum = c * 100 + b * 10 + a;
//	printf("y=%d\n", sum);
//	return 0;
//}