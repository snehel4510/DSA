#include <bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<int> dis(n + 1, INT_MAX);
    dis[k] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < times.size(); j++)
        {
            int u = times[j][0]; // source
            int v = times[j][1]; // destination
            int w = times[j][2]; // weight
            if (dis[u] != INT_MAX && dis[u] + w < dis[v])
                dis[v] = w + dis[u];
        }
    }
    for (auto i : dis)
        if (i == INT_MAX)
            return -1;
    return *max_element(dis.begin(), dis.end());
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> times;
    for (int i = 0; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        times.push_back({v, w, w});
    }
    cout << networkDelayTime(times, n, k);
    return 0;
}