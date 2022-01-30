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
int main()
{

    return 0;
}