// topological sorting works only in DAGs
// find a permutation of the vertices (topological order) such that every edge leads from the vertex with a smaller number assigned to the vertex with a larger one.
// it is not unique
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];
bool vis[N];
stack<int> s;
void dfs(int v)
{
    vis[v] = true;
    for (auto u : g[v])
    {
        if (!vis[u])
            dfs(u);
    }
    s.push(v);
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
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    cout << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}