#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];
long long min_coins(vector<int> &coins, int amt)
{
    long long ans = INT_MAX;
    if (amt == 0)
        return 0;
    if (dp[amt] != -1)
        return dp[amt];
    for (auto i : coins)
    {
        if (amt - i >= 0)
            ans = min(ans, min_coins(coins, amt - i) + 1);
    }
    return dp[amt] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, amt;
    cin >> n >> amt;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int ans = min_coins(coins, amt);
    (ans == INT_MAX) ? cout << -1 << endl : cout << ans << endl;
    return 0;
}