// Find all valid combinations of k numbers that sum up to n such that the following conditions are true :- Only numbers 1 through 9 are used and Each number is used at most once.

#include <bits/stdc++.h>
using namespace std;
void helper(vector<vector<int>> &ans, vector<int> &v, int k, int n, int sum, int i)
{
    if (k == 0)
    {
        if (sum == n)
        {
            ans.push_back(v);
            return;
        }
        else
            return;
    }

    if (i > 9)
        return;

    v.push_back(i);
    helper(ans, v, k - 1, n, sum + i, i + 1);
    v.pop_back();
    helper(ans, v, k, n, sum, i + 1);
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    if ((k * (k + 1)) / 2 > n)
        return {};
    vector<int> v;
    int sum = 0, i = 1;
    helper(ans, v, k, n, sum, i);
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans = combinationSum3(k, n);
    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}