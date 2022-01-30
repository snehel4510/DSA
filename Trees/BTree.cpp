// Representation of binary trees using LL
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
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    return 0;
}

// Representation of binary trees using arrays
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char nodes[5] = {'A', 'B', 'C', 'D', 'E'};
    int left[5] = {1, 3, -1, -1, -1};
    int right[5] = {2, 4, -1, -1, -1};
    cout << "Node\tLeft child\tRight child :- " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << nodes[i] << "\t";
        if (left[i] != -1)
            cout << nodes[left[i]] << "\t\t";
        if (right[i] != -1)
            cout << nodes[right[i]];
        cout << endl;
    }
    return 0;
}
