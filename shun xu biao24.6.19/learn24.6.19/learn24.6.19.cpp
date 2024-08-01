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
		cout << "使用默认拷贝构造函数"<<endl;
	}
	/*student( string name="zsy")
	{
		cout << "student():" << endl;
		cout << "名字：" << name << endl;
	}*/
	void show()const
	{
		cout << "名字：" << name << endl;
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
		cout << "是正方形" << endl;
	else
		cout << "不是正方形" << endl;
	cout<<rect1.area()<<endl;
	return 0;
}