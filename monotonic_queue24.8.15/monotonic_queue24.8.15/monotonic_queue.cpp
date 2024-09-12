#include<iostream>
#include<deque>
#include<vector>
using namespace std;
//单调队列:维护区间最值 

void output(vector<int>& arr) {
	int n = arr.size();
	int len = 0;
	for (int i = 0; i < n; i++) {
		len += printf("%3d", i);
	}
	cout << endl;
	for (int i = 0; i < len; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	cout << endl;
	return;
}

//int main() {
//	int n, k;//k为区间范围
//	cin >> n >> k;
//	deque<int> q;
//	vector<int>arr;
//	for (int i = 0; i < n; i++) {
//		int a;
//		cin >> a;
//		arr.push_back(a);
//	}
//	output(arr);
//	for (int i = 0; i < n; i++) {//单调队列的建立，存储的是数组的下标
//		while (!q.empty() && arr[q.back()]> arr[i]) q.pop_back();//维护单调递增队列，如果当前值优先队列值最后一个数据大于arr[i]的数据，则弹出队尾元素
//		q.push_back(i);//压入下标，通过下标可以找到值，但是存储值的话找不到下标，会造成信息损失
//		if (i - q.front() == k)//这里指可能等于k，因为每一次进入的话都是等于条件成立进去，而不是大于条件成立
//		{
//			q.pop_front();
//		}
//		printf("[%d,%d]=arr[%d]=%d\n",
//			max(i - k + 1, 0), i,
//			q.front(), arr[q.front()]);
//	}
//	return 0;
//}