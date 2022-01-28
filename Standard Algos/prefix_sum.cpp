// does not work for negative numbers in the array

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> pf;
    pf.push_back(0);
    for (int i = 0; i < v.size(); i++)
    {
        pf.push_back(pf[i] + v[i]);
    }
    int l = 2, r = 6;
    int a = pf[l];   // sum of first l elements in v
    int b = pf[r];   // sum of first r elements in v
    int sum = b - a; // sum of elements from of (l+1) to r in the vector v
    cout << sum;
    return 0;
}