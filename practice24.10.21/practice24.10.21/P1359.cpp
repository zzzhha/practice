#include<iostream>

using namespace std;

int arr[100][100];



int main() {
	/*int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j==1 || i == j) continue;
			arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << arr[i][j] << " ";
			
		}
		cout << endl;
	}*/
	double arr1[7];//y->u
	int arr2[7] = { 0,20,40,60,80,100,120 };//x->w
	for (int i = 0; i < 7; i++) cin >> arr1[i];
	double sum1 = 0;//u�ܺ�
	double sum2 = 0;//w�ܺ�
	double sum5 = 0;//w*u�ܺ�
	double sum6 = 0;//w^2�ܺ�
	for (int i = 0; i < 7; i++) sum1 += arr1[i];//u
	for (int i = 0; i < 7; i++) sum2 += arr2[i];//w
	for (int i = 0; i < 7; i++) sum5 += arr2[i]*arr1[i];//w*u
	for (int i = 0; i < 7; i++) sum6 += arr2[i]*arr2[i];//w*w
	double u = sum1 / 7.0;//uƽ�� yƽ��
	double w = sum2 / 7.0;//wƽ�� xƽ��
	double b = 0;
	double tempx = 0;//x->w 
	double tempy = 0;//y->u 
	double sum3 = 0;//���� 
	double sum4 = 0;//��ĸ wi-w -> xi-x
	for (int i = 0; i < 7; i++) {
		tempx = arr2[i] - w;//wi-w x
		tempy = arr1[i] - u;//ui-u y
		sum3 += tempx * tempy;
		sum4 += tempx * tempx;
	}
	b = sum3 / sum4;
	double a = u - b * w;
	printf("%.1lf %.1lf\n",sum3, sum4);
	printf("-u=%.2lf a=%.2lf b=%.2lf\n",u ,a, b);
	double s= ((sum2 * sum1) - (7 * sum5)) / ((sum2 * sum2) - 7 * sum6);
	double U = u - s * w;
	printf("K=S=%.2lf U'=%.2lf", s, U);
	return 0;
}