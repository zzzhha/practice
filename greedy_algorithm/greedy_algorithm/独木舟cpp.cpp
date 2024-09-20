#include<iostream>
#include<algorithm>
using namespace std;

int people[30005];
//int main() {
//	int w;
//	int n;
//	cin >> w;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> people[i];
//	}
//	sort(people, people + n);
//	int ans = 0;
//	int i = n - 1, j = 0;
//	for (; i > j; i--) {
//		if (people[i] + people[j] <= w) {
//			j++;
//		}
//		ans++;
//	}
//	if(i==j)
//		ans++;
//	cout << ans;
//	return 0;
//}