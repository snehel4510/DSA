#include <bits/stdc++.h>
using namespace std;
struct bst
{
    int data;
    bst *lc;
    bst *rc;
    bst(int val)
    {
        data = val;
        lc = NULL;
        rc = NULL;
    }
};

// insertion of elements
bst* insert(bst* root, int x) {
    if(root==NULL)
    {
        root=new bst(x);
        return root;
    }    
    else if(x>root->data)
    {
        root->rc=insert(root->rc,x);
    }
    else
    {
        root->lc=insert(root->lc,x);
    }
    return root;
}

// searching the elements
bool search(bst *root, int x)
{
    if (root == NULL)
        return false;
    else if (root->data == x)
        return true;
    else if (x < root->data)
        return search(root->lc, x);
    else
        return search(root->rc, x);
}

// Tree traversals
void inorder(bst *root)
{
    if (root != NULL)
    {
        inorder(root->lc);
        cout << root->data << " ";
        inorder(root->rc);
    }
}
void preorder(bst *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->lc);
        preorder(root->rc);
    }
}
void postorder(bst *root)
{
    if (root != NULL)
    {
        postorder(root->lc);
        postorder(root->rc);
        cout << root->data << " ";
    }
}

// finding smallest value from the tree
bst *find_min(bst *root)
{
    bst *temp = root;
    while (temp->lc != NULL)
    {
        temp = temp->lc;
    }
    return temp;
}

// finding largest value from the tree
bst *find_max(bst *root)
{
    bst *temp = root;
    while (temp->rc != NULL)
    {
        temp = temp->rc;
    }
    return temp;
}

// deletion of a node from the BST
bst *del(bst *root, int x)
{
    if (root == NULL)
        return root;
    else if (x < root->data)
        root->lc = del(root->lc, x);
    else if (x > root->data)
        root->rc = del(root->rc, x);
    else
    {
        // CASE1 - 0 child
        if (root->lc == NULL & root->rc == NULL)
        {
            delete root;
            root = NULL;
        }
        // CASE2 - 1 child
        else if (root->lc == NULL)
        {
            bst *temp = root;
            root = root->rc;
            delete temp;
        }
        else if (root->rc == NULL)
        {
            bst *temp = root;
            root = root->lc;
            delete temp;
        }
        // CASE3 - 2 child
        else
        {
            bst *temp = find_min(root->rc);
            root->data = temp->data;
            root->rc = del(root->rc, temp->data);
        }
    }
    return root;
}

// finding the inorder succesor/predecessor of a node in a BST
bst *findIS(bst *root, bst *x, bst *ans)
{
    if (root == NULL)
        return ans;
    if (root->data <= x->data)
        return findIS(root->rc, x, ans);
    ans = root;
    return findIS(root->lc, x, ans);
}
bst *findIP(bst *root, bst *x, bst *ans)
{
    if (root == NULL)
        return ans;
    if (root->data >= x->data)
        return findIP(root->lc, x, ans);
    ans = root;
    return findIP(root->rc, x, ans);
}
void inorder_P_S(bst *root, bst *x, bst *&pre, bst *&suc)
{
    if (root == NULL or x == NULL)
        return;
    suc = findIS(root, x, NULL);
    pre = findIS(root, x, NULL);
}

// validating a BST
class Solution
{
public:
    vector<int> v;
    void inorder(bst *root)
    {
        if (root != NULL)
        {
            inorder(root->lc);
            v.push_back(root->data);
            inorder(root->rc);
        }
    }
    bool isValidBST(bst *root)
    {
        // if the inorder traversal of the tree is not sorted then the tree is not bst
        if (root == NULL)
            return true;
        inorder(root);
        int c = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] <= c)
                return false;
            c = v[i];
        }
        return true;
    }
};

int main()
{
    bst *root = NULL;
    return 0;
}
