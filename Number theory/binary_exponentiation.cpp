// calculating (a^b)%m using binary exponentiation in O(logn) time.
// this is a divide and conquer strategy ans modular arithmetic

#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;

// 1) RECURSIVE METHOD
long long berec(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long res = berec(a, b / 2);

    if (b % 2 == 0)
        return (res % mod * res % mod) % mod;
    return (a % mod * (res % mod * res % mod) % mod) % mod;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << berec(a, b) << endl;

    // 2) ITERATIVE METHOD
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans % mod * a % mod) % mod;
        b >>= 1;
        a = (a % mod * a % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}