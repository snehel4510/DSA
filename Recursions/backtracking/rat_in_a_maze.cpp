#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(vector<string> &ans, string s, vector<vector<int>> &a, int n, int i, int j)
    {
        if (i == n - 1 and j == n - 1)
        {
            ans.push_back(s);
            return;
        }
        // DLRU is in lexographical order
        // downward
        if (i + 1 < n and a[i + 1][j] == 1)
        {
            a[i][j] = 0;
            helper(ans, s + "D", a, n, i + 1, j);
            a[i][j] = 1;
        }

        // left
        if (j - 1 >= 0 and a[i][j - 1] == 1)
        {
            a[i][j] = 0;
            helper(ans, s + "L", a, n, i, j - 1);
            a[i][j] = 1;
        }

        // right
        if (j + 1 < n and a[i][j + 1] == 1)
        {
            a[i][j] = 0;
            helper(ans, s + "R", a, n, i, j + 1);
            a[i][j] = 1;
        }

        // upward
        if (i - 1 >= 0 and a[i - 1][j] == 1)
        {
            a[i][j] = 0;
            helper(ans, s + "U", a, n, i - 1, j);
            a[i][j] = 1;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        string s = "";
        if (m[0][0] == 1)
            helper(ans, s, m, n, 0, 0);
        return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}