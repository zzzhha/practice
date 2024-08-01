#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef struct Node {
	int key;
	struct Node* lchild;//left 也可以
	struct Node* rchild;//right 也可以

}Node;

Node* getNewNode(int key)
{
	Node* p = new(Node);
	p->key = key;
	p->lchild = p->rchild = NULL;
	return p;
}

Node* insert(Node* root,int key)//随机插入左右叶子结点
{
	if (root == NULL) return getNewNode(key);
	if (rand() % 2) root->lchild = insert(root->lchild,key);//当rand为1的时候，进入此递归，将根节点的左孩子，视作下一次递归的根节点（“子树”），进行插入
	else root->rchild = insert(root->rchild,key);//同上
	//if就可以完成“根/子根 左右”、“根/子根 右左”共四种的插入方法
	return root;
}

void clear(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	clear(root->lchild);
	clear(root->rchild);
	delete root;
}

Node* queue[15];
int head, tail;
void bfs(Node* root)
{
	head = tail = 0;
	queue[tail++] = root;
	while (head < tail)
	{
		Node* node = queue[head];
		cout << endl<<"node:" << node->key;
		if (node->lchild) 
		{
			queue[tail++] = node->lchild;
			cout << "\t" << node->key<<"->"<<node->lchild->key<<"(left)" << endl;
		}
	
		if (node->rchild) 
		{
			queue[tail++] = node->rchild;
			cout << "\t" << node->key << "->" << node->rchild->key << "(right)" << endl;
		}
		head++;
	}
}
int tot = 0;
void dfs(Node* root)
{
	if (root == NULL)
		return;
	int start, end;
	tot += 1 ;
	start = tot;
	if (root->lchild) dfs(root->lchild);
	if (root->rchild) dfs(root->rchild);
	tot += 1;
	end = tot;
	printf("%d:[%d,%d]\n", root->key, start, end);
}
int main()
{
	srand(time(0));
	Node* root = NULL;
	for (int i = 0; i < 10; i++)
	{
		root = insert(root, rand() % 100);
	}
	bfs(root);
	cout << endl;
	cout << endl;
	dfs(root);
	return 0;
}