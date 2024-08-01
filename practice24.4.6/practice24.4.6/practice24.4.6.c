#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//void print_orig(char* st)
//{
//	printf("%s", st);
//}
//void print_upper(char* st)
//{
//	while (*st != EOF && *st != '\0')
//	{
//		putchar(toupper(*st++));
//	}
//}
//void print_lower(char* st)
//{
//	while (*st != EOF && *st != '\0')
//	{
//		putchar(tolower(*st++));
//	}
//}
//int main(int argc, char* argv[])
//{
//	char c;
//	if (argc < 2)
//	{
//		c = 'p';
//	}
//	char c = argv[1][1];
//	char test[256];
//	printf("enter a string to convert");
//	fgets(test, 256, stdin);
//	switch (c)
//	{
//	case 'p':
//	case 'P':
//		print_orig(test);
//		break;
//	case 'u':
//	case 'U':
//		print_upper(test);
//		break;
//	case 'l':
//	case 'L':
//		print_lower(test);
//		break;
//	}
//	return 0;
//}
//int myatoi(char* st)
//{
//	int result = 0;
//	int bit_mark = 1;
//	int length = sstrlen(st);
//	int i = 0;
//	for (i = length; i > 0; i--)
//	{
//		if (isdigit(*(st + i - 1)) == 0)
//		{
//			printf("error\n");
//			return 0;
//		}
//		result += (*(st + i - 1) - '0') * bit_mark;
//		bit_mark *= 10;
//	}
//	return result;
//}
//int main(int argc, char* argv[])
//{
//	char test[8];
//	scanf("%s", test);
//	printf("you input int is:%d\n", myatoi(test));
//	return 0;
//}
//int main(int argc,char *argv[])
//{
//	if (argc != 3)
//	{
//		printf("error\n");
//		return 0;
//	}
//	float f = atof(argv[1]);
//	int i = atoi(argv[2]);
//	float result = 1;
//	int k = 0;
//	for (; k < i; k++)
//	{
//		result = result * f;
//	}
//	printf("The %g s %d power is %g\n", f, i, result);
//	return 0;
//}
//int main(int argc, char* argv[])
//{
//	if (argc < 2)
//	{
//		printf("Error\n");
//	}
//	else
//	{
//		int i = 0;
//		for (i = argc; i > 1; i--)
//		{
//			printf("%s ", argv[i - 1]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//char *empty_delete(char *arr)
//{
//	char* head = arr;
//	int count = 0;
//	while (*arr != '\n')
//	{
//		if (*arr != ' ')
//		{
//			*head++ = *arr++;
//		}
//		else
//		{
//			arr++;
//			count++;
//		}
//	}
//	while (count--)
//	{
//		*head++ = '\0';
//	}
//	return arr;
//}
//int main()
//{
//	char arr[100] ;
//	char *p = NULL;
//	fgets(arr, 100, stdin);
//	int i = 0;
//	int flag = 1;
//	while(*arr!='\n')
//	{
//		int sz = strlen(arr);
//		p= empty_delete(arr);
//		printf("%s\n", arr);
//		fgets(arr, 100, stdin);
//	}
//	printf("Done!");
//	return 0;
//}
//void reverse(char arr[],int sz)
//{
//	char str[50] = { 0 };
//	int i = sz-1;
//	int j = 0;
//	for (; i >= 0; i--)
//	{
//		str[j] = arr[i];
//		j++;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = str[i];
//	}
//}
//int main()
//{
//	char arr[] = "hello world";
//	reverse(arr,strlen(arr));
//	printf("%s", arr);
//	return 0;
//}
//char* string_in(char* arr1, char* arr2)
//{
//	int count = 0;
//	char* sp = arr1;
//	int sz2 = strlen(arr2);
//	int sz1 = strlen(arr1);
//	while (*arr1)
//	{
//		if (*arr1 == *arr2)
//		{
//			count++;
//			arr1++;
//			arr2++;
//			if (count == sz2)
//			{
//				return sp;
//			}
//		}
//		else
//		{
//			arr1++;
//			sp++;
//			count = 0;
//		}
//
//
//	}
//	return NULL ;
//}
//int main()
//{
//	char arr1[10] = "hats";
//	char arr2[5] = "at";
//	char* sp=string_in(arr1, arr2);
//	printf("%c", *sp);
//	return 0;
//}
//char* my_strncpy(char arr1[], const char arr2[], int n)
//{
//	assert(arr1);
//	assert(arr2);
//	char* sp1 = arr1;
//	char* sp2 = arr2;
//	int i = 0;
//	if (strlen(arr2) >= n&&sizeof(arr1)-strlen(arr1)>n)
//	{
//		return arr1;
//	}
//	else
//	{
//		while ((*arr1++) != '\0')
//		{
//			sp1++;
//		}
//		while(*sp2)
//		{
//			*sp1++ = *sp2++;
//		}
//		*sp1 = '\0';
//	}
//	return arr1;
//}
//int main()
//{
//	char arr1[100] = "hello world";
//	char arr2[13] = "good morning";
//	char* sp = my_strncpy(arr1, arr2, 13);
//	printf(arr1);
//	return 0;
//}
//int is_within(const char* sp, char n)
//{
//	assert(sp);
//	int i = 0;
//	int sz=strlen(sp);
//	while (i < sz)
//	{
//		if (sp[i] == n)
//		{
//			return 1;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	const char* ch = "my name is zhao shaoyu";
//	int i = is_within(ch, 'z');
//	if (i)
//	{
//		printf("yes");
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//}
//char* my_strchr(char arr[], char n)
//{
//	assert(arr);
//	int i = 0;
//	char* sp = arr;
//	while (i< n)
//	{
//		if (arr[i] == n)
//		{
//			return sp;
//		}
//		else
//		{
//			sp++;
//			i++;
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	char arr[] = "my name is zhao shaoyu";
//	char* pch=my_strchr(arr, 'z');
//	printf("%s", pch);
//	return 0;
//}
//char* get_first_word(char str[],int n)
//{
//	char arr[100] = { 0 };
//	int i = 0;
//	char* pch = arr;
//	fgets(arr, 100, stdin);
//	while ((arr[i] == '\n' || arr[i] == ' ' || arr[i] == '\t')&&arr[i]!='\0')
//	{
//		i++;
//		pch++;
//	}
//	while (*pch != '\n' && *pch != ' ' && *pch != '\t'&& *pch!='\0')
//	{
//		*str++ = *pch++;
//		i++;
//		if(i>=n)
//			{
//				char ch;
//				while((ch=getchar())!=EOF&&ch!='\n')
//				{
//					;
//				}
//				return str;
//			}
//	}
//	char ch;
//	while((ch=getchar())!=EOF&&ch!='\n')
//	{
//		;
//	}
//	return str;
//}
//int main()
//{
//	char str[100] = { 0 };
//	get_first_word(str,100);
//	printf("%s", str);
//	return 0;
//}
//void get_arr(char arr[],int n)
//{
//	int i = 0;
//	do 
//	{
//		arr[i] = getchar();
//		if(arr[i]=='\n'||arr[i]==' '||arr[i]=='\t')
//		{
//			break;
//		}
//	} while (arr[i] != EOF && ++i < n);
//}
//int main()
//{	
//	char arr[100];
//	get_arr(arr,100);
//	puts(arr);
//	return 0;
//}
//char* first_empty(const char* str)
//{
//	while (*str!='\0')
//	{
//		if (*str == ' ')
//		{
//			return str;
//		}
//		str++;	
//	}
//	return NULL;
//}
//int main()
//{
//	char arr[] = "hello world";
//	char* str=first_empty(arr);
//	printf(str);
//	return 0;
//}
//double arr_max(double arr[][5],int n)
//{
//	double max = arr[0][0];
//	int i = 0;
//	for (; i < n; i++)
//	{
//		int j = 0;
//		for (; j < 5; j++)
//		{
//			if (max < arr[i][j])
//			{
//				max = arr[i][j];
//			}
//		}
//	}
//	return max;
//}
//double all_average(double arr[][5],int l)
//{
//	double sum = 0;
//	int i = 0;
//	for (; i < l; i++)
//	{
//		int j = 0;
//		for (; j < 5; j++)
//		{
//			sum += arr[i][j];
//		}
//	}
//	return sum / 15;
//}
//double line_average(double arr[][5], int i)
//{
//	int j = 0;
//	double sum = 0;
//	for (; j < 5; j++)
//	{
//		sum += arr[i][j];
//	}
//	return sum / 5;
//}
//void input(double arr[][5])
//{
//	int i = 0;
//	for (; i < 3; i++)
//	{
//		int j = 0;
//		for (; j < 5; j++)
//		{
//			scanf("%lf", arr[i][j]);
//		}
//	}
//}
//int main()
//{
//	double arr[3][5];
//	input(arr);
//	int i = 0;
//	for(;i<3;i++)
//	{ 
//		double y=line_average(arr,i);
//		printf("%lf ", y);
//	}
//	double ret = all_average(arr,3);
//	printf("%lf ", ret);
//	double max = arr_max(arr,3);
//	printf("%lf ", max);
//	return 0;
//}
//void arr_x2(int arr[][5], int n)
//{
//	int i = 0;
//	for (; i < n; i++)
//	{
//		int j = 0;
//		for (; j < 5; j++)
//		{
//			arr[i][j] = arr[i][j] * 2;
//		}
//	}
//}
//void arr_printf(int arr[][5], int n)
//{
//	int i = 0;
//	for (; i < n; i++)
//	{
//		int j = 0;
//		for (; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,0,2,0,3},{4,0,5,0,6},{7,0,8,0,9} };
//	arr_printf(arr, 3);
//	arr_x2(arr, 3);
//	arr_printf(arr, 3);
//	return 0;
//}
//void arr_add(int arr1[], int arr2[], int arr3[], int n)
//{
//	int i = 0;
//	for (; i < n; i++)
//	{
//		arr3[i] = arr1[i] + arr2[i];
//	}
//}
//int main()
//{
//	int arr1[4] = { 2,4,5,8 };
//	int arr2[4] = { 1,0,4,6 };
//	int arr3[4] = { 0 };
//	arr_add(arr1, arr2, arr3, 4);
//	int i = 0;
//	for (; i < 4; i++)
//	{
//		printf("%d ", arr3[i]);
//	}
//	return 0;
//}
//void arr_copy(double(*arr3)[5], double(*arr4)[5], int n)
//{
//	int x = 0;
//	for (; x < n; x++)
//	{
//		int y = 0;
//		for (; y < 5; y++)
//		{
//			arr4[x][y] = arr3[x][y];
//		}
//	}
//}
//int main()
//{
//	double arr1[][5] = { {1,0,2,0,3},{4,0,5,0,6},{7,0,8,0,9} };
//	double arr2[3][5] = { 0 };
//	int i = 0;
//	arr_copy(arr1, arr2,3);
//	for (i = 0; i <3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%.0lf ", arr2[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//void arr_copy(double(*arr)[5], double(*arr2)[5])
//{
//	int x = 0;
//	for (; x < 3; x++)
//	{
//		int y = 0;
//		for (; y < 5; y++)
//		{
//			arr2[x][y] = arr[x][y];
//		}
//	}
//}
//int main()
//{
//	double arr1[3][5] = { {1,0,2,0,3},{4,0,5,0,6},{7,0,8,0,9} };
//	double arr2[3][5] = { 0 };
//	arr_copy(arr1, arr2);
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (; j < 5; j++)
//		{
//			printf(" %.0lf", arr2[i][j]);
//		}
//	}
//	return 0;
//}