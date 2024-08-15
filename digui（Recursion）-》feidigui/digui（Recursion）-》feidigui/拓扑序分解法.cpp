#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<set>
using namespace std;

//��������
#define MAX_N

int indeg[MAX_N + 5] = { 0 };
vector<vector<int>>g(MAX_N+5);
int ans[MAX_N + 5], cnt = 0;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		indeg[b] += 1;
		g[a].push_back(b);
	}
	set<int> q;
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0)q.insert(i);
	}
	while (q.size() > 0) {
		int now = *q.begin();//top()
		ans[cnt++] = now;
		q.erase(q.begin());//pop()
		//-------------
		for (int i = 0, I = g[now].size(); i < I; i++) {
			int t = g[now][i];
			indeg[t] -= 1;
			if (indeg[t] == 0) {
				q.insert(t);
			}
		}
		//-------------

	}
	for (int i = 0; i < cnt; i++) {
		if (i)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}