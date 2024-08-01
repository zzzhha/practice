#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<string.h>


//15.
void dollars(char* dest, char const* src)
{
	int sz = strlen(src);
	*dest++ = '$';
	int count = 0;
	if (sz > 2)
	{
		for (int i = sz - 2; i > 0; i--)
		{
			*dest++ == *src++;
			count++;
			if (count == 3)
			{
				*dest++ = ',';
				count = 0;
			}
		}
	}
	else
	{
		*dest++ = '0';
	}
	*dest++ = '.';
	*dest++ = sz < 2 ? '0' : *src++;
	*dest++ = sz < 1 ? '0' : *src;
	*dest = '\0';
}
//14.
void decrypt(char* data, char const* key)
{
	int ch;
	char arr[] = "abcdefghijklnmopqrstuvwxyz";
	for (; (ch = *data) != '\0'; data++)
	{
		if (islower(ch))
		{
			*data = arr[strchr(key, ch) - key];
		}
		else if (issupper(ch))
		{
			*data = toupper(arr[strchr(key, ch) - key]);
		}
	}
}
//13.
void encrypt(char* data, char const* key)
{
	int ch;
	for (; (ch = *data) != '\0'; data++)
	{
		if (islower(ch))
		{
			*data = (key[ch - 'a']);
		}
		else if (isupper(ch))
			*data = toupper(key[ch - 'A']);
	}
}
//12.
char adc[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char bcd[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int prepare_key(char* key)
{
	int i, j;
	char* p = key;
	char* sh = key;
	int ch;
	for (i = 0; (j = key[i]) != '\0'; i++)
	{
		if (!islower(key[i]))
		{
			if (!isupper(key[i]))
				return 0;
			*p = tolower(key[i]);
		}
		
	}
	for (p = key; (ch = *p) != '\0'; )
	{
		sh = ++p;
		while ((ch = strchr(sh, ch)) != NULL)
			strcpy(sh, sh + 1);
	}
	for (ch='a'; ch<='z'; ch++)
	{
		if (strchr(key, ch) == NULL)
		{
			*p++ = ch;
			*p = '\0';
		}
	}
	return 1;
}
int main()
{
	char arr[100];
	prepare_key(arr);
	return 0;
}
////11.
//int count_arr(char* str, char* src)
//{
//	int count = 0;
//	while (*str)
//	{
//		char* sp = str++;
//		if (!strncmp(sp, src, 3))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	char arr1[105];
//	fgets(arr1, 100, stdin);
//	char arr2[] = "the";
//	int d = count_arr(arr1, arr2);
//	printf("%d", d);
//	return 0;
//}
////10.
//int malindrome(char* string)
//{
//	char* start = string;
//	char* end = string + strlen(string) - 1;
//	
//	while (1)
//	{
//		while (!isalpha(*start))
//			start++;
//		while (!isalpha(*end))
//			end--;
//		if (end <= start)
//			return 1;
//		if (tolower(*start++) != tolower(*end--))
//			return 0;
//	}
//}
////9.
//int count_chars(char const* str, char const* chars)
//{
//	int count = 0;
//	while (*str)
//	{
//		char* ch = str++;
//		char* ps = chars;
//		while (*ps)
//		{
//			if (*ch == *ps++)
//				count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[] = "hlo";
//	int count = count_chars(arr1,arr2);
//	printf("%d", count);
//	return 0;
//}
//8.
//char* my_strnchr(char const* str, int ch,int which)
//{
//	if (which == 1)
//		return strchr(str, ch);
//	else
//	{
//		int count = 0;
//		while (*str!='\0')
//		{
//			if (*str++ == ch)
//				count++;
//			if (count == which)
//				return str - 1;
//		}
//	}
//	return NULL;
//}
//7.
//char* my_strrchr(char const* str, int ch)
//{
//	char* sp = NULL;
//	for (; (str = strchr(str, ch)) != NULL; str += 1)
//		sp = str;
//	return sp;
//}
//int main()
//{
//	char arr1[20] = "hello ,world";
//	int ch = 'l';
//	char* sp = my_strnchr(arr1, ch,3);
//	printf("%s", sp);
//	
//	return 0;
//}
//6.
//char* my_strcpy_end(char* dest,const char* scr)
//{
//	while ((*dest++ = *scr++)!='\0')
//	{
//		;
//	}
//	return dest - 1;
//}
////5.
//void my_strncat(char* dest, char* src, int dest_len)
//{
//	dest_len--;
//	int length = strlen(src);
//	int size = strlen(dest);
//	dest_len -= size;
//	if (dest_len > 0)
//		strncat(dest + size, src, dest_len);
//4.
//int my_strlen(char* str, int size)
//{
//	int i = 0;
//	for (; i < size; i++)
//	{
//		if ((*str++) == '\0')
//			break;
//	}
//	return i;
//}
//char* my_strcat(char* des, const char* str, int size)
//{
//	size--;
//	int a = size -(int)my_strlen(des, size);
//	if(a>0)
//	{
//		strncat(des, str, a);
//		des[size] = '\0';
//	}
//	return des;
//}
////3.
//char * my_strcpy(char* str,const char*ptr,int size)
//{
//	strncpy(str, ptr, size);
//	str[size - 1] = '\0';
//	return str;
//}
////2.
//int my_strlen(char* str, int size)
//{
//	int i = 0;
//	for (; i < size; i++)
//	{
//		if ((*str++)=='\0')
//			break;
//	}
//	return i;
//}
////1.
//int main()
//{
//	char arr[105];
//	fgets(arr, 100,stdin);
//	char* ch = arr;
//	int white_char = 0;
//	int control_char = 0;
//	int number_char = 0;
//	int low_char = 0;
//	int up_char = 0;
//	int punct_char = 0;
//	int nprint_char = 0;
//	int total = strlen(arr);
//	while (*ch)
//	{
//		if (iscntrl(*ch))
//			control_char++;
//		if (isspace(*ch))
//			white_char++;
//		if (isdigit)
//			number_char++;
//		if (islower(*ch))
//			low_char++;
//		if(isupper(*ch))
//			up_char++;
//		if (ispunct(*ch))
//			punct_char++;
//		if (!isprint(*ch))
//			nprint_char++;
//		ch++;
//	}
//	printf("%3.0f%% control characters\n",
//		control_char * 100.0 / total);
//	printf("%3.0f%% whitespace characters\n",
//		white_char * 100.0 / total);
//	printf("%3.0f%% digit characters\n",
//		number_char * 100.0 / total);
//	printf("%3.0f%% lower case characters\n",
//		low_char * 100.0 / total);
//	printf("%3.0f%% upper case characters\n",
//		up_char * 100.0 / total);
//	printf("%3.0f%% punctuation characters\n",
//		punct_char * 100.0 / total);
//	printf("%3.0f%% non¨Cprintable characters\n",
//		nprint_char * 100.0 / total);
//	return 0;
//}