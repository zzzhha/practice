#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//海贼OJ 46
//dp(i,j)代表从i到j最少切多少刀
//dp(i,j)=min(dp(i,k)+dp(k+1,j)+1 , 0 ) k属于[i,j) 若取0，需满足: s[i]=s[j]且dp(i+1,j-1)=0
//区间DP不优化无法满分
// 
// 区间DP
// 区间DP的目标是在给定的一段区间上求解最优解。
// 在这个过程中，需要将要求的区间分割成若干个小区间，
// 分别求解每个小区间的最优解，
// 然后通过合并这些小区间的最优解来求解大区间的最优解。

// 定义状态：通常使用dp[i][j]来表示区间[i, j]上的最优解。
// 这个最优解可以是最大值、最小值、最长子序列长度等，具体取决于题目的要求。

// 初始化：对于长度为1或2的区间，可以直接给出最优解，这些区间是求解大区间最优解的基础。

// 状态转移：通过枚举合并点k，将区间[i, j]分割成[i, k]和[k + 1, j]两个小区间，
// 并分别求解这两个小区间的最优解。然后，根据这两个小区间的最优解和合并点k处的状态，
// 更新区间[i, j]的最优解。状态转移方程通常表示为dp[i][j] = min / max{ dp[i][k] + dp[k + 1][j] + w(i, j, k) }，
// 其中w(i, j, k)表示合并区间[i, j]时，在合并点k处产生的额外代价或收益。

// 求解结果：最终，dp[1][n]或dp[0][n - 1]（取决于区间的定义方式）将表示整个区间的最优解。
//待优化
//优化方案：4.3.1优化转移过程

//题目数据是500000（50万）但是50万*50万开不下
//此处用1000小数据模拟
int huiwendp[15][15] = { 0 };
//int main() {
//	string s;
//	cin >> s;
//	s = '@' + s;
//	int n = s.length() - 1;
//	for (int l = 1; l <= n; l++) {
//		for (int i = 1; i <= n - l + 1; i++) {
//			int j = i + l - 1;
//			if (s[i] == s[j] && huiwendp[i + 1][j - 1] == 0)
//			{
//				huiwendp[i][j] = 0;
//			}
//			else
//			{
//				huiwendp[i][j] = l;
//				for (int k = i; k < j; k++) {
//					huiwendp[i][j] = min(huiwendp[i][j], huiwendp[i][k] + huiwendp[k + 1][j] + 1);
//				}
//				
//			}
//		}
//	}
//	cout << huiwendp[1][n];
//	return 0;
//}