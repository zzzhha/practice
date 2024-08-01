#include<iostream>

using namespace std;



//双链表
typedef struct D_Node
{
	int val;
	struct D_Node* pre;
	struct D_Node* next;

}D_Node, * D_Linklist;
//Linklist ==Node* 为了增强可读性
//Linklist 强调该指针是头指针，通过保存头结点的地址，标记了整个链表
//Node* 强调该指针指向一个普通的节点

//初始化一个带头结点的空双链表
D_Linklist D_initlist()
{
	//申请一个头结点的空间，地址赋值给头指针
	D_Linklist l = new D_Node;
	l->next = NULL;//循环双链表：l->next=l
	l->pre = NULL;//循环双链表:l->pre=l
	return l;
}

//头插法插入节点
D_Linklist D_head_insert(D_Linklist p, int value)
{
	D_Node* n = new D_Node;
	n->val = value;
	//四个指针改变
	n->next = p->next;//新节点的next指向下一个节点
	if (p->next != NULL) //循环双链表p->next!=p
	{
		p->next->pre = n;//下一个节点的pre指向新节点
	}
	p->next = n;//当前节点的next指向新节点
				//循环双链表：
	n->pre = p;//新节点的pre指向当前节点
	return p;
}

//尾插法插入节点
D_Linklist D_tail_insert(D_Linklist p, int value)
{
	D_Node* cur = p;
	while (cur->next != NULL)//循环双链表cur->next!=cur
	{
		cur = cur->next;
	}
	D_Node* n = new D_Node;
	n->val = value;
	cur->next = n;
	n->next = NULL;//循环双链表n->next=p
	return p;
	
	
	return p;
}

//查找某个节点
D_Node* D_find(D_Linklist p, int x)
{
	D_Node* cur = p->next;
	while (cur->val != x && cur != NULL)//循环双链表 cur!=p
		cur = cur->next;
	return cur;
}

//中间法插入节点
D_Linklist D_mid_insert(D_Linklist p, int x, int value)
{
	D_Node* cur = D_find(p, x);
	if (cur == NULL)//循环双链表cur==p
	{
		cout << "数据不存在，无法插入" << endl;
		return p;
	}
	D_Node* n = new D_Node;
	n->val = value;
	n->next = cur->next;
	if(cur->next!=NULL)//循环双链表cur->next==p
	{
		cur->next->pre = n;
	}
	cur->next = n;
	n->pre = cur;
	return p;
}

//改变节点数据
D_Linklist D_change(D_Linklist p, int x, int value)
{
	D_Node* cur = D_find(p, x);
	if (cur == NULL)//循环双链表p==p
	{
		cout << "数据不存在，无法更改" << endl;
		return p;
	}
	cur->val = value;
	return p;
}

//判断是否为空
bool D_isempty(D_Linklist p)
{
	if (p->next == NULL)//循环双链表p->next==p
	{
		return true;
	}
	return false;
}

//删除节点
D_Linklist D_destory(D_Linklist p, int value)
{
	if (D_isempty(p))
	{
		cout << "是空链表，无法进行删除操作" << endl;
		return p;
	}
	D_Node* cur = p->next;
	D_Node* prev = p;
	while (cur->val != value && cur != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)//循环双链表cur==p
	{
		cout << "数据不存在，无法删除" << endl;
		return p;
	}
	prev->next = cur->next;
	if (cur->next != NULL)//循环双链表cur->next==p
	{
		cur->next->pre = prev;
	}
	delete cur;
	cur = NULL;
	return p;
}

//展示双链表
void D_show(D_Linklist p)
{
	D_Node* q = p->next;
	while (q != NULL)//循环双链表q!=p
	{
		cout << q->val << " ";
		q = q->next;
	}
	cout << endl;
}
//单链表
typedef struct Node
{
	int val;
	struct Node* next;

}Node,*Linklist;
//Linklist ==Node* 为了增强可读性
//Linklist 强调该指针是头指针，通过保存头结点的地址，标记了整个链表
//Node* 强调该指针指向一个普通的节点

//初始化一个带头结点的空链表
Linklist initlist()
{
	//申请一个头结点的空间，地址赋值给头指针
	Linklist l = new Node;
	l->next = NULL;//    循环单链表
	// l->next=l;
	return l;
}

//头插法插入节点
Linklist head_insert(Linklist p,int value)
{
	Node* n = new Node;
	n->val = value;
	n->next = p->next;
	p->next = n;
	return p;
}

//尾插法插入节点
Linklist tail_insert(Linklist p, int value)
{
	Node* cur = p;
	while (cur->next != NULL)
		cur = cur->next;
	Node* n = new Node;
	n->val = value;
	n->next = NULL;//循环单链表
	//n->next=l;

	cur->next = n;
	return p;
}

//查找某个节点
Node* find(Linklist p, int x)
{
	Node* cur = p->next;
	while (cur->val != x && cur != NULL)
		cur = cur->next;
	return cur;
}

//中间法插入节点
Linklist mid_insert(Linklist p, int x, int value)
{
	Node* cur = find(p, x);
	if (p == NULL)
	{
		cout << "数据不存在，无法插入" <<  endl;
	}
	else
	{
		Node* n = new Node;
		n->val = value;
		n->next = cur->next;
		cur->next = n;
	}
	return p;
}

//改变节点数据
Linklist change(Linklist p, int x, int value)
{
	Node* cur = find(p, x);
	if (p == NULL)
	{
		cout << "数据不存在，无法更改" << endl;
		return p;
	}
	cur->val = value;
	return p;
}

//判断是否为空
bool isempty(Linklist p)
{
	if (p->next == NULL)//循环单链表（p->next==l）
	{
		return true;
	}
	return false;
}

//删除节点
Linklist destory(Linklist p, int value)
{
	if (isempty(p))
	{
		cout << "是空链表，无法进行删除操作" << endl;
		return p;
	}
	Node* cur = p->next;
	Node* pre = p;
	while (cur->val !=value && cur != NULL)
	{
		pre = cur;
		cur = cur->next;
	}
	if (cur == NULL)//循环单链表 cur==l
	{
		cout << "数据不存在，无法删除" << endl;
		return p;
	}
	pre->next = cur->next;
	delete cur;
	cur = NULL;
	return p;
}

//展示链表
void show(Linklist p)
{
	Node* q = p->next;
	while (q != NULL)//循环单链表q==l
	{
		cout << q->val<<" ";
		q = q->next;
	}
	cout << endl;
}
//int main()
//{
//	Linklist l = initlist();
//	l = head_insert(l, 1);
//	l = head_insert(l, 4);
//	l = head_insert(l, 2);
//	l = head_insert(l, 6);
//	show(l);
//	l = tail_insert(l, 7);
//	show(l);
//	l = mid_insert(l, 4, 9);
//	show(l);
//	l = destory(l, 6);
//	show(l);
//	D_Linklist ll = D_initlist();
//	ll = D_head_insert(ll, 1);
//	ll = D_head_insert(ll, 4);
//	ll = D_head_insert(ll, 2);
//	ll = D_head_insert(ll, 6);
//	D_show(ll);
//	ll = D_tail_insert(ll, 7);
//	D_show(ll);
//	ll = D_mid_insert(ll, 4,9);
//	D_show(ll);
//	ll = D_destory(ll, 6);
//	D_show(ll);
//	return 0;
//}

//习题1：反转链表：
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

  struct ListNode {
      int val;
     struct ListNode *next;
  };
 
  struct ListNode* reverseList(struct ListNode* head) {
	  struct ListNode* pre = NULL;
	  struct ListNode* fwd;
	  while (head != NULL)
	  {
		  fwd = head->next;
		  head->next = pre;
		  pre = head;
		  head = fwd;
	  }
	  return pre;
  }



  //习题2 环形链表
  //给你一个链表的头节点 head ，判断链表中是否有环
  //如果链表中存在环 ，则返回 true 。 否则，返回 false 。

  bool hasCycle(struct ListNode* head) 
  {
	  struct ListNode* fast = head;
	  struct ListNode* slow = head;
	  while (fast && fast->next) {
		  fast = fast->next->next;
		  slow = slow->next;
		  if (fast == slow)
		  {
			  return true;
		  }
	  }
	  return false;
  }

  //习题3 快乐数
  //编写一个算法来判断一个数 n 是不是快乐数。
  //「快乐数」 定义为：
	 //1.对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
	 //2.然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
	 //3.如果这个过程 结果为 1，那么这个数就是快乐数。
	 //如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

  //题解：
  // 此处没有链表，但是运用到了链表的思想
  //因为根据第一步，每个数所能确定的下一个数是固定的
  //所以，我们可以根据提供的数 写出一串根据此数得出的下几个数
  //他们的顺序是固定的，一个数只能得到一个固定的数
  //所以可以近似看做单链表
  //最后一个数为1，相当于找到了链表的最后一个节点，指针域指向了NULL
  //所谓“无限循环”既是：没办法找到最后一个节点
  //即，根据习题二可得：此时的链表存在环，
  //于是可以用到环形链表的题解：快慢指针，慢指针一次进行一次1,2步
  //快指针一次进行两次1,2步
  //如果快指针等于了慢指针且快慢指针都不为1
  //那么就是形成了环，输出false
  //如果快慢指针有一个等于了1，则输出true
  int getNext(int x)
  {
	  int d, y = 0;
	  while (x)
	  {
		  d = x % 10;
		  y += d * d;
		  x /= 10;
	  }
	  return y;
  }
  bool isHappy(int n)
  {
	  int p = n, q = n;
	  while (q != 1)
	  {
		  p = getNext(p);
		  q = getNext(getNext(q));
		  if (p == q && p != 1)//等价if(p==q&&q!=1&&p!=1)
		  {
			  return false;
		  }
	  }
	  return true;
  }

  //习题4 旋转链表
  //给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

  //题解：1.第一步，因为移动k步，k无限制，所以可能超过链表大小
  // 2.举例，当k等于5的时候，就相当于链表没有改变，发生改变的只有取模的部分
  // 3.所以我们要得到链表的大小 ，然后去取模，得到改变了几个节点->此步骤从开始到 注释1
  // 4.第二步，将链表分为两个部分----部分1和部分2，以要旋转多少个节点为界限，声明两个指向头结点的指针
  // （旋转：将部分1的最后一个节点的next指向空，部分2的最后一个节点指向head，即可完成旋转）
  // 5.先让一个指针往后移动取k+1步（k为取模后的数据），在同时将两个指针后移
  // 6.当先移动的指针指向了NULL的时候，此时后移动的指针一定指向部分1的最后一个节点，他的next就是部分2的第一个节点
  // 7.将先移动的指针（此时指向了空的指针）指向后移动的指针的next（也就是部分2的第一个节点）
  //8.再将后移动的指针的next指向空（开始旋转第一步了），完成后，将后移动的指针指向部分2的第一个节点，即 将先移动的指针赋值给后移动的指针
  //9.再把后移动的指针遍历到最后一个节点（while(后移动的指针->next!=NULL))，此时，后移动的指针就指向部分2的最后一个节点
  //10.最后将后移动的指针的next指向head即可（完成旋转第二步）
  //11.最后返回部分2的第一个节点，既是新的链表的头结点
  //12.我们先移动的指针在第7步骤时，指向了部分2的第一个节点，8-11步骤全移动的是后移动的指针，未对先移动的指针进行操作
  //13.故，此时返回先移动的指针即可完成操作。
  class Solution {
  public:
	  ListNode* rotateRight(ListNode* head, int k)
	  {
		  if (head == NULL)
		  {
			  return head;
		  }
		  int count = 0;
		  ListNode* p = head;
		  while (p != NULL)
		  {
			  p = p->next;
			  count++;
		  }
		  k %= count;
		  if (k == 0)
		  {
			  return head;
		  }//1
		  ListNode* cur = head;
		  ListNode* pre = head;
		  for (int i = 0; i <= k; i++)
		  {
			  cur = cur->next;
		  }
		  while (cur)
		  {
			  cur = cur->next;
			  pre = pre->next;
		  }
		  cur = pre->next;
		  pre->next = NULL;
		  pre = cur;
		  while (pre->next != NULL)
		  {
			  pre = pre->next;
		  }
		  pre->next = head;
		  return cur;
	  }
  };
