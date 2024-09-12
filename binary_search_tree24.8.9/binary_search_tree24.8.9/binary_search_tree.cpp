#include<iostream>




typedef struct Node {
	int key;
	struct Node* lchild, * rchild;
};


Node* getNewNode(int key) {
	Node* p = new Node;
	p->key = key;
	p->lchild = p->rchild = NULL;
	return p;
}

Node* insert(Node* root,int key) {
	if (root==NULL)return getNewNode(key);
	if (key == root->key) return root;
	if (key < root->key) root->lchild = insert(root->lchild, key);
	else
		root->rchild = insert(root->rchild, key);
	return root;

}

Node* predecessor(Node* root) {//搜索前驱
	Node* temp = root->lchild;
	while (temp->rchild)temp = temp->rchild;
	return temp;
}


Node* erase(Node* root, int key) {
	if (root == NULL) return root;
	if (key < root->key)    root->lchild = erase(root->lchild, key);
	else if(key>root->key)  root->rchild = erase(root->rchild, key);
	else {
		if (root->lchild == NULL && root->rchild == NULL) {
			delete root;
			return NULL;
		}
		else if (root->lchild == NULL || root->rchild == NULL){
			Node* temp = root->lchild ? root->lchild:root->rchild;
			delete root;
			return temp;
		}
		else{
			Node* temp = predecessor(root);//找到前驱节点
			root->key = temp->key;//交换节点值，也就是我们把删除度为2的节点转化成了删除一个度为1的节点
			root->lchild = erase(root->lchild, temp->key);//因为他的前驱一定在他的左子树中，所以我们向左子树递归去删除对应值。
		}
	}
	return root;
}


void clear(Node* root) {
	if (root == NULL)
		return;
	clear(root->lchild);
	clear(root->rchild);
	delete root;
	return;
}
