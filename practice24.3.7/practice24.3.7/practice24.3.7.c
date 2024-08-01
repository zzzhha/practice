#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	int n,x,y;
	int j;
	scanf("%d%d%d", &n,&x,&y);
	int i = 1;
	for (i = 1; i <= n; i++)
	{
		printf("(%d,%d) ", x, i);
	}
	printf("\n");
	for (i = 1; i <= n; i++)
	{
		printf("(%d,%d) ", i, y);
	}
	printf("\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i - j == x - y)
			{
				printf("(%d,%d) ", i, j);
			}
		}
	}
	printf("\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i + j == x + y)
			{
				printf("(%d,%d) ", j, i);
			}
		}
	}
	printf("\n");
	return 0;
}
//int main()
//{
//	int arr[5][5];
//	int i = 0;
//	int j=0;
//	for (i=0; i < 5; i++)
//	{
//		for(j=0;j<5;j++)
//		{
//			int a = 0;
//			scanf("%d", &a);
//			arr[i][j] = a;
//		}
//	}
//	int x, y;
//	scanf("%d%d", &x, &y);
//	for (i = 0; i < 5; i++)
//	{
//		int tmp = arr[x - 1][i];
//		arr[x - 1][i] = arr[y - 1][i];
//		arr[y - 1][i] = tmp;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()// 将n个数存入到数组中，在第一个for循环（i从1到n）中先输入a[i]，
////再套一个循环，将a[i]与数组前面的数进行比较，如果两数不等则进入下一层循环，
////如果两数相等则使i-1，n-1。这样输入的下一个数会将重复的那个数覆盖，这样就得到了一组去重的数。
//{
//	int n,i,j;
//	scanf("%d", &n);
//	int arr[20000] ;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		for (j = 0; j < i; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				i = i - 1;
//				n = n - 1;
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[2000] = {0};
//	//int arr1[2000] = { 0 };
//	int i = 0;
//	int x = 0;
//	int m = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int count = 1;
//	for (i = 0; i < n - 1; i++)
//	{
//		if (arr[i] == arr[i + 1])
//		{
//			count++;
//		}
//		else
//		{
//			count=1;
//			/*arr1[x] = count;
//			x++;
//			count = 1;*/
//		}
//		if (m < count)
//			m = count;
//	}
//	/*int max = 0;
//	for (i = 0; i < n; i++)
//	{
//	if (max < arr1[i])
//		max = arr1[i];
//	}*/
//	//printf("%d", max);
//	printf("%d", m);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[100000] ;
//	int i = 0;
//	int max = 0;
//	for (; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (max < arr[i])
//			max = arr[i];
//	}
//	for (i = 0; i<=max; i++)
//	{
//		int count = 0;
//		int j;
//		for (j = 0; j < n; j++)
//		{
//			if (i == arr[j])
//			{
//				count++;
//			}
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}