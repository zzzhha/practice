#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef struct Node {
	int key;
	struct Node* lchild;//left Ҳ����
	struct Node* rchild;//right Ҳ����

}Node;

Node* getNewNode(int key)
{
	Node* p = new(Node);
	p->key = key;
	p->lchild = p->rchild = NULL;
	return p;
}

Node* insert(Node* root,int key)//�����������Ҷ�ӽ��
{
	if (root == NULL) return getNewNode(key);
	if (rand() % 2) root->lchild = insert(root->lchild,key);//��randΪ1��ʱ�򣬽���˵ݹ飬�����ڵ�����ӣ�������һ�εݹ�ĸ��ڵ㣨���������������в���
	else root->rchild = insert(root->rchild,key);//ͬ��
	//if�Ϳ�����ɡ���/�Ӹ� ���ҡ�������/�Ӹ� ���󡱹����ֵĲ��뷽��
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