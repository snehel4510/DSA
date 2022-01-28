#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets;
void subset(vector<int> &v1, vector<int> &v, int i)
{
    if (i == v.size())
    {
        subsets.push_back(v1);
    }

    subset(v1, v, i + 1);

    v1.push_back(v[i]);
    subset(v1, v, i + 1);
    v1.pop_back();
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> v1;
    subset(v1, v, 0);
    for (auto i : subsets)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}