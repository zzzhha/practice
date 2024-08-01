#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
#define SMALL_DATA_N 5000
#define BIG_DATA_N 10000000


//__attribute__((constructor))
void __init_Rand__() {
	printf("init rand\n");
	srand(time(0));
}

bool check(int* arr, int l, int r) {
	for (int i = l + 1; i < r; i++)
	{
		if (arr[i] < arr[i - 1])return false;
	}
	return true;
}

int* getRandData(int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 10000;
	return arr;
}

#define TEST(func,arr,n)\
{ \
	printf("Test %s:",#func);\
	int *temp=new int[n];\
	memcpy(temp,arr,sizeof(int)*n);\
	long long b=clock();\
	func(temp,0,n);\
	long long e=clock();\
	if (check(temp, 0, n))\
	{\
	cout<<"\tOK";\
	}\
	else\
	{\
		cout<<"failed";\
	}\
	cout<<(e-b)*1000/CLOCKS_PER_SEC<<" ms\n";\
	delete[]temp;\
}