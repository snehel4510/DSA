// implementing a singly circular linked list

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *last = NULL;

void insertbegin(int x)
{
    node *temp = new node();
    temp->data = x;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
    }
}

void insertend(int x)
{
    node *temp = new node;
    temp->data = x;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void insertnth(int n, int x)
{
    node *temp = new node;
    temp->data = x;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        node *p = last;
        for (int i = 1; i < n; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void deletebegin()
{
    if (last == NULL)
    {
        return;
    }
    else
    {
        node *temp = last->next;
        last->next = temp->next;
        delete temp;
    }
}

void deleteend()
{
    if (last == NULL)
    {
        return;
    }
    node *temp = last;
    node *p = last->next;
    while (p->next != last)
    {
        p = p->next;
    }
    p->next = last->next;
    last = p;
    delete temp;
}

void deletenth(int n)
{
    if (last == NULL)
    {
        return;
    }
    node *p = last;
    for (int i = 1; i < n; i++)
    {
        p = p->next;
    }
    node *temp = p->next;
    p->next = temp->next;
    delete temp;
}

void print()
{
    node *temp = last->next;
    while (temp != last)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main()
{
    insertend(1);
    insertend(2);
    insertend(3);
    insertend(4);
    insertend(5);
    print();
    insertbegin(6);
    insertbegin(9);
    insertbegin(10);
    print();
    insertnth(4, 7);
    print();
    deletebegin();
    print();
    deleteend();
    print();
    deletenth(4);
    print();
    return 0;
}