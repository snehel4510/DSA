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
    for (int i = 0; i < t1.size(); i++)
    {
        for (int j = 0; j < t2.size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // print the LCS
    string lcs;
    int i = t1.size() - 1, j = t2.size() - 1;
    while (i >= 0 and j >= 0)
    {
        if (t1[i] == t2[j])
        {
            lcs.push_back(t1[i]);
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
            j--;
        else
            i--;
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;
    return 0;
}

// lcs iterative bottom up approach
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string t1, t2;
    cin >> t1 >> t2;
    int dp[t1.length() + 1][t2.length() + 1];
    for (int i = 0; i <= t1.length(); i++)
    {
        for (int j = 0; j <= t2.length(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (t1[i - 1] == t2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    for (int i = 0; i <= t1.size(); i++)
    {
        for (int j = 0; j <= t2.size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // print the LCS
    string lcs;
    int i = t1.length(), j = t2.length();
    while (i > 0 && j > 0)
    {
        if (t1[i - 1] == t2[j - 1])
        {
            lcs.push_back(t1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;
    return 0;
}