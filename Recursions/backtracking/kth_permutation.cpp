#include <bits/stdc++.h>
using namespace std;
string getPermutation(int n, int k)
{
    string ans = "";
    vector<int> v;
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
        fact *= i;
    }
    k--;
    while (v.size() > 0)
    {
        fact = fact / v.size();
        int d = k / fact;
        k = k % fact;
        ans.push_back(v[d] + '0');
        v.erase(v.begin() + d);
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k) << endl;
    return 0;
}