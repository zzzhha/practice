#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct name
{
	char first_name[20];
	char last_name[20];
};
struct student
{
	struct name student_name;
	float grade[3];
	float average;
};
int main()
{
	struct student csize[4] ;

	return 0;
}
//struct name
//{
//	char first_name[20];
//	char middle_name[20];
//	char last_name[20];
//};
//struct society
//{
//	char social_number[20];
//	struct name one;
//};
//int main()
//{
//	struct society people[5];
//	scanf("%s", &people[0].one.first_name);
//	scanf("%s", &people[0].one.last_name);
//	scanf("%s", &people[0].one.middle_name);
//	scanf("%s", &people[0].social_number);
//	printf("%s %s ", people[0].one.first_name, people[0].one.last_name);
//	if (people[0].one.middle_name[0] != '\0')
//	{
//		printf("%c.", people[0].one.middle_name[0]);
//	}
//	printf("-- %s", people[0].social_number);
//
//	return 0;
//}
//struct book
//{
//	char title[40];
//	char author[40];
//	float value;
//};
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	char* find;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		find = strchr(st, '\n');
//		if (find)
//		{
//			*find = '\0';
//		}
//		else
//		{
//			while (getchar() != '\n')
//			{
//				continue;
//			}
//		}
//	}
//}
//void org(struct book library[], int index, int count)
//{
//	for (; index < count; index++)
//	{
//		printf("%s by %s:%.2f\n", library[index].title, library[index].author, library[index].value);
//	}
//}
//int strcmp_abc(const void* e1, const void* e2)
//{
//	if ((((struct book*)e1)->title - ((struct book*)e2)->title) < 0)
//		return 1;
//	else if ((((struct book*)e1)->title - ((struct book*)e2)->title) == 0)
//		return 0;
//	else
//		return -1;
//}
//int strcmp_value(const void* e1, const void* e2)
//{
//	if ((((struct book*)e1)->value - ((struct book*)e2)->value) < 0)
//		return -1;
//	else if ((((struct book*)e1)->value - ((struct book*)e2)->value) == 0)
//		return 0;
//	else
//		return 1;
//}
//int main()
//{	
//	struct book library[100];
//	int count = 0;
//	int index=0;
//	printf("Plezse enter the book title.\n");
//	printf("Press [enter] at the start of a line to stop.\n");
//	while (count < 100 && s_gets(library[count].title, 40) != NULL && library[count].title[0] != '\0')
//	{
//		printf("Now enter the auther");
//		s_gets(library[count].author, 40);
//		printf("Now enter the value");
//		scanf("%f", &library[count++].value);
//		while (getchar() != '\n')
//			continue;
//		if (count < 100)
//			printf("Enter the next title.\n");
//	}
//	if (count > 0)
//	{
//		
//		int sz = sizeof(struct book);
//		printf("Here is the list of your books:\n");
//		org(library, index, count);
//		qsort(library, count, sz, strcmp_abc);
//		org(library, index, count);
//		qsort(library, count, sz, strcmp_value);
//		org(library, index, count);
//	}
//	else
//		printf("No books?Too bad");
//	return 0;
//}
//int run(char year[], int ret,int len)
//{
//	int i = 0;
//	int count = 0;
//	int years=0;
//	int j = len;
//	for (; i < len; i++)
//	{
//		if (isdigit(year[i]))
//		{
//			count++;
//			years += (year[i]-'0') * pow(10, --j);
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	if(count==len)
//	{
//		if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0))
//		{
//			return ret;
//		}
//		else
//		{
//			return ret-1;
//		}
//	}
//}
//int days(int arr[],char y[], char m[], int d, int len, int len_y)
//{
//		char* arr2[12] ={ "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
//		if (len <= 2&&len>=0)
//		{
//			int i = 0;
//			int sum = 0;
//			int months = 0;
//			if (len == 2)
//			{
//				months = (m[0] - '0') * 10 + (m[1]-'0');
//			}
//			else
//			{
//				months = (m[0]-'0');
//			}
//			for (; i < months-1; i++)
//			{
//				sum += arr[i];
//			}
//			if(arr[i]>=d)
//			{
//				sum += d;
//				sum = run(y, sum, len_y);
//				return sum;
//			}
//			else
//			{
//				return 0;
//			}
//
//		}
//		else if(len > 2&&len<=8)
//		{
//			int i = 0;
//			int ret = 0;
//			int count = 0;;
//			for (; i < len; i++) {
//				tolower(m[i]);
//			}
//			for (i = 0; i < 12; i++)
//			{
//				if (strncmp(arr2[i], m,3) == 0)
//				{
//					count = i;
//					break;
//				}
//				else
//				{
//					return 0;
//				}
//			}
//			for (; i > 0; i--)
//			{
//				ret += arr[i-1];
//			}
//			if(arr[count]>=d)
//			{
//				ret += d;
//				ret = run(y, ret,len_y);
//				return ret;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		else 
//		{
//			return 0;
//		}
//}
//int main()
//{
//	int run_year[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
//	int day;
//	char month[10];
//	char  year[10];
//	printf("plz input year:");
//	scanf("%s", &year);
//	printf("plz input month:");
//	scanf("%s", month);
//	printf("plz input day:");
//	scanf("%d", &day);
//	int len = strlen(month);
//	int len_y = strlen(year);
//	int ret=days(run_year ,year,month,day,len,len_y);
//	if(ret!=0)
//	{
//		printf("一共有%d天", ret);
//	}
//	else
//	{
//		printf("error\n");
//	}
//	return 0;
//}