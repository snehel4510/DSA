// to return all possible permutation of a given array
#include <bits/stdc++.h>
using namespace std;
void helper(int ind, vector<int> a, vector<vector<int>> &ans)
{
    if (ind == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = ind; i < a.size(); i++)
    {
        swap(a[ind], a[i]);
        helper(ind + 1, a, ans);
    }
}
vector<vector<int>> permute(vector<int> &a)
{
    vector<vector<int>> ans;
    helper(0, a, ans);
    return ans;
}
int main()
{
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> n;
    vector<vector<int>> ans = permute(a);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}