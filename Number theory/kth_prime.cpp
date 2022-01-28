// finding Kth prime number using seive

#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int n = 9 * 1e7 + 1;
    vector<int> v1, v(n, true);
    v[0] = v[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                v[j] = false;
            }
        }
    }
    v1.push_back(2);
    for (int i = 3; i < n; i += 2)
    {
        if (v[i])
            v1.push_back(i);
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", v1[k - 1]);
    }
    return 0;
}