#pragma once
#include<iostream>
#include<string>
#include<cstring>
#define TELE 12
#define NAME 20
#define ADDR 50
using namespace std;

struct Contect
{
	char name[NAME];
	int sex;
	int age;
	char tele[TELE];
	char address[ADDR];
};
struct Addressbooks
{
	struct Contect *people;
	int p_size;
	int capacity;//当前通讯录的最大容量
};
void InitContect(struct Addressbooks*);
void menu();
void Add_new_contect(struct Addressbooks *);
void Delete_Contect(struct Addressbooks *);
void Search_Contect(struct Addressbooks*);
void Modification_Contect(struct Addressbooks*);
void Print_Contect(struct Addressbooks*);
void Destory_Contect(struct Addressbooks*);