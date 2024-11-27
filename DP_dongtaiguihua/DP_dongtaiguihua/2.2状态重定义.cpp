#include<iostream>
#include<algorithm>

using namespace std;

//海贼OJ 50 

//dp(i,j) 前i个鸡蛋测j层楼的最多最少次数
//dp(i,j)=min{max(dp[i][j-k],dp[i-1][k-1])}+1
// k代表当前楼层 k属于[1,j]
// dp[i][j-k]代表蛋没碎，那么我们就需要再测上方的j-k层
// dp[i-1][k-1]代表蛋碎了，说明我们要测下方的k-1层
// 他说的点最背的情况，就是这两个数据要取一个最大值
// 而最少的操作次数就是外层的min
// 外层的min代表在所有的k中选择一个max最小的值

int egg[32 + 5][100000 + 5];

//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) egg[1][i] = i;//只有一个鸡蛋时，不管有多少层楼，都是测楼层次数
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			egg[i][j] = j;//最差情况
//			for (int k = 1; k <= j; k++) {
//				egg[i][j] = min(egg[i][j], max(egg[i - 1][k - 1], egg[i][j - k]) + 1);
//			}
//		}
//	}
//	cout << egg[n][m];
//	return 0;
//}


//i个鸡蛋，测k次，最多能测多少层楼
//dp(i,k)=dp[i][k-1]+dp[i-1][k-1]+1
//dp[i-1][k-1]鸡蛋碎了，我们现在只有i-1个鸡蛋，还能测k-1次
//dp[i][k-1]鸡蛋没碎，我们现在只有i个鸡蛋，还能测k-1次
//+1是我加上我们当前的楼层

long long egg_plus[32 + 5][1000 + 5];//这里的1000只是预测的数据

//int main() {
//	long long n, m;
//	cin >> n >> m;
//	if (n == 1) {
//		cout << m << endl;
//		return 0;//特判只有1个鸡蛋的时候
//	}
//	for (int i = 1; i <= 1000; i++) egg_plus[1][i] = i;//只有一个鸡蛋，能测楼层就是测试次数
//	for (int i = 2; i <= n; i++) {//鸡蛋数
//		for (int j = 1; j <= 1000; j++) {//扔的次数
//			egg_plus[i][j] = egg_plus[i][j - 1] + egg_plus[i - 1][j - 1] + 1;
//			if (egg_plus[i][j] > m) break;
//		}
//	}
//	int k = 1;
//	while (egg_plus[n][k] < m) k += 1;
//	cout << k << endl;
//	return 0;
//}

