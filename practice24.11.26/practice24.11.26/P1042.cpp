//#include<iostream>
//#include<string>
//using namespace std;
//
//string str[2505];
//int win[65000];
//int w, l;
//int main() {
//	char s;
//	for (int i = 1; cin >> s && s != 'E'; i++) {
//		if (s == 'W')win[i] = 1;
//		else if (s == 'L')win[i] = 2;
//		else {}
//	}
//
//	for (int i = 1;; i++) {
//		if (win[i] == 1)w++;
//		if (win[i] == 2)l++;
//		if (win[i] == 0) {
//			cout << w << ":" << l <<endl << endl;
//			break;
//		}
//		if (w - l >= 2 || l - w >= 2) {
//			if (w >= 11 || l >= 11) {
//				cout << w << ":" << l << endl;
//				w = 0;
//				l = 0;
//			}
//		}
//	}
//	w = 0;
//	l = 0;
//
//	for (int i = 1; 1; i++)
//	{
//		if (win[i] == 1)w++;
//		if (win[i] == 2)l++;
//		if (win[i] == 0)
//		{
//			cout << w << ":" << l;
//			break;
//		}
//		if (w - l >= 2 || l - w >= 2)
//			if (w >= 21 || l >= 21)
//			{
//				cout << w << ":" << l << endl;
//				w = 0;
//				l = 0;
//			}
//	}
//	return 0;
//}