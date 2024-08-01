#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand ((unsigned)time(NULL));
	int count = 0;
	int n;
	int start = 0;
	int end = 100;
	scanf("%d", &n);
	while (1)
	{
		count++;
		int mid = (start + end) / 2;
		printf("%d ", mid);
		if (n > mid)
		{
			printf("小\n");
			start = mid+1;
		}
		else if (n < mid)
		{
			printf("大\n");
			end = mid - 1;
		}
		else
		{
			printf("正确");
			break;
		}
	}
	printf("猜了%d次", count);
	return 0;
}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int sum = 0;
//	int x=1 ,y=1 ;
//	for (int i = 1; i <= n; i++)
//	{
//		if (i == 1 || i == 2)
//		{
//			sum = 1;
//		}
//		else
//		{
//			x = y;
//			y = sum;
//			sum = x + y;
//		}
//	}
//	printf("%d", sum);
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	printf("%d ", a / 100);
//	printf("%d ", a / 10 % 10);
//	printf("%d", a % 10);
//	return 0;
//}