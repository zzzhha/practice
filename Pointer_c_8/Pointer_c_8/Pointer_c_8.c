#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <float.h>
#include <stdarg.h>

typedef int BOOL;
#define true 1
#define false 0
int num = 0;  //解数目
char m[8][8] = { '*' };//m[8][8]表示棋盘，初始为*，表示未放置皇后
//对于棋盘前row-1行已放置好皇后
//检查在第row行、第column列放置一枚皇后是否可行
BOOL Check(int row, int column)
{
	int i, j;
	if (row == 1)
		return true;
	for (i = 0; i <= row - 2; i++)//纵向只能有一枚皇后
	{
		if (m[i][column - 1] == 'Q')
			return false;
	}
	//左上至右下只能有一枚皇后
	i = row - 2;
	j = i - (row - column);
	while (i >= 0 && j >= 0)
	{
		if (m[i][j] == 'Q')
			return false;
		i--;
		j--;
	}
	//右上至左下只能有一枚皇后
	i = row - 2;
	j = row + column - i - 2;
	while (i >= 0 && j <= 7)
	{
		if (m[i][j] == 'Q')
			return false;
		i--;
		j++;
	}
	return true;
}
void Output()  //当已放置8枚皇后，为可行解时，输出棋盘
{
	int i, j;
	num++;
	printf("可行解  %d:\n", num);
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%c", m[i][j]);
		}
		printf("\n");
	}
}
//采用递归函数解决实现八皇后回溯算法
//该函数求解当棋盘前row-1行已放置好皇后
void EightQueen(int row)
{
	int j;
	for (j = 0; j < 8; j++)    //在其中一列放置皇后
	{
		m[row - 1][j] = 'Q';     //检查在该列放置皇后是否可行
		if (Check(row, j + 1) == true)
		{
			if (row == 8)
				Output();//若该列可放置皇后，且该列为最后一列，则找到一可行解，输出
			else 
				EightQueen(row + 1);//若该列可放置皇后，则向下一行继续搜索、求解
		}
		//取出该列的皇后，进行回溯，在其他列放置皇后
		m[row - 1][j] = '*';
	}
}
//主函数
int main()
{
	EightQueen(1);   //求解八皇后问题
	return 0;
}


////7.
//int array_offset(int* arrayinfo, ...)
//{
//	int ndim;
//	int offset;
//	int hi, lo;
//	int* sp;
//	int s[10];
//	va_list subscripts;
//	ndim = *arrayinfo++;
//	if (ndim >= 1 && ndim <= 10)
//	{
//		va_start(subscripts, arrayinfo);
//		for (offset = 0; offset < ndim; offset += 1)
//			s[offset] = va_arg(subscripts, int);
//		va_end(subscripts);
//
//		offset = 0;
//		arrayinfo += ndim * 2;
//		sp = s + ndim;
//		while (ndim-- >= 1) {
//			
//			hi = *--arrayinfo;
//			lo = *--arrayinfo;
//			if (*--sp > hi || *sp < lo) {
//				return -1;
//			}
//			offset *= hi - lo + 1;
//			offset += *sp - lo;
//		}
//		return offset;
//	}
//	return -1;
//}
////6.
//int array_offset( int* arrayinfo, ...)
//{
//	int ndim;
//	int offset;
//	int hi, lo;
//	int i;
//	int s[10];
//	va_list subscripts;
//	ndim = *arrayinfo++;
//	if (ndim >= 1 && ndim <= 10)
//	{
//			
//		va_start(subscripts, arrayinfo);
//		for (i = 0; i < ndim; i += 1)
//			s[i] = va_arg(subscripts, int);
//		va_end(subscripts);
//			
//		offset = 0;
//		for (i = 0; ndim; ndim--, i++)
//		{
//				
//			lo = *arrayinfo++;
//			hi = *arrayinfo++;
//			if (s[i] < lo || s[i] > hi)
//				return -1;
//			offset *= hi - lo + 1;
//			offset += s[i] - lo;
//		}
//		return offset;
//	}
//	return -1;
//}
//5.
//void matrix_multiply(int* m1, int* m2, int* r, int x, int y, int z)
//{
//	int* m1p;
//	int* m2p;
//	int k;
//	int row;
//	int col;
//	for (row = 0; row < x; row++)
//	{
//		for (col = 0; col < z; col++)
//		{
//			m1p = m1 + row * y;
//			m2p = m2 + col;
//			*r = 0;
//			for (k = 0; k < y; k++)
//			{
//				*r = *m1p + *m2p;
//				m1p++;
//				m2p+=z;
//			}
//			r++;
//		}
//	}
//
//}
//4.
//int identity_matrix(int *matrix,int n)
//{
//	int r = 0;
//	for (; r < n; r++)
//	{
//		int c = 0;
//		for (; c < n; c++)
//		{
//			if (matrix[r] != 1 )
//			{
//				return 0;
//			}
//			if (c == r)
//			{
//				c++;
//			}
//			if (matrix[c] != 0)
//			{
//				return 0;
//			}
//		}
//		
//	}
//	return 1;
//}
//3.
//int identity_matrix(int matrix[10][10])
//{
//	int r = 0;
//	for (; r < 10; r++)
//	{
//		int c = 0;
//		for (; c < 10; c++)
//		{
//			if (c != r)
//			{
//				if (matrix[r][c] !=  0)
//				{
//					return 0;
//				}
//			}
//			else
//			{
//				if (matrix[r][c] != 1)
//				{
//					return 0;
//				}
//			}
//		}
//	}
//	return 1;
//}
//2.
//static double income_list[] = {
//    0, 23350, 56550, 117950, 256500, DBL_MAX };
//static double base_tax[] = {
//    0, 3502.5, 12798.5, 31832.5, 81710.5 };
//static float percentage[] = {
//    .15, .28, .31, .36, .396 };
//
//double single_tax(double income) {
//    int i = 1;
//    for (i; income >= income_list[i]; i++)
//        ;
//    i--;
//    return base_tax[i] + percentage[i] * (income - income_list[i]);
//}