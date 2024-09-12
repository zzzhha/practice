#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cstring>
#include<inttypes.h>

typedef struct Node {
	int key, level;//key存关键值，level存储 级数（当前数据是第几层的数）
	struct Node* next, * down, * up;//next指向当前层数的下一个数据，down存储当前key值的上一级层数的，up存储下一级层数
}Node;

#define MAX_LEVEL 32
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct Skiplist {
	Node* head, * tail;
	int max_level;
}skiplist;

Node* getNewNode(int key,int n) {
	Node* nodes = new Node[n];
	for (int i = 0; i < n; i++) {
		nodes[i].key = key;
		nodes[i].level = i;
		nodes[i].next = NULL;
		nodes[i].down = (i ? nodes + (i - 1) : NULL);
		nodes[i].up = (i + 1 < n ? nodes + (i + 1) : NULL);
	}
	return nodes + n - 1;
}

skiplist* getNEwskiplist(int n) {
	skiplist* s= new skiplist;
	s->head = getNewNode(INT32_MIN,n);
	s->tail = getNewNode(INT32_MAX,n);
	Node* p = s->head, * q = s-> tail;
	s->max_level = n;
	while (p)
	{
		p->next = q;
		p = p->down, q=q->down;
	}
	while (s->head->level != 0) {
		s->head = s->head->down;
	}
	return s;
}

Node* find(skiplist* s, int x) {
	Node* p = s->head;
	while (p && p->key != x) {
		if (p->next->key <= x)
			p = p->next;
		else
			p = p->down;
	}
	return p;
}

double randdouble() {
	#define MAX_RAND_N 1000000
	return (rand() % MAX_RAND_N)*1.0/MAX_RAND_N;//随机一个数，先求模是为了他大于MAX，在求除是为了控制在0~1

	#undef MAX_RAND_N
}

int randlevel(skiplist* s) {
	int level = 1;
	double p = 1.0 / 2.0;//随机设置的一个数，如果小于次数层数增加，如果大于就返回
	while (randdouble() < p) {
		level++;
	}
	return min(s->max_level, level);//这里控制level不能超过跳跃表的最高层数
}


void insert(skiplist* s, int x) {
	int level = randlevel(s);
	while (s->head->level +1< level)//从0开始，直到level层，此时head层level一定不小于level
	{
		s->head = s->head->up;
	}
	Node* node = getNewNode(x, level);//建立一个新节点，层高为level
	Node* p = s->head;//p指向刚刚找到的等高的起始节点
	while (p->level != node->level)p = p->down;//防止p的level高于node节点的，让他往下，如果不高就不进行
	while (p) {//一层循环完成一层链表的链接
		while (p->next->key < node->key)p = p->next;//如果小于就往后指
		node->next = p->next;//开始插入节点
		p->next = node;//插入完毕

		p = p->down;//p往下指
		node = node->down;//node往下指
	}
	return;

}


void clearNode(Node* p) {
	if (p == NULL) return;
	delete []p;
	return;
}

void clearskiplist(skiplist *s) {
	Node* p = s->head, *q;
	while (p->level != 0)p = p->down;
	while (p) {
		q = p->next;
		clearNode(p);
		p = q;
	}
	delete s;
}


int main() {
	srand(time(0));
	return 0;
}

