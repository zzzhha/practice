#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
#include<easyx.h>

using namespace std;

//HZOJ 49

int manybag_p[100000 + 5];

//��һ�ַ���
//ʹ�����ƶ����Ƶķ�����ģ����Ʒ�ж��
//���籾��Ʒ��14��
//�������ֳܷ� 1 2 4 8
//���Ǵ˴�8����ȡ����Ϊ1+2+4+8>14
//������1 2 4 7
//�⼸�����־���ģ��1-14���������
//
//int main() {
//	int V, n;
//	cin >> V >> n;
//	for (int i = 0,v,w,s; i < n; i++) {
//		cin >> v >> w >> s;
//		for (int k = 1; s; s-=k, k *= 2){
//			k = min(s, k);
//			for (int j = V; j >= k * v; j--) {
//				manybag_p[j] = max(manybag_p[j], manybag_p[j - k * v] + k * w);
//			}
//		}
//
//	}
//	cout << manybag_p[V];
//	return 0;
//}

//�ڶ�������
int muchbag_p[105][100005];
//ʱ�临�Ӷ� O(nV)��01�������Ӷ�һ��
//int main() {
//	int V, n;
//	cin >> V >> n;
//	for (int i = 1, v, w, s; i <= n; i++) {
//		cin >> v >> w >> s;
//		for (int r = 0; r < v; r++) {
//			deque<int> q;
//			for (int j = r; j <= V; j += v) {
//				muchbag_p[i - 1][j] -= j / v * w;
//				while (!q.empty() && muchbag_p[i - 1][q.back()] < muchbag_p[i - 1][j])q.pop_back();
//				q.push_back(j);
//				if ((j - q.front()) / v > s)q.pop_front();
//				muchbag_p[i][j] = muchbag_p[i - 1][q.front()] + j / v * w;
//			}
//		}
//	}
//	cout << muchbag_p[n][V];
//	return 0;
//}