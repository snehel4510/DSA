// disjoint set union
#ifndef MYFILE_H_
#define MYFILE_H_

// your code goes here
const int N = 1e5 + 10;
int parent[N];
int size[N];

// makes an independent node in the DSU
void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}
// finds the parent of a node
int find(int v)
{
    if (parent[v] == v)
        return v;
    // path compression
    return parent[v] = find(parent[v]);
}
// joins the parent of 2 nodes to make it a same set in the DSU
void Union(int a, int b)
{
    int a1 = find(a);
    int b1 = find(b);
    if (a1 != b1)
    {
        // Union by size
        if (size[b1] > size[a1])
        {
            int t = a1;
            a1 = b1;
            b1 = t;
        }
        parent[b1] = a1;
        size[a1] += size[b1];
    }
}

#endif