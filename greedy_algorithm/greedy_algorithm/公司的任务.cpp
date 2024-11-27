#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//海贼OJ 259
struct machine {
	int times;
	int level;
}chine[100005];

struct task {
	int times;
	int level;
}ta[100005];


//int main() {
//	int cnt[105] = {0};//能处理难度系数为i的机器有多少台
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin>>chine[i].times >> chine[i].level;
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> ta[i].times >> ta[i].level;
//	}
//	sort(chine, chine + n, [](machine& a, machine& b)->bool {
//		if (a.times - b.times) return a.times > b.times;
//		else return a.level > b.level;
//		});
//	sort(ta, ta+ m, [](task& a, task& b)->bool {
//		if (a.times - b.times) return a.times > b.times;
//		else return a.level > b.level;
//		});
//
//	long long ans = 0;
//	int count = 0;
//	for (int i = 0 ,j=0; i < m; i++) {
//		while (j < n && chine[j].times >= ta[i].times) {
//			cnt[chine[j].level]++;
//			j++;
//		}
//		for (int y = ta[i].level; y <= 100; y++) {
//			if (cnt[y] == 0)continue;
//			cnt[y]--;
//			ans += 500 * ta[i].times + 2 * ta[i].level;
//			count++;
//			break;
//		}
//	}
//	
//	cout << count<<" "<<ans;
//	return 0;
//}
