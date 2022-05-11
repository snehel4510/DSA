#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];
int cost_op(vector<int> &a, int i, int k)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int c = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
            c = min(c, cost_op(a, i - j, k) + abs(a[i - j] - a[i]));
    }
    return dp[i] = c;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << cost_op(a, n - 1, k) << endl;
    return 0;
}