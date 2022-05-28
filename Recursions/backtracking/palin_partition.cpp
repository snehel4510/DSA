#include <bits/stdc++.h>
using namespace std;
bool palin(string s1, int s, int e)
{
    while (s <= e)
    {
        if (s1[s] != s1[e])
            return false;
        s++;
        e--;
    }
    return true;
}
void helper(vector<vector<string>> &ans, vector<string> &v, string &s, int ind)
{
    if (ind == s.length())
    {
        ans.push_back(v);
        return;
    }
    for (int i = ind; i < s.length(); i++)
    {
        if (palin(s, ind, i))
        {
            v.push_back(s.substr(ind, i - ind + 1));
            helper(ans, v, s, i + 1);
            v.pop_back();
        }
    }
}
int main()
{
    string s;
    cin >> s;
    vector<vector<string>> ans;
    vector<string> v;
    helper(ans, v, s, 0);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}