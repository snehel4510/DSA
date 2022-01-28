// given a number, output the answer after reversing its bit

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, ind;
//     cin >> n;
//     vector<int> v(31);
//     for (int i = 0; i < 32; i++)
//     {
//         v[i] = ((n >> i) & 1);
//     }
//     for (int i = 31; i >= 0; i--)
//     {
//         if (v[i] == 1)
//         {
//             ind = i;
//             break;
//         }
//     }
//     int ans = 0, j = 0;
//     for (int i = ind; i >= 0; i--)
//     {
//         ans += (v[i] * (1 << j));
//         j++;
//     }
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 0, i = -1, ans = 0, j = 0;
    // this is to find the index i of MSB of n
    while (a <= n)
    {
        i++;
        a = (1 << i);
    }
    i--;
    //cout << i;
    while (i != -1)
    {
        ans += ((n >> j) & 1) * (1 << i);
        i--;
        j++;
    }
    cout << ans;
    return 0;
}