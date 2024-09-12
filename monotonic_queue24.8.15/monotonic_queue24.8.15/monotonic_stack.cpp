#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//单调栈：求当前元素最近的大小元素

void output(vector<int>& arr); 

//int main() {
//	int n, k;//k为区间范围
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
//			r[s.top()] = i;//存储当前比原本栈的栈顶元素小的元素
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
//		printf("arr[%d] = %d, 右边最近小于他的元素right : arr[%d] = %d, 左边最近小于他的元素left : arr[%d] = %d\n",
//			i, arr[i],
//			r[i], arr[r[i]],
//			l[i], arr[l[i]]
//		);
//	}
//	return 0;
//}