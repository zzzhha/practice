#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<limits.h>

int main()
{
	int n;
	int m;
	scanf("%d%d", &n, &m);
	int arr[3005];
	int max=INT_MAX;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i <= n-m; i++)
	{
		int sum = 0;
		int s = 0;
		for (int j = i; s < m; j++,s++)
		{
			sum += arr[j];
		}
		if (max > sum)
			max = sum;
	}
	printf("%d", max);
	return 0;
}
//int a[3]; char s1, s2;
//int main()
//{
//    while (scanf("%c:=%c;", &s1, &s2) == 2)
//    {
//        a[s1 - 'a'] = s2 >= '0' && s2 <= '9' ? s2 - '0' : a[s2 - 'a'];
//    }
//    printf("%d %d %d", a[0], a[1], a[2]);
//}
//int arr[1000005];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int count = 1;
//	int max = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", arr + i);
//	}
//	for (int i = 0; i < n-1; i++)
//	{
//		if (arr[i] < arr[i + 1])
//		{
//			count++;
//		}
//		else
//		{
//			count = 1;
//		}
//		if (max < count)
//			max = count;
//	}
//	printf("%d", max);
//	return 0;
//}
//int arr[10];
//
//void print_one_result(int n)
//{
//	for (int m = 0; m <= n; m++)
//	{
//		if (m)
//			printf(" ");
//		printf("%d", arr[m]);
//	}
//	printf("\n");
//}
//void f(int i,int j,int n)//i��ʾ��ǰԪ�أ�j��ʾ��ǰ���е���С����j��n���������
//{
//	if (j > n)
//		return;//����������޾�ֱ�ӷ���
//	for (int k = j; k <= n; k++)
//	{
//		arr[i] = k;//����ǰλ�õ�������Ϊk
//		print_one_result(i);//��ӡ��0��iλ�õ�������
//		f(i + 1, k + 1, n);//�ݹ�
//	}
//} 
//n=3������
//1.�������룺��һ������ʱ����arr[0]����Ϊ1��Ȼ�����print��ӡһ�����֣�i=0forֻ����һ��)����ӡ��  1
//2.Ȼ�������f(i + 1, k + 1, n)����ʱΪf(1,2,3)��k����ֵΪ2����ʱarr[1]=2��Ȼ�����print��ӡ   1  2
//3.��f(1,2,3)�Ļ����ϣ��ֽ�����f��2,3,3������ʱarr[2]=3����ӡ 1  2  3
//4.f(2,3,3)�����f(3,4,3)ֱ���˳�����ʱ����f��1,2,3���Ļ����ϣ�������һ��forѭ��k++��ʹk=3����ʱarr[1]�ı����3��Ȼ���ӡ 1 3����Ϊi=1�����Դ�ӡ���������֣�
//5. ֮�����f��2,4,3���˳�
//֮���˳���һֱ�˳���f��0,1,3��,Ҳ���ǵ�һ������ʱ�����ݣ���ʱforѭ�����еڶ��Σ�kΪ2����������ٴ�ѭ��������1-5�Ĳ���
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	f(0,1,n);
//
//	return 0;
//}
//int main()
//{
//	int n, m;
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int count[10] = {0,0,0,0,0,0,0,0,0,0};
//	scanf("%d%d", &n, &m);
//	for (; n <= m; n++)
//	{
//		int a = n;
//		while (a)
//		{
//			for (int i = 0; i < 10; i++)
//			{
//				if (a % 10 == arr[i])
//				{
//					count[i]++;
//				}
//			}
//			a /= 10;
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", count[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int n,m;
//	scanf("%d%d", &n, &m);
//	int square = 0;
//	int rectangle = 0;
//	for (int i = 0; i < n || i < m; i++)
//	{
//		square += (n - i) * (m - i);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; (j < m); j++)
//		{
//			if(i!=j)
//			rectangle += (n - i) * (m - j);
//		}
//	}
//	printf("%d %d", square,rectangle);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int class_time;
//	int kewai_time;
//	int temp=0;
//	int sum=0;
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d%d", &class_time, &kewai_time);
//		sum =(kewai_time + class_time+ temp)-8;
//		temp = sum;
//		count += temp;
//		
//	}
//	printf("%d", count);
//	return 0;
//}