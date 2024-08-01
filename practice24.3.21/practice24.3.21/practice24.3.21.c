#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	char arr[20];
//	
//	scanf("%s", arr);
//	int i;
//	for (i = strlen(arr)-1; i >=0; i--)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	int i;
//	for (i = n; i < m; i++)
//	{
//		printf("%d %d %d", i, i * i, i * i * i);
//	}
//		return 0;
//}
//int main()
//{
//	char a;
//	scanf("%c", &a);
//	int i = 0;
//	for (; i < a - 'A'+1; i++)
//	{
//		int j = a - 'A';
//		for (; j >= i+1 ; j--)
//		{
//			printf(" ");
//		}
//		int n = 0;
//		for (; n <= i; n++)
//		{
//			printf("%c", 'A'+n);
//		}
//		int m =i-1;
//		for (; m >=0; m--)
//		{
//			printf("%c", 'A'+m);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	char a = 'A';
//		int i = 0;
//	for (; i < 6; i++)
//	{
//		
//		int j = 0;
//		for (; j <= i; j++)
//		{
//			printf("%c", a++);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	
//	int i = 0;
//	for (; i < 6; i++)
//	{
//		char a = 'F';
//		int j = 0;
//		for (; j <= i; j++)
//		{
//			printf("%c", a--);
//		}
//		printf("\n");
//	}
//	return 0;
//
//}
//int main()
//{
//	int i = 0;
//	for (; i < 5; i++)
//	{
//		int j = 0;
//		for (; j <= i; j++)
//		{
//			printf("$");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	char arr[26];
//	int i = 0;
//	char x = 'a';
//
//	for (i = 0; i < 26; i++)
//	{
//		//arr[i] = x;
//		//x++;
//		printf("%c", arr[i]=x++);
//		
//	}
//	return 0;
//}
//int main()
//{
//	char ch;
//	scanf("%c", &ch);
//	while (ch != 'g')
//	{
//		printf("%c", ch);
//		scanf("%c", &ch);
//	}
//	return 0;
//}