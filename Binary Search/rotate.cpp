#include <bits/stdc++.h>
using namespace std;

// binary search algo
int BS(vector<int> arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return BS(arr, l, mid - 1, x);
        return BS(arr, mid + 1, r, x);
    }
    return -1;
}

// searching in a rotated sorted array
int Search(vector<int> v, int k)
{
    int n = v.size() - 1;
    if (v[0] < v[n])
        return BS(v, 0, n, k);
    int l = 0, r = n;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (v[m] > v[0])
            l = m + 1;
        else
            r = m;
    }
    int ans1 = BS(v, 0, l - 1, k);
    int ans2 = BS(v, l, n, k);
    return max(ans1, ans2);
}

// finding minimum value in a rotated sorted array
int findMin(vector<int> &v)
{
    if (v.size() == 1)
        return v[0];
    vector<int> n;
    n.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i - 1])
            n.push_back(v[i]);
    }
    int l = 0, h = n.size() - 1;
    if (n[l] < n[h])
        return n[l];
    while (h - l > 1)
    {
        int m = (l + h) / 2;
        if (n[m] < n[0])
            h = m;
        else
            l = m;
    }
    if (n[h] < n[l])
        return n[h];
    return n[l];
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << findMin(v);
    return 0;
}