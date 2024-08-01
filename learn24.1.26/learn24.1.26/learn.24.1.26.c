#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i <= 12; i++)
	{
		printf("hehe\n");
		arr[i] = 0;//若出现循环则：，栈区默认使用是先使用高地址处的空间，再使用低地址处的空间
		//而数组是随着下标的增长，地址是由低到高变化的
		//如果发生越界访问则有可能遇到i，遇到i后将0值赋予i，导致造成死循环
	}
	system("pause");
	return 0;
}
//int main()//想输出3得到9，但是输出3得到15，错误在于ret未初始化
////ret在主函数中定义，未在for循环中定义，导致每次for循环ret的值
////会不断累计，最后导致代码错误，改正方法是删去主函数中ret，在第一个for循环中创建ret变量。
//{//此函数是为了计算1!+...+n!。
//	int i = 0;
//	int sum = 0;
//	int n = 0;
//	//int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int ret = 1;
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}