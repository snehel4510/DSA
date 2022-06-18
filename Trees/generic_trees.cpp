// generic trees (irrespetive of their no of childs)
// will be represented using adjacency list -> like graphs(with no loops and only 1 connected comps)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
// tree structre
vector<int> t[N];
// arrays to store depth and height of each vertex
int d[N], h[N], par[N];
// DFS in a tree
void dfs(int v, int p = 0)
{
    par[v] = p;
    for (auto c : t[v])
    {
        if (c == p)
            continue;
        // depth of a vertex = depth of it's parent + 1
        d[c] = d[v] + 1;
        dfs(c, v);
        // height of a vertex = max(height of it's all children)
        h[v] = max(h[v], h[c] + 1);
    }
}
// lowest common ancestor(LCA) of any 2 given nodes in a generic tree
void LCA(int v, int u)
{
    vector<int> vp, up;
    while (v)
    {
        vp.push_back(v);
        v = par[v];
    }
    while (u)
    {
        up.push_back(u);
        u = par[u];
    }
    reverse(vp.begin(), vp.end());
    reverse(up.begin(), up.end());
    int lca = -1, i = 0, j = 0;
    while (i < vp.size() && j < up.size())
    {
        if (vp[i] == up[j])
        {
            lca = vp[i];
            i++;
            j++;
        }
        else
            break;
    }
    if (lca == -1)
        (par[v] == u) ? lca = u : lca = v;
    cout << lca << endl;
}
int main()
{
    // n vertices of a tree
    int n;
    cin >> n;
    // n-1 edges in a tree
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    // calling DFS on root node = 1
    dfs(1);
    // print depth and height of each vertex
    for (int i = 1; i <= n; i++)
        cout << i << " : "
             << "depth-> " << d[i] << " height-> " << h[i] << endl;
    LCA(6, 12);
    LCA(8, 10);
    LCA(5, 13);
    LCA(4, 3);
    return 0;
}