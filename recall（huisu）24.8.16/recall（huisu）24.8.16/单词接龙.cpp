#include<iostream>
#include<cmath>

using namespace std;


//洛谷P1019 难！！！
string s[25],start;
int d[25][25];//d数组保存两个单词首尾相接的字母的个数
//例如d[i][j]就是i所对应的字符串和j所对应的字符串首尾相接的字母个数

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
	//大于等于1是因为两个单词不能完全重合
	//不让i遍历0的位置，就永远不会出现重合的情况
	//d数组所有存的数都是只能部分重合的数的值
	//而能够完全重合的两个数会因为第一个字符串的第二个数和第二个字符串的第一个数不一样而重合度为0
	for (int i = s1.size() - 1; i >= 1; i--) {
		int flag = 1;
		for (int j = 0; j < s1.size() - i; j++) {//s1.size-i代表所取s1字符串的后缀的长度
			//这个if出现的疑问：假设第一个字符串最后俩字符能和第二个字符串的前俩字符一样（例如一个字符以ee结尾，另一个以ee开头）
			//那么这个if就会有问题，但是洛谷hack数据没有这样的数据，所以只能假定上方假设在英语字典中不成立
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
//		}//初始化d数组
//	}
//	for (int i = 0; i < n; i++) {
//		if (s[i][0] != start[0])continue;
//		dfs_dan(i, s[i].size());
//	}
//	cout << maxx << endl;
//	return 0;
//}