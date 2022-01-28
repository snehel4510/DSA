// uses recursions / Divide & conquer
// the basic idea is that we will keep dividing the array into 2 halves until we reach a single element
// also we should know how to merge two sorted arrays

#include <iostream>
using namespace std;

// to implement merge sort

void merge(int a[], int l, int r, int m)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[m + 1 + i];
    }
    L[n1] = R[n2] = INT_MAX;
    int li = 0, ri = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[li] <= R[ri])
        {
            a[i] = L[li];
            li++;
        }
        else
        {
            a[i] = R[ri];
            ri++;
        }
    }
}

void mergeSort(int a[], int l, int r)
{
    int mid = (l + r) / 2;
    if (l == r)
        return;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, r, mid);
}

int main()
{
    int a[10] = {4, 8, 1, 2, 9, 0, 7, 6, 3, 5};
    mergeSort(a, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}