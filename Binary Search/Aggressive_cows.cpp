#include <bits/stdc++.h>
using namespace std;
int n, c;
const int N = 1e5 + 10;
int v[N];

bool cows(int d)
{
    int c1 = c - 1, j = 0;
    for (int i = 1; i < n; i++)
    {
        if (c1 == 0)
            break;
        if (v[i] - v[j] >= d)
        {
            c1--;
            j = i;
        }
    }
    return (c1 == 0);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v, v + n);
        int lo = 0, hi = v[n - 1] - v[0];
        while (hi - lo > 1)
        {
            int mid = (hi + lo) / 2;
            if (cows(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        if (cows(hi))
            cout << hi << endl;
        else
            cout << lo << endl;
    }
    return 0;
}