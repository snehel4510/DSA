// calculation nth root of x upto 10^-5 precision

#include <bits/stdc++.h>
using namespace std;

double power(double x, double n)
{
    double p = 1;
    while (n--)
    {
        p *= x;
    }
    return p;
}

int main()
{
    double n, x, eps = 1e-6;
    cin >> x >> n;

    double lo = 1, hi = x;
    while (hi - lo > eps)
    {
        double m = (lo + hi) / 2;
        if (power(m, n) < x)
        {
            lo = m;
        }
        else
        {
            hi = m;
        }
    }
    cout << hi;

    return 0;
}
