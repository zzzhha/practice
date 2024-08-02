#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

//Binary Search Tree BST ���������������������
//��һ���ڵ������������������������нڵ��ֵ��С�ڸýڵ�ֵ
//��һ���ڵ������������������������нڵ��ֵ�����ڸýڵ�ֵ

typedef struct BSTNode {
	int data;
	struct BSTNode* left;
	struct BSTNode* right;
}BSTNode,*BSTree;

BSTree initBST(int k)
{
	BSTNode* s = (BSTNode*)malloc(sizeof(BSTNode));
	if (s == NULL)
	{
		printf("FAIL!\n");
		return NULL;
	}
	s->data = k;
	s->left = s->right = NULL;
	return  s;
}

BSTree insert_BST(BSTree root, int k)
{
	BSTNode* s = (BSTNode*)malloc(sizeof(BSTNode));
	if (s == NULL)
	{
		cout << "fail" << endl;
		return NULL;
	}
	s->data = k;
	s->left = s->right = NULL;
	BSTNode* p = root;
	BSTNode* pre = NULL;
	while (p != NULL)
	{
		if (k < p->data)
		{
			pre = p;
			p->left;
		}
		else if (k > p->data)
		{
			pre = p;
			p = p->right;
		}
	}
	if (k < pre->data)
	{
		pre->left = s;
	}
	else
		pre->right = s;
	return root;
	
}

int main()
{
	int n, x;
	cin >> n;
	cin >> x;
	BSTree root = initBST(x);
	for (int i = 2; i <= n; i++)
	{
		cin >> x;
		root=insert_BST(root, x);
	}
	return 0;
}