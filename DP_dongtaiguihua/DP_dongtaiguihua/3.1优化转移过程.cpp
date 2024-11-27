#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<easyx.h>

using namespace std;


//����OJ 46 
//dp(i) ��1��i�����ж��ٵ�
//dp(i)={min(dp[k]+1}|S[k+1]

//�Ż�ת�ƹ��̣�ȥԤ����һЩ�Ż���Ϣ
//�Է������״̬ת��

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
//		extract(s,i,i);//��ȡ����λ�Ļ��Ĵ�
//		extract(s, i, i + 1);//��ȡż��λ�Ļ��Ĵ�
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