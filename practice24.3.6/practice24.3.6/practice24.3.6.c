#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<malloc.h>

int main()
{
	int n;
	scanf("%d",&n);
	double arr[300] = { 0 };
	int i = 0;
	double sum1 = 0,sum2=0,sum=0;
	double ret = 0;
	for (; i < n; i++)
	{
		scanf("%lf", &arr[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		int flag = 1;
		int j = 0;
		for (; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				double tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	for (i = 1; i < n-1; i++)
	{
		ret += arr[i];
	}
	sum1 = ret / (n - 2) - arr[1];
	sum2 = ret / (n - 2) - arr[n - 2];
	if (fabs(sum1) >= fabs(sum2))
	{
		sum = sum1;
	}
	else
		sum = sum2;
	printf("%.2lf ", ret / (n - 2));
	printf("%.2lf", fabs(sum));
	return 0;
}
//int main()
//{
//	int arr[100] = { 0 };
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	int max = 0;
//	int sum = 0;
//	for (; i < n; i++)
//	{
//		int a;
//		scanf("%d", &a);
//		arr[i] = a;
//	}
//	max = arr[0];
//	for (i = 0; i < n ; i++)
//	{
//		if (arr[i] > max )
//		{
//			max = arr[i];
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		if(max!=arr[i])
//		sum += arr[i];
//	}
//	
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	int arr[10000] = { 0 };
//	int n;
//	int count = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (; i < n; i++)
//	{
//		int a = 0;
//		scanf("%d", &a);
//		arr[i] = a;
//	}
//	int b;
//	scanf("%d", &b);
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] == b)
//		{
//			printf("%d", i);
//			break;
//		}
//		else
//			count++;
//	}
//	if (count == n)
//	{
//		printf("-1");
//	}
//	return 0;
//}
//int main()//b2092Âå¹È ¿ª¹ØµÆ
//{
//	int n;
//	scanf("%d", &n);
//	int a = sqrt(n);
//	int i = 1;
//	for (; i <= a; i++)
//	{
//		printf("%d ", i * i);
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int arr1[1000] = { 0 };
//	int arr2[1000] = { 0 };
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d",&arr1[i]);
//	}
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//	for (i = 0; i < n; i++)
//	{
//		sum+=arr1[i]*arr2[i];
//	}
//	printf("%d", sum);
//	return 0;
//}