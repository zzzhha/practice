#define  _CRT_SECURE_NO_WARNINGS 1
#include"TXL.h"


int main()
{
	Addressbooks abs;
	InitContect(&abs);
	int n;//�Ƿ����ѭ��������
	char s=1;
	do
	{
		menu();
		cout << "please enter the serial number" << endl;
		cin >> n;
		switch(n)
		{
		case 1:
			Add_new_contect(&abs);//�����µĳ�Ա
			break;
		case 2:
			Delete_Contect(&abs);//ɾ����Ա
			break;
		case 3:
			Search_Contect(&abs);//���ҳ�Ա
			break;
		case 4:
			Modification_Contect(&abs);//�޸ĳ�Ա
			break;
		case 5:
			InitContect(&abs);//���ͨѶ¼
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