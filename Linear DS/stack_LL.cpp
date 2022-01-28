
// implementing a stack using singly linked list

#include <iostream>
using namespace std;

struct stk
{
    int data;
    struct stk *next;
};

stk *top = NULL;

void push(int x)
{
    stk *temp = new stk();
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop()
{
    if (top == NULL)
    {
        return;
    }

    stk *temp = top;
    top = top->next;
    delete temp;
}

int topp()
{
    // stk *temp = top;
    return top->data;
}

bool isempty()
{
    // stk *temp = top;
    return top == NULL;
}

void print()
{
    stk *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print();
    return 0;
}