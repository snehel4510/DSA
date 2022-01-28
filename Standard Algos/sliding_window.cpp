// does not work for negative numbers in the array

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {5, -1, 3, 4, -2, 7, -6, 4, 10, 6};
    int t = 4;
    int sum = 0, ind = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        while (sum > t)
        {
            sum -= v[ind];
            ind++;
        }
        if (sum == t)
        {
            cout << "target sum found between indexes : " << ind << " & " << i;
            return 1;
        }
    }
    cout << "No subarray found for the given target sum";
    return 0;
}