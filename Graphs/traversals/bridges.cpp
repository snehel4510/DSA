// those edges on whose removal, the number of connected components in a graoh increases
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];
vector<int> st(N, -1);  // starting time of each node
vector<int> lst(N, -1); // smallest reaching time of each node
bool vis[N];
vector<pair<int, int>> bridges;
int s = 0;
void dfs(int v, int p = -1)
{
    vis[v] = true;
    st[v] = lst[v] = ++s;
    for (auto u : g[v])
    {
        if (u == p)
            continue;
        if (vis[u])
            lst[v] = min(lst[v], st[u]);
        else
        {
            dfs(u, v);
            lst[v] = min(lst[v], lst[u]);
            // if u can't be reached except from it's parent v then it is a bridge
            if (lst[u] > st[v])
                bridges.push_back({v, u});
        }
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
    for (int i = 0; i < v; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
    }
    cout << bridges.size() << endl;
    for (auto i : bridges)
        cout << i.first << " " << i.second << endl;
    return 0;
}