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

//void reverse(const char* ch,int sz/*需打印的字符个数*/, int n/*字符总长度*/)
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
//			reverse(arr, sum/*需打印的字符个数*/,i/*字符总长度*/);
//			sum = 0;
//		}
//	}
//	return 0;
//}
//void reverse(const char* ch,int sz)//一个失败的倒序字符串代码
//{
//	char n ;//去除\n
//	int m = sz-1;//右 下标
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
//	char* ch = strtok(arr," ");//将arr分割，用ch接受
//	while (ch)//如果ch不等于空则进行
//	{
//		int sz = strlen(ch);//计算ch长度
//		reverse(ch,sz);//翻转打印
//		ch = strtok(NULL," ");//跳转到下一个分割点
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
//		if (arr[i] == ' ' || arr[i] == ',' || arr[i] == '.') // 如果发现标点符号和空格，代表单词结束
//		{
//
//			if (max < sum)//如果单词长度突破目前发现的最长长度
//			{
//				maxb = i; // 把最长单词的结束点更新，i就是结束点
//				max = sum;//把最长单词的长度更新
//			}
//			if (min > sum)//如果单词长度低于目前发现的最短长度
//			{
//				minb = i;//更新最短单词结束点
//				min = sum;//更新最短长度
//			}
//			sum = 0;//sum清空，以便下次操作
//		}
//		else
//		{
//			sum++;//如果是字母，长度加一
//		}
//	}
//	for (i = maxb - max/*从开始位置开始输出*/; i < maxb/*到结束位置结束*/; i++)
//	{
//		putchar(arr[i]);
//	}
//	printf("\n");
//	for (i = minb - min; i < minb; i++)//最短单词同理
//	{
//		putchar(arr[i]);
//	}
//	return 0;
//}