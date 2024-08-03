//#include "0.sort_text.h"
#include"sort.h"
using namespace std;
////ϣ������ʱ�临�Ӷ�o(nlogn)~o(n^2)
void unguarded_insert_sort(int* arr, int l, int r,int step)
{
	int ind = l;
	for (int i = l +step; i < r; i+=step)
	{
		if (arr[i] < arr[ind])ind = i;
	}
	while (ind > l)
	{
		swap(arr[ind], arr[ind - step]);
		ind-=step;
	}
	for (int i = l + 2*step; i < r; i+=step)
	{
		int j = i;
		while (arr[j] < arr[j - step])
		{
			swap(arr[j], arr[j - step]);
			j-=step;
		}
	}
	return;
}

void shell_sort(int* arr, int l, int r)//ʱ�临�Ӷ����n��2�η�
{
	int k = 2, n = (r - l),step;//ϣ����������
	do{
		step = n / k == 0 ? 1 : n / k;
		for (int i = l, I = l + step; i < I; i++)
		{
			unguarded_insert_sort(arr,i,r,step);
		}
		k *= 2;
	} while (step != 1);
}

void shell_sort_hibbard(int* arr, int l, int r)//ʱ�临�Ӷ����n��1.5�η�
{
	int step = 1, n=r-l;//hibbard��������
	while (step  <= n / 2)
		step = step * 2 + 1;
	do {
		step /= 2;
		for (int i = l, I = l + step; i < I; i++)
		{
			unguarded_insert_sort(arr, i, r, step);
		}
		
	} while (step > 1);
}

//int main()
//{
//	int* arr = getRandData(BIG_DATA_N);
//	TEST(shell_sort, arr, BIG_DATA_N);
//	TEST(shell_sort_hibbard, arr, BIG_DATA_N);
//	return 0;
//}