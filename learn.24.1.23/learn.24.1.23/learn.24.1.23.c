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
//	//���Ƕ��ܺܺõĴ��a�ĵ�ַ
//	//��������*�ı�a��ֵ��ʱ��a�����4���ֽ�
//	// char* ֻ�ܸı�һ���ֽ��ڵ����ݣ�char�����ڴ�Ϊһ���ֽڣ���short*ͬ��
//	//����������������ȫ�ı�a�е����ݣ���int*���ԡ�
//	return 0;
//}
//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c));//1
//	printf("%u\n", sizeof(+c));//4�����������������������������ڴ���Ϊ�������ͣ�ռ4���ֽ�
//	printf("%u\n", sizeof(!c));//1�����߼����㣬�������������㣬��������ʱ���������������߼����㲻�ᷢ����������
//	return 0;
//}
//int main()
//{
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//	if (a == 0xb6)//����ӡ�������������������ԭ��������֮��ֵ�����仯
//		printf("a");
//	if (b == 0xb600)//ͬ��
//		printf("b");
//	if (c == 0xb6000000)//��ӡ��intΪ���Σ�0xb6000000ҲΪ���Σ�ֱ�Ӵ�ӡ
//		printf("c");
//	return 0;
//}
//struct stu 
//{
//	//��Ա����
//	char name[20];
//	int age;
//	char id[20];
//};
//int main()
//{
//	struct stu s1 = {"����",18,"2023212561"};
//	struct stu* ps = &s1;
//	printf("%s\n", ps->name);//ȫ��������ģ�*ps��.name
//	//"->"�÷����ṹ��ָ��->��Ա��
//	//printf("%s\n", (*ps).name);
//	//printf("%d\n", (*ps).age);
//	//printf("%s\n", (*ps).id);
//	//printf("%s\n",s1.name);
//	//printf("%d\n", s1.age);
//	//printf("%s\n", s1.id);
//	//��.�������ڣ��ṹ�����.��Ա����s1��
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