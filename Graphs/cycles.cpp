// to check whether an undirected graph contains a cycle or not using DFS
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];
vector<int> par(N, -1);
bool vis[N];
int cs, ce;
bool dfs(int v, int p)
{
    // p stores the parent of vertex v
    vis[v] = true;
    bool loop = false;
    for (auto u : g[v])
    {
        // if u is visited and coming from it's parent then continue
        if (vis[u] and u == p)
            continue;
        // else if u is visited but isn't coming from it's parent then there's a loop
        if (vis[u])
        {
            cs = u;
            ce = v;
            return true;
        }
        par[u] = v;
        // ORing the answer since if there's even a single loop for a vertex v then we have detected a loop in the graph
        loop |= dfs(u, v);
    }
    return loop;
}
int main()
{
    int v, e;
    cin >> v >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cs = -1;
    for (int i = 0; i < v; i++)
    {
        if (vis[i])
            continue;
        // parent is 0 initially since vertex 1 has no parent
        if (dfs(i, 0))
            break;
    }
    for (int i = 0; i < v; i++)
        cout << par[i] << " ";
    cout << endl;
    if (cs == -1)
        cout << "No cycle";
    else
    {
        cout << "Cycle detected from " << cs << " to " << ce << endl;
        cout << "Path : ";
        int v = cs;
        while (v != ce)
        {
            cout << v << " ";
            v = par[v];
        }
        cout << v << endl;
    }
    return 0;
}