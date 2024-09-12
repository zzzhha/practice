//#include<algorithm>
//#include "0.sort_text.h"
//#include<vector>
//
// sort排序第三个参数是排序方式，可以用已提供的，也可以自己创造一个函数给他传进去
// 
//void output(int* arr, int n);
//
//
//
//template<typename T>
//void output(vector <T>& arr);
//
//
//
//class Node {
//public:
//	int a;
//	double b;
//	
//	int operator+()
//	{
//		return a + (int)b;
//	}
//};
//
//
//
//void test1()
//{
//	//sort array
//	int* arr = getRandData(10);
//	output(arr, 10);
//	sort(arr, arr + 10);//[ )左闭右开
//	output(arr, 10);
//	sort(arr, arr + 10, greater<int>());
//	output(arr, 10);
//}
//
//void test2()
//{
//	//sort vector
//	vector<int> arr;
//	for (int i = 0; i < 10; i++) arr.push_back(rand() % 10000);
//	output(arr);
//	sort(arr.begin(), arr.end());
//	output(arr);
//	sort(arr.begin(), arr.end(), greater<int>());
//	output(arr);
//}
//ostream&operator<< (ostream & out, const Data& d) {
//	out << "(" << d.x << ", " << d.y << ")";
//	return out;
//}
//
//struct Data {
//	int x, y;
//};
//
//bool cmp(const Data& a, const Data& b)
//{
//	if (a.x != b.x) return a.x < b.x;
//	return a.y > b.y;
//}
//
//
//
//void test3()
//{
//	cout <<endl << "tset my data structure:" << endl;
//	vector<Data>arr;
//	for (int i = 0; i < 10; i++)
//	{
//		Data d;
//		d.x = rand() % 10, d.y = rand() % 10;
//		arr.push_back(d);
//	}
//	output(arr);
//	sort(arr.begin(), arr.end(), cmp);
//}
//
////int main()
////{
////	test1();
////	test2();
////	test3();
////	return 0;
////}
//
//void output(int* arr, int n)
//{
//	printf("arr[%d]", n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return;
//}
//
//
//template<typename T>
//void output(vector <T>& arr)
//{
//	printf("vector[%lu]", arr.size());
//	for (int i = 0; i < arr.size(); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return;
//}