#include<iostream>
#include<string>

using namespace std;

const char priority[][7] = {
	{'>','>','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'<','<','<','<','<','=','0'},
	{'>','>','>','>','0','>','>'},
	{'<','<','<','<','<','0','='},
};

class stack_val {
public:
	int rear;
	int* data;
	const int length =50;
	stack_val() {
		rear = -1;
		data = new int[50];
	}
	void pop() {
		if (empty()) return;
		rear--;
	}

	void push(int p) {
		if (full()) return;
		data[++rear] = p;
	}

	bool empty() {
		return rear == -1;
	}

	int top() {
		if (empty()) return 0;
		return data[rear];
	}

	bool greater2() {
		return rear >= 1;
	}

	bool full() {
		return rear == length;
	}
};

class stack_oper {
public:
	int rear;
	char * data;
	const int length = 50;
	stack_oper() {
		rear = 0;
		data = new char[50];
		data[0] = '#';
	}
	void pop() {
		if (empty()) return;
		rear--;
	}

	void push(int p) {
		if (full()) return;
		data[++rear] = p;
	}

	bool empty() {
		return rear == 0;
	}

	char top(){
		return data[rear];
	}

	bool full() {
		return rear == length;
	}
};

int getIndex(char theta) {
	int index = 0;
	switch (theta) {
	case '+':
		index = 0;
		break;
	case'-':
		index = 1;
		break;
	case'*':
		index = 2;
		break;
	case'/':
		index = 3;
		break;
	case'(':
		index = 4;
		break;
	case')':
		index = 5;
		break;
	case'#':
		index = 6;
		break;
	default:break;
	}
	return index;
}

char getPriority(char theta1, char theta2) {
	int index1 = getIndex(theta1);
	int index2 = getIndex(theta2);
	return priority[index1][index2];
}


int main() {
	string s;
	stack_val val;
	stack_oper oper;
	int arr[50];
	int count = 0;
	while(1)
	{
		cin >> s;
		int ind = 0;
		int flag = 0;
		if (s == "=") break;
		while(1)
		{
			
			if (s[ind] >= '0' && s[ind] <= '9') {
				if (flag) {
					val.data[val.rear] = val.top() * 10 + (s[ind] - '0');
				}
				else
					val.push(s[ind] - '0');
				flag = 1;
				ind++;
			}
			else if (s[ind] == '\0') {
				arr[count++] = val.top();
				while (!val.empty()) val.pop();
				while (!oper.empty()) oper.pop();
				break;
			}
			else {
				switch (getPriority(oper.top(), s[ind])) {
				case'<':
					oper.push(s[ind++]);
					break;
				case'=':
					oper.pop();
					ind++;
					break;
				case'>':
					if (oper.top() == '#')break;
					int a = val.top();
					val.pop();
					int b = val.top();
					val.pop();
					switch (oper.top()) {
					case '+':
						val.push(b + a);
						break;
					case '-':
						val.push(b - a);
						break;
					case '/':
						val.push(b / a);
						break;
					case'*':
						val.push(b * a);
						break;
					}
					oper.pop();
				}
				
				flag = 0;
				
			}
		}
	}
	for(int i=0;i<count;i++)
	{
		cout <<arr[i] << endl;
	}
	return 0;
}

/*
2+2=
20*(4-2)=
=
*/