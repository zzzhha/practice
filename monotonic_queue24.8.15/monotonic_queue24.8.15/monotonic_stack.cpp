#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//����ջ����ǰԪ������Ĵ�СԪ��

void output(vector<int>& arr); 

//int main() {
//	int n, k;//kΪ���䷶Χ
//	cin >> n >> k;
//	stack<int> s;
//	vector<int>arr;
//	arr.push_back(-1);
//	for (int i = 0; i < n; i++) {
//		int a;
//		cin >> a;
//		arr.push_back(a);
//	}
//	arr.push_back(-1);
//	vector<int> l(arr.size() - 1), r(arr.size() + 1);
//	output(arr);
//	//right
//	for (int i = 0,I = arr.size(); i < I; i++) {
//		while (!s.empty()&& arr[s.top()]>arr[i]) {
//			r[s.top()] = i;//�洢��ǰ��ԭ��ջ��ջ��Ԫ��С��Ԫ��
//			s.pop();
//		}
//		s.push(i);
//	}
//	//left
//	while (!s.empty())s.pop();
//	for (int i  = arr.size() - 1; i >= 0; i--) {
//		while (!s.empty() && arr[s.top()] > arr[i]) {
//			l[s.top()] = i;
//			s.pop();
//		}
//		s.push(i);
//	}
//	for (int i = 1; i <= n; i++) {
//		printf("arr[%d] = %d, �ұ����С������Ԫ��right : arr[%d] = %d, ������С������Ԫ��left : arr[%d] = %d\n",
//			i, arr[i],
//			r[i], arr[r[i]],
//			l[i], arr[l[i]]
//		);
//	}
//	return 0;
//}