#include <bits/stdc++.h>
using namespace std;
void print_heap(vector<int> &a)
{
    int n = a.size() - 1;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void min_heapify(vector<int> &a, int i)
{
    int n = a.size() - 1;
    int l = 2 * i;
    int r = 2 * i + 1;
    int smallest = i;
    if (l <= n && a[l] < a[i])
        smallest = l;
    if (r <= n && a[r] < a[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        min_heapify(a, smallest);
    }
}
void build_min_heap(vector<int> &a)
{
    int n = a.size() - 1;
    for (int i = n / 2; i >= 1; i--)
        min_heapify(a, i);
}
void heap_sort(vector<int> &a)
{
    int n = a.size() - 1;
    build_min_heap(a);
    // this will sort the array in descending order
    for (int i = n; i >= 2; i--)
    {
        swap(a[1], a[i]);
        min_heapify(a, 1);
    }
}
int heap_min(vector<int> &a)
{
    return a[1];
}
int extract_min(vector<int> &a)
{
    int n = a.size() - 1;
    int m;
    if (n < 1)
    {
        cout << "Heap underflow" << endl;
        return -1;
    }
    else
    {
        m = a[1];
        swap(a[1], a[n]);
        min_heapify(a, 1);
    }
    a.pop_back();
    return m;
}
void change_key(vector<int> &a, int i, int key)
{
    if (i > a.size() - 1)
        return;
    a[i] = key;
    while (i > 1 && a[i / 2] > a[i])
    {
        swap(a[i], a[i / 2]);
        i = i / 2;
    }
}
void heap_insert(vector<int> &a, int key)
{
    int n = a.size() - 1;
    a.push_back(INT_MAX);
    change_key(a, n + 1, key);
}
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(-1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    build_min_heap(a);
    print_heap(a);
    cout << heap_min(a) << endl;
    cout << extract_min(a) << endl;
    print_heap(a);
    heap_insert(a, 100);
    print_heap(a);
    change_key(a, 5, 4);
    print_heap(a);
    heap_sort(a);
    print_heap(a);

    return 0;
}