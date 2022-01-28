// Bit Masking technique using a question
// There are n workers working for x number for days (1<= Xi <=30), find 2 waorkers that work on same days and number of days is also maximum

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int d, mask = 0;
        cin >> d;
        for (int j = 0; j < d; j++)
        {
            int day;
            cin >> day;
            mask = (mask | (1 << day));
        }
        v.push_back(mask);
    }
    int w1 = -1, w2 = -1, maxd = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            int cd = __builtin_popcount(v[i] & v[j]);
            maxd = max(maxd, cd);
            if (maxd == cd)
            {
                w1 = i + 1;
                w2 = j + 1;
            }
        }
    }
    cout << w1 << "th worker and " << w2 << "th worker should work together to maximise the no. of common working days i.e., " << maxd;
    return 0;
}