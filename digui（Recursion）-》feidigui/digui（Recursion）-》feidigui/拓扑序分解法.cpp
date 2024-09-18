#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<set>
using namespace std;

//拓扑排序
#define MAX_N 10

int indeg[MAX_N + 5] = { 0 };//入度数组
vector<vector<int>>g(MAX_N+5);//邻接矩阵
int ans[MAX_N + 5], cnt = 0;//ans是顶点数组

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;//统计边的两点
		indeg[b] += 1;//入度数组++
		g[a].push_back(b);//在邻接矩阵存储弧头点
	}
	set<int> q;//保存读入为0的点
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0)q.insert(i);
	}
	while (q.size() > 0) {
		int now = *q.begin();//相当于队列top()
		ans[cnt++] = now;//记录第一个出队列的数
		q.erase(q.begin());//相当于队列pop()
		//-------------
		for (int i = 0, I = g[now].size(); i < I; i++) {
			int t = g[now][i];//读取now点相连接的点
			indeg[t] -= 1;//将此点的出度的点减1
			if (indeg[t] == 0) {//如果此点入度为0
				q.insert(t);//保存入度为0的点
			}
		}
		//-------------

	}
	for (int i = 0; i < cnt; i++) {
		if (i)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}