// longest palindromic substring
#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.length(), ansl = 0, rt = 0, lt = 0;
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        int r = i, l = i, len = 0;
        // odd
        while (r < n and l >= 0 and s[r] == s[l])
        {
            len = r - l + 1;
            ansl = max(ansl, len);
            if (ansl == len)
            {
                lt = l;
                rt = r;
            }
            r++;
            l--;
        }
        // even
        r = i + 1, l = i;
        while (r < n and l >= 0 and s[r] == s[l])
        {
            len = r - l + 1;
            ansl = max(ansl, len);
            if (ansl == len)
            {
                lt = l;
                rt = r;
            }
            r++;
            l--;
        }
    }
    for (int i = lt; i <= rt; i++)
        ans.push_back(s[i]);
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}