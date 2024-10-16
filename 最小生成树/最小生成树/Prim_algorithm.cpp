#include<iostream>

using namespace std;

const int maxx = 10001;
//给定一个带权无线连通图，该图有n个点，m条边（m>=n-1）
// n<100 m<5000 边权最大是10000
//求该图的最小生成树，在m条边种选出n-1条边
//这n-1条边在保证使得n个点联通（不能有环）的情况下，权值和最小

//一、分析
// 去选点：再选点的过程中，逐渐地把点分为两类
//1.已经选到生成树中的点
//2.还未选到生成树中的点
// 初始时：所有的点都是2类点
// 结束时：所有的点都是1类点
// 
// 点x到生成树的最小距离dist[x];
// 编号为x的点到生成树中的某个点的边的权值（距离）
// 如果x和生成树中的多个点相连，选权值最小的边权
// 
// 1.第一个点选谁：1）选题目告诉你的点 2）任选一个点即可
// 2.进行循环，循环n-1次，每次选离生成树最近的点，加入到生成树中 
// 将某点加入到生成树之后，要用该点去更新其他未加入到生成树中的点的dist 
//
// 
// 二、代码思路：Prim算法 ------基于贪心算法   O(|V|^2)点数的平方 适用于稠密图
// 维护一个dist[]，维护点到生成树的距离，初始化为无穷大
// 维护一个标记数组flag[i]=0,说明i没有被选到生成树中，=1，说明i已经备选入到生成树中
// 1.将起点加入到生成树中。
// 2.用起点去更新其他店的dist[],起点的邻接点到生成树的距离机会变成与起点相连的边权
// 3.n-1次循环：（1）选dist值最小的点，加入到生成树中，（2）用p去更新p的邻接点的dist 
// 
// 

int v[105];//点集
int g[105][105];//邻接矩阵存图
int dist[105];
int flag[105];
int n, m;

void Prim() {
	dist[0] = 0;
	flag[0] = 1; 
	cout << "把起点0加入到最小生成树中" << endl;
	//起点0所对应的权值如果小于dist里的值，则更新dist里的值
	for (int i = 0; i < n; i++) {//O(|V|)------->O(E)
		if (dist[i] > g[0][i] && flag[i] == 0) {
			dist[i] = g[0][i];
		}
	}
	int temp;//dist值最小的点的编号
	int minn;//最小的dist值
	for (int i = 0; i < n-1; i++) {//循环/O(|V|)
		minn = maxx;
		temp = -1;
		//选择dist中最小的值，且点为未被选过的点
		for (int j = 0; j < n; j++) {//O(|V|^2)
			if (flag[j] == 0 && dist[j] < minn) {
				temp = j;
				minn = dist[j];
			}
		}
		cout << "点" << temp << "通过权值为" << minn << "边，加入到最小生成树中" << endl;
		dist[temp] = 0;
		flag[temp] = 1;//标记此点已被加入到最小生成树中
		for (int j = 0; j < n; j++) {//O(|V|^2)
			if (flag[j] == 0 && dist[j] > g[temp][j]) {//加入的点的权值，如果小于dist里的值，则更新dist值
				dist[j] = g[temp][j];
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j)
			{
				g[i][j] = g[j][i] = maxx;
			}
		}
		dist[i] = maxx;
	}
	int x, y, w;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		g[x][y] = g[y][x] = w;
	}
	Prim();
}