#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<list>
using namespace std;

//复习递归

//指数型枚举

int arr[10];

void print_one_result(int n) {
	for (int i = 0; i <= n; i++) {
		if (i)cout << " ";
		cout << arr[i];
	}
	cout << endl;
	return;
}

void exponential_enum(int i, int j ,int n) //此递归函数表示第i个位置最小放置的元素为j，最大不超过n。实现所有的指数型枚举
{
	if (j > n)//边界条件
		return;
	for (int k = j; k <= n; k++) 
	{
		arr[i] = k;
		print_one_result(i);//打印当前arr数组的所有元素
		exponential_enum(i + 1,k + 1, n);//进行下一次递归，i+1表示在那个位置，k+1表示当前最小数字为多少
	}
	return;
	
}


//组合型枚举
int arr1[10];
void print_on_result(int n) {
	for (int i = 0; i < n; i++) {
		if (i)cout << " ";
		cout << arr1[i];
	}
	cout << endl;
	return;
}
void combinatorial_enum(int i, int j, int n, int k)//此递归函数表示，第i个位置最小数据位j，并且总数不超过k个，最大不超过n 
{
	if (i == k)
	{
		print_on_result(k);
		return;
	}
	for (int q = j; q <= n; q++) {
		arr1[i] = q;
		combinatorial_enum(i + 1, q + 1, n, k);
	}

	return;
}

//排列型枚举
int arr2[10];
int vis[10] = { 0 };
void print_o_result(int n) {
	for (int i = 0; i < n; i++) {
		if (i)cout << " ";
		cout << arr2[i];
	}
	cout << endl;
}

void arrange_enum(int i,  int n)//此递归函数表明，且数量不能超过n,大小不超过n
{
	if (i == n) {
		print_o_result(n);
		return;
	}
	for (int x = 1; x <= n; x++) {
		if (vis[x])continue;
		arr2[i] = x;
		vis[x] = 1;
		arrange_enum(i + 1,n);
		vis[x] = 0;
	}
}
//


int main() {
	int n;
	cin >> n;
	//exponential_enum(0,1,n);
	int  m;
	//cin >> n >> m;
	//combinatorial_enum(0, 1, n, m);

	arrange_enum(0,  n);
	return 0;
}