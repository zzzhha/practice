#include<iostream>
#include<deque>
#include<vector>
using namespace std;
//��������:ά��������ֵ 

void output(vector<int>& arr) {
	int n = arr.size();
	int len = 0;
	for (int i = 0; i < n; i++) {
		len += printf("%3d", i);
	}
	cout << endl;
	for (int i = 0; i < len; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	cout << endl;
	return;
}

//int main() {
//	int n, k;//kΪ���䷶Χ
//	cin >> n >> k;
//	deque<int> q;
//	vector<int>arr;
//	for (int i = 0; i < n; i++) {
//		int a;
//		cin >> a;
//		arr.push_back(a);
//	}
//	output(arr);
//	for (int i = 0; i < n; i++) {//�������еĽ������洢����������±�
//		while (!q.empty() && arr[q.back()]> arr[i]) q.pop_back();//ά�������������У������ǰֵ���ȶ���ֵ���һ�����ݴ���arr[i]�����ݣ��򵯳���βԪ��
//		q.push_back(i);//ѹ���±꣬ͨ���±�����ҵ�ֵ�����Ǵ洢ֵ�Ļ��Ҳ����±꣬�������Ϣ��ʧ
//		if (i - q.front() == k)//����ָ���ܵ���k����Ϊÿһ�ν���Ļ����ǵ�������������ȥ�������Ǵ�����������
//		{
//			q.pop_front();
//		}
//		printf("[%d,%d]=arr[%d]=%d\n",
//			max(i - k + 1, 0), i,
//			q.front(), arr[q.front()]);
//	}
//	return 0;
//}