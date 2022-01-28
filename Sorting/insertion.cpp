// taking the ith element and inserting it at its correct place b/w o to i in the array

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
    for (int i = 1; i < n; i++)
    {
        int a = v[i];
        for (int j = 0; j < i; j++)
        {
            if (a < v[j])
            {
                v.erase(v.begin() + i);
                v.insert(v.begin() + j, a);
                break;
            }
        }
        print(v);
    }
    return 0;
}