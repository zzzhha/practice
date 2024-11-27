#include<iostream>
#include<algorithm>

using namespace std;

//海贼OJ 41墙壁涂色
//f[n][j]代表前n块墙壁，不考虑头尾成环的前提下，第一块涂颜色0，第n块涂颜色j的方法总数
//f[n][j]=f[n-1][k] (k!=j)从k=0到k=2求和]
//上述式子表示了第一块墙壁的颜色固定，能有多少种涂色方法
//结果只需要 乘颜色种类即可
//ans =3*(f[n][1]+f[n][2])
//需要大整数
//本题优化：状态重定义
//算法空间时间复杂度都有优化
//
//墙壁最多1000块，颜色最多10种
int wall_plus[1005][15];
//int main() {
//	int n, k;
//	cin >> n >> k;
//	wall_plus[1][0] = 1;//有一块墙壁，第一块涂第0种颜色
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j < k; j++) {
//			wall_plus[i][j] = 0;
//			//c代表第j-1块墙壁涂什么色
//			for (int c = 0; c < k; c++) {
//				if (c == j)continue;//不能涂j的色
//				//i-1块墙壁，最后涂c的颜色的和
//				wall_plus[i][j] += wall_plus[i - 1][c];
//			}
//		}
//	}
//	int sum = 0;
//	//把wall_plus[n][0]的值去除了是因为，我们的第一块墙固定涂了第0种颜色
//	for (int i = 1; i < k; i++) sum += wall_plus[n][i];
//	cout << sum * k;
//	return 0;
//}

//再次优化
//f[n]代表n块墙壁 收尾颜色不同的方法总数
//f[n]=f[n-1]+2*f[n-2] 
//从n-1块开始看
//容斥原理：n-1块颜色与第一块颜色 相同  / 不相同
//这样，最后一块的颜色只剩下      k-2种 /  k-1种
//如果颜色不同，那么f[n]的方法总数就是(k-2)*f[n-1]
//k-2代表最后一块能涂的颜色种类，f[n-1]可以由递推状态可知是n-1块墙壁能涂的颜色的方案总数
//如果颜色相同，则代表n-1块的颜色与第一块的颜色相同
//n-1块的颜色与第一块的颜色想通的方法总数就等于是说
//n-2块和第一块颜色不同的方案总数
//所以这部分的方法总数就是f[n]=f[n-2]*(k-1)
//k-1为第n块能涂的颜色
//所以f[n]=f[n-2]*(k-1)+f[n-1]*(k-2)
int wall_pp[1005];
//int main() {
//	int n, k;
//	cin >> n >> k;
//	wall_pp[1] = k;
//	wall_pp[2] = k * (k - 1);
//	wall_pp[3] = k * (k - 1) * (k - 2);
//	//根据下方的i-1 ，i-2我们可以知道要初始化1,2
//	//为什么要初始化3
//	//是因为我们在容斥原理中证明如果第一块颜色与n-1块颜色相同的时候
//	//我们用到了f[n-2]，此处的n-2颜色要与n-1颜色不同，也就是要与第一块颜色不同
//	//但是在只有三块墙壁中，n-2就是第一块墙壁，是一定和第一块墙壁颜色相同的
//	//所以必须先求出来
//	//第四块就不用了，四块的时候n-2=2，第二块墙壁与第一块墙壁链接，一定与第一块墙壁不同色
//
//	for (int i = 4; i <= n; i++) {
//		wall_pp[i] = wall_pp[i - 1] * (k - 2) + wall_pp[i - 2] * (k - 1);
//	}
//	cout << wall_pp[n] << endl;
//	return 0;
//}
