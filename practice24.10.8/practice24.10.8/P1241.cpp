#include<iostream>
#include<stack>
#include<string>
using namespace std;

//char c[110];//存储s[i]对应的右括号，
//stack<char> arr;//记录左括号
//stack<int>w;//存储做左括号下标
//int main() {
//	string s;
//	cin >> s;
//	int flag = 0;
//	for (int i = 0; s[i]; i++) {
//		//arr记录的左括号，且arr栈每一次压栈，我们的top就会++，w[]就会记录下这个左括号的位置i
//		//c[]就会对应这个左括号记录一个右括号
//		if (s[i] == '(' || s[i] == '[') {//如果是左括号
//			w.push(i);//记录此时的下标
//			arr.push(s[i]);//将左括号压入栈中，不用c++的话 就是arr[top]=s[i]
//			if (s[i] == '(') c[i] = ')';//c[i]匹配右相应括号
//			else c[i] = ']';
//		}else {//如果当前元素是右括号
//			switch (s[i])//则判断是什么括号
//			{
//			case ')'://如果是小括号
//				if (!arr.empty() && arr.top() == '(')//记录左括号的栈不为空，且栈顶元素是‘（’，说明这个右括号可以被最近的左括号所匹配
//				{
//					c[w.top()] = ' ';//则w[top]也就是arr栈顶所对应的元素位置，使这个位置的c[]为 空（原本这个位置的c记录的就是‘）’）
//					//c[i]这个位置没有被赋值，也就是0
//					arr.pop();//出栈
//					w.pop();
//				}
//				else {//如果arr栈顶元素不是'('或者是空的 则说明此右括号无法匹配
//					c[i] = '(';//那么c[i]的位置就记录为‘（’（因为要对应s[i]的相应位置）
//				}
//				break;
//			case ']'://同上
//				if (!arr.empty() && arr.top() == '[')
//				{
//					c[w.top()] = ' ';
//					arr.pop();
//					w.pop();
//				}
//				else {
//					c[i] = '[';
//				}
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < s.length(); i++)//打印
//	{
//		if (c[i] == '(' || c[i] == '[') printf("%c%c", c[i], s[i]);//如果c[i]是左括号，则说明s[i]对应的是无法被对应的右括号
//		else if (c[i] == ')' || c[i] == ']') printf("%c%c", s[i], c[i]);//如果c[i]是右括号，则说明s[i]对应的是无法被对应的左括号
//		else printf("%c", s[i]);//如果c[i]为空或者0，则说明此位置的s[i]和s[i+1]是一对能匹配上的括号
//	}
//	return 0;
//}
