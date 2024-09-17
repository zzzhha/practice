#include<iostream>

using namespace std;

//洛谷1135 难！



int to[205];

//记录点a到达点i的最短距离（已知的最短距离）
int dis[205] = { 0 };

//第一个参数代表当前到达a用了几步
//第二个参数代表当前在哪个点
//第三个点代表总结点数量
void dfs(int k, int a,int n) {
	if (dis[a] <= k) return;//如果现在的最短距离大于已知的最短距离，说明他不是最优解，所以直接返回
	dis[a] = k;
	if (a + to[a] <= n)dfs(k + 1, a + to[a], n);
	if (a - to[a] >= 1)dfs(k + 1, a - to[a], n);
	return;
}

//int main() {
//	int n, a, b;//n是多少层楼,a是第几层，b是目标层数
//	cin >> n >> a >> b;
//	for (int i = 1; i <= n; i++) {
//		cin >> to[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		dis[i] = n + 1;//已知电梯的最大值就为n，所以此时初始化最大值就可以初始化为n+1
//	}
//	dfs(0,a,n);//计算完毕后可以得到a点到达所有点的最短距离
//	cout << (dis[b] == n + 1 ? -1 : dis[b]);
//	return 0;
//}