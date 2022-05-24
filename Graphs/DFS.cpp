#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];
bool vis[N];
void dfs(int v) // TC : O(V+E)
{
    cout << "visit : " << v << endl;
    // take action on the vertex v after entering v
    vis[v] = true;
    for (auto u : g[v])
    {
        cout << "par : " << v << "child : " << u << endl;
        // take action on the child u before entering u
        if (!vis[u])
            dfs(u);
        // take action on the child u after leaving u
    }
    // take action on the vertex v before leaving v
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
    dfs(1);
    return 0;
}