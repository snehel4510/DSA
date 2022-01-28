#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 1e6 + 1;
    vector<bool> v(n, 1);
    v[0] = v[1] = 0;
    // 0 -> composite & 1 -> prime
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            for (int j = i * i; j <= n; j += i)
                v[j] = 0;
        }
    }

    int n1;
    cin >> n1;
    if (v[n1])
        cout << "Prime";
    else
        cout << "composite";

    // to find kth prime number
    // int k, k1 = 0;
    // cin >> k;
    // for (int i = 0; i < n; i++)
    // {
    //     if (v[i])
    //         k1++;
    //     if (k1 == k)
    //     {
    //         cout << i;
    //         break;
    //     }
    // }
    return 0;
}