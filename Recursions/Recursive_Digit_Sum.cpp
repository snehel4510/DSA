#include <bits/stdc++.h>
using namespace std;
int super(string &s,long long sum)
{
    long long l = s.length();
    sum=0;
    if (l == 1)
    {
        char c = s[0]-'0';
        return (int)c;
    }
    for (auto i : s)
    {
        char c1 = i - '0';
        sum += (int)c1;
    }
    s = to_string(sum);
    return super(s,sum);
}
int main()
{
    string s;
    cin >> s;
    long long n,sum=0;
    cin >> n;
    for (auto i : s)
    {
        char c1 = i - '0';
        sum += (int)c1;
    }
    sum = n*sum;
    s=to_string(sum);
    cout << super(s,sum);
    return 0;
}
