// sparse matrix implementation using linked lists

#include <iostream>
using namespace std;

struct node
{
    int val, row, col;
    node *next;
};
node *head = NULL;

void insert(int r, int c, int v)
{
    node *temp = new node();
    temp->row = r;
    temp->col = c;
    temp->val = v;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->next = NULL;
}

void display()
{
    node *p = head;
    while (p->next != NULL)
    {
        cout << p->row << " " << p->col << " " << p->val << endl;
        p = p->next;
    }
}

int main()
{
    int m, n, nz = 0;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
                nz++;
        }
    }
    insert(m, n, nz);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
                insert(i, j, a[i][j]);
        }
    }
    display();
    return 0;
}