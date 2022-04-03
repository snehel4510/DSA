#include <bits/stdc++.h>
using namespace std;
bool prime(int n)
{
    bool f = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f = false;
            break;
        }
    }
    return f;
}
int main()
{
    int n = 1;
    cout << "Enter an even number greater than 4 : ";
    while (n <= 4 || n % 2 != 0)
    {
        cin >> n;
        if (n <= 4)
            cout << "Wrong input! Please enter a number greater than 4 : ";
        else if (n % 2 != 0)
            cout << "Wrong input! Please enter an even number : ";
    }
    for (int i = 3; i < n; i++)
    {
        if (prime(i) && prime(n - i))
        {
            cout << i << " + " << (n - i) << " = " << n;
            break;
        }
    }
    return 0;
}