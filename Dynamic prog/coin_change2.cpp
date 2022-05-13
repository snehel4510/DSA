#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 310;
int dp[M][N];
int count(vector<int> &coins, int amt, int ind)
{
    if (amt == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (dp[ind][amt] != -1)
        return dp[ind][amt];
    int ans = 0;
    for (int i = 0; i <= amt; i += coins[ind])
    {
        ans += count(coins, amt - i, ind - 1);
    }
    return dp[ind][amt] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, amt;
    cin >> n >> amt;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int ans = count(coins, amt, coins.size() - 1);
    cout << ans << endl;
    return 0;
}