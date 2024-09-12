#include<iostream>

using namespace std;

const int maxx = 100;

//����һ����Ȩ������ͨͼ����ͼ��n���㣬m���ߣ�m>=n-1��
//���ͼ����С����������m������ѡ��n-1����
//��n-1�����ڱ�֤ʹ��n������ͨ�������л���������£�Ȩֵ����С

//1.����n-1��ѡ��ÿ��ѡһ���ߣ�ѡδ��ѡ��ı���Ȩֵ������С��
//̰��/̰���㷨 �������������Ž�ģ�ÿ�ζ�������������ѡ��
//2ÿ��ѡһ�����Ҫ�жϸñ��ܲ���ʹ�ã��жϻ᲻���γɻ�
// �ò��鼯�жϻ᲻���γɻ���quick_union�㷨���жϲ��鼯�����ŵ�ֵ�Ƿ���ͬ��
// ��1������ͬ���޷��γɻ����������ӣ��������鼯�������
// ��2������ͬ���γɻ�����˵�����γɻ���������ѡ�ñ�
//

//kruskal�㷨��ʱ�临�Ӷ�������йأ�O(ElogE~E^2)(ȡ���������㷨)������ϡ��ͼ��վ��ѡ�ߵĽǶ�����

//----------------------------------------------

struct graph {//�߼����鷨
	int start;
	int end;
	int weight;
}G[105];//�߼�
int v[105];//�㼯
int n, m;

int f[105];
//-----------���鼯quick_union�㷨-------------
int find(int x) {
	////·��ѹ��
	 if(x!=f[x])
			return f[x]=find(f[x]);
	 else
			return x;
	
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x == y)
		return false;
	f[x] = y;
	cout << a <<" " << b<<" "<<endl;
	return true;
}
void bubble_sort(graph* arr, int l, int r) {
	for (int i = l; i < r - 1; i++)
	{
		int flag = 1;
		for (int j = l; j < r - 1 - i; j++)
		{
			if (arr[j].weight > arr[j + 1].weight)
			{
				flag = 0;
				swap(arr[j], arr[j + 1]);
			}
		}
		if (flag)
			break;
	}
}


void Kruskal(graph *g) {
	cout << "��С������:\n";
	for(int i=0;i<m-1;i++)
	{
		merge(g[i].start, g[i].end);
	}
}

int main() {
	cin >> n >> m;
	int x, y,w;
	for (int i = 0; i < m; i++) {//O(m)
		v[i] = i;
		cin >> x >> y >> w;
		G[i].start = x;
		G[i].end = y;
		G[i].weight = w;
		f[i] = i;
	}
	bubble_sort(G, 0, m);//O(m^2��
	cout << "������������:\n";
	for (int i = 0; i < m; i++) {//O(m)
		cout << G[i].start << " " << G[i].end << " " << G[i].weight << endl;
	}
	Kruskal(G);//O(m)


	return 0;
}
/*
9 15
0 1 3
0 5 4
1 6 6
6 5 7
1 2 8
1 8 5
2 8 2
2 3 12
8 3 11
6 3 14
6 7 9
5 4 18
3 7 6
7 4 1
3 4 10
*/