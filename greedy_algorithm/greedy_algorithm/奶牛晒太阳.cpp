#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


//º£ÔôOJ 253
struct milk {
	int mi;
	int ma;
	int flag;
}arr[2505];

struct desun {
	int sun;
	int num;
}fs[2505];



//int main() {
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i].mi >> arr[i].ma;
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> fs[i].sun >> fs[i].num;
//
//	}
//	sort(arr, arr + n, [](milk& a, milk& b)-> bool { return a.ma < b.ma;
//	});
//	sort(fs, fs+ m, [](desun& a, desun& b)-> bool { return a.sun < b.sun;
//		});
//
//	int count = 0;
//	for (int pos = 0; pos < m;pos++) {
//		for(int so=0;so<n;so++)
//		if ((fs[pos].sun<=arr[so].ma) && (fs[pos].sun>=arr[so].mi) &&(fs[pos].num!=0)&&(arr[so].flag==0)) {
//			fs[pos].num--;
//			count++;
//			arr[so].flag = 1;
//		}
//	}
//	cout << count;
//	return 0;
//}