#include<iostream>
#include<algorithm>
using namespace std;

//�߼����鷨 -->˼ά�򵥣�������Ч�ʲ��ߣ����Բ���
struct wuxiangbian {
	int x;
	int y;
	int weight;
}wubianji[100];//��߼�

struct youxianbian {
	int start;
	int end;
	int weight;
}youbianji[100];
int dianji[100];///��㼯
//�߼����鷨
//int main() {
//	//��¼����
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
//	//Ѱ��һ���˵�Ķ�
//	cin >> x;
//	for (int i = 0; i < 100; i++) {
//		if (wubianji[i].x == x || wubianji[i].y == x) {
//			cout << "haha";
//		}
//	}
//	//Ѱ��һ������ߵĳ���
//	for (int i = 0; i < 100; i++) {
//		if (youbianji[i].start == x ) {
//			cout << "haha";
//		}
//	}
//	return 0;
//}




//�ڽӾ���  ---->�ö�ά�����ͼ		ȱ�� �˷ѿռ� �����10000���㣬10���� ������Ҫ��e[10000][10000]������
char v[105];//�㼯
int e[105][105];//���
//����ͼ 
//��Ȩͼ 
//
// e[x][y]=w1 һ���ӵ�x����y�ıߣ�ȨֵΪw1; 
// e[y][x]=w2 һ���ӵ�y����x�ıߣ�ȨֵΪw2;
//w�з�Χһ����1~100 �������Χ�������бߣ�������������ݾ���û�ߣ�һ���� INF 101 Ϊ�ޱ�


//��Ȩͼ��
//e[x][y]=0; û��һ���ӵ�x����y�ı�
//e[x][y]=1; ����һ���ӵ�x����y�ı�

//����ͼ
//һ����Ҫ��������Σ����ǰ�һ������� �������������෴Ȩֵ��ȵ������
//e[x][y]=e[y][x]=w/1;w������Ȩֵ���ж����Ϸ���ͬ��1������Ȩֵ��

//�ڽӾ��� ->��Ȩ����ͼ
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
//	//��ʼ��
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			e[i][j] = INF;
//			if (i == j)
//			{
//				e[i][j] = 0;
//			}
//		}
//	}
//	//һ���Զ���
//	for (int i = 0; i < m; i++) {
//		cin >> x >> y >> w;
//		int xi = find(x,m);
//		int yi = find(y,m);
//		e[xi][yi] = e[yi][xi] = w; 
//	}
//	//�ҵ�ĳ���˵�Ķ�
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


//�ڽӱ�
//��Ȩ����ͼ
struct Node {
	int key;//�ٽ����
	int w;//Ȩֵ
	struct Node* next;
}ei[105];//�߼�
struct Vertex {
	char data;//��������
	Node* first;//ָ��õ���ڽӱ�����
}G[105];
//�˴�������˵㵱��βʱ��������� ���ߣ�
//�����Ҫ����ȿ��Խ������ڽӱ��� ��ߣ�
//������������˵㶼�� �����v1v3������v1���v3����v3���v1��ͷ�巨��

//�ڽӱ�
//��Ȩ����ͼ
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
//		//����ͼ�ò����� x--->y y---->x
//		Node* p = new Node;
//		p->key = yi;//��ʾ�˱ߵĳ��ȵ��±��ǽṹ���������һ��
//		p->w = w;
//		p->next = G[xi].first;
//		G[xi].first = p;
//		//����ͼ�˴���Ҫ
//		Node* p = new Node;
//		p->key = xi;
//		p->w = w;
//		p->next = G[yi].first;
//		G[xi].first = p;
//	}
//	//��x�Ķ�
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



//ʮ������ ֻ������ ����ͼ �Ƕ�����ͼ���ڽӱ���Ż�
//ͨ��������ͼ���ڽӱ�����ڽӱ�ϲ�����������һ���߼�ʱ�仡β����ĳ��ߣ�Ҳ���仢ͷ��������
//���Դ���һ���ߵ�����ڵ� Ҫ���뵽���������У�������ʮ�������ȷ��������Ҳ���������

struct ten_linklist {
	int rvex;
	struct ten_linklist* rnext;//��β
	int hvex;
	struct ten_linklist* hnext;//��ͷ
	int w;
};//�߼�
struct point{
	char data;
	ten_linklist* firstin;//���ȵ�ָ�룬�Ա껡β
	ten_linklist* firstout;//��ȵ�ָ�룬�Ա껡ͷ
}g[105];//�㼯
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
//		//�ѽڵ�s���뵽x�ĳ��ߵ�����
//		p->rnext = g[xi].firstout;
//		g[xi].firstout = p;
//		//�ѽڵ�s���뵽y����ߵ�����
//		p->hnext = g[yi].firstin;
//		g[yi].firstin = p;
//	}
//	//��x�ĳ��Ⱥ����
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

//�����ڽӱ� ��������ͼ��ʮ���������ƣ�Ҳ�ǸĽ��ڽӱ������洢
struct double_Next {
	int i, j;
	double_Next* inext, *jnext;
	int w;
};
struct duo {
	char data;
	double_Next* first;
}h[105];//�㼯
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
	//��x�ĳ��Ⱥ����
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
