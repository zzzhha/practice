#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//海贼OJ 49

int doublebag[10005];
//多重背包用01背包去做
//此代码待优化
//优化：4.3.3
//int main() {
//	int n, v;
//	cin >> v >> n;
//	for (int i = 1, weight, val, s; i <= n; i++) {
//		cin >> weight >> val >> s;
//		for (int k = 0; k < s; k++) {
//			for (int j = v; j >= weight; j--) {
//				doublebag[j] = max(doublebag[j], doublebag[j - weight] + val);
//			}
//		}
//	}
//	cout << doublebag[v];
//	return 0;
//}