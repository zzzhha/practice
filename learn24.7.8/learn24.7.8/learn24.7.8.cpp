#include"learn24.7.8.h"




////��ҵ
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
//			cout << "���ݲ����Ϸ�Χ�����������롣";
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
//void text<T>::show()//����ʵ��ģ����ĳ�Ա����
//{
//	cout << "����textģ��show������Ա����" << endl;
//}
//
//typedef text<int> text_int; //Ϊһ��ʵ��������ģ�� �����
//
//template<class T>//c++11���ԣ���using Ϊ��ģ���ģ���� �����
//using t = text<T>;
//
//int main()
//{
//	text<int> wow;//ԭ������ʵ������ģ��
//	wow.show();
//	text_int qwerty;//�ñ�����ʵ����
//	qwerty.show();
//	t<int> ttt;//����ģ���ģ�������ʵ����
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
//	cout << "������func����\n";
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
//	decltype(func)da;//��ʱdaΪint da����  �ĺ��� ����ִ��func��������
//	decltype(func())da;//��ʱda��int ���͵�
//	decltype(func)*da=func;//��ʱda��int �����������͵�ָ��
//
//	decltype(++a)da = a;//��ʱda��int&����
//	decltype((a))da=a;//��ʱda��int&����
//	decltype((func))da=func;//��ʱda��int����
//	auto da = func();//��ʱda��int �����������ͣ����ǻ�ִ��func��������
//	
//	return 0;
//}
