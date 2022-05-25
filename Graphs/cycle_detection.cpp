// to check whether a graph contains a cycle or not
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> g[N];
bool vis[N];

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
            return true;
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
    bool f = false;
    for (int i = 1; i <= v; i++)
    {
        if (vis[i])
            continue;
        // parent is 0 initially since vertex 1 has no parent
        if (dfs(i, 0))
        {
            f = true;
            break;
        }
    }
    cout << f << endl;
    return 0;
}