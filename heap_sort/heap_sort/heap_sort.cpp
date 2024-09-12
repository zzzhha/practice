#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
//������ O(nlogn) ���ȶ�
#define ROOT 1
#define FATHER(i) ((i)/2)
#define LEFT(i) ((i)*2)
#define RIGHT(i) ((i)*2+1)

//#define TEST(func,arr,n)\
//{\
//	printf("TEST:%s", #func);\
//	int *temp=new int[n];\
//	memcpy(temp,arr,sizeof(int)*n);\
//	long long b=clock();\
//	func(temp, n);\
//	long long e=clock();\
//	if(check(temp,n))\
//	{\
//		printf("ok\t");\
//	}\
//	else\
//	{\
//		printf("fail\t");\
//	}\
//	printf("%lld ms\n",1000*(e-b)/CLOCKS_PER_SEC);\
//	delete[]temp;\
//}
//
//int* getRandData(int n)
//{
//	int* arr = new int [n];
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = rand() % 100000;
//	}
//	return arr;
//}
//
//bool check(int* arr, int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		if (arr[i] < arr[i - 1])
//			return false;
//	}
//	return true;
//}
//
void up_update(int* data, int i)
{
	while (i > 1 && data[i] > data[FATHER(i)])
	{
		swap(data[i], data[FATHER(i)]);
		i = FATHER(i);
	}
}

void down_update(int* data, int i,int n)
{
	while (LEFT(i) <= n)
	{
		int ind = i;
		int l = LEFT(i);
		int r = RIGHT(i);
		if (data[l] > data[ind])
			ind = l;
		if (r <= n && data[r] > data[ind])
			ind = r;
		if (ind == i)
			break;
		swap(data[ind], data[i]);
		i = ind;
	}
}

void mormal_heap_bulid(int* data, int n)//��ͨ�ѵĽ���
{
	for (int i = 2; i <= n; i++)
	{
		up_update(data, i);
	}
}

void linear_heap_build(int* data, int n) {//���ԶѵĽ���
	for (int i = n / 2; i >= 1; i--)
	{
		down_update(data, i,n);
	}
}

void heap_sort_final(int* data, int n)
{
	for (int i = n; i >= 2; i--)
	{
		swap(data[1], data[i]);
		down_update(data, 1, i - 1);
	}
}

void mormal_heap(int* arr, int n)
{
	int* data = arr - 1;
	mormal_heap_bulid(arr, n);
	heap_sort_final(data, n);
}

void linear_heap(int* arr, int n)//ʱ�临�Ӷ� O(n)
{
	int* data = arr - 1;
	linear_heap_build(arr, n);
	heap_sort_final(data, n);
}
//
////int main()
////{
////	srand(time(0));
////	int *arr = getRandData(1000);
////	TEST(mormal_heap, arr, 1000);
////	TEST(linear_heap, arr, 1000);
////	return 0;
////}
//
//
////�������е� k ��Ԫ��
////���һ���ҵ��������е� k ��Ԫ�ص��ࣨclass����
//// ע���������ĵ� k ��Ԫ�أ����ǵ� k ����ͬ��Ԫ�ء�
//class KthLargest {
//public:
//	typedef pair<int, int>PII;
//	int tot, k;
//	set<PII>s;
//	KthLargest(int k, vector<int>& nums) {
//		this->k = k;
//		for (auto x : nums)
//		{
//			add(x);
//		}
//		return;
//	}
//
//	int add(int val) {
//		if (s.size() < k) {
//			s.insert(PII(val,tot++));
//		}
//		else
//		{
//			if (s.begin()->first < val)
//				s.insert(PII(val, tot++));
//		}
//		if (s.size() > k)
//			s.erase(s.begin());
//		return s.begin()->first;
//	}
//};


