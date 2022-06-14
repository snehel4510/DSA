#include <bits/stdc++.h>
using namespace std;
const int N = 505;
long long dis[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            dis[i][j] = w;
        }
    }
    int x[n], ans[n];
    for (int i = 1; i <= n; i++)
        cin >> x[i - 1];
    for (int k = 1; k <= n; k++)
    {
        long long s = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][x[n - k]] + dis[x[n - k]][j]);
            }
        }
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                s += dis[x[n - i]][x[n - j]];
            }
        }
        ans[n - k] = s;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}