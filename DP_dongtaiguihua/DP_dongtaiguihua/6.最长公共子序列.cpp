#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//����OJ 45

int pq[1005][1005];
//dp(i,j)����a������Ϊiλ��Ϊ��β��b������Ϊjλ��Ϊ��β�������г���

//int main() {
//	string a, b;
//	cin >> a >> b;
//	a = "@" + a;
//	b = "#" + b;//�����һ���ַ���Ϊ�˷�ֹ����pq[i-1]����׼��
//	//Ҳ���Ա����ں��������ʱ������±��ƫ��
//	int len_a = a.length()-1;
//	int len_b = b.length()-1;
//	for (int i = 1; i <= len_a; i++) {
//		for (int j = 1; j <= len_b; j++) {
//			pq[i][j] = max(pq[i - 1][j], pq[i][j - 1]);
//			if (a[i] == b[j]) {
//				pq[i][j] = max(pq[i][j], pq[i - 1][j - 1] + 1);
//			}
//		}
//	}
//	cout << pq[len_a][len_b];
//	return 0;
//}