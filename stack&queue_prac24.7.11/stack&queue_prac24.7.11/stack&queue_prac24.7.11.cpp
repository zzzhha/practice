#include<iostream>
#include <cstdlib>
#include <queue>
#include<stack>
using namespace std;


//2020年数据结构41题
//定义三元组（a,b, c）（a,b,c 均为正数）的距离 D=|a-b|+|b-c|+|c-a|。
// 给定 3 个非空整数集合 S1, S2 ,S3, 按升序分别存储在 3 个数组中。
// 请设计一个尽可能高效的算法，计算并输出所有可能的三元组（a, b, c）
// （a∈S1,b∈S2,c∈S3）中的最小距离。
// 例如 S1={-1, 0, 9}, S2={-25，-10，10，11}，S3={2，9，17，30，41}，
// 则最小距离为 2，相应的三元组为（9，10，9）。

//题解：
//题目已给用队列实现（其实等于数组加相应的函数罢了），观察三组数据
//发现，我们要求的最小距离，将这三个数放入数轴中，即可转换为：
// D=|a-b|+|b-c|+|c-a|就等于D=两倍的最左边的点到最右边的点的距离
//如何使得所得线段的两端距离最小就成了我们所要求的
//所以进行循环，判断如果有一个队列为空了，那么就退出循环（防止越界）
//再将队列中的数据赋值给相应abc，找出abc中的最小数据
//（为什么找最小数据：因为是有序数组，从左到右依次增大
//所以上述所述的求两端距离最小就再次转换成移动最左端数据，使得距离最小）
//用临时值记录当前三个点所得的距离，再用一个值保存最小距离
//如果当前距离小于已记录的最小距离，那么就将此值赋值给保存最小距离的值
//返回记录最小距离的值即可。

int min_num(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    return a;
}

int func(queue<int> que1, queue<int> que2, queue<int> que3) {
    int ans = 0x3f3f3f3f;
    while (!que1.empty() && !que2.empty() && !que3.empty())
    {
        int a = que1.front();
        int b = que2.front();
        int c = que3.front();
        int temp_ans = abs(a - b) + abs(a - c) + abs(b - c);
        if (temp_ans < ans)
            ans = temp_ans;
        int d = min_num(a, b, c);
        if (a == d) que1.pop();
        if (b == d) que2.pop();
        if (c == d) que3.pop();
    }
    return ans;
}

//int main() {
//    int m, n, k, x;
//    queue<int> que1, que2, que3;
//    cin >> m >> n >> k;
//    for (int i = 0; i < m; i++) {
//        cin >> x;
//        que1.push(x);
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> x;
//        que2.push(x);
//    }
//    for (int i = 0; i < k; i++) {
//        cin >> x;
//        que3.push(x);
//    }
//    cout << func(que1, que2, que3) << endl;
//    return 0;
//}



//比较含退格的字符串 
//给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，
// 如果两者相等，返回 true 。# 代表退格字符。

//注意：如果对空文本输入退格字符，文本继续为空。
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1,s2;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '#')
            {
                s1.push(s[i]);
            }
            else
            {
                if (!s1.empty())
                {
                    s1.pop();
                }
            }
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] != '#')
            {
                s2.push(t[i]);
            }
            else
            {
                if (!s2.empty())
                {
                    s2.pop();
                }
            }
        }
        if (s2.size() != s1.size())
        {
            return false;
        }
        while(!s1.empty())
        {
            if (s1.top() != s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};


//火车进栈 
// 有 n 列火车按 1 到 n 的顺序从东方左转进站，
// 这个车站是南北方向的，它虽然无限长，
// 只可惜是一个死胡同，而且站台只有一条股道，
// 火车只能倒着从西方出去，而且每列火车必须进站，先进后出。

// 进站的火车编号顺序为 1∼n，
// 现在请你按火车编号从小到大的顺序，
// 输出前 20 种可能的出站方案。


//题解：暂时不懂，等后面回来再说

bool isValid(int a[], int n)
{
    stack<int>s;
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        if (!s.empty() || s.top() < a[i])
        {
            while (x <= a[i])
            {
                s.push(x++);
            }
        }
        if (s.empty() || s.top() != a[i])
            return false;
        s.pop();
    }
    return true;
}
int main()
{
    int n,a[25],count=20;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        a[i] = i + 1;
    }
    do {
        if (isValid(a, n))
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i];
            }
            cout << endl;
            count -= 1;
        }
    } while (next_permutation(a, a + n)&&count);
    return 0;
}