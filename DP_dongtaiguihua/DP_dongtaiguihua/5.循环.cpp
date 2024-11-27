#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//���P1050

class BigINt :public vector<int> {
public:
	static int MaxLen;
	BigINt() {
		push_back(0);
	}
	BigINt(int n, int v) :vector<int>(n, v) {};
	BigINt(int x) {
		this->push_back(x);
		proccess_digit();//��λת��
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


//����ʵ��
//int main() {
//	int n;
//	int k;
//	cin >>n >> k;
//	int pre_y = n, y;//pre_y������֪��ѭ���ڵĻ�����y����ÿһ��������Ҫ���ϵĻ���
//	//Ҳ����ȷ����λ��Ϊ0��ȷ��ʮλ���Ǹ�λ����ѭ���ڵ�n�η���ȷ����λ������ ����λ��ѭ����*10λѭ���ڣ��Ĵη�
//	int base = 1, x, y;//baseȡ�����kλ
//	for (int i = 0; i < k; i++, base *= 10);
//	x = n % base;//x����n�����kλ
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
//������ʵ��
//int main() {
//	string s;//��ȡ������
//	int k;//��ȡ����λ��
//	cin >> s >> k;
//	BigINt::MaxLen = k;//����������λ��
//	BigINt n(s, k);//������ת��λ��
//	BigINt pre_y = n, y;
//	vector<int>arr;
//	for (int i = 0; i < n.size(); i++) {
//		y = pre_y;
//		int cnt = 1;
//		while ((y * n).at(i) != n[i]) {
//			y = y * pre_y;
//			cnt++;
//			if (cnt == 11) break;//����11�������λ���Ѿ�ѭ����10�Σ�����������ÿ�����ֶ�ѭ����һ�飩
//			//û����ֹ����˵����λ��û���뵱ǰλ��ѭ����������
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