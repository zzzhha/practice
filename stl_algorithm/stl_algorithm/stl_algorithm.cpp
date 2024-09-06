#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;


template <typename T>
class punf {
public:
	T m_no;
	punf(const T& no) :m_no(no) {}
	/*void operator()(T& no) {
		cout << "Dear: " << no << " I'm a shazi" << endl;
	}*/
	bool operator()(const T& no) {
		if (no != m_no)return false;
		cout << "Dear: " << no << " I'm a shazi" << endl;
		return true;
	}
	/*void operator()(string& a) {
		cout << "Dear: " << a << " I'm a shazi" << endl;
	}*/
};


template <typename T>
bool pfun_if(T& no) {
	if (no != 3)return false;
	cout << "Dear: " << no << " I'm a shazi" << endl;
	return true;
}


template <typename T>
void pfun(T& no) {
	cout << "Dear: " << no << " I'm a shazi" << endl;
}

//void pfun(string& a) {
//	cout << "Dear: " << a<< " I'm a shazi" << endl;
//}


template <typename T1,typename T2>
void foreach(T1 first, T1 last, T2 pfun)
{
	for (auto it = first; it != last; it++) {
		//cout << "Dear: " << *it << " I'm a shazi" << endl;
		pfun(*it);
	}
}

//template <typename T>
//void foreach(T first, T last,void (*pfun)( string&)) 
//{
//	for (auto it = first; it != last; it++) {
//		//cout << "Dear: " << *it << " I'm a shazi" << endl;
//		pfun(*it);
//	}
//}
//template <typename T>
//void foreach(T first, T last, punf pfun)
//{
//	for (auto it = first; it != last; it++) {
//		//cout << "Dear: " << *it << " I'm a shazi" << endl;
//		pfun(*it);
//	}
//}
template <typename T1, typename T2>
T1 findif(T1 first, T1 last, T2 pfun)
{
	for (auto it = first; it != last; it++) {
		if (pfun(*it) == true) return it;	
	}
	return last;
}

int main() {
	//list<int>bh = { 5,3,4,8,7,1,6,9,2 };
	vector<int>bh = { 5,3,4,8,7,1,6,9,2 };
	//vector<string>bh = { "5","3","4","8","7","1","6","9","2" };
	/*punf zs;
	foreach(bh.begin(), bh.end(),zs);*/
	/*foreach(bh.begin(), bh.end(), punf<int>());
	foreach(bh.begin(), bh.end(), pfun<int>);*/
	auto it1=findif(bh.begin(), bh.end(), punf<int>(8));//仿函数
	if (it1 == bh.end())
		cout << "查找失败" <<   endl;
	else
		cout << "查找成功" << *it1 << endl;
	auto it2=findif(bh.begin(), bh.end(), pfun_if<int>);//函数
	if (it2 == bh.end())
		cout << "查找失败"  << endl;
	else
		cout << "查找成功" << *it1 << endl;

}