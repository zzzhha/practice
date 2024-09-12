#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string.h>
using namespace std;
//���л��뷴���л�
//������->����� ���л�

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

char buff[1000];//�����Ĵ洢
int len = 0;//�������Ϣ�ĳ���

//���л����������A��B,C)�����������������������������������
//�����ڸ����ң����Կ��Ը�����������ķ�ʽ�����л�
void __serialize(Node* root)
{
	if (root == NULL)return;
	len+= sprintf(buff + len, "%d", root->key);//��ӡ������len+sprintf�ķ���ֵ���Ǽ�¼ƫ��ֵ����ֹ��ǰ��洢�����ݸ���
	if (root->lchild == NULL && root->rchild == NULL) return;//�������������Ϊ�գ���ֱ�ӷ���
	len += sprintf(buff + len, "(" );//����һ���϶������������������������������Ҫ�����ţ����Դ洢��������
	__serialize(root->lchild);//���л���ǰ�ڵ��������
	if (root->rchild)//�����������Ϊ��
	{
		len += sprintf(buff + len, ",");//��Ϊ���л���ӡ��������Ҫһ���������ţ����������ж��������Ƿ�Ϊ�գ�
										//��Ϊ�գ���ô����Ҫһ�����ţ������ȴ�ӡ����
		__serialize(root->rchild);//�����л�������
	}
	len += sprintf(buff + len, ")");//���������л�����Ҫ�������š����Դ洢�����š�

}


void serialize(Node *root)//���л�
{
	memset(buff, 0, sizeof(buff));
	len = 0;//��ʼ��
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
	Node** s = new Node* [10];//s�Ƕ�̬���飨ģ��ջ�������鱣�����һ��Node����ָ�룬s�洢ÿһ���ڵ㣬ÿһ���ڵ㶼��������������
	int top = -1;//����s�Ĵ洢��ģ��ջ��Ԫ��
	int flag = 0;//�ж�������������������
	int scode = 0;//״̬��
	Node* p = NULL;//pָ��������ɵĽڵ�
	Node* root=NULL;
	for (int i = 0; buff[i]; i++)
	{
		int key = 0;
		switch (scode) {
		case 0://0״̬���У�����ǹؼ��֣���ô��ת��1״̬�룬����ǡ���������ת��2״̬��
				//����ǡ���������ת��3״̬�룬����ǡ���������ת4״̬��
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
			
			while (buff[i]<='9'&&buff[i]>='0')//��key���浱ǰֵ����Ϊ��������λ����������whileѭ��������keyֵ
			{
				key = key * 10 + (buff[i] - '0');
				i += 1;//keyֵÿ����һ�μ��㣬buff����ѭ����iֵ��Ҫ������һλ��ֱ��buff[i]����0~9����
			}
			p = getNewNode(key);//����һ���ڵ�
			if (top >= 0&&flag==0)//������
			{
				s[top]->lchild = p;
			}
			if (top >= 0 && flag == 1)//������
			{
				s[top]->rchild = p;
			}
			i--;//--��ԭ������Ϊforѭ������1���˴�buff[i]���ǣ�����������һ�������ټӾͱ�������ˣ���Ҫ��1��Ȼfor+1�����ǣ�����������һ
			scode = 0;
			break;
		case 2://�����������
			s[++top] = p;//ѹջ��������p����Ϊp�洢�ǵ��������µ�һ���ڵ�
			flag = 0;
			scode = 0;
			break;
		case 3://����Ƕ��ţ����´�һ���ڵ�Ӧ����������
			flag = 1;
			scode = 0;
			break;
		case 4://
			root = s[top--];//��ջ������buff�洢������ǡ��������ǿ���һ�δε�ջ���������һ�ξ��Ǹ��ڵ�
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


//�����->������ �����л�

