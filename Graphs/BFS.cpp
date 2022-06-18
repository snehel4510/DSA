#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];
int level[N];
bool vis[N];
void BFS(int v)
{
    queue<int> q;
    // visit and push the root node to the queue
    q.push(v);
    vis[v] = true;
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (auto i : g[u])
        {
            // push each child node i of parent u (which is not visited) and mark them visited
            if (!vis[i])
            {
                vis[i] = true;
                q.push(i);
                // level of child = level of parent + 1
                level[i] = level[u] + 1;
            }
        }
    }
    cout << endl;
}
int main()
{
    // v vertices and e edges
    int v, e;
    cin >> v >> e;
    // graph input
    while (e--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    // calling BFS function with root node = 1
    BFS(1);

    // print level of each node
    for (int i = 1; i <= v; i++)
        cout << i << " : " << level[i] << endl;

    // printing each node level wise
    int n = *max_element(level + 1, level + v + 1);
    vector<vector<int>> ans;
    for (int i = 0; i <= n; i++)
    {
        vector<int> t;
        for (int j = 1; j <= v; j++)
        {
            if (level[j] == i)
                t.push_back(j);
        }
        ans.push_back(t);
    }
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// APPLICATIONS OF BFS