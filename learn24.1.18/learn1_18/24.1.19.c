#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>

////��������
//int Add(int x, int y);//�˴�xy��д�ɲ�д,Ҫ�ӡ�����һ���ӳ���˴����ӡ�����
////�����ĺ������ӳ���û��д���������������д����������������
////��������Ҫ�������д˺����ٽ���ʹ�á�
////��Ϊһ������Ǵ������¶�ȡ�ģ��ӳ���������������ᵼ���޷���ȡ�Ӻ���
////�����ֱ����ʿ������Ϸ������д˺���
//int main()
//{
//	int a = 10;
//	int b = 10;
//	int sum = 0;
//	sum = Add(a, b);//��������
//	printf("%d\n", sum);
//		return 0;
//}
//int Add(int x  , int y)//��������
// ��������ôд���롣
// �����Ķ���������������ô�õġ�
// һ����ͷ�ļ�������������Դ�ļ���д�����Ķ���
// ����Ҫ������Դ�ļ���ʹ�õ��˺������ڿ�ͷ����
// �����ģ���ͷ����#include"add.h"(��ν���⡱)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	printf("%d",printf("%d",printf("%d",43)));
//	//����Ƕ�ף���һ�������ķ���ֵ��Ϊ��һ�������Ĳ���
//	return 0;
//}
//int add(int a, int b)//ÿʹ��һ�κ������¼�˺���ʹ�ô�����һ
//{
//	int c;
//	c = a + b;
//	return c;
//	
//}
//void increase(int* a)
//{
//	
//	(*a )++;
//}
//int main()
//{
//	int num=0,a=1,b=2,c=0;
//	c=add(a, b );
//	increase(&num);
//	printf("%d\n%d", c,num);
//	return 0;
//}
//int binary_search(int arr[], int k,int sz)//���ֲ��Һ���
////int sz = sizeof(arr) / sizeof(arr[0]);
////�ⲽ���󣬲����ں����������鳤��
////�˴�������������������arrΪarr�е�һ�����ĵ�ַ
////��Ϊ�ǵ�ַ�����Ǻ������ӳ�����д�ġ�int arr[]��Ϊһ����ַ
////����ָ�롣ָ��Ĵ�Сֻ��ϵͳλ����32or64��������4����8��
////���ں������ӳ����ڲ������鳤�ȣ������м��������ǲ��е�Ҫ����������ȥ��
//{
//	int left = 0, right = sz - 1;
//	while (left <= right)//�˴���С�ڵ��ڣ���ȱ�ٵ��ڿ��ܻ�©��һ����������±����.
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k=7;
//	int ret = binary_search(arr, k,sz);
//	if (ret == -1)
//	{
//		printf("�Ҳ���ָ��������\n");
//	}
//	else
//		printf("�ҵ����±���%d",ret);
//	return 0;
//}
// 
//int run(int x)//��������
//{
//	if ((x % 4 == 0 && x % 100 != 0) ||( x % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int a,b=0;
//	for (a = 1000; a <= 2000; a++)
//	{
//	
//		if (run(a) == 1)
//		{  
//			b++;
//			printf("%d  ", a);
//		}
//	
//	}
//	printf("\n%d", b);
//	return 0;
//}
//int is_prime(int n)//����100-200�ڵ�����
//{
//	int z = 2;
//	for(;z<=sqrt(n);z++)
//	{
//		if (n % z == 0 )//�ж��ܲ��ܱ�����������
//		{
//			return 0;//�ܱ�����ֱ�ӵ��ñ��ʽΪ0
//		}
//	}
//	return 1;//û��������������ñ��ʽΪ1
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//int is_prime(int n)
//{
//	int z=1;
//	while(1)
//	{
//		z++;
//		if (n % z == 0 && n / z != 1)//�ж��ܲ��ܱ�����������
//		{
//			break;
//		}
//		else if (n % z == 0 && n / z == 1)//�ж��Ƿ�Ϊ����
//			return 1;
//	
//	}
//	return 0;
//}
//int main()//
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d\n", i);
//	}
//	return 0;
//}
//void zhishu(int x)
//{
//	int i,n=0;
//	for (i = 1; i <= x; i++)
//	{
//		if (x % i == 0 )
//		{
//			n++;	//ͳ���ܱ�����������������2���������������ڶ���Ϊ����
//		}	
//	}
//	 if (n == 2||x==1)
//		printf("������");
//}
//
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	zhishu(a);
//	return 0;
//}

//void exchance(int* x, int* y)//�ú���������������
////int*x��int*yȡ������������������������ַ����*x��*y��������
////��void����Ϊ�˺����޷���ֵ��viodΪ�޷���ֵ���͡�
////���з���ֵ���������е��ñ��ʽ����Ϊ��������ʹ�õ���������ĵط��ͽе��ñ��ʽ��
////�����ģ��������е��ñ��ʽ�ͻᱻ���践��ֵ��return x��xֵ��
//{
//	int z;
//	z = *x;
//	*x = *y;
//	*y = z;//��������ֵ
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d",&a,&b);
//	printf("a=%db=%d\n", a, b);
//	exchance(&a, &b);//�ı�ab��ֵ����ȡ��ַ���õ�ab�ĵ�ַ����������exchange�����仯
//	printf("a=%db=%d\n", a, b);//��Ϊ��ַ�д�ŵ�ֵ���ı䣨��ַδ�䣬��ַ�д�ŵ�ֵ�ı䣩��abֵ������
//	return 0;
//}

//int Compare(int x, int y)
//{
//	if (x >= y)
//		return x;
//	else 
//		return y;
//}
//int main()
//{
//	int a, b,c;
//	scanf(" %d%d", &a, &b);
//	c= Compare(a, b);//��������Ľ����������˴�����ȡ��ַ������Ϊ�лع�ֵ��
// //�����ģ��ع�ֵ����Ϊ1.�����������ӳ��򣩣��������õı�����λ��2.�ͺ���ֵ�����ñ��ʽ��
// //�����ģ����ñ��ʽ��Ϊ�������õ�Compare����ʱCompare��a��b���Ѿ��Ƿ���ֵ�з��ص�����
// //�����ģ��ȣ�compare��a��b��Ϊһ�����������������c���ɴ��Ŀ�ġ�
//	printf("%d", c);
//	return 0;
//}