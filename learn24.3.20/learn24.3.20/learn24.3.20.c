#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define S 60
int main()
{
	int a;
	int b;
	int n;
	scanf("%d", &n);
	while (n > 0)
	{
		b = n / S;
		a = n % S;
		printf("%d hours %d minutes\n", b, a);
		printf("next time:");
		scanf("%d",&n);
	}
	return 0;
}