#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct Stack
{
	char*/*int* */ data;
	int size, top;
}stack;

stack* initstack(int n)
{
	stack* s = new stack;
	s->data = new char[n];
	s->size = n;
	s->top = -1;
	return s;
}

bool empty(stack*s)
{
	return s->top == -1;
}

char/*int */ top(stack* s)
{
	if (empty(s))
		return 0;
	return s->data[s->top];
}

int push(stack* s, char/*int*/  val)
{
	if (s->top + 1 == s->size)
		return 0;
	s->top += 1;
	s->data[s->top] = val;
	return 1;
}

int pop(stack* s)
{
	if (empty(s))
		return 0;
	s->top -= 1;
	return 1;
}

void clearStack(stack* s)
{
	if (s == NULL)
		return;
	delete[]s->data;
	delete s;
}


//ϰ��1������ƥ�� 
// ����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺
	//�����ű�������ͬ���͵������űպϡ�
	//�����ű�������ȷ��˳��պϡ�
	//ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�

//��⣺���Ϸ�ʵ�ֵ�stack������int*data ��Ϊchar*data,��غ���Ҳ���иı�
//�ж������Ƿ���ƥ�䣬�����õ�ջ��˼�룬���������ǽ������ŷ���ջ�У���������ջ��Ԫ��ƥ��
//���ƥ��ɹ�����ɾ��ջ��Ԫ�أ�������ɹ�����ɶҲ����
//������ɺ��ж�ջ�Ƿ�Ϊ�գ����Ϊ�գ���ô˵��������ȫƥ��ɹ��������Ϊ�գ���ô˵��ƥ��ʧ��
//����ķ�������flag����emptyҲ�ǿ��Ե�
bool slove(char s[])
{
	Stack* p = initstack(10000);
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			push(p, s[i]);
		else
		{
			switch (s[i])
			{
			case ')':
				if (!empty(p) && top(p) == '(')
					pop(p);
				else
					return false;
				break;
			case ']':
				if (!empty(p) && top(p) == '[')
					pop(p);
				else
					return false;
				break;
			case '}':
				if (!empty(p) && top(p) == '{')
					pop(p);
				else
					return false;
				break;
			}
		}
	}
	if (empty(p))
		return true;
	else
		return false;
}



void program()
{
	int flag = 0;
	int n;
	cin >> n;
	vector<string> ops(n),s;
	string target;
	for (int i = 0; i < n; i++)
	{
		cin >> ops[i];
	}
	cin >> target;
	for (int i = 0; i < n; i++)
	{
		if (target == ops[i])
		{
			s.push_back(ops[i]);
			flag = 1;
			break;
		}
		if (ops[i] == "return")
		{
			s.pop_back();
		}
		else
		{
			s.push_back(ops[i]);
		}	
	}
	if (flag)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (i)cout << "->";
			cout << s[i];
		}
		cout << endl;
	}
	else
		cout << "NOT REFERENCED" << endl;
}
int main()
{
	program();
	return 0;
}