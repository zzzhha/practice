#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

unsigned long Fact(unsigned int n)
{
	unsigned int i = 1;
	unsigned int sum = 1;
	for (; i <= n; i++)
	{
		sum *= i;
	}
	return sum;
}
int main()
{
	int m, k;
	printf("Input m,k (m>=k>0):");
	scanf("%d,%d", &m, &k);
	while (m <= 0 || m <= 0 || m < k)
	{
		printf("Input m,k (m>=k>0):");
		scanf("%d,%d", &m,&k);
	}
	unsigned long c = Fact(m) / (Fact(k) * Fact(m - k));
	printf("The combination is %ld\n", c);
	return 0;
}
//int main()
//{
//	int a = 0x11223344;
//	int* pa = &a;
//	short* pb = &a;
//	char* pc = &a;
//	*pb = 0;
//	*(pb + 1) = 0;
//	//他们都能很好的存放a的地址
//	//但是在用*改变a的值的时候，a存放了4个字节
//	// char* 只能改变一个字节内的内容（char类型内存为一个字节），short*同理
//	//上面两个都不能完全改变a中的内容，而int*可以。
//	return 0;
//}
//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c));//1
//	printf("%u\n", sizeof(+c));//4发生了整形提升，整形提升后在内存中为整形类型，占4个字节
//	printf("%u\n", sizeof(!c));//1发生逻辑运算，而不是算术运算，算术运算时会有整形提升，逻辑运算不会发生整形提升
//	return 0;
//}
//int main()
//{
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//	if (a == 0xb6)//不打印，发生整形提升后进行原反补互换之后值发生变化
//		printf("a");
//	if (b == 0xb600)//同上
//		printf("b");
//	if (c == 0xb6000000)//打印，int为整形，0xb6000000也为整形，直接打印
//		printf("c");
//	return 0;
//}
//struct stu 
//{
//	//成员变量
//	char name[20];
//	int age;
//	char id[20];
//};
//int main()
//{
//	struct stu s1 = {"张三",18,"2023212561"};
//	struct stu* ps = &s1;
//	printf("%s\n", ps->name);//全等于下面的（*ps）.name
//	//"->"用法：结构体指针->成员名
//	//printf("%s\n", (*ps).name);
//	//printf("%d\n", (*ps).age);
//	//printf("%s\n", (*ps).id);
//	//printf("%s\n",s1.name);
//	//printf("%d\n", s1.age);
//	//printf("%s\n", s1.id);
//	//“.”作用于：结构体变量.成员名（s1）
//	return 0;
//}
//int main()
//{
//	int a = 5;
//	int b = 10;
//	printf("%d\n", sizeof(a=a + b));
//	printf("%d", a);
//	return 0;
//}