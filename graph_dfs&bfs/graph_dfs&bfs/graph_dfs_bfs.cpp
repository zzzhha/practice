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
}G[105];//�ڽӱ�



char v[105];
int g[105][105];//�ڽӾ���
int flag[105];//flag[i]==0 iδ�����ʣ�i=1�����ʹ�
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

//DFS��˼·
// 1.������㣬���ǣ����Ϊ�ѷ���״̬
// 2.�ҵ�һ��v��δ�����ʹ����ڽӵ�x������x����x��Ϊ�ѷ���״̬
// 3.�ҵ�һ��x��δ�����ʵ��ڽӵ㣬ѭ��2.3��ֱ��ĳ����û��δ�����ʵ��ڽӵ㣬��ʱ��ʼ������һ��
//һֱѭ��2��3����ֱ�����еĵ㶼��������Ϊֹ  
//�ڽӾ��������ͼ ����DFS ʱ�临�Ӷ� O(|V|^2) 
//�ڽӱ��ͼ ����DFS ʱ�临�Ӷ� O��|V|+|E|��
void DFS(int i) {//������ȱ���
	cout << G[i].data<< " ";
	flag[i] = 1;
	//for (int j = 0; j < n; j++) {//�ڽӾ���
	//	if (g[i][j] == 1 && flag == 0) {
	//		DFS(j);//����
	//	}
	//}
	Node* p = G[i].first;
	while (p) {
		if (!flag[p->data])
			DFS(p->data);
		p = p->next;
	}//�ڽӱ�
}

//BFS��˼·
//1.����һ�����У���������
//2.������
//3.����ѭ����������зѿأ�����Ԫ�س��ң����ʸ����ݣ��Ѹ��������Ӱ��ϰ����ڽӵ����
//ֱ������Ϊ�գ�������������ͼ����ͨͼ��

int head, tail;
void BFS(int i) {//������ȱ���
	
	head, tail = 0;

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		//cin >> v[i];
		cin >> G[i].data;
		G[i].first = nullptr;
	}//�ڽӾ���/�ڽӱ�
	char x, y;
	for (int i = 0; i < m; i++) {
		
		cin >> x >> y;
		//int xi = _find(x);
		//int yi = _find(y);//�ڽӾ���
		int xi = find(x);
		int yi = find(y);
		//g[xi][yi] =g[yi][xi] = 1;//�ڽӾ���
		Node* p = new Node;
		p->data = y;
		p->next = G[xi].first;
		G[xi].first = p;

		Node* e = new Node;
		e->data = x;
		e->next = G[yi].first;
		G[yi].first = e;//�ڽӱ�����ͼ
		
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