#include<iostream>
#include<algorithm>

using namespace std;

//���P1025

int figure[205][10] = { 0 };//������i��ֳ�j��
//�ݳ�ԭ���Ѳ�ֵ�����Ϊ��1����1����
//��1�ļ�ȥ���1����ô����i��Ҫ-1����i-1���ֳ�j�ݣ���Ϊ��ȥ�����1�����Ծͱ���˷ֳ�j-1��
//��1�ģ�˵����ֵ����ֶ�����1����ô���ǽ���ֵ����ֶ�-1������i�ͳ���i-j�������j�ݣ���Ҫ��ȥj��1����j����
//��Ϊ�����ݲ��ص�������ӵ���ȫ��������֤��
//�������Ǿ͵õ���figure[i][j] = figure[i - 1][j - 1] + figure[i - j][j]
//int main() {
//	int n, k;
//	cin >> n >> k;
//	int count = 0;
//	figure[0][0] = 1;
//	for (int i = 1; i <= n; i++) {
//		figure[i][1] = 1;//�������ֲ��1�ݶ�ֻ��1��
//		for (int j = 1,J=min(i,k); j <= J; j++) {//J��������ܲ�ɼ���	
//			figure[i][j] = figure[i - 1][j - 1] + figure[i - j][j];
//		}
//	}
//	cout << figure[n][k] << endl;
//	return 0;
//}