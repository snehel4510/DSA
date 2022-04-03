// works only on monotonic functions (ex - sorted arrays)

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{10, 6, 5, 8};
    int n;
    cin >> n;
    // int hi = v.size() - 1, lo = 0;
    // while (hi - lo > 1)
    // {
    //     int mid = (lo + hi) / 2;
    //     if (v[mid] < n)
    //     {
    //         lo = mid + 1;
    //     }
    //     else
    //     {
    //         hi = mid;
    //     }
    // }
    // if (v[lo] == n)
    //     cout << lo << endl;
    // else if (v[hi] == n)
    //     cout << hi << endl;
    // else
    //     cout << "Element not found in the array" << endl;
    cout << binary_search(v.begin(), v.end(), n);
    return 0;
}