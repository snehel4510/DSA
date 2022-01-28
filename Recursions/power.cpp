#include <bits/stdc++.h>
using namespace std;
double power(double a, double b)
{
    if (b == 0)
        return 1;

    if (b < 0)
        return (1.0 / a) * power(a, b + 1);

    return a * power(a, b - 1);
}
int main()
{
    cout << power(5.000000, -3);
    return 0;
}