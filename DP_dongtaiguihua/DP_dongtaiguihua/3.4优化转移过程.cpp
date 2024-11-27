#include<iostream>
#include<algorithm>
#include<deque>
#include<stack>
#include<string>
#include<easyx.h>

using namespace std;

//HZOJ 51
//δ�Ż�
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

//�Ż�
//1.�ռ��Ż����������飩����ά�Ż���1ά
//2.����ջ������ջ��while��̯ʱ�临�Ӷ�ΪO��1�������ԭ�ȵ�O��n����
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
//			while (bw_rectangle_val[i][s.top()] >= bw_rectangle_val[i][j])s.pop();//��һ�����󣬴�ʱջ��Ԫ�ؾ��ǵ�һ��С�ڵ�ǰij��ֵ��Ԫ��
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