#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

//int light[100005];
//int main() {
//	int n, dist;
//	cin >> n >> dist;
//
//	for (int i = 1; i <= n; i++) cin >> light[i];
//	sort(light + 1, light + n + 1);
//	int ans = 0;
//	// i+1 - i-1 <=dist   -> i+1 -dist<=i -1 i-1+dist >=i+1
//	int ind = 1;
//	for (int i = 2; i <= n - 1; i++) {
//		if (light[i- 1] + dist >= light[i + 1]) 
//		{
//			light[i] = light[i - 1];
//			ans++;
//		}
//		
//	}
//	
//	cout << ans;
//	return 0;
//}