// implementation of stacks using array and linked list
#include <bits/stdc++.h>
using namespace std;

struct stk
{
    int arr[100];
    int top = -1;
};
struct stk s;

void push(int x)
{
    if (s.top == 99)
    {
        return;
    }

    s.top++;
    s.arr[s.top] = x;
}

void pop()
{
    if (s.top == -1)
    {
        return;
    }
    s.top--;
}

void print()
{
    int n = s.top;
    while (n != -1)
    {
        cout << s.arr[n] << " ";
        n--;
    }
    cout << endl;
}

bool isempty()
{
    return (s.top == -1);
}

bool isfull()
{
    return (s.top == 99);
}

int size()
{
    return (s.top + 1);
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print();
    pop();
    pop();
    print();
    cout << isempty() << " " << isfull() << endl;
    pop();
    pop();
    pop();
    cout << isempty() << " " << isfull() << endl;
    return 0;
}