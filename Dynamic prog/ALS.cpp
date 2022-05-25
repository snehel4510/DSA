// assembly line scheduling problem
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < n; i++)
        cin >> v2[i];
    int e1, e2, o1, o2;
    cin >> e1 >> e2 >> o1 >> o2;
    vector<int> t1(n - 1), t2(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> t1[i];
    for (int i = 0; i < n - 1; i++)
        cin >> t2[i];
    vector<pair<int, int>> f1(n + 1), f2(n + 1);
    f1[0].first = e1 + v1[0];
    f2[0].first = e2 + v2[0];
    f1[0].second = 1;
    f2[0].second = 2;
    for (int i = 1; i < n; i++)
    {
        f1[i].first = min((f1[i - 1].first + v1[i]), (f2[i - 1].first + t2[i - 1] + v1[i]));
        (f1[i].first == f1[i - 1].first + v1[i]) ? f1[i].second = 1 : f1[i].second = 2;
        f2[i].first = min((f2[i - 1].first + v2[i]), (f1[i - 1].first + t1[i - 1] + v2[i]));
        (f2[i].first == f2[i - 1].first + v2[i]) ? f2[i].second = 2 : f2[i].second = 1;
    }
    f1[n].first = f1[n - 1].first + o1;
    f2[n].first = f2[n - 1].first + o2;
    f1[n].second = 1;
    f2[n].second = 2;
    int ans = min(f1.back().first, f2.back().first);
    cout << ans << endl;
    int x;
    (ans == f1.back().first) ? x = 1 : x = 2;
    vector<int> path;
    for (int i = n; i > 0; i--)
    {
        if (x == 1)
        {
            path.push_back(f1[i].second);
            x = f1[i].second;
        }
        else
        {
            path.push_back(f2[i].second);
            x = f2[i].second;
        }
    }
    reverse(path.begin(), path.end());
    for (auto i : path)
        cout << i << " ";
    cout << endl;
    return 0;
}