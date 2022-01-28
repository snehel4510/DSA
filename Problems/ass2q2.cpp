#include <bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    struct node *next;
};
node *head = NULL;
node *ans = NULL;

void insert(char x, node **head_ref)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = temp;
    }
    else
    {
        node *p = *head_ref;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void print(node **head_ref)
{
    node *p = *head_ref;
    while (p != NULL)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char x;
        cin >> x;
        insert(x, &head);
    }
    print(&head);
    node *p = head;
    node *q = ans;
    while (p->next != NULL)
    {
        if (p->data == '*' and p->next->data == '*')
        {
            insert(' ', &ans);
            p = p->next->next;
            char c = p->data;
            c = char(65 + (c - 'a'));
            insert(c, &ans);
            p = p->next;
        }
        else if (p->data == '/' and p->next->data == '/')
        {
            insert(' ', &ans);
            p = p->next->next;
            char c = p->data;
            c = char(65 + (c - 'a'));
            insert(c, &ans);
            p = p->next;
        }
        else if (p->data == '*' and p->next->data == '/')
        {
            insert(' ', &ans);
            p = p->next->next;
            char c = p->data;
            c = char(65 + (c - 'a'));
            insert(c, &ans);
            p = p->next;
        }
        else if (p->data == '/' and p->next->data == '*')
        {
            insert(' ', &ans);
            p = p->next->next;
            char c = p->data;
            c = char(65 + (c - 'a'));
            insert(c, &ans);
            p = p->next;
        }
        else if (p->data == '*' or p->data == '/')
        {
            insert(' ', &ans);
            p = p->next;
        }
        else
        {
            insert(p->data, &ans);
            p = p->next;
        }
    }
    insert(p->data, &ans);
    print(&ans);
    return 0;
}