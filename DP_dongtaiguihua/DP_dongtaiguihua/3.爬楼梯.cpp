#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class BigInt :public vector<int> {
public:
	BigInt() {
		push_back(0);
	}
	BigInt(int x) {
		this->push_back(x);
		proccess_digit();//进位转化
	}

	BigInt operator+=(const BigInt& a) {
		for (int i = 0; i < a.size(); i++) {
			if (i > size())push_back(a[i]);
			else at(i) += a[i];
		}
		proccess_digit();
		return *this;
	}

	BigInt operator+(const BigInt& a) {
		BigInt ret(*this);
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
BigInt rabbit2[105];


ostream& operator<<(ostream& out, const BigInt& a) {
	for (int i = a.size() - 1; i >= 0; i--) {
		out << a[i];
	}
	return out;
}

//海贼OJ 40
BigInt climb;
BigInt climb_f[505];

//错误，数据范围超出，需改更改数据结构（算法没错）
//long long climb_floor(int n) {
//	if (n < 2)
//		return 0;
//	if (n == 2 || n == 3)
//		return 1;
//	if (!climb_f[n])
//		climb_f[n] = climb_floor(n - 2) + climb_floor(n - 3);
//	return climb + climb_f[n];
//}

//int main() {
//	int n;
//	cin >> n;
//	climb_f[0] = 1;//为什么等于1看climb_f[3]
//	climb_f[1] = 0;
//	climb_f[2] = 1;
//	climb_f[3] = climb_f[2]+ climb_f[0];
//	for (int i = 4; i <= n;i++) {
//		climb_f[i] = climb_f[i - 2] + climb_f[i - 3];
//	}
//	cout << climb_f[n];
//	return 0;
//}