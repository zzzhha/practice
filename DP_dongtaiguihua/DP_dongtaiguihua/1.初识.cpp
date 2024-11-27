#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//海贼OJ 38
long long rabbit1[105];

class Bigint:public vector<int> {
public:
	Bigint() {
		push_back(0);
	}
	Bigint(int x) {
		this->push_back(x);
		proccess_digit();//进位转化
	}

	Bigint operator+=(const Bigint &a) {
		for (int i = 0; i < a.size(); i++) {
			if (i > size())push_back(a[i]);
			else at(i) += a[i];
		}
		proccess_digit();
		return *this;
	}

	Bigint operator+(const Bigint& a) {
		Bigint ret(*this);
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
Bigint rabbit2[105];
long long f(int n) {

	if (n <= 2)
		return n;
	if (rabbit1[n])
		return rabbit1[n];
	rabbit1[n] = f(n - 1) + f(n - 2);
	return rabbit1[n];
}

ostream& operator<<(ostream& out, const Bigint& a) {
	for (int i = a.size() - 1; i >= 0; i--) {
		out << a[i];
	}
	return out;
}

//正向递推求解（从n求解到1）---->递归求解
//逆向递推求解（从1求解到n）---->循环求解

int main() {
	//1 2 3 5 8 13 21 33
	int n;
	cin >> n;
	rabbit2[1] = 1;
	rabbit2[2] = 2;
	for (int i = 3; i <= n; i++) {
		rabbit2[i] = rabbit2[i - 1] + rabbit2[i - 2];
	}
	cout << f(n) << endl;
	cout << rabbit2[n] << endl;
	return 0;
}