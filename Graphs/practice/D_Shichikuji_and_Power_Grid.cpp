#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int parent[N];
int sz[N];
void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    int a1 = find(a);
    int b1 = find(b);
    if (a1 != b1)
    {
        if (sz[b1] > sz[a1])
        {
            int t = a1;
            a1 = b1;
            b1 = t;
        }
        parent[b1] = a1;
        sz[a1] += sz[b1];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    vector<ll> c, k;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        c.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        k.push_back(x);
    }
    vector<pair<ll, pair<int, int>>> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                ll w = (k[i] + k[j]) * (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second));
                e.push_back({w, {i + 1, j + 1}});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        e.push_back({c[i], {i + 1, 0}});
    }

    for (int i = 0; i <= n; i++)
        make(i);
    sort(e.begin(), e.end());
    ll cost = 0, vv = 0, cc = 0;
    vector<int> ps;
    vector<pair<int, int>> con;
    for (auto &i : e)
    {
        int w = i.first;
        int a = i.second.first;
        int b = i.second.second;
        if (find(a) != find(b))
        {
            cost += w;
            Union(a, b);
            // cout << a << " " << b << endl;
            if (b == 0)
            {
                vv++;
                ps.push_back(a);
            }
            else
            {
                cc++;
                con.push_back({a, b});
            }
        }
    }
    cout << cost << endl;
    cout << vv << endl;
    for (auto &i : ps)
        cout << i << " ";
    cout << endl;
    cout << cc << endl;
    for (auto &i : con)
        cout << i.first << " " << i.second << endl;
    return 0;
}