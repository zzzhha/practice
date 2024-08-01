#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


typedef struct Node {
	int key;
	int ltag, rtag;//�������1����˵������һ���������������0������һ�������Ľڵ�
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
void __build_in_order_thread(Node* root)//�����������п�ָ��Ľڵ㣬ָ����Ӧ��ǰ�����ߺ�̣�
										//��ltag��rtag�������˽ڵ��Ƿ���ǰ���ͺ��
										//ʹ����״�ṹ��������һ������
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
	//cout << root->key << " ";//������ӡ��ǰ�ڵ�����ݣ����ݴ�������ҵ���ǰ�Ľڵ㣬����������
	if (root->rtag == 0)__build_in_order_thread(root->rchild);
}

void build_in_order_thread(Node* root)
{
	__build_in_order_thread(root);
	pre_node->rchild = NULL;
	pre_node->rtag = 1;
}

Node* getNext(Node* root)//����һ���ڵ�
{
	if (root->rtag == 1) return root->rchild;//�жϴ˽ڵ���Һ����ǽڵ㻹���������������������ô�ͷ�������
	root = root->rchild;//���������������֤�����Һ��ӣ���rootָ����һ���Һ���
	while (root->ltag == 0 && root->lchild)
	{
		root = root->lchild;//�����������������ң����ѵ�ǰ�ڵ��������ڵ㣬
							//��ô��һ����ӡ������һ���ǵ�ǰ�ٸ��ڵ��������������ߵ�Ҷ�ӣ���û�����������������Ҷ�ӽڵ㣩�ڵ�
							//Ϊʲô����ʱ�ݹ���е������ʱ�����Ѿ����й�������ˣ���Ϊ������ң�
							//�����ж���ʱ�����ڽ��С�������ʱ����еģ����Ի������һ���������ҡ����ӵĵݹ飬
							//������һ���ݹ�ʱ���ֿ�ʼ���޽��С��󡱵ݹ飬֪��ָ��գ�
							//Ҳ������ν��������������Ҷ�ӣ�Ҷ��ͬ�ϣ��ڵ�
							//�����Ϳ����ҵ���ǰ�ڵ����һ���ڵ���
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

	//���ڴ������������� �����������
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