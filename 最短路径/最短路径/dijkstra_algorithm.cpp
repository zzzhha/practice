#include<iostream>

using namespace std;

//基于贪心
// dijkstra算法：用来解决起点到其他n-1个点的最短距离
// 是单源最短路径算法，一次只能求一个起点到其他点的最短路径算法
// 时间复杂度O(|V|^2)（点数的平方）
// 应用范围：无权图 带权图 有向图 无向图 但是不能处理带负边权的图（权值必须大于0，不能小于0）
// 邻接矩阵存储
// 假设起点是start点
// dist[start]=0
// flag[i]=0 表示起点到i的最短路径未被确立下来，=1表明已经确定下来
// dist[i]=x;当前，点i到起点的最短距离
// 初始化，dist[start]=0 其余值都是无穷大
//

//首先能确定 离start最近的邻接点p的最短路径，这个最短路径就是start直接到该点p的边
//dist[p]=g[start][p];
//后面我们就可以用已经确定最短路径的点作为中转点，去缩短其他点的最短路径
// path[i]=j 在起点到i点的最短路径中，i的上一个点是j（最短路径经过哪些点）

//初始化:dist[start]=0，假设i是start的邻接点，dist[i]=g[start][i],其余的点的dist值都是无穷大，flag[start]=1,path[]=-1 path[start]=start
//进行n-1次循环：
// 1）找到被确定最短路径且dist最小的点p flag[p]==0 && dist[p]最小
// 2）该点的最短路径可以被确立下来，flag[p]=1;
// 3）根据该点去更新未被确立最短路径的邻接点j（flag[j]=0），
// 更新要求：dist[j]>dist[p]+g[p][j]&&flag[j]==0
// path[j]=p
//
//带权无向图
int g[105][105];
int v[105];
int dist[105];
int flag[105];
int path[105];
int n, m;

void Dijkstra(int start) {
	//先确定起点到起点的距离
	dist[start] = 0;
	path[start] = start;
	flag[start] = 1;
	//更新起点的邻接点
	for (int i = 0; i < n; i++) {
		if (g[start][i] != 10005 && flag[i] == 0) {
			dist[i] = g[start][i];
			path[i] = start;
		}
	}
	int t;//最小值下标
	int minn;//最小值
	for (int k = 0; k < n - 1; k++) {
		minn = 10005;
		t = -1;
		//找flag==0且dist值最小的点
		for (int i = 0; i < n; i++) {
			if (flag[i] == 0 && dist[i] < minn) {
				minn = dist[i];
				t = i;
			}
		}
		//t点的最短路径可以被确定
		flag[t] = 1;
		//用该点取更新未被确定最短路径的邻接点
		for (int i = 0; i < n; i++) {
			if (flag[i] == 0 && dist[i] > dist[t] + g[t][i])
			{
				dist[i] = dist[t] + g[t][i];
				path[i] = t;
			}
		}

	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i)
				g[i][j] = g[j][i] == 0;
			else
				g[i][j] = g[j][i] = 10005;
		}
		v[i] = i;
		dist[i] = 10005;
		flag[i] = 0;
		path[i] = -1;
	}
	int x, y, w,start;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		g[x][y] = g[y][x] = w;
	}
	cin >> start;//给出起点
	//对辅助数组赋值
	for (int i = 0; i < n; i++) {
		dist[i] = g[start][i];
	}
	Dijkstra(start);
	int p;
	for (int i = 0; i < n; i++) {
		cout << "起点到" << i << "的最短路径的距离是" << dist[i] << "该路径为:";
		p = i;
		while (path[p] != p) {
			cout << p<<" ";
			p = path[p];
		}
		cout << p << endl;
	}

	return 0;
}

/*
9 16
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4
0
*/