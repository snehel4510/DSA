#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &n, vector<int> t, set<vector<int>> &s)
{
    if (t.size() == n.size())
    {
        s.insert(t);
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] != 100)
        {
            int x = n[i];
            n[i] = 100;
            t.push_back(x);
            helper(n, t, s);
            n[i] = x;
            t.pop_back();
        }
    }
}
vector<vector<int>> permuteUnique(vector<int> &n)
{
    set<vector<int>> s;
    vector<vector<int>> ans;
    helper(n, {}, s);
    for (auto i : s)
        ans.push_back(i);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<vector<int>> ans = permuteUnique(nums);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}