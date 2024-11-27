#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int zombie[10][2005];
int num[10];
int main() {
  int n;
  int ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
	  int a, b;
	  cin >> a >> b;
	  zombie[a][++num[a]] = b;

	}
  for (int i = 1; i <= 6; i++) {
	  sort(zombie[i] + 1, zombie[i] + 1 + num[i]);
  }
	for (int i = 1; i <= 6; i++) //对每一行分别处理
	{
	  for(int x=1,x1=x;x<=num[i];x=x1)
	  {
		ans++;
		while (zombie[i][x1] < zombie[i][x] + 60 && zombie[i][x1]!=0) x1++;
	  }
	}
  cout << ans;
  return 0;
}