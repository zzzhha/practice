#include<iostream>

using namespace std;
//int arr[100005];
//
////归并排序O(nlogn)
//void merge_sort(int l, int r) {
//	int* buff = new int[1000000];
//	if (r - l <= 1) return;
//	int mid = (l + r) / 2;
//	merge_sort(l, mid);
//	merge_sort(mid, r);
//	int p1 = l, p2 = mid, k = 0;
//	while (p1 < mid || p2 < r) {
//		if (p2 == r || (p1 < mid && arr[p1] <= arr[p2])) {
//			buff[k++] = arr[p1++];
//		}
//		else buff[k++] = arr[p2++];
//	}
//	for (int i = l; i < r; i++) {
//		arr[i] = buff[i - l];
//	}
//	delete[]buff;
//}
//
////快排
//void uninsert_sort(int l,int r) {
//	int ind = l;
//	for (int i = l + 1; i < r; i++) {
//		if (arr[i] < arr[ind])ind = i;
//	}
//	while (ind > l) {
//		swap(arr[ind], arr[ind - 1]);
//		ind--;
//	}
//	for (int i = l + 1; i < r; i++) {
//		int j = i;
//		while (arr[j] < arr[j - 1]) {
//			swap(arr[j], arr[j - 1]);
//			j--;
//		}
//	}
//
//}
//
//int tps(int a, int b, int c) {
//	if (a > b)swap(a, b);
//	if (a > c)swap(a, c);
//	if (b > c)swap(b, c);
//	return b;
//}
//#define T 16
//void __quick_sort(int l, int r) {
//	while (r - l > T) {
//		int x = l, y = r - 1;
//		int z = tps(arr[l], arr[r - 1], arr[(l + r) / 2]);
//		do {
//			while (z > arr[x]) ++x;
//			while (arr[y] > z) --y;
//			if (x <= y) {
//				swap(arr[x], arr[y]);
//				++x, --y;
//			}
//		} while (x <= y);
//		__quick_sort(l, y + 1);
//		l = x;
//	}
//	return;
//}
//
//void quick_sort(int l ,int r) {
//	__quick_sort(l, r);
//	uninsert_sort(l, r);
//}
//
////基数排序O(nlogm) n关键字个数 ，基数排序的轮数
//#define K 65536
//void radix_sort(int l ,int r) {
//	int* cnt = new int[K];
//	int* temp = new int[r - l];
//	memset(cnt, 0, sizeof(int) * K);
//	for (int i = l; i < r; i++) cnt[arr[i] % K] += 1;
//	for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
//	for (int i = r - 1; i >= l; i--)temp[--cnt[arr[i] % K]] = arr[i];
//	memcpy(arr + l, temp, sizeof(int) * (r - l));
//	
//	memset(cnt, 0, sizeof(int) * K);
//	
//	for (int i = l; i < r; i++)cnt[arr[i] / K] += 1;
//	for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
//	for (int i = r - 1; i >= l; i--)temp[--cnt[arr[i] / K]] = arr[i];
//	memcpy(arr + l, temp, sizeof(int) * (r - l));
//	return;
//}
//
////希尔排序hibbard增量序列
//void uninsert_sort(int l, int r,int step) {
//	int ind = l;
//	for (int i = l + step; i < r; i+=step) {
//		if (arr[i] < arr[ind])ind = i;
//	}
//	while (ind > l) {
//		swap(arr[ind], arr[ind - step]);
//		ind-=step;
//	}
//	for (int i = l + 2*step; i < r; i+=step) {
//		int j = i;
//		while (arr[j] < arr[j - step]) {
//			swap(arr[j], arr[j - step]);
//			j-=step;
//		}
//	}
//
//}
//void shell_sort(int l,int r) {
//	int step = 1, n = r - l;
//	while (step <= n / 2) step = step * 2 + 1;
//	do {
//		step /= 2;
//		for (int i = l, I = l + step; i < I; i++) uninsert_sort(i, r, step);
//	} while (step > 1);
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> arr[i];
//	radix_sort(1, n+1);
//	for (int i = 1; i <= n; i++) cout<< arr[i] << " ";
//	return 0;
//}