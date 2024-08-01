#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


typedef struct Node {
	int key;
	int ltag, rtag;//如果等于1，则说明他是一个线索，如果等于0，则是一个正常的节点
	struct Node* lchild;
	struct Node* rchild;
}Node;

Node* getNewNode(int key)
{
	Node* p = new Node;
	p->key = key;
	p->ltag = p->rtag = 0;
	p->lchild = p->rchild = NULL;
	return p;
}

void pre_order(Node* root)
{
	if (root == NULL)
		return;
	cout << root->key<<" ";
	if (root->ltag == 0)pre_order(root->lchild);
	if (root->rtag == 0)pre_order(root->rchild);
}

void in_order(Node* root)
{
	if (root == NULL)
		return;
	if (root->ltag == 0)in_order(root->lchild);
	cout << root->key << " ";
	if (root->rtag == 0)in_order(root->rchild);
}

void post_order(Node* root)
{
	if (root == NULL)
		return;
	if (root->ltag == 0)post_order(root->lchild);
	if (root->rtag == 0)post_order(root->rchild);
	cout << root->key << " ";
}

Node* insert(Node* root, int key)
{
	if (root == NULL)
		return getNewNode(key);
	if (rand() % 2) root->lchild = insert(root->lchild, rand() % 100);
	else  root->rchild = insert(root->rchild, rand() % 100);
	return root;
}

void clear(Node*p)
{
	if (p == NULL)
		return;
	if (p->ltag == 0) clear(p->lchild);
	if (p->rtag == 0) clear(p->rchild);
	delete p;
}

Node* pre_node = NULL, *inorder_root = NULL;
void __build_in_order_thread(Node* root)//线索化：将有空指针的节点，指向相应的前驱或者后继，
										//用ltag和rtag来表明此节点是否有前驱和后继
										//使其树状结构能像链表一样操作
{
	if (root == NULL) return;
	if (root->ltag == 0) __build_in_order_thread(root->lchild);
	if (inorder_root == NULL) inorder_root = root;
	if (root->lchild == NULL) 
	{
		root->lchild = pre_node;
		root->ltag = 1;
	}
	if (pre_node && pre_node->rchild == NULL)
	{
		pre_node->rchild = root;
		pre_node->rtag = 1;
	}
	pre_node = root;
	//cout << root->key << " ";//此语句打印当前节点的数据，根据此语句能找到当前的节点，进行线索化
	if (root->rtag == 0)__build_in_order_thread(root->rchild);
}

void build_in_order_thread(Node* root)
{
	__build_in_order_thread(root);
	pre_node->rchild = NULL;
	pre_node->rtag = 1;
}

Node* getNext(Node* root)//找下一个节点
{
	if (root->rtag == 1) return root->rchild;//判断此节点的右孩子是节点还是线索，如果是线索，那么就返回线索
	root = root->rchild;//如果不是线索，则证明有右孩子，令root指向下一个右孩子
	while (root->ltag == 0 && root->lchild)
	{
		root = root->lchild;//根据中序遍历（左根右），把当前节点视作根节点，
							//那么下一个打印的数据一定是当前假根节点的右子树的最左边的叶子（在没有线索化的情况下是叶子节点）节点
							//为什么：此时递归进行到这里的时候，是已经进行过左遍历了（因为是左根右）
							//我们判定的时候是在进行“根”的时候进行的，所以会进行下一步触发“右”孩子的递归，
							//进入下一个递归时，又开始无限进行“左”递归，知道指向空，
							//也就是所谓的右子树的最左叶子（叶子同上）节点
							//这样就可以找到当前节点的下一个节点了
	}
	return root;

}


int main()
{
	srand((unsigned)time(0));
	Node* root = NULL;
	for (int i = 0; i < 10; i++)
	{
		root = insert(root, rand() % 100);
	}
	pre_node =inorder_root =NULL;
	build_in_order_thread(root);
	pre_order(root);
	cout << endl;
	in_order(root);
	cout << endl;
	post_order(root);
	cout << endl;

	//现在此树经过线索化 变得像链表了
	Node* node = inorder_root;
	while (node) 
	{
		cout << node->key << " ";
		node = getNext(node);

	}
	cout << endl;
	clear(root);
	return 0;
}