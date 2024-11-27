//#include "0.sort_text.h"
#include"sort.h"
using namespace std;
////�鲢���� O(nlogn) �ȶ�


void merge_sort(int* arr, int l, int r) {
	int* buff = new int[1000000];
	if (r - l <= 1)
		return;
	int mid = (l + r) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid, r);//�������Ϊ�������֣������Ұ룬ͨ����εĵݹ飬
	//���Խ���ǰ�ݹ麯���������ú�С��Ȼ�����ζ���Щ�������������Եõ��������߶����������
	//���ϲ���һ�����顣
	//�ܵ�˼�룺�ֳ�С�����������Ȼ��С����ϲ��ɴ�����

	int p1 = l, p2 = mid, k = 0;
	while (p1 < mid || p2 < r)//p1С��mid�Ƕ���ߵ����飨�鲢�ó���С���飩�������ƣ�p2С��r�Ƕ��ұߵ������������
	//��ʱ���Կ���ֻ���������飬������Ҫ������������ϲ�����������飬
	//p1������������ͷָ�룬p2ָ������ұ������ͷָ��
	//while�жϵ�һ��������ߵڶ������黹��Ԫ��
	{
		if (p2 == r || (p1 < mid && arr[p1] <= arr[p2]))//���ڶ�������û��Ԫ�ػ��ߵ�һ�����黹��Ԫ�أ��Ҹ�Ԫ��С�ڵڶ�������Ķ�ӦԪ��
			//�����ǰ�p1�洢
		{
			buff[k++] = arr[p1++];
		}
		else//�෴�洢p2�����ﲻ���ж�p1�Ƿ񳬳��ұ߽�����Ϊ
			//1��p1������͵���mid��λ�ã�������������
			//2��p1����mid��λ�ú󣬾ͻ�ִ��else���룬p2++�����p1������p2����Ӧ�����黹�������
			//p2��ӦԪ��һ�����ڣ�����С�ڣ����������ǽ��򣩣�p1��ӦԪ�أ����в���
			buff[k++] = arr[p2++];
	}
	for (int i = l; i < r; i++)//����ϲ���ԭ����
	{
		arr[i] = buff[i - l];//i-l����Ϊ��buff�洢�Ǵӵ�ǰѭ���ľֲ�����k=0����ʼ�ģ�Ҳ����buffÿ�ζ��Ǵ�ͷ��ʼ�洢��
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