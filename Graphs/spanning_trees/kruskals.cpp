// kruskal's algo to find MST using DSU
#include <bits/stdc++.h>
#include "dsu.h"
using namespace std;
int main()
{
    // cout << add(4, 5);
    int n, m;
    cin >> n >> m;
    // E -> (w, (a, b))
    vector<pair<int, pair<int, int>>> edges;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    // make the DSU
    for (int i = 1; i <= n; i++)
        make(i);
    // sort all the edges on the basis of their weight
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto &e : edges)
    {
        int w = e.first;
        int a = e.second.first;
        int b = e.second.second;
        // if both vertices a & b have same parent, that means they will be forming a loop
        if (find(a) != find(b))
        {
            cost += w;
            Union(a, b);
            cout << a << " " << b << endl;
        }
    }
    cout << "Total cost of the MST : " << cost << endl;
    return 0;
}