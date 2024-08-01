#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//void print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	for (; i < x; i++)
//	{
//		int j = 0;
//		for (; j < y; j++)
//		{
//			printf("%d ", *(*(p+i)+j));
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print2(arr, 3, 5);
//	return 0;
//}
//int main()
//{
//	char* arr[5];//这是一个指针数组
//	char* (*pa)[5] = &arr;//这是一个指向指针数组的数组指针。
//	return 0;
//}
//int main()
//{
//	//int* p =NULL;//p是整形指针-指向整形的指针-可以存放整形的地址
//	//char* pc=NULLl;//pc是字符指针-指向字符的指针-可以存放字符的地址
//	                //数组指针-指向数组的指针-可以存放数组地址
//	//int arr[10]={0};
//	// arr -首元素地址
//	// &arr[0]-首元素地址
//	// &arr-数组的地址
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;//要存放数组的地址
//	//上面的p就是数组指针，如果不加括号，那么[]的优先级会高，会判断称指针数组(int* p[10])
//	//用括号把优先级改变使得（*p）优先级最高，形成数组指针。
//	return 0;
//}
//int main()
//{
//	const char* p = "abcdef";//abcdef是一个常量字符串，应无法被改变。为了防止用*p改变发生错误，我们用const去修饰*p，已达到*p无法改变的效果
//	
//	printf("%s\n", p);
//	return 0;
//}
