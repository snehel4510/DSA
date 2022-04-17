#include <bits/stdc++.h>
using namespace std;
bool helper(vector<int> &piles, int k, int h)
{
    int c = 0;
    for (auto i : piles)
    {
        if (k >= i)
            c++;
        else
        {
            if (i % k == 0)
                c += (i / k);
            else
                c += (i / k) + 1;
        }
    }
    return c <= h;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int lo = 1, hi = *max_element(piles.begin(), piles.end());
    while (hi - lo > 1)
    {
        int k = (lo + hi) / 2;
        if (helper(piles, k, h))
            hi = k;
        else
            lo = k + 1;
    }
    if (helper(piles, lo, h))
        return lo;
    return hi;
}
int main()
{
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
        cin >> piles[i];
    cout << minEatingSpeed(piles, h);
    return 0;
}