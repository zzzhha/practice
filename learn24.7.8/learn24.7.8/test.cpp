#include"learn24.7.8.h"

template <typename T>
T add (T& a, T& b)
{
	return a + b;
}

template <typename T1,typename T2>
auto add(T1& a, T2& b) ->decltype(a+b)
{
	auto temp = a + b;
	return temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	int s=add(a, b);
	cout << s << endl;

	double x = 11.4;
	double y = 5.14;
	double z = add(x, y);
	cout << z << endl;

	auto  g = add(a, x);
	cout << g << endl;
}