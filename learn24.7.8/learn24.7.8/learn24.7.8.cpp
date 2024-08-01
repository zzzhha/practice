#include"learn24.7.8.h"




////作业
//template<class T>
//class input
//{
//public:
//	T min;
//	T max;
//	input() {};
//	input(int a, int b)
//	{
//		min = a;
//		max = b;
//	}
//	void output(T a) {
//		if (min<= a && a <= max) {
//			cout << a << endl;
//		}
//		else {
//			cout << "数据不符合范围，请重新输入。";
//		}
//	}
//};
//int main()
//{
//	int x, y,z;
//	cin >> x >> y >> z;
//	input<int> ob(x, y);
//	ob.output(z);
//	return 0;
//}
//template<typename T>
//void three_value(T a[], int size)
//{
//	T min=a[0];
//	T max=a[0];
//	double average=0;
//	double sum = 0;
//	for (int i = 0; i < size; i++)
//	{
//		sum += a[i];
//		if (min > a[i])
//			min = a[i];
//		if (max < a[i])
//			max = a[i];
//	}
//	average = sum / size;
//	cout << "min=" << min << endl << "max=" << max << endl << "average=" << average << endl;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	double ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	three_value(arr, 10);
//	three_value(ar, 10);
//	return 0;
//}
//template<class T>
//class text 
//{
//public:
//	text() {};
//	void show();
//};
//
//template<class T>
//void text<T>::show()//类外实现模板类的成员函数
//{
//	cout << "调用text模板show（）成员函数" << endl;
//}
//
//typedef text<int> text_int; //为一个实例化的类模板 起别名
//
//template<class T>//c++11特性，用using 为类模板的模板名 起别名
//using t = text<T>;
//
//int main()
//{
//	text<int> wow;//原本名来实例化类模板
//	wow.show();
//	text_int qwerty;//用别名来实例化
//	qwerty.show();
//	t<int> ttt;//用类模板的模板别名来实例化
//	ttt.show();
//	return 0;
//}
//template <typename T>
//T add(T& a, T& b)
//{
//	return a + b;
//}
//
//template <typename T1, typename T2>
//auto add(T1& a, T2& b)->decltype(a+b)
//{
//	return a + b;
//}


//int func()
//{
//	cout << "调用了func函数\n";
//	return 1;
//}
//int main()
//{
//	//test01();
//	// 	array<int, 5>(1, 2, 3, 4, 5);
//	short a = 10;
//	int b = 20;
//	short& ra = a;
//
//	decltype(func)da;//此时da为int da（）  的函数 不会执行func（）函数
//	decltype(func())da;//此时da是int 类型的
//	decltype(func)*da=func;//此时da是int （）函数类型的指针
//
//	decltype(++a)da = a;//此时da是int&类型
//	decltype((a))da=a;//此时da是int&类型
//	decltype((func))da=func;//此时da是int（）
//	auto da = func();//此时da是int （）函数类型，但是会执行func（）函数
//	
//	return 0;
//}
