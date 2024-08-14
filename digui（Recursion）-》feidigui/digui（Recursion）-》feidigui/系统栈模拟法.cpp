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
	int n;//代表本次调用的n值为多少
	int code;//状态码，如果是0状态码则运行第10行代码（即：递归版本的乘阶n==1 return 1），
	//如果是1则返回第11行代码，当状态码为0的时候，判断n==1，如果为假则将code改为1，为真就直接返回
	//状态码为2代表此时f（n-1）已经计算完毕，需计算n*f(n-1)的值
	int ret;//如果本层函数要调用下一层函数，则ret接受f(n-1)的返回值
	int* pre_ret;//存储上一层函数用来接收返回值的地址 
	//例如：本层函数f(4)的pre_ret指向f(5)的ret变量，f(5)的ret是接受f(4)的返回值
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
	Data d(n, &ans);//最后的结果会写入ans中
	s.push(d);//将d加入栈中
	while (!s.empty()) {//当栈不为空，我们都要取出栈顶元素然后执行
		Data& cur = s.top();
		switch (cur.code) {//根据状态码来执行代码
		case 0:
			if (cur.n == 1) {
				*(cur.pre_ret) = 1;
				s.pop();
			}
			else {//n不等于1说明此时阶乘计算未计算到1
				cur.code = 1;//将当前的cur 的状态码从0改为1，进行code为1的计算
			}
			break;
		case 1://状态码为1
			Data next(cur.n - 1, &(cur.ret));//状态码为1，说明此时n不为1，就可以压入n-1的值，并将当前的ret的地址传递给下一层的pre_ret
			cur.code = 2;
			s.push(next);
			break;
		case 2://状态码为2代表此时f（n-1）已经计算完毕，需计算n*f(n-1)的值
			*(cur.pre_ret) = cur.ret * cur.n;//相当于下一层的ret存储了本层ret*本层的n值
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

//二叉树中序遍历
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
