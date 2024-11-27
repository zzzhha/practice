#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<easyx.h>

using namespace std;

//���P1541
//dp[a][b][c][d]������Ϊ1�Ŀ�Ƭ����a�ţ�����Ϊ2�Ŀ�Ƭ����b�ţ�����Ϊ3�Ŀ�Ƭ����c�ţ�����Ϊ4�Ŀ�Ƭ����d�� 
int tortoise[355];
int card[45][45][45][45];

//int main() {
//	int n, m;
//	cin >> n >> m;
//	int nums[4] = { 0 };
//	for (int i = 0; i < n; i++) {
//		cin >> tortoise[i];
//	}
//	for (int i = 0; i < m; i++) {
//		int x;
//		cin >> x;
//		nums[x]++;
//	}
//	int step = 0;
//	card[0][0][0][0] = tortoise[0];
//	for (int i = 0; i <= nums[0]; i++) {
//		for (int j = 0; j <= nums[1]; j++) {
//			for (int k = 0; k <= nums[2]; k++) {
//				for (int l = 0; l <= nums[3]; l++) {
//					int s = i + 2 * j + 3 * k + 4 * l;
//					card[i][j][k][l] = tortoise[s];
//					int ans = 0;
//					if (i) ans = max(ans, card[i - 1][j][k][l]);
//					if (j) ans = max(ans, card[i][j - 1][k][l]);
//					if (k) ans = max(ans, card[i][j][k - 1][l]);
//					if (l) ans = max(ans, card[i][j][k][l - 1]);
//					card[i][j][k][l] = ans + tortoise[s];
//				}
//			}
//		}
//	}
//	cout << card[nums[0]][nums[1]][nums[2]][nums[3]]<<endl;
//	return 0;
//}

//�Ż�����״̬:��ʱ�临�Ӷ���Ӱ�죬���Կռ临�Ӷ���Ӱ��
//�����ù������飬����ά�����Ż�����ά
//ԭ����Ϊans���бȽϵ�ʱ��ֻ���õ���ǰֵ����һ��ֵ��������ֵ��������ֵ�޹�

//�������ǿ��Խ���һά�Ż���[2]
//������0/1������֪�������[2]����ֱ���Ż�û
//ֻ��Ҫ����ǰԪ�ر�ʾΪ��ǰ״̬��δ���£�������ǰ����һ��״̬���Ѹ��£����бȽϣ�����
//�磺if (i) ans = max(ans, card[i][j][k][l]);
//�Ż���if (i) ans = max(ans, card[j][k][l]);
//ֻ�Ǹı���int ans = card_plus[j][k][l];
//��仰�����˵�ǰ״̬Ϊjkl����δ����
//�����ȽϵĶ���[j-1]����[k-1]����[l-1]����Щ״̬����jkl֮ǰ��
//������е���jkl��״̬��˵��������״̬���Ѿ������¹���
//�����������Ѹ���״̬��jkl��δ����״̬
int card_plus[45][45][45];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int nums[4] = { 0 };
//	for (int i = 0; i < n; i++) {
//		cin >> tortoise[i];
//	}
//	for (int i = 0; i < m; i++) {
//		int x;
//		cin >> x;
//		nums[x]++;
//	}
//	int step = 0;
//	card[0][0][0][0] = tortoise[0];
//	for (int i = 0; i <= nums[0]; i++) {
//		for (int j = 0; j <= nums[1]; j++) {
//			for (int k = 0; k <= nums[2]; k++) {
//				for (int l = 0; l <= nums[3]; l++) {
//					int s = i + 2 * j + 3 * k + 4 * l;
//					int ans = card_plus[j][k][l];
//					if (i) ans = max(ans, card_plus[j][k][l]);
//					if (j) ans = max(ans, card_plus[j - 1][k][l]);
//					if (k) ans = max(ans, card_plus[j][k - 1][l]);
//					if (l) ans = max(ans, card_plus[j][k][l - 1]);
//					card_plus[j][k][l] = ans + tortoise[s];
//				}
//			}
//		}
//	}
//	cout << card_plus[nums[1]][nums[2]][nums[3]] << endl;
//	return 0;
//}