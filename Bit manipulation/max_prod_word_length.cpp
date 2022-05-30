#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<string> &w)
{
    int ans = 0;
    vector<int> m(w.size(), 0);
    for (int i = 0; i < w.size(); i++)
    {
        for (auto j : w[i])
            m[i] |= 1 << (j - 'a');
    }
    for (int i = 0; i < w.size() - 1; i++)
    {
        for (int j = i + 1; j < w.size(); j++)
            if (!(m[i] & m[j]))
                ans = max(ans, int(w[i].length() * w[j].length()));
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << maxProduct(v) << endl;
    return 0;
}