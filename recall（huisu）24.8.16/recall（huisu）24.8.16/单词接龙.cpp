#include<iostream>
#include<cmath>

using namespace std;


//���P1019 �ѣ�����
string s[25],start;
int d[25][25];//d���鱣������������β��ӵ���ĸ�ĸ���
//����d[i][j]����i����Ӧ���ַ�����j����Ӧ���ַ�����β��ӵ���ĸ����

int n;
int maxx;
int vis_s[25] = { 0 };
void dfs_dan(int x,int L) {
	vis_s[x]++;
	if (L > maxx)maxx = L;
	for (int y = 0; y < n; y++) {
		if (d[x][y] == 0) continue;
		if (vis_s[y] == 2) continue;
		dfs_dan(y, L + s[y].size() - d[x][y]);
	}
	vis_s[x]--;
	return;
}

int f(string& s1, string& s2)
{
	//���ڵ���1����Ϊ�������ʲ�����ȫ�غ�
	//����i����0��λ�ã�����Զ��������غϵ����
	//d�������д��������ֻ�ܲ����غϵ�����ֵ
	//���ܹ���ȫ�غϵ�����������Ϊ��һ���ַ����ĵڶ������͵ڶ����ַ����ĵ�һ������һ�����غ϶�Ϊ0
	for (int i = s1.size() - 1; i >= 1; i--) {
		int flag = 1;
		for (int j = 0; j < s1.size() - i; j++) {//s1.size-i������ȡs1�ַ����ĺ�׺�ĳ���
			//���if���ֵ����ʣ������һ���ַ���������ַ��ܺ͵ڶ����ַ�����ǰ���ַ�һ��������һ���ַ���ee��β����һ����ee��ͷ��
			//��ô���if�ͻ������⣬�������hack����û�����������ݣ�����ֻ�ܼٶ��Ϸ�������Ӣ���ֵ��в�����
			if (s1[i + j] == s2[j]) continue;
			flag = 0;
			break;
		}
		if (flag == 1)return s1.size() - i;
	}
	return 0;
}

//int main() {
//	cin >> n;
//	
//	for (int i = 0; i < n; i++) {
//		cin >> s[i];
//	}
//	cin >> start;
//	for(int i=0;i<n;i++)
//	{
//		for (int j = 0; j < n; j++) {
//			d[i][j] = f(s[i], s[j]);
//		}//��ʼ��d����
//	}
//	for (int i = 0; i < n; i++) {
//		if (s[i][0] != start[0])continue;
//		dfs_dan(i, s[i].size());
//	}
//	cout << maxx << endl;
//	return 0;
//}