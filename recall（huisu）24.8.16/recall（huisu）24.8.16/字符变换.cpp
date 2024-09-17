#include<iostream>
#include<map>
#include<string>
using namespace std;

//洛谷P1032  难！！！！！

int trans_cnt = 0;
int anss=100;
int ans_k;
string a, b;//a是原字符串，b是经过变换后的目的字符串
string from[10], to[10];//from是变换前的字符串，to 是变换后的字符串
map<string, int>dp;//红黑树，以字符串当做下标，i  nt为他存储的值

void dfs_string(string& now,int step) {
	if (step >= ans_k) return;
	dp[now] = step;
	if (step > 10)return;
	if (now == b) {
		anss = step;
		return;
	}
	for (int i = 0; i < trans_cnt; i++) {
		int pos = -1;
		pos = now.find(from[i]);
		string changed;
		while (pos != -1)
		{
			changed = now;
			changed.erase(pos, from[i].size());
			changed.insert(pos, to[i]); 
			if (dp.find(changed) == dp.end() || dp[changed] > step+1)
			{
				dfs_string(changed, step + 1);
			}
			pos = now.find(from[i], pos + 1);
		}
	}
	return;
}

//int main() {
//	cin >> a >> b;
//	while (cin >> from[trans_cnt] >> to[trans_cnt])trans_cnt++;
//	for (int i = 1; i <= 10; i++) {//迭代加深
//		ans_k = i;
//		dp.clear();
//		dfs_string(a, 0);
//		if (anss != 100)break;
//
//	}
//	if (anss == 100) cout << "NO ANSWER!"<<endl;
//	else
//		cout << anss << endl;
//	return 0;
//}