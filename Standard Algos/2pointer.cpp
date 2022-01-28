// works only on sorted arrays

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {3, 7, 9, 12, 13, 17, 21, 23};
    int t = 34;
    int j = v.size() - 1, i = 0;
    while (v[i] + v[j] != t)
    {
        if (v[i] + v[j] > t)
        {
            j--;
        }
        else if (v[i] + v[j] < t)
        {
            i++;
        }
    }
    cout << i << " " << j;
    return 0;
}