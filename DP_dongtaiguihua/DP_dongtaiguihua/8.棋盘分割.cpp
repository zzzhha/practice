#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<easyx.h>

using namespace std;

 //����OJ 360
//dp[n][i][j][k][l] i,j�Ǿ�������Ͻ� k,l�Ǿ�������½�
//ͨ����4����ȥȷ��һ������n�����������ֳ�n��
int disboard[10][10] = { 0 };//�����Ǵ������̣���¼ÿ��λ�õ���ֵ
//�˴�Ϊ�˼����㣬���洢��ֵ��Ϊ��ά�����ǰ׺��ֵ
int disdp[20][10][10][10][10] = { 0 };
IMAGE disboardphoto;
#define INF 0x3f3f3f3f
int S(int x) {//����ƽ����
	return x * x;
}

int VAL(int i, int j, int k, int l) {
	//val�����������ӣ�i,j������k,l����ֵ
	//��Ϊdisboard[k][l]�����˴�00��kl������ǰ׺��
	//����������Ҫ��ȥ�ٺ͢ڵ�������
	//��������������ˢۣ������ڼ�һ����
	loadimage(&disboardphoto,"photo/VAL����ͼʾ.jpg",100,100);
	return disboard[k][l] - disboard[k][j - 1] - disboard[i - 1][l] + disboard[i - 1][j - 1];
}

//int main() {
//	int n;
//	cin >> n;
//	//��ά����ǰ׺����ͼ��ʾ��i��j��ʾ��ǰλ�ã�����ǰ׺�͵��ں�ɫ���ּ���ɫ�����ټ�ȥͨ�õ��ǲ���
//	loadimage(&disboardphoto, "photo/��ά����ǰ׺��.jpg", 100, 100);
//	//�����ά����ǰ׺��
//	for (int i = 1; i <= 8; i++) {
//		for (int j = 1; j <= 8; j++) {
//			cin >> disboard[i][j];
//			disboard[i][j] += disboard[i - 1][j] + disboard[i][j - 1] - disboard[i - 1][j - 1];//��ά�����ǰ׺��ֵ
//		}
//	}
//	for (int i = 1; i <= 8; i++) {
//		for (int j = 1; j <= 8; j++) {
//			for (int k = i; k <= 8; k++) {
//				for (int l = j; l <= 8; l++) {
//					disdp[1][i][j][k][l] = S(VAL(i, j, k, l));
//				}
//			}
//		}
//	}
//	for (int t = 2; t <= n; t++) {
//		for (int i = 1; i <= 8; i++) {
//			for (int j = 1; j <= 8; j++) {
//				for (int k = i; k <= 8; k++) {
//					for (int l = j; l <= 8; l++) {
//						int ans = INF;
//						//�˴����ǿ�ʼö��������
//						loadimage(&disboardphoto, "photo/������.jpg", 100, 100);
//						for (int c = j; c < l; c++) {
//							//�Ѣٷ�Ϊ1�飬�Ѣڷ�Ϊt-1��
//							int val1 = disdp[1][i][j][k][c] + disdp[t - 1][i][c + 1][k][l];
//							//�Ѣڷ�Ϊ1�飬�Ѣٷ�Ϊt-1�飨�٢ڿ�ͼƬ��
//							int val2 = disdp[t - 1][i][j][k][c] + disdp[1][i][c + 1][k][l];
//							ans = min(ans, min(val1, val2));
//						//��ʱ������������е�����õ���Сֵ
//						}
//						//�˴����ǿ�ʼö�ٺ�����
//						loadimage(&disboardphoto, "photo/������.jpg", 100, 100);
//						for (int c = i; c < k; c++) {
//							int val1 = disdp[1][i][j][c][l] + disdp[t - 1][c + 1][j][k][l];
//							int val2 = disdp[t - 1][i][j][c][l] + disdp[1][c + 1][j][k][l];
//							ans = min(ans, min(val1, val2));
//						}
//						disdp[t][i][j][k][l] = ans;
//					}
//				}
//			}
//		}
//	}
//	cout << disdp[n][1][1][8][8];//����������Ϊ�����̷�Ϊn�飬�����Ͻ�1 1�������½� 8 8,���ܵõ������ƽ������Сֵ
//	return 0;
//}