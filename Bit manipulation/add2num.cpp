// addition of 2 numbers without using + or - operator

#include <bits/stdc++.h>
using namespace std;
int getSum(int a, int b)
{
    while (b != 0)
    {
        int c = a;
        a = a ^ b;
        b = (unsigned)(c & b) << 1;
        cout << a << " " << b << endl;
    }
    return a;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << getSum(a, b);
    return 0;
}