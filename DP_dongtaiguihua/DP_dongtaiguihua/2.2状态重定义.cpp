#include<iostream>
#include<algorithm>

using namespace std;

//����OJ 50 

//dp(i,j) ǰi��������j��¥��������ٴ���
//dp(i,j)=min{max(dp[i][j-k],dp[i-1][k-1])}+1
// k����ǰ¥�� k����[1,j]
// dp[i][j-k]����û�飬��ô���Ǿ���Ҫ�ٲ��Ϸ���j-k��
// dp[i-1][k-1]�������ˣ�˵������Ҫ���·���k-1��
// ��˵�ĵ�����������������������Ҫȡһ�����ֵ
// �����ٵĲ���������������min
// ����min���������е�k��ѡ��һ��max��С��ֵ

int egg[32 + 5][100000 + 5];

//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) egg[1][i] = i;//ֻ��һ������ʱ�������ж��ٲ�¥�����ǲ�¥�����
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			egg[i][j] = j;//������
//			for (int k = 1; k <= j; k++) {
//				egg[i][j] = min(egg[i][j], max(egg[i - 1][k - 1], egg[i][j - k]) + 1);
//			}
//		}
//	}
//	cout << egg[n][m];
//	return 0;
//}


//i����������k�Σ�����ܲ���ٲ�¥
//dp(i,k)=dp[i][k-1]+dp[i-1][k-1]+1
//dp[i-1][k-1]�������ˣ���������ֻ��i-1�����������ܲ�k-1��
//dp[i][k-1]����û�飬��������ֻ��i�����������ܲ�k-1��
//+1���Ҽ������ǵ�ǰ��¥��

long long egg_plus[32 + 5][1000 + 5];//�����1000ֻ��Ԥ�������

//int main() {
//	long long n, m;
//	cin >> n >> m;
//	if (n == 1) {
//		cout << m << endl;
//		return 0;//����ֻ��1��������ʱ��
//	}
//	for (int i = 1; i <= 1000; i++) egg_plus[1][i] = i;//ֻ��һ���������ܲ�¥����ǲ��Դ���
//	for (int i = 2; i <= n; i++) {//������
//		for (int j = 1; j <= 1000; j++) {//�ӵĴ���
//			egg_plus[i][j] = egg_plus[i][j - 1] + egg_plus[i - 1][j - 1] + 1;
//			if (egg_plus[i][j] > m) break;
//		}
//	}
//	int k = 1;
//	while (egg_plus[n][k] < m) k += 1;
//	cout << k << endl;
//	return 0;
//}

