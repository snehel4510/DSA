// articulation points in a graph -> vertices whose removal disconnects the graph
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];
vector<int> st(N, -1);  // starting time of each node
vector<int> lst(N, -1); // smallest reaching time of each node
bool vis[N];
vector<int> ap;
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
            // if any child can't reach it's parent or any other node before it's parent then it is an articulation point
            // this condition is not applicable to root node
            if (lst[u] >= st[v] and p != -1)
                ap.push_back(v);
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
    for (int i = 1; i <= v; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
    }
    cout << ap.size() << endl;
    for (auto i : ap)
        cout << i << endl;
    return 0;
}