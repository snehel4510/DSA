#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum(vector<ll> BIT, ll i)
{
    ll s = 0;
    for (; i > 0; i -= (i & -i)) // removing the right most set bit from i
        s += BIT[i];
    return s;
}
void update(vector<ll> &BIT, ll i, ll N)
{
    for (; i <= N; i += (i & -i)) // adding rightmost set bit to i again
        BIT[i]++;
}
ll inversionCount(ll nums[], ll n)
{
    // since we are using array elements as BIT indexes, so we are mapping small values with array elements if in case any element is too large to be an index of BIT array
    map<ll, ll> m;
    ll c = 0, k = 1;
    for (ll i = 0; i < n; i++)
        m[nums[i]];
    for (auto &it : m)
        it.second = k++;
    ll N = m[*max_element(nums, nums + n)];
    vector<ll> BIT(N + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        c += sum(BIT, N) - sum(BIT, m[nums[i]]);
        update(BIT, m[nums[i]], N);
    }
    return c;
}

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    // using the concept of BITs to count inversions
    cout << inversionCount(a, n) << endl;
    return 0;
}