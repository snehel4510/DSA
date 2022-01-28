// adding 2 numbers without '+' operator
// AND(&) is used to take the carry
// XOR(^) is used to add
// Left shift(<<) is used to take the carry to next bit
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    while (b != 0)
    {
        int a1 = (a ^ b);
        int b1 = ((a & b) << 1);
        a = a1;
        b = b1;
    }
    cout << a;
    return 0;
}