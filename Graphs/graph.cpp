// Graph representation using adjacency matrix
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int adj_mat[N][N];
int main()
{
    int n, m;
    // n vertices and m edges
    cin >> n >> m;
    // description of m edges
    while (m--)
    {
        int a, b;
        // vertex a is connected with vertex b (undirected)
        cin >> a >> b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Graph representation using adjacency list
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int Adata;
    node *next;
};
struct Hnode
{
    int data;
    Hnode *next;
    node *Alink;
};
int main()
{

    return 0;
}