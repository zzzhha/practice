#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


//����OJ 255
double xiaodao[1005][2];//С����Ӧx������״������䵽�ķ�Χ
double zuobiao[1005];//��תվ����ֹ����̫�ࣩ�����Բ��ӣ�
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
//		xiaodao[i][0] = xiaodao[i][0] + zuobiao[i];//�ٸĳɼ�¼x���Ӧ��Χ
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n-1; j++) {
//			if (xiaodao[j][0] > xiaodao[j + 1][0]) {
//				swap(xiaodao[j][0], xiaodao[j + 1][0]);
//				swap(xiaodao[j][1], xiaodao[j + 1][1]);//�ȼ�¼С�������
//			}
//		}
//	}
//	double leida = xiaodao[0][0];//���ұߵ�С�����ܶ�Ӧ�����ұߵ�x��
//	int count = 1;
//	for (int i = 1; i < n; i++) {
//		if (leida < xiaodao[i][1]) {
//			leida = xiaodao[i][0];//�൱��������߷���һ���״�
//			count++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}  