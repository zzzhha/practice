#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include<ctype.h>
#include <stdarg.h>
//static char* digits[] = {
//"", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", "SIX ", "SEVEN ",
//"EIGHT ", "NINE ", "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN ",
//"FOURTEEN ", "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",
//"NINETEEN "
//};
//static char* tens[] = {
//"", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", "SIXTY ", "SEVENTY ",
//"EIGHTY ", "NINETY "
//};
//static char* magnitudes[] = {
//"", "THOUSAND ", "MILLION ", "BILLION "
//};
//static void do_one_group(unsigned int amount, char* buffer, char** magnitude)
//{
//	int value;
//	value = amount / 1000;
//	if (value > 0)
//		do_one_group(value, buffer, magnitude + 1);
//	amount %= 1000;
//	value = amount / 100;
//	if (value > 0) {
//	strcat(buffer, digits[value]);
//	strcat(buffer, "HUNDRED ");
//}
//
//value = amount % 100;
//if (value >= 20) {
//	strcat(buffer, tens[value / 10]);
//	value %= 10;
//}
//if (value > 0)
//strcat(buffer, digits[value]);
//
//if (amount > 0)
//strcat(buffer, *magnitude);
//}
//void
//written_amount(unsigned int amount, char* buffer)
//{
//	if (amount == 0)
//		
//		strcpy(buffer, "ZERO ");
//	else
//	{
//		*buffer = '\0';
//		do_one_group(amount, buffer, magnitudes);
//	}
//}
//void printf(char* format, ...)
//{
//	va_list arg;
//	char ch;
//	char* str;
//	va_start(arg, format);
//	while ((ch = *format++) != '\0') {
//		if (ch != '% ') 
//		{
//			putchar(ch);
//			continue;
//		}
//
//		switch (*format != '\0 ' ? *format++ : '\0') {
//		case 'd':
//			print_integer(va_arg(arg, int));
//			break;
//		case 'f':
//			print_float(va_arg(arg, float));
//			break;
//		case 'c':
//			putchar(va_arg(arg, int));
//			break;
//		case 's':
//			str = va_arg(arg, char*);
//			while (*str != '\0')
//				putchar(*str++);
//			break;
//		}
//	}
//}
//int max_list(int first_arg, ...)
//{
//	va_list var_arg;
//	int max = 0;
//	if (first_arg >= 0) {
//		int this_arg;
//		max = first_arg;
//		va_start(var_arg, first_arg);
//		while ((this_arg = va_arg(var_arg, int)) >= 0)
//		{
//			if (this_arg > max)
//			{
//				max = this_arg;
//			}
//		}
//		va_end(var_arg);
//	}
//	return max;
//}
//int ascii_to_integer(char* string)
//{
//	char* p = string;
//	int sum = 0;
//	while(*p)
//	{
//		if (isdigit(p))
//		{
//			sum = sum * 10 + (p - '0');
//		}
//		else 
//		{
//			return 0;
//		}
//		p++;
//	}
//	return sum;
//}
//int gcd(int m, int n)
//{
//	return n == 0 ? m : gcd(n, m % n);
//}

//int hermite(int n, int x)
//{
//	if (n <= 0)
//	{
//		return 1;
//	}
//	else if(n==1)
//	{
//		return x * 2;
//	}
//	else
//	{
//		return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
//	}
//}

//int prime(int n)
//{
//	int i = 2;
//	for (; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int count = 0;
//	for (int i = 100000; i < 101000; i++)
//	{
//		if (prime(i))
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//void sieveOfEratosthenes(int n)
//{
//	int* prime = (int*)calloc(n + 1, sizeof(int));
//	if (prime == NULL) {
//		exit(EXIT_FAILURE);
//	}
//	for (int p = 2; p <= n; p++) {
//		prime[p] = 1; 
//	}
//	prime[0] = prime[1] = 0;
//	for (int p = 2; p * p <= n; p++)
//	{
//		if (prime[p] == 1)
//		{
//			for (int i = p * p; i <= n; i += p)
//			{
//				prime[i] = 0;
//			}
//		}
//	}
//	for(int p = 2; p <= n; p++)
//		if (prime[p])
//			printf("%d ", p);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	sieveOfEratosthenes(n);
//	return 0;
//}