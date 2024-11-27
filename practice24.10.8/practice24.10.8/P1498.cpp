#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
//异或和(a+b)%2有相同的效果
//int nm[1030] = { 1 };
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < pow(2, n)/*1<<n*/; ++i) {
//		for (int j = 1; j < pow(2,n) - i; ++j) cout << " ";//前导空格
//		
//		for (int j = i; j >= 0; --j) nm[j] ^= nm[j - 1];//修改数组
//		
//		if (!(i % 2))for (int j = 0; j <= i; ++j)cout << (nm[j] ? "/\\" : "  ");//奇数行
//		
//		else for (int j = 0; j <= i; j += 2) cout << (nm[j] ? "/__\\" : "    ");//偶数行
//		
//		cout << endl;
//	}
//	return 0;
//}
char a[3000][3000];//1024 1024
int h = 2, w = 4;//h是高,w是宽
//int main() {
//	int n;
//	cin >> n;
//	memset(a, ' ', sizeof(a)); 
//	a[1][1] = a[1][4] = ' ';
//	a[1][2] = a[2][1] = '/';
//	a[1][3] = a[2][4] = '\\';//向右的划线有特殊的含义
//	a[2][2] = a[2][3] = '_';
//	for (int i = 1; i < n; i++) {
//		//向下和向右
//		for (int j = 1; j <= h; j++) {
//			for (int k = 1; k <= w; k++) {
//				a[j + h][k] = a[j + h][k + w] = a[j][k];
//				a[j][k] = ' ';//把上面的清掉
//			}
//		}
//		//向上
//		for (int j = 1; j <= h; j++) {
//			for (int k = 1; k <= w; k++) {
//				a[j][k + w / 2] = a[j + h][k];
//			}
//		}
//		w *= 2, h *= 2;
//		//刷新完成一次
//	}
//	for (int i = 1; i <= h; i++) {
//		for (int j = 1; j <= w; j++) {
//			cout << a[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}