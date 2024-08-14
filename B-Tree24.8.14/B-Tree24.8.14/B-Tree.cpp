#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;
#define MAX_N 5


typedef struct Node {
	int n;
	int key[MAX_N + 1];
	struct Node* next[MAX_N + 1];
}node;

int main() {
	srand(time(0));
	return 0;
}