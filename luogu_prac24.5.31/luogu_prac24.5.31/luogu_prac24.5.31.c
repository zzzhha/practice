#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include"queue.h"
//#define MIN_PER_HR 60.0
//typedef struct item
//{
//	long arrive;//顾客加入队列的时间
//	int processtime;//该顾客咨询时花费的时间
//}Item;
#include<stdio.h>
#include<string.h>


int main()
{
	int N, i = 0; int num = 0, k = -1;        //num表示还要输出的0/1个数，k标志输出的是1还是0,i表示已输入的个数
	scanf("%d", &N);
	for (i = 1; i <= N * N; i++)
	{
		if (num <= 0)               //如果本次对0/1输入完成，输入接下来要输入1/0的数目
		{
			scanf("%d", &num);
			k++;
		}
		if (k % 2 == 0) printf("0");
		else printf("1");
		num--;

		if (i % N == 0) printf("\n");
	}
	return 0;
}
//int main()
//{
//	int a, n, t = 0, i = 0, b, s = 0;
//	scanf("%d", &n);
//	while (s < n * n)
//	{
//		scanf("%d", &a);
//		i++;
//		for (b = a; b >= 1; b--)
//		{
//			if (t == n)
//			{
//				printf("\n");
//				t = 0;
//			}
//			if (i % 2 == 1)
//				printf("0");
//			else
//				printf("1");
//			t++;
//			s++;
//		}
//	}
//	return 0;
//}
//int main()
//{
//    int int_x, int_y;
//    int int_a, int_b;
//    long long x, y;
//    long long a, b;
//    scanf("%lld%lld", &x, &y);
//    scanf("%lld%lld", &a, &b);
//    int_x = x;
//    int_y = y;
//    int_a = a;
//    int_b = b;
//    if (x * a != int_x * int_a || x * b != int_x * int_b || y * a != int_y * int_a || y * b != int_y * int_b)
//    {
//        printf("long long int\n");
//    }
//    else
//    {
//        printf("int\n");
//    }
//    return 0;
//}
//int main()
//{
//	char arr[260];
//	fgets(arr, 255, stdin);
//	int count_b = 0;
//	int count_g = 0;
//	char* sp=arr;
//	while (*sp!='\0')
//	{
//		if (*sp == 'b' || *(sp + 1) == 'o' || *(sp + 2) == 'y')//判断连着的三个字母是否为b、o、y 
//		{
//			count_b++;
//			sp++;
//		}
//		else if (*sp == 'g' || *(sp + 1) == 'i' || *(sp + 2) == 'r' || *(sp + 3) == 'l')//判断连着的三个字母是否为g、i、r、l 
//		{
//			count_g++;
//			sp++;
//		}
//		else
//			sp++;
//		
//	}
//	printf("%d\n", count_b);
//	printf("%d", count_g);
//	return 0;
//}
//int main()
//{
//	int count = 1;
//	int s = 0;
//	int t = 0;
//	int ch;
//	char arr[200];
//	char src[100001];
//	scanf("%s", arr);
//	int n = strlen(arr);
//	strcat(src, arr);
//	for (int i = 2; i <= n; i++)
//	{
//		scanf("%s", arr);
//		strcat(src, arr);
//	}
//	printf("%d ", n);
//	for (int i = 0, sum = 0, num = '0'; i <= strlen(src); i++)
//		if (num == src[i])
//			sum++;
//		else
//		{
//			num = src[i];
//			printf("%d ", sum);
//			sum = 1;
//		}
//	return 0;
//}
//int main()
//{
//	int a, n, t = 0, i = 0, b, s = 0;
//	scanf("%d", &n);
//	while (s < n * n)
//	{
//		scanf("%d", &a);
//		i++;
//		for (b = a; b >= 1; b--)
//		{
//			if (t == n)
//			{
//				printf("\n");
//				t = 0;
//			}
//			if (i % 2 == 1)
//				printf("0");
//			else
//				printf("1");
//			t++;
//			s++;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[10005];
//	int n;
//	int count = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int flag = 0;
//	for (int i = 1; i < n-1; i++)
//	{
//		
//		if (arr[i] < arr[i - 1])
//		{
//			flag = 1;
//		}
//		if ( arr[i] < arr[i - 1] && arr[i] <= arr[i + 1]&&flag==1)
//		{
//			count++;
//			flag = 0;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	Queue line;
//	Item temp;
//	int hours;
//	int perhour;
//	long cycle, cyclelimit;
//	long turnaway = 0;
//	long customers = 0;
//	long served = 0;
//	long sum_line = 0;
//	int wait_time = 0;
//	double min_per_cust;
//	long line_wait = 0;
//
//	InitalizeQueue(&line);
//	srand((unsigned int)time(0));
//	puts("Case Study:Sigmund Lander's Advice Booth");
//	puts("Enter the munber of simulation hours");
//	scanf("%d", &hours);
//	cyclelimit = MIN_PER_HR * hours;
//	puts("Enter the average number of customers per hours:");
//	scanf("%d", &perhour);
//	min_per_cust = MIN_PER_HR / perhour;
//
//	for (cycle = 0; cycle < cyclelimit; cycle++)
//	{
//		if (newcustomer(min_per_cust))
//		{
//			if (QueueIsFull(&line))
//			{
//				turnaway++;
//			}
//			else
//			{
//				customers++;
//				temp = customertime(cycle);
//				EnQueue(temp, &line);
//			}
//		}
//		if (wait_time <=0 && !QueueIsEmpty(&line))
//		{
//			DeQueue(&temp,&line);
//			wait_time=temp.
//
//		}
//	}
//}

