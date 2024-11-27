#include<iostream>

using namespace std;
//long long dp[25][25];
//int dpfz[25][25];
//
//int mdirt[8][2] = {
//	{2,1},
//	{-2,1},
//	{2,-1},
//	{-2,-1},
//	{ 1,2 },
//	{-1,2},
//	{1,-2},
//	{-1,-2}
//};
//int main() {
//	int x, y;
//	int mx, my;
//	cin >> x >> y;
//	cin >> mx >> my;
//	x += 2; y += 2; mx += 2; my += 2;
//	dp[2][1] = 1;
//	dpfz[mx][my] = 1;
//	for (int i = 0; i < 8; i++) {
//		dpfz[mx + mdirt[i][0]][my + mdirt[i][1]] = 1;
//	}
//	for (int i = 2; i <= x; i++) {
//		for (int j = 2; j <= y; j++) {
//			if (dpfz[i][j]) continue;
//			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//		}
//	}
//	cout << dp[x][y] << endl;
//	return 0;
//}