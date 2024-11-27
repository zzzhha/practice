#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//洛谷P1096

//本递推：f（n）2n个盘 从A柱移到C柱的最小步数 

//f(n)=2f(n-1)+2;
class bigint :public vector<int> {
public:
	bigint() {
		push_back(0);
	}
	bigint(int x) {
		push_back(x);
		process_digit();
	}

	bigint operator*=(int x) {
		for (int i = 0; i < size(); i++) {
			at(i) *= x;
		}
		process_digit();
		return *this;
	}

	bigint operator*(int x) {
		bigint ret(*this);
		ret *= x;
		return ret;
	}
	bigint operator+=(int x) {
		at(0) += x;
		process_digit();
		return*this;
	}
	bigint operator+(int x) {
		bigint ret(*this);
		ret += x;
		return ret;
	}
private:
	void process_digit()
	{
		for (int i = 0; i < size(); i++) {
			if (at(i) < 10)continue;
			if (i + 1 == size())push_back(0);
			at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		return;
	}
};

ostream& operator<<(ostream& out, const bigint& a) {
	for (int i = a.size() - 1; i >= 0; i--) out << a[i];
	return out;
}

bigint hanoi[205];

//int main() {
//	int n;
//	cin >> n;
//	hanoi[1] = 2;
//	for (int i = 2; i <= n; i++){
//		hanoi[i]=hanoi[i-1]*2 +2;
//	}
//	cout << hanoi[n] << endl;
//	return 0;
//}