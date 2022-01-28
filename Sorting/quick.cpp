// uses recursions/divide and conquer strategy
// we choose a pivot index(last element of the array) and keep partitoning the array till end(when there is only 1 element left)
// The partitioning happens such that all elements less than pivot comes to left of pivet and all greater than pivot comes to its right in the array

#include <iostream>
using namespace std;

// to implement quick sort
void print(int a[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int partition(int a[], int s, int e)
{
    int pivot = a[e];
    int pi = s;
    for (int i = s; i < e; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pi]);
            pi++;
        }
    }
    swap(a[pi], a[e]);
    print(a);
    return pi;
}

void quick(int a[], int s, int e)
{
    if (s >= e)
        return;
    int p = partition(a, s, e);
    quick(a, s, p - 1);
    quick(a, p + 1, e);
}

int main()
{
    int a[10] = {2, 3, 7, 8, 1, 4, 6, 9, 0, 5};
    quick(a, 0, 9);
    return 0;
}