#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//leetcode128 最长连续序列
// 给定一个未排序的整数数组 nums ，
// 找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

class UnionSet {
public:
	vector<int>fa, size;
	UnionSet(int n) :fa(n + 1), size(n + 1) {
		for (int i = 0; i <= n; i++) {
			fa[i] = i;
			size[i] = 1;
		}
	}
	int find(int x) {
		return fa[x] = (fa[x] == x ? x : find(fa[x]));
	}

	int merge(int a, int b) {
		int aa = find(a), bb = find(b);
		if (aa == bb) return 0;
		fa[aa] = bb;
		size[bb] += size[aa];
		return 1;
	}
};


class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
		UnionSet u(nums.size());
		unordered_map<int, int>h;
		int count = 0;
        for (int i = 0; i < nums.size(); i++){
			int x = nums[i];
			if (h.find(x) != h.end()) continue;
			h[x] = (count++);
			if (h.find(x + 1) != h.end()) u.merge(h[x], h[x + 1]);
			if (h.find(x - 1) != h.end()) u.merge(h[x], h[x - 1]);
        }
		int ans = 0;
		for (int i = 0; i < count; i++) {
			ans = max(ans, u.size[i]);
		}
		return ans;
    }
};


//leetcode 130被围绕的区域
//给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：
//连接：一个单元格与水平或垂直方向上相邻的单元格连接。
//区域：连接所有 'O' 的单元格来形成一个区域。
//围绕：如果您可以用 'X' 单元格 连接这个区域，并且区域中没有任何单元格位于 board 边缘，则该区域被 'X' 单元格围绕。
//通过将输入矩阵 board 中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。

//此题可用dfs和bfs做，此处为练习并查集，所以用并查集做

class Unionset {
public:
	vector<int> fa;
	Unionset(int n) :fa(n + 1) {
		for (int i = 0; i <= n; i++) {
			fa[i] = i;
		}
	}
	int get(int x) {
		return fa[x] = (fa[x] == x ? x : get(fa[x]));
	}
	void merge(int a, int b) {
		if (get(a) == get(b)) return;
		fa[get(a)] = get(b);
		return;
	}
};
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int m = board.size(), n = board[0].size();
		Unionset u(m * n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int ind = i * n + j + 1;
				if (board[i][j] != 'O') continue;
				if (i == 0 || i == m - 1) u.merge(ind, 0);
				if (j == 0 || j == n - 1) u.merge(ind, 0);
				if (j + 1 < n && board[i][j + 1] == 'O') u.merge(ind, ind + 1);
				if (i + 1 < m && board[i + 1][j] == 'O') u.merge(ind, ind + n);
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 'O') continue;
				int ind = i * n + j + 1;
				if (u.get(ind) != u.get(0)) board[i][j] = 'X';
			}
		}
		return;
	}
};



//leetcode200 岛屿数量
//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//岛屿总是被水包围，并且每座岛屿只能由水平方向和 / 或竖直方向上相邻的陆地连接形成。
//此外，你可以假设该网格的四条边均被水包围。
// 
//解法与上题相似，所以用到上题的Unionset
class Unionset {
public:
	vector<int> fa;
	Unionset(int n) :fa(n + 1) {
		for (int i = 0; i <= n; i++) {
			fa[i] = i;
		}
	}
	int get(int x) {
		return fa[x] = (fa[x] == x ? x : get(fa[x]));
	}
	void merge(int a, int b) {
		fa[get(a)] = get(b);
		return;
	}
};
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size(), n = grid[0].size();
		Unionset u(m * n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int ind = i * n + j + 1;
				if (grid[i][j] != '1') continue;
				if (j + 1 < n && grid[i][j + 1] == '1') u.merge(ind, ind + 1);
				if (i + 1 < m && grid[i + 1][j] == '1') u.merge(ind, ind + n);
			}
		}
		int count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int ind = i * n + j + 1;
				if (grid[i][j] == '1' && u.get(ind) == ind)count++;
			}
		}
		return count;
	}
};


//547 省份数量
//有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，
// 且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
//省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
//给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，
// 而 isConnected[i][j] = 0 表示二者不直接相连。
//返回矩阵中 省份 的数量。

class unionset {
public:
	vector<int>fa;
	unionset(int n) :fa(n + 1) {
		for (int i = 0; i <= n; i++) fa[i] = i;
	}
	int get(int x) {
		return fa[x] = (fa[x] == x ? x : get(fa[x]));
	}
	void merge(int a, int b) {
		fa[get(a)] = get(b);
	}
};
class Solution {
public:
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		unionset u(n);
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (isConnected[i][j]) u.merge(i, j);

			}
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (u.get(i) ==i)count++;
		}
		return count;
	}
};