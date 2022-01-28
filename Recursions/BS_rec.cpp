// implementing Binary search recursively

#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int BS(int lo, int hi, int n)
{
    if (hi - lo <= 1)
    {
        if (v[lo] == n)
            return lo;
        else if (v[hi] == n)
            return hi;
        else
            return -1;
    }
    int mid = (lo + hi) / 2;
    if (v[mid] < n)
        return BS(mid + 1, hi, n);
    else
        return BS(lo, mid, n);
}
int main()
{
    v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n;
    cin >> n;
    int ind = BS(0, v.size() - 1, n);
    cout << ind << endl;
    return 0;
}