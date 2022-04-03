#include <bits/stdc++.h>
using namespace std;
vector<string> v;
void generate(string &s, int o, int c)
{
    if (o == 0 && c == 0)
    {
        v.push_back(s);
        return;
    }
    if (o > 0)
    {
        s.push_back('(');
        generate(s, o - 1, c);
        s.pop_back();
    }
    if (c > 0)
    {
        if (o < c)
        {
            s.push_back(')');
            generate(s, o, c - 1);
            s.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    string s = "";
    generate(s, n, n);
    for (auto i : v)
    {
        cout << i << endl;
    }
    return 0;
}