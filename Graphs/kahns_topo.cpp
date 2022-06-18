// cycle detection in directed graphs using BFS
// using kahn's algorithm for topological sort which works only on DAGs
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> g[N];
int main()
{
    int v, e, c = 0;
    cin >> v >> e;
    while (e--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
    }
    vector<int> I(v, 0), topo;
    for (int i = 0; i < v; i++)
    {
        for (auto j : g[i])
            I[j]++;
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (I[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        c++;
        topo.push_back(u);
        for (auto v : g[u])
        {
            I[v]--;
            if (I[v] == 0)
                q.push(v);
        }
    }
    // since count of elements in the topo sort isn't equal to the total no of vertices in the graph, hence it contains a cycle where we can't find the topo sort
    if (c != v)
        cout << "Not a DAG, Cycle detected" << endl;
    return 0;
}