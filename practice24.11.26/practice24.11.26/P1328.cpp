#include<iostream>
#include<string>
using namespace std;

//int win[5][5] = {
//	{0,-1,1,1,-1},//剪刀
//	{1,0,-1,1,-1},//石头
//	{-1,1,0,-1,1},//布
//	{-1,-1,1,0,1},//蜥蜴人
//	{1,1,-1,-1,0},//斯波克
//};
//int is_win(int a,int b) {
//	if (win[a][b] == 1) return 1;
//	else if (win[a][b] == 0)return 0;
//	else return -1;
//}
//
//int main() {
//	int a, b, n;
//	cin >> n >> a >> b;
//	int arra[205];
//	int arrb[205];
//	int counta = 0;
//	int countb = 0;
//	for (int i = 0; i < a; i++) cin >> arra[i];
//	for (int i = 0; i < b; i++) cin >> arrb[i];
//	for (int i = 0,j=0,k=0; i < n; i++,j=++j%a,k=++k%b) {
//		int z = is_win(arra[j], arrb[k]);
//		if (z == 1) counta++;
//		else if (z == -1)countb++;
//		else{}
//	}
//	cout << counta << " " << countb;
//	return 0;
//}