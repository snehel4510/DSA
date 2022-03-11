// creating a max-heap from a given unordered array A
// if A[i] is parent then A[2i] is left child and A[2i+1] is right child
// if A[i] is a child then A[floor(i/2)] is parent

#include <bits/stdc++.h>
using namespace std;

// maintains/restores the max-heap property
void max_heapify(vector<int> a, int i, int n) // O(logn)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;
    // finding the largest among the left and right child of i and replacing i with the largest one
    if (l <= n && a[l] > a[i])
        largest = l;
    if (r <= n && a[r] > a[largest])
        largest = r;
    if (largest != i) // if largest=i then either the max-heap property is satisfied for index i or i is leaf
    {
        swap(a[i], a[largest]);
        max_heapify(a, largest, n); // recursive call for next element(child of i) to be heapified
    }
}

// converting the given array into a max-heap
void build_max_heap(vector<int> a, int n) // O(nlogn)
{
    for (int i = n / 2; i >= 1; i--) // the last n/2 elements are leaves
        max_heapify(a, i, n);
}

// sorting the given array using max-heap property
void heap_sort(vector<int> a, int n) // O(nlogn)
{
    build_max_heap(a, n);        // first convert the array into a max-heap
    for (int i = n; i >= 2; i--) // then extract the max element from the heap(i.e., root or the first element of the arrayy) and replace it with the last element
    {
        swap(a[1], a[i]);
        max_heapify(a, 1, i - 1); // recursive call for next element(child of i) to be heapified with one less element in the array since the root is now eliminated
    }
}

// to find the maximum element of the heap
int heap_max(vector<int> a) // O(1)
{
    return a[1]; // root element
}

// to extract the maximum element(root) and remove it from the heap
int extract_max(vector<int> a, int n) // O(logn)
{
    int m;
    if (n < 1)
        cout << "Heap underflow" << endl;
    else
    {
        m = a[1];
        swap(a[1], a[n]);
        max_heapify(a, 1, n - 1);
    }
    return m;
}

// increase the value of key at index i to a new_val
void increase_key(vector<int> a, int i, int key) // O(logn)
{
    if (key < a[i])
        cout << "New key is smaller than current key" << endl;
    else
        a[i] = key;
    while (i > 1 && a[i / 2] < a[i]) // if the parent is smaller than the child then swap them
    {
        swap(a[i], a[i / 2]);
        i = i / 2;
    }
}

// insert a new key in the heap
void heap_insert(vector<int> a, int key, int n) // O(logn)
{
    a.push_back(INT_MIN); // adding a dummy element(with smallest possible value) at the end of the array
    increase_key(a, n + 1, key);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1); // we are taking 1 based indexing
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build_max_heap(a, n);
    heap_max(a);
    extract_max(a, n);
    heap_sort(a, n);
    increase_key(a, 5, 100);
    heap_insert(a, 100, n);

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}