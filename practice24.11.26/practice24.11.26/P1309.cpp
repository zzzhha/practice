#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct selecter {
	int power;
	int point;
	int bh;
	selecter() :power(0), point(0), bh(0) {}

}player[100005];

selecter* buff = new selecter[1000000];
void merge_sort(int l, int r) {
	if (r - l <= 1) return;
	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid, r);
	int p1 = l, p2 = mid, k = 0;
	while (p1 < mid || p2 < r) {
		if (p2 == r || (p1 < mid && player[p1].power <= player[p2].power)) {
			buff[k++] = player[p1++];
		}
		else buff[k++] = player[p2++];
	}
	for (int i = l; i < r; i++) {
		player[i] = buff[i - l];
	}
}


int main() {
	int n,q,r;
	cin >> n >> q >> r;
	for (int i = 0; i < 2 * n; i++) cin >> player[i].point;
	for (int i = 0; i < 2 * n; i++) cin >> player[i].power;
	for (int i = 0; i < 2 * n; i++) player[i].bh = i + 1;
	sort(player, player + 2 * n, [&](selecter a, selecter b)-> bool {
		if (a.point == b.point) return a.bh < b.bh;
		return a.point > b.point;
		});
	for(int i=0;i<q;i++){
		
		for (int j = 0; j < 2 * n; j += 2) {
			if (player[j].power > player[j + 1].power) player[j].point++;
			else player[j + 1].point++;
		}
	}
	cout << player[r].bh;
	return 0;
}