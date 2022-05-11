#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];
int fib(int n)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1) // memoisation
        return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp)); // setting all values of array to -1
    cout << fib(n) << endl;
    return 0;
}