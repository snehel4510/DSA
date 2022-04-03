// returning the top K frequent element from an array
#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    for (auto i : nums)
        m[i]++;
    vector<int> ans;
    unordered_map<int, vector<int>> f;
    for (auto i : m)
    {
        f[i.second].push_back(i.first);
    }
    int x = 0;
    for (int i = 1e5; i >= 1; i--)
    {
        if (f.find(i) != f.end())
        {
            for (auto j : f[i])
            {
                ans.push_back(j);
                x++;
            }
        }
        if (x == k)
            break;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;
    vector<int> ans = topKFrequent(v, k);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}