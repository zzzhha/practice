#include<iostream>
#include<algorithm>

using namespace std;

//洛谷P1025

int figure[205][10] = { 0 };//将数字i拆分成j份
//容斥原理：把拆分的数分为有1和无1两种
//有1的减去这个1，那么数字i就要-1，得i-1，分成j份，因为减去了这个1，所以就变成了分成j-1份
//无1的，说明拆分的数字都大于1，那么我们将拆分的数字都-1，数字i就成了i-j（拆成了j份，就要减去j个1），j不变
//因为这两份不重叠，且相加等于全集，所以证毕
//于是我们就得到了figure[i][j] = figure[i - 1][j - 1] + figure[i - j][j]
//int main() {
//	int n, k;
//	cin >> n >> k;
//	int count = 0;
//	figure[0][0] = 1;
//	for (int i = 1; i <= n; i++) {
//		figure[i][1] = 1;//所以数字拆成1份都只有1种
//		for (int j = 1,J=min(i,k); j <= J; j++) {//J代表最多能拆成几份	
//			figure[i][j] = figure[i - 1][j - 1] + figure[i - j][j];
//		}
//	}
//	cout << figure[n][k] << endl;
//	return 0;
//}