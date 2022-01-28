// Applications of seive algorithm

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 1e6 + 1;
    vector<bool> v(n, 1);
    v[0] = v[1] = 0;
    // 0 -> composite & 1 -> prime

    vector<int> lp(n), hp(n);

    for (int i = 2; i <= n; i++)
    {
        if (v[i])
        {
            lp[i] = hp[i] = i;
            for (int j = i * 2; j <= n; j += i)
            {
                v[j] = 0;
                hp[j] = i;
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }

    // 1) Find lowest prime and highest prime of a number N which divides N
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " : "
             << "lp = " << lp[i] << " and hp = " << hp[i] << endl;
    }

    // 2) Find prime factorisation of a number N
    vector<int> pfs;
    int num;
    cin >> num;
    while (num > 1)
    {
        int pf;
        pf = lp[num];
        while (num % pf == 0)
        {
            num /= pf;
            pfs.push_back(pf);
        }
    }
    cout << "Prime factorisation of " << num << " is ";
    for (auto i : pfs)
    {
        cout << i << "*";
    }
    return 0;
}