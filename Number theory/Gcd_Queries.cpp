#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> v(n + 1);
        v[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        vector<int> fg(n + 1), bg(n + 2);
        fg[0] = 0;
        bg[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            fg[i] = __gcd(fg[i - 1], v[i]);
        }
        for (int i = n; i >= 0; i--)
        {
            bg[i] = __gcd(bg[i + 1], v[i]);
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << __gcd(fg[l - 1], bg[r + 1]) << endl;
        }
    }
    return 0;
}