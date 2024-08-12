#include<iostream>


using namespace std;

#define MAX_N 10000
int fa[MAX_N + 5];

void init(int n) {
	for (int i = 0; i <= n; i++) {
		fa[i] = i;
	}
	return;
}

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return find(fa[x]);
	////Â·¾¶Ñ¹Ëõ
	// if(x!+f[x])
	//		return f[x]=find(f[x]);
	// else
	//		return x;
	//
}

int merge(int a, int b) {
	int aa = find(a), bb = find(b);
	if (aa == bb) return 0;
	fa[aa] = bb;
	return 1;
}

void output(int n) {
	int ret = 0;
	for (int i = 0; i <= n; i++) {
		ret += printf("%3d", i);
	}
	cout << endl;
	for (int i = 0; i <= ret; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i <= n; i++) {
		printf("%3d", fa[i]);
	}
	cout << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	init(n);
	int a, b;
	while (cin >> a >> b) {
		cout << "merge "<< a <<" with "<< b << " : " << merge(a, b) << endl;
		output(n);
	}
}