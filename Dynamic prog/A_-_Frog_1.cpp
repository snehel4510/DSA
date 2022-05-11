#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];

// simple brute force recursive method
int cost(vector<int> &a, int i, int c)
{
    if (i == a.size() - 1)
        return c;
    if (i == a.size() - 2)
        return c + abs(a[i] - a[i + 1]);
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = min(cost(a, i + 1, c + abs(a[i + 1] - a[i])), cost(a, i + 2, c + abs(a[i + 2] - a[i])));
}

// optimized DP BOTTOM UP APPROACH
int cost_op(vector<int> &a, int i)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int c = INT_MAX;
    c = min(c, cost_op(a, i - 1) + abs(a[i - 1] - a[i]));
    if (i > 1)
        c = min(c, cost_op(a, i - 2) + abs(a[i - 2] - a[i]));
    return dp[i] = c;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << cost_op(a, n - 1) << endl;
    return 0;
}