#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
//����(a+b)%2����ͬ��Ч��
//int nm[1030] = { 1 };
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < pow(2, n)/*1<<n*/; ++i) {
//		for (int j = 1; j < pow(2,n) - i; ++j) cout << " ";//ǰ���ո�
//		
//		for (int j = i; j >= 0; --j) nm[j] ^= nm[j - 1];//�޸�����
//		
//		if (!(i % 2))for (int j = 0; j <= i; ++j)cout << (nm[j] ? "/\\" : "  ");//������
//		
//		else for (int j = 0; j <= i; j += 2) cout << (nm[j] ? "/__\\" : "    ");//ż����
//		
//		cout << endl;
//	}
//	return 0;
//}
char a[3000][3000];//1024 1024
int h = 2, w = 4;//h�Ǹ�,w�ǿ�
//int main() {
//	int n;
//	cin >> n;
//	memset(a, ' ', sizeof(a)); 
//	a[1][1] = a[1][4] = ' ';
//	a[1][2] = a[2][1] = '/';
//	a[1][3] = a[2][4] = '\\';//���ҵĻ���������ĺ���
//	a[2][2] = a[2][3] = '_';
//	for (int i = 1; i < n; i++) {
//		//���º�����
//		for (int j = 1; j <= h; j++) {
//			for (int k = 1; k <= w; k++) {
//				a[j + h][k] = a[j + h][k + w] = a[j][k];
//				a[j][k] = ' ';//����������
//			}
//		}
//		//����
//		for (int j = 1; j <= h; j++) {
//			for (int k = 1; k <= w; k++) {
//				a[j][k + w / 2] = a[j + h][k];
//			}
//		}
//		w *= 2, h *= 2;
//		//ˢ�����һ��
//	}
//	for (int i = 1; i <= h; i++) {
//		for (int j = 1; j <= w; j++) {
//			cout << a[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}