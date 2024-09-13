#include<iostream>

using namespace std;

//����̰��
// dijkstra�㷨�����������㵽����n-1�������̾���
// �ǵ�Դ���·���㷨��һ��ֻ����һ����㵽����������·���㷨
// ʱ�临�Ӷ�O(|V|^2)��������ƽ����
// Ӧ�÷�Χ����Ȩͼ ��Ȩͼ ����ͼ ����ͼ ���ǲ��ܴ��������Ȩ��ͼ��Ȩֵ�������0������С��0��
// �ڽӾ���洢
// ���������start��
// dist[start]=0
// flag[i]=0 ��ʾ��㵽i�����·��δ��ȷ��������=1�����Ѿ�ȷ������
// dist[i]=x;��ǰ����i��������̾���
// ��ʼ����dist[start]=0 ����ֵ���������
//

//������ȷ�� ��start������ڽӵ�p�����·����������·������startֱ�ӵ��õ�p�ı�
//dist[p]=g[start][p];
//�������ǾͿ������Ѿ�ȷ�����·���ĵ���Ϊ��ת�㣬ȥ��������������·��
// path[i]=j ����㵽i������·���У�i����һ������j�����·��������Щ�㣩

//��ʼ��:dist[start]=0������i��start���ڽӵ㣬dist[i]=g[start][i],����ĵ��distֵ���������flag[start]=1,path[]=-1 path[start]=start
//����n-1��ѭ����
// 1���ҵ���ȷ�����·����dist��С�ĵ�p flag[p]==0 && dist[p]��С
// 2���õ�����·�����Ա�ȷ��������flag[p]=1;
// 3�����ݸõ�ȥ����δ��ȷ�����·�����ڽӵ�j��flag[j]=0����
// ����Ҫ��dist[j]>dist[p]+g[p][j]&&flag[j]==0
// path[j]=p
//
//��Ȩ����ͼ
int g[105][105];
int v[105];
int dist[105];
int flag[105];
int path[105];
int n, m;

void Dijkstra(int start) {
	//��ȷ����㵽���ľ���
	dist[start] = 0;
	path[start] = start;
	flag[start] = 1;
	//���������ڽӵ�
	for (int i = 0; i < n; i++) {
		if (g[start][i] != 10005 && flag[i] == 0) {
			dist[i] = g[start][i];
			path[i] = start;
		}
	}
	int t;//��Сֵ�±�
	int minn;//��Сֵ
	for (int k = 0; k < n - 1; k++) {
		minn = 10005;
		t = -1;
		//��flag==0��distֵ��С�ĵ�
		for (int i = 0; i < n; i++) {
			if (flag[i] == 0 && dist[i] < minn) {
				minn = dist[i];
				t = i;
			}
		}
		//t������·�����Ա�ȷ��
		flag[t] = 1;
		//�øõ�ȡ����δ��ȷ�����·�����ڽӵ�
		for (int i = 0; i < n; i++) {
			if (flag[i] == 0 && dist[i] > dist[t] + g[t][i])
			{
				dist[i] = dist[t] + g[t][i];
				path[i] = t;
			}
		}

	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i)
				g[i][j] = g[j][i] == 0;
			else
				g[i][j] = g[j][i] = 10005;
		}
		v[i] = i;
		dist[i] = 10005;
		flag[i] = 0;
		path[i] = -1;
	}
	int x, y, w,start;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		g[x][y] = g[y][x] = w;
	}
	cin >> start;//�������
	//�Ը������鸳ֵ
	for (int i = 0; i < n; i++) {
		dist[i] = g[start][i];
	}
	Dijkstra(start);
	int p;
	for (int i = 0; i < n; i++) {
		cout << "��㵽" << i << "�����·���ľ�����" << dist[i] << "��·��Ϊ:";
		p = i;
		while (path[p] != p) {
			cout << p<<" ";
			p = path[p];
		}
		cout << p << endl;
	}

	return 0;
}

/*
9 16
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4
0
*/