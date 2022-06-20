// strongly connected components are the connected components of a directed graph in which all the vertices are reachable from each other.
// topological sort -> sorting all the vertices in order of their finishing time
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];
// transpose the graph -> reverse the edges
vector<int> t[N];
bool vis[N];
bool vist[N];
stack<int> s;
// to store each strongly connected components seperately
vector<vector<int>> scc;
vector<int> c;
// to store the topological order of the vertices
void topo(int v)
{
    vis[v] = true;
    for (auto u : g[v])
    {
        if (!vis[u])
            topo(u);
    }
    s.push(v);
}
void dfs(int v)
{
    vist[v] = true;
    c.push_back(v);
    for (auto u : t[v])
    {
        if (!vist[u])
            dfs(u);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        t[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            topo(i);
    }
    while (!s.empty())
    {
        int i = s.top();
        s.pop();
        if (vist[i])
            continue;
        c.clear();
        dfs(i);
        scc.push_back(c);
    }
    cout << scc.size() << endl;
    for (auto i : scc)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}