#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//海贼OJ 45

int pq[1005][1005];
//dp(i,j)代表a串长度为i位作为结尾，b串长度为j位作为结尾的子序列长度

//int main() {
//	string a, b;
//	cin >> a >> b;
//	a = "@" + a;
//	b = "#" + b;//随意加一个字符是为了防止后面pq[i-1]做的准备
//	//也可以避免在后续计算的时候出现下标的偏移
//	int len_a = a.length()-1;
//	int len_b = b.length()-1;
//	for (int i = 1; i <= len_a; i++) {
//		for (int j = 1; j <= len_b; j++) {
//			pq[i][j] = max(pq[i - 1][j], pq[i][j - 1]);
//			if (a[i] == b[j]) {
//				pq[i][j] = max(pq[i][j], pq[i - 1][j - 1] + 1);
//			}
//		}
//	}
//	cout << pq[len_a][len_b];
//	return 0;
//}