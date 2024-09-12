#include<iostream>
#include<stack>
#include<deque>
#include<vector>
#include<climits>
#include<queue>
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

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
	deque<int> q;
	for (int i = 0; i < n; i++) {
		while (!q.empty() && arr[i]<arr[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
		if (i - q.front() == k) {
			q.pop_front();
		}
		if (i + 1 < k)continue;
		if (i >= k) cout << " ";
		cout << arr[q.front()];
	}
	cout << endl;
	q.clear();
	for (int i = 0; i < n; i++) {
		while (!q.empty() && arr[i] > arr[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
		if (i - q.front() == k) {
			q.pop_front();
		}
		if (i + 1 < k)continue;
		if (i >= k)cout << " ";
		cout << arr[q.front()];
	}
	return 0;
}

//海贼OJ 270最大子序和
//输入一个长度为n的整数序列，从中找出一段不超过M的连续子序列，使得整个序列的和最大。
//​例如 1,-3,5,1,-2,3:
//​当 m=4 时，S=5+1-2+3=7；
//当 m=2或m=3时，S=5+1=6。

//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int>s(n+1);//记录前缀和
//	deque<int>q;//单调队列存储前缀和的最小值，存储下标
//	s.push_back(0);//前缀和的初始值一定为0
//	for (int i = 1; i <= n; i++) {
//		cin >> s[i];
//		s[i] += s[i - 1];//得到前缀和序列
//	}
//	q.push_back(0);//初始化，将前缀和为0的值存进去
//	int ans = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		ans = max(ans, s[i] - s[q.front()]);
//		while (!q.empty() && s[i] < s[q.back()]) {
//			q.pop_back();
//		}
//		q.push_back(i);
//		if (i - q.front() == m)
//			q.pop_front();
//		
//	}
//	cout << ans << endl;
//	return 0;
//}



//剑指offer59 
//请定义一个队列并实现函数max_value得到队列里的最大值，
// 要求函数max_value、pish_back和pop_front的均摊时间复杂度都是O(1)
//若队列为空，pop_front和max_value需要返回-1


class MaxQueue {
public:
	queue<int>q;
	deque<int>mq;
	MaxQueue() {}

	int max_value() {
		if (q.empty()) return -1;
		return mq.front();
	}

	void push_back(int value) {
		q.push(value);
		while (!mq.empty() && mq.back() < value)mq.pop_back();
		mq.push_back(value);
		return;
	}

	int pop_front() {
		if (q.empty()) return -1;
		int val = q.front();
		q.pop();
		if (val == mq.front()) {
			mq.pop_front();
		}
		return val;
	}
};


//leetcode 1438绝对差不超过限制的最长连续子数组
//给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，
// 该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit
//如果不存在满足条件的子数组，则返回 0

//输入：nums = [8,2,4,7], limit = 4
//输出：2
//解释：所有子数组如下：
//[8] 最大绝对差 | 8 - 8 | = 0 <= 4.
//[8, 2] 最大绝对差 | 8 - 2 | = 6 > 4.
//[8, 2, 4] 最大绝对差 | 8 - 2 | = 6 > 4.
//[8, 2, 4, 7] 最大绝对差 | 8 - 2 | = 6 > 4.
//[2] 最大绝对差 | 2 - 2 | = 0 <= 4.
//[2, 4] 最大绝对差 | 2 - 4 | = 2 <= 4.
//[2, 4, 7] 最大绝对差 | 2 - 7 | = 5 > 4.
//[4] 最大绝对差 | 4 - 4 | = 0 <= 4.
//[4, 7] 最大绝对差 | 4 - 7 | = 3 <= 4.
//[7] 最大绝对差 | 7 - 7 | = 0 <= 4.
//因此，满足题意的最长子数组的长度为 2 。

class Solution {
public:
	
	int longestSubarray(vector<int>& nums, int limit) {
		if (limit < 0) return 0;
		deque<int>min_q;
		deque<int>max_q;
		int l = 0;
		int ans = 1;
		min_q.push_back(0);
		max_q.push_back(0);
		for (int i = 1; i < nums.size(); i++) {
			while (!min_q.empty() && nums[i] < nums[min_q.back()])
			{
				min_q.pop_back();
			}
			while(!max_q.empty() && nums[i] > nums[max_q.back()])
			{
				max_q.pop_back();
			}
			min_q.push_back(i);
			max_q.push_back(i);
			while(nums[max_q.front()] - nums[min_q.front()] > limit) {
				if (min_q.front() == l)min_q.pop_front();
				if (max_q.front() == l)max_q.pop_front();
				l += 1;
			}
			ans = max(ans, i - l + 1);
		}
		return ans;
	}
};


//海贼OJ 264最大矩形面积
//给定从左到右多个矩形，已知这此矩形的宽度都为 1，长度不完全相等。
// 这些矩形相连排成一排，求在这些矩形包括的范围内能得到的面积最大的矩形，打印出该面积。
// 所求矩形可以横跨多个矩形，但不能超出原有矩形所确定的范围

//题解：由题可知：1.最大矩形的高度=某块木板的高度
//				  2.此矩形两侧的木板都要比矩形中的最短的那个木板要矮
//				  3.矩形中其他木板的高度都要比最短的那个木板高
//我们确定一块木板，将他作为矩形中最矮的那块，用单调栈去找到左右在最近比他矮的木板
//此时，我们就找到了以当前木板为最矮木板的最大矩形面积
//遍历一次即可找完所有木板作为最矮木板形成的最大矩形面积，取最大值即可


//int main() {
//	int n;
//	cin >> n;
//	vector<long long>arr(n + 2, -1);
//	vector<long long>l(n + 2), r(n + 2);//l记录左边小于当前木板的最近的那块木板，r记录右边
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//	}
//	stack<int>s;
//
//	for (int i = 1; i <= n + 1; i++)
//	{
//		while (!s.empty() && arr[i] < arr[s.top()]) {
//			r[s.top()] = i;
//			s.pop();
//		}
//		s.push(i);
//	}
//	while (!s.empty())s.pop();
//	for (int i = n; i >= 0; i--) {
//		while (!s.empty() && arr[i] < arr[s.top()]) {
//			l[s.top()] = i;
//			s.pop();
//		}
//		s.push(i);
//	}
//	long long ans = 0;
//	for (int i = 1; i <= n; i++) {
//		long long width = r[i] - l[i] - 1;
//		long long height = arr[i];
//		ans = max(height * width, ans);
//	}
//	cout << ans << endl;
//	return 0;
//}


