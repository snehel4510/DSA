// to represent a number using the multiple of its prime factors

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = n;
    vector<int> pf;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            pf.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        pf.push_back(n);
    }
    cout << "Prime factorisation of " << a << " is : ";
    for (auto i : pf)
    {
        cout << i << " ";
    }
    return 0;
}