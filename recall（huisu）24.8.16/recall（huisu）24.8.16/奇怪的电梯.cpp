#include<iostream>

using namespace std;

//���1135 �ѣ�



int to[205];

//��¼��a�����i����̾��루��֪����̾��룩
int dis[205] = { 0 };

//��һ����������ǰ����a���˼���
//�ڶ�����������ǰ���ĸ���
//������������ܽ������
void dfs(int k, int a,int n) {
	if (dis[a] <= k) return;//������ڵ���̾��������֪����̾��룬˵�����������Ž⣬����ֱ�ӷ���
	dis[a] = k;
	if (a + to[a] <= n)dfs(k + 1, a + to[a], n);
	if (a - to[a] >= 1)dfs(k + 1, a - to[a], n);
	return;
}

//int main() {
//	int n, a, b;//n�Ƕ��ٲ�¥,a�ǵڼ��㣬b��Ŀ�����
//	cin >> n >> a >> b;
//	for (int i = 1; i <= n; i++) {
//		cin >> to[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		dis[i] = n + 1;//��֪���ݵ����ֵ��Ϊn�����Դ�ʱ��ʼ�����ֵ�Ϳ��Գ�ʼ��Ϊn+1
//	}
//	dfs(0,a,n);//������Ϻ���Եõ�a�㵽�����е����̾���
//	cout << (dis[b] == n + 1 ? -1 : dis[b]);
//	return 0;
//}