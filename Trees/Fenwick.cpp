// one bit manipulation trick
// to unset the right most set bit of n -> n & (n - 1)

// BIT -> Binary Indexed Tree or Fenwick Tree
// BIT is used to solve the range queries and point queries in a segment tree.
// for an array of size n, every index i of a BIT will store a sum within range [j+1, i] where :
// j = i & (i-1)
// it's important to note that BITs uses 1 based indexing since all bit  manipulation tricks fail for index = 0

#include <bits/stdc++.h>
using namespace std;
vector<int> BIT, v;
void constructBIT(vector<int> &nums)
{
    v = nums;
    int n = nums.size();
    vector<int> pf(n + 1, 0); // since BITs are 1 based indexing
    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + nums[i - 1];
    BIT.push_back(-1);
    for (int i = 1; i <= n; i++)
    {
        int j = i & (i - 1); // removing the right most set from i
        BIT.push_back(pf[i] - pf[j]);
    }
}

// update the value of index i with value val
void update(int i, int val)
{
    int c = val - v[i];
    v[i] = val;
    i++;
    for (; i <= v.size(); i += (i & -i)) // adding rightmost set bit to i again
        BIT[i] += c;
}

// find the sum in BIT from index 1 till index i
int sum(int i)
{
    int s = 0;
    for (; i > 0; i -= (i & -i)) // removing the right most set bit from i
        s += BIT[i];
    return s;
}

// find the sum in range [l, r]
int sumRange(int l, int r)
{
    l++;
    r++;
    return sum(r) - sum(l - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    constructBIT(nums);
    for (int i = 1; i <= n; i++)
        cout << BIT[i] << " ";
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sumRange(l, r) << endl;
        int ind, val;
        cin >> ind >> val;
        update(ind, val);
    }
    return 0;
}
