#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int rectangle[105][105];
int linetangle[105][105];

//����OJ 258
//int main() {
//	int n;
//	cin >> n;
//	int x = 1;
//	int y = 1; 
//	int max=-130;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cin >> rectangle[i][j];//��������е�ÿ��ֵ
//			rectangle[i][j] += rectangle[i - 1][j];//�������е�ÿ��ֵ��Ϊ�����е�ǰ׺��ֵ
//		}
//	}
//	int ans = INT_MIN;
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j <= n; j++) {
//			int s = 0;
//			for (int k = 1; k <= n; k++) {
//				int a = rectangle[j][k] - rectangle[i - 1][k];
//				if (s >= 0)s += a;
//				else s = a;
//				if (s > ans)ans = s;
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}