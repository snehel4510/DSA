// to check if the ith bit of a number n is set or unset
#include <bits/stdc++.h>
using namespace std;
void dtob(int n)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}
int main()
{
    int n, i;
    cin >> n >> i;
    int n1 = (1 << i);
    // cout << n1 << endl;
    // cout << (n & n1) << endl;
    dtob(n);
    if ((n & n1) == 0)
        cout << i << "th bit of " << n << " is unset" << endl;
    else
        cout << i << "th bit of " << n << " is set" << endl;

    // to check the number of set bits in n
    cout << "Number of set bits in " << n << " is : ";
    cout << __builtin_popcount(n) << endl;

    // to make the ith bit set
    cout << "After setting " << i << "th bit of " << n << " : ";
    dtob(n | n1);

    // to make the ith bit unset
    cout << "After unsetting " << i << "th bit of " << n << " : ";
    dtob(n & ~n1);

    // toggle ith bit of n
    cout << "After toggling the " << i << "th bit of " << n << " : ";
    dtob(n ^ n1);

    // to unset the right most set bit of n
    cout << "After unsetting the right most bit of " << n << " : ";
    dtob(n & (n - 1));
    return 0;
}