#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//int main() 
//{
//	float a, b, c;
//	printf("�����������ε������ߣ��ã��ָ�\n");
//	scanf("%f,%f,%f", &a, &b, &c);
//	if (a + b > c && a + c > b && b + c > a)
//	{
//		float p = (a + b + c) / 2;
//		float arr = sqrt(p * (p - a) * (p - b) * (p - c));
//		if (a == b && a == c)
//		{
//			
//			printf("�����:%f\n", arr);
//			printf("�ȱ�������\n");
//		}
//		else if (a == b || b == c || a == c)
//		{
//			
//			printf("�����:%f\n", arr);
//			printf("����������\n");
//		}
//		else if ((c * c) == (a * a + b * b))
//		{
//			
//			printf("�����:%f\n", arr);
//			printf("ֱ��������\n");
//		}
//		else
//		{
//			
//			printf("�����:%f\n", arr);
//			printf("��ͨ������\n");
//		}
//	}
//	else
//	{
//		printf("���ܹ���������\n");
//	}
//	return 0;
//}
//int main()
//{
//	char ch,sport,diet;
//	printf("Are you a boy(M) or a girl(F)?");
//	scanf("%c", &ch);
//	float f, m,sum;
//	printf("Please input your father's height(cm):");
//	scanf("%f", &f);
//	printf("Please input your mother's height(cm):");
//	scanf("%f", &m);
//	printf("Do you like sports(Y/N)?");
//	scanf(" %c", &sport);
//	printf("Do you have a good habit of diet(Y/N)?");
//	scanf(" %c", &diet);
//	if (ch == 'M')
//	{
//		if (sport == 'Y')
//		{
//			if (diet == 'Y')
//			{
//				sum = (f + m) * 0.54* 1.02 * 1.015;
//				printf("Your future height will be %.0f(cm)\n", sum);
//			}
//			else
//			{
//				sum = (f + m) * 0.54 * 1.02;
//				printf("Your future height will be %.0f(cm)\n", sum);
//			}
//		}
//		else
//		{
//			if (diet == 'Y')
//			{
//				sum = (f + m) * 0.54 * 1.015;
//				printf("Your future height will be %.0f(cm)\n", sum);
//			}
//			else
//			{
//				sum = (f + m) * 0.54 ;
//				printf("Your future height will be %.0f(cm)\n", sum);
//			}
//		}
//	}
//	else 
//	{
//		if (sport == 'Y')
//		{
//			if (diet == 'Y')
//			{
//				sum = (f * 0.923 + m) / 2 * 1.02 * 1.015;
//				printf("Your future height will be %.0f(cm)\n", sum);
//			}
//			else
//			{
//				sum = (f *0.923+ m)/2 * 1.02;
//				printf("Your future height will be %.0f(cm)\n", sum);
//			}
//		}
//		else
//		{
//			if (diet == 'Y')
//			{
//				sum = (f * 0.923 + m) / 2 * 1.015;
//				printf("Your future height will be %.0f(cm)\n", sum);
//			}
//			else
//			{
//				sum = (f * 0.923 + m) / 2 ;
//				printf("Your future height will be %.0f(cm)\n", sum);
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	double n;
//	printf("���������õ�����\n");
//	scanf("%lf", &n);
//	if (n <= 50)
//	{
//		printf("Ӧ֧�����=%.2f\n", n * 0.53);
//	}
//	else
//	{
//		printf("Ӧ֧�����=%.2f\n",  n  * 0.58);
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	printf("Input an integer number:");
//	scanf("%d", &n);
//	if (n % 2 == 0)
//	{
//		printf("It is an even number");
//	}
//	else
//	{
//		printf("It is an odd number");
//	}
//	return 0;
//}
//int main()
//{
//	int n, m;
//	printf("input the value of x and y:");
//	scanf("%d %d", &n, &m);
//	if (n > m)
//	{
//		printf("The max of %d and %d  is %d\n",n,m,n);
//	}
//	else 
//	{
//		printf("The max of %d and %d  is %d\n", n, m, m);
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	printf("���������:");
//	scanf("%d", &n);
//	if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
//	{
//		printf("31,29,31,30,31,30");
//		printf("31,31,30,31,30,31");
//	}
//	else
//	{
//		printf("31,28,31,30,31,30");
//		printf("31,31,30,31,30,31");
//	}
//	return 0;
//}