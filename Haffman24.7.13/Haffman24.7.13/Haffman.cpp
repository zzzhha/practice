#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;


#define FATHER(i) ((i)/2)
typedef struct Node {
	char ch;//�ַ�
	int freq;//�ַ����ֵ�Ƶ�Σ�����������
	struct Node* lchild, * rchild;//�������ڵ�
}Node;

typedef struct Heap {//��
	Node** __data,**data;//ʹ��ƫ������__dataָ��ʵ�ʴ洢����dataָ���߼��洢����
	int n, size;
}Heap;

Heap* getNewHeap(int size)
{
	Heap* h = new Heap;
	h->__data = new Node*;
	h->data = h->__data - 1;
	h->n = 0;
	h->size = size;
	return h;
}

bool fullHeap(Heap* h) {
	return h->n == h->size;
}

int emptyHeap(Heap* h)
{
	return h->n == 0;
}

Node* top(Heap* h)
{
	if (emptyHeap(h))return NULL;
	return h->data[1];
}

int cmpHeap(Heap* h, int i, int j)
{
	return h->data[i]->freq < h->data[j]->freq;
}


void up_maintain(Heap* h, int i)
{
	while (i > 1 && cmpHeap(h,i,i/2))
	{
		swap(h->data[i], h->data[FATHER(i)]);
		i = FATHER(i);
	}
}

void down_maintain(Heap* h, int i)
{
	while (i*2<=h->n)
	{
		int ind = i, l = i * 2, r = i * 2 + 1;
		if (cmpHeap(h,l, ind)) ind = l;
		if (r <= h->n && cmpHeap(h, r, ind))ind = r;
		if (ind == i)break;
		swap(h->data[i], h->data[ind]);
		i = ind;
	}
	return;
}

int pushHeap(Heap* h, Node* n)
{
	if (fullHeap(h))return 0;
	h->n++;
	h->data[h->n] = n;
	up_maintain(h, h->n);
	return 1;
}

int popHeap(Heap* h)
{
	if (emptyHeap(h))return 0;
	h->data[1] = h->data[h->n];
	h->n--;
	down_maintain(h, 1);
	return 1;
}

void clearHeap(Heap* h)
{
	if (h == NULL)
		return;
	delete[]h->__data;
	delete h->data;
}

Node* getNewNode(int freq, char ch) {
	Node* p = new Node;
	p->ch = ch;
	p->freq = freq;
	p->lchild = p->rchild = NULL;
	return p;
}
void swap_node(Node** node_arr, int i, int j)
{
	Node* temp = node_arr[i];
	node_arr[i] = node_arr[j];
	node_arr[j] = temp;
}

int find_min_node(Node** node_arr, int n)//�ҵ���СƵ�ʵ��±�
{
	int ind = 0;
	for (int j = 1; j <= n; j++) {
		if (node_arr[ind]->freq > node_arr[j]->freq)
			ind = j;
	}
	return ind;
}

Node* buildHaffmanTree(Node** node_arr, int n) {
	//Heap* h = getNewHeap(n);//�Ѻ����ȶ���
	//for (int i = 0; i < n; i++)
	//{
	//	pushHeap(h, node_arr[i]);
	//}
	//for (int i = 1; i < n; i++)
	//{
	//	Node* node1 = top(h);
	//	popHeap(h);
	//	Node* node2 = top(h);
	//	popHeap(h);
	//	Node* node3 = getNewNode(node1->freq + node2->freq, 0);
	//	node3->lchild = node1;
	//	node3->rchild = node2;
	//	pushHeap(h, node3);
	//}
	//Node* ret = top(h);
	//clearHeap(h);
	//return ret;
	for (int i = 1; i < n; i++) {//�Ѻ����ȶ��п����Ż�
		int ind1 = find_min_node(node_arr, n - i);//�ҵ�������һ����СƵ�ʵ��±�
		swap_node(node_arr, ind1, n - i); //�����ŵ����������Ӧλ��
		int ind2 = find_min_node(node_arr, n - i - 1);//�ҵ��ڶ�С��Ƶ���±�
		swap_node(node_arr, ind1, n - i - 1);//�����ŵ�����������Ӧλ��
		int freq = node_arr[n - i]->freq + node_arr[n - i - 1]->freq;//ͳ���������ڵ��Ƶ��֮��
		Node* node = getNewNode(freq, 0);//����һ���½ڵ㣬Ƶ�ʵ��������ڵ�֮��
		node->lchild = node_arr[n - i - 1];//��ڵ�ָ��ڶ�С
		node->rchild = node_arr[n - i];//�ҽڵ�ָ����С
		node_arr[n - i - 1] = node;//�ϲ��������ڵ㣬����ʹ�µĽڵ��������
	}
	return node_arr[0];
}

void clear(Node* root) {
	if (root == NULL) return;
	clear(root->lchild);
	clear(root->lchild);
	delete root;
}

char* char_code[128]{ 0 };
void extraHaffmanCode(Node* root, char buff[], int k) {
	buff[k] = 0;//�������е�һ�±��붼��0��ʼ
	if ((root->lchild == NULL) && (root->rchild == NULL)) {//�����Ҷ�ӽ����ô���Ǿʹ�ӡ���ڵ��ֵ
		char_code[root->ch] = _strdup(buff);//��ȡ���ַ�����ͽ����ַ����뿽������Ӧλ��
		printf("%c:%s\n", root->ch, buff);
		return;
	}
	buff[k] = '0';
	extraHaffmanCode(root->lchild, buff, k + 1);//������������������������0
	buff[k] = '1';
	extraHaffmanCode(root->rchild, buff, k + 1);//������������������������1
	return;
}
int main() {
	char s[10];
	int n, freq;
	cin >> n;
	Node** node_arr = new(nothrow) Node * [n];
	if (node_arr)
	{
		cout << "�޷�������ô���ڴ�" << endl;
		return 0;
	}
	else
	{
		cout << "����ɹ�" << endl;
	}
	for (int i = 0; i < n; i++) {
		cin >> s >> freq;
		node_arr[i] = getNewNode(freq, s[0]);
	}
	Node* root = buildHaffmanTree(node_arr, n);
	char buff[1000];
	extraHaffmanCode(root, buff, 0);//��������������ǰ���Ǵ�·����ȡ����ǰ׺�ĳ��ȣ�һ��ʼΪ0�������������Ǵ�0��ʼ�ı䳤���룬���Է�0��
	for (int i = 0; i < 128; i++)
	{
		if (char_code[i] == NULL)
			continue;
		printf("%c:%s", i, char_code[i]);
	}
	return 0;
}