// BIT MANIPULATION TRICKS
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // to check if a number is odd or even using bit manipulation
    // 0th bit of odd numbers is 1
    // 0th bit of even number is 0
    if (n & 1)
        cout << n << " is odd" << endl;
    else
        cout << n << " is even" << endl;

    // to divide a number by 2
    cout << (n >> 1) << endl; // its not actual but floor division
    // to multiply a number by 2
    cout << (n << 1) << endl;

    // to convert a char from uppercase to lowercase and vice-versa
    cout << char('C' | ' ') << endl;
    cout << char('z' & ~(' ')) << " or " << char('z' & '_') << endl;

    // to check if a number is power of 2 or not
    // 16 = pow(2,4) = 10000 or  1<<4
    // 16-1 = 15 is 01111
    int n1 = 16;
    if (__builtin_popcount(n1) == 1)
        cout << n1 << " is power of 2" << endl;
    else
        cout << n1 << " is not a power of 2" << endl;
    // also if [n & (n-1) == 0] or <16 & 15 ==0> --> n is power of 2
    return 0;
}