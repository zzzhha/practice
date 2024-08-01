#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char* x;
	x = "ABC";
	return 0;
}
//int main()
//{
//	double x, y;
//	scanf("%2lf", &x);
//	if (x < 0 && x != -3)
//	{
//		y = (x * x + x - 6);
//		printf("%.3lf", y);
//	}
//	else if (x >= 0 && x < 10 && x != 2 && x != 3)
//	{
//		y = x * x - 5 * x + 6;
//		printf("%.3lf", y);
//	}
//	else {
//		y = x * x - x - 1;
//		printf("%.3lf", y);
//	}
//	return 0;
//}

//void copy_arr2(double target1[], double source[], int n)
//{
//	int i = 0;
//	for (; i < n; i++)
//	{
//		target1[i] = source[i];
//	}
//}
//int main()
//{
//	double arr[10] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };
//	double arr1[10] = {0};
//	copy_arr2(arr1+3,arr+3, 3);
//	int i = 0;
//	for (; i < 10; i++)
//	{
//		printf(" %lf", arr1[i]);
//	}
//	return 0;
//}
//void copy_arr2(double target1[], double source[], int n)
//{
//	int i = 0;
//	for (; i < n; i++)
//	{
//		target1[i] = source[i];
//	}
//}
//void copy_arr(double(*arr)[5], double(*source)[5], int sz)
//{
//	int i = 0;
//	for (; i < sz; i++)
//	{
//		copy_arr2(arr[i], source[i], 5);
//	}
//}
//int main()
//{
//	double arr[3][5] = { 0 };
//	double source[3][5] = { 1.1,2.2,3.3,4.4,5.5 };
//	copy_arr(arr, source,3);
//	int i = 0;
//	for (; i < 3; i++)
//	{
//		int j = 0;
//		for (; j < 5; j++)
//		{
//			printf(" %lf", arr[i][j]);
//		}
//	}
//	return 0;
//}
//void reverse(int arr[], int sz)
//{
//	int i;
//	int* temp= NULL;
//	for (i = 0; i < (sz / 2); i++)
//	{
//		temp = arr[i];
//		arr[i] = arr[sz - i - 1];
//		arr[sz - i - 1] = temp;
//	}
//}
//int main()
//{
//	int arr[] = { 1,5,3,7,2,95,123,16 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	reverse(arr, sz);
//	int i = 0;
//	for (; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,5,3,7,2,95,123,16 };
//	int max = arr[0];
//	int i = 0,j=0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//			j = i ;
//		}
//	}
//	printf("%d", j);
//}
//int main() 
//{
//	int arr[] = { 1,5,3,7,2,95,123,16 };
//	int max = arr[0];
//	int i = 0;
//	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d", max);
//}
//void copy_arr(double target1[], double source[], int n)
//{
//	int i = 0;
//	for (; i < n; i++)
//	{
//		target1[i] = source[i];
//	}
//}
//void copy_ptr(double target2[], double source[], int m)
//{
//	int i = 0;
//	for (; i < m; i++)
//	{
//		*(target2 + i) = *(source+i);
//	}
//}
//void copy_ptrs(double target3[], double source[], double* ch)
//{
//	int i = 0;
//	for (; i < ch - source; i++)
//	{
//		*(target3 + i) = *(source + i);
//	}
//}
//int main()
//{
//	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
//	double target1[5];
//	double target2[5];
//	double target3[5];
//	copy_arr(target1, source, 5);
//	copy_ptr(target2, source, 5);
//	copy_ptrs(target3, source, source+5);
//	int i = 0;
//	for (; i < 5; i++)
//	{
//		printf("%f\n", target1[i]);
//		printf("%f\n", target2[i]);
//		printf("%f\n", target3[i]);
//	}
//	return 0;
//}
//#define MONTHS 12
//#define YEARS 5
//int main()
//{
//	const float rain[5][12] =
//	{
//		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
//		{8.5,8.2,4.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
//		{9.1,8.5,6.7,4.3,2.3,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
//		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
//		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
//	};
//	int year, month;
//	float subtot, total;
//	printf("YEAR RAINFALL (inches)\n");
//	for (year = 0, total = 0; year < 5; year++)
//	{
//		for (month = 0, subtot = 0; month < 12; month++)
//		{
//			subtot += *(*(rain + year) + month);
//		}
//			printf(" % 5d % 15.1f\n",2010+year,subtot);
//			total += subtot;
//	}
//	printf("\nthe yearlyaverage is %.1f inches.\n\n", total / 5);
//	printf("MONTHLY AVERAGES.\n\n");
//	printf(" JAN FEB MAR APR MAY JUN JUL AUG SEP OCT");
//	printf("NOV DEC\n");
//	for (month = 0; month < 12; month++)
//	{
//		for (year = 0, subtot = 0; year < 5; year++)
//		{
//			subtot += *(*(rain + year) + month);
//		}
//			printf("%4.1f", subtot / 5);
//		
//	}
//	return 0;
//}