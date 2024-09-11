#include<iostream>


using namespace std;

#define MAX_N 10000
int color[MAX_N + 5];
//quick_find
void init(int n) {
	for (int i = 0; i <= n; i++) {
		color[i] = i;
	}
	return;
}

int find(int a) {
	return color[a];
}

int merge(int a, int b, int n) {
	int aa = find(a), bb = find(b);
	if (aa == bb) return 0;
	for (int i = 0; i <= n; i++) {
		if (color[i] == aa) {
			color[i] = bb;
		}
	}
	return 1;
}

void output(int n) {
	int ret = 0;
	for (int i = 0; i <= n; i++) {
		ret+=printf("%3d", i);
	}
	cout << endl;
	for (int i = 0; i <= ret; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i <= n; i++) {
		printf("%3d", color[i]);
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
		cout << "merge "<< a <<" with "<< b << " : " << merge(a, b, n) << endl;
		output(n);
	}
}