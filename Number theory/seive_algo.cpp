#include <bits/stdc++.h>
using namespace std;
vector<int> findPrimeFactors(int n)
{
    // Write your code here
    vector<bool> v(n + 1, 1);
    v[0] = v[1] = 0;
    vector<int> lp(n + 1, 0), hp(n);
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            lp[i] = hp[i] = i;
            for (int j = i * i; j <= n; j += i)
            {
                v[j] = 0;
                hp[j] = i;
                if (lp[j] == 0)
                    lp[j] = i;
            }
        }
    }
    for (int i = 0; i <= n; i++)
        if (lp[i] == 0)
            lp[i] = i;

    // 1) Find lowest prime and highest prime of a number N which divides N
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " : "
             << "lp = " << lp[i] << " and hp = " << hp[i] << endl;
    }
    
    // 2) Find prime factorisation of a number N
    vector<int> pfs;
    while (n > 1)
    {
        int pf;
        pf = lp[n];
        while (n % pf == 0)
        {
            n /= pf;
            pfs.push_back(pf);
        }
    }
    return pfs;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = findPrimeFactors(n);
    cout << "Prime factorisation of " << n << " is ";
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}