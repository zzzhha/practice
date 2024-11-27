#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//可优化，待优化
//优化前去4.2状态重定义

class BigINT :public vector<int> {
public:
	BigINT() {
		push_back(0);
	}
	BigINT(int x) {
		push_back(x);
		proccess_digit();//进位转化
	}

	BigINT operator+=(const BigINT& a) {
		for (int i = 0; i < a.size(); i++) {
			if (i < size())at(i) += a[i];
			else push_back(a[i]);
		}
		proccess_digit();
		return *this;
	}

	BigINT operator+(const BigINT& a) {
		BigINT ret(*this);
		ret += a;
		return ret;
	}


	void proccess_digit() {
		for (int i = 0; i < size(); i++) {
			if (at(i) < 10)continue;
			if (i == size() - 1)push_back(0);
			at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		return;
	}
};


ostream& operator<<(ostream& out, const BigINT& a) {
	for (int i = a.size() - 1; i >= 0; i--) {
		out << a[i];
	}
	return out;
}

BigINT wall[2][15][15];
//2是滚动数组
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	for (int i = 1; i <= k; i++) wall[1][i][i] = 1;
//	for (int ws = 2; ws <= n; ws++) {
//		for (int i = 1; i <= k; i++) {
//			for (int j = 1; j <= k; j++) {
//				wall[ws%2][i][j] = 0;
//				for (int l = 1; l <= k; l++) {
//					if (l == j)continue;
//					wall[ws % 2][i][j] += wall[(ws - 1)%2][i][l];
//				}
//			}
//		}
//	}
//	BigINt ans = 0;
//	for (int i = 1; i <= k; i++) {
//		for (int j = 1; j <= k; j++) {
//			if (i == j)continue;
//			ans += wall[n%2][i][j];
//		}
//	}
//	cout << ans;
//	return 0;
//}

