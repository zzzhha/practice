#include<iostream>
#include<queue>
using namespace std;

//洛谷1443 难！！

/*int n, m;
int min_dist[405][405];
int dir[8][2] = {
	{2,1},{-2,1},{2,-1},{-2,-1},
	{1,2},{1,-2},{-1,2},{-1,-2},
};*///方向数组，对于本题，马可以走8个方向，每个方向需要记录两个值


//回溯深搜 会超时TLE 只有80昏
//void dfs_ma(int step, int x, int y) {
//	if (min_dist[x][y] != -1 && min_dist[x][y] <= step)
//		return;
//	min_dist[x][y] = step;
//	for (int k = 0; k < 8; k++) {
//		int dx = x + dir[k][0];
//		int dy = y + dir[k][1];
//		if (dx<1 || dx>n)continue;
//		if (dy<1 || dy>m)continue;
//		dfs_ma(step + 1, dx, dy);
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	int x, y;
//	cin >> x >> y;
//	for (int i =1; i <= n; i++) {
//		for (int j = 1; j <= 1; j++) {
//			min_dist[i][j] = -1;
//		}
//	}   
//	dfs_ma(0,x,y);//第一位到达当前点所花的步数，二三位表示当前所在的点
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (j > 1)cout << " ";
//			cout << min_dist[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}


//层序遍历 适合求最短步长 

int min_dist[405][405];
int dir[8][2] = {
	{2,1},{-2,1},{2,-1},{-2,-1},
	{1,2},{1,-2},{-1,2},{-1,-2},
};
struct Node {
	int x, y;//坐标
	int s;//最短距离是s步
	Node(int x,int y,int s):x(x),y(y),s(s){}
};
void bfs(int n, int m, int x, int y) {
	queue<Node>q;
	q.push(Node(x, y, 0));//将起点压入队列
	min_dist[x][y] = 0;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int dx = now.x + dir[i][0];
			int dy = now.y + dir[i][1];
			if (dx<1 || dx>n)continue;
			if (dy<1 || dy>m)continue;
			if (min_dist[dx][dy] != -1)continue;
			q.push(Node(dx, dy, now.s + 1));
			min_dist[dx][dy] = now.s + 1;
		}
	}
	return;
}
//int main() {
//	int  n, m, a, b;
//	cin >> n >> m >> a >> b;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			min_dist[i][j] = -1;
//		}
//	}
//	bfs(n, m, a, b);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (j > 1)cout << " ";
//			cout << min_dist[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}