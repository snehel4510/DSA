// pushing the highest, then 2nd highest and so on...values of the array to the last,last-1... index after comparing them with their adjacent elements one by one

#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v = {9, 2, 6, 3, 4, 7, 0, 5};
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
        print(v);
    }
    return 0;
}