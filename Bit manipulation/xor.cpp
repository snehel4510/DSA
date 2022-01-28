// properties of XOR

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // swapping of 2 numbers using XOR operator
    int a = 2, b = 4;
    cout << "Before swapping a = " << a << " and b = " << b << endl;
    int c = a ^ b;
    a = (a ^ c);
    b = (b ^ c);
    cout << "After swapping a = " << a << " and b = " << b << endl;

    // given an array of int where frequency of every element is even except one element whose count is odd
    // find that one element in O(n) time ans O(1) space
    vector<int> v = {1, 2, 2, 1, 3, 5, 2, 5, 2};
    int ans = 0;
    for (auto i : v)
        ans ^= i;
    cout << ans; //3
    return 0;
}