#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<easyx.h>

using namespace std;
//海贼OJ 44
//dp[i]代表以i位结尾的上升子序列最长的长度
//leng(j)是一个动态更新的数组，记录长度为j序列的末尾最小值
int sequence_p[1000005];
int leng[100005] = { 0 };

int erfenfind(int *len,int n, int x) {
	int head = 0;
	int tail = n;
	int mid=1;
	while(head<tail)
	{
		mid = (head + tail + 1) >> 1;
		if (len[mid] < x)head = mid;
		else tail = mid - 1;
	}
	return head;
}


//int main() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	leng[0] = -1;
//	for (int i = 0,a; i < n; i++)
//	{
//		cin >> a;
//		sequence_p[i] = erfenfind(leng, ans, a) + 1;
//		leng[sequence_p[i]] = a;
//		if (sequence_p[i] > ans) ans = sequence_p[i];
//	}
//	cout << ans;
//	return 0;
//}