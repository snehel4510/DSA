// modular multiplicative inverse (MMI)
// (a/b)%m = (a%m * b^-1%m)%m

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

// binary exponentiation function
ll be(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans % mod * a % mod) % mod;
        b >>= 1;
        a = (a % mod * a % mod) % mod;
    }
    return ans;
}

int main()
{
    ll a;
    cin >> a;
    // calculating MMI (a^-1) of a
    cout << be(a, mod - 2) << endl;

    // aplications of MMI --> find nCr % mod for Q queries
    // (n!/(n-r)! * r!)%mod  --> (n!%mod * ((n-r)!*r!)^-1 %mod)%mod

    ll N = 1e5 + 10;
    ll fact[N];
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (i * fact[i - 1] * 1LL) % mod;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll n, r;
        cin >> n >> r;
        ll num = fact[n];
        ll den = (fact[n - r] * fact[r] * 1LL) % mod;
        ll ans = (num % mod * be(den, mod - 2) % mod) % mod;
        cout << ans << endl;
    }

    return 0;
}
