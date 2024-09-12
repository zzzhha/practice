//#include "0.sort_text.h"
#include"sort.h"
using namespace std;
//基数排序 O(nlogm) 稳定 n代表关键字个数，m代表基数排序的轮数
void radix_sort(int* arr, int l, int r)
//基数排序排序原则：相同数字相对位置不变
//假设有31 21，本次基数为个位数来排序 那么31若在21左边，那么本轮排序 31 依然还在 21 前面
{
	//假设有数据13 21 11 32 31 22 21 ，假设k值为10
	#define K 65536 //基数选择65536是因为 int类型存储2的32次，指向进行两次我们就需要存储一半的值也就是2^16次65536
	int* cnt = new int[K];//存储每个位置对于当前基数的位置信息
	int* temp = new int[r - l];//存放结果的数组，大小为右边r-左边l（L）
	memset(cnt, 0, sizeof(int) * K);
	for (int i = l; i < r; i++)cnt[arr[i] % K]+=1;//存储数据：对基数求模后cnt对应位置有多少个数(求前缀和)
	//cnt[1]所对应个位为1的数据，有4个，cnt[2]有2个,cnt[3]有1个
	for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];//累加，后一个数加等上前一个数的数据，
	 //这样就可以知道根据基数求模后，每个类型的数据应该存放在哪里
	//     1    |      2      |      3
	//     4    |      6      |      7
	//如上，个位数为1累加后在第4位，所以从尾部存储个位数为1的数应该从4号位开始存储应该从4号位存储
	//个位数为2的累加后在第6位，所以从尾部存储个位数为2的数应该从6号位开始存储
	//个位数为3的累加后在第7位，所以从尾部存储个位数为3的数应该从7号位开始存储
	for (int i = r - 1; i >= l; i--)temp[--cnt[arr[i] % K]] = arr[i];//倒序遍历arr[i]%k可得到每个类型的数据
	//所对应在cnt的指针地址，此地址对应数据就是该类型应在数组存放的位置
	//每存放一个我们就把对应累加的cnt值减1，代表该存放在前面一个位置了
	//完成后我们就会得到数组以基数为模后的有序数组了
	//排序后上方数组应为 21 11 31 21 32 22 13
	memcpy(arr + l, temp, sizeof(int) * (r - l));//将这r-l个数据存放在arr中
	
	memset(cnt, 0, sizeof(int) * K);//再次初始化为0，准备存放数组根据基数求除后的对应类型的数据
	for (int i = l; i < r; i++)cnt[arr[i] / K] += 1;
	for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
	for (int i = r - 1; i >= l; i--)temp[--cnt[arr[i] / K]] = arr[i];//跟上方步骤一样
	//例子就是基数从对个位排序变成对十位进行排序
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