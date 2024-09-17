#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;

//P2392
int s[4];//4个科目
int s1[4][25];//[0][]第一个科目的习题集，存的数代表每道题花的时间

//[1][]第二个习题集 .......TODO(1)
int annss = 0;
//void fojiao() {//有问题
//	for (int i = 0; i < 4; i++) {
//		if (s[i] == 1)
//			annss += s1[i][0];
//		else if (s[i] == 2)
//			annss += max(s1[i][0], s1[i][1]);
//		else {
//			sort(&s1[i][0], &s1[i][s[i]]);
//			int x = 0;
//			int y = s[i] - 1;
//			while (y > x)
//			{
//				int maax = s1[i][y];
//				while (maax > s1[i][x] && y > x) {
//					maax -= s1[i][x];
//					x++;
//				}
//				annss += s1[i][y];
//				s1[i][x] -= maax;
//				if (y == x) {
//					annss += maax;
//				}
//				else if (y - x == 1) {
//					annss += s1[i][x];
//				}
//				y--;
//				if (y - x == 1) {
//					annss += s1[i][y];
//				}
//
//			}
//		}
//	}
//}

int aannss = INT_MAX;
//x代表本层，k代表本层的第几个数据,l代表左脑处理的数据的时间,r代表右脑处理的数据的时间
void dfs_ling(int k, int x, int l,int r) {
	if (k == s[x]) {
		aannss = min(aannss, max(l, r));
		return;
	}
	//将当前题目交给左脑处理，进行递归解决下一道题，递归结束后，将这道题退出
	l += s1[x][k];
	dfs_ling(k + 1, x, l, r);
	l -= s1[x][k];
	//把当前题目交给右脑处理，进行递归解决下一道题，递归结束后，退出此题。
	r += s1[x][k];
	dfs_ling(k + 1, x, l, r);
	r -= s1[x][k];
	//这两步递归，从整个程序看就是先把所有数据存放到左脑中
	//然后逐渐把左脑退出的数据放入右脑中，相当于左右脑处理不同的数据
	//此时k值达到s[x]时，所花时间会变小，aannss就开始统计最优解了
	//后续把数据都放在了右脑又会使总时间变长，但是ans不会记录

	return;
}

//int main() {
//	for (int i = 0; i < 4; i++) {//TODO(4)
//		cin >> s[i];
//	}
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < s[i]; j++) {
//			cin >> s1[i][j];
//		}
//	}
//	//fojiao();
//	int total = 0;
//	for (int i = 0; i < 4; i++) {
//		dfs_ling(0, i, 0, 0);
//		total += aannss;
//	}
//	cout << total;
//	return 0;
//}
unordered_map<int, int>ind;
int sum[10] = { 0 };//存储4课复习册花的总时间
int solve(int k) {
	int ans = INT_MAX;
	int T = (1 << s[k]) - 1;//掩码值

	//其实这个for循环是在仿照上面的回溯
	//i为什么小于的是T（掩码值），是因为
	//这样我们的i就会得到从1到T所有的二进制的全排列
	//根据不同的二进制，左脑就会分配不同的习题
	//右脑通过sum存储的 每课花费总时间-左脑花费的时间，就可以得到右脑需要花费的时间
	//就完成了左右脑分配不同题目的目的
	//ans再在每次循环后去取得最小值，得到本科目中所需最少时间的解法
	//通过slove函数外层的4次循环，就可以得到总的最短时间
	//就达到了解题的目的
	for (int i = 0; i < T; i++) {
		int j = i;
		int l = 0;
		int r = 0;
		while (j) {
			l += s1[k][ind[j & -j]];//获得掩码值二进制位最低位1所对应下标 在数组中存储的值
			j -= (j & -j);
		}
		r = sum[k] - l;
		ans = min(ans, max(l, r));
	}
	return ans;
}


int main() {
	for (int i = 0; i < 4; i++) {
	cin >> s[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < s[i]; j++) {
			cin >> s1[i][j];
			sum[i] += s1[i][j];//统计了总时间？
		}
	}
	for (int k = 1, i = 0; i <= 20; i++, k *= 2) {
		ind[k] = i;
	}
	int aa = 0;
	for (int i = 0; i < 4; i++) {
		aa += solve(i);
	}

	return 0;
}
