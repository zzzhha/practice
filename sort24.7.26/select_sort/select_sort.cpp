//#include "0.sort_text.h"
//
//
//void selection_sort(int* arr, int l, int r){
//	for (int i = l; i < r-1; i++)
//	{
//		int ind = i;
//		for (int j = i + 1; j < r; j++)
//		{
//			if (arr[j] < arr[ind])
//				ind = j;
//		}
//		swap(arr[i], arr[ind]);
//	}
//	return;
//}
//
//int main()
//{
//	int* arr = getRandData(SMALL_DATA_N);
//	TEST(selection_sort, arr, SMALL_DATA_N);
//	return 0;
//}