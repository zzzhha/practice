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

//��ת����������ʧ������ĵ�������������������վ�ڸ��׽ڵ��ϸ���
//LL--��ʧ��ڵ�x ��������
AVLNode* LL_rotation(AVLNode* x) {//����
	AVLNode* y = x->rchild;//ԭ������������Ϊ�¸��ڵ㣬��ʱԭ�����������ճ�����
	x->rchild = y->lchild;//�¸�����������Ϊԭ��������������ʱ�¸����������ճ�����
	y->lchild = x;//ԭ����Ϊ�¸���������
	update_height(x);//����ԭ���ĸ߶�
	update_height(y);//�����¸��ĸ߶�
	return y;
}

AVLNode* RR_rotation(AVLNode* x) {//����
	AVLNode* y = x->lchild;//ԭ������������Ϊ�¸��ڵ㣬��ʱԭ�����������ճ�����
	x->lchild = y->rchild;//ԭ���������������¸�������������ʱ�¸����������ճ�����
	y->rchild = x;//ԭ���ڵ���Ϊ�¸���������
	update_height(x);
	update_height(y);
	return y;
}



AVLNode* maintain(AVLNode* root){
	if (abs(geth(root->lchild)) - geth(root->lchild) <= 1)return root;
	if (geth(root->lchild) >geth(root->rchild)) {//����������߶ȸ����������߶ȣ���Ҫ���������ж���������
		if (geth(root->lchild->rchild) > geth(root->lchild->lchild))//��������������������ߣ���ʧ������ΪLR
			//����Ҫ�Ƚ���С���������ٽ��д������
		{
			root->lchild = LL_rotation(root->lchild);
		}
		//���ΪLL���;�ֱ�ӽ�������
		root = RR_rotation(root);
	}
	else
	{
		if (geth(root->rchild->lchild) > geth(root->rchild->rchild))//��������������������ߣ���ʧ������ΪRL
			//����Ҫ�Ƚ���С���������ٽ��д�����
		{
			root->rchild = RR_rotation(root->rchild);
		}
		//���ΪRR��ֱ�ӽ�������
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




AVLNode* predecessor(AVLNode* root) {//��ǰ��
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
