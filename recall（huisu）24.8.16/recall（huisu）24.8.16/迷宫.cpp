#include<iostream>

using namespace std;

//洛谷P1605 难！！！
//0未走过的路，1障碍
//掩码值1是未走 0是已走
int migong[10][10];
int ans;
int startx, starty;
int endx, endy;
int mi_dir[4][2] = {
	{1,0},{-1,0},{0,1},{0,-1}
};
void dfs_mi(int x, int y) {
	if (x == endx && y == endy)
	{
		ans += 1;
		return;
	}
	migong[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int dx = x + mi_dir[i][0];
		int dy = y + mi_dir[i][1];
		if (migong[dx][dy] == 0)continue;
		dfs_mi(dx, dy);
	}
	migong[x][y]=1;
	return;
}
//
//int main() {
//	int n, m, t;
//	cin >> n >> m >> t;
//
//	cin >> startx >> starty >> endx >> endy;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			migong[i][j] = 1;
//		}
//	}
//	for (int i = 1; i <= t; i++) {
//		int a, b;
//		cin >> a >> b;
//		migong[a][b] = 0;
//	}
//	ans = 0;
//	dfs_mi(startx, starty);
//	cout << ans;
//	return 0;
//}
