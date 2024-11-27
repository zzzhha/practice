//#include "0.sort_text.h"
#include"sort.h"
using namespace std;
////归并排序 O(nlogn) 稳定


void merge_sort(int* arr, int l, int r) {
	int* buff = new int[1000000];
	if (r - l <= 1)
		return;
	int mid = (l + r) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid, r);//将区间分为两个部分，左半和右半，通过多次的递归，
	//可以将当前递归函数的数组变得很小，然后依次堆这些数组排序，最后可以得到左右两边都有序的数组
	//最后合并成一个数组。
	//总的思想：分成小数组进行排序，然后小数组合并成大数组

	int p1 = l, p2 = mid, k = 0;
	while (p1 < mid || p2 < r)//p1小于mid是对左边的数组（归并得出的小数组）进行限制，p2小于r是对右边的数组进行限制
	//此时可以看做只有两个数组，我们需要把这两个数组合并成有序的数组，
	//p1就是左边数组的头指针，p2指针就是右边数组的头指针
	//while判断第一个数组或者第二个数组还有元素
	{
		if (p2 == r || (p1 < mid && arr[p1] <= arr[p2]))//当第二个数组没有元素或者第一个数组还有元素，且该元素小于第二个数组的对应元素
			//则我们把p1存储
		{
			buff[k++] = arr[p1++];
		}
		else//相反存储p2，这里不用判断p1是否超出右边界是因为
			//1）p1超出后就到了mid的位置，不满足条件。
			//2）p1到了mid的位置后，就会执行else代码，p2++后大于p1，但是p2所对应的数组还是有序的
			//p2对应元素一定大于（或者小于（看是升序还是降序））p1对应元素，所有不用
			buff[k++] = arr[p2++];
	}
	for (int i = l; i < r; i++)//数组合并回原数组
	{
		arr[i] = buff[i - l];//i-l是因为，buff存储是从当前循环的局部变量k=0；开始的，也就是buff每次都是从头开始存储的
	}
	delete[]buff;
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