#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;

//P2392
int s[4];//4����Ŀ
int s1[4][25];//[0][]��һ����Ŀ��ϰ�⼯�����������ÿ���⻨��ʱ��

//[1][]�ڶ���ϰ�⼯ .......TODO(1)
int annss = 0;
//void fojiao() {//������
//	for (int i = 0; i < 4; i++) {
//		if (s[i] == 1)
//			annss += s1[i][0];
//		else if (s[i] == 2)
//			annss += max(s1[i][0], s1[i][1]);
//		else {
//			sort(&s1[i][0], &s1[i][s[i]]);
//			int x = 0;
//			int y = s[i] - 1;
//			while (y > x)
//			{
//				int maax = s1[i][y];
//				while (maax > s1[i][x] && y > x) {
//					maax -= s1[i][x];
//					x++;
//				}
//				annss += s1[i][y];
//				s1[i][x] -= maax;
//				if (y == x) {
//					annss += maax;
//				}
//				else if (y - x == 1) {
//					annss += s1[i][x];
//				}
//				y--;
//				if (y - x == 1) {
//					annss += s1[i][y];
//				}
//
//			}
//		}
//	}
//}

int aannss = INT_MAX;
//x�����㣬k������ĵڼ�������,l�������Դ�������ݵ�ʱ��,r�������Դ�������ݵ�ʱ��
void dfs_ling(int k, int x, int l,int r) {
	if (k == s[x]) {
		aannss = min(aannss, max(l, r));
		return;
	}
	//����ǰ��Ŀ�������Դ������еݹ�����һ���⣬�ݹ�����󣬽�������˳�
	l += s1[x][k];
	dfs_ling(k + 1, x, l, r);
	l -= s1[x][k];
	//�ѵ�ǰ��Ŀ�������Դ������еݹ�����һ���⣬�ݹ�������˳����⡣
	r += s1[x][k];
	dfs_ling(k + 1, x, l, r);
	r -= s1[x][k];
	//�������ݹ飬���������򿴾����Ȱ��������ݴ�ŵ�������
	//Ȼ���𽥰������˳������ݷ��������У��൱�������Դ���ͬ������
	//��ʱkֵ�ﵽs[x]ʱ������ʱ����С��aannss�Ϳ�ʼͳ�����Ž���
	//���������ݶ������������ֻ�ʹ��ʱ��䳤������ans�����¼

	return;
}

//int main() {
//	for (int i = 0; i < 4; i++) {//TODO(4)
//		cin >> s[i];
//	}
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < s[i]; j++) {
//			cin >> s1[i][j];
//		}
//	}
//	//fojiao();
//	int total = 0;
//	for (int i = 0; i < 4; i++) {
//		dfs_ling(0, i, 0, 0);
//		total += aannss;
//	}
//	cout << total;
//	return 0;
//}
unordered_map<int, int>ind;
int sum[10] = { 0 };//�洢4�θ�ϰ�Ứ����ʱ��
int solve(int k) {
	int ans = INT_MAX;
	int T = (1 << s[k]) - 1;//����ֵ

	//��ʵ���forѭ�����ڷ�������Ļ���
	//iΪʲôС�ڵ���T������ֵ��������Ϊ
	//�������ǵ�i�ͻ�õ���1��T���еĶ����Ƶ�ȫ����
	//���ݲ�ͬ�Ķ����ƣ����Ծͻ���䲻ͬ��ϰ��
	//����ͨ��sum�洢�� ÿ�λ�����ʱ��-���Ի��ѵ�ʱ�䣬�Ϳ��Եõ�������Ҫ���ѵ�ʱ��
	//������������Է��䲻ͬ��Ŀ��Ŀ��
	//ans����ÿ��ѭ����ȥȡ����Сֵ���õ�����Ŀ����������ʱ��Ľⷨ
	//ͨ��slove��������4��ѭ�����Ϳ��Եõ��ܵ����ʱ��
	//�ʹﵽ�˽����Ŀ��
	for (int i = 0; i < T; i++) {
		int j = i;
		int l = 0;
		int r = 0;
		while (j) {
			l += s1[k][ind[j & -j]];//�������ֵ������λ���λ1����Ӧ�±� �������д洢��ֵ
			j -= (j & -j);
		}
		r = sum[k] - l;
		ans = min(ans, max(l, r));
	}
	return ans;
}


int main() {
	for (int i = 0; i < 4; i++) {
	cin >> s[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < s[i]; j++) {
			cin >> s1[i][j];
			sum[i] += s1[i][j];//ͳ������ʱ�䣿
		}
	}
	for (int k = 1, i = 0; i <= 20; i++, k *= 2) {
		ind[k] = i;
	}
	int aa = 0;
	for (int i = 0; i < 4; i++) {
		aa += solve(i);
	}

	return 0;
}
