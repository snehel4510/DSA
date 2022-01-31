// some important algos of binary trees
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
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
        cout << root->data << "\t";
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
int main()
{

    return 0;
}