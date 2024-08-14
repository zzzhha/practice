#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;


#define FATHER(i) ((i)/2)
typedef struct Node {
	char ch;//字符
	int freq;//字符出现的频次，堆排序依据
	struct Node* lchild, * rchild;//二叉树节点
}Node;

typedef struct Heap {//堆
	Node** __data,**data;//使用偏移量，__data指向实际存储区域，data指向逻辑存储区域
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

int find_min_node(Node** node_arr, int n)//找到最小频率的下标
{
	int ind = 0;
	for (int j = 1; j <= n; j++) {
		if (node_arr[ind]->freq > node_arr[j]->freq)
			ind = j;
	}
	return ind;
}

Node* buildHaffmanTree(Node** node_arr, int n) {
	//Heap* h = getNewHeap(n);//堆和优先队列
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
	for (int i = 1; i < n; i++) {//堆和优先队列可以优化
		int ind1 = find_min_node(node_arr, n - i);//找到倒数第一的最小频率的下标
		swap_node(node_arr, ind1, n - i); //把他放到数组后面相应位置
		int ind2 = find_min_node(node_arr, n - i - 1);//找到第二小的频率下标
		swap_node(node_arr, ind1, n - i - 1);//把它放到数组后面的相应位置
		int freq = node_arr[n - i]->freq + node_arr[n - i - 1]->freq;//统计这两个节点的频率之和
		Node* node = getNewNode(freq, 0);//创建一个新节点，频率等于这俩节点之和
		node->lchild = node_arr[n - i - 1];//左节点指向第二小
		node->rchild = node_arr[n - i];//右节点指向最小
		node_arr[n - i - 1] = node;//合并这两个节点，即：使新的节点插入数组
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
	buff[k] = 0;//代表所有的一下编码都从0开始
	if ((root->lchild == NULL) && (root->rchild == NULL)) {//如果是叶子结点那么我们就打印当节点的值
		char_code[root->ch] = _strdup(buff);//提取到字符编码就将此字符编码拷贝到相应位置
		printf("%c:%s\n", root->ch, buff);
		return;
	}
	buff[k] = '0';
	extraHaffmanCode(root->lchild, buff, k + 1);//向左子树遍历则哈夫曼编码加0
	buff[k] = '1';
	extraHaffmanCode(root->rchild, buff, k + 1);//向右子树遍历则哈弗曼编码加1
	return;
}
int main() {
	char s[10];
	int n, freq;
	cin >> n;
	Node** node_arr = new(nothrow) Node * [n];
	if (node_arr)
	{
		cout << "无法申请这么多内存" << endl;
		return 0;
	}
	else
	{
		cout << "申请成功" << endl;
	}
	for (int i = 0; i < n; i++) {
		cin >> s >> freq;
		node_arr[i] = getNewNode(freq, s[0]);
	}
	Node* root = buildHaffmanTree(node_arr, n);
	char buff[1000];
	extraHaffmanCode(root, buff, 0);//第三个参数代表当前我们从路径提取到的前缀的长度，一开始为0（哈夫曼编码是从0开始的变长编码，所以放0）
	for (int i = 0; i < 128; i++)
	{
		if (char_code[i] == NULL)
			continue;
		printf("%c:%s", i, char_code[i]);
	}
	return 0;
}