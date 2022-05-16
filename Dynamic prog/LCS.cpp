#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int LCS(string &t1, string &t2, int i, int j)
{
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (j - 1 >= 0)
        ans = max(ans, LCS(t1, t2, i, j - 1));
    if (i - 1 >= 0)
        ans = max(ans, LCS(t1, t2, i - 1, j));
    if (t1[i] == t2[j])
        ans = max(ans, LCS(t1, t2, i - 1, j - 1) + 1);
    return dp[i][j] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    string t1, t2;
    cin >> t1 >> t2;
    cout << LCS(t1, t2, t1.size() - 1, t2.size() - 1) << endl;
    return 0;
}