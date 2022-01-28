#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int hsh[N];
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        hsh[v[i]]++;
    }
    vector<int> m(N);
    m[1] = n;
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            m[i] += hsh[j];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int p, q;
        long long ans = 0;
        cin >> p >> q;
        long long lcm = (p * 1LL * q) / __gcd(p, q);
        ans = m[p] + m[q];
        if (lcm < N)
            ans -= m[lcm];
        cout << ans << endl;
    }
    return 0;
}