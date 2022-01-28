// implementation of circular queues using arrays

#include <bits/stdc++.h>
using namespace std;
struct que
{
    int arr[5];
    int front = -1;
    int rear = -1;
};
struct que cq;
void enCqueue(int x)
{
    if (cq.front == -1 or cq.rear == -1)
    {
        cq.front = 0;
        cq.rear = 0;
        cq.arr[0] = x;
    }
    else if (cq.rear == 4)
    {
        if (cq.front == 0)
            return;
        else
        {
            cq.rear = 0;
            cq.arr[0] = x;
        }
    }
    else if (cq.rear == cq.front - 1)
        return;
    else
    {
        cq.rear++;
        cq.arr[cq.rear] = x;
    }
}
void deCqueue()
{
    if (cq.front == -1 or cq.rear == -1)
        return;
    int x = cq.front;
    if (cq.front == cq.rear)
    {
        cq.front = cq.rear = -1;
    }
    else if (cq.front == 4)
        cq.front = 0;
    else
        cq.front++;
}
void display()
{
    if (cq.rear < cq.front)
    {
        for (int i = cq.front; i <= 5 + cq.rear; i++)
        {
            cout << cq.arr[i % 5] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = cq.front; i <= cq.rear; i++)
        {
            cout << cq.arr[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    enCqueue(5);
    enCqueue(4);
    enCqueue(1);
    enCqueue(2);
    enCqueue(7);
    display();
    deCqueue();
    enCqueue(10);
    deCqueue();
    display();
    return 0;
}