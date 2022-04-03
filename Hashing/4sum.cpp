// return no. of tuples such that a[i]+a[j]+a[k]+a[l]=0
#include <bits/stdc++.h>
using namespace std;
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    unordered_map<int, int> m;
    int ans = 0;
    for (auto i : nums1)
    {
        for (auto j : nums2)
        {
            m[i + j]++;
        }
    }
    for (auto i : nums3)
    {
        for (auto j : nums4)
        {
            if (m.find(-(i + j)) != m.end())
                ans += m[-(i + j)];
        }
    }
    return ans;
}
int main()
{

    return 0;
}