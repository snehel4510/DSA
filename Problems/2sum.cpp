// to find wheteher 2 indexes of an unsorted array sum to a specific number without 2pointers
// this hashing approach reduces the TC from O(nlogn)->due to sorting the array to O(n)
#include <bits/stdc++.h>
using namespace std;
bool tsum(int arr[], int n, int x)
{
    // code here
    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        if (s.find(x - arr[i]) != s.end())
        {
            return true;
        }

        s.insert(arr[i]);
    }

    return false;
}
int main()
{
    int n = 8, x = 12;
    int arr[8] = {2, 4, 1, 7, 5, 9, 7, 3};
    if (tsum(arr, n, x))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
