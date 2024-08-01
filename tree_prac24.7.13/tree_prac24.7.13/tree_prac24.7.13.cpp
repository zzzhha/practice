#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//1.N叉树的前序遍历
//给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

//n 叉树 在输入中按层序遍历进行序列化表示，
// 每组子节点由空值 null 分隔（请参见示例）。
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
//解法一：遍历树的每一个子树
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == NULL)
            return vector<int>();//如果为空，返回空
        vector<int> ans;
        ans.push_back(root->val);
        for (auto x : root->children) {
            vector<int>temp = preorder(x);
            for (auto y : temp)ans.push_back(y);
        }
        return ans;
    }
};
//解法二：
class Solution {
public:
    void __preorder(Node* root, vector<int>& ans)
    {
        if (root == NULL)return;
        ans.push_back(root->val);
        for (auto x : root->children) {
            __preorder(x, ans);
        }
        return;
    }
    vector<int> preorder(Node* root) {
        vector<int>ans;
        __preorder(root, ans);
        return ans;
    }
};


//从前序与中序遍历构造二叉树

//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
// inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        int pos = 0,n=preorder.size();
        while (inorder[pos] != preorder[0])
            pos += 1;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int>preArr, inArr;
        for (int i = 1; i <= pos; i++)
        {
            preArr.push_back(preorder[i]);//保存前序遍历左子树的数据
        }
        for (int i = 0; i < pos; i++)
        {
            inArr.push_back(inorder[i]);//保存中序遍历左子树的数据
        }
        root->left = buildTree(preArr, inArr);
        preArr.clear();
        inArr.clear();
        for (int i = pos + 1; i < n; i++)
        {
            preArr.push_back(preorder[i]);//保存前序遍历右子树的数据
        }
        for (int i = pos+1; i < n; i++)
        {
            inArr.push_back(inorder[i]);//保存中序遍历右子树的数据
        }
        root->right = buildTree(preArr, inArr);
        return root;
    }
};

//二叉树的层序遍历
//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
// （即逐层地，从左到右访问所有节点）

//解法一：用队列完成层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (root == NULL)
            return vector<vector<int>>();
        TreeNode* node;
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty())
        {
            int cnt = q.size();
            vector<int> temp;
            for (int i = 0; i < cnt; i++)
            {
                node = q.front();
                temp.push_back(node->val);
                if (node->left)q.push(node->left);
                if (node->right)q.push(node->right);
                q.pop();
                
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//解法二：用栈使用深度搜索完成层序遍历

class Solution {
public:
    void dfs(TreeNode  * root, int k, vector<vector<int>>& ans)
    {
        if (root == NULL)
            return;
        if (k ==ans .size()) ans.push_back(vector<int>());
        ans[k].push_back(root->val);
        dfs(root->left, k + 1, ans);
        dfs(root->right, k + 1, ans);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};


//翻转二叉树
//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

