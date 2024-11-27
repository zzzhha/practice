#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


//海贼OJ 257 极难！！！
//看视频吧，贪心第十讲，不想写注释了
#define MAX_N 1000

int C[MAX_N + 5] = { 0 };//存储染色的代价基础值
int fa[MAX_N + 5] = { 0 };//存储第i个节点的父节点的编号,并查集
int vis[MAX_N + 5] = { 0 };//标记已经合并的节点，节点名作为下标，存储0代表未合并，1代表已合并
double w[MAX_N + 5] = { 0 };//用于比较的平均权值
int cnt[MAX_N + 5] = { 0 };//表示第i个节点，所包含的节点数量
int n, r;
long long ans = 0;

int find_x() {
	int x = -1;
	for (int i = 1; i <= n; i++) {
		if (i == r || vis[i] == 1)continue;//如果已经被合并，则继续
		if (x == -1 || w[x] < w[i])//如果当前值为无效值，或者之前找的那个节点的平均权值小于当前节点的平均权值，见合并节点处
			x = i;
	}
	return x;
}

int find_father(int x) {
	if (vis[fa[x]])//如果x节点的父节点被合并了，那么我们就需要继续向上去找x父节点的父节点是否被合并
		return find_father(fa[x]);
	return fa[x];//如果没有被合并，那么就返回x的父节点
}

int main() {
	cin >> n >> r;
	for (int i = 1; i <= n; i++) {
		cin >> C[i];//存储染色的代价基础值
		//此处ans+=ci是因为我们对树的节点进行了合并T(x1)+(T+1)x2=T(x1+x2)+x2;
		//按照此法，将所有节点合并就成了T(x1)+(T+1)x2+(T+3)x3……(T+n)xn=T(x1+x2+……+xn)+x1+x2+……+xn
		ans += C[i];
		fa[i] = i;
		w[i] = C[i];//在初始化的时候节点并未合并，所以每个节点的权值就你等于他自身所带值
		cnt[i] = 1;//每个节点原始包含的节点数量只有自己本身，也就是1

	}
	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		fa[b] = a;//b节点的父节点是a节点，也就是改变并查集了

	}
	for (int i = 1; i < n; i++)//要对n个节点进行合并，就要进行n-1轮
	{
		int x = find_x();//找到权值最大的节点
		//找到当前权值最大的节点的父节点
		//为什么不用fa[x]去找:是因为fa[x]的节点可能已经被合并了，不是当前x的父节点了
		//所以我们需要找到x节点真正的父节点，也就是那个合并后的节点
		int father_x = find_father(x);
		//x和father_x合并中，会出现一个德尔塔值
		//T*y+(T+n)*x=T*(y+x)+n*x;这个德尔塔值就等于n*x，n是父节点中包含的节点数量
		//合并x和x的父节点，ans所加的值根据上面的公式就是父节点所包含的节点的数量*当前节点的C[x]值
		ans += cnt[father_x] * C[x];
		//合并操作
		C[father_x] += C[x];//合并基础代价值
		cnt[father_x] += cnt[x];//合并节点数量
		//用于比较的权值存储的是节点的平均权值
		//他等于 父节点的权值和再除以 父节点的节点总数
		w[father_x] = 1.0 * C[father_x] / cnt[father_x];
		vis[x] = 1;//代表x节点已经被合并过了
	}
	cout << ans << endl;//最小的染色代价
	return 0;
}