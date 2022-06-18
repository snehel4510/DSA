// finding out indegree and outdegree of every node in a graph
// indegree -> number of edges coming into a node
// outdegree -> number of edges going out of a node
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> G[N];
vector<int> I(N, 0);
vector<int> O(N, 0);
int main()
{
    int v, e;
    cin >> v >> e;
    while (e--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
    }
    for (int i = 0; i < v; i++)
    {
        O[i] = G[i].size();
        for (auto j : G[i])
            I[j]++;
    }
    cout << "indegree for all nodes :- \n";
    for (int i = 0; i < v; i++)
        cout << i << " : " << I[i] << "\n";
    cout << "outdegree for all nodes :- \n";
    for (int i = 0; i < v; i++)
        cout << i << " : " << O[i] << "\n";
    return 0;
}