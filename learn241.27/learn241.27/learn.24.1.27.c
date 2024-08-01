#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	const int num = 10;
	
	//const 放在指针变量*的左边时，修饰的是*p，不能通过p来改变*p（num）的值
	// {例子
	// const int *p=&num;
	// *p=20//error
	// p=&n;//可以
	// }
	//const 放在指针变量*的右边时，修饰的是p本身，p不能被改变。
	//{例子
	//  int* const p = &num;
	// n=100;
	// p=&n;//error
	// *p=20//可以
	// }
	printf("%d", num);
	return 0;
}