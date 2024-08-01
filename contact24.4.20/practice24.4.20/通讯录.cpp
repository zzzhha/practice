#define  _CRT_SECURE_NO_WARNINGS 1
#include"TXL.h"


int main()
{
	Addressbooks abs;
	InitContect(&abs);
	int n;//是否进行循环的条件
	char s=1;
	do
	{
		menu();
		cout << "please enter the serial number" << endl;
		cin >> n;
		switch(n)
		{
		case 1:
			Add_new_contect(&abs);//增加新的成员
			break;
		case 2:
			Delete_Contect(&abs);//删除成员
			break;
		case 3:
			Search_Contect(&abs);//查找成员
			break;
		case 4:
			Modification_Contect(&abs);//修改成员
			break;
		case 5:
			InitContect(&abs);//清空通讯录
			break;
		case 6:
			Print_Contect(&abs);
			break;
		case 0:
			Destory_Contect(&abs);
			break;
		default:
			cout << "error please try again" << endl;
		}
	} while (n);
}