#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//洛谷P1038


int c[105], U[105];//c为状态值，U为阈值
int w[105][105];//图的边，存储权值
int outdeg[105];//记录对应下标的出度
int indeg[105];//记录对应下标的入度
vector<int> g[105];//存储每个点对应的点

//int main() {
//	int n,p;
//	cin >> n >> p;
//	for (int i = 1; i <= n; i++) {
//		cin >> c[i] >> U[i];
//		if (c[i] == 0)c[i] = -U[i];//如果不是输入层的神经节点（输入层c[i]不为0），那么我们将其标记成未激活的（c[i]<0表示未激活，>0表示激活）
//	}
//	for (int i = 0; i < p; i++) {
//		int a, b, weight;
//		cin >> a >> b >> weight;
//		w[a][b] = weight;
//		indeg[b]++;
//		outdeg[a]++;
//		g[a].push_back(b);
//	}
//	queue<int>q;
//	for (int i = 1; i <= n; i++) {
//		if (indeg[i])continue;
//		q.push(i);//将输入层的神经节点加入,输出层的入度一定为0
//	}
//	while (!q.empty()) {
//		int ind = q.front();
//		q.pop();
//		if (c[ind] > 0) {//说明当前节点已被激活
//			for (int i = 0; i < g[ind].size(); i++) {
//				int to = g[ind][i];
//				c[to] += w[ind][to] * c[ind];
//			}
//		}
//		for (int i = 0; i < g[ind].size(); i++) {
//			int to = g[ind][i];
//			indeg[to]--;
//			if (indeg[to] == 0) {
//				q.push(to);
//			}
//		}
//	}
//	int flag = 0;
//	for (int i = 1; i <= n; i++) {
//		if (outdeg[i])continue;//输出层的神经节点出度为0
//		if (c[i] <= 0)continue;//如果c[i]未激活
//		cout << i << " " << c[i]<< endl;
//		flag = 1;
//	}
//	if (!flag)cout << "NULL" << endl;
//	return 0;
//}