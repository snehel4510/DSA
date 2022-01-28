// implementation of queues using linked list

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
struct que
{
    node *front = NULL;
    node *rear = NULL;
};
que q;
void enqueue(int x)
{
    node *temp = new node();
    temp->data = x;
    temp->next = NULL;
    if (q.front == NULL or q.rear == NULL)
    {
        q.front = temp;
        q.rear = temp;
        return;
    }
    q.rear->next = temp;
    q.rear = temp;
}
void dequeue()
{
    if (q.front == NULL or q.rear == NULL)
    {
        return;
    }
    node *p = q.front;
    q.front = q.front->next;
    delete p;
}
void display()
{
    node *p = q.front;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}