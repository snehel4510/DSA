// all pairs shortest path -> O(V^3)
// uses DP same as bellman and can handle negative weights but not negative weight cycles
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e3 + 10;
int dis[N][N];
int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INF;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] != INF and dis[k][j] != INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "From vertex " << i << " :- " << endl;
        for (int j = 1; j <= n; j++)
        {
            cout << " to " << j << " : ";
            if (dis[i][j] == INF)
                cout << "I ";
            else
                cout << dis[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}