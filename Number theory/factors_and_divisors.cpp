// to find all the factors if a given number

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, c = 0, sum = 0;
    cin >> n;
    cout << "All factors of " << n << " are :" << endl;
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            cout << i << " ";
            c++;
            sum += i;
        }
        else if (n % i == 0)
        {
            cout << i << " " << (n / i) << " ";
            c += 2;
            sum += (i + (n / i));
        }
    }
    cout << endl;
    cout << "count of factors = " << c << " and sum of all the factors = " << sum << endl;
    return 0;
}