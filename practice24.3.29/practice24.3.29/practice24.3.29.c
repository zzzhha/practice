#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char arr[1005];
	fgets(arr, 1000, stdin);
	int i = 1;
	int count = 1;
	for (i = 1; i < strlen(arr); i++)
	{
		if (arr[i] != arr[i - 1])
		{
			printf("%d%c", count, arr[i-1]);
			count = 0;
		}
		count++;
	}
	return 0;
}
//int main()
//{
//	char arr[1005];
//	const char arr1[] = {'0','1','2','3','4','5','6','7','8','9'};
//	int arr2[15] = { 0 };
//	int i = 0;
//	char ch;
//	while ((ch = getchar())!= '\n')
//	{
//		arr[i] = ch;
//		i++;
//		arr2[ch - '0']++;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if(arr2[i]!=0)
//		{
//			printf("%c%d", arr1[i], arr2[i]);
//		}
//	}
//	return 0;
//}

//void reverse(const char* ch,int sz/*���ӡ���ַ�����*/, int n/*�ַ��ܳ���*/)
//{
//	int i = 0;
//	for (; i<sz; i++)
//	{
//		printf("%c", ch[n-i-1]);
//	}
//	printf("\n");
//}
//int main()
//{
//	char arr[10005];
//	fgets(arr, 10000, stdin);
//	int i = 0;
//	int sum = 0;
//	for (; i <= strlen(arr); i++)
//	{
//		if ( isalpha(arr[i]))
//		{
//			sum++;
//		}
//		else
//		{
//			reverse(arr, sum/*���ӡ���ַ�����*/,i/*�ַ��ܳ���*/);
//			sum = 0;
//		}
//	}
//	return 0;
//}
//void reverse(const char* ch,int sz)//һ��ʧ�ܵĵ����ַ�������
//{
//	char n ;//ȥ��\n
//	int m = sz-1;//�� �±�
//
//	for (; m >= 0; m--)
//	{
//		if (ch[m] == '\n')
//		{
//			continue;
//		}
//		printf("%c", ch[m]);
//	}
//	printf("\n");
//}
//int main()
//{
//	char arr[105];
//	fgets(arr, 100, stdin);
//	char* ch = strtok(arr," ");//��arr�ָ��ch����
//	while (ch)//���ch�����ڿ������
//	{
//		int sz = strlen(ch);//����ch����
//		reverse(ch,sz);//��ת��ӡ
//		ch = strtok(NULL," ");//��ת����һ���ָ��
//	}
//	return 0;
//}
//int main()
//{
//	char arr[20005];
//	gets(arr);
//	int i = 0;
//	int sum = 0, max = -100, maxb, minb, min = 1000000;
//	for (; i < strlen(arr) ; i++)
//	{
//		if (arr[i] == ' ' || arr[i] == ',' || arr[i] == '.') // ������ֱ����źͿո񣬴����ʽ���
//		{
//
//			if (max < sum)//������ʳ���ͻ��Ŀǰ���ֵ������
//			{
//				maxb = i; // ������ʵĽ�������£�i���ǽ�����
//				max = sum;//������ʵĳ��ȸ���
//			}
//			if (min > sum)//������ʳ��ȵ���Ŀǰ���ֵ���̳���
//			{
//				minb = i;//������̵��ʽ�����
//				min = sum;//������̳���
//			}
//			sum = 0;//sum��գ��Ա��´β���
//		}
//		else
//		{
//			sum++;//�������ĸ�����ȼ�һ
//		}
//	}
//	for (i = maxb - max/*�ӿ�ʼλ�ÿ�ʼ���*/; i < maxb/*������λ�ý���*/; i++)
//	{
//		putchar(arr[i]);
//	}
//	printf("\n");
//	for (i = minb - min; i < minb; i++)//��̵���ͬ��
//	{
//		putchar(arr[i]);
//	}
//	return 0;
//}