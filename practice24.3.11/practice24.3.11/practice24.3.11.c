#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <limits.h>

int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	int i = 0;
	int j = 0;
	int arr1[100][100] = { 0 };
	int arr2[100][100] = { 0 };
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			int a = 0;
			scanf("%d", &a);
			arr1[i][j] = a;
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr1[j][i]);
		}
		printf("\n");
	}
	return 0;
}
//int main()
//{
//	int arr1[100][100] = { 0 };
//	int arr2[100][100] = { 0 };
//	int arr3[100][100] = { 0 };
//	int i = 0;
//	int j = 0;
//	int n, m;
//	int  y;
//	scanf("%d%d%d", &n,&m,&y);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			int a = 0;
//			scanf("%d", &a);
//			arr1[i][j] = a;
//		}
//	}
//	
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			int  b = 0;
//			scanf("%d", &b);
//			arr2[i][j] = b;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			int k = 0;
//			int sum = 0;
//			for (k = 0; k < m; k++)
//			{
//				sum += arr1[i][k] * arr2[k][j];
//			}
//			arr3[i][j] = sum;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr3[i][j]);
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
//	int arr2[100][100] = { 0 };
//	int arr3[100][100] = { 0 };
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			int a = 0;
//			scanf("%d", &a);
//			arr1[i][j] = a;
//		}
//	}
//	
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			int a = 0;
//			scanf("%d", &a);
//			arr2[i][j] = a;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			printf( "%d ",arr1[i][j] + arr2[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
	//int n, m;
	//scanf("%d%d",&n,&m);
	//int arr1[100][100] = { 0 };
	//int arr2[100][100] = { 0 };
	//int i = 0;
	//int j = 0;
	//int count = 0;
	//for (i = 0; i < n; i++)
	//{
	//	for (j = 0; j < m; j++)
	//	{
	//		int a = 0;
	//		scanf("%d", &a);
	//		arr1[i][j] = a;
	//	}
	//}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			int a = 0;
	//			scanf("%d", &a);
	//			arr2[i][j] = a;
	//		}
	//	}
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < m; j++)
	//		{
	//			if (arr1[i][j] == arr2[i][j])
	//			{
	//				count++;
	//			}
	//		}
	//	}
	//	double ret = 1.0*count / (m * n)*100;
	//	printf("%.2lf", ret);
	//	return 0;
//}
//int main()
//{//��Ŀͬ�£�������
//	int arr[5][5] = {0};
//	int arrh[5][5] = { 0 };//��¼arr������ÿһ�е����ֵ������¼����Ӧλ��
//	int arrl[5][5] = { 0 };//��¼arr������ÿһ�е���Сֵ������¼����Ӧλ��
//	int i = 0;
//	int j = 0;
//	for (i=0; i < 5; i++)
//	{
//		for (j=0; j < 5; j++)
//		{
//			int a = 0;
//			scanf("%d", &a);
//			arr[i][j] = a;
//		}
//	}
//	for (i = 0; i < 5; i++)
//	{
//		int max_h = INT_MIN;
//		int y = 0;
//		for (j = 0; j < 5; j++)//����һ��
//		{
//			if (max_h < arr[i][j])
//			{
//				max_h = arr[i][j];//����ÿһ�е����ֵ
//				y = j;//��¼���е����ֵ��
//			}
//		}
//		arrh[i][y] = max_h;//����һ�е����ֵ��¼��arrh����Ӧλ�ã��ܹ���¼5�Σ��������5�����ݡ�
//	}
//	for (i = 0; i < 5; i++)
//	{
//		int max_l = INT_MAX;
//		int x = 0;
//		for (j=0; j < 5; j++)//����һ��
//		{
//			if (max_l > arr[j][i])
//			{
//				max_l = arr[j][i];
//				x = j;
//			}
//		}
//		arrl[x][i] = max_l;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			if (arrh[i][j] != 0 && arrl[i][j] != 0)
//			{
//				printf("%d %d %d", i+1, j+1, arrl[i][j]);
//				return 0;
//			}
//		}
//	}
//	printf("not found");
//	return 0;
//}
//int main()//����һ�� 5��5
////�ľ���ÿ��ֻ��һ�����ֵ��
//// ÿ��ֻ��һ����Сֵ��Ѱ���������İ��㡣
//// ����ָ���Ǿ����е�һ��Ԫ�أ����������е����ֵ�������������е���Сֵ��
//// //��1
//{
//	int arr[5][5] = { 0 };
//	int i = 0,j=0,k=0;
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int x = 0;
//	int ret = 0;
//	for (i = 0; i < 5; i++)//i��
//	{
//		//���ַ����е�������⣬ÿ��if�����Ҫ�ǵ����ķ񶨣�
//		// �����if���˵����ǰarr[i][j]��������ĿҪ��
//		//���һֱ����if�������ǰarr[i][j]�������������С�ġ�
//		//
//		for (j = 0; j < 5; j++)//j��
//		{
//			int flag = 1;
//			for (x = 0; x < 5; x++)
//			{
//				if (arr[x][j] < arr[i][j])//�ж�j���Ƿ�Ϊ��С
//				{//�����ģ��ӷ�ȥ�������arrp[i][j]Ϊ��С����ô��С�����е�arr[x][j]
//				//���������arr[x][j]С��arr[i][j]��ôarr[i][j]�Ͳ�����С�ġ�
//					flag = 0;//���Ǿ�����ȥ
//					break;
//				}
//			}
//			for (x = 0; x < 5; x++)
//			{
//				if (arr[i][x] > arr[i][j])//�ж�i���Ƿ�Ϊ�������ͬ�ϡ�
//				{
//					flag = 0;
//					break;
//				}
//			}
//			if (flag)//������ѭ����ֻҪ��һ���в�Ϊ����в�Ϊ��С����������
//			{
//				ret++;
//				printf("%d %d %d", i+1, j+1, arr[i][j]);
//			}
//		}
//	}
//	if (ret == 0)//ret����0˵�������������ѭ����ÿ��ѭ����������������
//	{
//		printf("not found");
//	}
//	return 0;
//}

//int main()
//{
//    int m, n;
//    scanf("%d%d", &m, &n);
//    int i = 1, j = 1;
//    int sum = 0;
//    for (i = 1; i <= m; i++)
//    {
//        for (j = 1; j <= n; j++)
//        {
//            int a;
//            scanf("%d ", &a);
//            if ((i == 1 || i == m) || (j == 1 || j == n))
//            {
//                sum += a;
//            }
//        }
//    }
//    printf("%d", sum);
//    return 0;
//}