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
	////string(string/char *,pos)���ָ�ֵ��ʽ
	//string s1("hello");
	//string s2(s1, 1);
	//cout << s2 << endl;
	////string s3(s1, 8);//����ᱨ��
	////cout << s3 << endl;
	//string s4(s1, 5);//pos=size��ʱ��string s4��Ϊ�� ����Ϊ->""
	//cout << s4 << endl;
	//string s5(s1, 0, 3);
	//cout << s5 << endl;
	//string s6(s1, 2, 10);//��ֵ����ԭ����ֻ�Ḵ�Ƶ�ĩβ��������Ĳ��Ჹ��
	//cout << s6 << endl;
	//string s7(s1, 5, 8);//pos=size ��s4��ͬ
	//cout << s7 << endl;
	////string s8(s1, 6, 2);//���󣬻ᱨ���׳��쳣
	////cout << s8 << endl;

	//string substr(pos,n)pos��n���ǿ�ѡ�ģ�Ĭ��Ϊpos=0��n=size����-pos��
	//n������Χ�󲻻��ٽ��и�ֵ��pos������Χ�ᱨ��

	//string earse (pos ,n)��pos��ʼɾ��n����pos������Χ����

	//string append ��ĩβ����

	//string replace (pos,n,string/char *)���±�posɾ��n���������±�pos��string/char*����
	// string replace (pos,n,string/char *��n2)���±�posɾ��n��������string/char*����n2��������
	//string replace (pos,n,string/char *��pos2��n2)���±�posɾ��n��������string/char*�±�pos2����n2��������
	//string replace (pos,n,n2��char )���±�posɾ��n���������±�pos��n2�� char����
	
	//��ϰispunct
	string s1;
	getline(cin, s1);
	for (auto i = s1.begin(); i < s1.end(); i++)
	{
		if (!ispunct(*i))
			cout << *i;
	}
	return 0;
}