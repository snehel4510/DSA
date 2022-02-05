#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// to construct a binary tree based on a given inorder and preorder traversal
class Solution
{
public:
    TreeNode *buildTree(vector<int> &pre, int ps, int pe, vector<int> &in, int is, int ie, unordered_map<int, int> &m)
    {
        if (ps > pe or is > ie)
            return NULL;
        TreeNode *root = new TreeNode(pre[ps]);
        int r = m[root->val];
        int nl = r - is;
        root->left = buildTree(pre, ps + 1, ps + nl, in, is, r - 1, m);
        root->right = buildTree(pre, ps + nl + 1, pe, in, r + 1, ie, m);
        return root;
    }
    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {
        unordered_map<int, int> m;
        int j = 0;
        for (auto i : in)
        {
            m[i] = j;
            j++;
        }
        TreeNode *root = buildTree(pre, 0, pre.size() - 1, in, 0, in.size() - 1, m);
        return root;
    }
};

// to construct a binary tree based on a given inorder and postorder traversal
class Solution
{
public:
    TreeNode *buildTree(vector<int> &post, int ps, int pe, vector<int> &in, int is, int ie, unordered_map<int, int> &m)
    {
        if (ps > pe or is > ie)
            return NULL;
        TreeNode *root = new TreeNode(post[ps]);
        int r = m[root->val];
        int rl = ie - r;
        root->left = buildTree(post, ps + rl + 1, pe, in, is, r - 1, m);
        root->right = buildTree(post, ps + 1, ps + rl, in, r + 1, ie, m);
        return root;
    }
    TreeNode *buildTree(vector<int> &in, vector<int> &post)
    {
        reverse(post.begin(), post.end());
        unordered_map<int, int> m;
        int j = 0;
        for (auto i : in)
        {
            m[i] = j;
            j++;
        }
        TreeNode *root = buildTree(post, 0, post.size() - 1, in, 0, in.size() - 1, m);
        return root;
    }
};

int main()
{
    return 0;
}