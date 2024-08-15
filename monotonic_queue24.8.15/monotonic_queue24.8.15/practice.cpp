#include<iostream>
#include<stack>
#include<deque>
#include<vector>
using namespace std;


//海贼OJ 271.滑动窗口
//给出一个长度为N的数组，一个肠胃K的滑动窗口从最左移动到最右，
// 每次窗口移动，如下图：
// Window position       Minimum value    Maximum value
// [1 3 -1] -3 5 3 6 7        -1              3
// 1 [3 -1 -3] 5 3 6 7        -3              3
// 4 3 [-1 -3 5] 3 6 7        -3              5
// 4 3 -1 -[3 5 3] 6 7        -3              5
// 4 3 -1 -3 [5 3 6] 7         3              6
// 4 3 -1 -3 5 [3 6 7]         3              7
//找出窗口在各个位置时的极大值和极小值。

//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int> arr;
//	for (int i = 0, a; i < n; i++) {
//		cin >> a;
//		arr.push_back(a);
//	}
//	deque<int> q;
//	for (int i = 0; i < n; i++) {
//		while (!q.empty() && arr[i]<arr[q.back()]) {
//			q.pop_back();
//		}
//		q.push_back(i);
//		if (i - q.front() == k) {
//			q.pop_front();
//		}
//		if (i + 1 < k)continue;
//		if (i >= k) cout << " ";
//		cout << arr[q.front()];
//	}
//	cout << endl;
//	q.clear();
//	for (int i = 0; i < n; i++) {
//		while (!q.empty() && arr[i] > arr[q.back()]) {
//			q.pop_back();
//		}
//		q.push_back(i);
//		if (i - q.front() == k) {
//			q.pop_front();
//		}
//		if (i + 1 < k)continue;
//		if (i >= k)cout << " ";
//		cout << arr[q.front()];
//	}
//	return 0;
//}

//海贼OJ 270最大子序和
//输入一个长度为n的整数序列，从中找出一段不超过M的连续子序列，使得整个序列的和最大。
//​例如 1,-3,5,1,-2,3:
//​当 m=4 时，S=5+1-2+3=7；
//当 m=2或m=3时，S=5+1=6。

int main() {
	int n, m;
	cin >> n >> m;
	vector<int>s(n+1);
	deque<int>q;
	s.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	q.push_back(0);
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, s[i] - s[q.front()]);
		while()
	}
	return 0;
}