#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
//int tuzi(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return tuzi(n-2)+tuzi(n-1);
//}
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	int y;
//	y = tuzi(x);
//	printf("%d", y);
//	return 0;
//}

//int main()//쳲���������whileѭ����
//{
//	int x;
//	scanf("%d",&x);
//	int z = 1, i = 1;
//	if (x <= 2)
//	{
//		printf("1");
//	}
//	else
//	{
//		while (x > 2)
//		{
//			x--;
//			i += z;
//			if (x == 2)
//			{
//				printf("%d", i);
//				break;
//			}
//			x--;
//			z += i;
//			if (x == 2)
//			{
//				printf("%d", z);
//				break;
//			}
//		}
//	}
//	return 0;
//}

//int jiecheng(int x)
//{
//
//	if (x!=0)
//	{
//		return x * jiecheng(x-1);
//	}
//	else
//	return 1;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int sum=jiecheng(n);
//	printf("%d", sum);
//	return 0;
//}

//int main()
//{
//	int i,n,sum=1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	printf("%d",sum);
//	return 0;
//}

//int my_strlen(char* str)
//{
//	if (*str != '/0')//�����ַ�д洢���������Ϊ��/0��
//	{
//		return 1 + my_strlen(str + 1);//��ô����1+��������������ݹ飩
//	}
//	else
//		return 0;//����ǡ�/0���򷵻�0
	//���Ǻ����ݹ�ķ�������������л������������1+�����ٴ�����
	// ֱ�������ݹ飨���ݺ͹�أ��д��ݽ��������ǻ�õ�1+1+...+0
	// +0����Ϊ������if����ת��else����з���0
	// �����顮bit���ܹ�����4�Σ�Ϊ1+1+1+0���ó�3�����ڵ��ñ��ʽ�л᷵��3��
	// ��Ȼ�ݹ��д��ݵ����һ������return0�н�����
	// ���ǵݹ��лع�Ľ�������return1+my_strlen�н���
	// �ܵ���˵�����һ��return������return1+1+1+my_strlen���˴�my-strlenΪ0��
	// ���Է���ֵΪ3�����ǵݹ��д��ݵ����һ���е�0
//int my_strlen(char* str)
//int count = 0;//������ʱ�����ķ���
//while (str != '/0')//���ַ�������
//{
//	count++;
//	str++;//str�˴���arr�ĵ�ַ�������ַ��������һ���
//	//��Ϊchar����Ϊ1������������ÿ�����ĵ�ַ���1���ֽ�
//	//str++��ʹ��ַ+1��Ϊ��һ�����ĵ�ַ��
//	// ���ǣ�*arr��++����ʹ��ַ��¼�������������һ��
//}
	//return count;
//}

//int main()
//{
//	char arr[] = 'bit';
//	int len = my_strlen(arr);
//		printf("len=%d",len);//arr�����飬���鴫�Σ�����ȥ�Ĳ����������飬���ǵ�һ��Ԫ�صĵ�ַ��
//	return 0;
//}