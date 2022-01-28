#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};
node *head;

node *newnode(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void inserthead(int data)
{
    node *temp = newnode(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void inserttail(int data)
{
    node *temp = newnode(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    node *lnode = head;
    while (lnode->next != NULL)
    {
        lnode = lnode->next;
    }
    lnode->next = temp;
    temp->prev = lnode;
}
void insert_sorted(int x)
{
    node *temp = newnode(x);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    node *p = head;
    while (p->data < x)
    {
        p = p->next;
    }
    node *l = p->prev;
    l->next = temp;
    p->prev = temp;
    temp->next = p;
    temp->prev = l;
}
void insertnth(int data, int n)
{
    node *temp = newnode(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    node *lnode = head;
    for (int i = 0; i < n - 1; i++)
    {
        lnode = lnode->next;
    }
    temp->next = lnode->next;
    temp->prev = lnode;
    lnode->next->prev = temp;
    lnode->next = temp;
}

void deletehead()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}
void deletetail()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}
void deletenth(int n)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;
    for (int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse()
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    inserttail(1);
    inserttail(2);
    inserttail(3);
    inserttail(6);
    inserttail(8);
    insert_sorted(5);
    display();
    // cout << endl;
    // inserttail(4);
    // inserttail(5);
    // inserttail(6);
    // display();
    // cout << endl;
    // insertnth(7, 3);
    // insertnth(8, 5);
    // display();
    // cout << endl;
    // deletetail();
    // display();
    // cout << endl;
    // deletehead();
    // display();
    // cout << endl;
    // deletenth(4);
    // display();
    // cout << endl;
    // reverse();
    return 0;
}