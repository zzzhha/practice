#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//int main()
//{
//	cout << "Input two FENSHU :"<<endl;
//	int a, b;
//	int x, y;
//	cin >> a >> b >> x >> y;
//	if ((float)a / (float)b > (float)x / (float)y)
//	{
//		cout << a << "/" << b << ">" << x << "/" << y << endl;
//	}
//	else if ((float)a / (float)b < (float)x / (float)y)
//	{
//		cout << a << "/" << b << "<" << x << "/" << y << endl;
//	}
//	else
//	{
//		cout << a << "/" << b << "=" << x << "/" << y << endl;
//	}
//	return 0;
//}
//unsigned long  Fact(unsigned int  n)
//{
//	unsigned int i = 1;
//	int  sum = 1;
//	for (; i <= n; i++)
//	{
//		sum *= i;
//	}
//	return sum;
//}
//int main()
//{
//	unsigned int a, b;
//	cout << "Input m,k (m>=k>0):";
//	cin >> a >> b;
//	while (a <= 0 || b <= 0||a<b)
//	{
//		cin >> a >> b;
//	}
//	int c = Fact(a) / (Fact(b) * Fact(a - b));
//	cout << "The combination is " << c << endl;
//	return 0;
//}