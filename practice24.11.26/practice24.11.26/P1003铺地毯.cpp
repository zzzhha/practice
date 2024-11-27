//#include<iostream>
//using namespace std;
//
//int xzhou[10005];
//int yzhou[10005];
//int length[10005];
//int width[10005];
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		int x, y, a, b;
//		cin >> x >> y >> a >> b;
//		xzhou[i] = x;
//		yzhou[i] = y;
//		length[i] = a;
//		width[i] = b;
//	}
//	int q, e;
//	cin >> q >> e;
//	int bh = -1;
//	for (int i = 1; i <= n; i++) {
//		if ((xzhou[i]<=q &&xzhou[i] + length[i] >= q )&& (yzhou[i]<=e && yzhou[i] + width[i] >= e)) bh = i;
//	}
//	cout << bh;
//	return 0;
//}