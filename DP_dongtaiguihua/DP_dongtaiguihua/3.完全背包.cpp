#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//海贼OJ 48

int allbag_ret[10005];
//int main() {
//	int v, n;
//	cin >> n >> v;
//	for (int i = 1, weight, val; i <= n; i++) { 
//		cin >> weight >> val;
//		for (int j = weight; j <= v; j++) {
//			allbag_ret[j] = max(allbag_ret[j], allbag_ret[j - weight] + val);
//		}
//		//此处正序是因为，我们需要用allbag_ret[j - weight]来更新allbag_ret[j]的值
//	}
//	//优化plusplus
//	cout << allbag_ret[v];
//	return 0;
//}