// longest palindromic approach follows the similar approach as of LCS, the only difference here is that the 2nd string will be the reverse of the first string
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
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    string s1 = s;
    reverse(s.begin(), s.end());
    int n = s.size() - 1;
    cout << LCS(s, s1, n, n);
    return 0;
}