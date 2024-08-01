#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int arr[10];
//	int str[10];
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < 9; i++)
//	{
//		str[i] = arr[i] + arr[i + 1];
//		printf("%4d", str[i]);
//	}
//
//}
//int main()
//{
//	int arr[10];
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	for (int i = 0; i < 10; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("max=%d", max);
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	int x = 1;
//	int y = 1;
//	int sum = 1;
//	int count = 0;
//	for (; i <= 10; i++)
//	{
//		if (i <= 2)
//		{
//			printf("%6d", sum);
//			count++;
//		}
//		else
//		{
//			sum = x + y;
//			x = y;
//			y = sum;
//			printf("%6d", sum);
//			count++;
//			if (count == 5)
//				printf("\n");
//		}
//	}
//	return 0;
//}
//main()
//{
//    int  up = 9, low = 0, mid, found = 0, find;
//    int  a[10] = { 1, 5, 6, 9, 11, 17, 25, 34, 38, 41 };
//
//    scanf("%d", &find);
//    printf("\n");
//
//    while (up >= low && !found)
//    {
//        mid = (up + low) / 2;
//        if (a[mid] == find)
//        {
//            found = 1;
//            break;
//        }
//        else  if (a[mid] > find)
//            up = mid - 1;
//        else
//            low = mid + 1;
//    }
//    if (found)  printf("found  number  is  %dth", mid+1);
//    else    printf("no  found");
//}