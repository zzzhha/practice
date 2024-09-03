#include<iostream>

using namespace std;

int add(int a, int b) {
	cout << "调用int类型";
	return a + b;
}

double add(double a, double b) {
	cout << "调用double类型";
	return a + b;
}

int main() {
	cout << add(1.0, 2.0);
	return 0;
}