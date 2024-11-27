#include<iostream>
#include<algorithm>

using namespace std;

//洛谷P1028
int fig[1005];//以i为开头的数列数量
//int main() {
//	int n;
//	cin >> n;
//	fig[0] = 0;
//	for (int i = 1; i <= n ; i++) {
//		fig[i] = 1;
//		int j = i/2;
//		while (j) {
//			fig[i] += fig[j];
//			j--;
//		}
//	}
//	cout << fig[n];
//	return 0;
//}