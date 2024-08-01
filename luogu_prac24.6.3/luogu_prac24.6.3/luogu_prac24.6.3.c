#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int a, b;
	int c, d;
	scanf("%d/%d", &a,&b);
	scanf("%d/%d", &c, &d);	
	int e = a * c;
	int f = b * d;
	printf("%d %d", f/gcd(e,f),e/gcd(e,f));
	return 0;
}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[100];
//	
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", arr + i);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int count = 0;
//		for (int j = i-1; j>=0; j--)
//		{
//			if (arr[i] > arr[j])
//			{
//				count++;
//			}
//		}
//		printf("%d ", count);
//	}
//	return 0;
//}
//int main()
//{
//	int arr[105];
//	int i = 0;
//	for (; i < 100; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (arr[i] == 0)
//		{
//			break;
//		}
//	}
//	for (i = 0; i < 100; i++)
//	{
//		if (arr[i] == 0)
//		{
//			break;
//		}
//	}
//	for (; i > 0; )
//	{
//		printf("%d ", arr[--i]);
//	}
//	return 0;
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	float start = 7;
//	float sum = 0;
//	int flag = 0;
//	while(1)
//	{	
//		if (sum >= a - b && sum <= a + b && flag == 1)
//		{
//			printf("y");
//			break;
//		}
//		else if (sum > a + b)
//		{
//			printf("n");
//			break;
//		}
//		if (sum >= a-b&&sum<=a+b)
//		{
//			flag = 1;
//		}
//		sum += start;
//		start *= 0.98;
//	}
//	return 0;
//}
//int main()
//{
//	int s_hour, s_minute;
//	int e_hour, e_minute;
//	scanf("%d%d%d%d", &s_hour, &s_minute, &e_hour, &e_minute);
//	int a = e_hour - s_hour;
//	int b = e_minute - s_minute;
//	if (b < 0)
//	{
//		a -= 1;
//		b = 60 + b;
//	}
//	printf("%d %d", a, b);
//	return 0;
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int day = 5;
//	int s = 0;
//	if (a == 6 )
//	{
//		b -= 2;
//	}
//	else if (a == 7)
//	{
//		b -= 1;
//	}
//	else
//	{
//		day = day - a+1 ;
//		s = day * 250;
//		b =b- day - 2;
//	}
//	int d = b / 7;
//	int e = b %7;
//	if (e >= 6)
//	{
//		e = 5;
//	}
//	if(d)
//	{
//		s += d * 5 * 250+e*250;
//	}
//	else
//	{
//		s += b * 250;
//	}
//	printf("%d", s);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	const int two = 2;
//	const int* s = pa;
//	*pa = 20;
//	//if (-1 < (unsigned int)1)//
//	//{
//	//	printf("1 big");
//	//}
//	//else
//	//{
//	//	printf("-1 big");
//	//}
//	//printf("%d", a);
//	return 0;//0x0000001583DAF524
//}
//int main()
//{
//	double n;
//	scanf("%lf", &n);
//	double sum = 0;
//	if (n > 0 && n <= 150)
//	{
//		sum = 0.4463 * n;
//	}
//	else if (n > 150 && n <= 400)
//	{
//		sum = 0.4463 * 150 + (n - 150) * 0.4663;
//	}
//	else
//	{
//		sum= 0.4463 * 150 + 250 * 0.4663+(n-400)*0.5663;
//	}
//	printf("%.1lf", sum);
//	return 0;
//}
//int main()
//{
//	int count = 1;
//	int max_count =1;
//	int arr[10000];
//	int n;
//	int a=-1;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] == a+1)
//		{
//			count++;
//			if (count > max_count)
//				max_count = count;
//			
//		}
//		else
//		{
//			count =1;
//		}
//		a = arr[i];
//	}
//	printf("%d", max_count);
//	return 0;
//}