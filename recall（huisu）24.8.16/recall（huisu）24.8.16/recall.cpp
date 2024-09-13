#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<list>
#include<easyx.h>
#include<unordered_map>
using namespace std;

//复习递归

//指数型枚举

int arr[10];

void printf_one_result(int n) {
	for (int i = 0; i <= n; i++) {
		if (i)cout << " ";
		cout << arr[i];
	}
	cout << endl;
	return;
}

void exponential_enum(int i, int j ,int n) //此递归函数表示第i个位置最小放置的元素为j，最大不超过n。实现所有的指数型枚举
{
	if (j > n)//边界条件
		return;
	for (int k = j; k <= n; k++) 
	{
		arr[i] = k;
		printf_one_result(i);//打印当前arr数组的所有元素
		exponential_enum(i + 1,k + 1, n);//进行下一次递归，i+1表示在那个位置，k+1表示当前最小数字为多少
	}
	return;
	
}


//组合型枚举
int arr1[10];
void printf_on_result(int n) {
	for (int i = 0; i < n; i++) {
		if (i)cout << " ";
		cout << arr1[i];
	}
	cout << endl;
	return;
}
void combinatorial_enum(int i, int j, int n, int k)//此递归函数表示，第i个位置最小数据位j，并且总数不超过k个，最大不超过n 
{
	if (i == k)
	{
		printf_on_result(k);
		return;
	}
	for (int q = j; q <= n; q++) {
		arr1[i] = q;
		combinatorial_enum(i + 1, q + 1, n, k);
	}

	return;
}

//排列型枚举
int arr2[10];
int vis[10] = { 0 };
void printf_o_result(int n) {
	for (int i = 0; i < n; i++) {
		if (i)cout << " ";
		cout << arr2[i];
	}
	cout << endl;
}

void arrange_enum(int i,  int n)//此递归函数表明，且数量不能超过n,大小不超过n
{
	if (i == n) {
		printf_o_result(n);
		return;
	}
	for (int x = 1; x <= n; x++) {
		if (vis[x])continue;
		arr2[i] = x;
		vis[x] = 1;
		arrange_enum(i + 1,n);
		vis[x] = 0;
	}
}
//


//int main() {
//	int n;
//	cin >> n;
//	//exponential_enum(0,1,n);
//	int  m;
//	//cin >> n >> m;
//	//combinatorial_enum(0, 1, n, m);
//
//	arrange_enum(0,  n);
//	return 0;
//}






//回溯例题1：八皇后 洛谷P1219

#define MASK(n) ((1 << (n + 1)) - 2)
IMAGE xiebian;
IMAGE fanxiebian;

unordered_map<int, int> ind;

//根据P1219我们要打印三个八皇后的排列，所以设置一个全局变量为3
int total_ans = 3;
//此数组记录每个点放置的位置
int arr_quene[20];
void print_one_result(int n) {
	for (int i = 1; i <= n; i++) {
		if (i > 1)cout << " ";
		cout << arr_quene[i];
	}
	cout << endl;
	total_ans -= 1;
	return;
}

//第一个值代表我们以前已经放置了i行的皇后，现在要放第i行的皇后,表示皇后的横坐标
//第二个值代表 每一列的状态码
//第三个值代表 每一斜行的状态码
//第四个值代表 每一反斜行的状态码
//第五个值代表 有多少行
int dfs(int i, int t1, int t2, int t3 ,int n) {
	if (i > n) {//表明n行都放置了皇后，此时我们就可以打印一组结果
		//此处if是为了完成洛谷P1219所述要求，如果只是完成n皇后可以不if
		if(total_ans)print_one_result(n);
		return 1;
	}
	//此时说明需要放置本层皇后
	//需要去枚举当前这一层我们可以使用的数字都包括什么

	//1)-t & t  表示当前掩码值的最后一位为1位权，我们需要获得他所对应的编号值
	//  我们可以使用一个哈希表 完成位权到编号的一个映射
	//2)t-=此值 表示我们此位置的值已经完成放置了，此位置应从1变为0，
	//  我们就让i去减等这个值，就会让掩码值的相应位置的1变成0
	int ans = 0;//此值是为了完成洛谷P1219需要统计总共有多少种存储方式，不影响八皇后的整体思路
	for (int t = t1; t != 0; t -= (-t & t)) 
	{
		//j值就表示当前在掩码值里能够被使用的最低位置的值
		//j值存储了皇后的纵坐标（[][j]）
		int j = ind[-t & t];//用j表示此编号值
		//现在需要判断 j这个数字在斜行和反斜行是不是有冲突
		//现在表示我的皇后可以放在[i][j]的位置上，需要判断是否在斜行和反斜行上有冲突
		
		//如果正反斜线都可以使用，那么代表此值能存放在这个位置
		//公式为什么是这个去看存储的图片
		if ((t2 & (1 << (i + j - 1))) && (t3 & (1 << (i - j + n)))) 
		{
			arr_quene[i] = j;//表明我们在第i行第j列存放了一个点,只是为了打印，不影响n皇后排列

			//此时代表我们存储成功了，需要进行下一行的皇后的存储
			//第一个数值代表我们应该在第i+1位进行插入皇后
			//第二个值 用t1按位异或上当前存储在此位置的皇后的列不可以用了（就是j位置上所对应的掩码的二进制从1变成0了）
			//第三第四个值同上，公式同if所述
			ans+=dfs(i + 1, (t1 ^ (1 << j)), 
							t2 ^ (1 << (i + j - 1)),
							t3 ^ (1 << (i - j + n)), 
							n
							);
		}
	}
	return ans;
}

int main() {
	int n;//n代表八皇后的棋盘n*n 有n个皇后 n<=13
	int MASK;//掩码
	cin >> n;
	total_ans = 3;//根据P1219我们要打印三个n皇后的排列，此处更新此全局变量
	for (int i = 0; i < 2 * n; i++) {
		ind[1 << i] = i;//位权就是1左移i位所对应的编号应该是i，表示二进制数第i位值所对应的那个值
		//此值作为下标，i作为结果，也就是我们通过掩码值的位移，作为哈希表的下标，可以获取这是第几位的编号值
	}
	//MASK = (1 << (n + 1)) - 1;//1左移n+1位我们就能得到1000000（n+2位）
	//MASK -= 1;//再减去一个1就可以得到  1111111（n+1位）,因为末尾二进制的1用不到，所以我们要再减去一个1
	//就能得到了11111110
	//以八皇后举例，n=8，我们左移9位就可以得到1个1 9个0
	//先减1 就得到了 9个1
	//因为最后一位1不用 再减去1 ，得到8个1 1个0 1111 1111 0
	//所以这就是为什么要位移n+1位（得到8个1）
	//最低位置上的1不用是因为 最低位置的1代表的是0行0列
	//我们计算从1行1列开始计算，所以不用
	//如果要用，那么 左移n位就可以了
	//这8个1是优化方案：状态压缩
	//本来是用一个数组来表示当前位置的值可以用还是不能用（0不能用 1能用）
	//现在用一个int类型的二进制位来表示当前位置的值能不能用
	//上方用宏表示了

	//第一个值代表当前已经确定了第几行的皇后,从第一行开始
	//第二个值表示 每一列上放置了那些皇后 表示列的状态
	//第三个值表示 每一斜行都放置了那些皇后 表示斜边的状态
	//第四个值表示 每一反斜行都放置了那些皇后 表示反斜边的状态
	//第五个值表示 有多少行
	//最多有n列，最多有2*n-1条斜边和反斜边
	int ans=dfs(1, MASK(n), MASK(2 * n - 1), MASK(2 * n - 1),n);
	//加载图片是为了更好的理解为什么有2*n-1条斜边，并不影响做题
	loadimage(&xiebian, "photo/斜边.jpg",500,500);//图片中的i,j表示当前皇后的坐标
	loadimage(&fanxiebian, "photo/反斜边.jpg", 500, 500);//图片中的i,j表示当前皇后的坐标，n代表棋盘大小

	cout << ans;
	return 0;
}