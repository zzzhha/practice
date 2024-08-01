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
		cout << "调用了cboy（）构造函数\n";
	}
	Cboy(int a)
	{
		boy_age = a;
		cout << "调用了cboy（int）构造函数\n";
	}
	void setvalue(int age)
	{
		boy_age = age;
	}
	Cboy(const Cboy& g)
	{
		boy_age = g.boy_age;
		cout << "使用了Cboy（const Cboy& ）的拷贝构造函数" << endl;
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
		cout << "调用了Cgirl（）构造函数" << endl;
		show();
	}*/
	/*Cgirl(int bh, int age, Cboy &boy):
	{ 
		m_bh=bh;
		m_age=age;
		boyfriend.boy_age = boy.boy_age;
		cout << "调用了Cgirl（int，int,Cboy)类型的构造函数" << endl; 
		show();
	}*/
	
	Cgirl(int bh, int age, Cboy& boy) :m_bh(bh), m_age(age),boyfriend(boy)
	{
		boyfriend.boy_age = boy.boy_age;
		cout << "调用了Cgirl（int，int,Cboy)类型的构造函数" << endl;
		show();
	}
	/*~Cgirl() 
	{
		cout << "调用了~Cgirl（）析构函数" << endl;
		
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
	void show() const { m_bh = 5; cout << "编号" << m_bh << "年龄" << m_age << "男友" << boyfriend.boy_age << "xw" <<xw<< endl; }
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

