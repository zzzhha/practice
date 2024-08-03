//#include "0.sort_text.h"
#include"sort.h"
using namespace std;
//快排
template<typename T1>
T1 three_point_select(T1 a, T1 b, T1 c)
{
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	return b;
}

void unguarded_insert_sort(int* arr, int l, int r)
{
	int ind = l;
	for (int i = l + 1; i < r; i++)
	{
		if (arr[i] < arr[ind])ind = i;
	}
	while (ind > l)
	{
		swap(arr[ind], arr[ind - 1]);
		ind--;
	}
	for (int i = l + 1; i < r; i++)
	{
		int j = i;
		while ( arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
	return;
}

#define threshold 16

void __quick_sort_v4(int* arr, int l, int r)//通过减少判断条件来优化快排
{	
	while (r - l > threshold)
	{
		int x = l, y = r - 1;
		int z = three_point_select(arr[l], arr[r - 1], arr[(l + r) / 2]);
		do {
			while (z > arr[x])++x;
			while (arr[y] > z)--y;
			if (x <= y)
			{
				swap(arr[y], arr[x]);
				++x, --y;
			}
		} while (x <= y);
		__quick_sort_v4(arr, l, y + 1);
			l = x;		
	}
	return;
}

void quick_sort_v4(int* arr, int l, int r)//通过减少判断条件来优化快排
{
	__quick_sort_v4(arr, l, r);
	unguarded_insert_sort(arr, l, r);
	return ;
}


void quick_sort_v3(int* arr, int l, int r)//通过减少判断条件来优化快排
{
	if (r - l <= 2)
	{
		if (r - l <= 1)return;
		if (arr[l] > arr[l + 1])
			swap(arr[l], arr[l + 1]);
		return;
	}
	while (l < r)
	{
		int x = l, y = r - 1;
		int z = three_point_select(arr[l], arr[r - 1], arr[(l + r) / 2]);
		while (x <= y)
		{
			while (z > arr[x])++x;
			while (arr[y] > z)--y;
			if (x <= y)
			{
				swap(arr[y], arr[x]);
				++x, --y;
			}
		}
		quick_sort_v3(arr, l, x);
		l = x;
	}
	return;
}



void quick_sort_v2(int* arr, int l, int r)//通过减少判断条件来优化快排
{
	if (r - l <= 2)
	{
		if (r - l <= 1)return;
		if (arr[l] > arr[l + 1])
			swap(arr[l], arr[l + 1]);
		return;
	}
	int x = l, y = r - 1;
	int z = three_point_select(arr[l],arr[r-1],arr[(l+r)/2]);
	while (x <= y)
	{
		while (z > arr[x])++x;
		while (arr[y] > z)--y;
		if (x <= y)
		{
			swap(arr[y], arr[x]);
			++x, --y;
		}
	}
	quick_sort_v2(arr, l, x);
	quick_sort_v2(arr, x, r);
	return;
}


void quick_sort_v1(int* arr, int l, int r)//通过减少判断条件来优化快排
{
	if (r - l <= 2)
	{
		if (r - l <= 1)return;
		if (arr[l] > arr[l + 1])
			swap(arr[l], arr[l + 1]);
		return;
	}
	int x = l, y = r - 1, z = arr[l];
	while (x <= y)
	{
		while (z > arr[x])++x;
		while ( arr[y] > z)--y;
		if (x <= y)
		{
			swap(arr[y], arr[x]);
			++x, --y;
		}
	}
	quick_sort_v1(arr, l, x);
	quick_sort_v1(arr, x, r);
	return;
}

void quick_sort(int* arr, int l, int r)
{
	if (r - l <= 2)
	{
		if (r - l <= 1)return;
		if (arr[l] > arr[l + 1])
			swap(arr[l], arr[l + 1]);
		return;
	}
	int x = l, y = r - 1, z = arr[l];
	while (x < y)
	{
		while (x < y && z <= arr[y])--y;
		if (x < y) arr[x++] = arr[y];
		while (x < y && arr[x] <= z)++x;
		if (x < y)arr[y--] = arr[x];
	}
	arr[x] = z;
	quick_sort(arr, l, x);
	quick_sort(arr, x + 1, r);
}
//int main()
//{
//	int* arr_s = getRandData(SMALL_DATA_N);
//	int* arr_b = getRandData(BIG_DATA_N);
//	//TEST(quick_sort, arr_s, SMALL_DATA_N);
//	TEST(quick_sort, arr_b, BIG_DATA_N);
//	TEST(quick_sort_v1, arr_b, BIG_DATA_N);
//	TEST(quick_sort_v2, arr_b, BIG_DATA_N);
//	TEST(quick_sort_v3, arr_b, BIG_DATA_N);
//	TEST(quick_sort_v4, arr_b, BIG_DATA_N);
//	delete[]arr_s;
//	delete[]arr_b;
//	return 0;
//}
