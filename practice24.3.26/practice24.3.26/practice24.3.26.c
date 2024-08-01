#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>


	void menu(void)
{
	printf("**********************************\n");
	printf("******a. 8.75****b. 9.33**********\n");
	printf("******c. 10.00***d. 11.20*********\n");
	printf("******q.quit  ********************\n");
}
void money(float m,float t)
{
	float n;
	if (t > 40)
	{
		n = 40.0 * m + (t - 40) * m * 1.5;
		if (n <= 300 && n > 0)
		{
			printf("%f", n - 0.15 * n);
		}
		else if (n > 300 && n <= 450)
		{
			printf("%f", (300 - 0.15 * 300) + (n - 300) - (n - 300) * 0.2);
		}
		else
		{
			printf("%f", (300 - 0.15 * 300) + (150 - 150 * 0.2) + (n - 400) - (n - 400) * 0.25);
		}
	}
	else
	{
		float s = m * t;

		if (s <= 300 && s > 0)
		{
			printf("%f", s - 0.15 * s);
		}
		else if (s > 300 && s <= 450)
		{
			printf("%f", (300 - 0.15 * 300) + (s - 300) - (s - 300) * 0.2);
		}
		else
		{
			printf("%f", (300 - 0.15 * 300) + (150 - 150 * 0.2) + (s - 400) - (s - 400) * 0.25);
		}
	}
}
int main()
{
	char n;
	do
	{
		menu();
		printf("plz input a-d(q is quit:>");
		scanf("%c", &n);
		if (n == 'q')
		{
			printf("thanks for you playing");
			break;
		}
		printf("plz input your work time:>");
		float t;
		scanf("%f", &t);
		switch (n)
		{
		case 'a':
			money(8.75, t);
			break;
		case 'b':
			money(9.33, t);
			break;
		case 'c':
			money(10.00, t);
			break;
		case 'd':
			money(11.20, t);
			break;
		default:
			printf("plz input a,b,c,etc\n");
		}
	} while (n!='q');
	return 0;
}
//char get_first(void)
//{
//	char in;
//	do
//	{
//		in = getchar();
//	} while (in == ' ' || in == '\n' || in == '\t');
//	return in;
//}
//int main()
//{
//	char ch;
//	ch = get_first();
//	printf("%c\n", ch);
//	return 0;
//}
//int main()
//{
//	int min = 1;
//	int max = 100;
//	int mid = (max + min) / 2;
//	char ch,in;
//	printf("i will guess the count");
//	do
//	{
//		printf("it is %d\n", mid);
//		if (getchar() == 'y')
//		{
//			break;
//		}
//		while ((in = getchar()) != '\n')
//		{
//			;
//		}
//		printf("他比%d大还是小，如果大请输入\"b\",如果小请输入\"s\"\n",mid);
//		if (getchar() == 'b')
//		{
//			min = mid+1;
//			mid = (min + max) / 2;
//		}
//		else if (getchar() == 's')
//		{
//			max = mid-1;
//			mid = (min + max) / 2;
//		}
//		else
//		{
//			printf("plz 输入 \"b\"or \"s\"\n");
//		}
//	} while ((ch = getchar()) != 'y');
//	printf("i know it is what,it is %d\n", mid);
//	return 0;
//}
//int main()
//{
//	char ch;
//	int i = 0;
//	int sum = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (isalpha(ch))
//		{
//			i++;
//		}
//		if (ispunct(ch))
//		{
//			sum++;
//		}
//	}
//	printf("%f", 1.0 * i / sum);
//	return 0;
//}
//int main()
//{
//	int count_m = 0;
//	int count_b = 0;
//	char ch;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch >= 'A' && ch <= 'Z')
//		{
//			count_b++;
//		}
//		if (ch >= 'a' && ch <= 'z')
//		{
//			count_m++;
//		}
//	}
//	printf("daxie=%d xiaoxie=%d", count_b, count_m);
//	return 0;
//}
//int main()
//{
//	int count = 0;
//	char ch;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch == '\n')
//		{
//			printf("\n");
//		}
//		else if (ch == '\t')
//		{
//			printf("\t");
//		}
//		else if (ch >= 32)
//		{
//			printf("%c", ch);
//		}
//		else
//			printf("^%c", ch+64);
//	}
//	return 0;
//}