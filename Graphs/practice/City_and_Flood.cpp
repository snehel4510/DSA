#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
void make(int v)
{
    parent[v] = v;
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
        parent[b1] = a1;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        make(i);
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        Union(i, j);
    }
    int c = 0;
    for (int i = 1; i <= n; i++)
        if (find(i) == i)
            c++;
    cout << c;
    return 0;
}