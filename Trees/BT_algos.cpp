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

// Finding the lowest common ancestor(LCA) of two nodes in a binary tree
// root-to-node path traversal
bool getPath(Node *root, int x, vector<Node *> &arr)
{
    if (root == NULL)
        return false;
    arr.push_back(root);
    if (root->val == x)
        return true;
    if (getPath(root->left, x, arr) or getPath(root->right, x, arr))
        return true;
    arr.pop_back();
    return false;
}
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return root;
    vector<Node *> p1, q1;
    getPath(root, p->val, p1);
    getPath(root, q->val, q1);
    int i = 0;
    while (i < p1.size() and i < q1.size())
    {
        if (p1[i]->val != q1[i]->val)
            break;
        i++;
    }
    return p1[i - 1];
}

int main()
{

    return 0;
}