#include<iostream>
#include<algorithm>

using namespace std;

 //��̬�滮���ĸ����ʣ��׶Σ�״̬���޺�Ч�ԣ�����

//����OJ 43

//��һ�ַ���
//�������Ͽ�ʼͳ�ƣ��ȴ�ֵ���ٰ�����µ�һ�����鸳��ret���飬ret��n-1�п�ʼ��̬�ݹ飬��õ�ǰ�����ֵ

int triangle_val[1005][1005];
int triangle_ret[1005][1005];
 
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= i; j++) {
//			cin >> triangle_val[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		triangle_ret[n][i] = triangle_val[n][i];
//	}
//	for (int i = n - 1; i >= 1; i--) {
//		for (int j = 1; j <= i; j++) {
//			triangle_ret[i][j] = max(triangle_ret[i + 1][j], triangle_ret[i + 1][j + 1] )+triangle_val[i][j];
//		}
//	}
//	//for (int i = 1; i <= n; i++) {
//	//	for (int j = 1; j <= i; j++) {
//	//		cout<< triangle_ret[i][j]<<" ";
//	//	}
//	//	cout << endl;
//	//}
//	cout << triangle_ret[1][1] << endl;
//	return 0;
//}

//�ڶ������� ��������

//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= i; j++) {
//			cin >> triangle_val[i][j];
//		}
//	}
//	triangle_ret[1][1] = triangle_val[1][1];
//	for (int i = 2; i <= n; i++) {
//		for (int j = 2; j <= i-1; j++) {
//			triangle_ret[i][j] = max(triangle_ret[i -1][j], triangle_ret[i -1][j -1] )+triangle_val[i][j];
//		}
//		triangle_ret[i][1] = triangle_ret[i - 1][1] + triangle_val[i][1];
//		triangle_ret[i][i] = triangle_ret[i - 1][i - 1] + triangle_val[i][i];
//	}
//	int ans = triangle_ret[n][1];
//	for (int i = 2; i <= n; i++) {
//		if (triangle_ret[n][i] > ans)
//			ans = triangle_ret[n][i];
//	}
//	cout << ans;
//	return 0;
//}