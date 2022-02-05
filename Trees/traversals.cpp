// Binary tree traversals - BFS, DFS, Level order, In/Pre/Post order, etc
// BFS means level order traversal
// DFS means root-to-leaf or leaf-to-root traversal using in/pre/post order traversals
#include <bits/stdc++.h>
using namespace std;
// binary tree
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
// DFS or In/Pre/Post order traversals already done recursively in BST code
// iterative In/Pre/Post order traversals in one function...

// iterative BFS using stack
void BFSi(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            Node *temp = q.front();
            cout << temp->data << " ";
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    cout << endl;
}
// root-to-node path traversal
bool getPath(Node *root, int x, vector<int> &arr)
{
    if (root == NULL)
        return false;
    arr.push_back(root->data);
    if (root->data == x)
        return true;
    if (getPath(root->left, x, arr) or getPath(root->right, x, arr))
        return true;
    arr.pop_back();
    return false;
}
void path(Node *root, Node *n)
{
    if (root == NULL)
        return;
    vector<int> arr;
    getPath(root, n->data, arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}
// all root-to-leaf paths

int main()
{
    return 0;
}

// All standard binary-tree traversal problems 👇
// https://www.geeksforgeeks.org/maximum-distinct-nodes-in-a-root-to-leaf-path/?ref=lbp
