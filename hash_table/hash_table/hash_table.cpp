#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

typedef struct Node{
	char* s;//存储字符串
	struct Node* next;
}Node;

typedef struct HashTable {
	Node* data;//node类型数组，（24.9.12 ps:当时复习感觉像是 邻接表）
	int size;//哈希表大小
	int cnt;//当前哈希表存储了多少个元素

}hashtable;

void clearhashtable(hashtable* h); 
bool insert(hashtable * h, const char* s);

Node* getNewNode(const char *s) {
	Node* p = new Node;
	p->s = strdup(s);
	p->next = NULL;
	return p;
}

hashtable* getNEewhashtable(int n) {
	hashtable* h = new hashtable;
	h->data = new Node[n];
	h->size = n;
	h->cnt = 0;
	return h;
}

int hash_func(const char* s) {//哈希函数（不固定，这里举了一种经典的例子）
	int seed = 131, h = 0;
	for (int i = 0; s[i]; i++) {
		h = h * seed + s[i];
	}
	return h & 0x7ffffff;
}

bool find(hashtable* h, const char* s) {
	int hcode = hash_func(s), ind = hcode % h->size;
	Node* p = h->data[ind].next;
	while (p) {
		if (strcmp(p->s, s) == 0) return true;
		p = p->next;
	}
	return false;
}

void swaphashtable(hashtable* h1, hashtable* h2) {
	swap(h1->data, h2->data);//j交换头指针地址
	swap(h1->cnt, h2->cnt);
	swap(h1->size, h2->size);
	return;
}

void expand(hashtable* h) {
	hashtable* new_h = getNEewhashtable(h->size * 2);
	for (int i = 0; i < h->size; i++) {
		Node* p = h->data[i].next;
		while (p) {
			insert(new_h, p->s);
			p = p->next;
		}
	}
	swaphashtable(h, new_h);
	clearhashtable(new_h);
	return;
}


bool insert(hashtable* h, const char* s) {
	if (h->cnt >= h->size*2)
	{
		expand(h);
	}
	int hcode = hash_func(s), ind = hcode % h->size;
	//冲突处理;
	Node* p = getNewNode(s);
	p->next = h->data[ind].next;
	h->data[ind].next = p;
	h->cnt += 1;
	return true;
}


void clearhashtable(hashtable* h) {
	if (h == NULL)
		return;

	for (int i = 0; i < h->size; i++) {
		Node* p = h->data[i].next, * q;
		while (p) {
			q = p->next;
			delete p->s;
			delete p;
			p = q;
		}
		delete[]h->data;
		delete h;
		return;
	}
}

void output(hashtable* h) {
	cout << endl << endl << "hash table(" << h->cnt << " / " << h->size << "):";
	for (int i = 0; i < h->size; i++) {
		printf("%d :", i);
		Node* p = h->data[i].next;
		while (p) {
			printf("%s -> ", p->s);
			p = p->next;
		}
		cout << endl;
	}
	return;
}

//int main()
//{
//	srand(time(0));
//	char s[100];
//	#define MAX_N 2
//	hashtable* h = getNEewhashtable(2);
//	while (~scanf("%s", s)) {
//		if (strcmp(s, "end")==0) break;
//		insert(h, s);
//	}
//	while (~scanf("%s", s)) {
//		cout << "find(" << s << ") = " << find(h, s) << endl;
//	}
//	output(h);
//	#undef MAX_N
//	return 0;
//}