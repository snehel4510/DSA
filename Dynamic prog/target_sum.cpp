#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void subset(vector<int> &p, int ind, int nsum, int psum, int &s)
{
    if (psum - nsum == s)
    {
        ans++;
        return;
    }
    if (ind < 0)
        return;
    subset(p, ind - 1, nsum, psum + p[ind], s);
    if (nsum - p[ind] >= 0)
        subset(p, ind - 1, nsum + p[ind], psum, s);
}
int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    subset(v, n - 1, 0, 0, s);
    cout << ans << endl;
    return 0;
}