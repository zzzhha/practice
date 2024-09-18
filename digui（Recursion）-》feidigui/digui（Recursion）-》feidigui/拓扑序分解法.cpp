#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<set>
using namespace std;

//��������
#define MAX_N 10

int indeg[MAX_N + 5] = { 0 };//�������
vector<vector<int>>g(MAX_N+5);//�ڽӾ���
int ans[MAX_N + 5], cnt = 0;//ans�Ƕ�������

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;//ͳ�Ʊߵ�����
		indeg[b] += 1;//�������++
		g[a].push_back(b);//���ڽӾ���洢��ͷ��
	}
	set<int> q;//�������Ϊ0�ĵ�
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0)q.insert(i);
	}
	while (q.size() > 0) {
		int now = *q.begin();//�൱�ڶ���top()
		ans[cnt++] = now;//��¼��һ�������е���
		q.erase(q.begin());//�൱�ڶ���pop()
		//-------------
		for (int i = 0, I = g[now].size(); i < I; i++) {
			int t = g[now][i];//��ȡnow�������ӵĵ�
			indeg[t] -= 1;//���˵�ĳ��ȵĵ��1
			if (indeg[t] == 0) {//����˵����Ϊ0
				q.insert(t);//�������Ϊ0�ĵ�
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