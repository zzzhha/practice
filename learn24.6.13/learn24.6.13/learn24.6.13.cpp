#include<iostream>
#include<cstdio>
using namespace std;


class Cboy
{
public:
	int boy_age;
	Cboy()
	{
		boy_age = 10;
		cout << "������cboy�������캯��\n";
	}
	Cboy(int a)
	{
		boy_age = a;
		cout << "������cboy��int�����캯��\n";
	}
	void setvalue(int age)
	{
		boy_age = age;
	}
	Cboy(const Cboy& g)
	{
		boy_age = g.boy_age;
		cout << "ʹ����Cboy��const Cboy& ���Ŀ������캯��" << endl;
	}
};

class Cgirl {
public:
	mutable int m_bh;
	const int m_age;
	static const int xw;
	Cboy boyfriend;
	void add();
	/*Cgirl() :m_age(1), boyfriend()
	{
		m_bh = 0; 
		boyfriend.boy_age = 1;
		cout << "������Cgirl�������캯��" << endl;
		show();
	}*/
	/*Cgirl(int bh, int age, Cboy &boy):
	{ 
		m_bh=bh;
		m_age=age;
		boyfriend.boy_age = boy.boy_age;
		cout << "������Cgirl��int��int,Cboy)���͵Ĺ��캯��" << endl; 
		show();
	}*/
	
	Cgirl(int bh, int age, Cboy& boy) :m_bh(bh), m_age(age),boyfriend(boy)
	{
		boyfriend.boy_age = boy.boy_age;
		cout << "������Cgirl��int��int,Cboy)���͵Ĺ��캯��" << endl;
		show();
	}
	/*~Cgirl() 
	{
		cout << "������~Cgirl������������" << endl;
		
	}*/

	const Cgirl& pk (const Cgirl &other) const
	{
		if (this->m_age <= other.m_age)
			return *this;
		else 
			return other;
	}
	operator int() {
		return m_age;
	}
	void show() const { m_bh = 5; cout << "���" << m_bh << "����" << m_age << "����" << boyfriend.boy_age << "xw" <<xw<< endl; }
	static void showxw() { cout << "xw" << xw << endl; }
};

void Cgirl::add()
{
	cout << m_bh + m_age << endl;
}

 int const Cgirl::xw = 52;
 
int main()
{
	cout << " Cgirl::xw" << Cgirl::xw<<endl;
	Cgirl::showxw();
	Cboy boy;
	boy.setvalue(10);
	Cgirl girl(1,15,boy);
	const Cgirl girl_2(5, 20, boy);
	return 0;
}

