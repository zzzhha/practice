//#include "0.sort_text.h"


//void bubble_sort(int* arr, int l, int r)
//{
//	for (int i = r - 1, I = l + 1; i >= I; i--)
//	{
//		for (int j = l; j < i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//				swap(arr[j], arr[j + 1]);
//		}
//	}
//}
//
//void bubble_sort(int* arr, int l, int r) {
//	for (int i = l; i < r - 1; i++)
//	{
//		int flag = 1;
//		for (int j = l; j < r - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				flag = 0;
//				swap(arr[j], arr[j + 1]);
//			}
//		}
//		if (flag)
//			break;
//	}
//}
//
//int main()
//{
//	int* arr = getRandData(SMALL_DATA_N);
//	TEST(bubble_sort, arr, SMALL_DATA_N);
//	delete[] arr;
//	return 0;
//}