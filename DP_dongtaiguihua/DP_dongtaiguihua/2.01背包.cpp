#include<iostream>
#include<algorithm>

using namespace std;

//����OJ 47
//f(i,j)ǰ��i����Ʒ����������Ϊjʱ�� ��ż�ֵ
long long bag01_weight[105];
long long bag01_val[105];
long long bag01_ret[105][10005] = { 0 };
//�Ż�
long long bag01_ret_plus[2][10005] = { 0 };

//int main() {
//	int v, n;
//	cin >> v >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> bag01_weight[i];
//		cin >> bag01_val[i];
//	}
//
//	for (int i = 1; i <=n; i++) {
//		for (int j = 1; j <=v;j++ ) {
//			bag01_ret[i][j] =bag01_ret[i - 1][j];
//			//�Ż�
//			//int ind=i%2,rind=(i-1)%2//ģ�⵱ǰ״̬����һ��״̬
//			//bag01_ret_plus[ind][j]=bag01_ret_plus[rind][j];//��ǰ״ֵ̬������һ��״ֵ̬
//			if (j < bag01_weight[i])continue;
//			bag01_ret[i][j] = max(bag01_ret[i][j], bag01_ret[i - 1][j - bag01_weight[i]] + bag01_val[i]);
//			//��[i-1][j - bag01_weight[i]]��Ϊ����ΪҪʹ�õ�i����Ʒ����������ҪΪ��i����Ʒ�����ռ�
//			//Ҳ��������Ҫ����i-1����Ʒ������j - bag01_weight[i]�Ŀռ�ļ�ֵ
//			//�Ż�
//			//bag01_ret_plus[ind][j]=max(bag01_ret_plus[ind][j],bag01_ret_plus[rind][j-bag01_weight[i]]+bag01_val[i])
//			//�Ƚϵ�ǰ״ֵ̬����һ��״ֵ̬����Ӧ�ļ�ȥ��ǰ��Ʒ�������õ��ļ�ֵ���ϱ���Ʒ�ļ�ֵ
//			//��ʵ����δ�Ż���bag01_ret[i][j] = max(bag01_ret[i][j], bag01_ret[i - 1][j - bag01_weight[i]] + bag01_val[i]);
//			//ֻ�ǰѴ�����ı���˹�������
//			//�ܸĵ�ԭ���������ֵֻ��weight��val��ֵ�йأ����ǵ�i����Ʒ�޹�
//			//���԰ѵ�i����Ʒ��105�ı��2 ����˹�������
//		}
//	}
//	cout << bag01_ret[n][v];
//	//�Ż�
//	//cout << bag01_ret_plus[n%2][v];
//	return 0;
//}

//�Ż�plusplus
//�Ż�plusplus
long long bag01_ret_plusplus[10005] = { 0 };//��ά�����Ż���һά����
//int main() {
//	int v, n;
//	cin >> v >> n;
//	for (int i = 1, weight, val; i <= n; i++) {
//		cin >> weight >> val;//ֱ�Ӷ�������Ϊ�������״ֵ̬��ʱ��ֻ��Ҫ��ȡ���ֵ�ֵ���ò���������ֵ������û��Ҫ��ǰ����
//		//�Ż�plusplus
//		for (int j = v; j >= weight; j--) {
//			bag01_ret_plusplus[j] = max(bag01_ret_plusplus[j], bag01_ret_plusplus[j - weight] + val);
//		}
//		//�˴�������Ϊ�˷�ֹ��Ϊbag01_ret_plusplus[j-weight]��ֵ���£����� bag01_ret_plusplus[j]��ֵ���£����Ե���
//	}
//	//�Ż�plusplus
//	cout << bag01_ret_plusplus[v];
//	return 0;
//}
