#include<iostream>
#include<cstdlib>
#include<algorithm>

//二分查找
using namespace std;


void output(int* arr, int n, int ind = -1) {
	int len = 0;
	for (int i = 0; i < n; i++) {
		len += printf("%4d", i);//打印下标
	}
	cout << endl;
	for (int i = 0; i < len; i++)
	{
		printf("-");
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (i == ind)printf("\033[1;32m");
		printf("%4d", arr[i]);
		if (i == ind) printf("\033[0m");
	}
	cout << endl;
	return;
}

int binary_search(int* arr, int n, int x) {
	int head= 0, tail = n - 1, mid;
	while (head <= tail) {
		mid = (head + tail) / 2;
		printf("[%d, %d], mid= %d, arr[%d]= %d\n",
			head, tail, mid, mid,arr[mid]);
		if (arr[mid] == x)return mid;
		if (arr[mid] < x)head = mid + 1;
		else tail = mid - 1;
	}
	return -1;
}

void test_binary_search(int n) {
	int* arr = new int[n];
	arr[0] = rand() & 10;
	for (int i = 1; i < n; i++)arr[i] = arr[i - 1] + rand() % 10;
	output(arr, n);
	int x;
	while (~scanf("%d", &x)) {
		if (x == -1)break;
		int ind = binary_search(arr, n, x);
		output(arr, n);
	}
	delete[]arr;
}
//二分算法
#define EXP 1e-4
#define min(a,b) ((a)<(b)?(a):(b))
double f(double x) {//税前工资扣除方法
	if (x>=0)        x -= min(x, 3000) * 0.03;
	if (x > 3000)    x -= (min(x, 12000) - 3000) * 0.1;
	if (x > 12000)   x -= (min(x, 25000) - 12000) * 0.2;
	if (x > 25000)   x -= (min(x, 35000) - 25000) * 0.25;
	if (x > 35000)   x -= (min(x, 55000) - 35000) * 0.3;
	if (x > 55000)   x -= (min(x, 80000) - 55000) * 0.35;
	if (x > 80000)   x -= (x- 80000) * 0.45;
	return x;//x为税后工资
}


double bineary_algorithm(double y) {//确定上下限，用mid去逼近y（税后工资），最后得到税后工资
	double head = 0, tail = 1000000, mid;
	while (tail-head>=EXP) {
		mid = (head + tail) / 2;
		printf("[%lf, %lf], mid= %lf, arr[%lf]= %lf\n",
			head, tail, mid, mid, f(mid));
		if (f(mid) < y)head = mid;
		else tail = mid;
	}
	return head;//返回head 是因为while循环中，tail和head在不断的逼近中已经无限接近了，相当于一个值，此值就是（约等）税后工资y
}



void test_binary_algorithm() {//由税后工资推测税前工资
	double y;
	cout << endl << "test binart algothm";
	while (~scanf("%lf", &y)) {
		if (y < 0)break;
		double x = bineary_algorithm(y);
		printf("f(%.2lf)=%.2lf\n", x, y);
	}
	return;
}

//int main()
//{
//	#define MAX_N 10
//	test_binary_search(MAX_N);
//	test_binary_algorithm();
//}