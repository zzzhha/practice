#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//洛谷P1050

class BigINt :public vector<int> {
public:
	static int MaxLen;
	BigINt() {
		push_back(0);
	}
	BigINt(int n, int v) :vector<int>(n, v) {};
	BigINt(int x) {
		this->push_back(x);
		proccess_digit();//进位转化
	}
	BigINt(string& s, int k) {
		for (int i = 0,j=s.size() - 1; i < k; i++, j--) {
			push_back(s[j] - '0');
		}
		return;
	}

	BigINt operator*(const BigINt& a) {
		BigINt ret(min(MaxLen, int(size() + a.size() - 1)), 0);
		for (int i = 0; i < size(); i++) {
			for (int j = 0; j < a.size(); j++) {
				if (i + j >= MaxLen)continue;
				ret[i + j] += at(i) * a[j];
			}
		}
		ret.proccess_digit();
		return ret;
	}

	BigINt operator*=(int x) {
		for (int i = 0; i <= size(); i++) {
			at(i) *= x;
		}
		proccess_digit();
		return *this;
		
	}

	BigINt operator+=(const BigINt& a) {
		for (int i = 0; i < a.size(); i++) {
			if (i > size())push_back(a[i]);
			else at(i) += a[i];
		}
		proccess_digit();
		return *this;
	}

	BigINt operator+(const BigINt& a) {
		BigINt ret(*this);
		ret += a;
		return ret;
	}


	void proccess_digit() {
		for (int i = 0; i < size(); i++) {
			if (at(i) < 10)continue;
			if (i + 1 < MaxLen) {
				if (i == size() - 1)push_back(0);
				at(i + 1) += at(i) / 10;
			}
			at(i) %= 10;
		}
		return;
	}
};

ostream& operator<<(ostream& out, const BigINt& a) {
	for (int i = a.size() - 1; i >= 0; i--) {
		out << a[i];
	}
	return out;
}

BigINt fw[105];


//整数实现
//int main() {
//	int n;
//	int k;
//	cin >>n >> k;
//	int pre_y = n, y;//pre_y代表已知的循环节的基数，y代表每一轮我们需要乘上的基数
//	//也就是确定个位就为0，确定十位就是个位数的循环节的n次方，确定百位数就是 （个位的循环节*10位循环节）的次方
//	int base = 1, x, y;//base取得最后k位
//	for (int i = 0; i < k; i++, base *= 10);
//	x = n % base;//x等于n的最后k位
//	y = x;
//	int cnt = 1;
//	while (x * y % base != x)
//	{
//		cout << "y==" << y << " , cnt= " << cnt;
//		y = y * x % base;
//		cnt += 1;
//	}
//	cout << cnt << endl;
//	return 0;
//}

int BigINt::MaxLen = 0;
//大整数实现
//int main() {
//	string s;//读取大数字
//	int k;//读取保留位数
//	cin >> s >> k;
//	BigINt::MaxLen = k;//大整数保留位数
//	BigINt n(s, k);//大整数转化位数
//	BigINt pre_y = n, y;
//	vector<int>arr;
//	for (int i = 0; i < n.size(); i++) {
//		y = pre_y;
//		int cnt = 1;
//		while ((y * n).at(i) != n[i]) {
//			y = y * pre_y;
//			cnt++;
//			if (cnt == 11) break;//等于11代表这个位数已经循环了10次（最差情况就是每个数字都循环了一遍）
//			//没有终止，就说明次位数没有与当前位数循环。就跳出
//		}
//		if (cnt == 11)
//		{
//			cout << "-1" << endl;
//			return 0;
//		}
//		arr.push_back(cnt);
//		pre_y = y;
//	}
//	BigINt ans = 1;
//	for (int i = 0; i < arr.size(); i++) {
//		ans*=arr[i];
//	}
//	cout<<ans<<endl;
//	return 0;
//}