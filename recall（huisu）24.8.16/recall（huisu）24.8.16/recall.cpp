#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<list>
using namespace std;

//��ϰ�ݹ�

//ָ����ö��

int arr[10];

void print_one_result(int n) {
	for (int i = 0; i <= n; i++) {
		if (i)cout << " ";
		cout << arr[i];
	}
	cout << endl;
	return;
}

void exponential_enum(int i, int j ,int n) //�˵ݹ麯����ʾ��i��λ����С���õ�Ԫ��Ϊj����󲻳���n��ʵ�����е�ָ����ö��
{
	if (j > n)//�߽�����
		return;
	for (int k = j; k <= n; k++) 
	{
		arr[i] = k;
		print_one_result(i);//��ӡ��ǰarr���������Ԫ��
		exponential_enum(i + 1,k + 1, n);//������һ�εݹ飬i+1��ʾ���Ǹ�λ�ã�k+1��ʾ��ǰ��С����Ϊ����
	}
	return;
	
}


//�����ö��
int arr1[10];
void print_on_result(int n) {
	for (int i = 0; i < n; i++) {
		if (i)cout << " ";
		cout << arr1[i];
	}
	cout << endl;
	return;
}
void combinatorial_enum(int i, int j, int n, int k)//�˵ݹ麯����ʾ����i��λ����С����λj����������������k������󲻳���n 
{
	if (i == k)
	{
		print_on_result(k);
		return;
	}
	for (int q = j; q <= n; q++) {
		arr1[i] = q;
		combinatorial_enum(i + 1, q + 1, n, k);
	}

	return;
}

//������ö��
int arr2[10];
int vis[10] = { 0 };
void print_o_result(int n) {
	for (int i = 0; i < n; i++) {
		if (i)cout << " ";
		cout << arr2[i];
	}
	cout << endl;
}

void arrange_enum(int i,  int n)//�˵ݹ麯�����������������ܳ���n,��С������n
{
	if (i == n) {
		print_o_result(n);
		return;
	}
	for (int x = 1; x <= n; x++) {
		if (vis[x])continue;
		arr2[i] = x;
		vis[x] = 1;
		arrange_enum(i + 1,n);
		vis[x] = 0;
	}
}
//


int main() {
	int n;
	cin >> n;
	//exponential_enum(0,1,n);
	int  m;
	//cin >> n >> m;
	//combinatorial_enum(0, 1, n, m);

	arrange_enum(0,  n);
	return 0;
}