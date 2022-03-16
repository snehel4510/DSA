// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;
// vector<ll> v;
// ll upper(vector<ll> v, ll n)
// {
//     ll lo = 0, hi = v.size() - 1;
//     while (hi - lo > 1)
//     {
//         ll mid = (hi + lo) / 2;
//         if (v[mid] <= n)
//         {
//             lo = mid + 1;
//         }
//         else
//         {
//             hi = mid;
//         }
//     }
//     if (v[lo] > n)
//         return lo;
//     else if (v[hi] > n)
//         return hi;
//     else
//         return -1;
// }

// int main()
// {
//     ll n, m;
//     cin >> n >> m;
//     for (ll i = 0; i < n; i++)
//     {
//         int b;
//         cin >> b;
//         v.push_back(b);
//     }
//     sort(v.begin(), v.end());
//     ll h = v[n - 1], w = 0, ans;
//     for (ll i = h; i >= 0; i--)
//     {
//         ll a = upper(v, i);
//         if (a != -1)
//             w += (n - a);
//         if (w >= m)
//         {
//             ans = i;
//             break;
//         }
//     }
//     cout << ans;
//     return 0;
// }

//Getting TLE in this approach

//-----------------------------------------------------------------------------------------------------------------------------//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, m;
vector<ll> v;
bool wood(ll h)
{
    ll w = 0;
    for (auto i : v)
    {
        if (i > h)
            w += (i - h);
    }
    return (w >= m);
}

int main()
{
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    ll lo = 0, hi = 1e9, mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (wood(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (wood(hi))
        cout << hi;
    else
        cout << lo;
    return 0;
}