#include<iostream>
#include<algorithm>
using namespace std;
int bh[5005];
int score[5005];
int ind[5005];

void unsigned_sort(int l, int r) {

	int index = l;
	for (int i = l+1; i < r; i++) {
		if (score[ind[index]] <= score[ind[i]]){
			if(score[ind[index]] < score[ind[i]]) index = i;
			else if(bh[ind[index]] > bh[ind[i]]) index = i;
		}

	}
	while (index > l) {
		swap(ind[index], ind[index - 1]);
		index--;
	}
	for (int i = l + 1; i < r; i++) {
		int j = i;
		while (score[ind[j]] >= score[ind[j-1]]) {
			if (score[ind[j]] > score[ind[j - 1]])
				swap(ind[j], ind[j - 1]);
			else if (score[ind[j]] == score[ind[j - 1]])
				if (bh[ind[j]] < bh[ind[j-1]])
					swap(ind[j], ind[j - 1]);
			j--;
		}
	}
}

int tsp(int a, int b, int c) {
	if (a > b)swap(a, b);
	if (a > c)swap(a, c);
	if (b > c)swap(b, c);
	return b;
}
#define W 16

void __quick_sort(int l,int r) {
	while (r - l > W) {
		int x = l, y = r - 1, z = (l + r) / 2;
		int mid = tsp(score[ind[x]], score[ind[y]], score[ind[z]]);
		do {
			while (mid < score[ind[x]]) x++;
			while (mid > score[ind[y]]) y--;
			if (x <= y) {
				swap(ind[x], ind[y]);
				x++, y--;
			}
		} while (x <= y);
		__quick_sort(l, y+1);
		l = x;
	}
	while (r - l > W) {
		int x = l, y = r - 1, z = (l + r) / 2;
		int mid = tsp(bh[ind[x]], bh[ind[y]], bh[ind[z]]);
		do {
			while (mid > bh[ind[x]]) x++;
			while (mid < bh[ind[y]]) y--;
			if (x <= y) {
				swap(ind[x], ind[y]);
				x++, y--;
			}
		} while (x <= y);
		__quick_sort(l, y + 1);
		l = x;
	}
	return;
}

void quick_sort(int l, int r) {
	__quick_sort(l, r);
	unsigned_sort(l, r);
}




//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> bh[i] >> score[i];
//		ind[i] = i;
//	}
//	score[0] = 0x0fffffff;
//	quick_sort(1, n + 1);
//	int g = m * 1.5;
//	int minn = score[ind[g]];
//	int count = 0;
//	for (int i = 1; score[ind[i]] >= score[ind[g]]; i++) {
//		count++;
//	}
//	cout << minn << " " << count<<endl;
//	for (int i = 1; i <= count; i++) {
//		cout << bh[ind[i]] << " " << score[ind[i]] << endl;
//	}
//	return 0;
//}

/*sort(ind +1, ind + n +1, [&](int i, int j)-> bool {
	if (score[i] != score[j])
		return score[i] > score[j];
	else
		return bh[i] < bh[j];
	});*/