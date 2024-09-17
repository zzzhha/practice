#include<iostream>
#include<vector>
using namespace std;

//P2404  易
int add_st[15];

void dfs_nature(int i, int j, int n, int sum) //此递归函数表示第i个位置最小放置的元素为j，最大不超过n
{
	if (sum == n) {//边界条件
		for (int x = 0; x < i; x++) {
			cout << add_st[x];
			if (x + 1 != i) {
				cout << "+";
			}
		}
		cout << endl;
		return;
	}
	for (int k = j; k < n; k++)
	{
		if (j + sum > n)//剪枝
			return;
		add_st[i] = k;			
		dfs_nature(i + 1, k, n ,sum+k);//进行下一次递归，i+2表示在那个位置，k表示当前最小数字为多少
	}
	return;
}

int aans[20] = { 0 };

void print(int n) {
	if (n < 2)return;
	for (int i = 0; i < n; i++) {
		if (i)cout << "+";
		cout << aans[i];
	}
	cout << endl;
	return;
}

//k是层数，sum是当前数，n是剩余数（输入的n减去当前数）
void dfs_zi(int k, int s_num, int n) {
	if (n == 0) {
		print(k);
		return;
	}
	if (s_num > n)
		return;
	for (int i = s_num; i <= n; i++) {
		aans[k] = i;
		dfs_zi(k + 1, i, n - i);
	}
	return;
}

//int main() {
//	int n;
//	cin >> n;
//	dfs_zi(0, 1, n);
//	dfs_nature(0, 1, n, 0);
//	return 0;
//}
