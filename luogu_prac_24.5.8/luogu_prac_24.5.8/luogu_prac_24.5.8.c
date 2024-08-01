#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char word[12];
	char sentence[1000005];
	fgets(word, 11, stdin);
	int w = strlen(word);
	int i = 0;
	int count = 0;
	int flag = 0;
	for (; i < w; i++)
	{
		if(isupper(word[i]))
		{
			word[i] = tolower(word[i]);
		}
	}
	fgets(sentence, 1000004, stdin);
	int s = strlen(sentence);
	for (i = 0; i < s; i++)
	{
		if (isupper(sentence[i]))
			sentence[i] = tolower(sentence[i]);
	}
	char* ch;
	char* find = sentence;
	int ret = -1;
	for (; ch = strstr(find, word); ) 
	{
		if (ch != NULL
			&& (ch == sentence || *(ch - 1) == ' ') 
			&& (*(ch + w) == '\0' || *(ch + w) == ' ')) 
		{
			count++;
			if (flag == 0)
			{
				flag = 1;
				ret = ch - sentence;
			}
		}
		find = ch + w;
	}

	if (flag == 1)
		printf("%d %d", count, ret);
	else
		printf("%d",ret);
	return 0;
}
//int main()
//{
//	char arr[15] = { 0 };
//	fgets(arr, 14, stdin);
//	int j = strlen(arr);
//	int sum = 0;
//	int count = 1;
//	for (int i = 0; i <j-1; i++)
//	{
//		if(isdigit(arr[i]))
//		{
//			sum += (arr[i] - '0') * (count++);
//		}
//	}
//	sum %= 11;
//	if (sum == 10)
//		sum = 'X';
//	else
//		sum += '0';
//	if (arr[j-1] != sum)
//	{
//		arr[j-1] = sum;
//		printf("%s ", arr);
//	}
//	else
//		printf("Right");
//	return 0;
//}
//int main()
//{
//	char arr[10];
//	fgets(arr, 9, stdin);
//	int n = strlen(arr);
//	int i = 0;
//	int count = 0;
//	for (; i < n; i++)
//	{
//		if (isalnum(arr[i]))
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int n,m,k;
//	scanf("%d%d%d", &n,&m,&k);
//	int i = 0;
//	int j = 0;
//	int arr[1004][1004] = { 0 };
//	int src[1004][1004] = { 0 };
//	int str[1004] = { 0 };
//	
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			if (!src[j][arr[i][j]-1])
//			{
//				src[j][arr[i][j]-1] = 1;
//				str[arr[i][j]-1]++;
//			}
//		}
//	}
//	for (i = 0; i < k; i++)
//	{
//		printf("%d ", str[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[100];
//	int str[100];
//	int i;
//	int count = 0;
//	int c;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		str[i] = 2;
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			for (int p = 0; p < n; p++)
//			{
//				if (arr[p] == arr[i] + arr[j] && str[p] != 1)
//				{
//					count++;
//					str[p] = 1;
//				}
//			}
//		}
//	}
//	printf("%d", count);
//	return 0;
//}