#include<iostream>

using namespace std;

class student {
public:
	string name;
	student():name("guo")
	{
		cout << "student():" << endl;
	}
	student(string name) 
	{
		this->name = name;
		cout << "student():" << endl;
	}
	student(const student& s) 
	{
		cout << "ʹ��Ĭ�Ͽ������캯��"<<endl;
	}
	/*student( string name="zsy")
	{
		cout << "student():" << endl;
		cout << "���֣�" << name << endl;
	}*/
	void show()const
	{
		cout << "���֣�" << name << endl;
	}
};
class rectangle {
public:
	int m_length;
	int m_width;
	rectangle()
	{
		m_length = 10;
		m_width = 50;
	}
	bool isSquare()const
	{
		if (m_length == m_width)
		{
			return true;
		}
		return false;
	}
	int area()const
	{
		return m_length * m_width;
	}
	void setlength(int a)
	{
		m_length = a;
	}
};
int main()
{
	rectangle rect1;
	rect1.setlength(20);
	if (rect1.isSquare())
		cout << "��������" << endl;
	else
		cout << "����������" << endl;
	cout<<rect1.area()<<endl;
	return 0;
}