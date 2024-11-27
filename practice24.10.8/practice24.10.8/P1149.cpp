#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

//int chai[10] = { 6,2,5,5,4,5,6,3,7,6 };
//int ans = 0;
//int chongfu[2000];
//
//int chai_num(int a) {
//	if (a < 10)
//		return chai[a];
//	return chai_num(a / 10) + chai[a % 10];
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int cur = n - 4;
//	for (int i = 0; i < 2000; i++) {
//		for (int j = 0; j < 2000; j++) {
//			if (i == j && chongfu[i]) break;
//			if (i == j)chongfu[i] = 1;
//			if (chai_num(i + j) + chai_num(i) + chai_num(j) == cur) ans++;
//		}
//	}
//	cout << ans;
//	return 0;
//}