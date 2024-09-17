#include<iostream>
#include<queue>
using namespace std;

//���1443 �ѣ���

/*int n, m;
int min_dist[405][405];
int dir[8][2] = {
	{2,1},{-2,1},{2,-1},{-2,-1},
	{1,2},{1,-2},{-1,2},{-1,-2},
};*///�������飬���ڱ��⣬�������8������ÿ��������Ҫ��¼����ֵ


//�������� �ᳬʱTLE ֻ��80��
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
//	dfs_ma(0,x,y);//��һλ���ﵱǰ�������Ĳ���������λ��ʾ��ǰ���ڵĵ�
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (j > 1)cout << " ";
//			cout << min_dist[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}


//������� �ʺ�����̲��� 

int min_dist[405][405];
int dir[8][2] = {
	{2,1},{-2,1},{2,-1},{-2,-1},
	{1,2},{1,-2},{-1,2},{-1,-2},
};
struct Node {
	int x, y;//����
	int s;//��̾�����s��
	Node(int x,int y,int s):x(x),y(y),s(s){}
};
void bfs(int n, int m, int x, int y) {
	queue<Node>q;
	q.push(Node(x, y, 0));//�����ѹ�����
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