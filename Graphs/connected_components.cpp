// to find the count of total connected components in a graph(forest)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];
bool vis[N];
void dfs(int v)
{
    vis[v] = true;
    for (auto u : g[v])
    {
        if (!vis[u])
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
        g[b].push_back(a);
    }
    int ans = 0;
    // ans is the number of times the DFS function is called
    for (int i = 1; i <= n; i++)
    {
        // if a vertex is already visited before then it is already a part of some other connected component so it won't count in the ans since we will not call dfs on this vertex again
        if (vis[i])
            continue;
        dfs(i);
        ans++;
    }
    cout << ans << endl;
    return 0;
}