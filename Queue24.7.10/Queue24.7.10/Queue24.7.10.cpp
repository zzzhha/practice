#include<iostream>

using namespace std;


//用链表实现队列：
//链表的实现
typedef struct Node
{
	int data;
	struct Node* next;
}node;

typedef struct LinkList {
	node head;
	node* tail;
}LinkList;

LinkList* Initlinklist()
{
	LinkList* l = new LinkList;
	l->head.next = NULL;
	l->tail = &(l->head);
	return l;
}

node* getNode(int val)
{
	node* p = new node;
	p->data = val;
	p->next = NULL;
	return p;
}

bool emptylist(LinkList* l)
{
	return l->head.next == NULL;
}
int frontlist(LinkList* l)
{
	if (l->head.next == NULL)
		return 0;
	return l->head.next->data;
}

int inserttail(LinkList* l, int val)
{
	node* p = getNode(val);
	l->tail->next = p;
	l->tail = p;
	return 1;
}

int erasehead(LinkList* l)
{
	if (emptylist(l))
	{
		return 0;
	}
	node* p = l->head.next;
	l->head.next = l->head.next->next;
	if (p == l->tail)
		l->tail = &(l->head);
	delete p;
	return 1;
}


void clearlinklist(LinkList* l)
{
	node* p = l->head.next;
	node* q;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	delete l;
}




//队列的实现


typedef struct Lqueue {
	LinkList* l;//链表头指针
	int count;
}lqueue;

lqueue* LinitQueue()
{
	lqueue* p = new lqueue;
	p->l = Initlinklist();
	p->count = 0;

}

bool lempty(lqueue* q)
{
	return q->count == 0;
}

int lfront(lqueue* q)
{
	if (lempty(q))
		return -1;
	return frontlist(q->l);
}

int lpush(lqueue* q,int val)
{
	inserttail(q->l, val);
	q->count++;
	return 1;
}

int lpop(lqueue* q)
{
	if(lempty(q))
		return -1;
	erasehead(q->l);
	q->count++;
	return 1;
}

void clearlqueue(lqueue* q)
{
	if (q == NULL)
		return;
	clearlinklist(q->l);
	delete q;
	return;
}

//用顺序表实现队列：
//顺序表的实现
typedef struct Vector
{
	int* data;
	int count;
	int length;
}vector;
vector* Initvector(int n)
{
	vector* p = new vector;
	p->data = new int[n];
	p->length = n;
	p->count = 0;
}

bool vector_empty(vector* p)
{
	if (p->count == 0)
		return true;
	return false;
}

int VectorSeek(vector* p, int n)
{
	if (vector_empty(p)||n>=p->count||n<0)
		return -1;
	return p -> data[n];

}

bool insertVector(vector* p, int n, int val)
{
	if (p->count==p->length)
		return false;
	if (n < 0 || n >= p->length)
		return false;
	p->data[n] = val;
	p->count++;
	return true;
}

void clearVector(vector* p)
{
	if (p == NULL)
	{
		return;
	}
	delete[]p->data;
	delete p;
}

//队列的实现
typedef struct Queue {
	vector* data;
	int size, head, tail, count;
}queue;

Queue* initQueue(int n)
{
	Queue* p = new Queue;
	p->data = Initvector(n);
	p->size = n;
	p->count = 0;
	p->head = 0;
	p->tail = 0;
	return p;
}

bool empty(Queue *q)
{
	return q->count == 0;
}

int front(Queue* q)
{
	return VectorSeek(q->data, q->head);
}

bool push(Queue* q,int val)
{
	if (q->count == q->size)
		return false;
	insertVector(q->data, q->tail,val);
	q->tail += 1;
	if (q->tail == q->size)
		q->tail = 0;
	q->count-=1;
	q->head += 1;
	return true;
}

bool pop(Queue* q)
{
	if (empty(q))
		return false;
	q->head += 1;
	return 1;
}

void clearQueue(Queue* q)
{
	if (empty(q))
		return;
	clearVector(q->data);
	delete q;
}