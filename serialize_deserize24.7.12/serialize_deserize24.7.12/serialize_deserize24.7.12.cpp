#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string.h>
using namespace std;
//序列化与反序列化
//二叉树->广义表 序列化

#define KEY(n) (n ? n->key : -1)

typedef struct Node {
	int key;
	struct Node* lchild, *rchild;
}Node;

Node* getNewNode(int val)
{
	Node* p=new Node;
	p->key = val;
	p->lchild = p->rchild = NULL;
	return p;
}

void claer(Node* p)
{
	if (p == NULL) return;
	claer(p->lchild);
	claer(p->rchild);
	delete p;
}

Node* insert(Node* root, int key){
	if (root == NULL) return getNewNode(key);
	if (rand() & 2) root->lchild = insert(root->lchild, rand() % 100);
	else root->rchild = insert(root->rchild, rand() % 100);
	return root;
}

Node* getRandomBinaryTree(int n){
	Node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		root = insert(root, rand() % 100);
	}
	return root;

}

char buff[1000];//广义表的存储
int len = 0;//广义表信息的长度

//序列化输出类似于A（B,C)，先输出根，在输出左子树，做输出右子树
//类似于根左右，所以可以根据先序遍历的方式来序列化
void __serialize(Node* root)
{
	if (root == NULL)return;
	len+= sprintf(buff + len, "%d", root->key);//打印根，用len+sprintf的返回值，是记录偏移值，防止将前面存储的数据覆盖
	if (root->lchild == NULL && root->rchild == NULL) return;//如果左右子树都为空，则直接返回
	len += sprintf(buff + len, "(" );//到这一步肯定有左或右子树，左子树右子树都需要左括号，所以存储做左括号
	__serialize(root->lchild);//序列化当前节点的左子树
	if (root->rchild)//如果右子树不为空
	{
		len += sprintf(buff + len, ",");//因为序列化打印右子树需要一个“，”号，所以我们判断右子树是否为空，
										//不为空，那么就需要一个逗号，所以先打印逗号
		__serialize(root->rchild);//再序列化右子树
	}
	len += sprintf(buff + len, ")");//右子树序列化后，需要有右括号。所以存储右括号。

}


void serialize(Node *root)//序列化
{
	memset(buff, 0, sizeof(buff));
	len = 0;//初始化
	__serialize(root);
}

void print(Node* node)
{
	printf("%d(%d,%d)\n", KEY(node), KEY(node->lchild), KEY(node->rchild));
}

void output(Node* root)
{
	if (root == NULL)return;
	print(root);
	output(root->lchild);
	output(root->rchild);
}

Node* deserialize(char* buff, int n)
{
	Node** s = new Node* [10];//s是动态数组（模拟栈），数组保存的是一个Node类型指针，s存储每一个节点，每一个节点都有他的左右子树
	int top = -1;//用于s的存储，模拟栈的元素
	int flag = 0;//判断是左子树还是右子树
	int scode = 0;//状态码
	Node* p = NULL;//p指向最后生成的节点
	Node* root=NULL;
	for (int i = 0; buff[i]; i++)
	{
		int key = 0;
		switch (scode) {
		case 0://0状态码中，如果是关键字，那么跳转到1状态码，如果是“（”则跳转到2状态码
				//如果是“，”则跳转到3状态码，如果是“）”则跳转4状态码
			if (buff[i] >= '0' && buff[i] <= '9')
				scode = 1;
			else if (buff[i] == '(')
				scode = 2;
			else if (buff[i] == ',')
				scode = 3;
			else
				scode = 4;
			i -= 1;
			break;
		case 1:
			
			while (buff[i]<='9'&&buff[i]>='0')//用key保存当前值，因为可能是两位数，所以用while循环来计算key值
			{
				key = key * 10 + (buff[i] - '0');
				i += 1;//key值每进行一次计算，buff运用循环的i值就要往后移一位，直到buff[i]不是0~9的数
			}
			p = getNewNode(key);//创建一个节点
			if (top >= 0&&flag==0)//左子树
			{
				s[top]->lchild = p;
			}
			if (top >= 0 && flag == 1)//右子树
			{
				s[top]->rchild = p;
			}
			i--;//--的原因是因为for循环加了1，此处buff[i]就是（，）三者其一，所以再加就变成数字了，需要减1，然for+1后再是（，）三者其一
			scode = 0;
			break;
		case 2://如果是左括号
			s[++top] = p;//压栈操作，存p是因为p存储是的我们最新的一个节点
			flag = 0;
			scode = 0;
			break;
		case 3://如果是逗号，则下次一个节点应该是右子树
			flag = 1;
			scode = 0;
			break;
		case 4://
			root = s[top--];//弹栈操作，buff存储的最后都是“）”我们可以一次次弹栈，弹到最后一次就是根节点
			scode = 0;
			break;
		}
	}
	return root;
}
int main()
{
	srand(time(0));
	Node* root = getRandomBinaryTree(10);
	serialize(root);
	output(root);
	printf("Buff[]:%s\n", buff);
	Node* new_root = deserialize(buff, len);
	output(new_root);
	return 0;
}


//广义表->二叉树 反序列化

