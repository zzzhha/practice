#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node {
	char data;
	Node* next;
};

struct graph_linjie {
	char data;
	Node* first;
}G[105];//邻接表



char v[105];
int g[105][105];//邻接矩阵
int flag[105];//flag[i]==0 i未被访问，i=1被访问过
int n, m;

int find(char x) {
	for (int i = 0; i < n; i++) {
		if (G[i].data == x) {
			return i;
		}
	}
	return -1;
}

int _find(char x) {
	for (int i = 0; i < n; i++) {
		if (v[i]== x) {
			return i;
		}
	}
	return -1;
}

//DFS的思路
// 1.访问起点，打标记，标记为已访问状态
// 2.找到一个v的未被访问过的邻接点x，访问x，把x标为已访问状态
// 3.找到一个x的未被访问的邻接点，循环2.3，直到某个点没有未被访问的邻接点，此时开始返回上一层
//一直循环2，3步，直到所有的点都被访问完为止  
//邻接矩阵存无向图 进行DFS 时间复杂度 O(|V|^2) 
//邻接表存图 进行DFS 时间复杂度 O（|V|+|E|）
void DFS(int i) {//深度优先遍历
	cout << G[i].data<< " ";
	flag[i] = 1;
	//for (int j = 0; j < n; j++) {//邻接矩阵
	//	if (g[i][j] == 1 && flag == 0) {
	//		DFS(j);//访问
	//	}
	//}
	Node* p = G[i].first;
	while (p) {
		if (!flag[p->data])
			DFS(p->data);
		p = p->next;
	}//邻接表
}

//BFS的思路
//1.生命一个队列，辅助遍历
//2.起点入队
//3.进行循环：如果队列费控，对手元素出兑，访问该数据，把该数据锁子阿迪按的邻接点入队
//直到队列为空，遍历结束（该图是连通图）

int head, tail;
void BFS(int i) {//广度优先遍历
	
	head, tail = 0;

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		//cin >> v[i];
		cin >> G[i].data;
		G[i].first = nullptr;
	}//邻接矩阵/邻接表
	char x, y;
	for (int i = 0; i < m; i++) {
		
		cin >> x >> y;
		//int xi = _find(x);
		//int yi = _find(y);//邻接矩阵
		int xi = find(x);
		int yi = find(y);
		//g[xi][yi] =g[yi][xi] = 1;//邻接矩阵
		Node* p = new Node;
		p->data = y;
		p->next = G[xi].first;
		G[xi].first = p;

		Node* e = new Node;
		e->data = x;
		e->next = G[yi].first;
		G[yi].first = e;//邻接表无向图
		
	}
	for (int i = 0; i < n; i++) {
		if (flag[i] == 0)
		{
			DFS(i);
		}
	}
	return 0;
}
/*
9 15
ABCDEFGHI
A B
A F
B G
G F
B C
B I
F E
C I
C D
I D
G H
E H
D H
D E
G D
*/