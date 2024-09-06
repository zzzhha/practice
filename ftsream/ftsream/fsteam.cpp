#include<fstream>
#include<iostream>
#include<string>//getline 需要包含此头文件
using namespace std;





//写入文本文件 和 读取文本文件
int main() {
	//文件名一般荣全路径，书写的方法如下(文本文件)
	//string filename = "text.txt";
	//char filename[]="text.txt";
	//	"/data/txt/text.txt"  //Linux系统采取的方法
	// string filename = R"(D:\please look svcr\xiangmu\c & c++\ftsream\ftsream\text.txt)";//原始自变量，C++11标准
	
	//文件名一般荣全路径，书写的方法如下(二进制文件)
	//string filename = "text.dat";
	//char filename[]="text.dat";
	//	"/data/txt/text.dat"  //Linux系统采取的方法
	string filename = R"(D:\please look svcr\xiangmu\c & c++\ftsream\ftsream\text.dat)";

	//如果已存在，则截断其内容(相当于c的"w"->这是缺省值)
	//ios::out     缺省值：会截断文件内容。相当于C的"w"
	//ios::trunc   截断文件内容
	//ios::app	   不截断文件内容，只在文件末尾追加文件，相当于C的"wa"(append)
	//ios::binary  以二进制方式打开文件
	//ofstream fout(filename, ios::out);
	/*ofstream fout(filename, ios::trunc);
	ofstream fout(filename, ios::app);*/	

	// ofstream fout;
	//fout.open("text.txt");//打开文件，如果文件不存在则创建文件，
	// fout.open(filename, ios::app | ios::binary);//以二进制的方式打开文件，并将后续内容追加当文件末尾
	//如果用open打开文件和上方的构造函数一样，

	//创建文件输入流对象，打开文件，如果文件不存在，则打开文件失败
	//ios::in	缺省值
	//ios::binary 以二进制的方式打开文件
	//ifstream fin(filename);
	//ifstream(filename,ios::in);
	
	ifstream fin;
	fin.open(filename, ios::in|ios::binary);

	if (fin.is_open() == false) {
		cout << "打开文件" << filename << "失败" << endl;
	}

	//判断打开文件是否成功
	//失败的原因主要有：1）目录不存在;2）磁盘空间已满;3）没有权限
	/*if (fout.is_open() == false) {
		cout << "打开文件" << filename << "失败" << endl;
	}*/

	//向文件中写入数据
	
	//文本文档
	/*fout << "nihao wsgjj\n";
	fout << "zhe si wo de ceshi qwewendang\n";
	fout << "xi wang ni kan dong \n";*/

	//二进制
	struct A{
		char name[31];  //名
		int no;	//编号
		char meno[301];//备注
		double weight;//重量
	}a;
	//a = { "nihao",3,"wcesinidema",5.5 };
	//fout.write((const char*)& a, sizeof(A));
	//string buffer;//用于存放从文件中读取道德内容
	//a = { "wbuhao",4,"ruikewudai",6.66 };
	//fout.write((const char*)&a, sizeof(A));//以二进制模式写文件（存疑）
	
	
	
	//读取文件内容的代码
	//二进制
	while(fin.read((char*)&a, sizeof(A)))
	{
		cout << "name=" << a.name << ",no=" << a.no << ",memo=" << a.meno << ",weight=" << a.weight << endl;
	}
	
	//文本文件一般以行的方式组织文件数据
	//getline读取一行文字，第一个参数是输入流，第二个参数是string字符串，返回值是输入流
	//getline(fin, buffer);//从fin中读取一行数据，存放到buffer中
	//如果要读取所有文件则需要用下方的方式写
	//while (getline(fin, buffer))//getline读取完毕后会返回空
	//{
	//	cout << buffer << endl;
	//}

	//或者把string 改成char buffer[]如下
	//char buffer[101];
	////如果采用此方法，一定要保证缓冲区足够大
	//while (fin.getline(buffer, 100))//getline读取完毕后会返回空
	//{
	//	cout << buffer << endl;
	//}
	// 

	//或者如此做
	//while (fin >> buffer) //此处buffer为string
	//{
	//	cout << buffer << endl;
	//}
	//fout.close();
	fin.close();
	return 0;
}


//操作文本文件和二进制文件的一些细节：
//1）在windows平台下，文本文件的换行标志是"\r\n"。
//2）在linux平台下，文本文件的换行标志是"\n"。
//3）在windows平台下，如果以文本方式打开文件，写入数据的时候，系统会将"\n"转换成"\r\n"；读取数据的时候，系统会将"\r\n"转换成"\n"。 如果以二进制方式打开文件，写和读都不会进行转换。
//4）在Linux平台下，以文本或二进制方式打开文件，系统不会做任何转换。
//5）以文本方式读取文件的时候，遇到换行符停止，读入的内容中没有换行符；以二制方式读取文件的时候，遇到换行符不会停止，读入的内容中会包含换行符（换行符被视为数据）。
//6）在实际开发中，从兼容和语义考虑，一般：a）以文本模式打开文本文件，用行的方法操作它；b）以二进制模式打开二进制文件，用数据块的方法操作它；c）以二进制模式打开文本文件和二进制文件，用数据块的方法操作它，这种情况表示不关心数据的内容。（例如复制文件和传输文件）d）不要以文本模式打开二进制文件，也不要用行的方法操作二进制文件，可能会破坏二进制数据文件的格式，也没有必要。（因为二进制文件中的某字节的取值可能是换行符，但它的意义并不是换行，可能是整数n个字节中的某个字节）
//示例：
//#include <iostream>
//#include <fstream>  // ofstream类需要包含的头文件。
//using  namespace std;
//
//int main()
//{
//	// 文件名一般用全路径，书写的方法如下：
//	//  1）"D:\data\bin\test.dat"       // 错误。
//	//  2）R"(D:\data\bin\test.dat)"   // 原始字面量，C++11标准。
//	//  3）"D:\\data\\bin\\test.dat"   // 转义字符。
//	//  4）"D:/tata/bin/test.dat"        // 把斜线反着写。
//	//  5）"/data/bin/test.dat"          //  Linux系统采用的方法。
//	string filename = R"(D:\data\bin\test.dat)";
//	//char    filename[] = R"(D:\data\bin\test.dat)";
//
//	// 创建文件输出流对象，打开文件，如果文件不存在，则创建它。
//	// ios::out     		缺省值：会截断文件内容。
//	// ios::trunc  		截断文件内容。（truncate）
//	// ios::app   			不截断文件内容，只在文件未尾追加文件。（append）
//	// ios::binary   		以二进制方式打开文件。
//	//ofstream fout(filename, ios::binary);
//	//ofstream fout(filename, ios::out | ios::binary);
//	//ofstream fout(filename, ios::trunc | ios::binary);
//	//ofstream fout(filename, ios::app | ios::binary);
//
//	ofstream fout;
//	fout.open(filename, ios::app | ios::binary);
//
//	// 判断打开文件是否成功。
//	// 失败的原因主要有：1）目录不存在；2）磁盘空间已满；3）没有权限，Linux平台下很常见。
//	if (fout.is_open() == false)
//	{
//		cout << "打开文件" << filename << "失败。\n";  return 0;
//	}
//
//	// 向文件中写入数据。
//	struct st_girl {               // 超女结构体。
//		char name[31];         // 姓名。
//		int    no;                    // 编号。   
//		char memo[301];      // 备注。
//		double weight;         // 体重。
//	}girl;
//	girl = { "西施",3,"中国历史第一美女。" ,45.8 };
//	fout.write((const char*)&girl, sizeof(st_girl));   // 写入第一块数据。
//	girl = { "冰冰",8,"也是个大美女哦。",55.2 };
//	fout.write((const char*)&girl, sizeof(st_girl));     // 写入第二块数据。
//
//	fout.close();	   // 关闭文件，fout对象失效前会自动调用close()。
//
//	cout << "操作文件完成。\n";
//}








