// some important algos of binary trees
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// to find the sum of all nodes in a given Binary tree
int sumOfNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
}

// to find max-depth of a given binary tree using queue (iterative approach)
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            Node *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans++;
    }
    return ans;
}

// to find the heigth of a given node in a binary tree
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// to find the minimum depth of a binary tree
int minDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (root->left == NULL or root->right == NULL)
        return 1 + max(l, r);
    return 1 + min(l, r);
}

// to find all leaf nodes of a given binary tree
void findLeafNode(Node *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        cout << root->val << "\t";
        return;
    }
    if (root->right)
        findLeafNode(root->right);
    if (root->left)
        findLeafNode(root->left);
}

// to find maximum width of a binary tree
int widthOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    int ans = 0;
    while (!q.empty())
    {
        int s = q.size();
        int m = q.front().second;
        int f, l;
        for (int i = 0; i < s; i++)
        {
            int id = q.front().second - m;
            Node *n = q.front().first;
            q.pop();
            if (i == 0)
                f = id;
            if (i == s - 1)
                l = id;
            if (n->left != NULL)
                q.push({n->left, 2 * (id) + 1});
            if (n->right != NULL)
                q.push({n->right, 2 * (id) + 2});
        }
        ans = max(ans, l - f + 1);
    }
    return ans;
}

// to find if 2 binary trees are same or not
bool isSameTree(Node *p, Node *q)
{
    if (p == NULL and q == NULL)
        return true;
    if (p != NULL and q != NULL and (p->val == q->val))
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    return false;
}

// Finding the lowest common ancestor(LCA) of two nodes in a binary tree
Node *LCA(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return root;
    if (root == p or root == q)
        return root;
    root->left = LCA(root->left, p, q);
    root->right = LCA(root->right, p, q);
    if (root->left != NULL and root->right != NULL)
        return root;
    if (root->left == NULL and root->right == NULL)
        return NULL;
    return root->left == NULL ? root->right : root->left;
}

// to find the length of the longest path between any 2 nodes in a binary tree
int helper(Node *root, int &s)
{
    if (root == NULL)
        return 0;
    int l = helper(root->left, s);
    int r = helper(root->right, s);
    s = max(l + r, s);
    return max(l, r) + 1;
}
int longestPath(Node *root)
{
    if (root == NULL)
        return 0;
    int s = 0;
    helper(root, s);
    return s;
}

int main()
{

    return 0;
}