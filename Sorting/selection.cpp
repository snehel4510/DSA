// taking the ith element and swapping it with smallest among i+1 to nth elements

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
    for (int i = 0; i < v.size(); i++)
    {
        int mi = i;
        for (int j = i; j < v.size(); j++)
        {
            if (v[j] < v[mi])
                mi = j;
        }
        swap(v[i], v[mi]);
        print(v);
    }
    return 0;
}