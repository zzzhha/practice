#include<iostream>

using namespace std;

const int maxx = 100;

//给定一个带权无线连通图，该图有n个点，m条边（m>=n-1）
//求该图的最小生成树，在m条边种选出n-1条边
//这n-1条边在保证使得n个点联通（不能有环）的情况下，权值和最小

//1.进行n-1次选择，每次选一条边：选未被选择的边种权值尽可能小的
//贪心/贪婪算法 ：是用来求最优解的，每次都做出最有利的选择
//2每次选一条便后，要判断该边能不能使用：判断会不会形成环
// 用并查集判断会不会形成环：quick_union算法，判断并查集数组存放的值是否相同，
// （1）若不同则无法形成环，可以链接，并将并查集数组更改
// （2）若相同则形成环，则说明会形成环，不可以选该边
//

//kruskal算法：时间复杂度与边数有关，O(ElogE~E^2)(取决于排序算法)适用与稀疏图，站在选边的角度来看

//----------------------------------------------

struct graph {//边集数组法
	int start;
	int end;
	int weight;
}G[105];//边集
int v[105];//点集
int n, m;

int f[105];
//-----------并查集quick_union算法-------------
int find(int x) {
	////路径压缩
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
	cout << "最小生成树:\n";
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
	bubble_sort(G, 0, m);//O(m^2）
	cout << "按照升序排序:\n";
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