#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>

using namespace std;


int f(int n) {
	if (n == 1) return 1;
	return n * f(n - 1);
}

struct Data {
	int n;//�����ε��õ�nֵΪ����
	int code;//״̬�룬�����0״̬�������е�10�д��루�����ݹ�汾�ĳ˽�n==1 return 1����
	//�����1�򷵻ص�11�д��룬��״̬��Ϊ0��ʱ���ж�n==1�����Ϊ����code��Ϊ1��Ϊ���ֱ�ӷ���
	//״̬��Ϊ2�����ʱf��n-1���Ѿ�������ϣ������n*f(n-1)��ֵ
	int ret;//������㺯��Ҫ������һ�㺯������ret����f(n-1)�ķ���ֵ
	int* pre_ret;//�洢��һ�㺯���������շ���ֵ�ĵ�ַ 
	//���磺���㺯��f(4)��pre_retָ��f(5)��ret������f(5)��ret�ǽ���f(4)�ķ���ֵ
	Data() {
		n = 0;
		code = 1;
	}
	Data(int n, int* pre_ret) :n(n), pre_ret(pre_ret) {
		code = 0;
	}
};

int non_f(int n) {
	stack<Data> s;
	int ans=1;
	Data d(n, &ans);//���Ľ����д��ans��
	s.push(d);//��d����ջ��
	while (!s.empty()) {//��ջ��Ϊ�գ����Ƕ�Ҫȡ��ջ��Ԫ��Ȼ��ִ��
		Data& cur = s.top();
		switch (cur.code) {//����״̬����ִ�д���
		case 0:
			if (cur.n == 1) {
				*(cur.pre_ret) = 1;
				s.pop();
			}
			else {//n������1˵����ʱ�׳˼���δ���㵽1
				cur.code = 1;//����ǰ��cur ��״̬���0��Ϊ1������codeΪ1�ļ���
			}
			break;
		case 1://״̬��Ϊ1
			Data next(cur.n - 1, &(cur.ret));//״̬��Ϊ1��˵����ʱn��Ϊ1���Ϳ���ѹ��n-1��ֵ��������ǰ��ret�ĵ�ַ���ݸ���һ���pre_ret
			cur.code = 2;
			s.push(next);
			break;
		case 2://״̬��Ϊ2�����ʱf��n-1���Ѿ�������ϣ������n*f(n-1)��ֵ
			*(cur.pre_ret) = cur.ret * cur.n;//�൱����һ���ret�洢�˱���ret*�����nֵ
			s.pop();
			break;

		}
		return ans;
	}
}

typedef struct Node {
	int key;
	struct Node *rchild, *lchild;
}Node;

//�������������
void in_order(Node* root) {
	if (root == NULL) return; //code 0
	in_order(root->lchild);	  //code 1
	printf("%d ", root->key);//code 2
	in_order(root->rchild);//code 3
	return;					//code 4
}

struct DAta {
	Node* root;
	int code;
	DAta(Node* root) :root(root),code(0) {}
};

void non_in_order(Node* root) {
	stack<DAta> s;
	DAta d(root);
	s.push(d);
	while (!s.empty()) {
		DAta& cur = s.top();
		switch (cur.code) {
		case 0:
			if (cur.root == NULL) s.pop();
			else
				cur.code = 1;
			break;
		case 1:
			DAta d(cur.root->lchild);
			cur.code = 2;
			s.push(d);
			break;
		case 2:
			printf("%d ", cur.root->key);
			cur.code = 3;
			break;
		case 3:
			DAta d(cur.root->rchild);
			cur.code = 4;
			s.push(d);
			break;
		case 4:
			s.pop();
			break;
		}
		
	}
	return;
}

int main() {
	int n;
	while (cin >> n)
	{
		cout << f(n) << endl;
		cout << non_f(n) << endl;
	}
	return 0;
}
