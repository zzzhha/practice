#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

//struct book {
//	string bh;
//	string name;
//	double value;
//	book() { value = 0; }
//	book(string bh, string name, double value) :bh(bh), name(name), value(value) {}
//};
//
//struct Node :public book {
//	Node* next;
//	Node(string bh, string name, double value) :book(bh, name, value) {
//		next = nullptr;
//	}
//};
//
//struct Linklist {
//	int size;
//	double sum;
//	Node* rear;
//	Node* tail;
//	Linklist() {
//		size = 0;
//		sum = 0;
//		rear = nullptr;
//		tail = nullptr;
//	}
//	void tailinsert(Node* s) {
//		size++;
//		sum += s->value;
//		if (rear == nullptr) {
//			rear = s;
//			tail = s;
//			return;
//		}
//		tail->next = s;
//		tail = s;
//		return;
//	}
//	void printlist() {
//		Node* cur = rear;
//		cout << size << endl;
//		while (cur) {
//			cout << cur->bh << " " << cur->name << " ";
//			printf("%.2lf\n", cur->value);
//			cur = cur->next;
//		}
//	}
//	void changelist() {
//		Node* cur = rear;
//		double average = sum / size;
//		while (cur) {
//			if (average > cur->value) cur->value*=1.2;
//			else  cur->value *= 1.1;
//			cur = cur->next;
//		}
//		return;
//	}
//
//	int findlist(double &m) {
//		Node* cur = rear;
//		double max = cur->value;
//		int ret = 0;
//		while (cur) {
//			if (max < cur->value) max = cur->value, ret = 1 ,m=max;
//			else if (max == cur->value) ret++;
//			cur = cur->next;
//		}
//		return ret;
//	}
//	void print_findlist(double ret) {
//		Node* cur = rear;
//		cout << size << endl;
//		while (cur) {
//			if(ret==cur->value) {
//				cout << cur->bh << " " << cur->name << " ";
//				printf("%.2lf\n", cur->value);
//			}
//			cur = cur->next;
//		}
//		return;
//	}
//
//	void insert(int n, Node* s) {
//		if (n >= size) {
//			cout << "抱歉，入库位置非法!" << endl;
//			return;
//		}
//		Node* cur = rear;
//		Node* pre = cur;
//		for( ; n-1 > 0 ; n--) {
//			pre = cur; 
//			cur = cur->next;
//		}
//		size++;
//		sum += s->value;
//
//		pre->next = s;
//		s->next = cur;
//		return;
//	}
//
//	void deletelist(int n) {
//		if (n >= size) {
//			cout << "抱歉，出库位置非法!" << endl;
//		}
//		size--;
//		Node* cur = rear;
//		Node* pre = cur;
//		for (; n - 1 > 0; n--) {
//			pre = cur;
//			cur = cur->next;
//		}
//		pre->next = cur->next;
//		delete cur;
//	}
//
//	void delete_double() {
//		for (Node* i = rear; i; i = i->next) {
//			Node* pre = i;
//			for (Node* j = i; j;pre = j,j = j->next) {
//				if (i!=j && (i->bh == j->bh)) {
//					size--;
//					pre->next = j->next;
//					delete j;
//					j = pre;
//				}
//			}
//		}
//	}
//};

//int main() {
//	string bh, name;
//	Linklist l;
//	double v;
//	//1.基于顺序（链式）存储结构的图书信息表的创建和输出
//	while ((cin >> bh >> name >> v) && (bh != "0" && name != "0" && v != 0)) {
//		Node* q = new Node(bh, name, v);
//		l.tailinsert(q);
//	}
//	
//	/*l.printlist();*/
//
//	//2.基于顺序（链式）存储结构的图书信息表的修改
//	/*l.changelist();
//	cout << l.sum / l.size<<endl;
//	l.printlist();*/
//
//	//3.基于顺序（链式）存储结构的图书信息表的最贵图书的查找
//	/*double m = 0;
//	cout<<l.findlist(m)<<endl;
//	l.print_findlist(m);*/
//
//	//4.基于顺序（链式）存储结构的图书信息表的新图书的入库
//	/*int n;
//	cin >> n;
//	cin >> bh >> name >> v;
//	Node* q = new Node(bh, name, v);
//	l.insert(n, q);
//	l.printlist();*/
//
//	//5.基于顺序（链式）存储结构的图书信息表的旧图书的出库
//	/*int n;
//	cin >> n;
//	l.deletelist(n);
//	l.printlist();*/
//
//	//6.基于顺序（链式）存储结构的图书信息表的图书去重
//	l.delete_double();
//	l.printlist();
//
//}
/*
* 
9787302257646 程序设计基础 25.00
9787302164340 程序设计基础(第2版) 20.00
9787302219972 单片机技术及应用 32.00
9787302257646 程序设计基础 25.00
9787810827430 工业计算机控制技术--原理与应用 29.00
9787302219972 单片机技术及应用 32.00
0 0 0



9787302257646 程序设计基础 25.00
9787302164340 程序设计基础(第2版) 20.00
9787302219972 单片机技术及应用 32.00
9787302203513 单片机原理与应用技术 26.00
9787810827430 工业计算机控制技术--原理与应用 29.00
9787811230710 C#程序设计易懂易会教程 32.00
0 0 0
*/