#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	const int num = 10;
	
	//const ����ָ�����*�����ʱ�����ε���*p������ͨ��p���ı�*p��num����ֵ
	// {����
	// const int *p=&num;
	// *p=20//error
	// p=&n;//����
	// }
	//const ����ָ�����*���ұ�ʱ�����ε���p����p���ܱ��ı䡣
	//{����
	//  int* const p = &num;
	// n=100;
	// p=&n;//error
	// *p=20//����
	// }
	printf("%d", num);
	return 0;
}