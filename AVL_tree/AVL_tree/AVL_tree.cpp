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
	root->h = (geth(root->lchild) > geth(root->lchild) ? geth(root->lchild) : geth(root->lchild) ) + 1;
	return;
}

//旋转操作：四种失衡情况的调整函数，左右旋都是站在父亲节点上更新
//LL--以失衡节点x 进行左旋
AVLNode* LL_rotation(AVLNode* x) {//左旋
	AVLNode* y = x->rchild;//原根的右子树作为新根节点，此时原根的右子树空出来了
	x->rchild = y->lchild;//新根的左子树变为原根的右子树，此时新根的左子树空出来了
	y->lchild = x;//原根作为新根的左子树
	update_height(x);//更新原根的高度
	update_height(y);//更新新根的高度
	return y;
}

AVLNode* RR_rotation(AVLNode* x) {//右旋
	AVLNode* y = x->lchild;//原根的左子树作为新根节点，此时原根的左子树空出来了
	x->lchild = y->rchild;//原根的右子树就是新根的左子树，此时新根的右子树空出来了
	y->rchild = x;//原根节点作为新根的右子树
	update_height(x);
	update_height(y);
	return y;
}



AVLNode* maintain(AVLNode* root){
	if (abs(geth(root->lchild)) - geth(root->lchild) <= 1)return root;
	if (geth(root->lchild) >geth(root->rchild)) {//如果左子树高度高于右子树高度，需要右旋，则判断右旋类型
		if (geth(root->lchild->rchild) > geth(root->lchild->lchild))//如果是左子树的右子树高，则失衡类型为LR
			//则需要先进行小的左旋，再进行大的右旋
		{
			root->lchild = LL_rotation(root->lchild);
		}
		//如果为LL类型就直接进行右旋
		root = RR_rotation(root);
	}
	else
	{
		if (geth(root->rchild->lchild) > geth(root->rchild->rchild))//如果是右子树的左子树高，则失衡类型为RL
			//则需要先进性小的右旋，再进行大左旋
		{
			root->rchild = RR_rotation(root->rchild);
		}
		//如果为RR则直接进行左旋
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




AVLNode* predecessor(AVLNode* root) {//找前驱
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
