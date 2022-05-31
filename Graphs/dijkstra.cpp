#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
// g[x] = {y,w} -> edge from vertex x to vertex y with weight w
vector<pair<int, int>> g[N];
void dijkstra(int src, int n) // O(V+ElogV)
{
    // visited array to check if the node is visited or not, initially all false
    vector<bool> vis(N, 0);
    // distance array to store the distance of the node from the source, intially set to infinity except src
    vector<int> dist(N, INT_MAX);
    // distance of source from itself is 0
    dist[src] = 0;
    // set of {distance from src,vertex}
    set<pair<int, int>> s;
    // push the source node in the set
    s.insert({0, src});

    while (s.size() > 0)
    {
        // extracting the vertex with minimum distance from the set
        auto node = *s.begin();
        // vertex v with min distance d
        int v = node.second;
        int d = node.first;
        // erase the node from the set which is already going to be processed
        s.erase(s.begin());
        // if the node is already visited then skip it
        if (vis[v])
            continue;
        // mark the node as visited
        vis[v] = 1;
        // for each children of the node
        for (auto child : g[v])
        {
            // if the child is already visited then skip it
            if (vis[child.first])
                continue;
            // if the distance of child from the source is greater than the distance of parent v from the source + weight(parent v->child) then update the distance of the child
            if (dist[child.first] > dist[v] + child.second)
            {
                dist[child.first] = dist[v] + child.second;
                // push the child in the set
                s.insert({dist[child.first], child.first});
            }
        }
    }
    // print the distance of each node from the source
    for (int i = 1; i <= n; i++)
        cout << i << " : " << dist[i] << " " << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }
    int k;
    cin >> k;
    dijkstra(k, n);
    return 0;
}