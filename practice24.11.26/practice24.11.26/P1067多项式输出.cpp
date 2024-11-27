#include<iostream>
#include<string>
using namespace std;

//int main() {
//	int n;
//	cin >> n;
//	int arr[105] = { 0 };
//	for (int i = 0; i <= n; i++) {
//		cin >> arr[i];
//	}
//	for (int i = n,j=0; i >=0 ; i--,j++) {
//		if (arr[j] == 0) continue;
//		else if (j == n)
//		{
//			if (arr[j] > 0 )
//			{
//				if(i!=n)
//					cout << "+";
//				cout << arr[j];
//			}
//			else cout << arr[j];
//		}
//		else if (j == n - 1)
//		{
//			if (arr[j] > 0 && arr[j] != 1)
//			{
//				cout << "+";
//				cout << arr[j] << "x";
//			}
//			else if (arr[j] == 1) cout << "+x";
//			else if (arr[j] == -1)cout << "-x";
//			else cout << arr[j] << "x";
//			
//		}
//		else if (arr[j] == 1) 
//		{
//			if (i != n)
//				cout << "+x^" << i;
//			else cout << "x^" << i;
//		}
//		else if (arr[j] == -1)
//		{
//			if (i != n)
//				cout << "-x^" << i;
//			else
//				cout << "-x^" << i;
//		}
//		
//	
//		else if (arr[j] > 0 && i!= n )cout << "+" << arr[j] << "x^" << i;
//		else cout << arr[j] << "x^" << i;	
//	}
//	return 0;
//}