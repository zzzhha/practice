#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


int main()
{
	char arr[255] = { 0 };
	gets(arr);
	int i = 0;
	int count = 0;
	int sz = strlen(arr);
	for(i=0;i<sz;i++)
	{
		if (arr[i] <= '9' && arr[i] >= '0')
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	int arr[105][105] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			if ((i == 0 || i == n-1) || (j == 0 || j == m-1))
//			{ 
//				printf("%d ", arr[i][j]);
//			}
//			else
//			{
//				double ret = 1.0*(arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1]) / 5;
//				int sum=(int)ret+0.5;
//				printf("%d ", sum);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	int arr1[100][100] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr1[i][j]);
//		}
//	}
//	for (i = 0; i < m; i++)
//	{
//		for (j = n-1; j >=0 ; j--)
//		{
//			printf("%d ", arr1[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}