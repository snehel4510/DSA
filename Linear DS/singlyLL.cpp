
#include <bits/stdc++.h>
using namespace std;

// singly linked list construction using structures

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;

// insert at begin

void insertbegin(int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

// Insert node at nth position

void insertNth(int new_data, int n)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *p = head;
        int i = 1;
        while (i < n)
        {
            p = p->next;
            i++;
        }
        new_node->next = p->next;
        p->next = new_node;
    }
}

// Insert node at end

void insertend(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

// deleting a node from the linked list

void deletebegin()
{
    Node *p = head;
    head = p->next;
    delete p;
}

void deleteend()
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        delete head;
    }
    Node *second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    delete (second_last->next);
    second_last->next = NULL;
}

void deleteNth(int n)
{
    if (head == NULL)
    {
        return;
    }
    Node *ptr = head;
    for (int i = 1; i < n - 1; i++)
    {
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

void display()
{
    Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void reverseLL()
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertbegin(x);
    }
    display();
    cout << endl;
    // inserting 10 at 3rd index
    insertNth(10, 3);
    display();
    cout << endl;
    deletebegin();
    display();
    cout << endl;
    deleteend();
    display();
    cout << endl;
    deleteNth(4);
    display();
    cout << endl;
    insertend(1);
    insertend(2);
    display();
    reverseLL();
    display();
    return 0;
}