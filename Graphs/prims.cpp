// prim's algorithm to find minimum spanning tree -> TC : O(V^2)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<pair<int, int>> g[N];
int main()
{
    int v, e;
    cin >> v >> e;
    int m = e, n = v;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    // parent and weight arrray for every vertex
    vector<int> parent(n + 1), key(n + 1, INT_MAX);
    // to check if a particular vertex is already present in our MST or not
    vector<bool> inMST(n + 1, false);
    // parent of root = -1 and weight of root to it's non-existent parent = 0
    key[1] = 0;
    parent[1] = -1;
    for (int i = 1; i <= n - 1; i++)
    {
        int u = -1, min = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            if (!inMST[j] && key[j] < min)
            {
                min = key[j];
                u = j;
            }
        }
        inMST[u] = true;
        for (auto p : g[u])
        {
            int v = p.first;
            int w = p.second;
            if (!inMST[v] && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    int cost = 0;
    // print the MST
    cout << "MST : " << endl;
    cout << "parent vertex weight" << endl;
    for (int i = 1; i <= n; i++)
    {
        cost += key[i];
        cout << parent[i] << "\t" << i << "\t" << key[i] << endl;
    }
    cout << "cost : " << cost << endl;
    return 0;
}