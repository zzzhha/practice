#include<iostream>
#include<algorithm>

using namespace std;

//容斥原理：统计整体的时候，把能想到的都加进来，多了就减掉，少了就再加


//海贼OJ 42

int coin[25][10005];//coin[i][j]表示，用前i中钱币，凑足j元钱的方案
//此题可分为两部分：第一部分：使用i种钱币，第二种：没有使用i中钱币
//其中没有使用i种钱币就可以表示为coin[i-1][j]
//如果我们想要计算第一部分的情况,我们就需要知道coin[i][j-val[i]]，val[i]表示为i的值
//也就是说我们需要知道，用i种钱币凑齐j-money[i]元钱的方法（可以使用i种钱币，也可以不使用）
//于是coin[i][j]就可以表示为coin[i-1][j]+coin[i][j-money[i]]两部分
//
int money[25];



//int main() {
//	int m, n;
//	cin >> m >> n;
//	for (int i = 1; i <= m; i++) {
//		cin >> money[i];
//	}
//	for (int i = 1; i <= m; i++) {//i代表钱的种类，种第一种开始遍历到最后一种,不从0开始是为了防止后面的i-1得到负数
//		coin[i][0] = 1;//用i种钱凑0块钱的方法是1种，就是不取钱
//		for (int j = 1; j <= n; j++) {//j代表钱数
//			//coin[i][j]=coin[i-1][j]+coin[i][j-money[i]]
//			//这里统计第一部分
//			coin[i][j] = coin[i - 1][j];
//			//如果当前钱数小于当前钱的面值，就继续（这步是为了防止j-money[i]<0）
//			if (j < money[i]) continue;
//			coin[i][j] += coin[i][j - money[i]];
//			coin[i][j] %= 9973;
//		}
//	}
//	cout << coin[m][n] << endl;
//	return 0;
//}
