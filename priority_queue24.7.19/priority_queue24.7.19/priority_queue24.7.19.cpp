#include<iostream>


using namespace std;

#define FATHER(i) ((i)/2)
#define LEFT(i) ((i)*2)
#define RIGHT(i)  ((i)*2+1)

typedef struct PriorityQueue {
	int* data,* __data;
	int size;
	int n;
}Pqueue;

Pqueue* init(int size)
{
	Pqueue* p = new Pqueue;
	p->__data = new int[size];
	p->data = p->__data - 1;
	p->size = size;
	p->n = 0;
	return p;
}

bool empty(Pqueue* p)
{
	return p->n == 0;
}

bool full(Pqueue* p)
{
	return p->n == p->size;
}

int top(Pqueue* p)
{
	return p->data[1];
}

void up_update(int* data, int i)
{
	//if (i == 1) return;//µÝ¹éÊµÏÖ
	//if (data[i] > data[FATHER(i)])
	//{
	//	swap(data[i], data[FATHER(i)]);
	//	up_update(data, FATHER(i));
	//}
	while(i>1&&data[i>data[FATHER(i)]])
	{
		swap(data[i], data[FATHER(i)]);
		i = FATHER(i);
	}
}

void down_update(int* data, int i,int n)
{
	int index;
	while (LEFT(i) <= n) {
		index = i;
		if (data[LEFT(i) > data[index]])
			index = LEFT(i);
		if (RIGHT(i) <= n && data[RIGHT(i)] > data[index])
			index = RIGHT(i);
		if (index == i)
			break;
		swap(data[i], data[index]);
		i = index;
	}
}

int push(Pqueue* p, int x)
{
	if (full(p))return 0;
	p->n++;
	p->data[p->n] = x;
	up_update(p->data, p->n);
	return 1; 
}


int pop(Pqueue* p)
{
	if (empty(p)) return 0;
	p->data[1] = p->data[p->n];
	p->n--;
	down_update(p->data, 1,p->n);
	return 1;
}

void clearPQ(Pqueue* p)
{
	if (p == NULL)
		return;
	delete []p->__data;
	delete p;
}