#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//leetcode128 ���������
// ����һ��δ������������� nums ��
// �ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�
//������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣

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


//leetcode 130��Χ�Ƶ�����
//����һ�� m x n �ľ��� board ���������ַ� 'X' �� 'O' ��ɣ����� ���� ��Χ�Ƶ�����
//���ӣ�һ����Ԫ����ˮƽ��ֱ���������ڵĵ�Ԫ�����ӡ�
//������������ 'O' �ĵ�Ԫ�����γ�һ������
//Χ�ƣ������������ 'X' ��Ԫ�� ����������򣬲���������û���κε�Ԫ��λ�� board ��Ե��������� 'X' ��Ԫ��Χ�ơ�
//ͨ����������� board �е����� 'O' �滻Ϊ 'X' �� ����Χ�Ƶ�����

//�������dfs��bfs�����˴�Ϊ��ϰ���鼯�������ò��鼯��

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



//leetcode200 ��������
//����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
//�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ����� / ����ֱ���������ڵ�½�������γɡ�
//���⣬����Լ��������������߾���ˮ��Χ��
// 
//�ⷨ���������ƣ������õ������Unionset
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


//547 ʡ������
//�� n �����У�����һЩ�˴���������һЩû��������������� a ����� b ֱ��������
// �ҳ��� b ����� c ֱ����������ô���� a ����� c ���������
//ʡ�� ��һ��ֱ�ӻ��������ĳ��У����ڲ�������û�������ĳ��С�
//����һ�� n x n �ľ��� isConnected ������ isConnected[i][j] = 1 ��ʾ�� i �����к͵� j ������ֱ��������
// �� isConnected[i][j] = 0 ��ʾ���߲�ֱ��������
//���ؾ����� ʡ�� ��������

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