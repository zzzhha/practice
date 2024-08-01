#include<iostream>
#include<string>

using namespace std;
int main()
{
	/*string s1;
	cout << s1 << endl;
	string s2(s1);
	cout << s2 << endl;
	string s3 = s1;
	cout << s3 << endl;
	string s4("hello");
	cout << s4 << endl;
	string s5 = "hello";
	cout << s5 << endl;
	string s6(3, 'a');
	cout << s6 << endl;
	string s7 = string("hello");
	cout << s7 << endl;
	string s8(string("hello"));
	cout << s8 << endl;
	string s9, s10, s11;
	cin >> s9;
	cin >> s10;
	cout << s9 << "   " << s10 << endl;
	getline(cin, s11);
	cout << s11;*/
	/*string s1 = "abc";
	string s2 = "axc";*/
	/*if (s1 > s2)
		cout << 1;
	else
		cout << 2;
	cout << s1 + s2;*/
	/*string s3 = "asvzliuenfDNF";
	for (auto c : s3)
		cout << c << " " ;
	cout << endl << s1[0] << endl;
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}*/
	/*for (auto i = s1.begin(); i != s1.end(); i++)
	{
		cout << *i << ' ';
	}*/
	////string(string/char *,pos,n)
	////string(string/char *,pos)两种赋值方式
	//string s1("hello");
	//string s2(s1, 1);
	//cout << s2 << endl;
	////string s3(s1, 8);//错误会报错
	////cout << s3 << endl;
	//string s4(s1, 5);//pos=size的时候，string s4会为空 内容为->""
	//cout << s4 << endl;
	//string s5(s1, 0, 3);
	//cout << s5 << endl;
	//string s6(s1, 2, 10);//赋值超出原长度只会复制到末尾，多出来的不会补齐
	//cout << s6 << endl;
	//string s7(s1, 5, 8);//pos=size 跟s4相同
	//cout << s7 << endl;
	////string s8(s1, 6, 2);//错误，会报错，抛出异常
	////cout << s8 << endl;

	//string substr(pos,n)pos和n都是可选的，默认为pos=0，n=size（）-pos；
	//n超出范围后不会再进行赋值，pos超出范围会报错

	//string earse (pos ,n)从pos开始删除n个，pos超出范围报错

	//string append 从末尾插入

	//string replace (pos,n,string/char *)在下标pos删除n个，并在下标pos用string/char*代替
	// string replace (pos,n,string/char *，n2)在下标pos删除n个，并在string/char*插入n2个来代替
	//string replace (pos,n,string/char *，pos2，n2)在下标pos删除n个，并在string/char*下标pos2插入n2个来代替
	//string replace (pos,n,n2，char )在下标pos删除n个，并在下标pos用n2个 char代替
	
	//练习ispunct
	string s1;
	getline(cin, s1);
	for (auto i = s1.begin(); i < s1.end(); i++)
	{
		if (!ispunct(*i))
			cout << *i;
	}
	return 0;
}