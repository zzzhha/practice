#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<limits.h>

//#define INT_BITS ( CHAR_BIT * sizeof( int ) )
//int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit)
//{
//	unsigned mask;
//	if (starting_bit < INT_BITS && ending_bit < INT_BITS && starting_bit >= ending_bit)
//	{
//		mask = (unsigned)-1;
//		mask >>= INT_BITS - (starting_bit - ending_bit + 1);
//		mask <<= ending_bit;
//		original_value &= ~mask;
//		value_to_store <<= ending_bit;
//		original_value|=value_to_store& mask;
//	}
//	return original_value;
//}
//int main()
//{
//
//	return 0;
//}
//void set_bit(char bit_array[],unsigned int bit_number)
//{
//	bit_array[bit_number - 1] = 1;
//}
//void clear_bit(char bit_array[], unsigned int bit_number)
//{
//	bit_array[bit_number - 1] = 0;
//}
//void assign_bit(char bit_array[], unsigned int bit_number, int value)
//{
//	if (value == 0)
//	{
//		set_bit(bit_array, bit_number);
//	}
//	else
//	{
//		clear_bit(bit_array, bit_number);
//	}
//}
//void test_bit(char bit_array[], unsigned int bit_number)
//{
//	if (bit_array[bit_number - 1] == 0)
//	{
//		return 0;
//	}
//	else
//		return 1;
//}
//int main()
//{
//	return 0;
//}
//unsigned int reverse_bits1(unsigned int value)
//{
//	int i = 1;
//	int n = 0;
//	for (; i != 0; i <<= 1)
//	{
//		n <<= 1;
//		if (value&1)
//		{
//			n |= 1;
//		}
//		value >>= 1;
//	}
//	return n;
//}
//unsigned int reverse_bits(unsigned int value)
//{
//	int sz = sizeof(int) *8;
//	int i = 0;
//	int arr[32] = { 0 };
//	int j = 0;
//	unsigned int n = 0;
//	for (i=0; i < sz ; i++)
//	{
//		arr[i] = (value >> i) & 1;
//	}
//	for (i=31; i >= 0; i--)
//	{
//		n = (n << 1) | arr[j];
//		j++;
//	}
//	return n;
//}
//int main()
//{
//	printf("%u", reverse_bits(25));
//	return 0;
//}
//int encrypt(int ch, int base)
//{
//	ch -= base;
//	ch += 13;
//	ch %= 26;
//	return ch + base;
//}
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != EOF && ch != '\n')
//	{
//		if (ch >= 'A' && ch <= 'Z')
//			ch = encrypt(ch, 'A');
//		else if (ch >= 'a' && ch <= 'z')
//			ch = encrypt(ch, 'a');
//		putchar(ch);
//	}
//	return 0;
//}
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != EOF && ch != '\n')
//	{
//		putchar(tolower(ch));
//	}
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int i = 0;
//	int b = 5;
//	int c = 6;
//	//i = a > 3 ? b + 1 : c + 5;
//	/*if (a > 3)
//	{
//		i = b + 1;
//	}
//	else
//		i = c + 5;*/
//}
//void deblank(char string[])
//{
//	char* src = string;
//	char* dest=string++;
//	int ch;
//	while ((ch = *src++) != NULL)
//	{
//		if (is_white(ch))
//		{
//			if (src == string || !is_white(dest[-1]))
//				*dest++ = ' ';
//		}
//		else
//		{
//			*dest++ = ch;
//		}
//	}
//	*dest = '\0';
//}
//int is_white(int ch)
//{
//	return ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\n'
//		|| ch == '\r';
//}
//int substr(char dst[], char src[], int start, int len)
//{
//	int srcindex = start-1;
//	int dstindex = 0;
//	int i = 0;
//	if (start >= 0 && len >= 0)
//	{
//		for (;i<len;i++)
//		{
//			dst[dstindex] = src[srcindex];
//			dstindex++;
//			srcindex++;
//		}
//	}
//	dst[dstindex] = '\0';
//	return dstindex;
//}
//int main()
//{
//	char arr1[20];
//	char arr2[10];
//	return 0;
//}
//int main()
//{
//	char arr1[100] ;
//	char arr2[100] ;
//	gets(arr1);
//	int count = 0;
//	while ( 1)
//	{
//		
//		gets(arr2);
//		if(arr2[0]=='\n'|| arr2[0] == '\0')
//		{
//			break;
//		}
//		else
//		{
//			if (!strcmp(arr1, arr2))
//			{
//				if (!count)
//				{
//					printf("%s\n", arr1);
//					count = 1;
//				}
//			}
//			else {
//				count = 0;
//			}
//			strcpy(arr1, arr2);
//			
//		}
//	}
//	return 0;
//}
//char *my_strncpy(char *arr1,const char *arr2,int n)
//{
//	assert(arr1);
//	assert(arr2);
//	int i = 0;
//	for (; i < n; i++)
//	{
//		arr1[i] = arr2[i];
//	}
//	return arr1;
//}