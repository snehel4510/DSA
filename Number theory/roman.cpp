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
        //cout << ans << endl;
    }
    if (mp[str[n - 1]] <= mp[str[n - 2]])
        ans += mp[str[n - 1]];

    cout << ans;

    return 0;
}