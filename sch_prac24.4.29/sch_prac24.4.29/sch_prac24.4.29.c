#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Gcd(int a, int b)
{
	return b==0 ? a : Gcd(b, a % b);
}
int main()
{
	int a, b;
	printf("Input a,b:");
	scanf("%d,%d", &a, &b);
	int x = Gcd(a, b);
	if  (a <= 0 || b <= 0)
	{
		printf("Input number should be positive!\n");
	}
	else
	printf("Greatest Common Divisor of %d and %d is %d\n",a,b,x);
	return 0;
}
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 2) + Fib(n - 1);
//	}
//}
//int main()
//{
//	int n;
//	printf("Input n:");
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		printf("Fib(%d)=%d\n", i, Fib(i));
//	}
//	return 0;
//}
//int digui(int x, int n)
//{
//	if (n > 1)
//		return x * (digui(x, n - 1));
//	else
//		return x;
//}
//int main()
//{
//	int x, n;
//	printf("x=? n=?");
//	scanf("%d %d", &x, &n);
//	printf("%d",digui(x, n));
//	return 0;
//}
//int MaxCommonFactor(int a, int b);
//
//main()
//{
//    int a, b, x;
//    printf("Input a,b:");
//    scanf("%d,%d", &a, &b);
//    x = MaxCommonFactor(a, b);
//    if (x < 0)  
//        printf("Input Error!\n");
//    else
//    printf("%d\n", x);
//}
//
//int MaxCommonFactor(int a, int b)
//{
//    if (a <= 0 || b <= 0)
//        return -1;
//        if (a > b)
//            return MaxCommonFactor(b, a - b);
//        else if (b > a)
//            return MaxCommonFactor(a, b - a);
//        else 
//            return a;
//
//}
//int suishu(int n, int x)
//{
//	if (x > 0)
//	{
//		return 2 + suishu(n, x - 1);
//	}
//	else
//		return n;
//}
//int main()
//{
//	int n = 10;
//	int x = 5;
//	printf("%d", suishu(n,x));
//	return 0;
//}
//unsigned long Factorial(int n)
//{
//	if (n < 0)
//	{
//		printf("data error!");
//		return 0;
//	}
//	else if (n == 0 || n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * Factorial(n - 1);
//	}
//}
//main()
//{
//	int n;
//	unsigned long x;
//	printf("Input n:\n");
//	scanf("%d", &n);
//	x = Factorial(n);
//	printf("%d!=%ld\n", n, x);
//}