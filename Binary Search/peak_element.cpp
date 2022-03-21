// finding peak element in an array
#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &n)
{
    int l = 0, h = n.size() - 1;
    while (l < h)
    {
        int m = (l + h) / 2;
        if (n[m] > n[m + 1])
            h = m;
        else
            l = m + 1;
    }
    return l;
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
    cout << findPeakElement(v);
    return 0;
}