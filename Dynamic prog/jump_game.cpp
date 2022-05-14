#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long dp[N];
long long steps(vector<int> &nums, int i)
{
    if (i >= nums.size() - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    long long ans = INT_MAX;
    for (int j = i + 1; j <= i + nums[i]; j++)
        ans = min(ans, steps(nums, j) + 1);
    return dp[i] = ans;
}
int jump(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    return steps(nums, 0);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << jump(nums) << endl;
    return 0;
}