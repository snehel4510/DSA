#include <bits/stdc++.h>
using namespace std;
const static int N = 110;
int dp[N];
int money(vector<int> &nums, int ind)
{
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    return dp[ind] = max(nums[ind] + money(nums, ind - 2), money(nums, ind - 1));
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int ans = money(nums, nums.size() - 1);
    cout << ans << endl;
    return 0;
}