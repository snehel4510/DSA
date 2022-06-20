// strongly connected components are the connected components of a directed graph in which all the vertices are reachable from each other.
// works on the same concept as of bridges and articulation points
// here, nodes with same low value are in the same strongly connected component
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];        // graph adjacency list
vector<int> scc[N];      // strongly connected components
vector<int> in(N, 1e6);  // in time of each node
vector<int> low(N, 1e6); // child node with the lowest in-time
bool vis[N];
int s = 0;
void dfs(int v)
{
    vis[v] = true;
    in[v] = s++;
    for (auto u : g[v])
    {
        if (vis[u])
            low[v] = min(low[v], in[u]);
        else
        {
            dfs(u);
            low[v] = min(low[v], low[u]);
        }
    }
    scc[low[v]].push_back(v);
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
    }
    for (int i = 0; i < v; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
    }
    for (int i = 0; i < v; i++)
    {
        for (auto j : scc[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}