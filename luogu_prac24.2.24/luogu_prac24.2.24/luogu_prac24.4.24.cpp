#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cmath>
#include<climits>
using namespace std;


//int main()
//{
//	int sum = 0;
//	int i = 1;
//	int cost;
//	int store=0;
//	bool flag = 1;
//	for (; i <= 12; i++)
//	{
//		sum += 300;
//		cin >> cost;
//		sum -= cost;
//		if (sum < 0)
//		{
//			cout << (-i);
//			flag = 0;
//			break;
//		}
//		if (sum / 100)
//		{
//			store += sum / 100;
//			sum %=100;
//		}
//	}
//	if(flag)
//	{
//		cout << sum+(store * 120);
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int i = 0;
//	int arr1[3] = { 0 };
//	int arr2[3] = { 0 };
//	for (; i < 3; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		arr1[i] = x;
//		arr2[i] = y;
//	}
//	int min = INT_MAX;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (;; j++)
//		{
//			if (arr1[i] * j >= n)
//				break;
//		}
//		int ret = arr2[i] * j;
//		if (min > ret)
//			min = ret;
//	}
//	cout << min;
//	return 0;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	int ret = n * 10 + m;
//	cout << (ret / 19);
//	return 0;
//}
//double f(double x, int n)
//{
//	if (n > 1)
//		return 1.0 * x / (n + (f(x, n - 1)));
//	else
//		return 1.0*x / (1 + x);
//}
//int main()
//{
//	int n;
//	double x;
//	cin >> x;
//	cin >> n;
//	printf("%.2lf", f(x, n));
//	return 0;
//}
//double f(double x, double n)
//{
//	if (n > 1)
//	{
//		return sqrt(n + f(x, n - 1));
//	}
//	else
//		return sqrt(x + 1);
//}
//int main()
//{
//	double x, n;
//	cin >> x >> n;
//	printf("%.2lf", f(x, n));
//	return 0;
//}
//int her(int n, int x)
//{
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return 2 * x;
//	else
//		return 2 * x * her(n - 1, x) - 2 * (n - 1)*her(n - 2, x);
//}
//int main()
//{
//	int n, x;
//	cin >> n >> x;
//	cout<<her(n, x);
//	return 0;
//}
//int digit(int n, int k)
//{
//	int i = 1;
//	for (; i < k; i++)
//	{
//		n /= 10;
//	}
//	return n % 10;
//}
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	cout<<digit(n, k);
//	return 0;
//}
//int akm(int m, int n)
//{
//	if (m == 0)
//	{
//		return n + 1;
//	}
//	else if (n == 0&& m > 0)
//	{
//		return akm(m - 1, 1);
//	}
//	else
//	{
//		return akm(m-1,akm(m, n - 1));
//	}
//}
//int main()
//{
//	int n, m;
//	cin >> m >> n;
//	int ret=akm(m, n);
//	cout << ret;
//	return 0;
//}