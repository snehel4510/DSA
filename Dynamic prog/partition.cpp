#include <bits/stdc++.h>
using namespace std;
int dp[210][20005];
bool subset(vector<int> &p, int ind, int sum)
{
    if (sum == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    bool s = subset(p, ind - 1, sum);
    if (sum - p[ind] >= 0)
        s = s or subset(p, ind - 1, sum - p[ind]);
    return dp[ind][sum] = s;
}
bool canPartition(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
        return false;
    sum /= 2;
    return subset(nums, nums.size() - 1, sum);
}
int main()
{
    int n;
    cin >> n;
    vector<int> part(n);
    for (int i = 0; i < n; i++)
        cin >> part[i];
    cout << canPartition(part) << endl;
    return 0;
}