#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//1.N������ǰ�����
//����һ�� n �����ĸ��ڵ�  root ������ ��ڵ�ֵ�� ǰ����� ��

//n ���� �������а���������������л���ʾ��
// ÿ���ӽڵ��ɿ�ֵ null �ָ�����μ�ʾ������
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
//�ⷨһ����������ÿһ������
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == NULL)
            return vector<int>();//���Ϊ�գ����ؿ�
        vector<int> ans;
        ans.push_back(root->val);
        for (auto x : root->children) {
            vector<int>temp = preorder(x);
            for (auto y : temp)ans.push_back(y);
        }
        return ans;
    }
};
//�ⷨ����
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


//��ǰ��������������������

//���������������� preorder �� inorder ������ preorder �Ƕ����������������
// inorder ��ͬһ����������������빹�����������������ڵ㡣

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
            preArr.push_back(preorder[i]);//����ǰ�����������������
        }
        for (int i = 0; i < pos; i++)
        {
            inArr.push_back(inorder[i]);//�����������������������
        }
        root->left = buildTree(preArr, inArr);
        preArr.clear();
        inArr.clear();
        for (int i = pos + 1; i < n; i++)
        {
            preArr.push_back(preorder[i]);//����ǰ�����������������
        }
        for (int i = pos+1; i < n; i++)
        {
            inArr.push_back(inorder[i]);//�����������������������
        }
        root->right = buildTree(preArr, inArr);
        return root;
    }
};

//�������Ĳ������
//����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� ��
// �������أ������ҷ������нڵ㣩

//�ⷨһ���ö�����ɲ������
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

//�ⷨ������ջʹ�����������ɲ������

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


//��ת������
//����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣

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

