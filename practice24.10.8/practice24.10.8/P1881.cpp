#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int shengzi[20005];
//int main() {
//	int l, n;
//	cin >> n >> l;
//	int p;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> p;
//		shengzi[p * 2] = 1;
//	}
//	for (int i = 1; i < 2 * l; i++) {//枚举位置
//		int flag = 1, s = 0;
//		while (i >= s && i + s <= 2 * l) {//是否越界
//			if (shengzi[i - s] != shengzi[i + s])flag = 0;
//			s++;
//		}//枚举长度
//		ans += flag;
//	}
//	cout << ans;
//	return 0;
//}