// to find intersection of 2 arrays
#include <bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> s1;
    unordered_set<int> s2;
    for (auto i : nums1)
    {
        s1.insert(i);
    }
    for (auto i : nums2)
    {
        s2.insert(i);
    }
    vector<int> ans;
    for (auto i : s1)
    {
        if (s2.find(i) != s2.end())
            ans.push_back(i);
    }
    return ans;
}
int main()
{

    return 0;
}