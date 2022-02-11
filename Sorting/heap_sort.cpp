// // sorting in descending order using default max-heap
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int> v1 = {20, 30, 40, 25, 15};
//     make_heap(v1.begin(), v1.end());
//     // sort_heap(v1.begin(), v1.end()); -> alternate method
//     // else we can do 👇
//     vector<int> ans;
//     while (!v1.empty())
//     {
//         ans.push_back(v1.front());
//         pop_heap(v1.begin(), v1.end());
//         v1.pop_back();
//     }
//     for (auto i : ans)
//         cout << i << " ";
//     cout << endl;
//     return 0;
// }

// sorting in ascending order using converted Priority queue min-heap
#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    cout << "Enter array elements one by one : -";
    while (n--)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}