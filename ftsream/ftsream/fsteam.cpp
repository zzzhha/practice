#include<fstream>
#include<iostream>
#include<string>//getline ��Ҫ������ͷ�ļ�
using namespace std;





//д���ı��ļ� �� ��ȡ�ı��ļ�
int main() {
	//�ļ���һ����ȫ·������д�ķ�������(�ı��ļ�)
	//string filename = "text.txt";
	//char filename[]="text.txt";
	//	"/data/txt/text.txt"  //Linuxϵͳ��ȡ�ķ���
	// string filename = R"(D:\please look svcr\xiangmu\c & c++\ftsream\ftsream\text.txt)";//ԭʼ�Ա�����C++11��׼
	
	//�ļ���һ����ȫ·������д�ķ�������(�������ļ�)
	//string filename = "text.dat";
	//char filename[]="text.dat";
	//	"/data/txt/text.dat"  //Linuxϵͳ��ȡ�ķ���
	string filename = R"(D:\please look svcr\xiangmu\c & c++\ftsream\ftsream\text.dat)";

	//����Ѵ��ڣ���ض�������(�൱��c��"w"->����ȱʡֵ)
	//ios::out     ȱʡֵ����ض��ļ����ݡ��൱��C��"w"
	//ios::trunc   �ض��ļ�����
	//ios::app	   ���ض��ļ����ݣ�ֻ���ļ�ĩβ׷���ļ����൱��C��"wa"(append)
	//ios::binary  �Զ����Ʒ�ʽ���ļ�
	//ofstream fout(filename, ios::out);
	/*ofstream fout(filename, ios::trunc);
	ofstream fout(filename, ios::app);*/	

	// ofstream fout;
	//fout.open("text.txt");//���ļ�������ļ��������򴴽��ļ���
	// fout.open(filename, ios::app | ios::binary);//�Զ����Ƶķ�ʽ���ļ���������������׷�ӵ��ļ�ĩβ
	//�����open���ļ����Ϸ��Ĺ��캯��һ����

	//�����ļ����������󣬴��ļ�������ļ������ڣ�����ļ�ʧ��
	//ios::in	ȱʡֵ
	//ios::binary �Զ����Ƶķ�ʽ���ļ�
	//ifstream fin(filename);
	//ifstream(filename,ios::in);
	
	ifstream fin;
	fin.open(filename, ios::in|ios::binary);

	if (fin.is_open() == false) {
		cout << "���ļ�" << filename << "ʧ��" << endl;
	}

	//�жϴ��ļ��Ƿ�ɹ�
	//ʧ�ܵ�ԭ����Ҫ�У�1��Ŀ¼������;2�����̿ռ�����;3��û��Ȩ��
	/*if (fout.is_open() == false) {
		cout << "���ļ�" << filename << "ʧ��" << endl;
	}*/

	//���ļ���д������
	
	//�ı��ĵ�
	/*fout << "nihao wsgjj\n";
	fout << "zhe si wo de ceshi qwewendang\n";
	fout << "xi wang ni kan dong \n";*/

	//������
	struct A{
		char name[31];  //��
		int no;	//���
		char meno[301];//��ע
		double weight;//����
	}a;
	//a = { "nihao",3,"wcesinidema",5.5 };
	//fout.write((const char*)& a, sizeof(A));
	//string buffer;//���ڴ�Ŵ��ļ��ж�ȡ��������
	//a = { "wbuhao",4,"ruikewudai",6.66 };
	//fout.write((const char*)&a, sizeof(A));//�Զ�����ģʽд�ļ������ɣ�
	
	
	
	//��ȡ�ļ����ݵĴ���
	//������
	while(fin.read((char*)&a, sizeof(A)))
	{
		cout << "name=" << a.name << ",no=" << a.no << ",memo=" << a.meno << ",weight=" << a.weight << endl;
	}
	
	//�ı��ļ�һ�����еķ�ʽ��֯�ļ�����
	//getline��ȡһ�����֣���һ�����������������ڶ���������string�ַ���������ֵ��������
	//getline(fin, buffer);//��fin�ж�ȡһ�����ݣ���ŵ�buffer��
	//���Ҫ��ȡ�����ļ�����Ҫ���·��ķ�ʽд
	//while (getline(fin, buffer))//getline��ȡ��Ϻ�᷵�ؿ�
	//{
	//	cout << buffer << endl;
	//}

	//���߰�string �ĳ�char buffer[]����
	//char buffer[101];
	////������ô˷�����һ��Ҫ��֤�������㹻��
	//while (fin.getline(buffer, 100))//getline��ȡ��Ϻ�᷵�ؿ�
	//{
	//	cout << buffer << endl;
	//}
	// 

	//���������
	//while (fin >> buffer) //�˴�bufferΪstring
	//{
	//	cout << buffer << endl;
	//}
	//fout.close();
	fin.close();
	return 0;
}


//�����ı��ļ��Ͷ������ļ���һЩϸ�ڣ�
//1����windowsƽ̨�£��ı��ļ��Ļ��б�־��"\r\n"��
//2����linuxƽ̨�£��ı��ļ��Ļ��б�־��"\n"��
//3����windowsƽ̨�£�������ı���ʽ���ļ���д�����ݵ�ʱ��ϵͳ�Ὣ"\n"ת����"\r\n"����ȡ���ݵ�ʱ��ϵͳ�Ὣ"\r\n"ת����"\n"�� ����Զ����Ʒ�ʽ���ļ���д�Ͷ����������ת����
//4����Linuxƽ̨�£����ı�������Ʒ�ʽ���ļ���ϵͳ�������κ�ת����
//5�����ı���ʽ��ȡ�ļ���ʱ���������з�ֹͣ�������������û�л��з����Զ��Ʒ�ʽ��ȡ�ļ���ʱ���������з�����ֹͣ������������л�������з������з�����Ϊ���ݣ���
//6����ʵ�ʿ����У��Ӽ��ݺ����忼�ǣ�һ�㣺a�����ı�ģʽ���ı��ļ������еķ�����������b���Զ�����ģʽ�򿪶������ļ��������ݿ�ķ�����������c���Զ�����ģʽ���ı��ļ��Ͷ������ļ��������ݿ�ķ��������������������ʾ���������ݵ����ݡ������縴���ļ��ʹ����ļ���d����Ҫ���ı�ģʽ�򿪶������ļ���Ҳ��Ҫ���еķ��������������ļ������ܻ��ƻ������������ļ��ĸ�ʽ��Ҳû�б�Ҫ������Ϊ�������ļ��е�ĳ�ֽڵ�ȡֵ�����ǻ��з������������岢���ǻ��У�����������n���ֽ��е�ĳ���ֽڣ�
//ʾ����
//#include <iostream>
//#include <fstream>  // ofstream����Ҫ������ͷ�ļ���
//using  namespace std;
//
//int main()
//{
//	// �ļ���һ����ȫ·������д�ķ������£�
//	//  1��"D:\data\bin\test.dat"       // ����
//	//  2��R"(D:\data\bin\test.dat)"   // ԭʼ��������C++11��׼��
//	//  3��"D:\\data\\bin\\test.dat"   // ת���ַ���
//	//  4��"D:/tata/bin/test.dat"        // ��б�߷���д��
//	//  5��"/data/bin/test.dat"          //  Linuxϵͳ���õķ�����
//	string filename = R"(D:\data\bin\test.dat)";
//	//char    filename[] = R"(D:\data\bin\test.dat)";
//
//	// �����ļ���������󣬴��ļ�������ļ������ڣ��򴴽�����
//	// ios::out     		ȱʡֵ����ض��ļ����ݡ�
//	// ios::trunc  		�ض��ļ����ݡ���truncate��
//	// ios::app   			���ض��ļ����ݣ�ֻ���ļ�δβ׷���ļ�����append��
//	// ios::binary   		�Զ����Ʒ�ʽ���ļ���
//	//ofstream fout(filename, ios::binary);
//	//ofstream fout(filename, ios::out | ios::binary);
//	//ofstream fout(filename, ios::trunc | ios::binary);
//	//ofstream fout(filename, ios::app | ios::binary);
//
//	ofstream fout;
//	fout.open(filename, ios::app | ios::binary);
//
//	// �жϴ��ļ��Ƿ�ɹ���
//	// ʧ�ܵ�ԭ����Ҫ�У�1��Ŀ¼�����ڣ�2�����̿ռ�������3��û��Ȩ�ޣ�Linuxƽ̨�ºܳ�����
//	if (fout.is_open() == false)
//	{
//		cout << "���ļ�" << filename << "ʧ�ܡ�\n";  return 0;
//	}
//
//	// ���ļ���д�����ݡ�
//	struct st_girl {               // ��Ů�ṹ�塣
//		char name[31];         // ������
//		int    no;                    // ��š�   
//		char memo[301];      // ��ע��
//		double weight;         // ���ء�
//	}girl;
//	girl = { "��ʩ",3,"�й���ʷ��һ��Ů��" ,45.8 };
//	fout.write((const char*)&girl, sizeof(st_girl));   // д���һ�����ݡ�
//	girl = { "����",8,"Ҳ�Ǹ�����ŮŶ��",55.2 };
//	fout.write((const char*)&girl, sizeof(st_girl));     // д��ڶ������ݡ�
//
//	fout.close();	   // �ر��ļ���fout����ʧЧǰ���Զ�����close()��
//
//	cout << "�����ļ���ɡ�\n";
//}








