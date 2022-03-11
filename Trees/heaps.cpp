// creating a max-heap from a given unordered array A
// if A[i] is parent then A[2i] is left child and A[2i+1] is right child
// if A[i] is a child then A[floor(i/2)] is parent

#include <bits/stdc++.h>
using namespace std;

// maintains/restores the max-heap property
void max_heapify(int a[], int i, int n) // O(logn)
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
void build_max_heap(int a[], int n) // O(nlogn)
{
    for (int i = n / 2; i >= 1; i--) // the last n/2 elements are leaves
        max_heapify(a, i, n);
}

// sorting the given array using max-heap property
void heap_sort(int a[], int n) // O(nlogn)
{
    build_max_heap(a, n);        // first convert the array into a max-heap
    for (int i = n; i >= 2; i--) // then extract the max element from the heap(i.e., root or the first element of the arrayy) and replace it with the last element
    {
        swap(a[1], a[i]);
        max_heapify(a, 1, i - 1); // recursive call for next element(child of i) to be heapified with one less element in the array since the root is now eliminated
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n + 1]; // we are taking 1 based indexing
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build_max_heap(a, n);
    // array after conversion into a max-heap
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    heap_sort(a, n);
    // array after sorting (using heap-sort)
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}