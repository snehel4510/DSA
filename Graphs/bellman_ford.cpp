// bellman ford algorithm to find the shortest path from source to destination
// works even for graphs containing negative weight edges(but not cycles)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v, e, src;
    cin >> v >> e >> src;
    // instead of using adjacency list we are taking all edges at once
    vector<vector<int>> edges(1);
    int x = e;
    bool flag = true;
    while (x--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // ensuring that the first edge should be the edge containg the source vertex
        if (u == src and flag)
        {
            edges[0] = {u, v, w};
            flag = false;
        }
        else
            edges.push_back({u, v, w});
    }
    vector<int> dis(v, INT_MAX);
    dis[src] = 0;
    // looping through all the edges |V-1| times
    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0]; // source vertex
            int v = edges[j][1]; // destination vertex
            int w = edges[j][2]; // weight of the edge
            // relaxing the edge
            if (dis[u] != INT_MAX && dis[v] > dis[u] + w)
                dis[v] = dis[u] + w;
        }
    }
    // to check if a graph contains any negative weight cycle(NWC) or not
    flag = false;
    // looping through all the edges once more to check if an edge can still be relaxed, if yes, then NWC exists
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (dis[u] != INT_MAX && dis[v] > dis[u] + w)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "Graph contains negative weight cycle" << endl;
        return 0;
    }
    // shortest distance of all vertices from the source vertex
    for (int i = 0; i < v; i++)
        cout << i << " : " << dis[i] << " " << endl;
    return 0;
}

// TC -> O(VE)