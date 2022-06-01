// bellman ford algorithm to find the Negative weight cycle in a graph if it exists
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v, e, src;
    cin >> v >> e >> src;
    vector<vector<int>> edges(1);
    int x = e;
    bool flag = true;
    while (x--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == src and flag)
        {
            edges[0] = {u, v, w};
            flag = false;
        }
        else
            edges.push_back({u, v, w});
    }
    vector<int> dis(v, INT_MAX);
    // parent array to store the parent of each vertex
    vector<int> p(v);
    dis[src] = 0;
    int y;
    for (int i = 0; i < v; i++)
    {
        y = -1;
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dis[u] != INT_MAX && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                p[v] = u;
                y = v;
            }
        }
    }
    // if y's value is not updated in the last loop
    if (y == -1)
        cout << "no NWC detected" << endl;
    else
    {
        // since y!=-1 means y is a vertex that is a part of the negative weight cycle
        cout << "NWC detected" << endl;
        cout << "NWC is : ";
        vector<int> cycle;
        // looping through each parent of y since thay are a part of the negative weight cycle
        for (int i = y;; i = p[i])
        {
            if (i == y and cycle.size() > 1)
                break;
            cycle.push_back(i);
        }
        reverse(cycle.begin(), cycle.end());
        for (auto i : cycle)
            cout << i << " ";
    }
    return 0;
}

// TC -> O(VE)