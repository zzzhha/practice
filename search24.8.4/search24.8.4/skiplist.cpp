#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cstring>
#include<inttypes.h>

typedef struct Node {
	int key, level;
	struct Node* next, * down, * up;
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
	return (rand() % MAX_RAND_N)*1.0/MAX_RAND_N;

	#undef MAX_RAND_N
}

int randlevel(skiplist* s) {
	int level = 1;
	double p = 1.0 / 2.0;
	while (randdouble() < p) {
		level++;
	}
	return min(s->max_level, level);
}


void insert(skiplist* s, int x) {
	int level = randlevel(s);
	while (s->head->level +1< level)
	{
		s->head = s->head->up;
	}
	Node* node = getNewNode(x, level);
	Node* p = s->head;
	while (p->level != node->level)p = p->down;
	while (p) {
		while (p->next->key < node->key)p = p->next;
		node->next = p->next;
		p->next = node;
		p = p->down;
		node = node->down;
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

