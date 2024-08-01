#include<iostream>

using namespace std;



//˫����
typedef struct D_Node
{
	int val;
	struct D_Node* pre;
	struct D_Node* next;

}D_Node, * D_Linklist;
//Linklist ==Node* Ϊ����ǿ�ɶ���
//Linklist ǿ����ָ����ͷָ�룬ͨ������ͷ���ĵ�ַ���������������
//Node* ǿ����ָ��ָ��һ����ͨ�Ľڵ�

//��ʼ��һ����ͷ���Ŀ�˫����
D_Linklist D_initlist()
{
	//����һ��ͷ���Ŀռ䣬��ַ��ֵ��ͷָ��
	D_Linklist l = new D_Node;
	l->next = NULL;//ѭ��˫����l->next=l
	l->pre = NULL;//ѭ��˫����:l->pre=l
	return l;
}

//ͷ�巨����ڵ�
D_Linklist D_head_insert(D_Linklist p, int value)
{
	D_Node* n = new D_Node;
	n->val = value;
	//�ĸ�ָ��ı�
	n->next = p->next;//�½ڵ��nextָ����һ���ڵ�
	if (p->next != NULL) //ѭ��˫����p->next!=p
	{
		p->next->pre = n;//��һ���ڵ��preָ���½ڵ�
	}
	p->next = n;//��ǰ�ڵ��nextָ���½ڵ�
				//ѭ��˫����
	n->pre = p;//�½ڵ��preָ��ǰ�ڵ�
	return p;
}

//β�巨����ڵ�
D_Linklist D_tail_insert(D_Linklist p, int value)
{
	D_Node* cur = p;
	while (cur->next != NULL)//ѭ��˫����cur->next!=cur
	{
		cur = cur->next;
	}
	D_Node* n = new D_Node;
	n->val = value;
	cur->next = n;
	n->next = NULL;//ѭ��˫����n->next=p
	return p;
	
	
	return p;
}

//����ĳ���ڵ�
D_Node* D_find(D_Linklist p, int x)
{
	D_Node* cur = p->next;
	while (cur->val != x && cur != NULL)//ѭ��˫���� cur!=p
		cur = cur->next;
	return cur;
}

//�м䷨����ڵ�
D_Linklist D_mid_insert(D_Linklist p, int x, int value)
{
	D_Node* cur = D_find(p, x);
	if (cur == NULL)//ѭ��˫����cur==p
	{
		cout << "���ݲ����ڣ��޷�����" << endl;
		return p;
	}
	D_Node* n = new D_Node;
	n->val = value;
	n->next = cur->next;
	if(cur->next!=NULL)//ѭ��˫����cur->next==p
	{
		cur->next->pre = n;
	}
	cur->next = n;
	n->pre = cur;
	return p;
}

//�ı�ڵ�����
D_Linklist D_change(D_Linklist p, int x, int value)
{
	D_Node* cur = D_find(p, x);
	if (cur == NULL)//ѭ��˫����p==p
	{
		cout << "���ݲ����ڣ��޷�����" << endl;
		return p;
	}
	cur->val = value;
	return p;
}

//�ж��Ƿ�Ϊ��
bool D_isempty(D_Linklist p)
{
	if (p->next == NULL)//ѭ��˫����p->next==p
	{
		return true;
	}
	return false;
}

//ɾ���ڵ�
D_Linklist D_destory(D_Linklist p, int value)
{
	if (D_isempty(p))
	{
		cout << "�ǿ������޷�����ɾ������" << endl;
		return p;
	}
	D_Node* cur = p->next;
	D_Node* prev = p;
	while (cur->val != value && cur != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)//ѭ��˫����cur==p
	{
		cout << "���ݲ����ڣ��޷�ɾ��" << endl;
		return p;
	}
	prev->next = cur->next;
	if (cur->next != NULL)//ѭ��˫����cur->next==p
	{
		cur->next->pre = prev;
	}
	delete cur;
	cur = NULL;
	return p;
}

//չʾ˫����
void D_show(D_Linklist p)
{
	D_Node* q = p->next;
	while (q != NULL)//ѭ��˫����q!=p
	{
		cout << q->val << " ";
		q = q->next;
	}
	cout << endl;
}
//������
typedef struct Node
{
	int val;
	struct Node* next;

}Node,*Linklist;
//Linklist ==Node* Ϊ����ǿ�ɶ���
//Linklist ǿ����ָ����ͷָ�룬ͨ������ͷ���ĵ�ַ���������������
//Node* ǿ����ָ��ָ��һ����ͨ�Ľڵ�

//��ʼ��һ����ͷ���Ŀ�����
Linklist initlist()
{
	//����һ��ͷ���Ŀռ䣬��ַ��ֵ��ͷָ��
	Linklist l = new Node;
	l->next = NULL;//    ѭ��������
	// l->next=l;
	return l;
}

//ͷ�巨����ڵ�
Linklist head_insert(Linklist p,int value)
{
	Node* n = new Node;
	n->val = value;
	n->next = p->next;
	p->next = n;
	return p;
}

//β�巨����ڵ�
Linklist tail_insert(Linklist p, int value)
{
	Node* cur = p;
	while (cur->next != NULL)
		cur = cur->next;
	Node* n = new Node;
	n->val = value;
	n->next = NULL;//ѭ��������
	//n->next=l;

	cur->next = n;
	return p;
}

//����ĳ���ڵ�
Node* find(Linklist p, int x)
{
	Node* cur = p->next;
	while (cur->val != x && cur != NULL)
		cur = cur->next;
	return cur;
}

//�м䷨����ڵ�
Linklist mid_insert(Linklist p, int x, int value)
{
	Node* cur = find(p, x);
	if (p == NULL)
	{
		cout << "���ݲ����ڣ��޷�����" <<  endl;
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

//�ı�ڵ�����
Linklist change(Linklist p, int x, int value)
{
	Node* cur = find(p, x);
	if (p == NULL)
	{
		cout << "���ݲ����ڣ��޷�����" << endl;
		return p;
	}
	cur->val = value;
	return p;
}

//�ж��Ƿ�Ϊ��
bool isempty(Linklist p)
{
	if (p->next == NULL)//ѭ��������p->next==l��
	{
		return true;
	}
	return false;
}

//ɾ���ڵ�
Linklist destory(Linklist p, int value)
{
	if (isempty(p))
	{
		cout << "�ǿ������޷�����ɾ������" << endl;
		return p;
	}
	Node* cur = p->next;
	Node* pre = p;
	while (cur->val !=value && cur != NULL)
	{
		pre = cur;
		cur = cur->next;
	}
	if (cur == NULL)//ѭ�������� cur==l
	{
		cout << "���ݲ����ڣ��޷�ɾ��" << endl;
		return p;
	}
	pre->next = cur->next;
	delete cur;
	cur = NULL;
	return p;
}

//չʾ����
void show(Linklist p)
{
	Node* q = p->next;
	while (q != NULL)//ѭ��������q==l
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

//ϰ��1����ת����
//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������

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



  //ϰ��2 ��������
  //����һ�������ͷ�ڵ� head ���ж��������Ƿ��л�
  //��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��

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

  //ϰ��3 ������
  //��дһ���㷨���ж�һ���� n �ǲ��ǿ�������
  //���������� ����Ϊ��
	 //1.����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
	 //2.Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
	 //3.���������� ���Ϊ 1����ô��������ǿ�������
	 //��� n �� ������ �ͷ��� true �����ǣ��򷵻� false ��

  //��⣺
  // �˴�û�������������õ��������˼��
  //��Ϊ���ݵ�һ����ÿ��������ȷ������һ�����ǹ̶���
  //���ԣ����ǿ��Ը����ṩ���� д��һ�����ݴ����ó����¼�����
  //���ǵ�˳���ǹ̶��ģ�һ����ֻ�ܵõ�һ���̶�����
  //���Կ��Խ��ƿ���������
  //���һ����Ϊ1���൱���ҵ�����������һ���ڵ㣬ָ����ָ����NULL
  //��ν������ѭ�������ǣ�û�취�ҵ����һ���ڵ�
  //��������ϰ����ɵã���ʱ��������ڻ���
  //���ǿ����õ������������⣺����ָ�룬��ָ��һ�ν���һ��1,2��
  //��ָ��һ�ν�������1,2��
  //�����ָ���������ָ���ҿ���ָ�붼��Ϊ1
  //��ô�����γ��˻������false
  //�������ָ����һ��������1�������true
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
		  if (p == q && p != 1)//�ȼ�if(p==q&&q!=1&&p!=1)
		  {
			  return false;
		  }
	  }
	  return true;
  }

  //ϰ��4 ��ת����
  //����һ�������ͷ�ڵ� head ����ת����������ÿ���ڵ������ƶ� k ��λ�á�

  //��⣺1.��һ������Ϊ�ƶ�k����k�����ƣ����Կ��ܳ��������С
  // 2.��������k����5��ʱ�򣬾��൱������û�иı䣬�����ı��ֻ��ȡģ�Ĳ���
  // 3.��������Ҫ�õ�����Ĵ�С ��Ȼ��ȥȡģ���õ��ı��˼����ڵ�->�˲���ӿ�ʼ�� ע��1
  // 4.�ڶ������������Ϊ��������----����1�Ͳ���2����Ҫ��ת���ٸ��ڵ�Ϊ���ޣ���������ָ��ͷ����ָ��
  // ����ת��������1�����һ���ڵ��nextָ��գ�����2�����һ���ڵ�ָ��head�����������ת��
  // 5.����һ��ָ�������ƶ�ȡk+1����kΪȡģ������ݣ�����ͬʱ������ָ�����
  // 6.�����ƶ���ָ��ָ����NULL��ʱ�򣬴�ʱ���ƶ���ָ��һ��ָ�򲿷�1�����һ���ڵ㣬����next���ǲ���2�ĵ�һ���ڵ�
  // 7.�����ƶ���ָ�루��ʱָ���˿յ�ָ�룩ָ����ƶ���ָ���next��Ҳ���ǲ���2�ĵ�һ���ڵ㣩
  //8.�ٽ����ƶ���ָ���nextָ��գ���ʼ��ת��һ���ˣ�����ɺ󣬽����ƶ���ָ��ָ�򲿷�2�ĵ�һ���ڵ㣬�� �����ƶ���ָ�븳ֵ�����ƶ���ָ��
  //9.�ٰѺ��ƶ���ָ����������һ���ڵ㣨while(���ƶ���ָ��->next!=NULL))����ʱ�����ƶ���ָ���ָ�򲿷�2�����һ���ڵ�
  //10.��󽫺��ƶ���ָ���nextָ��head���ɣ������ת�ڶ�����
  //11.��󷵻ز���2�ĵ�һ���ڵ㣬�����µ������ͷ���
  //12.�������ƶ���ָ���ڵ�7����ʱ��ָ���˲���2�ĵ�һ���ڵ㣬8-11����ȫ�ƶ����Ǻ��ƶ���ָ�룬δ�����ƶ���ָ����в���
  //13.�ʣ���ʱ�������ƶ���ָ�뼴����ɲ�����
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
