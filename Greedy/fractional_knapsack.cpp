#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, W;
    cin >> n >> W;
    int w[n], p[n];
    for (int i = 0; i < n; i++)
        cin >> w[i] >> p[i];
    float profit = 0;
    // sort the items on the basis of their value to weight ratio
    vector<pair<float, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].first = (float)p[i] / w[i];
        v[i].second = i;
    }
    sort(v.begin(), v.end(), [](pair<float, int> a, pair<float, int> b)
         { return a.first > b.first; }); // descending order
    int i = 0;
    cout << "Items Picked :- \n";
    while (W)
    {
        if (W >= w[v[i].second])
        {
            W -= w[v[i].second];
            profit += p[v[i].second];
            cout << "1 unit of Item " << v[i].second + 1 << endl;
        }
        else
        {
            float x = (float)(W * 1.0 / w[v[i].second]);
            profit += x * p[v[i].second];
            W = 0;
            cout << x << " units of Item " << v[i].second + 1 << endl;
        }
        i++;
    }
    cout << "Total : " << profit << endl;
    return 0;
}