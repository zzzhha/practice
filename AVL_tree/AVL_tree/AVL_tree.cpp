#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
typedef struct AVLNode {
	int key;
	struct AVLNode* lchild, * rchild;
	int h;
}AVLNode,*AVLTree;

#define H(n) (n->h)
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define K(n) (n->key)

AVLNode* getNewNode(int key) {
	AVLNode* p = new AVLNode;
	p->key = key;
	p->lchild = p->rchild = NULL;
	p->h = 1;
	return p;
}



int geth(AVLNode* root) {
	if (root == NULL)
		return 0;
	else
		return root->h;
}

void update_height(AVLNode* root) {
	root->h = geth(root->lchild) > geth(root->lchild) ? geth(root->lchild) : geth(root->lchild) + 1;
	return;
}

//旋转操作：四种失衡情况的调整函数
//LL--以失衡节点x 进行左旋
AVLNode* LL_rotation(AVLNode* x) {
	AVLNode* y = x->rchild;//新的根节点
	x->rchild = y->lchild;//原根的右子树就是新根的左子树
	y->lchild = x;//新根的左子树是原根节点
	update_height(x);
	update_height(y);
	return y;
}

AVLNode* RR_rotation(AVLNode* x) {
	AVLNode* y = x->lchild;//新的根节点
	x->lchild = y->rchild;//原根的左子树就是新根的右子树
	y->rchild = x;//新根的右子树是原根节点
	update_height(x);
	update_height(y);
	return y;
}



AVLNode* maintain(AVLNode* root){
	if (abs(geth(root->lchild)) - geth(root->lchild) <= 1)return root;
	if (geth(root->lchild) >geth(root->rchild)) {
		if (geth(root->rchild->lchild) > geth(root->lchild->lchild))
		{
			root->lchild = LL_rotation(root->lchild);
		}
		root = RR_rotation(root);
	}
	else
	{
		if (geth(root->lchild->rchild) > geth(root->rchild->rchild))
		{
			root->rchild = RR_rotation(root->rchild);
		}
		root = LL_rotation(root);
	}
	return root;
}

AVLNode* insert(AVLNode* root, int key) {
	if (root == NULL)
	{
		getNewNode(key);
	}
	if (key == root->key) 
		return root;
	if (key < root->key) 
	{
		root->lchild = insert(root->lchild, key);
	}
	else
	{
		root->rchild = insert(root->rchild, key);
	}
	update_height(root);
	return maintain(root);

}




AVLNode* predecessor(AVLNode* root) {
	AVLNode* temp = root->lchild;
	while (temp->rchild!=NULL)temp = temp->rchild;
	return temp;
}


AVLNode* erase(AVLNode* root, int key) {
	if (root == NULL) return root;
	if (key < root->key)    root->lchild = erase(root->lchild, key);
	else if (key > root->key)  root->rchild = erase(root->rchild, key);
	else {
		
		if (root->lchild == NULL || root->rchild == NULL) {
			AVLNode* temp = root->lchild ? root->lchild : root->rchild;
			delete root;
			return temp;
		}
		else {
			AVLNode* temp = predecessor(root);
			root->key = temp->key;
			root->lchild = erase(root->lchild, temp->key);
		}
	}
	update_height(root);
	return maintain(root);
}


void clear(AVLNode* root) {
	if (root == NULL)
		return;
	clear(root->lchild);
	clear(root->rchild);
	delete root;
	return;
}
