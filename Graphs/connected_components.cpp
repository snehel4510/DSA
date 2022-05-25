// to find the count of total connected components in a graph(forest)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];
bool vis[N];

// to store each connect components seperately
vector<vector<int>> cc;
vector<int> c;

void dfs(int v)
{
    vis[v] = true;
    c.push_back(v);
    for (auto u : g[v])
    {
        if (!vis[u])
            dfs(u);
    }
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
    for (int i = 1; i <= v; i++)
    {
        // if a vertex is already visited before then it is already a part of some other connected component so it won't count in the cc since we will not call dfs on this vertex again
        if (vis[i])
            continue;
        c.clear();
        dfs(i);
        cc.push_back(c);
    }
    cout << cc.size() << endl;
    for (auto i : cc)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}