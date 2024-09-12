#include<iostream>
#include<queue>
using namespace std;

struct Node {
	char data;//邻接点下标
	Node* next;
};

struct graph_linjie {
	char data;//顶点数据
	Node* first;
}G[105];//邻接表

//-------队列代码--------
const int Max = 100;
struct queue1 {
	int qdata[Max];
	int head, tail;//头尾指针
};

void initqueue(queue1 *q) {
	q->head = q->tail = 0;
}

void Enqueue(queue1 *q,int k) {
	if ((q->tail + 1) % Max == q->head)
	{
		cout << "已满" << endl;
		return;
	}
	q->qdata[q->tail] = k;
	q->tail = (q->tail + 1) % Max;
}

bool empty(queue1* q) {
	if (q->tail == q->head)
		return true;
	return false;
}

void Dequeue(queue1* q, int* k) {
	if (empty(q)) {
		cout << "队空" << endl;
		return;
	}
	*k = q->qdata[q->head];
	q->head = (q->head + 1) % Max;
}


//--------------------------------


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

int _find(char x) {//邻接矩阵
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

//深度优先遍历
void DFS(int i) {
	//printf("%c ", G[i].data);
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
//1.声明一个队列，辅助遍历
//2.起点入队
//3.进行循环：如果队列非空，队首元素出队，访问该数据，把该数据所在点的邻接点入队
//直到队列为空，遍历结束（该图是连通图）

//广度优先遍历
void BFS(int start) {
	queue1 q;
	initqueue(&q);
	Enqueue(&q, start);
	flag[start] = 1;
	int k,j;
	while (empty(&q) == 0) {
		Dequeue(&q, &k);
		cout << G[k].data << " " ;
		Node* p = G[k].first;
		while (p != nullptr) {
			j = p->data;
			if (flag[j] == 0) {
				Enqueue(&q, j);
				flag[j] = 1;
				v[j] = v[k] + 1;
			}
			p = p->next;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		//cin >> v[i];//邻接矩阵
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
		p->data = yi;
		p->next = G[xi].first;
		G[xi].first = p;

		Node* e = new Node;
		e->data = xi;
		e->next = G[yi].first;
		G[yi].first = e;//邻接表无向图
		
	}
	for (int i = 0; i < n; i++) {
		if (flag[i] == 0)
		{
			//DFS(i);
			BFS(i);
			cout << endl;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%c %d\n", G[i].data, v[i]);
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
G D
E H
D H
D E
*/