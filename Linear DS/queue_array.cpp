// // implementation of queue using arrays

#include <bits/stdc++.h>
using namespace std;

struct que
{
    int arr[10];
    int front = -1;
    int rear = -1;
};
struct que q;

void enqueue(int x)
{
    if (q.front == -1 or q.rear == -1)
    {
        q.front = 0;
        q.rear = 0;
        q.arr[0] = x;
    }
    else if (q.rear == 9)
    {
        if (q.front == 0)
        {
            return;
        }
        else
        {
            int i = 0, t = q.front;
            while (t != 9)
            {
                q.arr[i] = q.arr[t];
                t++;
                i++;
            }
            q.arr[i] = x;
            q.front = 0;
            q.rear = i;
        }
    }
    else
    {
        q.rear++;
        q.arr[q.rear] = x;
    }
}

int dequeue()
{
    int item;
    if (q.front == -1 and q.rear == -1)
    {
        cout << "queue is already empty" << endl;
    }
    else if (q.front == q.rear)
    {
        item = q.arr[q.front];
        q.front = q.rear = -1;
    }
    else
    {
        item = q.arr[q.front];
        q.front++;
    }
    return item;
}

void print()
{
    for (int i = q.front; i <= q.rear; i++)
    {
        cout << q.arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(7);
    enqueue(9);
    print();
    dequeue();
    dequeue();
    dequeue();
    print();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    print();
    enqueue(7);
    enqueue(8);
    enqueue(9);
    print();
    return 0;
}
