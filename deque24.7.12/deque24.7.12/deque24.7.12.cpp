#include<iostream>

//双端队列
typedef struct Deque{
	int* data;
	int l, r;
	int sum;//元素个数
}deque;

int maxx = 10;
deque init_()
{
	deque p ;
	p.l = 0;
	p.r = 0;
	p.sum = 0;
	return p;
}

void left_insert(deque *q,int val)
{
	if (q->sum == maxx)
		return;
	q->data[q->l--] = val;
	q->l = (q->l+maxx) % maxx;
	q->sum++;
}

void right_insert(deque* q,int val)
{
	if (q->sum == maxx)
		return;
	q->r = (q->r+1) % maxx;
	q->data[q->r] = val;
	q->sum++;
}

void left_dele(deque* q)
{
	int x;
	if (q->sum == 0)
		return;
	// = q->data[(q->l + 1) % maxx];
	q->l = (q->l + 1) % maxx;
	q->sum--;
}
void right_dele(deque* q)
{
	int x;
	if (q->sum == 0)
		return;
	//x = q->data[(q->r) % maxx];
	q->r = (q->r - 1) % maxx;
	q->sum--;
}
void pri(deque* q)
{
	int i;
	i = (q->l + 1) % maxx;
	while (i != q->r + 1)
	{
		printf("%d", q->data[i]);
		i = (i + 1) % maxx;
	}
	printf("\n");
}
typedef struct qNode {
	int data;
	struct qNode* next;
	struct qNode* pre;
}qNode;

typedef struct D_deque {
	struct qNode* l;
	struct qNode* r;
}Dqueue;

D_deque initDqueue()
{
	Dqueue q;
	q.l = q.r = new qNode;
	q.l->next = NULL;
	q.l->pre = NULL;
	return q;
}

void left_insert(Dqueue* q, int k)
{
	qNode* s = new qNode;
	s->data = k;
	s->pre = NULL;
	q->l->next = s;
	s -> next = q->l;
	q->l = s;
}

void right_insert(Dqueue* q, int k)
{
	q->r->data = k;
	qNode* s = new qNode;
	q->r->next = s;
	s->next = NULL;
	s->pre = q->r;
	q->r = s;
}


void left_de(Dqueue* q)
{
	if (q->l == q->r)
		return;
	qNode* p = q->l;
	q->l = q->l->next;
	q->l->pre = p->pre;
	delete p;
}

void right_de(Dqueue* q)
{
	if (q->l == q->r)
		return;
	qNode* p=q->r;
	q->r = q->r->pre;
	q->r->next = NULL;
	delete p;

}

