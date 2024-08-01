#define  _CRT_SECURE_NO_WARNINGS 1
#include"TXL.h"

//设置通讯录最初只有0个元素
void InitContect(struct Addressbooks* p)
{	
	p->people = (struct Contect*)new(struct Contect[3]);
	if (p->people == nullptr)
	{
		return;
	}
	p->p_size = 0;
	p->capacity = 3;
}
void CheckCapacity(struct Addressbooks* p)
{
	if (p->p_size == p->capacity)
	{
		struct Contect* ptr=(struct Contect*)realloc(p->people, (p->capacity + 2) * sizeof(Contect));
		if (ptr != nullptr)
		{
			p->people = ptr;
			p->capacity += 2;
			cout << "增容成功" << endl;
		}
	}
}
int isExist(Addressbooks* p, char *name)
{
	for (int i = 0; i < p->p_size; i++)
	{
		if(strcmp(p->people[i].name,name)==0)
			return i;//找到返回这个人在数组中的下标
	}
	return -1;//没找到返回-1
}
void menu()
{
	cout << "********************************************" << endl;
	cout << "****1.add the new contect people  **********" << endl;
	cout << "****2.delete the contect people   **********" << endl;
	cout << "****3.search the contect people   **********" << endl;
	cout << "****4.modification contect people **********" << endl;
	cout << "****5.empty all contect people    **********" << endl;
	cout << "****6.print all contect people    **********" << endl;
	cout << "****0.exit the contect system     **********" << endl;
	cout << "********************************************" << endl;
}

void Add_new_contect(struct Addressbooks * p)
{
	//检测当前通讯录的容量
	CheckCapacity(p);
	cout << "please input the new contect people name:";
	cin >> p->people[p->p_size].name;
	cout << "please input the new contect people sex" << endl;
	cout << "1---男  ";
	cout << "2---女" << endl;
	char sex = 0;
	while (1)
	{
		cin >> sex;
		if (sex == '1' || sex == '2')
		{
			p->people[p->p_size].sex = sex;
			break;
		}
		else
		{
			cout << "error,please try again:" << endl;
		}
	}
	cout << "please input the new contect people age:";
	int age = 0;
	while (1)
	{
		cin >> age;
		if (age > 0)
		{
			p->people[p->p_size].age = age;
			break;
		}
		else
		{
			cout << "error,please try again:" << endl;
		}
	}
	cout << "please input the new contect people telephone:";
	while (1)
	{
		cin >> p->people[p->p_size].tele;
		if (strlen(p->people[p->p_size].tele) != 11)
		{
			cout << "error ,please try again" << endl;
		}
		else
			break;
	}
	cout << "please input the new contect people address:";
	cin >> p->people[p->p_size].address;
	p->p_size++;
	cout << "添加成功" << endl;
	/*if (p->p_size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else 
	{
		
	}*/
}
void Delete_Contect(Addressbooks* p)
{
	char name[NAME];
	cout << "please enter the name of the person you want to delete" << endl;
	cin >> name;
	int i = 0;
	if(p->p_size)
	{
		int flag = 1;
		int n;
		if (( n= isExist(p, name)) != -1)
		{
			for (; n < p->p_size - 1; n++)
			{
				p->people[n] = p->people[n + 1];
			}

			p->p_size--;
			cout << "已删除:" << name << endl;
		}		
		else
		{
			cout << "查无此人" << endl;
		}
	}
	else
	{
		cout << "您没有好友可以删除" << endl;
	}
}
void Search_Contect(struct Addressbooks* p)
{
	char name[20];
	cout << "please enter the name of person you want to search:";
	cin >>name;
	int i;
	if ((i = isExist(p, name))!=-1)
	{
		cout << p->people[i].name << endl;
		cout << p->people[i].sex << endl;
		cout << p->people[i].age << endl;
		cout << p->people[i].tele<< endl;
		cout << p->people[i].address<< endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
void Modification_Contect(struct Addressbooks* p)
{
	char name[20];
	cout << "please enter the name of person you want to modification:";
	cin >> name;
	int i;
	if ((i = isExist(p, name)) != -1)
	{
		cout << "please input the contect people name:";
		cin >> p->people[p->p_size].name;
		cout << "please input the contect people sex" << endl;
		cout << "1---男  ";
		cout << "2---女:" ;
		char sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == '1' || sex == '2')
			{
				p->people[p->p_size].sex = sex;
				break;
			}
			else
			{
				cout << "error,please try again:" << endl;
			}
		}
		cout << "please input the contect people age:";
		int age = 0;
		while (1)
		{
			cin >> age;
			if (age > 0)
			{
				p->people[p->p_size].age = age;
				break;
			}
			else
			{
				cout << "error,please try again:" << endl;
			}
		}
		cout << "please input the contect people telephone:";
		while (1)
		{
			cin >> p->people[p->p_size].tele;
			if (strlen(p->people[p->p_size].tele) != 11)
			{
				cout << "error ,please try again" << endl;
			}
			else
				break;
		}
		cout << "please input the contect people address:";
		cin >> p->people[p->p_size].address;
		p->p_size++;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
void Print_Contect(struct Addressbooks* p)
{
	int i = 0;
	for (; i < p->p_size; i++)
	{
		cout << "name:" << p->people[i].name << endl;
		cout << "sex:" << p->people[i].sex << endl;
		cout << "age:" << p->people[i].age << endl;
		cout << "telephone:" << p->people[i].tele << endl;
		cout << "address:" << p->people[i].address << endl;
	}
}
void Destory_Contect(struct Addressbooks* p)
{
	delete(p->people);
	p->people = NULL;
}