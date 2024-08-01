#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;


int main()
{
	bool arr[25][25] = {0};
	long long a[25][25] = { 0 };
	a[1][1] = 1;
	int x, y, n, m;
	cin >> n >> m >> x >> y;
	n++;
	m++;
	x++;
	y++;
	arr[x][y] = 1;

	return 0;
}


//int main()
//{
//	int n;
//	cin >> n;
//	srand(time(0));
//	vector<int>arr;
//	for (int i = 0; i < n; i++)
//	{
//		arr.push_back(rand() % 100);
//	}
//	int min = arr.front();
//	int max = arr[0];
//	for (auto x : arr)
//	{
//		if (min > x)
//			min = x;
//		if (max < x)
//			max = x;
//	}
//	cout << max << "  " << min;
//	return 0;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int ret = i;
//		while (ret)
//		{
//			if (ret % 10 == m) count++;
//			ret /= 10;
//		}
//	}
//	cout << count;
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	string str;
//	cin >> str;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] + n > 'z')
//		{
//			int temp = str[i] + n - 'z';
//			str[i] = 'a'-1 + temp;
//		}
//		else
//			str[i] += n;
//	}
//	cout << str;
//	return 0;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int arr1[3];
//	int arr2[3];
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> arr1[i] >> arr2[i];
//	}
//	int a[3];
//	for (int i = 0; i < 3; i++)
//	{
//		int e = n / arr1[i];
//		int f = n % arr1[i];
//		if (f != 0)
//			e++;
//		a[i] = e * arr2[i];
//	}
//	int min = a[0];
//	for (int i = 1; i < 3; i++)
//	{
//		if (min > a[i])
//			min = a[i];
//	}
//	cout << min;
//	return 0;
//}