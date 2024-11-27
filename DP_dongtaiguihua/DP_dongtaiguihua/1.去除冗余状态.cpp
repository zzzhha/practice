#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<easyx.h>

using namespace std;

//洛谷P1541
//dp[a][b][c][d]代表步数为1的卡片用了a张，步数为2的卡片用了b张，步数为3的卡片用了c张，步数为4的卡片用了d张 
int tortoise[355];
int card[45][45][45][45];

//int main() {
//	int n, m;
//	cin >> n >> m;
//	int nums[4] = { 0 };
//	for (int i = 0; i < n; i++) {
//		cin >> tortoise[i];
//	}
//	for (int i = 0; i < m; i++) {
//		int x;
//		cin >> x;
//		nums[x]++;
//	}
//	int step = 0;
//	card[0][0][0][0] = tortoise[0];
//	for (int i = 0; i <= nums[0]; i++) {
//		for (int j = 0; j <= nums[1]; j++) {
//			for (int k = 0; k <= nums[2]; k++) {
//				for (int l = 0; l <= nums[3]; l++) {
//					int s = i + 2 * j + 3 * k + 4 * l;
//					card[i][j][k][l] = tortoise[s];
//					int ans = 0;
//					if (i) ans = max(ans, card[i - 1][j][k][l]);
//					if (j) ans = max(ans, card[i][j - 1][k][l]);
//					if (k) ans = max(ans, card[i][j][k - 1][l]);
//					if (l) ans = max(ans, card[i][j][k][l - 1]);
//					card[i][j][k][l] = ans + tortoise[s];
//				}
//			}
//		}
//	}
//	cout << card[nums[0]][nums[1]][nums[2]][nums[3]]<<endl;
//	return 0;
//}

//优化冗余状态:对时间复杂度无影响，但对空间复杂度有影响
//本题用滚动数组，将四维数组优化成三维
//原理：因为ans进行比较的时候，只会用到当前值和上一个值，这两个值，与其他值无关

//所以我们可以将第一维优化成[2]
//而根据0/1背包可知道，这个[2]可以直接优化没
//只需要将当前元素表示为当前状态（未更新），与以前的上一个状态（已更新）进行比较，即可
//如：if (i) ans = max(ans, card[i][j][k][l]);
//优化成if (i) ans = max(ans, card[j][k][l]);
//只是改变了int ans = card_plus[j][k][l];
//这句话代表了当前状态为jkl，还未更新
//而作比较的都是[j-1]或者[k-1]或者[l-1]，这些状态都在jkl之前，
//如果进行到了jkl此状态，说明这三个状态都已经被更新过了
//所以他们是已更新状态，jkl是未更新状态
int card_plus[45][45][45];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int nums[4] = { 0 };
//	for (int i = 0; i < n; i++) {
//		cin >> tortoise[i];
//	}
//	for (int i = 0; i < m; i++) {
//		int x;
//		cin >> x;
//		nums[x]++;
//	}
//	int step = 0;
//	card[0][0][0][0] = tortoise[0];
//	for (int i = 0; i <= nums[0]; i++) {
//		for (int j = 0; j <= nums[1]; j++) {
//			for (int k = 0; k <= nums[2]; k++) {
//				for (int l = 0; l <= nums[3]; l++) {
//					int s = i + 2 * j + 3 * k + 4 * l;
//					int ans = card_plus[j][k][l];
//					if (i) ans = max(ans, card_plus[j][k][l]);
//					if (j) ans = max(ans, card_plus[j - 1][k][l]);
//					if (k) ans = max(ans, card_plus[j][k - 1][l]);
//					if (l) ans = max(ans, card_plus[j][k][l - 1]);
//					card_plus[j][k][l] = ans + tortoise[s];
//				}
//			}
//		}
//	}
//	cout << card_plus[nums[1]][nums[2]][nums[3]] << endl;
//	return 0;
//}