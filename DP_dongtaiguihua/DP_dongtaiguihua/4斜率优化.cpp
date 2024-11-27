#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
//int printer_val[100006];
//int printer[100006];
//HZOJ 52

//int main() {
//	int n,M;
//	cin >> n >> M;
//	for (int i = 1; i <= n; i++) {
//		cin >> printer_val[i];
//		printer_val[i] += printer_val[i - 1];
//		printer[i] = printer_val[i] * printer_val[i] + M;
//		for (int k = 2; k <= n; k++) {
//			for (int i = 0; i < n; i++) {
//				printer[k] = min(printer[k], printer[i]+(int)pow(printer_val[k] - printer_val[i], 2) + M);
//			}
//		}
//	}
//	cout << printer[n];
//	return 0;
//}


//ÓÅ»¯
//long long pp[1000000 + 5],sum[1000000+5];
//long long dpp[1000000 + 5], f[1000000+5];
//int que[1000000 + 5], head, tail;
//long long  n, M;
//
//double slope(int i, int j) {
//	return 1.0 * (f[i] - f[j]) /(sum[i] - sum[j]);
//}
//
//void set(int i, int j) {
//	dpp[i] = dpp[j] +((sum[i] - sum[j]) * (sum[i] - sum[j])) + M;
//	f[i] = dpp[i] + sum[i] * sum[i];
//	return;
//}
//
//int main() {
//
//	cin >> n >> M;
//	for (int i = 1; i <= n; i++) {
//		cin >> pp[i];
//		sum[i] = sum[i - 1] + pp[i];
//	}
//	head = tail = 0;
//	que[tail++] = 0;
//	for (int i = 1; i <= n; i++) {
//		while (tail - head >= 2 && slope(que[head + 1], que[head]) < 2 * sum[i]) head += 1;
//		set(i, que[head]);
//		while (tail - head >= 2 && slope(que[tail - 1], que[tail - 2]) > slope(i, que[tail - 1])){
//			tail--;
//		}
//		que[tail++] = i;
//	}
//	cout << dpp[n];
//	return 0;
//}