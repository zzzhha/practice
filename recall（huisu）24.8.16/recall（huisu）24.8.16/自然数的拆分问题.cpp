#include<iostream>
#include<vector>
using namespace std;

//P2404  ��
int add_st[15];

void dfs_nature(int i, int j, int n, int sum) //�˵ݹ麯����ʾ��i��λ����С���õ�Ԫ��Ϊj����󲻳���n
{
	if (sum == n) {//�߽�����
		for (int x = 0; x < i; x++) {
			cout << add_st[x];
			if (x + 1 != i) {
				cout << "+";
			}
		}
		cout << endl;
		return;
	}
	for (int k = j; k < n; k++)
	{
		if (j + sum > n)//��֦
			return;
		add_st[i] = k;			
		dfs_nature(i + 1, k, n ,sum+k);//������һ�εݹ飬i+2��ʾ���Ǹ�λ�ã�k��ʾ��ǰ��С����Ϊ����
	}
	return;
}

int aans[20] = { 0 };

void print(int n) {
	if (n < 2)return;
	for (int i = 0; i < n; i++) {
		if (i)cout << "+";
		cout << aans[i];
	}
	cout << endl;
	return;
}

//k�ǲ�����sum�ǵ�ǰ����n��ʣ�����������n��ȥ��ǰ����
void dfs_zi(int k, int s_num, int n) {
	if (n == 0) {
		print(k);
		return;
	}
	if (s_num > n)
		return;
	for (int i = s_num; i <= n; i++) {
		aans[k] = i;
		dfs_zi(k + 1, i, n - i);
	}
	return;
}

//int main() {
//	int n;
//	cin >> n;
//	dfs_zi(0, 1, n);
//	dfs_nature(0, 1, n, 0);
//	return 0;
//}
