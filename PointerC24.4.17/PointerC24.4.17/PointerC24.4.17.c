#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	char sieve[1000];
	char* sp;
	int number;
	for (sp = sieve; sp < &sieve[1000];)
	{
		*sp++ = 1;
	}
	for (number = 3;; number += 2)
	{
		sp = &sieve[0] + (number - 3) / 2;
		if (sp >= &sieve[1000])
			break;
		while (sp += number, sp < &sieve[1000])
			*sp = 0;
	}
	printf("2\n");
	for (number = 3, sp = &sieve[0]; sp < &sieve[1000]; number += 2, sp++)
	{
		if (*sp)
			printf("%d\n", number);
	}
	return 0;
}
//void reverse_string(char* str)
//{
//	char arr[1005] = { 0 };
//	int sz = strlen(str);
//	char* p = str;//指向最后一个字符
//	int i = 0;
//	while (*p)
//	{
//		arr[i] = *p++;
//		i++;
//	}
//	i--;
//	for (; i >= 0; i--)
//	{
//		*str = arr[i];
//		str++;
//	}
//}
//int main()
//{
//	char arr[] = "hello world";
//	reverse_string(arr);
//	printf("%s", arr);
//}
//int del_substr(char* str, char const* substr)
//{
//	char* p;
//	if (p = strstr(str, substr))
//	{
//		int sz = strlen(substr);
//		int sp = strlen(str);
//		char* s = p + sz;
//		int i = 0;
//		for (; i < sp - 1; i++)
//		{
//			if (s)
//			{
//				*p++ = *s++;
//			}
//			else {
//				*p = '\0';
//			}
//		}
//		return 1;
//	}
//	else
//		return 0;
//}
//#define TRUE 1
//#define FALSE 0
///*
//** See if the substring beginning at ’str’ matches the string ’want’. If
//** so, return a pointer to the first character in ’str’ after the match.
//*/
//char* match(char* str, char const* want)
//{
//	
//	while (*want != '\0')
//		if (*str++ != *want++)
//			return NULL;
//	return str;
//}
//int del_substr1(char* str, char const* substr)
//{
//	char* next=str;
//	while (*str != '\0') {
//		next = match(str, substr);
//		if (next != NULL)
//			break;
//		str++;
//	}
//	if (*str == '\0')
//		return FALSE;
//	while (*str++ = *next++)
//	;
//	return TRUE;
//}
//int main()
//{
//	char arr[20] = "hello world";
//	char arr2[20] = "world";
//	del_substr(arr, arr2);
//	printf("%s", arr);
//}
//char* find_char(char const* source, char const* chars)
//{
//	if (source && chars)
//		return NULL;
//	char* p = source;
//	char* s = chars;
//	while (s)
//	{
//		while (p)
//		{
//			if (*p == *s)
//			{
//				return p;
//			}
//			p++;
//		}
//		s++;
//	}
//	return NULL;
//}
