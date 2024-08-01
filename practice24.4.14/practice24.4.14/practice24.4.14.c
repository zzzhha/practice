#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


//struct score {
//	int n;
//	char name[20];
//};
//int mystrcmp(const void* c1, const void* c2)
//{
//	const struct score* a = (struct score*)c1;
//	const struct score* b = (struct score*)c2;
//	return a->n < b->n;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	struct score* s = (struct score*)malloc(n * sizeof(struct score));
//	char arr[20] = { 0 };
//	int i = 0;
//	for (; i < n; i++)
//	{
//		scanf("%d", &s[i].n);
//		scanf("%s", s[i].name);
//	}
//	qsort(s, n, sizeof(struct score), mystrcmp);
//	/*int max = s[0].n;
//	for (i=0; i < n; i++)
//	{
//		if (max < s[i].n)
//		{
//			max = s[i].n;
//			int j = 0;
//			for (; j < strlen(s[i].name) - 1; j++)
//			{
//				arr[j] = s[i].name[j];
//			}
//		}
//	}
//	printf("%s", arr);*/
//	printf("%s", s[0].name);
//	free(s);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	char(*p)[20] = (char(*)[20])malloc(n * 20 * sizeof(char));
//	int i = 0;
//	for (; i < n; i++)
//	{
//		fgets(p[i], 20, stdin);
//	}
//	char* max = p[0];
//	for (i=0; i < n; i++)
//	{
//		if (strncmp(max, p[i], 2)>=0)
//		{
//			;
//		}
//		else
//		{
//			max = p[i];
//		}
//	}
//	printf("%s", (max+3));
//	free(p);
//	return 0;
//}
//int main()
//{
//	char arr1[105] = { 0 };
//	char arr2[105] = { 0 };
//	scanf("%s", arr1);
//	int sz = strlen(arr1);
//	int i = sz-1;
//	int j = 0;
//	for (; i >= 0; i--, j++)
//	{
//		arr2[j] = arr1[i];
//	}
//	if (!strncmp(arr1, arr2,j) )
//	{
//		printf("yes");
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//}
//int self_love(int n)
//{
//	n%10
//}
//int main()
//{
//	int i = 1;
//	int j = 1;
//	int k = 1;
//	for (i = 0; i <= 9; i++)
//	{
//		for (j = 0; j <= 9; j++)
//		{
//			for (k = 0; k <= 9; k++)
//			{
//				int n = i * 100 + j * 10 + k;
//				int ret=self_love(n);
//				if (ret == n)
//				{
//					printf("%d",n);
//				}
//			}
//		}
//	}
//}

//int main()
//{
//	int i = 1;
//	int j = 1;
//	int k = 1;
//	for (i = 0; i <= 9; i++)
//	{
//		for (j = 0; j <= 9; j++)
//		{
//			for (k = 0; k <= 9; k++)
//			{
//				int n = i * 100 + j * 10 + k;
//				if ( n== (pow(i, 3) + pow(j, 3) + pow(k, 3)))
//				{
//					printf("%d ", n);
//				}
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	double e=1;
//	while (1)
//	{
//		int j;
//		double n = 1;
//		for(j=1;j<=i;j++)
//		{
//			n *= j;
//		}
//		e += 1 / n;
//		i++;
//		if ((1/n) < 1.0e-5)
//		{
//			break;
//		}
//		
//	}
//	printf("e = %f, count = %d\n", e, i);
//	return 0;
//}
//int main()
//{
//	int n;
//	int flag = 1;
//	scanf("%d", &n);
//	int i = 10;
//	if (n % 10 != 0 && (n % 10) != (n / 10))
//	{
//		for (; i < 100; i++)
//		{
//			if(i % 10 != 0 && (i % 10) != (i / 10))
//			{
//				int c = i % 10 * 10 + i / 10;
//				int d = n % 10 * 10 + n / 10;
//				if (c + d == i + n)
//				{
//					flag = 0;
//					printf("%d+%d=%d+%d\n", n, i, d, c);
//				}
//			}
//		}
//		if (flag)
//		{
//			printf("NONE");
//		}
//	}
//	else {
//		printf("NONE");
//	}
//	return 0;
//}
//int main()
//{
//	float a, b;
//	int flag = 1;
//	float c = 0;
//	printf("Enter x1,x2:");
//	scanf("%f,%f", &a, &b);
//	while (flag)
//	{
//		c = (a + b) / 2;
//		if (2 * c * c * c - 4 * c * c + 3 * c - 6 > 0)
//		{
//			b = c;
//		}
//		else if (2 * c * c * c - 4 * c * c + 3 * c - 6 == 0)
//		{
//
//			flag = 0;
//			printf("x=%6.2f\n", c);
//		}
//		else
//		{
//			a = c;
//		}
//	}
//	return 0;
//}
//main()
//{
//    int i, a, n = 1;
//    while (n <= 7)
//    {
//        do
//        {
//            scanf("%d", &a);
//        } while (a < 1 && a > 50);
//        for (i = 1; i <= a; i++)
//        {
//            printf("*");
//        }
//        printf("\n");
//        n++;
//    }
//}
//int main()
//{
//	int i = 2;
//	for (; i < 1000; i++)
//	{
//			if (pow((i % 10), 3) + pow((i / 10 % 10), 3) + pow((i / 100), 3) == i)
//			{
//				printf("%d ", i);
//			}
//	}
//	return 0;
//}
//int main()
//{
//	int i,flag = 1;
//	int a, b, c, d;
//	int la, lb, lc, ld;
//	for (a = 0; a <= 1; a++)
//	{
//		for (b = 0;  b<= 1; b++)
//		{
//			for (c = 0; c <= 1; c++)
//			{
//				for (d = 0; d <= 1; d++)
//				{
//					la = b || c || d;
//					lb = !b && c;
//					lc = a || d;
//					ld = lb;
//					if(la+lb+lc+ld==2&&a+b+c+d==1)
//					{
//						if (a)
//						{
//							printf("1,0,0,0\n");
//							printf("A是罪犯.\n");
//						}
//						else if (b)
//						{
//							printf("0,1,0,0\n");
//							printf("B是罪犯.\n");
//						}
//						else if (c)
//						{
//							printf("0,0,1,0\n");
//							printf("C是罪犯.\n");
//						}
//						else if (d)
//						{
//							printf("0,0,0,1\n");
//							printf("D是罪犯.\n");
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//main()
//{
//	int x = 118, find = 0;
//	while (!find)
//	{
//		if ((x % 2 == 1) && (x % 3 == 2) && (x % 5 == 4) && (x % 6 == 5) && (x % 7 == 0))
//		{
//			printf("x = %d\n", x);
//			find = 1;
//		}
//		x++;
//	}
//}
//int getint(int a, int b)
//{
//	int n;
//	printf("请输入[%d..%d]间的一个整数：\n", a, b);
//	scanf("%d", &n);
//	if (n<b || n>a)
//	{
//		return 0;
//	}
//	else
//	{
//		printf("你输入的整数为:% d\n", n);
//		return 1;
//	}
//}
//int main()
//{
//	int n;
//	int max = 100, min = 3;
//	
//	while (!getint( max, min))
//	{
//		;
//	}
//	return 0;
//}