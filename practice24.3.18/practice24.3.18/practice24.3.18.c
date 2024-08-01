#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	int arr[1005];
	gets(arr);
	char* token;
	token = strtok(arr, " ");
	int i = 0;
	while (token != NULL)
	{
		int len = strlen(token);
		printf("%d", len);
		token=strtok(NULL, " ");
		if (token!=NULL)
		{
			printf(",");
		}
	}
	return 0;
}
//int main()
//{
//	char arr[40];
//	scanf("%s", arr);
//	int sz = strlen(arr);
//	if (arr[sz - 1] == 'r')
//	{
//		if (arr[sz - 2] == 'e')
//		{
//			arr[sz - 1] = 0;
//			arr[sz - 2] = 0;
//		}
//	}
//	else if (arr[sz - 1] == 'y')
//	{
//		if (arr[sz - 2] == 'l')
//		{
//			arr[sz - 1] = 0;
//			arr[sz - 2] = 0;
//		}
//	}
//	else if (arr[sz - 1] == 'g')
//	{
//		if (arr[sz - 2] == 'n')
//		{
//			if (arr[sz - 3] == 'i')
//			{
//				arr[sz - 1] = 0;
//				arr[sz - 2] = 0;
//				arr[sz - 3] = 0;
//			}
//		}
//	}
//		printf("%s", arr);
//	return 0;
//}
//int main()
//{
//	char arr1[25];
//	char arr2[25];
//	scanf("%s", arr1);
//	scanf("%s", arr2);
//	if (strstr(arr2, arr1))
//	{
//		printf("%s is substring of %s", arr1, arr2);
//	}
//	else if (strstr(arr1, arr2))
//	{
//		printf("%s is substring of %s", arr2, arr1);
//	}
//	else
//		printf("No substring");
//	return 0;
//}
//int main()
//{
//	char arr[25] = { 0 };
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", arr);
//		int j = 0;
//		int sz = strlen(arr);
//		for (j = 0; j < sz; j++)
//		{
//			if (j == 0)
//			{
//				if (arr[j] >= 'a' && arr[j] <= 'z')
//				{
//					arr[j] -= 32;
//				}
//			}
//			else
//			{
//				if (arr[j] >= 'A' && arr[j] <= 'Z')
//				{
//					arr[j] += 32;
//				}
//			}
//		}
//		printf("%s\n", arr);
//		memset(arr,0,sizeof(arr));
//	}
//	return 0;
//}
//void reverse(char arr[], char arr2[], int sz)
//{
//	int i = sz;
//	int j = 0;
//	for (i = sz; i > 0; i--)
//	{
//		arr2[j] = arr[i-1];
//		j++;
//	}
//}
//int main()
//{
//	char arr[55] = { 0 };
//	scanf("%s", arr);
//	int i = 0;
//	int sz = strlen(arr);
//	for (i = 0; i < sz; i++)
//	{
//		if ((arr[i] >= 'a' && arr[i] <= 'z') || arr[i] >= 'A' && arr[i] <= 'Z')
//		{
//			if (arr[i] == 'x')
//			{
//				arr[i] = 'a';
//			}
//			else if (arr[i] == 'y')
//			{
//				arr[i] = 'b';
//			}
//			else if (arr[i] == 'z')
//			{
//				arr[i] = 'c';
//			}
//			else if (arr[i] == 'X')
//			{
//				arr[i] = 'A';
//			}
//			else if (arr[i] == 'Z')
//			{
//				arr[i] = 'C';
//			}
//			else if (arr[i] == 'Y')
//			{
//				arr[i] = 'B';
//			}
//			else
//				arr[i] += 3;
//		}
//	}
//	char arr2[55] = { 0 };
//	reverse(&arr, &arr2,sz);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr2[i] >= 'A' && arr2[i] <= 'Z')
//		{
//			arr2[i] += 32;
//		}
//		else if (arr2[i] >= 'a' && arr2[i] <= 'z')
//		{
//			arr2[i] -= 32;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c", arr2[i]);
//	}
//	return 0;
//}
//int main()
//{
//	char arr[10005] ;
//	gets(arr);
//	int sz = strlen(arr);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if ((arr[i] >= 'a' && arr[i] <= 'z')||arr[i]>='A'&&arr[i]<='Z')
//		{
//			if (arr[i] == 'a')
//			{
//				printf("z");
//			}
//			else if (arr[i] == 'A')
//			{
//				printf("Z");
//			}
//			else
//				printf("%c", arr[i] - 1);
//		}
//		else
//		{
//			putchar(arr[i]);
//		}
//	}
//	return 0;
//}