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


//习题1：括号匹配 
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
	//左括号必须用相同类型的右括号闭合。
	//左括号必须以正确的顺序闭合。
	//每个右括号都有一个对应的相同类型的左括号。

//题解：用上方实现的stack，并将int*data 改为char*data,相关函数也进行改变
//判断括号是否能匹配，可以用到栈的思想，遍历，我们将左括号放入栈中，右括号与栈首元素匹配
//如果匹配成功，则删除栈首元素，如果不成功，则啥也不干
//遍历完成后，判断栈是否为空，如果为空，那么说明括号完全匹配成功，如果不为空，那么说明匹配失败
//下面的方法用了flag，用empty也是可以的
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