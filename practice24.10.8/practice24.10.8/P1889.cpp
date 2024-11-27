#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;


//dp(i,j)

int soilor_x[10005];
int soilor_y[10005];

//int main() {
//	int n;
//	cin >> n;
//	int retx, rety;
//	int ans=0;
//	for (int i = 1; i <= n; i++) {
//			cin >> soilor_x[i] >> soilor_y[i];
//	}
//	sort(soilor_x + 1, soilor_x + n + 1);
//	sort(soilor_y + 1, soilor_y + n + 1);
//	for (int i = 1; i <= n; i++) soilor_x[i] -= i;
//	sort(soilor_x + 1, soilor_x + n + 1);
//	if (n % 2 == 0) {
//		retx = (soilor_x[n / 2] + soilor_x[(n / 2) + 1]) / 2;
//		rety = (soilor_y[n / 2] + soilor_y[(n / 2) + 1]) / 2;
//	}
//	else {
//		retx = (soilor_x[n / 2 + 1]);
//		rety = (soilor_y[n / 2 + 1]) ;
//	}
//	for (int i = 1; i <= n; i++) {
//		ans += abs(soilor_x[i] - retx) + abs(soilor_y[i] - rety);
//	}
//	cout << ans;
//	return 0;
//}