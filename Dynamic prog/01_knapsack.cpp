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

// O1 knapsack iterative bottom up
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, W;
    cin >> n >> W;
    int w[n], p[n];
    int dp[n + 1][W + 1];
    for (int i = 0; i < n; i++)
        cin >> w[i] >> p[i];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (w[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    // maximum profit obtained
    cout << dp[n][W] << endl;
    // printing the knapsack items
    int i = n, j = W;
    while (i >= 1)
    {
        while (j >= 1)
        {
            if (dp[i][j] == dp[i - 1][j])
                i--;
            else
            {
                cout << "Item" << i << " + ";
                i--;
                j -= w[i];
            }
        }
    }
    return 0;
}