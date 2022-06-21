//  a bipartite graph (or bigraph) is a graph whose vertices can be divided into two disjoint and independent sets and , that is every edge connects a vertex in to one in
// The graph is 2-colorable -> if a graph can be colored with exactly 2 colors such that no 2 adjacent vertices have the same color then it is bipartite.
// a graph is bipartite if and only if all its cycles have even length

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
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
    vector<int> color(v, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int V = 0; V < v; ++V)
    {
        if (color[V] != -1)
            continue;
        q.push(V);
        color[V] = 0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int u : g[v])
            {
                if (color[u] == -1)
                {
                    color[u] = color[v] ^ 1;
                    q.push(u);
                }
                else
                    is_bipartite &= color[u] != color[v];
            }
        }
    }
    cout << (is_bipartite ? "YES" : "NO") << endl;
    return 0;
}