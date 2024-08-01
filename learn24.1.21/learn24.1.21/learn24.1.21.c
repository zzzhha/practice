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

//int main()//斐波那契数列while循环版
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
//	if (*str != '/0')//如果地址中存储的这个数不为‘/0’
//	{
//		return 1 + my_strlen(str + 1);//那么返回1+这个函数（函数递归）
//	}
//	else
//		return 0;//如果是‘/0’则返回0
	//这是函数递归的方法，如果数组中还有数，则进行1+函数再次运行
	// 直到函数递归（传递和归回）中传递结束，我们会得到1+1+...+0
	// +0是因为不符合if条件转入else语句中返回0
	// 此数组‘bit’总共运行4次，为1+1+1+0，得出3，故在调用表达式中会返回3。
	// 虽然递归中传递的最后一次是在return0中结束，
	// 但是递归中回归的结束是在return1+my_strlen中结束
	// 总的来说，最后一次return结束是return1+1+1+my_strlen（此处my-strlen为0）
	// 所以返回值为3而不是递归中传递的最后一次中的0
//int my_strlen(char* str)
//int count = 0;//创造临时变量的方法
//while (str != '/0')//求字符串长度
//{
//	count++;
//	str++;//str此处是arr的地址，数组地址是连续在一起的
//	//因为char长度为1，所以数组中每个数的地址相隔1个字节
//	//str++是使地址+1即为下一个数的地址，
//	// 若是（*arr）++则是使地址记录的这个“数”加一。
//}
	//return count;
//}

//int main()
//{
//	char arr[] = 'bit';
//	int len = my_strlen(arr);
//		printf("len=%d",len);//arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址。
//	return 0;
//}