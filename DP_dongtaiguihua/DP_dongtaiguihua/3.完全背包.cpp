#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//����OJ 48

int allbag_ret[10005];
//int main() {
//	int v, n;
//	cin >> n >> v;
//	for (int i = 1, weight, val; i <= n; i++) { 
//		cin >> weight >> val;
//		for (int j = weight; j <= v; j++) {
//			allbag_ret[j] = max(allbag_ret[j], allbag_ret[j - weight] + val);
//		}
//		//�˴���������Ϊ��������Ҫ��allbag_ret[j - weight]������allbag_ret[j]��ֵ
//	}
//	//�Ż�plusplus
//	cout << allbag_ret[v];
//	return 0;
//}