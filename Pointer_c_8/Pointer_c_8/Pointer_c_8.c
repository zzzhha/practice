#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <float.h>
#include <stdarg.h>

typedef int BOOL;
#define true 1
#define false 0
int num = 0;  //����Ŀ
char m[8][8] = { '*' };//m[8][8]��ʾ���̣���ʼΪ*����ʾδ���ûʺ�
//��������ǰrow-1���ѷ��úûʺ�
//����ڵ�row�С���column�з���һö�ʺ��Ƿ����
BOOL Check(int row, int column)
{
	int i, j;
	if (row == 1)
		return true;
	for (i = 0; i <= row - 2; i++)//����ֻ����һö�ʺ�
	{
		if (m[i][column - 1] == 'Q')
			return false;
	}
	//����������ֻ����һö�ʺ�
	i = row - 2;
	j = i - (row - column);
	while (i >= 0 && j >= 0)
	{
		if (m[i][j] == 'Q')
			return false;
		i--;
		j--;
	}
	//����������ֻ����һö�ʺ�
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
void Output()  //���ѷ���8ö�ʺ�Ϊ���н�ʱ���������
{
	int i, j;
	num++;
	printf("���н�  %d:\n", num);
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%c", m[i][j]);
		}
		printf("\n");
	}
}
//���õݹ麯�����ʵ�ְ˻ʺ�����㷨
//�ú�����⵱����ǰrow-1���ѷ��úûʺ�
void EightQueen(int row)
{
	int j;
	for (j = 0; j < 8; j++)    //������һ�з��ûʺ�
	{
		m[row - 1][j] = 'Q';     //����ڸ��з��ûʺ��Ƿ����
		if (Check(row, j + 1) == true)
		{
			if (row == 8)
				Output();//�����пɷ��ûʺ��Ҹ���Ϊ���һ�У����ҵ�һ���н⣬���
			else 
				EightQueen(row + 1);//�����пɷ��ûʺ�������һ�м������������
		}
		//ȡ�����еĻʺ󣬽��л��ݣ��������з��ûʺ�
		m[row - 1][j] = '*';
	}
}
//������
int main()
{
	EightQueen(1);   //���˻ʺ�����
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