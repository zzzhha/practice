//#include "0.sort_text.h"
#include"sort.h"
using namespace std;
////πÈ≤¢≈≈–Ú

int* buff=new int[1000000];
void merge_sort(int* arr, int l, int r) {
	if (r - l <= 1)
		return;
	int mid = (l + r) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid, r);
	int p1 = l, p2 = mid, k = 0;
	while (p1 < mid || p2 < r)
	{
		if (p2 == r || (p1 < mid && arr[p1] <= arr[p2]))
		{
			buff[k++] = arr[p1++];
		}
		else
			buff[k++] = arr[p2++];
	}
	for (int i = l; i < r; i++)
	{
		arr[i] = buff[i - l];
	}
	return;
}
//
//int main()
//{
//	int* arr_s = getRandData(SMALL_DATA_N);
//	int* arr_b = getRandData(BIG_DATA_N);
//	
//	TEST(merge_sort, arr_s, SMALL_DATA_N);
//	TEST(merge_sort, arr_b, BIG_DATA_N);
//	delete[]arr_s;
//	delete[]arr_b;
//	delete[]buff;
//	return 0;
//}