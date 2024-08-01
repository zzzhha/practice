#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//typedef struct NODE
//{
//	int val;
//	struct NODE* next;
//}Node;
//
//Node* getNewNode(int val)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	if (p != NULL)
//	{
//		p->val = val;
//		p->next = NULL;
//		return p;
//	}
//	return NULL;
//}
//
//void clear(Node* head)
//{
//	Node* temp;
//	for (Node* p = head; p != NULL; )
//	{
//		temp = p;
//		p = p->next;
//		free(temp);
//	}
//}
//Node* insert(Node* head,int val,int pos)
//{
//	Node* p = getNewNode(val);
//	if (p == NULL)
//	{
//		printf("创造链表失败，未能成功创造新链表\n");
//		return head;
//	}
//	if(pos==0)
//	{
//		p->next = head;
//		return p;
//	}
//	Node* tmp = head;
//	for (int i = 0; i < pos; i++) tmp = tmp->next;
//	p->next = tmp->next;
//	tmp->next = p;
//	return head;
//}
//int insertpriornode(Node* pp, int val)
//{
//	if (pp == NULL)
//	{
//		printf("节点不存在\n");
//		return 0;
//	}
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->next = pp->next;
//	p->val = pp->val;
//	pp->next = p;
//	pp->val = val;
//	return 1;
//}
//
//int deletedestnode(Node* pp)
//{
//	if (pp == NULL)
//	{
//		printf("节点不存在\n");
//		return 0;
//	}
//	if(pp->next!=NULL)
//	{//思想：把pp后一个节点的数据next指针复制到pp节点，删除pp节点的后一个节点
//		Node* p = pp->next;//p指向pp的后一个节点
//		pp->val = p->val;//把后一个节点的数据赋值到pp上
//		pp->next = p->next;//pp的next指向后继点的next
//		free(p);//释放后继结点
//		return 1;
//	}
//	else//如果pp是最后一个节点 
//	{
//		return 0;
//	}
//}
//void print_node(Node* head)
//{
//	if(head=NULL)
//	{
//		printf("链表不存在\n");
//		return;
//	}
//	Node* p = head->next;
//	while (p != NULL)
//	{
//		printf("%d ", p->val);
//		p = p->next;
//	}
//	printf("\n");
//}


//反转链表的实现

//Node* reverse_node(Node* current)
//{
//	Node* next;
//	Node* pre = NULL;
//	while(current!=NULL)
//	{
//		next = current->next;
//		current->next = pre;
//		pre = current;
//		current = next;
//	}
//	return current;
//}
//leetcode206代码
//struct ListNode* reverseList(struct ListNode* head) {
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//	struct ListNode* tail = head->next;
//	struct ListNode* new_head = reverseList(head->next);
//	head->next = tail->next;
//	tail->next = head;
//	return new_head;
//leetcode141代码
// bool hasCycle(struct ListNode *head) {
//struct ListNode* fast = head;
//struct ListNode* slow = head;
//while (fast && fast->next) {
//	fast = fast->next->next;
//	slow = slow->next;
//	if (fast == slow)
//	{
//		return true;
//	}
//}
//return false;
//}
// 
//}
//---------------------------------以上是单链表的实现----------------------------
//---------------------------------下面是循环链表的实现--------------------------------------

typedef struct cir_node {
	int val;
	struct cir_node* nextnode;
}cirnode;


cirnode* init_cirnode(cirnode*head)
{
	head = (cirnode*)malloc(sizeof(cirnode));
	head->nextnode = head;
}
cirnode* getnew_cirnode(int val)
{
	cirnode* p = (cirnode*)malloc(sizeof(cirnode));
	if (p == NULL)//返回空说明创造失败
		return NULL;
	p->val = val;
	p->nextnode = NULL;
	return p;
}
void cirnode_insert_r(cirnode* head, int val)
{
	cirnode* r = head;
	cirnode* p = (cirnode*)malloc(sizeof(cirnode));
	p->val = val; 
	r->nextnode = p;
	r = p;
	r->nextnode = head;
}
cirnode* cirnode_insert(cirnode*head,int pos,int val)
{
	cirnode* tmp = head;
	int i = 0;
	for (; i < pos; i++) tmp = tmp->nextnode;
	if (!tmp || i > pos)
	{
		printf("插入失败！");
		return head;
	}
	cirnode* p = getnew_cirnode(val);
	p->nextnode = tmp->nextnode;
	tmp->nextnode = p;
	return head;
}

int destory_cirnode(cirnode* head)
{
	cirnode* tmp = head->nextnode;
	cirnode* p;
	while (tmp != head)
	{
		p = tmp;
		tmp = tmp->nextnode;
		free(p);
	}
	head->nextnode = NULL;
	return 1;
}
//----------------------------循环单链表实现---------------------------------------
//----------------------------队列用顺序表实现版---------------------------
//typedef struct vector {//一个顺序表
//	int size;
//	int* data;
//	int count;
//}vector;
//
//vector* initVector(int n)
//{
//	vector* p = (vector*)malloc(sizeof(vector));
//	p->data = (int*)malloc(sizeof(int) * n);
//	p->size = n;
//	p->count = 0;
//	return p;
//}
//
//int insertVector(vector* p, int tail, int val)
//{
//	if (tail < 0 || tail >= p->size) return 0;
//	p->data[tail] = val;
//	p->count++;
//	return 1;
//}
//
//int vectorSeek(vector* p, int head)
//{
//	if (head<0 || head>=p->size) return -1;
//	if (head>=p->count)
//	{
//		return -1;
//	}
//	return p->data[head];
//}
//
//void clearVector(vector* p)
//{
//	if (p == NULL) return;
//	free(p->data);
//	free(p);
//}
//
//typedef struct Queue {
//	vector* data;
//	int size;
//	int head;
//	int tail;
//	int count;
//}Queue;
//
//
//Queue* initQueue(int n)
//{
//	Queue* p = (Queue*)malloc(sizeof(Queue));
//	p->data = initVector(n);
//	p->size = n;
//	p->head = p->tail = p->count = 0;
//	return p;
//}
//
//int empty(Queue* q)
//{
//	return q->count == 0;
//}
//
//int push(Queue* q, int val)
//{
//	if (q->count == q->size) return 0;
//	insertVector(q->data,q->tail, val);
//	q->tail += 1;
//	if (q->tail == q->size) q->tail = 0;
//	q->count++;
//	return 1;
//}
//
//int front(Queue* q)
//{
//	int i = vectorSeek(q->data, q->head);
//	if (i == -1)
//		return 0;
//	else 
//		return i;
//}
//
//int pop(Queue* q)
//{
//	if (empty(q)) return 0;
//	//eraseVector(q->data,q->head);
//	q->head += 1;
//	if (q->head == q->size) q->head = 0;
//	q->count--;
//	return 1;
//}
//
//void clearQueue(Queue* q)
//{
//	if (q == NULL) return;
//	clearVector(q->data);
//	free(q);
//	return;
//}
//
//void outputQueue(Queue* q)
//{
//	printf("Queue:");
//	for (int i = 0; i < q->count; i++)
//	{
//		printf("%4d", vectorSeek(q->data, (q->head + i) % q->size));
//	}
//	printf("\n\n");
//}
//int main()
//{
//	srand(time(0));
//	#define MAX 10
//	Queue* q = initQueue(5);
//	for (int i = 0; i < MAX; i++)
//	{
//		int op = rand() % 5;//0,1:pop |2,3,4:push
//		int val = rand() % 100;
//		int ret;
//		switch (op)
//		{
//		case 0:
//		case 1:
//			if ((ret=front(q)) == 0)
//				printf("队列为空\n");
//			else
//				printf("front of queue:%d\n", ret);
//			pop(q);
//			break;
//		case 2:
//		case 3:
//		case 4:
//			printf("push %d to queue\n", val);
//			push(q, val);
//			break;
//		}
//		outputQueue(q);
//	}
//	clearQueue(q);
//}
//----------------------------队列用顺序表实现版---------------------------
//----------------------------队列用链表实现版---------------------------

typedef struct Node{
	int data;
	struct Node* next;

}Node;


Node* getNewNode(int val)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = val;
	p->next = NULL;
	return p;
}
typedef struct LinkList {
	Node head;//有头链表的实现
	Node* tail;
}LinkList;


int emptyList(LinkList* l)
{
	return l->head.next == NULL;
}
int frontList(LinkList* l)
{
	if (emptyList(l)) return 0;
	return l->head.next->data;
}

int insertTail(LinkList* l, int val) {
	Node* node = getNewNode(val);
	l->tail->next = node;
	l->tail = node;
	return 1;
}

int eraseHead(LinkList* l)
{
	if (emptyList(l)) return 0;
	Node* p = l->head.next;
	l->head.next = l->head.next->next;
	if (p == l->tail)
		l->tail = &(l->head);
	free(p);
	return 1;

}

LinkList* initLinkList()
{
	LinkList* l = (LinkList*)malloc(sizeof(LinkList));
	l->head.next = NULL;
	l->tail = &(l->head);
	return l;
}

void clearLinkList(LinkList* l)
{
	Node* p= l->head.next;
	Node* q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	free(l);
}
typedef struct Queue{
	LinkList* l;
	int size;
	int count;
}Queue;

Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->l = initLinkList();
	q->count = 0;
	return q;
}

int empty(Queue* q)
{
	return q->count == 0;
}

int front(Queue* q)
{
	if (empty(q)) return 0;
	return frontList(q->l);
}

int push(Queue* q,int val)
{
	insertTail(q->l, val);
	q->count++;
	return 1;
}

int pop(Queue* q)
{
	eraseHead(q->l);
	q->count--;
	return 1;
}

void clearQueue(Queue* q)
{
	if (q == NULL) return;
	clearLinkList(q->l);
	free(q);
}

void outputQueue(Queue* q)
{
	printf("Queue:");
	Node* p = q->l->head.next;
	for (int i = 0; i < q->count; i++,p=p->next)
	{
		printf("%4d", p->data);
	}
	printf("\n\n");
}

int main()
{
	srand(time(0));
#define MAX 10
	Queue* q = initQueue();
	for (int i = 0; i < MAX; i++)
	{
		int op = rand() % 5;//0,1:pop |2,3,4:push
		int val = rand() % 100;
		int ret;
		switch (op)
		{
		case 0:
		case 1:
			if ((ret = front(q)) == 0)
				printf("队列为空\n");
			else
				printf("front of queue:%d\n", ret);
			pop(q);
			break;
		case 2:
		case 3:
		case 4:
			printf("push %d to queue\n", val);
			push(q, val);
			break;
		}
		outputQueue(q);
	}
	clearQueue(q);
}