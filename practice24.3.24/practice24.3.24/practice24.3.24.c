#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		putchar(ch++);
		putchar(++ch);
	}
	return 0;
}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 2;
//	for (i = 2; i <= n; i++)
//	{
//		int j;
//		int count = 0;
//		int flag = 1;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//void menu(void)
//{
//	printf("**********************************\n");
//	printf("******1. 8.75****2. 9.33**********\n");
//	printf("******3. 10.00***4. 11.20*********\n");
//	printf("******5.quit  ********************\n");
//}
//void money(float m,float t)
//{
//	float n;
//	if (t > 40)
//	{
//		n = 40.0 * m + (t - 40) * m * 1.5;
//		if (n <= 300 && n > 0)
//		{
//			printf("%f", n - 0.15 * n);
//		}
//		else if (n > 300 && n <= 450)
//		{
//			printf("%f", (300 - 0.15 * 300) + (n - 300) - (n - 300) * 0.2);
//		}
//		else
//		{
//			printf("%f", (300 - 0.15 * 300) + (150 - 150 * 0.2) + (n - 400) - (n - 400) * 0.25);
//		}
//	}
//	else
//	{
//		float s = m * t;
//
//		if (s <= 300 && s > 0)
//		{
//			printf("%f", s - 0.15 * s);
//		}
//		else if (s > 300 && s <= 450)
//		{
//			printf("%f", (300 - 0.15 * 300) + (s - 300) - (s - 300) * 0.2);
//		}
//		else
//		{
//			printf("%f", (300 - 0.15 * 300) + (150 - 150 * 0.2) + (s - 400) - (s - 400) * 0.25);
//		}
//	}
//}
//int main()
//{
//	menu();
//	printf("plz input 1-5(5 is quit:>");
//	int n;
//	scanf("%d", &n);
//	printf("plz input your work time:>");
//	float t;
//	scanf("%f", &t);
//	switch (n)
//	{
//	case(1):
//		money(8.75,t);
//		break;
//	case(2):
//		money(9.33, t);
//		break;
//	case(3):
//		money(10.00, t);
//		break;
//	case(4):
//		money(11.20, t);
//		break;
//	default:
//		printf("plz input a int ,such as 1, 2 ,3");
//	}
//	return 0;
//}
//int main()
//{
//	float t;
//	float n;
//	scanf("%f", t);
//	if (t > 40)
//	{
//		n = 40.0 * 10.0 + (t - 40) * 10.0 * 1.5;
//		if (n <= 300 && n>0)
//		{
//			printf("%f", n - 0.15 * n);
//		}
//		else if (n > 300 && n <= 450)
//		{
//			printf("%f", (300 - 0.15 * 300) + (n - 300) - (n - 300) * 0.2);
//		}
//		else
//		{
//			printf("%f", (300 - 0.15 * 300) + (150 - 150 * 0.2) + (n - 400) - (n - 400) * 0.25);
//		}
//	}
//	else
//	{
//		printf("%f", 10.0 * t);
//	}
//	return 0;
//}
//int main()
//{
//	int ei = 0;
//	int n = 0;
//	char ch;
//	while ((ch = getchar()) != '#')
//	{
//		if (ch == 'e')
//		{
//			ei=1;
//		}
//		else if (ch == 'i')
//		{
//			if (ei == 1)
//			{
//				n++;
//			}
//			else
//			{
//				ei = 0;
//			}
//		}
//		else
//		{
//			ei = 0;
//		}
//	}
//	printf(" %d", n);
//	return 0;
//}
//int main()
//{
//	int count = 0;
//	char ch;
//	while ((ch = getchar()) != '#')
//	{
//		switch (ch)
//		{
//		case ('!'):
//		{
//			printf("!!");
//			count++;
//			break;
//		}
//		case ('.'):
//		{
//			printf("!");
//			count++;
//			break;
//		}
//		default:
//		{
//			printf("%c", ch);
//			break;
//		}
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int count = 0;
//	char ch;
//	while ((ch = getchar()) != '#')
//	{
//		if (ch == '!')
//		{
//			printf("!!");
//			count++;
//		}
//		else if (ch == '.')
//		{
//			printf("!");
//			count++;
//		}
//		else
//		{
//			printf("%c", ch);
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int n_c = 0;
//	int m_c = 0;
//	int i;
//	while (scanf("%d", &i))
//	{
//		if (i == 0)
//		{
//			break;
//		}
//		if (i % 2 == 0)
//		{
//			n += i;
//			n_c++;
//		}
//		else
//		{
//			m += i;
//			m_c++;
//		}
//	}
//	printf("Å¼Êý%d,%f", n_c, 1.0 * n / n_c);
//	printf("ÆæÊý%d,%f", m_c, 1.0 * m / n_c);
//	return 0;
//}
//int main()
//{
//	char ch;
//	int a=0;
//	while ((ch = getchar()) != '#')
//	{
//		if (ch == '/n')
//		{
//			printf("'\\n'-%d",ch);
//		}
//		else if (ch == '/t')
//		{
//			printf("'\\t'-%d", ch);
//		}
//		else
//		{
//			printf("%c-%d", ch, ch);
//		}
//		a++;
//		if (a % 8 == 0)
//		{
//			printf("\n");
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char ch;
//	int a=0, b=0, c=0;
//	while ((ch = getchar()) != '#')
//	{
//		if (ch == " ")
//		{
//			a++;
//		}
//		else if (ch == '\n')
//		{
//			b++;
//		}
//		else
//		{
//			c++;
//		}
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != '#')
//	{
//		if (ch != '\n')
//		{
//			printf("Step1\n");
//			if (ch != 'c')
//			{
//				if (ch == 'b')
//				{
//					break;
//				}
//				else if (ch == 'h')
//				{
//					printf("step3\n");
//					
//				}
//				else
//				{
//					printf("step2");
//					printf("step3");
//				}
//			}
//		}
//	}
//	return 0;
//}