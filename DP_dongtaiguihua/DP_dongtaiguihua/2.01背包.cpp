#include<iostream>
#include<algorithm>

using namespace std;

//海贼OJ 47
//f(i,j)前第i件物品，背包称重为j时， 存放价值
long long bag01_weight[105];
long long bag01_val[105];
long long bag01_ret[105][10005] = { 0 };
//优化
long long bag01_ret_plus[2][10005] = { 0 };

//int main() {
//	int v, n;
//	cin >> v >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> bag01_weight[i];
//		cin >> bag01_val[i];
//	}
//
//	for (int i = 1; i <=n; i++) {
//		for (int j = 1; j <=v;j++ ) {
//			bag01_ret[i][j] =bag01_ret[i - 1][j];
//			//优化
//			//int ind=i%2,rind=(i-1)%2//模拟当前状态和上一个状态
//			//bag01_ret_plus[ind][j]=bag01_ret_plus[rind][j];//当前状态值等于上一个状态值
//			if (j < bag01_weight[i])continue;
//			bag01_ret[i][j] = max(bag01_ret[i][j], bag01_ret[i - 1][j - bag01_weight[i]] + bag01_val[i]);
//			//用[i-1][j - bag01_weight[i]]是为了因为要使用第i种物品，所以我们要为第i种物品留出空间
//			//也就是我们要计算i-1种物品，用了j - bag01_weight[i]的空间的价值
//			//优化
//			//bag01_ret_plus[ind][j]=max(bag01_ret_plus[ind][j],bag01_ret_plus[rind][j-bag01_weight[i]]+bag01_val[i])
//			//比较当前状态值和上一个状态值所对应的减去当前物品重量所得到的价值加上本物品的价值
//			//其实就是未优化的bag01_ret[i][j] = max(bag01_ret[i][j], bag01_ret[i - 1][j - bag01_weight[i]] + bag01_val[i]);
//			//只是把大数组改编成了滚动数组
//			//能改的原因是数组的值只与weight和val的值有关，跟是第i件物品无关
//			//所以把第i件物品从105改变成2 变成了滚动数组
//		}
//	}
//	cout << bag01_ret[n][v];
//	//优化
//	//cout << bag01_ret_plus[n%2][v];
//	return 0;
//}

//优化plusplus
//优化plusplus
long long bag01_ret_plusplus[10005] = { 0 };//二维数组优化成一维数组
//int main() {
//	int v, n;
//	cin >> v >> n;
//	for (int i = 1, weight, val; i <= n; i++) {
//		cin >> weight >> val;//直接读入是因为发现求解状态值的时候只需要读取本轮的值，用不到其他的值，所以没必要提前读入
//		//优化plusplus
//		for (int j = v; j >= weight; j--) {
//			bag01_ret_plusplus[j] = max(bag01_ret_plusplus[j], bag01_ret_plusplus[j - weight] + val);
//		}
//		//此处倒序是为了防止因为bag01_ret_plusplus[j-weight]的值更新，导致 bag01_ret_plusplus[j]的值更新，所以倒序
//	}
//	//优化plusplus
//	cout << bag01_ret_plusplus[v];
//	return 0;
//}
