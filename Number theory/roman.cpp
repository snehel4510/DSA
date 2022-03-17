// roman to integer
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int ans = 0;
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int n = str.length();
    if (n == 1)
    {
        ans += mp[str[0]];
        cout << ans;
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (mp[str[i]] >= mp[str[i + 1]])
        {
            ans += mp[str[i]];
        }
        else
        {
            ans += mp[str[i + 1]] - mp[str[i]];
            if (mp[str[i + 1]] > mp[str[i + 2]])
                i++;
        }
        // cout << ans << endl;
    }
    if (mp[str[n - 1]] <= mp[str[n - 2]])
        ans += mp[str[n - 1]];

    cout << ans;

    return 0;
}

// Integer to Roman
// #include <bits/stdc++.h>
// using namespace std;
// string intToRoman(int num)
// {
//     vector<int> v = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
//     unordered_map<int, string> mp;
//     mp[1] = "I";
//     mp[4] = "IV";
//     mp[5] = "V";
//     mp[9] = "IX";
//     mp[10] = "X";
//     mp[40] = "XL";
//     mp[50] = "L";
//     mp[90] = "XC";
//     mp[100] = "C";
//     mp[400] = "CD";
//     mp[500] = "D";
//     mp[900] = "CM";
//     mp[1000] = "M";
//     string s;
//     for (int i = 12; i >= 0; i--)
//     {
//         if (num >= v[i])
//         {
//             if (v[i] == 1000 or v[i] == 100 or v[i] == 10 or v[i] == 1)
//             {
//                 int m = num;
//                 num = num % v[i];
//                 m /= v[i];
//                 while (m--)
//                     s += mp[v[i]];
//             }
//             else
//             {
//                 num %= v[i];
//                 s += mp[v[i]];
//             }
//         }
//         if (num == 0)
//             break;
//     }
//     return s;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     cout << intToRoman(n);
//     return 0;
// }