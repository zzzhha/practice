//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int arr[105];
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> arr[i];
//	sort(arr + 1, arr + n + 1);
//	int count = 0;
//	for (int i = 1; i < n; i++) {
//		if (arr[i] == arr[i + 1]) {
//			memcpy(arr + i, arr + i + 1, sizeof(int) * (n - i));
//			n--;
//			i--;
//		}
//	}
//	cout << n  << endl;
//	for (int i = 1; i <= n ; i++) cout << arr[i]<<" ";
//	return 0;
//}