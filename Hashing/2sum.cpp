// to find wheteher 2 indexes of an unsorted array sum to a specific number without 2pointers
// this hashing approach reduces the TC from O(nlogn)->due to sorting the array to O(n)
#include <bits/stdc++.h>
using namespace std;
bool tsum(int arr[], int n, int x)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(x - arr[i]) != s.end())
        {
            return true;
        }

        s.insert(arr[i]);
    }

    return false;
}
// finding the indexes of both the elements
vector<int> twoSum(vector<int> &v, int t)
{
    vector<int> nums(v.begin(), v.end());
    vector<int> ans = {};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        int l = i + 1, h = nums.size() - 1;
        while (l < h)
        {
            int m = (l + h) / 2;
            if (nums[m] < (t - nums[i]))
                l = m + 1;
            else
                h = m;
        }
        if (nums[l] + nums[i] == t)
        {
            ans.push_back(i);
            ans.push_back(l);
            break;
        }
        if (nums[h] + nums[i] == t)
        {
            ans.push_back(i);
            ans.push_back(h);
            break;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == ans[0])
        {
            ans[0] = i;
            v[i] = INT_MIN;
            break;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == ans[1])
        {
            ans[1] = i;
            break;
        }
    }
    return ans;
}
int main()
{
    int n = 8, x = 12;
    int arr[8] = {2, 4, 1, 7, 5, 9, 7, 3};
    if (tsum(arr, n, x))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
