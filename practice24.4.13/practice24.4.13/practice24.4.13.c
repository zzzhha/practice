#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>


//#define PI 3.14
//typedef struct PC
//{
//	double length, angle;
//}PC;
//typedef struct CC
//{
//	double x, y;
//}CC;
//CC trans(PC a)
//{
//	CC cc;
//	cc.x = a.length * cos(a.angle);
//	cc.y = a.length * sin(a.angle);
//	return cc;
//}
//int main()
//{
//	PC pc;
//	scanf("%lf %lf", &pc.length, &pc.angle);
//	pc.angle *= PI / 180.0;
//	CC cc = trans(pc);
//	printf("%lf %lf\n", cc.x, cc.y);
//}
//#define RE(x,y) (1/((1/(x))+(1/(y)))/2)
//typedef unsigned int un;
//struct font
//{
//	un id   : 8;
//	un size : 7;
//	un align: 2;
//	un B    : 1;
//	un I    : 1;
//	un U    : 1;
//}font_a = {1,12,0,0,0,0};
//const char al[][7] = { "left","center","right" };
//const char st[][4] = { "off","on" };
//void funcf()
//{
//	un n;
//	printf("Enter font id(0-255):");
//	scanf("%u", &n);
//	font_a.id = n;
//}
//void funcs()
//{
//	un n;
//	printf("Enter font size(0-127):");
//	scanf("%u", &n);
//	font_a.size = n;
//}
//void funca()
//{
//	un n;
//	printf("Select alignment:\n 0)left   1)center 2)right\n");
//	scanf("%u", &n);
//	font_a.align = n;
//}
//void funcb()
//{
//	font_a.B = (font_a.B + 1) % 2;
//}
//void funci()
//{
//	font_a.I=(font_a.I + 1) % 2;
//}
//void funcu()
//{
//	font_a.U = (font_a.U + 1) % 2;
//}
//void print()
//{
//	puts("ID     SIZE     ALIGN    B       I       U");
//	printf("%-8u%-8u%-8s%-8s%-8s%-8s\n", font_a.id, font_a.size, al[font_a.align], st[font_a.B], st[font_a.I], st[font_a.U]);
//}
//void menu()
//{
//	printf("***************************************************************************************\n");
//	printf("********* f)change font*********** s)change size*********a)change alignment************\n");
//	printf("********* b)toggle bold*********** i)toggle italic*******u)toggle underline************\n");
//	printf("********* q)quit***********************************************************************\n");
//	printf("***************************************************************************************\n");
//}
//int main()
//{
//	char ch;
//	print();
//	menu();
//	while((scanf("%c",&ch) && ch != 'q'))
//	{
//		getchar();
//		switch (ch)
//		{
//		case 'f':
//			funcf();
//			break;
//		case 's':
//			funcs();
//			break;
//		case 'a':
//			funca();
//			break;
//		case 'b':
//			funcb();
//			break;
//		case 'i':
//			funci();
//			break;
//		case 'u':
//			funcu();
//			break;
//		case 'q':
//			break;
//		default:
//			break;
//		}
//		print();
//		menu();
//		while ((ch == getchar()) == '\n');
//	}
//	return 0;
//}
//int rotate_l(unsigned int x, int a)
//{
//	int arr[32] = { 0 };
//	int i = 0;
//	int j = 31;	
//	for (; i < a; i++)
//	{
//		arr[i] = ((x >> j) & 1);
//		j--;
//	}
//	for (i = 0; i < a; i++)
//	{
//		x = ((x << 1) | arr[i]);
//	}
//	return a;
//}
//int main()
//{
//	unsigned int x;
//	scanf("%d", &x);
//	rotate_l(x, 4);
//	return 0;
//}
//int funct(int a, int b)
//{
//	if ((a >>= b - 1) & 1)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	if (funct(a, b))
//	{
//		printf("1");
//	}
//	else
//	{
//		printf("0");
//	}
//	return 0;
//}
//int func(int a)
//{
//	int sz = sizeof(a) * 8;
//	int i = 0;
//	int count = 0;
//	for (; i < sz; i++)
//	{
//		if (a & 1)
//		{
//			count++;
//		}
//		a >>=1;
//	}
//	return count;
//}
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	printf("%d", func(x));
//	return 0;
//}
//void er(int num) {
//	if (num == 0) {
//		printf("0");
//		return;
//	}
//	int size = sizeof(num) * 8; // 计算 num 的位数  
//	for (int i = size - 1; i >= 0; i--) {
//		((num >> i) & 1) ? printf("1") : printf("0");
//	}
//}
//int get_int(char* a,int n)
//{
//	int i = n - 1;
//	int j = 0;
//	int sum=0;
//	for (i = n - 1; i >= 0; i--)
//	{
//		if (a[i] == '1')
//		{
//			sum += (1 << j);
//		}
//		j++;
//	}
//	return sum;
//}
//void yu(char* a, char* b)
//{
//	int s = strlen(a);
//	int z = strlen(b);
//	int x = get_int(a, s);
//	int y = get_int(b, z);
//	int c = x & y;
//	printf("%d\n", c);
//	printf("二进制:");
//	er(c);
//	printf("\n");
//}
//void huo(char* a, char* b)
//{
//	int s = strlen(a);
//	int z = strlen(b);
//	int x = get_int(a, s);
//	int y = get_int(b, z);
//	int c = x | y;
//	printf("%d\n", c);
//	printf("二进制:");
//	er(c);
//	printf("\n");
//}
//void yihuo(char* a, char* b)
//{
//	int s = strlen(a);
//	int z = strlen(b);
//	int x = get_int(a, s);
//	int y = get_int(b, z);
//	int c = x & y;
//	printf("%d\n", c);
//	printf("二进制:");
//	er(c);
//	printf("\n");
//}
//void fan(char* a, char* b)
//{
//	int s = strlen(a);
//	int z = strlen(b);
//	int x = get_int(a, s);
//	int y = get_int(b, z);
//	int c = ~x ;
//	int d = ~y;
//	printf("%d\n", c);
//	printf("%d\n", d);
//	printf("二进制:");
//	er(c);
//	printf("\n");
//	er(d);
//	printf("二进制:");
//	printf("\n");
//}
//int main()
//{
//	char a[35], b[35];
//	scanf("%s %s", a, b);
//	yu(a, b);
//	huo(a, b);
//	yihuo(a, b);
//	fan(a, b);
//	return 0;
//}

//int main()
//{
//	char arr[33] = { 0 };
//	int sum = 0;
//	int j = 0,i;
//	scanf("%s", arr);
//	int sz = strlen(arr);
//	for (i = sz-1; i >=0;i--)
//	{
//		if (arr[i] == '1')
//		{
//			sum += (1 << j);
//		}
//		j++;
//	}
//	/*for (i = sz-1; i >= 0; i--)
//	{
//		sum += (arr[i]-'0') * pow(2, j);
//		j++;
//	}*/
//	printf("%d", sum);
//	return 0; 
//}
//typedef double (*SIN)(double);
//void transform(double a[], double b[], int n, SIN fp)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		b[i] = fp(a[i]);
//		printf("%-5.2lf ", b[i]);
//		if ((i + 1) % 10 == 0)
//		{
//			printf("\n");
//		}
//	}
//}
////double test1(double a)
////{
////	return a +a;
////}
////double test2(double a)
////{
////	return a *a;
////}
//int main()
//{
//	double a[50], b[50];
//	int i = 0,j=0;
//	for (; i < 50; i++)
//	{
//		a[i] = i;
//	}
//	for (i = 0; i < 4; i++)
//	{
//		printf("The %d time:\n", i + 1);
//		transform(a, b, 50, sqrt);
//	}
	//transform(a, b, 50, test1);
	//for (j=0; j < 50; j++)
	//{
	//	printf("%.2lf ", b[j]);
	//}
	//puts("\n-----------------------");
	//transform(a, b, 50, test2);
	//for (j = 0; i < 50; j++)
	//{
	//	printf("%.2lf ", b[j]);
	//}
	//puts("\n-----------------------");
	//transform(a, b, 50, sin);
	//for (j = 0; i < 50; j++)
	//{
	//	printf("%.2lf ", b[j]);
	//}
	//puts("\n-----------------------");
	//transform(a, b, 50, cos);
	//for (j = 0; i < 50; j++)
	//{
	//	printf("%.2lf ", b[j]);
	//}
//	return 0;
//}
//int jia(int a, int b)
//{
//	return a + b;
//}
//int jian(int a, int b)
//{
//	return a - b;
//}
//int cheng(int a, int b)
//{
//	return a * b;
//}
//int chu(int a, int b)
//{
//	if(b!=0)
//	{
//		return a / b;
//	}
//	else
//	{
//		printf("b=0,无法相除");
//		return 0;
//	}
//}
//void menu()
//{
//	printf("*************************************\n");
//	printf("*******1. jia********1. jian*********\n");
//	printf("*******3.cheng*******4.chu **********\n");
//	printf("*******0. quit***********************\n");
//}
//int main()
//{
//	int(*calc[4])(int, int) = { jia,jian,cheng,chu };
//	int i;
//	do
//	{
//		menu();
//		printf("What calc do you want to choose:");
//		scanf("%d", &i);
//		if (!i)
//		{
//			break;
//		}
//		int a, b;
//		printf("please input the two int:");
//		scanf("%d%d", &a, &b);
//		int ret;
//		switch (i)
//		{
//		case 1:
//			ret=calc[0](a,b);
//			printf("result is %d\n", ret);
//			break;
//		case 2:
//			ret = calc[1](a, b);
//			printf("result is %d\n", ret);
//			break;
//		case 3:
//			ret = calc[2](a, b);
//			printf("result is %d\n", ret);
//			break;
//		case 4:
//			ret = calc[3](a, b);
//			printf("result is %d\n", ret);
//			break;
//		case 0:
//			break;
//		default:
//			printf("error");
//		}
//	} while (i);
//	return 0;
//}
//struct plane
//{
//	int sit;
//	int flag;
//	int book;
//	char firstname[20];
//	char lastname[20];
//}air[4][12] = { {{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1} },
//				{{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1} },
//				{{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1} },
//				{{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1} }
//               };
//int hb;
//int de[4] = { 0,0,0,0 };
//void menu2();
//void my_fflush()
//{
//	char ch;
//	while ((ch = getchar()) != '\n' && ch != EOF)
//	{
//		;
//	}
//}
//void afunc()
//{
//	int i = 0;
//	int sum = 0;
//	for (; i < 12; i++)
//	{
//		if (air[hb][i].flag)
//		{
//			sum++;
//		}
//	}
//	printf("There are %d empty seats. \n", sum);
//}
//void bfunc()
//{
//	puts("Empty seat list:");
//	int i = 0;
//	for (; i < 12; i++)
//	{
//		if (air[hb][i].flag == 1)
//		{
//			printf("%d ", air[hb][i].sit);
//		}
//	}
//	printf("\n");
//}
//int cfunccmp(const void* a, const void* b)
//{
//	struct plane* i = (struct plane*)a;
//	struct plane* j = (struct plane*)b;
//	if (i->flag && j->flag)//防止可选座位被乱排，返回小于零的数，qsort不改变位置
//	{
//		return i->sit - j -> sit;
//	}
//	if (!i->flag)//当前座位是否为空，为空则qsort不会改变位置
//	{
//		return 0;
//	}
//	if (!j->flag)//当前位置位i，下一个元素位置位j，当前元素有空位（flag=1）而下一个座位无空位（flag=0），
//		//则将无空位的前置，有空位的后置。
//	{
//		return 1;
//	}
//	int x = strcmp(i->firstname, j->firstname);
//	if (x > 0)//正常比较人名。
//	{
//		return 1;
//	}
//	else if (x == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return -1;
//	}
//}
//void cfunc()
//{
//	qsort(air[hb], 12, sizeof(struct plane), cfunccmp);
//	puts("Alphabetical list:");
//	int i = 0;
//	for (; i < 12; i++)
//	{
//		printf("%s %s\n", air[hb][i].firstname, air[hb][i].lastname);
//	}
//	menu2();
//}
//void dfunc()
//{
//	int n;
//	char a[20], b[20];
//	bfunc();
//	printf("Which seat you wanna assign?");
//	while (scanf("%d", &n) == 1)
//	{
//		int i = 0;
//		for (; i < 12; i++)
//		{
//			if (air[hb][i].sit == n)
//			{
//				n = i;
//				break;
//			}
//		}
//		if (air[hb][n].flag)
//		{
//			air[hb][n].flag = 0;
//			printf("What's your first name:");
//			scanf("%s", a);
//			strcpy(air[hb][n].firstname, a);
//			printf("What's your last name:");
//			scanf("%s", b);
//			strcpy(air[hb][n].lastname, b);
//			printf("Done\n");
//			break;
//		}
//		else
//		{
//			printf("The seat in not empty\n");
//		}
//	}
//	menu2();
//}
//void efunc()
//{
//	int n;
//	puts("Assign list:");
//	int i = 0;
//	for (; i < 12; i++)
//	{
//		if (!air[hb][i].flag)
//		{
//			printf("%d ", air[hb][i].sit);
//		}
//	}
//	printf("\n");
//	puts("Which assign you wanna delete?\n");
//	while (scanf("%d", &n) == 1)
//	{
//		if (!air[hb][n].flag )
//		{
//			air[hb][n].flag = 1;
//			puts("Done!");
//			break;
//		}
//		else
//		{
//			puts("This seat is empty");
//		}
//	}
//	menu2();
//}
//void menu2()
//{
//	printf("\n");
//	printf("*********************************************\n");
//	printf("To choose a function, enter its letter label:\n");
//	printf("a) Show number of empty seats                \n");
//	printf("b) Show list of empty                        \n");
//	printf("c) Show alphabetical list of seats           \n");
//	printf("d) Assign a customer to a sezt assignment    \n");
//	printf("e) Delete ae seat assignment                 \n");
//	printf("f) Determine allocation                      \n");
//	printf("g) Quit                                      \n");
//	printf("*********************************************\n");
//	int n=0;
//	my_fflush();
//	while (n != 'g'&&scanf("%c",&n))
//	{
//		n=tolower(n);
//		switch (n)
//		{
//		case 'a':
//			afunc();
//			break;
//		case 'b':
//			bfunc();
//			break;
//		case 'c':
//			cfunc();
//			break;
//		case 'd':
//			dfunc();
//			break;
//		case 'e':
//			efunc();
//			break;
//		case 'f':
//			n = 'g';
//			de[hb] = 1;
//			break;
//		case  'g':
//			break;
//		default:
//			printf("error,please try again:");
//			break;
//		}
//		my_fflush();
//	} 
//}
//void menu1()
//{
//	hb = 0;
//	printf("********************************************\n");
//	printf("***********1. 102**********2. 311***********\n");
//	printf("***********3. 444**********4. 519***********\n");
//	printf("***********0.quit  *************************\n");
//	printf("Choose you want to view the flight:");
//	while (scanf("%d", &hb) == 1)
//	{
//		if (de[hb] == 1)
//		{
//			puts("This flihgt has been determined,please choise another one");
//		}
//		else
//		{
//			if (hb == 0)
//			{
//				break;
//			}
//		}
//		switch (hb)
//		{
//		case 1:
//			printf("\nyou choose the 102 flight");
//			menu2();
//			break;
//		case 2:
//			printf("\nyou choose the 311 flight");
//			menu2();
//			break;
//		case 3:
//			printf("\nyou choose the 444 flight");
//			menu2();	
//			break;
//		case 4:
//			printf("\nyou choose the 519 flight");
//			menu2();			
//			break;
//		case 0:
//			break;
//		default:
//			printf("please input correct num:");
//		}
//	}
//}
//int main()
//{
//	menu1();
//	return 0;
//}
