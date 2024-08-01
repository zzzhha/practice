#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>

////函数声明
//int Add(int x, int y);//此处xy可写可不写,要加“；”一般子程序此处不加“；”
////如果你的函数（子程序）没有写在主函数上面而是写在了主函数的下面
////则我们需要先声明有此函数再进行使用。
////因为一般程序是从上往下读取的，子程序在主函数下面会导致无法读取子函数
////而出现报错，故可以在上方声明有此函数
//int main()
//{
//	int a = 10;
//	int b = 10;
//	int sum = 0;
//	sum = Add(a, b);//函数调用
//	printf("%d\n", sum);
//		return 0;
//}
//int Add(int x  , int y)//函数定义
// 不建议这么写代码。
// 函数的定义与声明不是这么用的。
// 一般是头文件里声明函数，源文件里写函数的定义
// 若你要在其他源文件中使用到此函数就在开头调用
// 接上文，开头调用#include"add.h"(所谓“库”)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	printf("%d",printf("%d",printf("%d",43)));
//	//函数嵌套：将一个函数的返回值作为另一个函数的参数
//	return 0;
//}
//int add(int a, int b)//每使用一次函数则记录此函数使用次数加一
//{
//	int c;
//	c = a + b;
//	return c;
//	
//}
//void increase(int* a)
//{
//	
//	(*a )++;
//}
//int main()
//{
//	int num=0,a=1,b=2,c=0;
//	c=add(a, b );
//	increase(&num);
//	printf("%d\n%d", c,num);
//	return 0;
//}
//int binary_search(int arr[], int k,int sz)//二分查找函数
////int sz = sizeof(arr) / sizeof(arr[0]);
////这步错误，不能在函数中求数组长度
////此处的由主函数传进来的arr为arr中第一个数的地址
////因为是地址故我们函数（子程序）中写的“int arr[]”为一个地址
////既是指针。指针的大小只有系统位数（32or64）决定是4还是8，
////故在函数（子程序）内部求数组长度（数组有几个数）是不行的要在主函数里去求
//{
//	int left = 0, right = sz - 1;
//	while (left <= right)//此处是小于等于，若缺少等于可能会漏掉一种情况。既下标相等.
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k=7;
//	int ret = binary_search(arr, k,sz);
//	if (ret == -1)
//	{
//		printf("找不到指定的数字\n");
//	}
//	else
//		printf("找到了下标是%d",ret);
//	return 0;
//}
// 
//int run(int x)//查找闰年
//{
//	if ((x % 4 == 0 && x % 100 != 0) ||( x % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int a,b=0;
//	for (a = 1000; a <= 2000; a++)
//	{
//	
//		if (run(a) == 1)
//		{  
//			b++;
//			printf("%d  ", a);
//		}
//	
//	}
//	printf("\n%d", b);
//	return 0;
//}
//int is_prime(int n)//查找100-200内的质数
//{
//	int z = 2;
//	for(;z<=sqrt(n);z++)
//	{
//		if (n % z == 0 )//判断能不能被其他数整除
//		{
//			return 0;//能被整除直接调用表达式为0
//		}
//	}
//	return 1;//没有数能整除则调用表达式为1
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//int is_prime(int n)
//{
//	int z=1;
//	while(1)
//	{
//		z++;
//		if (n % z == 0 && n / z != 1)//判断能不能被其他数整除
//		{
//			break;
//		}
//		else if (n % z == 0 && n / z == 1)//判断是否为质数
//			return 1;
//	
//	}
//	return 0;
//}
//int main()//
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d\n", i);
//	}
//	return 0;
//}
//void zhishu(int x)
//{
//	int i,n=0;
//	for (i = 1; i <= x; i++)
//	{
//		if (x % i == 0 )
//		{
//			n++;	//统计能被整除的数，若大于2则不是质数，若等于二则为质数
//		}	
//	}
//	 if (n == 2||x==1)
//		printf("是质数");
//}
//
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	zhishu(a);
//	return 0;
//}

//void exchance(int* x, int* y)//用函数交换两个变量
////int*x，int*y取得主函数括号中两个变量地址，用*x和*y储存起来
////用void是因为此函数无返回值，viod为无返回值类型。
////若有返回值则主函数中调用表达式（即为主函数中使用到这个函数的地方就叫调用表达式）
////接上文，主函数中调用表达式就会被赋予返回值既return x的x值。
//{
//	int z;
//	z = *x;
//	*x = *y;
//	*y = z;//交换变量值
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d",&a,&b);
//	printf("a=%db=%d\n", a, b);
//	exchance(&a, &b);//改变ab的值，用取地址符得到ab的地址，将他交给exchange函数变化
//	printf("a=%db=%d\n", a, b);//因为地址中存放的值被改变（地址未变，地址中存放的值改变）故ab值交换。
//	return 0;
//}

//int Compare(int x, int y)
//{
//	if (x >= y)
//		return x;
//	else 
//		return y;
//}
//int main()
//{
//	int a, b,c;
//	scanf(" %d%d", &a, &b);
//	c= Compare(a, b);//连接上面的交换函数，此处不用取地址符是因为有回归值，
// //接上文，回归值作用为1.结束函数（子程序），消除调用的变量单位，2.送函数值到调用表达式中
// //接上文，调用表达式即为我们所用的Compare，此时Compare（a，b）已经是返回值中返回的数据
// //接上文，既，compare（a，b）为一个数，将这个数赋予c即可达成目的。
//	printf("%d", c);
//	return 0;
//}