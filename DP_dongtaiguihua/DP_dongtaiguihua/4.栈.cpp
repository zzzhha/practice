#include<iostream>
#include<algorithm>

using namespace std;


//���P1044
int stack[25];//��ʾi�����ܵõ���������е��ܺ�


//int main() {
//	int n;
//	cin >> n; 
//	stack[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		stack[i] = 0;
//		for (int x = 1; x <= i; x++) {
//			stack[i] += stack[x - 1] * stack[i - x];//xΪ���һ����ջ��Ԫ�أ�
//			//���ܹ��ĳ�ջ�����Ϳ��Ի���Ϊ��xǰ���Ԫ����ô��ջ��ջ��x�����Ԫ����ô��ջ��ջ
//			//���ʹ��x���һ����ջ
//			//�����ַ�����ʹx��1-i�������Ϳ��Եõ���ǰջ����i��Ԫ�ص��ܹ���ջ������е��ܺ���
//
//		}
//	}
//
//	cout << stack[n] << endl;
//	return 0;
//}