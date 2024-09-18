#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<set>
using namespace std;

struct Stack{
	int data;//顶点下标
	Stack* next;
};

Stack* init() {
	Stack* s = new Stack;
	s->next = nullptr;
	return s;
}

Stack* push(Stack *p,int n) {
	Stack *s = new Stack;
	s->data = n;
	Stack* q = p;
	while (q->next) {
		q = q->next;
	}
	s->next = q->next;
	q->next = s;
	return p;
}

bool empty(Stack* p) {
	if (p->next == nullptr) return true;
	return false;
}

Stack* pop(Stack* s, int* j) {
	if (empty(s))
	{
		*j = 0;
		return s;
	}
	Stack* q=s;
	Stack* p=s;
	while (p->next) {
		q = p;
		p = p->next;
	}
	*j = p->data;
	q->next = nullptr;
	delete p;
	return s;
}


//邻接表存有向图 出边
struct adjNode {
	int data;
	adjNode* next;
};
//顶点数组
struct VNode {
	char d;
	adjNode* first;
}g[105];
int n, m;
int ind[105];//存入度
int ans;
int topo[105];//保存拓扑序列顺序

int find(char x) {
	for (int i = 0; i < n; i++) {
		if (x == g[i].d)
			return i;
	}
	return -1;
}

void TopoSort() {
	stack<int> s;
	for (int i = 0; i < n; i++) {
		if (ind[i] == 0) {
			s.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (s.empty())
			break;
		int now = s.top();
		topo[ans++] = g[now].d;
		s.pop();
		adjNode* p = g[now].first;
		while (p) {
			int t = p->data;
			ind[t]--;
			if (ind[t] == 0) {
				s.push(t);
			}
			p = p->next;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> g[i].d;
		g[i].first = nullptr;
	}
	char x, y;
	int xi, yi;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		xi = find(x);
		yi = find(y);
		ind[yi]++;
		adjNode* p = new adjNode;
		p->data = yi;
		p->next = g[xi].first;
		g[xi].first = p;
	}
	TopoSort();
	if (ans!=n) {
		cout << "是带环图，无拓扑序列" << endl;
	}
	
		for (int i = 0; i < n; i++) {
			printf("%c", topo[i]);
		}
	
	return 0;
}

//拓扑排序
#define MAX_N 10

int indeg[MAX_N + 5] = { 0 };//入度数组
vector<vector<int>>gr(MAX_N + 5);//邻接矩阵
int anss[MAX_N + 5], cnt = 0;//ans是顶点数组

//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0, a, b; i < m; i++) {
//		cin >> a >> b;//统计边的两点
//		indeg[b] += 1;//入度数组++
//		gr[a].push_back(b);//在邻接矩阵存储弧头点
//	}
//	set<int> q;//保存读入为0的点
//	for (int i = 1; i <= n; i++) {
//		if (indeg[i] == 0)q.insert(i);
//	}
//	while (q.size() > 0) {
//		int now = *q.begin();//相当于队列top()
//		anss[cnt++] = now;//记录第一个出队列的数
//		q.erase(q.begin());//相当于队列pop()
//		//-------------
//		for (int i = 0, I = gr[now].size(); i < I; i++) {
//			int t = gr[now][i];//读取now点相连接的点
//			indeg[t] -= 1;//将此点的出度的点减1
//			if (indeg[t] == 0) {//如果此点入度为0
//				q.insert(t);//保存入度为0的点
//			}
//		}
//		//-------------
//
//	}
//	for (int i = 0; i < cnt; i++) {
//		if (i)cout << " ";
//		cout << anss[i];
//	}
//	cout << endl;
//	return 0;
//}

/*
6 8
A B C D E F
A B
A C
A D
F D
F E
D E
C B
C E


*/