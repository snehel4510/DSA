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

void insert(bst **root, int x)
{
    if (*root == NULL)
    {
        *root = new bst(x);
    }
    else if (x < (*root)->data)
    {
        insert(&((*root)->lc), x);
    }
    else if (x > (*root)->data)
    {
        insert(&((*root)->rc), x);
    }
}

// searching the elements elements

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

int main()
{
    bst *root = NULL;
    insert(&root, 15);
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 25);
    insert(&root, 8);
    insert(&root, 12);
    // cout << search(root, 25) << endl;
    // cout << search(root, 17) << endl;
    // cout << search(root, 15) << endl;
    inorder(root);
    cout << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    del(root, 15);
    inorder(root);
    cout << endl;
    return 0;
}