#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//����OJ 49

int doublebag[10005];
//���ر�����01����ȥ��
//�˴�����Ż�
//�Ż���4.3.3
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