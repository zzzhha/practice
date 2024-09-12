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
	//if (i == 1) return;//递归实现
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


int pop(Pqueue* p)//头部弹出元素，把data【1】位置的元素弹出，然后n--，所以可以把堆的最后一个元素直接赋给第一个元素
//既达到了弹出头部元素的需求，又满足了n--，因为把最后一个元素给了data[1]所以可能会破坏堆的结构性质，所以要进行向下调整
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