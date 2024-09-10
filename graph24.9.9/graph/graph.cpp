#include<iostream>
#include<algorithm>
using namespace std;

//边集数组法 -->思维简单，但是是效率不高，所以不用
struct wuxiangbian {
	int x;
	int y;
	int weight;
}wubianji[100];//存边集

struct youxianbian {
	int start;
	int end;
	int weight;
}youbianji[100];
int dianji[100];///存点集
//边集数组法
//int main() {
//	//记录数据
//	int x, int y, int w;
//	for (int i = 0; i < 100; i++) {
//		cin >> x >> y >> w;
//		wubianji[i].x = x;
//		wubianji[i].y = y;
//		wubianji[i].weight = w;
//	}
//	for (int i = 0; i < 100; i++) {
//		cin >> x >> y >> w;
//		youbianji[i].start = x;
//		youbianji[i].end = y;
//		youbianji[i].weight = w;
//	}
//	for (int i = 0; i < 100; i++) {
//		cin >> dianji[i];
//	}
//	//寻找一个端点的度
//	cin >> x;
//	for (int i = 0; i < 100; i++) {
//		if (wubianji[i].x == x || wubianji[i].y == x) {
//			cout << "haha";
//		}
//	}
//	//寻找一个有向边的出度
//	for (int i = 0; i < 100; i++) {
//		if (youbianji[i].start == x ) {
//			cout << "haha";
//		}
//	}
//	return 0;
//}




//邻接矩阵  ---->用二维数组存图		缺点 浪费空间 如果有10000个点，10条边 我们需要开e[10000][10000]的数组
char v[105];//点集
int e[105][105];//存边
//有向图 
//带权图 
//
// e[x][y]=w1 一条从点x到点y的边，权值为w1; 
// e[y][x]=w2 一条从点y到点x的边，权值为w2;
//w有范围一般是1~100 在这个范围内算是有边，超过了这个数据就是没边，一般设 INF 101 为无边


//无权图：
//e[x][y]=0; 没有一条从点x到点y的边
//e[x][y]=1; 存在一条从点x到点y的边

//无向图
//一条边要反向存两次，就是把一条无向边 看成两条方向相反权值相等的有向边
//e[x][y]=e[y][x]=w/1;w代表有权值，判断于上方相同，1代表无权值。

//邻接矩阵 ->带权无向图
#define INF 101

int find(char x,int n) {
	for (int i = 0; i < n; i++) {
		if (v[i] == x) {
			return i;
		}
	}
	return -1;
}

//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i <= n; i++) {
//		cin >> v[i];
//	}
//	int w;
//	char x, y;
//	//初始化
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			e[i][j] = INF;
//			if (i == j)
//			{
//				e[i][j] = 0;
//			}
//		}
//	}
//	//一次性读入
//	for (int i = 0; i < m; i++) {
//		cin >> x >> y >> w;
//		int xi = find(x,m);
//		int yi = find(y,m);
//		e[xi][yi] = e[yi][xi] = w; 
//	}
//	//找到某个端点的度
//	cin >> x;
//	int d = 0;
//	int xi = find(x,105);
//	for (int i = 0; i < n; i++) {
//		if (e[xi][i] < INF && xi!=i) {
//			d++;
//		}
//	}
//	return 0;
//}


//邻接表：
//带权无向图
struct Node {
	int key;//临界点标号
	int w;//权值
	struct Node* next;
}ei[105];//边集
struct Vertex {
	char data;//顶点数据
	Node* first;//指向该点的邻接表数据
}G[105];
//此处有向表存端点当弧尾时的情况（存 出边）
//如果需要求入度可以建立逆邻接表（存 入边）
//无向表则两个端点都存 例如边v1v3，则在v1存放v3，在v3存放v1（头插法）

//邻接表：
//带权无向图
int _find(char x, int n) {
	for (int i = 0; i < n; i++) {
		if (G[i].data == x) {
			return i;
		}
	}
	return -1;
}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> G[i].data;
//		G[i].first = nullptr;
//	}
//	int x, y, w;
//	for (int i = 0; i < m; i++) {
//		cin >> x >> y >> w;
//		int xi = _find(x,n);
//		int yi = _find(y, n);
//		//无向图得差两次 x--->y y---->x
//		Node* p = new Node;
//		p->key = yi;//表示此边的出度的下标是结构体数组的哪一个
//		p->w = w;
//		p->next = G[xi].first;
//		G[xi].first = p;
//		//有向图此处不要
//		Node* p = new Node;
//		p->key = xi;
//		p->w = w;
//		p->next = G[yi].first;
//		G[xi].first = p;
//	}
//	//求x的度
//	cin >> x;
//	int d = 0;
//	int xi = _find(x,105);
//	Node* s = G[xi].first;
//	while (s) {
//		d++;
//		s = s->next;
//	}
//	return 0;
//}



//十字链表 只适用于 有向图 是对有向图的邻接表的优化
//通过把有向图的邻接表和逆邻接表合并起来，并且一条边及时其弧尾顶点的出边，也是其虎头顶点的入边
//所以代表一条边的链表节点 要插入到两条链表中，构成了十字链表，既方便求出度也方便求入度

struct ten_linklist {
	int rvex;
	struct ten_linklist* rnext;//弧尾
	int hvex;
	struct ten_linklist* hnext;//弧头
	int w;
};//边集
struct point{
	char data;
	ten_linklist* firstin;//出度的指针，对标弧尾
	ten_linklist* firstout;//入度的指针，对标弧头
}g[105];//点集
int __find(char x, int n) {
	for (int i = 0; i < n; i++) {
		if (g[i].data == x) {
			return i;
		}
	}
	return -1;
}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> g[i].data;
//		g[i].firstin=g[i].firstout = nullptr;
//	}
//	int x, y, w;
//	for (int i = 0; i < m; i++) {
//		cin >> x >> y >> w;
//		int xi = __find(x,n);
//		int yi = __find(y, n);
//
//		ten_linklist* p = new ten_linklist;
//		p->rvex = xi;
//		p->hvex = yi;
//		p->w = w;
//		//把节点s插入到x的出边单链表
//		p->rnext = g[xi].firstout;
//		g[xi].firstout = p;
//		//把节点s插入到y的入边单链表
//		p->hnext = g[yi].firstin;
//		g[yi].firstin = p;
//	}
//	//求x的出度和入度
//	cin >> x;
//	int ind = 0, outd = 0;
//	int xi = find(x, 105);
//	ten_linklist* s = g[xi].firstout;
//	while (s) {
//		outd++;
//		s = s->rnext;
//	}
//	cin >> y;
//	int yi = __find(x, 105);
//	s = g[yi].firstin;
//	while (s) {
//		ind++;
//		s = s->hnext;
//	}
//	return 0;
//}

//多重邻接表 用于无向图跟十字链表相似，也是改进邻接表用来存储
struct double_Next {
	int i, j;
	double_Next* inext, *jnext;
	int w;
};
struct duo {
	char data;
	double_Next* first;
}h[105];//点集
int _find_(char x, int n) {
	for (int i = 0; i < n; i++) {
		if (h[i].data == x) {
			return i;
		}
	}
	return -1;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> g[i].data;
		h[i].first = nullptr;
	}
	int x, y, w;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		int xi = _find_(x,n);
		int yi = _find_(y, n);

		double_Next* p = new double_Next;
		p->i = xi;
		p->j = yi;
		p->w = w;

		p->inext = h[xi].first;
		h[xi].first = p;

		p->jnext = h[yi].first;
		h[yi].first = p;
	}
	//求x的出度和入度
	cin >> x;
	int d = 0 ;
	int xi = _find_(x, 105);
	double_Next* s = h[xi].first;
	while (s) {
		d++;
		if (s->i == xi)
			s = s->inext;
		if (s->j == xi)
			s = s->jnext;
	}
	
	return 0;
}
