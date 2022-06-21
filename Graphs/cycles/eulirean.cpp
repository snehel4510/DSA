// eulirean path/trail -> a path of edges that visits all the edges in the graph exactly once.
// **For an eulirean path to exist :-
// 1)undirected graphs -> either every vertex has even degree or exactly 2 vertices have odd degree
// 2)directed graphs -> at most 1 vertex has (in - out) degree equal = 1 and at most 1 vertex has (out - in) degree equal = 1 and all other vertices have same in and out degrees

// eulirean circuit/cycle -> an eulirean path that starts and ends on the same vertex.
// **For an eulirean circuit to exist :-
// 1)undirected graphs -> every vertex has even degree
// 2)directed graphs -> every vertex have equal in and out degrees

// All vertices with non-zero degree need to belong to same component
// an eulirean path can have a unique start/end vertex but itself isn't always unique

// an eulirean circuit is also an eulirean path. Just feed the graph(having an eulirean ckt) with the eulirean path algorithm and outcomes the eulirean circuit.

// heirholzar's algorithm to find an eulirean path for a directed graph
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> G[N];
vector<int> I(N, 0);
vector<int> O(N, 0);
vector<int> path;
// checking if the graph contains an eulirean path or not
bool path_exist(int v)
{
    bool flag = false;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < v; i++)
    {
        // no vertex should have too many incoming or outgoing edges
        if (I[i] - O[i] > 1 or O[i] - I[i] > 1)
            return false;
        // ending nodes
        else if (I[i] - O[i] == 1)
            c1++;
        // starting nodes
        else if (O[i] - I[i] == 1)
            c2++;
    }
    // if all in/out degrees are equal(eulirean ckt case, c3==v) then any node with non-zero degree can be our start/end node for the eulirean path
    if ((c1 == 1 and c2 == 1) or (c1 == 0 and c2 == 0))
        flag = true;
    return flag;
}
// finding the start node
int start(int v)
{
    int s = 0;
    for (int i = 0; i < v; i++)
    {
        // if unique starting vertex exist
        if (O[i] - I[i] == 1)
            return i;
        // start at any vertex with an outgoing edge
        if (O[i] > 0)
            s = i;
    }
    return s;
}
// force traversing all the edges
void dfs(int v)
{
    while (O[v] != 0)
    {
        int c = G[v][--O[v]];
        dfs(c);
    }
    path.push_back(v);
}
// getting the eulirean path if it exists
vector<int> eulirean_path(int v, int e)
{
    if (path_exist(v))
    {
        dfs(start(v));
        // Make sure all edges of the graph were traversed. There could be a case where the graph is disconnected.
        if (path.size() == e + 1)
            return {};
        // reversing the path because we are backtracking
        reverse(path.begin(), path.end());
        return path;
    }
    else
        cout << "The graph doesn't have an eulirean path";
    return {};
}
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
    // calculating the In and Out degrees
    for (int i = 0; i < v; i++)
    {
        O[i] = G[i].size();
        for (auto j : G[i])
            I[j]++;
    }

    cout << path_exist(v) << endl;
    cout << start(v) << endl;

    vector<int> ans = eulirean_path(v, e);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}