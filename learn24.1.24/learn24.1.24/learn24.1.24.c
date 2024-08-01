#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
 
double cifang(int n, int k)
{
	if (k < 0)
		return (1.0/  cifang(n,-k));
	else if (k == 0)
		return 1;
	else
	{
		return n * cifang(n, k - 1);
	}
}

int main()
{
	int n,k;
	scanf("%d%d", &n, &k);
	double len=cifang(n, k);
	printf("%lf", len);
	return 0;
}
//int zonghe(unsigned int a)
//{
//	if (a > 9)
//	{
//		return a % 10 + zonghe(a / 10);
//	}
//	else
//		return a;
//}
//int main()
//{
//	unsigned int a = 1729;
//	int sum=zonghe(a);
//	printf("%d", sum);
//	return 0;
//}
//void reverse_string(char* str,int sz)
//{
//	int tmp;
//	int left = 0;
//	int right = sz - 2;//right=strlen(str)-1
//	while (left < right)
//	{
//		tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		left++;
//		right--;
//	}
//}
//void reverse_string(char arr[])
//{
//
//}
//
//int main()
//{
//	char str[] = "abcdef";
//	int sz = sizeof(str) / sizeof(str[0]);
//	reverse_string(str,sz);
//	printf("%s\n", str);
//}
//int main()
//{
//	int n,i=1;
//	int sum = 1;
//	scanf("%d",&n);
//	for (; i <= n; i++)
//	{
//		sum *= i;
//	}
//	printf("%d",sum);
//	return 0;
//}
//int jiecheng(int x)
//{
//	if (x != 0)
//	{
//		return x * jiecheng(x - 1);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int y=jiecheng(n);
//	printf("%d", y);
//	return 0;
//}
//int meiyiwei(int a)
//{
//	if (a > 9)
//	{
//		meiyiwei( a /10);
//		
//	}
//	printf("%d  ", a % 10);
//}
//int main()
//{
//	int a = 1314;
//	 meiyiwei(a);
//	
//	return 0;
//}
//void chengfabiao(int a)
//{
//	int i = 1;
//	for (; i <= a; i++)
//	{
//
//		int j;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ",i,j, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	chengfabiao(a);
//	printf("");
//	return 0;
//}
//void print(int *p,int sz)
//{
//	int i = 0;
//	for (; i < sz; i++)
//	{
//		printf("%d", *(p+i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	
//	a = a ^ b;
//	b = a^b;
//	a = a ^ b;
//	printf("a=%db=%d", a, b);
//	return 0;
//}
//int main()
//{
//	int a, b, c;
//	scanf("%d",&a);
//	b = 30;
//	c = 31;
//	printf("奇数位");
//	for (; b >=0; b -= 2)
//	{
//		printf("%d ", ((a >> b) & 1));
//	}
//	printf("\n");
//	printf("偶数位");
//	for (; c >=1; c-=2)
//	{
//		printf("%d ", ((a >> c) & 1));
//	}
//	return 0;
//}
//int main()
//{
//	int a, b,c;
//	int count = 0;
//	scanf("%d%d", &a, &b);
//	c = a ^ b;
//	while (c)
//	{
//		count++;
//		c = c & (c - 1);
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int count = 0;
//	int n;
//	scanf("%d", &n);
//	while (n)
//	{//设n=13，则n为1101（二进制），n-1为1100
//		//按位与得1100，此时n-1为1011，
//		//再次按位与得1000，n-1为0111，
//		//按位与得0，
//		//此循环每进行一次都会消掉所求数（n）二进制里的一个1
//		//循环能进行几次说明所求数二进制就会有几个1.
//		count++;
//		n = n & (n - 1);
//	}
//	return 0;
//}
//int main()
//{
//	int i, x,count = 0;
//	scanf("%d", &x);
//	for(i=1;i<=32;i++)
//	{
//		if (1 ==( (x >> i) & 1))
//			count++;
//	}
//	printf("%d", count);
//}
//void exchange(int arr1[], int arr2[], int sz)
//{
//	int i = 0;
//	for (; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//int main()
//{
//	int arr1[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i,sz;
//	sz = sizeof(arr1) / sizeof(arr1[0]);
//	exchange(arr1, arr2, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}
//void chushihua(int arr[], int sz)
//{
//	int x = 0;
//	for (; x < sz; x++)
//	{
//		arr[x] = 0;
//	}
//}
//void reverse(int arr[], int sz)
//{
//	int start=0;
//	int end = sz - 1;
//	int i;
//	/*int end=0;
//	for (; end < sz-1; end++)
//	{
//	}*/
//	for (i = 0; i < sz / 2; i++)
//	{
//		int n = arr[start];
//		arr[start] = arr[end];
//		arr[end] = n;
//		start++;
//		end--;
//	}
//	//或写成：
//	//while(start<right)
//	//{
//	//    int n = arr[start];
//	//    arr[start] = arr[end];
//	//    arr[end] = n;
//	//    start++;
//	//    end--;
//	// }
//}
//int main() 
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i, sz;
//	sz = sizeof(arr) / sizeof(arr[0]);
//	/*chushihua(arr, sz);*/
//		for (i = 0; i < sz; i++)
//		{
//			printf("%d ",arr[i]);
//		}
//		printf("\n");
//	reverse(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//void buttle_sort(int arr[],int sz)
//{
//	int i = 0;
//	for (; i < sz-1; i++)
//	{
//		int flag = 1;
//		int j;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int x;
//				x = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = x;
//				flag = 0;
//			}
//		}
//	if (flag == 1)
//		break;
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,4,5,3,8,7,9,0,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	buttle_sort(arr, sz);
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//    }
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,(3,4),5 };
//	printf("%d\n",sizeof(arr)/arr[0]);
//	//补充：数组在“”初始化时，会自动带上/0，内存计算时会算上，而用{}初始化时不会带上/0，内存计算就不会计算/0
//	return 0;
//}