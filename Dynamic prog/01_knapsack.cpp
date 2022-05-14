// 1st APPROACH
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 15;
int w[110], p[110], dp[110][N];
// in this approach, we are having weight and index of items as our DP states and are calculating how much value we are getting for each state
int profit(int wt, int ind)
{
    // if we have no items to or no weight pick, we return value = 0
    if (wt == 0 or ind < 0)
        return 0;
    if (dp[ind][wt] != -1)
        return dp[ind][wt];
    int ans = profit(wt, ind - 1);
    if (wt - w[ind] >= 0)
        ans = max(ans, profit(wt - w[ind], ind - 1) + p[ind]);
    return dp[ind][wt] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> p[i];
    cout << profit(W, n - 1) << endl;
    return 0;
}

// 2nd APPROACH
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int w[110], p[110], dp[110][N];
// but if somehow the constraints for the problem are changed, we can't use the above approach.
// in the 2nd approach we will be having index of item and value as our DP states and are calculating how much weight we can get for each state
int weight(int ind, int val)
{
    // if we have to pick items worth 0 value, then we will not pick any item or 0 weight
    if (val == 0)
        return 0;
    // if we have some value left to pick up but no items to pick, so we will return an undefined amount of weight
    if (ind < 0)
        return 1e9;
    if (dp[ind][val] != -1)
        return dp[ind][val];
    int ans = weight(ind - 1, val);
    if (val - p[ind] >= 0)
        ans = min(ans, weight(ind - 1, val - p[ind]) + w[ind]);
    return dp[ind][val] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> p[i];
    // we will choose the first weight which is <= W where the value is maximum(reverse loop from max possible value = 1e5 to 0)
    for (int i = N; i >= 0; i--)
    {
        if (weight(n - 1, i) <= W)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}