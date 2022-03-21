// finding k closest element to an element x in a sorted array
#include <bits/stdc++.h>
using namespace std;
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int l = 0;
    int r = arr.size() - 1;
    while (l + k - 1 < r)
    {
        if (abs(arr[l] - x) > abs(arr[r] - x))
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    vector<int> ans;
    for (int i = l; i <= r; ++i)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int k, x;
    cin >> k >> x;
    vector<int> ans = findClosestElements(v, k, x);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}