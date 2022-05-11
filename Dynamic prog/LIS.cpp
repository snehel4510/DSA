// longest increasing subsequence
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int dp[N];
int lis(int i)
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[j] < a[i])
            ans = max(ans, lis(j) + 1);
    }
    return dp[i] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, lis(i));
    cout << ans << endl;
    return 0;
}