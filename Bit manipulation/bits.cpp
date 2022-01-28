// convert binary to decimal and decimal to binary

#include <bits/stdc++.h>
using namespace std;
// to convert from decimal to bianry(of 10 bit)
void dtob(int n)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}
// to convert from binary(givena s a string) to decimal
int btod(string s)
{
    int num = 0, m = 0;
    for (auto i : s)
    {
        if (i == '1')
            num += (1 << m);
        m++;
    }
    return num;
}

int main()
{
    string s = "111";
    int num = 7;
    //cout<<dtob(num);
    //cout << btod(s);

    // count the number of set/unset bits in a 32 bit binary of a decimal number
    int n, cs = 0, cu = 0;
    cin >> n;
    for (int i = 0; i < 32; i++)
    {
        if ((n & (1 << i)) == 0)
            cu++;
        else
            cs++;
    }
    cout << "No. of set bits in binary of " << n << " is : " << cs << " or " << __builtin_popcount(n) << endl;
    cout << "No. of unset bits in binary of " << n << " is : " << cu << endl;
    return 0;
}