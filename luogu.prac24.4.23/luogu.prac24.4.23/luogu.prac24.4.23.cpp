#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
using namespace std;

string c="0123456798ABCDEF";
void f(long long x,long long m)
{
	if(x/m) 
	{
	    f(x/m,m);
	}
	cout<<c[x%m];
}
int main()
{
	long long x,m;
	cin>>x>>m;
	f(x,m);
	return 0;
}
//int main()
//{
//	int n;
//	int sum = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += i;
//	}
//	cout << sum;
//	return 0;
//}
//long long shi(int n,int b)
//{
//	int sum = 0;
//	int m = 0;
//	while (n)
//	{
//		sum += pow(b, m) * (n % 10);
//		m++;
//		n /= 10;
//	}
//	return sum;
//}
//int pos(int a) 
//{
//	int res = 0;
//	while (a) {
//		res = max(res, a % 10);
//		a /= 10;
//		if (res == 9) break;
//	}
//	return res;
//}
//int main()
//{
//	int p, q, r;
//	int B=2;
//	cin >> p >> q >> r;
//	int t = max({ pos(p),pos(q),pos(r) });
//	for(B=t+1;B<=16;B++)
//	{
//		if (shi(r, B) * shi(q, B) == shi(p, B))
//		{
//			cout << B;
//			return 0;
//		}
//	}
//	cout << 0;
//	return 0;
//}
//int pos(int a)
//{
//	int res = 0;
//	while (a) {
//		res = max(res, a % 10);
//		a /= 10;
//		if (res == 9) break;
//	}
//	return res;
//}
//int main()
//{
//	int A = 0;
//	int B = 0;
//	int n;
//	
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		int j = 31;
//		int ling = 0;
//		int yi = 0;
//		int ret = i;
//		while (ret)
//		{
//			if (ret % 2 == 1)
//				yi++;
//			else
//				ling++;
//			ret /= 2;
//		}
//		if (yi > ling)
//		{
//			A++;
//		}
//		else
//			B++;
//	}
//	cout << A << " " << B;
//	return 0;
//}
//int huiwen(int n)
//{
//	int sum = 0;
//	while (n)
//	{
//		sum = 10 * sum + n % 10;
//		n /= 10;
//	}
//	return sum;
//}
//
//int prime(int i)
//{
//	if (i == 2) {
//		return 1;
//	}
//	for (int j = 2; j <= sqrt(i); j++) {
//		if (i % j == 0) {
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int x, y;
//	bool f=0, b = 0;
//	cin >> x >> y;
//	while(x<=y)
//	{
//		int ret = huiwen(x);
//		if (prime(x) && prime(ret))
//		{
//			if (f)
//				cout << ",";
//			cout << x;
//			b = 1;
//			f = 1;
//		}
//		x++;
//	}
//	if (!b)
//	{
//		cout << "No";
//	}
//	return 0;
//}
//int prime_max(int n)
//{
//	int max = 1;
//	if (n < 2)
//	{
//		return 0;
//	}
//	else
//	{
//		for (int i = 2; i <n; i++)
//		{
//			if (n % i == 0)
//			{
//				max = i;
//				max = prime_max(max);
//			}
//		}
//	}
//	if (max == 1)
//	{
//		max = n;
//	}
//	return max;
//}

//void zhi(int i) {
//	for (int j = i; j >= 2; j--) {
//		if (i % j == 0 && prime(j) == 1) {
//			cout << j;
//			break;
//		}
//	}
//}
//int main() {
//	int n, m;
//	cin >> n >> m;//n,m∫¨“Âø¥Ã‚ 
//	for (int i = n; i <= m; i++) 
//	{
//		zhi(i);
//		if (i != m) 
//		{  
//			cout << ",";
//		}
//	}
//}
//int main()
//{
//	int x, y;
//	int count = 0;
//	cin >>x >> y;
//	if(x<y)
//	{
//
//		while (x <= y)
//		{
//			if (sushu(x))
//			{
//				count++;
//			}
//			x++;
//		}
//	}
//	else
//	{
//		while (y <= x)
//		{
//			if (sushu(x))
//			{
//				count++;
//			}
//			y++;
//		}
//	}
//	cout << count;
//	return 0;
//}


//int main()
//{
//	int n;
//	cin >> n;
//	int i = 11;
//	int count = 0;
//	for (; i <= n; i++)
//	{
//		int x = huiwen(i);
//		if (i== x&&sushu(i))
//		{
//			count++;
//		}
//	}
//	cout << count;
//
//	return 0;
//}
//int main()
//{
//	string str[105];
//	int i = 0;
//	string gai;
//	while (cin >> gai)
//	{
//		str[++i] = gai;
//	}
//	
//	
//	for (int n = 1; n <= i-2; n++)
//	{
//		if (str[n]==str[i-1])
//		{
//			cout <<str[i] <<" ";
//		}
//		else
//		{
//			cout << str[n] << " ";
//		}
//	}
//	return 0;
//}