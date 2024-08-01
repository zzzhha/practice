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
//void f(int i,int j,int n)//i表示当前元素，j表示当前排列的最小数是j，n代表最大数
//{
//	if (j > n)
//		return;//如果超出上限就直接返回
//	for (int k = j; k <= n; k++)
//	{
//		arr[i] = k;//将当前位置的数设置为k
//		print_one_result(i);//打印从0到i位置的所有数
//		f(i + 1, k + 1, n);//递归
//	}
//} 
//n=3举例：
//1.上述代码：第一次运行时：将arr[0]设置为1，然后进入print打印一个数字（i=0for只进行一次)，打印了  1
//2.然后进入了f(i + 1, k + 1, n)，此时为f(1,2,3)，k被赋值为2，此时arr[1]=2，然后进入print打印   1  2
//3.在f(1,2,3)的基础上，又进入了f（2,3,3），此时arr[2]=3，打印 1  2  3
//4.f(2,3,3)后进入f(3,4,3)直接退出，此时，在f（1,2,3）的基础上，进行了一次for循环k++，使k=3，此时arr[1]改变成了3，然后打印 1 3（因为i=1，所以打印了两个数字）
//5. 之后进入f（2,4,3）退出
//之后退出，一直退出到f（0,1,3）,也就是第一次运行时的数据，此时for循环进行第二次，k为2进行上面的再次循环类似于1-5的步骤
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