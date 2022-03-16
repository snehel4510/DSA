// generating subsets using bit masking

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // given an array of size n, find all subsets of that array
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int n1 = (1 << n);
    vector<vector<int>> ans;
    for (int i = 0; i < n1; i++)
    {
        vector<int> v1;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                v1.push_back(v[j]);
        }
        ans.push_back(v1);
    }
    int num = 0;
    for (auto i : ans)
    {
        cout << num << ")";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
        num++;
    }
    return 0;
}