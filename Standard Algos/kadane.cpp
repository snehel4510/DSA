// kadane's algo is widely used to find the contiguous subarray with the largest sum.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int ans = INT_MIN, s = 0;
    for (auto i : nums)
    {
        s += i;
        ans = max(ans, s);
        if (s < 0)
            s = 0;
    }
    cout << ans;
    return 0;
}

// another implementation similar to kadane's to find maximum product subarray
#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{
    int maxP = 1, minP = 1, ans = *max_element(nums.begin(), nums.end());
    for (auto i : nums)
    {
        if (i == 0)
        {
            maxP = 1;
            minP = 1;
            continue;
        }
        int t1 = maxP, t2 = minP;
        maxP = max(t1 * i, t2 * i);
        maxP = max(i, maxP);
        minP = min(t1 * i, t2 * i);
        minP = min(i, minP);
        ans = max(ans, maxP);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << maxProduct(nums);
    return 0;
}