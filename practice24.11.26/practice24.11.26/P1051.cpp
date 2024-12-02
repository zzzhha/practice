#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//struct stu {
//	string name;
//	int qimo_score;
//	int class_score;
//	bool ganbu;
//	bool west;
//	int lunwen;
//	int mi = 0;
//	int val;
//	stu() {}
//	stu(string name, int q,int c,char g, char w, int l, int n)
//	{
//		this->name = name;
//		qimo_score = q;
//		class_score = c;
//		if (g == 'Y') ganbu = 1;
//		else ganbu = 0;
//		if (w == 'Y') west = 1;
//		else west = 0;
//		lunwen = l;
//		val = n;
//	}
//
//	void money() {
//
//		if (qimo_score > 80 && lunwen >= 1) mi += 8000;
//		if (qimo_score > 85 && class_score > 80) mi += 4000;
//		if (qimo_score > 90) mi += 2000;
//		if (west && qimo_score > 85) mi += 1000;
//		if (ganbu && class_score > 80) mi += 850;
//	}
//
//}student[105];
//
//
//int main() {
//	int n;
//	cin >> n;
//	string name;
//	int qimo_score;
//	int class_score;
//	char ganbu;
//	char west;
//	int lunwen;
//	for (int i = 1; i <= n; i++){
//		cin >> name >> qimo_score >> class_score >> ganbu >> west >> lunwen;
//		student[i] = stu(name, qimo_score, class_score, ganbu, west, lunwen ,n-i);
//		student[i].money();
//	}
//
//	sort(student + 1, student + n + 1, [&](stu a, stu b)-> bool {
//		if(a.mi!=b.mi)return a.mi > b.mi;
//		return a.val > b.val;
//		});
//	cout << student[1].name << endl;
//	cout << student[1].mi << endl;
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		sum += student[i].mi;
//	}
//	cout << sum << endl;
//	return 0;
//}