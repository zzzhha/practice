#include<iostream>
#include<string>
using namespace std;
//P1101

char s[105][105];
int vv[105][105];
int anns[105][105];//anns�������Ϊ1�����λ�õ�s����������Ҫ������ֵ��0���ʾ������Ҫ��Ϊ*
string word = "yizhong";

int n_s;
int dir_word[8][2]{
	{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}
};

void get_ans(int x, int y) {//��8������ɨ�裬ɨ��y���Ǿ���8��������
	for (int k = 0; k < 8; k++) {
		int flag = 1;
		for (int i = 0; word[i]; i++) {
			int dx = x + i * dir_word[k][0];
			int dy = y + i * dir_word[k][1];
			if (word[i] == s[dx][dy])continue;
			flag = 0;
			break;
		}
		if (flag == 1)//���ƥ������word����ô�Ͱ�anns��Ӧλ�õ�ֵ��Ϊ1
		{
			for (int i = 0; word[i]; i++) {
				int dx = x + i * dir_word[k][0];
				int dy = y + i * dir_word[k][1];
				anns[dx][dy] = 1;
			}
		}
	}
}

void dfs_word(int i,int j) {
	if (s[i][j] == '\0')return;
	if (vv[i][j])return;
	if (s[i][j]=='y') {
		get_ans(i, j);
	}
	vv[i][j] = 1;//��ʾij�߹���
	dfs_word(i, j + 1);
	dfs_word(i + 1, j);
	return;
}

//int main(){
//
//	cin >> n_s;
//	for (int i = 1; i <= n_s; i++) {
//			cin >>( s[i]+1);
//		}
//	dfs_word(1,1);
//	for (int i = 1; i <= n_s; i++) {
//		for (int j = 1; j <= n_s; j++) {
//			if (anns[i][j]) cout << s[i][j];
//			else cout << "*";
//		}
//		cout << endl;
//	}
//	return 0;
//}