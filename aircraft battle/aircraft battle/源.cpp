#include<iostream>

using namespace std;

int add(int a, int b) {
	cout << "����int����";
	return a + b;
}

double add(double a, double b) {
	cout << "����double����";
	return a + b;
}

int main() {
	cout << add(1.0, 2.0);
	return 0;
}