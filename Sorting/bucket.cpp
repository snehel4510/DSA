#include <bits/stdc++.h>
using namespace std;
void sort(vector<float> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int mi = i;
        for (int j = i; j < v.size(); j++)
        {
            if (v[j] < v[mi])
                mi = j;
        }
        swap(v[i], v[mi]);
    }
}
int main()
{
    int n;
    cin >> n;
    float a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<float>> bucket(10);
    for (int i = 0; i < n; i++)
    {
        int ind = a[i] * 100;
        ind /= 10;
        bucket[ind].push_back(a[i]);
    }
    for (auto i : bucket)
        sort(i);
    for (auto i : bucket)
    {
        for (auto j : i)
            cout << j << " ";
    }
    return 0;
}