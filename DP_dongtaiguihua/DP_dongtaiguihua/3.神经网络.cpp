#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//���P1038


int c[105], U[105];//cΪ״ֵ̬��UΪ��ֵ
int w[105][105];//ͼ�ıߣ��洢Ȩֵ
int outdeg[105];//��¼��Ӧ�±�ĳ���
int indeg[105];//��¼��Ӧ�±�����
vector<int> g[105];//�洢ÿ�����Ӧ�ĵ�

//int main() {
//	int n,p;
//	cin >> n >> p;
//	for (int i = 1; i <= n; i++) {
//		cin >> c[i] >> U[i];
//		if (c[i] == 0)c[i] = -U[i];//��������������񾭽ڵ㣨�����c[i]��Ϊ0������ô���ǽ����ǳ�δ����ģ�c[i]<0��ʾδ���>0��ʾ���
//	}
//	for (int i = 0; i < p; i++) {
//		int a, b, weight;
//		cin >> a >> b >> weight;
//		w[a][b] = weight;
//		indeg[b]++;
//		outdeg[a]++;
//		g[a].push_back(b);
//	}
//	queue<int>q;
//	for (int i = 1; i <= n; i++) {
//		if (indeg[i])continue;
//		q.push(i);//���������񾭽ڵ����,���������һ��Ϊ0
//	}
//	while (!q.empty()) {
//		int ind = q.front();
//		q.pop();
//		if (c[ind] > 0) {//˵����ǰ�ڵ��ѱ�����
//			for (int i = 0; i < g[ind].size(); i++) {
//				int to = g[ind][i];
//				c[to] += w[ind][to] * c[ind];
//			}
//		}
//		for (int i = 0; i < g[ind].size(); i++) {
//			int to = g[ind][i];
//			indeg[to]--;
//			if (indeg[to] == 0) {
//				q.push(to);
//			}
//		}
//	}
//	int flag = 0;
//	for (int i = 1; i <= n; i++) {
//		if (outdeg[i])continue;//�������񾭽ڵ����Ϊ0
//		if (c[i] <= 0)continue;//���c[i]δ����
//		cout << i << " " << c[i]<< endl;
//		flag = 1;
//	}
//	if (!flag)cout << "NULL" << endl;
//	return 0;
//}