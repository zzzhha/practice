#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//����OJ 44
//f(i)=max(f(j)) j=[1--(i-1)]j����1��i-1
//�˴�����Ż�
//�Ż�����4.3.2
int sequence[1000005];
int sequence_num[1000005];
//��ʾ������еķ���
int sequence_pre[1000005];
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> sequence[i];
//		sequence_num[i] = 1;
//	}
//	int ans = 0;
//	//��ʾ������еķ���
//	int ind = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j < i; j++) {
//			/*if(sequence[j]<sequence[i])
//				sequence_num[i] = max(sequence_num[i],sequence_num[j] + 1);*/
//			//��ʾ������еķ���
//			if (sequence[j] >= sequence[i])continue;
//			if (sequence_num[j] + 1 > sequence_num[i]) {
//				sequence_num[i] = sequence_num[j] + 1;
//				sequence_pre[i] = j;
//			}
//		}
//		//��ʾ������еķ���
//		if (sequence_num[i] > ans) {
//			ans = sequence_num[i];
//			ind = i;
//		}
//		//ans = max(ans, sequence_num[i]);
//	}
//	cout << ans << endl;
//	while (ind) {
//		cout << ind <<"("<<sequence[ind] <<")" << "->";
//		ind = sequence_pre[ind];
//	}
//	cout << endl;
//	return 0;
//}


