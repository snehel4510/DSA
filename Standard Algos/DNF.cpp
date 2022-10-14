// dutch national flag algortihm

// problem -> sort colors (sort an array of 0s, 1s and 2s)

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& v) {
    int l = 0, m = 0, h = v.size()-1;
    while(l<=m and m<=h) {
        if(v[m]==0) {
            swap(v[l],v[m]);
            m++;
            l++;
        }
        else if(v[m]==1) {
            m++;
        }
        else if(v[m]==2) {
            swap(v[m],v[h]);
            h--;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    solve(v);
    for(int i=0;i<n;i++) cout<<v[i];
    return 0;
}