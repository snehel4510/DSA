#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10] = {3, 2, 1, 4, 2, 1, 3, 4, 1, 3};
    vector<int> b(11, 0);
    vector<int> c(11, 0);
    for (auto i : a)
        c[i]++;
    for (int i = 1; i <= 10; i++)
        c[i] += c[i - 1];
    for (int i = 0; i < 10; i++)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    for (int i = 1; i < b.size(); i++)
        cout << b[i] << " ";
    return 0;
}