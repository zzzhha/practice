#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


//海贼OJ 255
double xiaodao[1005][2];//小岛对应x轴汇中雷达能照射到的范围
double zuobiao[1005];//中转站（防止打字太多）（可以不加）
int pos[1005];
//int main() {
//	int n;
//	double d;
//	cin >> n >> d;
//	for (int i = 0; i < n; i++) {
//		double x, y;
//		cin >> x >> y;
//		xiaodao[i][0] = x;
//		xiaodao[i][1] = y;
//		if (d  < xiaodao[i][1])
//		{
//			cout << -1;
//			return 0;
//		}
//		zuobiao[i] = sqrt(d * d - xiaodao[i][1] * xiaodao[i][1]);
//		xiaodao[i][1] = xiaodao[i][0] - zuobiao[i];
//		xiaodao[i][0] = xiaodao[i][0] + zuobiao[i];//再改成记录x轴对应范围
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n-1; j++) {
//			if (xiaodao[j][0] > xiaodao[j + 1][0]) {
//				swap(xiaodao[j][0], xiaodao[j + 1][0]);
//				swap(xiaodao[j][1], xiaodao[j + 1][1]);//先记录小岛坐标点
//			}
//		}
//	}
//	double leida = xiaodao[0][0];//最右边的小岛所能对应的最右边的x轴
//	int count = 1;
//	for (int i = 1; i < n; i++) {
//		if (leida < xiaodao[i][1]) {
//			leida = xiaodao[i][0];//相当于在最左边放置一个雷达
//			count++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}  