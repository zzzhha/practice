#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

string arr[100005];
string ans[100005];
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	string s;
//	cin >> s;
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		int flag = 0;
//		for(int j=0;j<s.length();j++)
//		{
//			if (s[j] != arr[i][j]) {
//				flag = 1;
//				break;
//			}
//		}
//		if (!flag) {
//			ans[count++] = arr[i];
//		}
//	}
//	sort(ans, ans + count);
//	for (int i = 0; i < count; i++) {
//		cout << ans[i] << endl;
//	}
//	return 0;
//}