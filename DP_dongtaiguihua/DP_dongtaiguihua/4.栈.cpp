#include<iostream>
#include<algorithm>

using namespace std;


//洛谷P1044
int stack[25];//表示i个数能得到的输出序列的总和


//int main() {
//	int n;
//	cin >> n; 
//	stack[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		stack[i] = 0;
//		for (int x = 1; x <= i; x++) {
//			stack[i] += stack[x - 1] * stack[i - x];//x为最后一个出栈的元素，
//			//则总共的出栈方法就可以划分为，x前面的元素怎么入栈出栈，x后面的元素怎么出栈入栈
//			//最后使得x最后一个出栈
//			//用这种方法，使x从1-i遍历，就可以得到当前栈若有i个元素的总共出栈输出序列的总和了
//
//		}
//	}
//
//	cout << stack[n] << endl;
//	return 0;
//}