#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//���P1057

//�����ƣ�f��i)(j) ����j�����ڵ�i�˵ķ�����

//f(j)(i)=f(j-1)(i+1)+f(j-1)(i-1)

int TPball[35][35]={0};

//int main() {
//	int n, m;
//	cin >> n >> m;
//	TPball[0][1] = 1;
//	for (int j = 1; j <= m; j++) {//j�ִ���
//		for (int i = 2; i < n; i++) {
//			TPball[j][i] = TPball[j - 1][i - 1] + TPball[j - 1][i + 1];
//		}
//		TPball[j][1] = TPball[j - 1][2] + TPball[j - 1][n];
//		TPball[j][n] = TPball[j - 1][1] + TPball[j - 1][n - 1];
//	}
//	cout << TPball[m][1] << endl;
//	return 0;
//}