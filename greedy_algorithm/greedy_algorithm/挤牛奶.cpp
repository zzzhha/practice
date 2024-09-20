#include<iostream>
#include<algorithm>
using namespace std;


//海贼OJ 254
struct cow {
	int start;
	int end;
	int id;
}co[50005];

int m_time[50005];
int bh[50005]; 
int cnt = 0;

bool cmp(cow& a, cow& b) {
	if (a.start != b.start) return a.start < b.start;
	return a.id < b.id;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &co[i].start, &co[i].end);
		co[i].id = i;
	}
	sort(co, co + n, cmp);
	for (int i = 0; i < n; i++) {
		int pos = -1;
		for (int j = 0; j < cnt; j++) {
			if (m_time[j] < co[i].start) {
				pos = j;
				break;
			}
		}
		if (pos == -1) {//代表原有机器都在被使用,需要新分配挤奶机
			pos=(cnt++);
		}
		m_time[pos] = co[i].end;
		bh[co[i].id] = pos + 1;
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		cout << bh[i] << endl;
	}
	return 0;
}