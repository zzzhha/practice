#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;


//int main()
//{
//	int n, m;
//	printf("Enter two numbers:");
//	scanf("%d%d", &n, &m);
//	if (m != 0)
//		printf("%d", n / m);
//	else
//		printf("cannot divide by zero.");
//	return 0;
//}
//main()
//{
//    int n;
//    char monthName[][20] = { "Illegal month", "January", "February", "March", "April","May", "June", "July", "August", "September", "October", "November", "December" };
//
//    printf("Input month number:");
//    scanf("%d", &n);
//    if ((n <= 12) && (n >= 1))
//    {
//        printf("month %d is %s\n", n, monthName[n]);
//
//    }
//    else
//    {
//        printf("Illegal month");
//    }
//}

//int main()
//{
//    int count=0, n;
//    do
//    {
//        printf("Input:");
//    } while (scanf("%d", &n) && (n <= 0 || n > 100));//判断读取数据是否正确 
//    printf("初始值为%d，以下为计算过程：\n", n);
//    while (n != 1)//在运算结果不为1 时
//    {
//        count++;
//        if (n % 2==0)//偶数的规则
//        {
//            n = n / 2;
//            printf("第%d步，进行了除以2的操作，结果为：%10d\n", count, n);
//        }
//        else//奇数的规则
//        {
//            n = n * 3 + 1;
//            printf("第%d步，进行了乘3加1的操作，结果为：%10d\n", count, n);
//        }
//    }
//    return 0;
//}
//int main()
//{
//    int n, i;
//    printf("Input n:\n");
//    scanf("%d", &n);
//
//    if (n <= 1)
//    {
//        printf("No!\n");
//        return 0;
//    }
//    for (i = 2; i <= sqrt(n); i++)
//    {
//        if (n % i == 0)
//        {
//            printf("No!\n");
//            return 0;
//        }
//    }
//    printf("Yes!\n");
//    return 0;
//}
//int main()
//{
//	printf("请输入爱尔兰当地时间（24小时制，如22：35）:");
//	int n, m;
//	scanf("%d:%d", &n, &m);
//	int h;
//	if (n > 5)
//		h = n - 5;
//	else
//		h = 24 - 5 + n;
//	int mo = n + 3;
//	mo %= 24;
//	int b = n + 7;
//	b %= 24;
//	printf("对应的华盛顿时间为%d:%d\n", h, m);
//	printf("对应的莫斯科时间为%d:%d\n",mo , m);
//	printf("对应的北京时间为%d:%d\n", b, m);
//	return 0;
//}
//int main()
//{
//	int n, m;
//	printf("Input a, b:");
//	scanf("%d,%d", &n, &m);
//	if (n < m)
//		n = m;
//	printf("max = %d\n", n);
//	return 0;
//}
//int main()
//{
//	int n;
//	printf("Please enter the number:\n");
//	scanf("%d", &n);
//	int m = abs(n);
//	int arr[10] = { 0 };
//	int count = 0;
//
//	while (m)
//	{
//		count++;
//		arr[m % 10]++;
//		m /= 10;
//	}
//	printf("%d: %d bits\n", n, count);
//	for (int i =0 ; i < 10; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d: % d\n", i, arr[i]);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	printf("Input n:");
//	scanf("%d", &n);
//	int sum = 0;
//	int i = 1;
//	do {
//		sum += i;
//		i++;
//	} while (i <= n);
//	printf("sum =%d\n", sum);
//	return 0;
//}
//int main()
//{
//	float a, b, c;
//	printf("Input a,b,c:");
//	scanf("%f,%f,%f", &a, &b, &c);
//	if (a + b > c && a + c > b)
//	{
//		float s = (a + b + c) / 2;
//		float area = sqrt(s * (s - a) * (s - b) * (s - c));
//		printf("area=%.2f", area);
//	}
//	else
//		printf("Input error!");
//	return 0;
//}
//int main()
//{
//	float n = 11.5;
//	float m = 2.5;
//	float h = 10;
//	float area = (n * m) * 2 + (n * h) * 2 + (m + h) * 2;
//	float v = n * m * h;
//	printf("area=%.2f,volume=%.2f", area, v);
//	return 0;
//}
//int main()
//{
//	int n;
//	printf("input data is:");
//	scanf("%d", &n);
//	n = abs(n);
//	int a = 0;
//	while (n)
//	{
//		a += n % 10;
//		n /= 10;
//	}
//	printf("The sum of the total bit is %d\n", a);
//	return 0;
//}
//int main()
//{
//	double n, m;
//	scanf("%lf,%lf", &n, &m);
//	printf("The average is :%.2f", (n + m) / 2);
//	return 0;
//}
//typedef struct Node {
//    int number;
//    struct Node* next;
//} Node;
//
//int main() {
//    int n, m;
//    scanf("%d%d", &n, &m);
//
//    Node* head = (Node*)malloc(sizeof(Node));
//    head->number = 1;
//    Node* prev = head;
//    for (int i = 2; i <= n; i++) {
//        Node* newNode = (Node*)malloc(sizeof(Node));
//        newNode->number = i;
//        prev->next = newNode;
//        prev = newNode;
//    }
//    prev->next = head;
//    Node* current = head;
//    prev = 0;
//    while (current->next != current) {   
//        for (int count = 1; count < m; count++) { 
//            prev = current;
//            current = current->next;
//        }
//        prev->next = current->next;
//        Node* temp = current;
//        current = current->next;
//        free(temp);
//    }
//    printf("%d\n", current->number);
//    free(current);
//    return 0;
//}

//int main()
//{
//	int n;
//	printf("Please enter a number:");
//	scanf("%d", &n);
//	if (n == 1 || n == 0 || n == -1)
//	{
//		printf("It is not a prime number.No divisor!\n");
//		return 0;
//	}
//	int flag = 1;
//	for (int i = 2; i <n; i++)
//	{	
//		if (n % i == 0)
//		{
//			printf("%d\n", i);
//			flag = 0;
//		}
//	}
//	if (flag)
//	{
//		printf("It is a prime number.No divisor!\n");
//	}
//	return 0;
//}
//int IsPerfect(int x)
//{
//	int arr[1000] = { 0 };
//	int j = 0;
//	for (int i = 1; i <x; i++)
//	{
//		if (x % i == 0)
//		{
//			arr[j] = i;
//			j++;
//		}
//	}
//	int sum = 0;
//	for (int i = 0; i <= j; i++)
//	{
//		sum += arr[i];
//	}
//	if (sum == x)
//		return 1;
//	else
//		return 0;
//}
//

//
//#define N 10
//int floatcmp(const void* p1, const void* p2)
//{
//	return *(float*)p1 - *(float *)p2;
//}

//void Sort(int h[], float f[], int n)
//{
//	for (int x = 0; x < n; x++)
//	{
//		for (int y = 0; y < n - 1 - x; y++)
//		{
//			if(f[y]>f[y+1])
//			{
//				float temp = f[y];
//				f[y] = f[y + 1];
//				f[y+ 1] = temp;
//				int t = h[y];
//				h[y] = h[y + 1];
//				h[y+1]=t;
//			}
//		}
//	}
//}
//int i = 0;
//int j = 0;
//void  CountAthleteScore(int sh[], float sf[], int n, float f[], int m)
//{
//	for(;i<n;++i)
//	{
//		float max = 0;
//		float min = 10;
//		printf("\nAthlete %d is playing.", i);
//		printf("\nPlease enter his number code:");
//		scanf("%d", &sh[i]);
//		for (int q=0; q < m; q++)//对一名运动员评分
//		{
//			printf("Judge %d gives score:", j+1);
//			scanf("%f",& f[q]);
//			if (max < f[q]) 
//				max = f[q];
//			if (min > f[q])
//				min = f[q];
//		}
//		printf("Delete a maximum score:%.1f\n", max);
//		printf("Delete a minimum score:%.1f\n", min);
//		float sum = 0;
//		int flag_max = 1;
//		int flag_min = 1;
//		for (int w = 0; w < m; w++)
//		{
//			if ((f[w] == max && flag_max) || (f[w] == min && flag_min))
//			{
//				if(f[w] == max && flag_max)
//					flag_max = 0;
//				else if(f[w] == min && flag_min)
//					flag_min = 0;
//			}
//			else
//			{
//				sum += f[w];
//			}
//		}
//		sum = sum / (m - 2);
//		sf[i] = sum;
//		printf("The final score of Athlete %d is %.4f", sh[i], sum);
//	}
//	
//}
//void CountJudgeScore(float pf[], int m, float sf[], float f[], int n)
//{
//	for(int y=0;y<m;y++)
//	{
//		float sum = 0;
//		for (int x = 0; x < n; x++)
//		{
//			sum += pow(f[(j * x) + i] - sf[i], 2);
//		}
//		pf[y] = (10 - sum);
//	}
//}
//void Print(int h[], float f[], int n)
//{
//	for(int i=0;i<n;i++)
//	{
//		printf("order\tfinal score\tnumber code\n");
//		printf("%5d\t%11.3f\t%6d\n", i, f[i], h[i]);
//	}
//}
//int main()
//{
//	int n;
//	int m;
//	int sh[1000];//运动员的编号
//	float sf[1000];//每个人的平均分
//	float f[1000];//统计每个人的得分
//	int h[1000];//运动员评分对应评委
//	float pf[1000];
//	printf("How many Athletes?");
//	scanf("%d", &n);
//	printf("How many judges?");
//	scanf("%d", &m);	
//	printf("Scores of Athletes:\n");
//	CountAthleteScore(sh, sf, n, f, m);	
//	CountJudgeScore(pf, m,sf, f, n);
//	Sort(sh, sf, n);
//	printf("Order of Athletes:\n");
//	Print(sh, f, n);
//	printf("Order of judges:\n");
//	for (int i = 0; i < n; i++)
//	{
//		h[i] = i + 1;
//	}
//	Print(h, f, n);
//		printf("Over!Thank you!");
//	return 0;
//}