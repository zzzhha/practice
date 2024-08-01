#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct s
{
	int a;
	char c;
	char arr[20];
	double d;
};
struct t
{
	char ch[10];
	struct s b;
	char* pc;
};
int main()
{
	char arr[] = "hello,world";
	struct t T = { "hello bit",{114514,'g',"weixinpai",5.1},arr};
	printf("%s\n", T.ch);
	printf("%d\n", T.b.a);
	printf("%c\n", T.b.c);
	printf("%s\n", T.b.arr);
	printf("%lf\n", T.b.d);
	printf("%s\n", T.pc);
	return 0;
}