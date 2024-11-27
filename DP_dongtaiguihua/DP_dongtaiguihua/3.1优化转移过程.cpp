#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<easyx.h>

using namespace std;


//海贼OJ 46 
//dp(i) 从1到i最少切多少刀
//dp(i)={min(dp[k]+1}|S[k+1]

//优化转移过程：去预处理一些优化信息
//以方便进行状态转移

int huiweiplus[500000 + 5];
vector<int> g_huiwen[500000 + 5];
int is_palindrome(const string &s,int i, int j) {
	while (i < j) {
		if (s[i] != s[j]) return 0;
		i++, j--;
	}
	return 1;
}

void extract(const string &s, int i, int j) {
	while (s[i] == s[j]) {
		g_huiwen[i].push_back(j-1);
		i++, j--;
	}
	return;
}

//int main() {
//	string s;
//	cin >> s;
//	s = '@' + s;
//	int n = s.length() - 1;
//	for (int i = 1; i <= n; i++) {
//		extract(s,i,i);//提取奇数位的回文串
//		extract(s, i, i + 1);//提取偶数位的回文串
//	}
//	huiweiplus[0] = -1;
//	for (int i = 1; s[i]; i++) {
//		huiweiplus[i] = i; 
//		for (auto j: g_huiwen[i]) {
//			huiweiplus[i] = min(huiweiplus[i], huiweiplus[j] + 1);
//		}
//	}
//	cout << huiweiplus[n] << endl;
//	return 0;
//}