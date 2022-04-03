// 0 1 1 2 3 5 8 13 21 34 55 ....
// find nth element of fibonacci series
#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}