#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>


//7.8，9,10不会

////6
//double payment(double amount, double interest, int periods)
//{
//	interest /= 1200;
//	periods *= 12;
//	amount = amount * interest /
//		(1 - pow(1 + interest, (double)(-periods)));
//	return floor(amount * 100 + 0.5) / 100;
//}
////5.
//#define A 10.45
//#define B 10.00
//#define C -1.0
//#define X 1.78816
//double
//wind_chill(double temp, double velocity)
//{
//	temp = 33 -temp;
//	return 33-((A + B * sqrt(velocity) + C * velocity) * temp) /
//		(A + B * sqrt(X) + C * X);
//}
////4
//char* month[] = { "January", "February", "March", "April", "May", "June",
//"July", "August", "September", "October", "November", "December"
//};
//char* day[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
//"Friday", "Saturday"
//};
//int main(int ac, char** av)
//{
//	struct tm tm;
//	if (ac != 4) {
//		fputs("Usage: day_of_seek month day year\n", stderr);
//		exit(EXIT_FAILURE);
//	}
//	/*
//	** Store the arguments in the struct tm variable.
//	*/
//	tm.tm_sec = 0;
//	tm.tm_min = 0;
//	tm.tm_hour = 12;
//	tm.tm_mday = atoi(av[2]);
//	tm.tm_mon = atoi(av[1]) – 1;
//	tm.tm_year = atoi(av[3])– 1900;
//	tm.tm_isdst = 0;
//	/*
//	** Normalize it, then print the answer.
//	*/
//	mktime(&tm);
//	printf("%s %d, %d is a %s\n", month[tm.tm_mon], tm.tm_mday,
//		tm.tm_year + 1900, day[tm.tm_wday]);
//	return 0;
//}
////3
//int main()
//{
//	struct tm* TM;
//	time_t a;
//	time(&a);
//	TM = localtime(&a);
//	printf("时针在%d上面，分针在%d上面", TM->tm_hour, TM->tm_min);
//	return 0;
//}
////2
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int a;
//	a = rand() % 6 + 1;
//	printf("%d", a);
//}
////1
//int shi(int n, int b)
//{
//	int sum = 0;
//	int m = 0;
//	while (n)
//	{
//		if ((n % 10) > b)
//		{
//			return 0;
//		}
//		sum += pow(b, m) * (n % 10);
//		m++;
//		n /= 10;
//	}
//	return sum;
//}
//int main()
//{
//	int p, q;
//	int B = 2;
//	scanf("%d%d", &p, &q);
//	for (; B <= 16; B++)
//	{
//		if (shi(p, B) ==shi(q, B)&&shi(p,B)!=0&& shi(q, B) != 0)
//		{
//			printf("%d",B);
//			return 0;
//		}
//	}
//	printf("0");
//	return 0;
//}