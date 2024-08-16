#include<iostream>

using namespace std;

typedef struct haffmantree {
	int weight;//权值
	int parent;//双亲下标
	int lchild, rchild;//左右孩子下标
}haffmanNode, * haffmanTree;

void find(haffmanTree tree, int x, int* s1, int* s2) {
	int minn = 0;
	for (int i = 1; i <= x; i++) {
		if (tree[i].parent == 0) {
			minn = i;
			break;
		}
	}
	for (int i = 1; i <= x; i++) {
		if (tree[i].parent == 0 && tree[i].weight < tree[minn].weight) {
			minn = i;
		}
	}
	*s1 = minn;
	for (int i = 1; i <= x; i++) {
		if (tree[i].parent == 0 &&i!=(*s1)) {
			minn = i;
			break;
		}
	}
	for (int i = 1; i <= x; i++) {
		if (tree[i].parent == 0 && tree[i].weight < tree[minn].weight &&i!=(*s1)) {
			minn = i;
		}
		*s2 = minn;
	}

}


haffmanTree buildHaffmanTree(int *w,int n) {
	int m = 2 * n - 1;
	haffmanTree tree = new haffmanNode;
	for (int i = 1; i <= m; i++) {
		tree[i].parent = tree[i].lchild = tree[i].rchild = 0;
		tree[i].weight = 0;
	}
	for (int i = 1; i <= n; i++) {
		tree[i].weight =w[i-1];
	}
	int s1, s2;
	for (int i = n + 1; i <= m; i++) {
		find(tree, i - 1, &s1, &s2);
		tree[s1].parent = tree[s2].parent = i;
		tree[i].lchild = s1;
		tree[i].rchild = s2;
		tree[i].weight = tree[s1].weight + tree[s2].weight;
	}
	return tree;
}

char** createcode(haffmanTree tree,  int n) {
	char* temp = new char[n];
	char** code = new char* [n];
	memset(code, 0, sizeof(char*)*n);
	int start;
	int p, pos;
	for (int i = 1; i <= n; i++) {
		start = n - 1;
		temp[start] = '\0';
		pos = i;
		p = tree[pos].parent;
		while (p != 0) {
			start--;
			temp[start] = ((tree[p].lchild == pos ? '1' : '0'));
			pos = p;
			p = tree[p].parent;
		}
		code[i - 1] = new char[n - start];
		strcpy(code[i - 1], &temp[start]);
	}
	delete[]temp;
	return code;
}

//int main() {
//	char s[8] = { 'A','B','C','D','E','F','G','H' };
//	int w[8] = { 5,29,7,8,14,23,3,11 };
//	haffmanTree tree = buildHaffmanTree(w, 8);
//	char** code = createcode(tree, 8);
//	for (int i = 0; i < 8; i++) {
//		cout << code[i] << endl;
//	}
//	return 0;
//}
