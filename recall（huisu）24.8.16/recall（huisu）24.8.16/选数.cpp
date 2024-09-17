#include<iostream>

using namespace std;


//洛谷P1036  难！！！
int g[25];
int count_sum=0;
long long all;//n<=20 k<n 最大值为c 20 10的排列，可能大于int范围，所以声明为longlong

bool isprime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
void dfs_x(int k, int ind, int n,int m,int sum) {
	if (k == m)//如果读取到了m个数，那么算当前sum是否为质数
	{
		if (isprime(sum))
			all++;
		return;
	}
	//此循环可参考组合型枚举
	for (int i = ind; i < n; i++) {//如果没读取到m个数，那么继续读取（k+1）,读取的数据应该是i
		dfs_x(k + 1, i + 1, n, m, sum+g[i]);
	}
}

//int main() {
//	int n, k;
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)cin >> g[i];
//	dfs_x(0, 0, n, k, 0);//第一个0表示当前层数为第0个数，第二个0表示我们在数组中应该读取的是那个数，n代表总数，k代表一共能读取多少个数（与第一个0相关联），最后一个0代表当前函数读取数组的数的总和
//	cout << all;
//	return 0;
//}