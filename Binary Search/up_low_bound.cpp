#include <bits/stdc++.h>
using namespace std;

// Lower bound returns the index of n if its present else return index of an element just greater than n

int lower(vector<int> v, int n)
{
    int lo = 0, hi = v.size() - 1;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if (v[mid] < n)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[lo] >= n)
    {
        return lo;
    }
    else if (v[hi] >= n)
    {
        return hi;
    }
    else
        return -1;
}

// upper bound return the index of an element just greater than n

int upper(vector<int> v, int n)
{
    int lo = 0, hi = v.size() - 1;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (v[mid] <= n)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[lo] > n)
        return lo;
    else if (v[hi] > n)
        return hi;
    else
        return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int n = 10;
    int lb = lower(v, n);
    int ub = upper(v, n);
    cout << "lower bound for " << n << " is at index : " << lb << " with value : " << ((lb != -1) ? v[lb] : -1) << endl;
    cout << "upper bound for " << n << " is at index : " << ub << " with value : " << ((ub != -1) ? v[ub] : -1) << endl;
    return 0;
}