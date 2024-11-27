#include<iostream>
#include<algorithm>
#include<deque>
#include<stack>
#include<string>
#include<easyx.h>

using namespace std;

//HZOJ 51
//未优化
int bw_rectangle[1000 + 5][1000 + 5];
int bw_rectangle_val[1005][1005];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> bw_rectangle_val[i][j];
//		}
//	}
//	for (int i = n - 1; i >= 1; i--){
//		for (int j = 1; j <= m; j++){
//			if (bw_rectangle_val[i][j]==0)continue;
//			bw_rectangle_val[i][j] += bw_rectangle_val[i + 1][j];
//		}
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = m; j>= 1; j--) {
//			int k = j;
//			while (k <= m && bw_rectangle_val[i][k] >= bw_rectangle_val[i][j])k++;
//			bw_rectangle[i][j] = bw_rectangle_val[i][j] * (k - j) + bw_rectangle[i][k];
//			bw_rectangle[i][j] %= 100007;
//			ans += bw_rectangle[i][j];
//			ans %= 100007;
//		}
//	}
//	cout << ans;
//	return 0;
//} 

//优化
//1.空间优化（滚动数组）将二维优化成1维
//2.单调栈，单调栈的while均摊时间复杂度为O（1），会比原先的O（n）快
int bw_rectangle_p[1000 + 5];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> bw_rectangle_val[i][j];
//		}
//	}
//	for (int i = n - 1; i >= 1; i--) {
//		for (int j = 1; j <= m; j++) {
//			if (bw_rectangle_val[i][j] == 0)continue;
//			bw_rectangle_val[i][j] += bw_rectangle_val[i + 1][j];
//		}
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		stack<int> s;
//		s.push(m + 1);
//		bw_rectangle_val[i][m + 1] = -1;
//		for (int j = m; j >= 1; j--) {
//			while (bw_rectangle_val[i][s.top()] >= bw_rectangle_val[i][j])s.pop();//这一步过后，此时栈顶元素就是第一个小于当前ij的值的元素
//			bw_rectangle_p[j] = bw_rectangle_val[i][j] * (s.top() - j) + bw_rectangle_p[s.top()];
//			bw_rectangle_p[j] %= 100007;
//			ans += bw_rectangle_p[j];
//			ans %= 100007;
//			s.push(j);
//		}
//	}
//	cout << ans;
//	return 0;
//}