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