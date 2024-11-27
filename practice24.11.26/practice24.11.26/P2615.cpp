//#include<iostream>
//
//using namespace std;
//
//int arr[45][45];
//int main() {
//	int n;
//	cin >> n;
//	arr[1][(n+1) / 2] = 1;
//	int x = 1, y = (n+1) / 2;
//	for (int k = 2; k <= n * n; k++) {
//		if (x == 1 && y != n) {
//			arr[n][y + 1] = k;
//			x = n, y = y + 1;
//		}
//		else if (y == n && x != 1) {
//			arr[x-1][1] = k;
//			x = x-1 , y = 1;
//		}
//		else if (x == 1 && y == n) {
//			arr[x + 1][y ] = k;
//			x = x + 1, y = y;
//		}
//		else if (x != 1 && y != n) {
//			if (arr[x - 1][y + 1] == 0) {
//				arr[x - 1][y + 1] = k;
//				x = x - 1, y = y + 1;
//			}
//			else {
//				arr[x + 1][y ] = k;
//				x = x + 1, y = y ;
//			}
//		}
//
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << arr[i][j]<<" ";
//		}
//		cout << endl;
//	}
//	return 0;
//}