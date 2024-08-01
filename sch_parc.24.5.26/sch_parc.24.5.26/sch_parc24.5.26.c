#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
	return 0;
}
//#include <stdio.h>
//#define M 3
//#define S 4
//#define N 2
//
//void multiply(int A[M][S], int B[S][N], int C[M][N])
//{
//	int i, j;
//	for (i = 0; i < M; i++)
//	{
//		for (j = 0; j < N; j++)
//		{
//			int k = 0;
//			int sum = 0;
//			for (k = 0; k < S; k++)
//			{
//				sum += A[i][k] * B[k][j];
//			}
//			C[i][j] = sum;
//		}
//	}
//}
//
//int main()
//{
//	int i, j;
//	int A[M][S], B[S][N], C[M][N];
//	printf("Please input A:\n");
//	for (i = 0; i < M; i++)
//		for (j = 0; j < S; j++)
//			scanf("%d", &A[i][j]);
//	printf("Please input B:\n");
//	for (i = 0; i < S; i++)
//		for (j = 0; j < N; j++)
//			scanf("%d", &B[i][j]);
//	multiply(A, B, C);
//	printf("C=\n");
//	for (i = 0; i < M; i++) {
//		for (j = 0; j < N; j++)
//			printf("%d ", C[i][j]);
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	int arr[10][10];
//	printf("请输入矩阵的行数：\n");
//	scanf("%d", &n);
//	printf("请输入原始矩阵：\n");
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	printf("原始矩阵:\n");
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for(int j=0;j<n-1;j++)
//		{
//			if (arr[j][j] < arr[j + 1][j + 1])
//			{
//				int temp = arr[j][j];
//				arr[j][j] = arr[j + 1][j + 1];
//				arr[j + 1][j + 1] = temp;
//			}
//		}
//	}
//	printf("排序后为：\n");
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	printf("please input n:(3<n<10)\n");
//	scanf("%d", &n);
//	printf("%d阶魔方矩阵如下：\n");
//	int(*p)[10] = (int(*)[])malloc(sizeof(int) * n * n);
//	int line = 0;
//	int row = (n + 1) / 2 - 1;
//	
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			p[i][j] = 0;
//		}
//	}
//	p[line][row] = 1;
//	for (int i = 2; i <= n*n; i++)
//	{
//		int line_0 = line;
//		int row_0 = row;
//		if (line == 0 && row == n - 1)
//		{
//			line = n - 1;
//			row = 0;
//		}
//		else if (line == 0)
//		{
//			line = n - 1;
//			row++;
//		}
//		else if(row == n-1)
//		{
//			line--;
//			row = 0;
//		}
//		else
//		{
//			line--;
//			row++;
//		}
//		if (p[line][row] != 0)
//		{
//			line = line_0 + 1;
//			row = row_0;
//		}
//		p[line][row] = i;
//	}
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				printf("%d", p[i][j]);
//			}
//			printf("\n");
//		}
//	return 0;
//}
//void p0(int arr[][10], int src[][10],int m,int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			src[i][n-j-1] = arr[i][j];
//		}
//	}
//	printf("After operation:\n");
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%4d", src[i][j]);
//		}
//		printf("\n");
//	}
//}
//void p1(int arr[][10], int src[][10], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			src[m-i-1][j] = arr[i][j];
//		}
//	}
//	printf("After operation:\n");
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%4d", src[i][j]);
//		}
//		printf("\n");
//	}
//}
//void p2(int arr[][10], int src[][10], int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			src[j][i] = arr[i][j];
//		}
//	}
//	printf("After operation:\n");
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf("%4d", src[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n, m;
//	int src[10][10];
//	printf("Input m,n:\n");
//	scanf("%d,%d", &m, &n);
//	int(*p)[10] = (int(*)[])malloc(sizeof(int) * n * m);
//	printf("Input %d*%d array:\n", m, n);
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &(p[i][j]));
//		}
//	}
//	int mode;
//	printf("Input operation mode:\n");
//	scanf("%d", &mode);
//	void(*h[3])(int arr[][10], int src[][10], int m, int n) = { p0,p1,p2 };
//	h[mode](p, src, m, n);
//	return 0;
//}
//#define N 4
//void swap(int* p1, int* p2)
//{
//	int p;
//	p = *p1; *p1 = *p2; *p2 = p;
//}
//
//void sort(int a[N][N])
//{
//	int i, j, k;
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < N ; j++)
//		{
//			for (k = j + 1; k <= N - 1; k++)
//			{
//				if (i % 2 == 0 ? a[i][j]>a[i][k] : a[i][j]<a[i][k])
//				{
//					swap(a[i] + j, a[i] + k);
//				}
//			}
//		}
//	}
//}
//void main() {
//	int a[N][N] = { {3,4,2,1},{8,7,5,6},{12,10,11,9},{15,14,16,13} };
//	int i, j;
//	sort(a);
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < N; j++)
//			printf("%3d", a[i][j]);
//		printf("\n");
//	}
//}
void  CaculateYH(int a[][15], int  n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			a[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j != 0 && j != i)
			{
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			}
		}

	}
}
void  PrintYH(int a[][15], int  n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
	
}
int main()
{
	int arr[15][15];
	printf("Input n(n<15):\n");
	int n;
	scanf("%d", &n);
	CaculateYH(arr, n);
	PrintYH(arr,n);
	return 0;
}
void Convert(int a[][4], int b[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			b[j][i] = a[i][j];
		}
	}
}
int main()
{
	int arr[3][4];
	int src[4][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	Convert(arr, src);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%4d", src[i][j]);
		}
		printf("\n");
	}
	return 0;
}
//int FindMax(int* p, int m, int n, int* pRow, int* pCol)
//{
//	int max = p[0];
//	for (int i = 0; i < m*n; i++)
//	{
//
//		if (max < p[i])
//		{
//			max = p[i];
//			*pRow = i/n;
//			*pCol = i%n;
//		}
//
//	}
//	return max;
//}
//void Input(int* p, int m, int n)
//{
//	printf("Please input your data:\n");
//	for (int i = 0; i < m*n; i++)
//	{
//			scanf("%d", &p[i]);
//
//	}
//}
//int main()
//{
//	int arr[3][4];
//	int i = 0;
//	int j = 0;
//	int* p=&i;
//	int* s=&j;
//	int* ps = &arr[0][0];
//	Input(ps,3,4);
//
//	int max=FindMax(ps,3,4,p,s);
//	printf("The maximum is %d, which is in row %d, colum %d\n", max, i, j);
//}
