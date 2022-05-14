#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int dp[N];
int val(int l, int price[], int n)
{
    if (l == 0)
        return 0;
    if (dp[l] != -1)
        return dp[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (l - i >= 0)
            ans = max(ans, price[i - 1] + val(l - i, price, n));
    }
    return dp[l] = ans;
}
int cutRod(int price[], int n)
{
    return val(n, price, n);
}
int main()
{
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    cout << cutRod(price, n) << endl;
    return 0;
}