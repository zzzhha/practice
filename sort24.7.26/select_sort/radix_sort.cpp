//#include "0.sort_text.h"
#include"sort.h"
using namespace std;
//»ùÊýÅÅÐò
void radix_sort(int* arr, int l, int r)
{
	#define K 65536
	int* cnt = new int[K];
	int* temp = new int[r - l];
	memset(cnt, 0, sizeof(int) * K);
	for (int i = l; i < r; i++)cnt[arr[i] % K]+=1;
	for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
	for (int i = r - 1; i >= l; i--)temp[--cnt[arr[i] % K]] = arr[i];
	memcpy(arr + l, temp, sizeof(int) * (r - l));
	memset(cnt, 0, sizeof(int) * K);
	for (int i = l; i < r; i++)cnt[arr[i] / K] += 1;
	for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
	for (int i = r - 1; i >= l; i--)temp[--cnt[arr[i] / K]] = arr[i];
	memcpy(arr + l, temp, sizeof(int) * (r - l));
	return;
}
//int main()
//{
//	int* arr_s = getRandData(SMALL_DATA_N);
//	int* arr_b = getRandData(BIG_DATA_N);
//	TEST(radix_sort, arr_s, SMALL_DATA_N);
//	TEST(radix_sort, arr_b, BIG_DATA_N);
//	delete[]arr_s;
//	delete[]arr_b;
//	return 0;
//}