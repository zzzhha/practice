#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>//353
//#include"pe12-2a.h"
#include<time.h>
#include<stdlib.h>

//int int_cmp(const int* p1, const int* p2)
//{
//	if (*p1 > *p2)
//		return -1;
//	else if (*p1 == *p2)
//		return 0;
//	else
//		return 1;
//}
//int main()
//{
//	srand((unsigned)time(NULL));
//	int i = 0;
//	int arr[105] = { 0 };
//	for(;i<100;i++)
//	{
//		arr[i] = rand() % 10;
//	}
//	qsort(arr, 100, 4, int_cmp);
//	for (i = 0; i < 100; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
//}
//int sum = 0;
//int show_count_add(int a, int b)
//{
//	
//	printf("%d\n",a+b);
//	sum++;
//	return sum;
//}
//int main()
//{
//	int count = 0;
//	int a, b;
//	int i = 0;
//	for(;i<10;i++)
//	{
//		scanf("%d%d", &a, &b);
//		if(a>0&&b>0)
//		{
//			count= show_count_add(a, b);
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//void set_mode(int mode)//自动变量版
//{
//	if (mode == 0)
//	{
//		printf("use metric mode:\n");
//	}
//	else if (mode == 1)
//	{
//		printf("use US mode:\n");
//	}
//	else
//	{
//		printf("error,plz try again\n");
//	}
//}
//void get_info(int mode,double *range,double *fuel)
//{
//	if (mode == 0)
//	{
//		printf("plz input the km");
//		scanf("%lf", range);
//		printf("plz input the fuel:");
//		scanf("%lf", fuel);
//	}
//	else if (mode == 1)
//	{
//		printf("plz input miles");
//		scanf("%lf", range);
//		printf("plz input gallon:");
//		scanf("%lf", fuel);
//	}
//}
//void show_info(int mode,double fuel,double range)
//{
//	if (mode == 0)
//	{
//		printf("%.2lf\n", (fuel / range) * 100.0);
//	}
//	else if(mode == 1)
//	{
//		printf("%.2lf\n", ( range / fuel) );
//	}
//}
//int main()
//{
//	int mode;
//	double fuel, range;
//	printf("Enter 0 for metric,1 for US mode:");
//	scanf("%d", &mode);
//	while (mode >= 0)
//	{
//		set_mode(mode);
//		get_info(mode,&range,&fuel);
//		show_info(mode, fuel, range);
//		printf("enter 0 for metric,1 for US mode:");
//		printf("(-1 to quit)");
//		scanf("%d", &mode);
//	}
//	printf("done");
//	return 0;
//}
//void critic(int *units)
//{
//	printf("no luck,my friend,try again");
//	scanf("%d", units);
//}
//void set_mode(int mode)//全局变量版
//{
//	if (mode == 0)
//	{
//		printf("use metric mode:\n");
//	}
//	else if (mode == 1)
//	{
//		printf("use US mode:\n");
//	}
//	else
//	{
//		printf("error,plz try again\n");
//	}
//}
//void get_info()
//{
//	if (mode == 0)
//	{
//		printf("plz input the km");
//	}
//	else if (mode == 1)
//	{
//		printf("plz input miles");
//	}
//	scanf("%lf", &range);
//	if (mode == 0)
//	{
//		printf("plz input the fuel:");
//	}
//	else if (mode == 1)
//	{
//		printf("plz input gallon:");
//	}
//	scanf("%lf", &fuel);
//}
//void show_info()
//{
//	if (mode == 0)
//	{
//		printf("%lf", (fuel / range) * 100);
//	}
//	else if(mode == 1)
//	{
//		printf("%lf", (fuel / range) );
//	}
//}
//int main()
//{
//	int mode;
//	printf("Enter 0 for metric,1 for US mode:");
//	scanf("%d", &mode);
//	while (mode >= 0)
//	{
//		set_mode(mode);
//		get_info();
//		show_info();
//		printf("enter 0 for metric,1 for US mode:");
//		printf("(-1 to quit)");
//		scanf("%d", &mode);
//	}
//	printf("done");
//	return 0;
//}
//void critic(int *units)
//{
//	printf("no luck,my friend,try again");
//	scanf("%d", units);
//}
//int main()
//{
//	int units;
//	scanf("%d", &units);
//	while (units != 56)
//	{
//		critic(&units);
//	}
//	printf("done");
//	return 0;
//}