#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

#define RED 0
#define BLACK 1
#define DBLACK 2
#define NIL (&__NIL)
#define K(n) (n->key)
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define C(n) (n->color)
typedef struct Node {
	int key;
	struct Node * lchild, * rchild;
	int color;//0->red 1->black 2->double black
}node;

node __NIL= { -1,NIL,NIL,BLACK };
node* getNewNode(int key) {
	node* p = new(nothrow)node;
	if (p == NULL)
	{
		cout << "申请内存失败";
		exit(0);
	}
	p->key = key;
	p->color = RED;
	p->lchild = p->rchild = NIL;
	return p;
}

bool has_red_node(node* root) {
	return root->lchild->color == RED || root->rchild->color == RED;
}

node* left_rotate(node* root) {
	node* new_root = root->rchild;
	root->rchild = new_root->lchild;
	new_root->lchild = root;
	return new_root;
}

node* right_rotate(node* root) {
	node* new_root = root->lchild;
	root->lchild = new_root->rchild;
	new_root->rchild = root;
	return new_root;
}

node* insert_maintain(node* root) {
	int flag = 0;
	if (C(L(root))==RED && has_red_node(L(root))) flag = 1;
	if (C(R(root))==RED && has_red_node(R(root))) flag = 2;
	if (flag == 0) return root;
	if (C(L(root)) == RED && C(R(root)) == RED) {
		C(root) = RED;
		C(L(root))=C(R(root)) = BLACK;
		return root;
	}
	if (flag == 1) {
		if (C(R(L(root))) == RED)
		{
			L(root) = left_rotate(L(root));
		}
		root = right_rotate(root);
	}
	else
	{
		if (C(L(R(root))) == RED)
		{
			R(root) = right_rotate(R(root));
		}
		root = left_rotate(root);
	}
	C(root) = RED;//红色上浮方法
	C(L(root)) = C(R(root)) = BLACK;
	return root;
}


node* __insert(node* root, int key) {
	if (root == NIL) return getNewNode(key);
	if (root->key == key)return root;
	if (key < root->key) root->lchild = __insert(root->lchild, key);
	else root->rchild = __insert(root->rchild, key);
	return insert_maintain(root);
}

node* insert(node* root, int key) {
	root=__insert(root, key);
	root->color = BLACK;
	return root;
}

void clear(node* root) {
	if (root == NIL) return;
	clear(root->lchild);
	clear(root->rchild);
	delete root;
	return;
}

void output(node* root) {
	if (root == NIL)return;
	cout << "(" << C(root) << "| " <<K(root) << " " << K(L(root)) << " " << K(R(root)) << ")"<<endl;
	output(root->lchild);
	output(root->rchild);
	return;
}

int main()
{
	srand(time(0));
#define MAX_N 10
	node *root = NIL;
	for (int i = 0; i < MAX_N; i++) {
		int x = rand() % 100;
		cout << "insert " << x << " to red black tree :" << endl;
		root = insert(root, x); 
		output(root);
	}

	return 0;
}