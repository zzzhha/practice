#include<iostream>
#include<string>
using namespace std;
//struct node
//{
//	string str;
//	int arr;
//}a[100005];
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> a[i].arr >> a[i].str;//0内 1外
//	int cur = 0;
//	int x, y;
//	for (int i = 1; i <= m; i++) {
//		cin >> x >> y;//x:0左 1右
//		if (a[cur].arr == 0 && x == 0) cur = (cur + n - y) % n;//朝内左数
//		else if (a[cur].arr == 0 && x == 1) cur = (cur + y) % n;//朝内右数
//		else if (a[cur].arr == 1 && x == 0) cur = (cur + y) % n;//朝外左数
//		else if (a[cur].arr == 1 && x == 1) cur = (cur + n - y) % n;//朝外右数
//	}
//	cout << a[cur].str << endl;
//	return 0;
//}
