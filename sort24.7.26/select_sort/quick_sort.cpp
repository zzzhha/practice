#include "0.sort_text.h"

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
int main()
{
	int* arr_s = getRandData(SMALL_DATA_N);
	int* arr_b = getRandData(BIG_DATA_N);
	TEST(quick_sort, arr_s, SMALL_DATA_N);
	TEST(quick_sort, arr_b, BIG_DATA_N);
	delete[]arr_s;
	delete[]arr_b;
	return 0;
}