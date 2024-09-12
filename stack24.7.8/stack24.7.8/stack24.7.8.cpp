#include<iostream>

using namespace std;


class D_stack
{
public:
	int data;
	D_stack* next;
	D_stack(int value)
	{
		data = value;
		next = NULL;
	}
	void Push(int value)
	{
		D_stack* s = next;
		while (s) {
			s = s->next;
		}
		D_stack* p = new D_stack(value);
		s = p;
	}
	bool isempty()
	{
		if (next == NULL)
			return 1;
		return 0;
	}
	void pop()
	{
		if (isempty())
			return;

		D_stack* temp = next;
		D_stack* s = next;
		while (s)
		{
			temp = s;
			s = s->next;
		}
		temp->next = NULL;
		delete s;
	}
	int gettop()
	{
		if (isempty())
			return false;
		D_stack* p = next;
		while (p->next) {
			p = p->next;
		}
		return p->data;
	}
	~D_stack()
	{
		while (isempty())
			pop();
	}
};



class Stack //顺序表实现栈
{
public:
	int* data;
	int top, size;
	Stack()
	{
		data = new int[10];
		size = 10;
		top = -1;
	}
	Stack(int n)
	{
		data = new int[n];
		size = n;
		top = -1;//top =0
	}
	bool isempty()const
	{
		return top == -1;//top初始等于0时为 top==0
	}

	bool push(int val)
	{
		if (top == size - 1)//top初始等于0时为 top==size
		{
			return 0;
		}
		data[++top] = val;
		return 1;
	}
	bool pop()
	{
		if (isempty())
		{
			return -1;
		}
		top--;
		return 1;
	}
	int Get_Top()
	{
		if (isempty())
		{
			return 0;
		}
		return data[0];
	}
	int Stack_length()
	{
		return top + 1;//top初始等于0时为 return top
	}
	void Clear_Stack()
	{
		top = -1;
	}
	~Stack()
	{
		delete[]data;
	}
};

int main()
{
	D_stack* p = new D_stack(10);
	
}