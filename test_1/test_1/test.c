#define  _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
//int main()
//{
//	char a;
//		printf("%c",a);
//}
Max(int x, int y)
{
	if (x > y)
	     return x;
	else
		 return y;

}
int main()
{
	int a = 10;
	int b = 20;
	int max = Max(a,b);
	printf("%d\n", max);
	return 0;
 }
//int main()
//{
//    scanf("%d", &x);
//    if (2 <= x <= 100)
//    {
//        printf("I am %d years old.", x);
//    }
//    else 
//    {
//        printf("你不可能这么大");
//    }
//    return 0;
//}
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	printf("I am %d years old.", x);
//	return 0;
//}
//#include  <stdio.h>
//int a;
//int b;
//int main()
//{
//	if (a <= b)
//	
//		printf("yes\n" );
//	
//	 else
//	
//		printf("no\n");
//	
//
//	return 0;
//}
