#include<iostream>

using namespace std;


//���P1036  �ѣ�����
int g[25];
int count_sum=0;
long long all;//n<=20 k<n ���ֵΪc 20 10�����У����ܴ���int��Χ����������Ϊlonglong

bool isprime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
void dfs_x(int k, int ind, int n,int m,int sum) {
	if (k == m)//�����ȡ����m��������ô�㵱ǰsum�Ƿ�Ϊ����
	{
		if (isprime(sum))
			all++;
		return;
	}
	//��ѭ���ɲο������ö��
	for (int i = ind; i < n; i++) {//���û��ȡ��m��������ô������ȡ��k+1��,��ȡ������Ӧ����i
		dfs_x(k + 1, i + 1, n, m, sum+g[i]);
	}
}

//int main() {
//	int n, k;
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)cin >> g[i];
//	dfs_x(0, 0, n, k, 0);//��һ��0��ʾ��ǰ����Ϊ��0�������ڶ���0��ʾ������������Ӧ�ö�ȡ�����Ǹ�����n����������k����һ���ܶ�ȡ���ٸ��������һ��0������������һ��0����ǰ������ȡ����������ܺ�
//	cout << all;
//	return 0;
//}