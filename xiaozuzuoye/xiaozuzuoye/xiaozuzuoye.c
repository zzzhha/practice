#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int main()
{
	int s;
	double t2, t3;
	scanf("%d", &s);
	t2 = s / 1.2;
	t3 = s / 3.0 + 27.0 + 23.0;
	if (t3 > t2)
	{
		printf("走路");
	}
	else if (t3 < t2)
		printf("骑车");
	else
		printf("一样");
	return 0;
}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int x = 1;
//	int n;
//	int arr[100][100];
//	scanf("%d", &n);
//	for (i=0; i < n; i++)
//	{
//		for (j=0;j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for(i=0;i<n;i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr[n-1-j][ i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 1;
//	int j = 1;
//	int m = n;
//	int x = 1;
//	for (; i <= n; i++)
//	{
//		for (j = --m; j >0; j--)
//		{
//			printf(" ");
//		}
//		for(j=1;j<=x;j++)
//		{
//			printf("*");
//		}
//		x+=2;
//		printf("\n");
//	}
//	x -= 2;
//	for (i=n-1; i > 0; i--)
//	{
//		for (j = i; j < n; j++)
//		{
//			printf(" ");
//		}
//		x -= 2;
//		for (j=x;j>0;j--)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//int cmpint(void* a, void* b)
//{
//	return *((int*)a) - *((int*)b);
//}
//int main()
//{
//	int arr1[100];
//	int arr2[100];
//	int sum[1000] = { 0 };
//	int n, m;
//	int j = 0;
//	scanf("%d%d", &n, &m);
//	int i = 0;
//	for (i=0; i < n; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//	for (i = 0; i < n; i++)
//	{
//		sum[i] = arr1[i];
//	}
//	for (; i+j < n + m; )
//	{
//		sum[i + j] = arr2[j];
//		j++;
//	}
//	qsort(sum, n + m, sizeof(int), cmpint);
//	for (i = 0; i < n + m; i++)
//	{
//		printf("%d ", sum[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n,&m);
//	double sum = n;
//	int i = 1;
//	double a=n;
//	for (; i <= m; i++)
//	{
//		a = 1.0 * a / 2;
//		sum += a;
//	}
//	printf("本次弹射高度%.2lf，用经过该距离：%.2lf", a, sum);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[9][9] ;
//	int i, j;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			arr[i][j] = 1; 
//		}
//	}
//	for (i = 1; i < n; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%6d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int longest(char* str, char* word)
//{
//	int i, j;
//	int count_1 = 0;
//	int count_2 = 0;
//	char b[50];
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		j = 0;
//		while (isalpha(str[i]))
//		{
//			b[j++] = str[i++];
//			if (str[i]==' ')
//			{
//				count_1++;
//			}
//			count_1++;
//		}
//		b[j] = '\0';
//		if (strlen(b) > strlen(word))
//		{
//			strcpy(word, b);
//			count_2 = count_1;
//		}
//	}
//	return count_2-strlen(word);
//}
//int main()
//{
//	int i, j;
//	char b[50];
//	char str[105], word[45];
//	word[0] = '\0';
//	fgets(str, 100, stdin);
//	i=longest(str, word);
//	j = strlen(word);
//	printf("长度:%d ，下标:%d\n",j,i  );
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	for (; i <= 9; i++)
//	{
//		int j = 1;
//		for (; j <= i; j++)
//		{
//			printf("%-2d*%-2d = %-3d", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	char arr[105];
//	fgets(arr, 100, stdin);
//	int i = 0;
//	for (; i < strlen(arr); i++)
//	{
//		if (islower(arr[i]))
//		{
//			arr[i] = toupper(arr[i]);
//		}
//		else if (isupper(arr[i]))
//			arr[i] = tolower(arr[i]);
//	}
//	printf("%s", arr);
//	return 0;
//}
//int main()
//{
//	int arr[100] = { 0 };
//	int n, m;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	scanf("%d", &m);
//	for(int j=m;j<n;j++)
//	{
//		printf("%d ",arr[j]);
//	}
//	for (int j = 0; j < m; j++)
//	{
//		printf("%d ", arr[j]);
//	}
//	return 0;
//}
//int main()
//{
//	int m;
//	int n;
// 
//	scanf("%d%d", &n,&m);
//	int* p = calloc(n, sizeof(int));
//	int j = 0;//数组下标
//	int i = 1;//计数
//	int count = n;
//	int flag = 1;
//	while (flag)
//	{
//		if (j >= n)
//		{
//			j = 0;//超出下标范围就回去（形成圈）
//		}
//		if (p[j] == 0)
//		{
//			if (i == m)//数到m就杀
//			{
//				p[j] = 1;
//				i = 0;
//				count--;
//			}
//			i++;
//		}
//		if (count == 1)
//		{
//			int x = 0;
//			for (; x<n; x++)
//			{
//				if (p[x] == 0)
//				{
//					printf("%d ", x+1);
//				}
//			}
//			flag = 0;
//		}
//		j++;
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[10][10] = { 0 };
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	int j = 0;//i,j作为数组下标开始循环
//	int x = 1;//x作为当前搜查的地方
//	int l = 0;//因为我的一次大循环是一圈，所以用L来进行每一圈
//	int c = n-1;//J（行）的下标是否需要加，每走完一圈，所需要加的数减一。
//	for(;l<=n/2;l++)
//	{
//		int i = j = l;//确定I,J从哪一行开始。
//		for (; i <n; i++)
//		{
//			for (; j < n && arr[i][j] == 0;)//一个“7”字形的搜查
//			{
//				arr[i][j] = x++;
//				if (j <c)//用C来判断是否要加，C的作用跟L一样，但是L是正着加的,那么C就反着减的；形成对称
//				{
//					j++;
//				}
//			}
//		}
//		c--;
//		i--;
//		j--;
//		for (; i >= l; i--)//一个倒着的“7”字形的搜查
//		{
//			
//			for (; j >= l && arr[i][j] == 0;)
//			{
//				
//				arr[i][j] = x++;
//				if (j > l)//大于L就减为什么是L，是因为L作为当前行列的下标，用他减可以防止减到以搜查过的地方
//				{
//					j--;
//				}
//			}
//		}
//		
//	}
//	for (i = 0; i < n; i++)//打印
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
