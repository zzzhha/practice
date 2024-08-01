#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int arr[10] = {0};
	char* p = arr;
	char i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 1;
	}
	printf("%d ", arr[0]);
	printf("%d ", arr[1]);
	printf("%d ", arr[2]);
	return 0;
}
//void jiqianouhou(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] % 2 == 0)
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//				
//		}
//	}
//}
//void jiqianouhou(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left<right)
//	{
//		if (arr[left] % 2 == 0)
//		{
//			if(arr[right]%2!=0)
//				{
//					int tmp=arr[left];
//					arr[left]=arr[right];
//					arr[right]=tmp;
//					right--;
//				}
//		}
//		left++;
//	}
//}
//int main()
//{
//	int arr[] = { 11,15,14,19,12,8,4,5,1 };
//	int sz = sizeof(arr) / sizeof arr[0];
//	jiqianouhou(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int i;
//	
//	scanf("%d", &i);
//	int sum = i;
//	int tmp = i;
//	int a=0;
//	//第一次买后能换几个，有没有没换的，再相加；
//	while (tmp>=2)
//	{
//		sum += tmp/2;
//		a= tmp % 2;
//		i = tmp / 2;
//		tmp = i + a;	
//	}
//	printf("%d",sum);
//	return 0;
//}
//int weishu(int i)
//{
//	if (i > 9)
//		return 1 + weishu(i / 10);
//	else
//		return 1;
//}
//
//
//int main()
//{
//	int i = 0;
//	int n;
//	
//	for (i = 0; i <= 100000; i++)
//	{
//		//判断i的位数
//		//判断每一位数的数字
//		//计算比较
//		int sum = 0;
//		n=weishu(i);
//		int x = i;
//		while (x)
//		{
//			sum+=pow(x % 10, n);
//			x /= 10;
//		}
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}