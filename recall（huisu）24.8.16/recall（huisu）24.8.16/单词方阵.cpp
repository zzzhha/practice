#include<iostream>
#include<string>
using namespace std;
//P1101

char s[105][105];
int vv[105][105];
int anns[105][105];//anns保存的数为1代表此位置的s数组我们需要保留其值，0则表示我们需要改为*
string word = "yizhong";

int n_s;
int dir_word[8][2]{
	{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}
};

void get_ans(int x, int y) {//向8个方向扫描，扫到y我们就往8个方向找
	for (int k = 0; k < 8; k++) {
		int flag = 1;
		for (int i = 0; word[i]; i++) {
			int dx = x + i * dir_word[k][0];
			int dy = y + i * dir_word[k][1];
			if (word[i] == s[dx][dy])continue;
			flag = 0;
			break;
		}
		if (flag == 1)//如果匹配上了word，那么就把anns对应位置的值改为1
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
	vv[i][j] = 1;//表示ij走过了
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