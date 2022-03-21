#include <bits/stdc++.h>
using namespace std;
double power(double x, long long n)
{
    if (n == 0 or x == 1)
        return 1;
    if (n < 0)
    {
        n = -1 * n;
        x = 1 / x;
    }
    if (n % 2 == 0)
        return power(x * x, n / 2);
    return x * power(x * x, n / 2);
}
int main()
{
    cout << power(5.000000, -3);
    return 0;
}
