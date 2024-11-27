#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<easyx.h>

using namespace std;

 //海贼OJ 360
//dp[n][i][j][k][l] i,j是矩阵的左上角 k,l是矩阵的右下角
//通过这4个数去确定一个矩阵，n代表将这个矩阵分成n块
int disboard[10][10] = { 0 };//本来是代表棋盘，记录每个位置的数值
//此处为了简便计算，将存储的值改为二维数组的前缀和值
int disdp[20][10][10][10][10] = { 0 };
IMAGE disboardphoto;
#define INF 0x3f3f3f3f
int S(int x) {//计算平方和
	return x * x;
}

int VAL(int i, int j, int k, int l) {
	//val函数计算矩阵从（i,j）到（k,l）的值
	//因为disboard[k][l]计算了从00到kl的所有前缀和
	//所以我们需要减去①和②的两部分
	//但是这两块包括了③，所以在加一个③
	loadimage(&disboardphoto,"photo/VAL函数图示.jpg",100,100);
	return disboard[k][l] - disboard[k][j - 1] - disboard[i - 1][l] + disboard[i - 1][j - 1];
}

//int main() {
//	int n;
//	cin >> n;
//	//二维数组前缀和如图所示，i，j表示当前位置，他的前缀和等于红色部分加绿色部分再减去通用的那部分
//	loadimage(&disboardphoto, "photo/二维数组前缀和.jpg", 100, 100);
//	//计算二维数组前缀和
//	for (int i = 1; i <= 8; i++) {
//		for (int j = 1; j <= 8; j++) {
//			cin >> disboard[i][j];
//			disboard[i][j] += disboard[i - 1][j] + disboard[i][j - 1] - disboard[i - 1][j - 1];//二维数组的前缀和值
//		}
//	}
//	for (int i = 1; i <= 8; i++) {
//		for (int j = 1; j <= 8; j++) {
//			for (int k = i; k <= 8; k++) {
//				for (int l = j; l <= 8; l++) {
//					disdp[1][i][j][k][l] = S(VAL(i, j, k, l));
//				}
//			}
//		}
//	}
//	for (int t = 2; t <= n; t++) {
//		for (int i = 1; i <= 8; i++) {
//			for (int j = 1; j <= 8; j++) {
//				for (int k = i; k <= 8; k++) {
//					for (int l = j; l <= 8; l++) {
//						int ans = INF;
//						//此处我们开始枚举竖着切
//						loadimage(&disboardphoto, "photo/竖着切.jpg", 100, 100);
//						for (int c = j; c < l; c++) {
//							//把①分为1块，把②分为t-1块
//							int val1 = disdp[1][i][j][k][c] + disdp[t - 1][i][c + 1][k][l];
//							//把②分为1块，把①分为t-1块（①②看图片）
//							int val2 = disdp[t - 1][i][j][k][c] + disdp[1][i][c + 1][k][l];
//							ans = min(ans, min(val1, val2));
//						//此时完成求完竖着切的所求得的最小值
//						}
//						//此处我们开始枚举横着切
//						loadimage(&disboardphoto, "photo/横着切.jpg", 100, 100);
//						for (int c = i; c < k; c++) {
//							int val1 = disdp[1][i][j][c][l] + disdp[t - 1][c + 1][j][k][l];
//							int val2 = disdp[t - 1][i][j][c][l] + disdp[1][c + 1][j][k][l];
//							ans = min(ans, min(val1, val2));
//						}
//						disdp[t][i][j][k][l] = ans;
//					}
//				}
//			}
//		}
//	}
//	cout << disdp[n][1][1][8][8];//输出这个是因为把棋盘分为n块，从左上角1 1，到右下角 8 8,所能得到的求和平方的最小值
//	return 0;
//}